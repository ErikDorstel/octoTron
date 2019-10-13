#include <Audio.h>
#include <Metro.h>
#include "ADT.h"

const bool logging=true;

// mount voices for polyphony
byte voiceTone[9], voiceAge[9], currentAge=8;
// mixing filters
float potFiltmixthru, potFiltmixlow, potFiltmixband, potFiltmixhigh, potFiltmixsum;
// velocity
float potVCOamp, veloVCO[9], potVCOratio, potVCOaddmul;
// frequency shift vco2
float potVCO2freq;
// glissando parameters
float oldfreqVCO1[9], newfreqVCO1[9], curfreqVCO1[9];
float oldfreqVCO2[9], newfreqVCO2[9], curfreqVCO2[9];
float potGlissspeed; byte lastVoice;
// to prevent restart oscillator
byte waveVCO1, waveVCO2, waveLFOvco, waveLFOfilt;
// arpeggiator parameters
byte arpMode[100], arpChannel[100], arpTone[100], arpVelo[100]; unsigned long arpTime[100];
float potArpspeed; byte potArpmode, voiceUsage;
// timer for glissando, arpeggiator and logging
Metro timer = Metro(5);
Metro logtimer = Metro(1000);

void setup() {
  Serial1.begin(31250,SERIAL_8N1);
  Serial3.begin(31250,SERIAL_8N1);
  Serial.begin(9600);
  AudioMemory(50);
  for (byte v=1;v<=8;v++) { voiceTone[v]=255; voiceAge[v]=v; }
  sgtl5000_1.enable(); sgtl5000_1.volume(0.8); sgtl5000_1.unmuteLineout(); sgtl5000_1.lineOutLevel(29);
  mix14.gain(0,0.25); mix14.gain(1,0.25); mix14.gain(2,0.25); mix14.gain(3,0.25);
  mix58.gain(0,0.25); mix58.gain(1,0.25); mix58.gain(2,0.25); mix58.gain(3,0.25);
  mix18.gain(0,5); mix18.gain(1,5); mix18.gain(2,0); mix18.gain(3,0);
  setVCOmix(0.33,0.33,0.33);
  setFiltmix(1,0,0,0);
  setAHDSR(0,500,500,1,500);
  setFilt(440,4,7);
  setVCO1(1,440,WAVEFORM_SINE,1);
  setVCO2(1,440,WAVEFORM_SINE,1);
  setLFOvco(0,10,WAVEFORM_SINE);
  setLFOfilt(0,10,WAVEFORM_SINE);
  delay(1000); }

void loop() {
  byte MIDIinA; static byte MIDIstatusA=0, MIDIchannelA=0, MIDIpara1A=0, MIDIpara2A=0;
  if (Serial1.available() > 0) { MIDIinA = Serial1.read();
    if ((MIDIinA & 128) == 128) { MIDIstatusA=MIDIinA & 240; MIDIchannelA=MIDIinA & 15; MIDIpara1A=255; MIDIpara2A=255; } else {
    if (MIDIpara1A==255) { MIDIpara1A=MIDIinA; } else if (MIDIpara2A==255) { MIDIpara2A=MIDIinA;
      if (MIDIstatusA==0x80) { MIDIsetNoteOff(MIDIchannelA,MIDIpara1A,MIDIpara2A); } else
      if (MIDIstatusA==0x90) { MIDIsetNoteOn(MIDIchannelA,MIDIpara1A,MIDIpara2A); }
      MIDIpara1A=255; MIDIpara2A=255; } } }

  byte MIDIinB; static byte MIDIstatusB=0, MIDIchannelB=0, MIDIpara1B=0, MIDIpara2B=0;
  if (Serial3.available() > 0) { MIDIinB = Serial3.read();
    if ((MIDIinB & 128) == 128) { MIDIstatusB=MIDIinB & 240; MIDIchannelB=MIDIinB & 15; MIDIpara1B=255; MIDIpara2B=255; } else {
    if (MIDIpara1B==255) { MIDIpara1B=MIDIinB; } else if (MIDIpara2B==255) { MIDIpara2B=MIDIinB;
      if (MIDIstatusB==0xB0) { MIDIsetControl(MIDIchannelB,MIDIpara1B,MIDIpara2B); } else
      if (MIDIstatusB==0xE0) { MIDIsetPitchbend(MIDIchannelB,MIDIpara1B+(128*MIDIpara2B)); }
      MIDIpara1B=255; MIDIpara2B=255; } } }
      
  if (timer.check() == 1) { if (potGlissspeed > 1) { doGlissando(); } doArpeggiator(); }
  if ((logtimer.check() == 1) and logging) { logUtil(); } }

void MIDIsetNoteOn(byte channel, byte tone, byte velocity) {
  if (potArpspeed<500) { setArpeggiator(1,channel,tone,velocity); } else { dostartPlayNote(channel, tone, velocity); } }

void dostartPlayNote(byte channel, byte tone, byte velocity) {
  byte voice=mountVoice(tone);
  if (voice!=255) {
    AudioNoInterrupts();
    lfovco[voice].restart(); lfofilt[voice].restart();
    newfreqVCO1[voice]=(pow(2,(float(tone)-69)/12))*440; newfreqVCO2[voice]=newfreqVCO1[voice]*getVCO2shift();
    if (potGlissspeed > 1) {
      curfreqVCO1[voice]=newfreqVCO1[lastVoice]; oldfreqVCO1[voice]=newfreqVCO1[lastVoice];
      curfreqVCO2[voice]=newfreqVCO2[lastVoice]; oldfreqVCO2[voice]=newfreqVCO2[lastVoice]; }
    else {
      curfreqVCO1[voice]=newfreqVCO1[voice]; oldfreqVCO1[voice]=newfreqVCO1[voice];
      curfreqVCO2[voice]=newfreqVCO2[voice]; oldfreqVCO2[voice]=newfreqVCO2[voice]; }
    vco1[voice].frequency(curfreqVCO1[voice]); vco2[voice].frequency(curfreqVCO2[voice]);
    vco1[voice].restart(); vco2[voice].restart();
    veloVCO[voice]=(float(velocity)/127*0.9)+0.1; mixvco[voice].gain(0,(1-potVCOaddmul)*(1-potVCOratio)*veloVCO[voice]*potVCOamp);
    mixvco[voice].gain(1,(1-potVCOaddmul)*potVCOratio*veloVCO[voice]*potVCOamp); mixvco[voice].gain(2,potVCOaddmul*veloVCO[voice]*potVCOamp);
    AudioInterrupts();
    ahdsr[voice].noteOn(); lastVoice=voice; voiceUsage++; } }

void MIDIsetNoteOff(byte channel, byte tone, byte velocity) {
  if (potArpspeed<500) { setArpeggiator(2,channel,tone,velocity); } else { dostopPlayNote(channel, tone, velocity); } }

void dostopPlayNote(byte channel, byte tone, byte velocity) {
  byte voice=unmountVoice(tone); if (voice!=255) { ahdsr[voice].noteOff(); voiceUsage--; } }

void doGlissando() {
  for (byte voice=1;voice<=8;voice++) {
    if ((oldfreqVCO1[voice] < newfreqVCO1[voice] and curfreqVCO1[voice] < newfreqVCO1[voice]) or (oldfreqVCO1[voice] > newfreqVCO1[voice] and curfreqVCO1[voice] > newfreqVCO1[voice])) {
      curfreqVCO1[voice]=curfreqVCO1[voice]*pow(newfreqVCO1[voice]/oldfreqVCO1[voice],(1/potGlissspeed));
      curfreqVCO2[voice]=curfreqVCO2[voice]*pow(newfreqVCO2[voice]/oldfreqVCO2[voice],(1/potGlissspeed));
      vco1[voice].frequency(curfreqVCO1[voice]); vco2[voice].frequency(curfreqVCO2[voice]); } } }

void setArpeggiator(byte mode, byte channel, byte tone, byte velocity) {
  byte arpIndex, arpToneseq[3]={0,0,0};
  if ((potArpmode&96)==0) { arpToneseq[0]=0; arpToneseq[1]=4; arpToneseq[2]=7; } else
  if ((potArpmode&96)==32) { arpToneseq[0]=0; arpToneseq[1]=3; arpToneseq[2]=7; } else
  if ((potArpmode&96)==64) { arpToneseq[0]=7; arpToneseq[1]=4; arpToneseq[2]=0; } else
  if ((potArpmode&96)==96) { arpToneseq[0]=7; arpToneseq[1]=3; arpToneseq[2]=0; }
  if (mode==1) { dostartPlayNote(channel,tone+arpToneseq[0],velocity); } else
  if (mode==2) { dostopPlayNote(channel,tone+arpToneseq[0],velocity); }
  if (potArpspeed == 0) {
    if (mode==1) { dostartPlayNote(channel,tone+arpToneseq[1],velocity); dostartPlayNote(channel,tone+arpToneseq[2],velocity); } else
    if (mode==2) { dostopPlayNote(channel,tone+arpToneseq[1],velocity); dostopPlayNote(channel,tone+arpToneseq[2],velocity); } }
  else {
    arpIndex=freeArpIndex(); if (arpIndex < 99) {
      arpMode[arpIndex]=mode; arpTime[arpIndex]=millis()+potArpspeed; arpChannel[arpIndex]=channel; arpTone[arpIndex]=tone+arpToneseq[1]; arpVelo[arpIndex]=velocity; }
    arpIndex=freeArpIndex(); if (arpIndex < 99) {
      arpMode[arpIndex]=mode; arpTime[arpIndex]=millis()+(2*potArpspeed); arpChannel[arpIndex]=channel; arpTone[arpIndex]=tone+arpToneseq[2]; arpVelo[arpIndex]=velocity; } } }

byte freeArpIndex() { byte arpIndex=0; while (arpMode[arpIndex] != 0 and arpIndex < 99) { arpIndex++; } return arpIndex; }

void doArpeggiator() {
  for (byte arpIndex=0;arpIndex<99;arpIndex++) {
    if (arpMode[arpIndex] != 0) {
      if (long(millis()-arpTime[arpIndex]) >= 0) {
        if (arpMode[arpIndex] == 1) { arpMode[arpIndex]=0; dostartPlayNote(arpChannel[arpIndex], arpTone[arpIndex], arpVelo[arpIndex]); } else
        if (arpMode[arpIndex] == 2) { arpMode[arpIndex]=0; dostopPlayNote(arpChannel[arpIndex], arpTone[arpIndex], arpVelo[arpIndex]); } } } } }

float getVCO2shift() { return(pow(2,pow((potVCO2freq*2)-1,3))); }

void MIDIsetControl(byte channel, byte control, byte value) {
  float fvalue=float(value)/127, lvalue=pow(fvalue,3);
  switch (control) {
    case 0: setAHDSRattack(fvalue*1500); break;
    case 1: setAHDSRhold(fvalue*1500); break;
    case 2: setAHDSRdecay(fvalue*1500); break;
    case 3: setAHDSRsustain(fvalue); break;
    case 4: setAHDSRrelease(fvalue*5000); break;
    case 5: if (voiceUsage==0) { potArpmode=value; } break;
    case 6: if (voiceUsage==0) { potArpspeed=fvalue*500; } break;
    case 7: potGlissspeed=(fvalue*99)+1; break;
    case 8:
      if ((value&96)==0) { if (waveVCO1 != WAVEFORM_SINE) { setVCO1wave(WAVEFORM_SINE); waveVCO1=WAVEFORM_SINE; } } else
      if ((value&96)==32) { if (waveVCO1 != WAVEFORM_SAWTOOTH) { setVCO1wave(WAVEFORM_SAWTOOTH); waveVCO1=WAVEFORM_SAWTOOTH; } } else
      if ((value&96)==64) { if (waveVCO1 != WAVEFORM_SQUARE) { setVCO1wave(WAVEFORM_SQUARE); waveVCO1=WAVEFORM_SQUARE; } } else
      if ((value&96)==96) { if (waveVCO1 != WAVEFORM_TRIANGLE) { setVCO1wave(WAVEFORM_TRIANGLE); waveVCO1=WAVEFORM_TRIANGLE; } } break;
    case 9:
      if ((value&96)==0) { if (waveVCO2 != WAVEFORM_SINE) { setVCO2wave(WAVEFORM_SINE); waveVCO2=WAVEFORM_SINE; } } else
      if ((value&96)==32) { if (waveVCO2 != WAVEFORM_SAWTOOTH) { setVCO2wave(WAVEFORM_SAWTOOTH); waveVCO2=WAVEFORM_SAWTOOTH; } } else
      if ((value&96)==64) { if (waveVCO2 != WAVEFORM_SQUARE) { setVCO2wave(WAVEFORM_SQUARE); waveVCO2=WAVEFORM_SQUARE; } } else
      if ((value&96)==96) { if (waveVCO2 != WAVEFORM_TRIANGLE) { setVCO2wave(WAVEFORM_TRIANGLE); waveVCO2=WAVEFORM_TRIANGLE; } } break;
    case 10: potVCOratio=fvalue; setVolume(); break;
    case 11: potVCOaddmul=fvalue; setVolume(); break;
    case 12: potVCO2freq=fvalue; for (byte v=1;v<=8;v++) { float VCO2shift=getVCO2shift(); newfreqVCO2[v]=newfreqVCO1[v]*VCO2shift;
      curfreqVCO2[v]=curfreqVCO1[v]*VCO2shift; oldfreqVCO2[v]=oldfreqVCO1[v]*VCO2shift; vco2[v].frequency(curfreqVCO2[v]); } break;
    case 13: potVCOamp=fvalue; setVolume(); break;
    case 16:
      if ((value&96)==0) { if (waveLFOvco != WAVEFORM_SINE) { setLFOvcowave(WAVEFORM_SINE); waveLFOvco=WAVEFORM_SINE; } } else
      if ((value&96)==32) { if (waveLFOvco != WAVEFORM_SAWTOOTH) { setLFOvcowave(WAVEFORM_SAWTOOTH); waveLFOvco=WAVEFORM_SAWTOOTH; } } else
      if ((value&96)==64) { if (waveLFOvco != WAVEFORM_SQUARE) { setLFOvcowave(WAVEFORM_SQUARE); waveLFOvco=WAVEFORM_SQUARE; } } else
      if ((value&96)==96) { if (waveLFOvco != WAVEFORM_TRIANGLE) { setLFOvcowave(WAVEFORM_TRIANGLE); waveLFOvco=WAVEFORM_TRIANGLE; } } break;
    case 17: AudioNoInterrupts(); setLFOvcophase(fvalue*360); AudioInterrupts(); break;
    case 18: setLFOvcoamp(fvalue); break;
    case 19: setLFOvcofreq(lvalue*100); break;
    case 20: potFiltmixthru=fvalue; potFiltmixsum=potFiltmixthru+potFiltmixlow+potFiltmixband+potFiltmixhigh;
      setFiltmix(potFiltmixthru/potFiltmixsum,potFiltmixlow/potFiltmixsum,potFiltmixband/potFiltmixsum,potFiltmixhigh/potFiltmixsum); break;
    case 21: potFiltmixlow=fvalue; potFiltmixsum=potFiltmixthru+potFiltmixlow+potFiltmixband+potFiltmixhigh;
      setFiltmix(potFiltmixthru/potFiltmixsum,potFiltmixlow/potFiltmixsum,potFiltmixband/potFiltmixsum,potFiltmixhigh/potFiltmixsum); break;
    case 22: potFiltmixband=fvalue; potFiltmixsum=potFiltmixthru+potFiltmixlow+potFiltmixband+potFiltmixhigh;
      setFiltmix(potFiltmixthru/potFiltmixsum,potFiltmixlow/potFiltmixsum,potFiltmixband/potFiltmixsum,potFiltmixhigh/potFiltmixsum); break;
    case 23: potFiltmixhigh=fvalue; potFiltmixsum=potFiltmixthru+potFiltmixlow+potFiltmixband+potFiltmixhigh;
      setFiltmix(potFiltmixthru/potFiltmixsum,potFiltmixlow/potFiltmixsum,potFiltmixband/potFiltmixsum,potFiltmixhigh/potFiltmixsum); break;
    case 24:
      if ((value&96)==0) { if (waveLFOfilt != WAVEFORM_SINE) { setLFOfiltwave(WAVEFORM_SINE); waveLFOfilt=WAVEFORM_SINE; } } else
      if ((value&96)==32) { if (waveLFOfilt != WAVEFORM_SAWTOOTH) { setLFOfiltwave(WAVEFORM_SAWTOOTH); waveLFOfilt=WAVEFORM_SAWTOOTH; } } else
      if ((value&96)==64) { if (waveLFOfilt != WAVEFORM_SQUARE) { setLFOfiltwave(WAVEFORM_SQUARE); waveLFOfilt=WAVEFORM_SQUARE; } } else
      if ((value&96)==96) { if (waveLFOfilt != WAVEFORM_TRIANGLE) { setLFOfiltwave(WAVEFORM_TRIANGLE); waveLFOfilt=WAVEFORM_TRIANGLE; } } break;
    case 25: AudioNoInterrupts(); setLFOfiltphase(fvalue*360); AudioInterrupts(); break;
    case 26: setLFOfiltamp(fvalue); break;
    case 27: setLFOfiltfreq(lvalue*100); break;
    case 28: setFiltfreq(lvalue*5000); break;
    case 29: setFiltres((fvalue*4.3)+0.7); break; } }

void MIDIsetPitchbend(byte channel, word pitch) { }

byte mountVoice(byte tone) {
  byte voice=255, age=0;
  if (voiceTone[1] == 255 and (age == 0 or voiceAge[1] < age)) { voice=1; age=voiceAge[1]; }
  if (voiceTone[2] == 255 and (age == 0 or voiceAge[2] < age)) { voice=2; age=voiceAge[2]; }
  if (voiceTone[3] == 255 and (age == 0 or voiceAge[3] < age)) { voice=3; age=voiceAge[3]; }
  if (voiceTone[4] == 255 and (age == 0 or voiceAge[4] < age)) { voice=4; age=voiceAge[4]; }
  if (voiceTone[5] == 255 and (age == 0 or voiceAge[5] < age)) { voice=5; age=voiceAge[5]; }
  if (voiceTone[6] == 255 and (age == 0 or voiceAge[6] < age)) { voice=6; age=voiceAge[6]; }
  if (voiceTone[7] == 255 and (age == 0 or voiceAge[7] < age)) { voice=7; age=voiceAge[7]; }
  if (voiceTone[8] == 255 and (age == 0 or voiceAge[8] < age)) { voice=8; age=voiceAge[8]; }
  if (voice != 255) { voiceTone[voice]=tone; } return voice; }
  
byte unmountVoice(byte tone) {
  if (currentAge > 220) { currentAge-=200; for (byte v=1;v<=8;v++) { voiceAge[v]-=200; } }
  if (voiceTone[1] == tone) { voiceAge[1]=++currentAge; voiceTone[1]=255; return 1; } else
  if (voiceTone[2] == tone) { voiceAge[2]=++currentAge; voiceTone[2]=255; return 2; } else
  if (voiceTone[3] == tone) { voiceAge[3]=++currentAge; voiceTone[3]=255; return 3; } else
  if (voiceTone[4] == tone) { voiceAge[4]=++currentAge; voiceTone[4]=255; return 4; } else
  if (voiceTone[5] == tone) { voiceAge[5]=++currentAge; voiceTone[5]=255; return 5; } else
  if (voiceTone[6] == tone) { voiceAge[6]=++currentAge; voiceTone[6]=255; return 6; } else
  if (voiceTone[7] == tone) { voiceAge[7]=++currentAge; voiceTone[7]=255; return 7; } else
  if (voiceTone[8] == tone) { voiceAge[8]=++currentAge; voiceTone[8]=255; return 8; } else { return 255; } }

void setVolume() { for (byte v=1;v<=8;v++) { mixvco[v].gain(0,(1-potVCOaddmul)*(1-potVCOratio)*veloVCO[v]*potVCOamp);
  mixvco[v].gain(1,(1-potVCOaddmul)*potVCOratio*veloVCO[v]*potVCOamp); mixvco[v].gain(2,potVCOaddmul*veloVCO[v]*potVCOamp); } }

void setAHDSR(float a, float h, float d, float s, float r) { for (byte v=1;v<=8;v++) { ahdsr[v].attack(a); ahdsr[v].hold(h); ahdsr[v].decay(d); ahdsr[v].sustain(s); ahdsr[v].release(r); } }
void setAHDSRattack(float a) { for (byte v=1;v<=8;v++) { ahdsr[v].attack(a); } }
void setAHDSRhold(float h) { for (byte v=1;v<=8;v++) { ahdsr[v].hold(h); } }
void setAHDSRdecay(float d) { for (byte v=1;v<=8;v++) { ahdsr[v].decay(d); } }
void setAHDSRsustain(float s) { for (byte v=1;v<=8;v++) { ahdsr[v].sustain(s); } }
void setAHDSRrelease(float r) { for (byte v=1;v<=8;v++) { ahdsr[v].release(r); } }

void setVCO1(float a, float f, byte w, byte o) { for (byte v=1;v<=8;v++) { vco1[v].begin(a,f,w); vco1[v].frequencyModulation(o); } }
void setVCO1amp(float a) { for (byte v=1;v<=8;v++) { vco1[v].amplitude(a); } }
void setVCO1freq(float f) { for (byte v=1;v<=8;v++) { vco1[v].frequency(f); } }
void setVCO1wave(byte w) { for (byte v=1;v<=8;v++) { vco1[v].begin(w); } }
  
void setVCO2(float a, float f, byte w, byte o) { for (byte v=1;v<=8;v++) { vco2[v].begin(a,f,w); vco2[v].frequencyModulation(o); } }
void setVCO2amp(float a) { for (byte v=1;v<=8;v++) { vco2[v].amplitude(a); } }
void setVCO2freq(float f) { for (byte v=1;v<=8;v++) { vco2[v].frequency(f); } }
void setVCO2wave(byte w) { for (byte v=1;v<=8;v++) { vco2[v].begin(w); } }

void setVCOmix(float a, float b, float c) { for (byte v=1;v<=8;v++) { mixvco[v].gain(0,a); mixvco[v].gain(1,b); mixvco[v].gain(2,c); mixvco[v].gain(3,0); } }

void setLFOvco(float a, float f, byte w) { for (byte v=1;v<=8;v++) { lfovco[v].begin(a,f,w); } }
void setLFOvcoamp(float a) { for (byte v=1;v<=8;v++) { lfovco[v].amplitude(a); } }
void setLFOvcofreq(float f) { for (byte v=1;v<=8;v++) { lfovco[v].frequency(f); } }
void setLFOvcowave(byte w) { for (byte v=1;v<=8;v++) { lfovco[v].begin(w); } }
void setLFOvcophase(float p) { for (byte v=1;v<=8;v++) { lfovco[v].phase(p); } }

void setLFOfilt(float a, float f, byte w) { for (byte v=1;v<=8;v++) { lfofilt[v].begin(a,f,w); } }
void setLFOfiltamp(float a) { for (byte v=1;v<=8;v++) { lfofilt[v].amplitude(a); } }
void setLFOfiltfreq(float f) { for (byte v=1;v<=8;v++) { lfofilt[v].frequency(f); } }
void setLFOfiltwave(byte w) { for (byte v=1;v<=8;v++) { lfofilt[v].begin(w); } }
void setLFOfiltphase(float p) { for (byte v=1;v<=8;v++) { lfofilt[v].phase(p); } }

void setFilt(float f,float r, float o) { for (byte v=1;v<=8;v++) { filt[v].frequency(f); filt[v].resonance(r); filt[v].octaveControl(o); } }
void setFiltfreq(float f) { for (byte v=1;v<=8;v++) { filt[v].frequency(f); } }
void setFiltres(float r) { for (byte v=1;v<=8;v++) { filt[v].resonance(r); } }

void setFiltmix(float a, float b, float c, float d) { for (byte v=1;v<=8;v++) { mixfilt[v].gain(0,a); mixfilt[v].gain(1,b); mixfilt[v].gain(2,c); mixfilt[v].gain(3,d); } }

void logUtil() {
  Serial.print("Memory: "); Serial.print(AudioMemoryUsage()); Serial.print("/"); Serial.print(AudioMemoryUsageMax());
  Serial.print(" CPU: "); Serial.print(AudioProcessorUsage()); Serial.print("/"); Serial.println(AudioProcessorUsageMax()); }
