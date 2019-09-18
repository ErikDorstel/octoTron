#include <Audio.h>
#include <Metro.h>

AudioSynthWaveform       lfovco[9];
AudioSynthWaveform       lfofilt[9];
AudioSynthWaveformModulated vco1[9];
AudioSynthWaveformModulated vco2[9];
AudioMixer4              mixvco[9];
AudioFilterStateVariable filt[9];
AudioMixer4              mixfilt[9];
AudioEffectEnvelope      ahdsr[9];
AudioMixer4              mix18;
AudioMixer4              mix58;
AudioMixer4              mix14;
AudioOutputI2S           i2s1;
AudioConnection          patchCord1(lfovco[1], 0, vco1[1], 0);
AudioConnection          patchCord2(lfovco[1], 0, vco2[1], 0);
AudioConnection          patchCord3(lfofilt[1], 0, filt[1], 1);
AudioConnection          patchCord4(lfovco[2], 0, vco1[2], 0);
AudioConnection          patchCord5(lfovco[2], 0, vco2[2], 0);
AudioConnection          patchCord6(lfofilt[2], 0, filt[2], 1);
AudioConnection          patchCord7(lfovco[3], 0, vco1[3], 0);
AudioConnection          patchCord8(lfovco[3], 0, vco2[3], 0);
AudioConnection          patchCord9(lfofilt[3], 0, filt[3], 1);
AudioConnection          patchCord10(lfovco[4], 0, vco1[4], 0);
AudioConnection          patchCord11(lfovco[4], 0, vco2[4], 0);
AudioConnection          patchCord12(lfofilt[4], 0, filt[4], 1);
AudioConnection          patchCord13(lfovco[5], 0, vco1[5], 0);
AudioConnection          patchCord14(lfovco[5], 0, vco2[5], 0);
AudioConnection          patchCord15(lfofilt[5], 0, filt[5], 1);
AudioConnection          patchCord16(lfovco[6], 0, vco1[6], 0);
AudioConnection          patchCord17(lfovco[6], 0, vco2[6], 0);
AudioConnection          patchCord18(lfofilt[6], 0, filt[6], 1);
AudioConnection          patchCord19(lfovco[7], 0, vco1[7], 0);
AudioConnection          patchCord20(lfovco[7], 0, vco2[7], 0);
AudioConnection          patchCord21(lfofilt[7], 0, filt[7], 1);
AudioConnection          patchCord22(lfovco[8], 0, vco1[8], 0);
AudioConnection          patchCord23(lfovco[8], 0, vco2[8], 0);
AudioConnection          patchCord24(lfofilt[8], 0, filt[8], 1);
AudioConnection          patchCord25(vco2[1], 0, mixvco[1], 1);
AudioConnection          patchCord26(vco2[2], 0, mixvco[2], 1);
AudioConnection          patchCord27(vco2[3], 0, mixvco[3], 1);
AudioConnection          patchCord28(vco1[1], 0, mixvco[1], 0);
AudioConnection          patchCord29(vco2[4], 0, mixvco[4], 1);
AudioConnection          patchCord30(vco1[2], 0, mixvco[2], 0);
AudioConnection          patchCord31(vco2[5], 0, mixvco[5], 1);
AudioConnection          patchCord32(vco1[3], 0, mixvco[3], 0);
AudioConnection          patchCord33(vco2[6], 0, mixvco[6], 1);
AudioConnection          patchCord34(vco1[4], 0, mixvco[4], 0);
AudioConnection          patchCord35(vco2[7], 0, mixvco[7], 1);
AudioConnection          patchCord36(vco1[5], 0, mixvco[5], 0);
AudioConnection          patchCord37(vco2[8], 0, mixvco[8], 1);
AudioConnection          patchCord38(vco1[6], 0, mixvco[6], 0);
AudioConnection          patchCord39(vco1[7], 0, mixvco[7], 0);
AudioConnection          patchCord40(vco1[8], 0, mixvco[8], 0);
AudioConnection          patchCord41(mixvco[1], 0, filt[1], 0);
AudioConnection          patchCord42(mixvco[1], 0, mixfilt[1], 0);
AudioConnection          patchCord43(mixvco[2], 0, filt[2], 0);
AudioConnection          patchCord44(mixvco[2], 0, mixfilt[2], 0);
AudioConnection          patchCord45(mixvco[3], 0, filt[3], 0);
AudioConnection          patchCord46(mixvco[3], 0, mixfilt[3], 0);
AudioConnection          patchCord47(mixvco[4], 0, filt[4], 0);
AudioConnection          patchCord48(mixvco[4], 0, mixfilt[4], 0);
AudioConnection          patchCord49(mixvco[5], 0, filt[5], 0);
AudioConnection          patchCord50(mixvco[5], 0, mixfilt[5], 0);
AudioConnection          patchCord51(mixvco[6], 0, filt[6], 0);
AudioConnection          patchCord52(mixvco[6], 0, mixfilt[6], 0);
AudioConnection          patchCord53(mixvco[7], 0, filt[7], 0);
AudioConnection          patchCord54(mixvco[7], 0, mixfilt[7], 0);
AudioConnection          patchCord55(mixvco[8], 0, filt[8], 0);
AudioConnection          patchCord56(mixvco[8], 0, mixfilt[8], 0);
AudioConnection          patchCord57(filt[1], 0, mixfilt[1], 1);
AudioConnection          patchCord58(filt[1], 1, mixfilt[1], 2);
AudioConnection          patchCord59(filt[1], 2, mixfilt[1], 3);
AudioConnection          patchCord60(filt[2], 0, mixfilt[2], 1);
AudioConnection          patchCord61(filt[2], 1, mixfilt[2], 2);
AudioConnection          patchCord62(filt[2], 2, mixfilt[2], 3);
AudioConnection          patchCord63(filt[3], 0, mixfilt[3], 1);
AudioConnection          patchCord64(filt[3], 1, mixfilt[3], 2);
AudioConnection          patchCord65(filt[3], 2, mixfilt[3], 3);
AudioConnection          patchCord66(filt[4], 0, mixfilt[4], 1);
AudioConnection          patchCord67(filt[4], 1, mixfilt[4], 2);
AudioConnection          patchCord68(filt[4], 2, mixfilt[4], 3);
AudioConnection          patchCord69(filt[5], 0, mixfilt[5], 1);
AudioConnection          patchCord70(filt[5], 1, mixfilt[5], 2);
AudioConnection          patchCord71(filt[5], 2, mixfilt[5], 3);
AudioConnection          patchCord72(filt[6], 0, mixfilt[6], 1);
AudioConnection          patchCord73(filt[6], 1, mixfilt[6], 2);
AudioConnection          patchCord74(filt[6], 2, mixfilt[6], 3);
AudioConnection          patchCord75(filt[7], 0, mixfilt[7], 1);
AudioConnection          patchCord76(filt[7], 1, mixfilt[7], 2);
AudioConnection          patchCord77(filt[7], 2, mixfilt[7], 3);
AudioConnection          patchCord78(filt[8], 0, mixfilt[8], 1);
AudioConnection          patchCord79(filt[8], 1, mixfilt[8], 2);
AudioConnection          patchCord80(filt[8], 2, mixfilt[8], 3);
AudioConnection          patchCord81(mixfilt[1], ahdsr[1]);
AudioConnection          patchCord82(mixfilt[2], ahdsr[2]);
AudioConnection          patchCord83(mixfilt[3], ahdsr[3]);
AudioConnection          patchCord84(mixfilt[4], ahdsr[4]);
AudioConnection          patchCord85(mixfilt[5], ahdsr[5]);
AudioConnection          patchCord86(mixfilt[6], ahdsr[6]);
AudioConnection          patchCord87(mixfilt[7], ahdsr[7]);
AudioConnection          patchCord88(mixfilt[8], ahdsr[8]);
AudioConnection          patchCord89(ahdsr[5], 0, mix58, 0);
AudioConnection          patchCord90(ahdsr[8], 0, mix58, 3);
AudioConnection          patchCord91(ahdsr[1], 0, mix14, 0);
AudioConnection          patchCord92(ahdsr[2], 0, mix14, 1);
AudioConnection          patchCord93(ahdsr[3], 0, mix14, 2);
AudioConnection          patchCord94(ahdsr[4], 0, mix14, 3);
AudioConnection          patchCord95(ahdsr[7], 0, mix58, 2);
AudioConnection          patchCord96(ahdsr[6], 0, mix58, 1);
AudioConnection          patchCord97(mix18, 0, i2s1, 0);
AudioConnection          patchCord98(mix18, 0, i2s1, 1);
AudioConnection          patchCord99(mix58, 0, mix18, 1);
AudioConnection          patchCord100(mix14, 0, mix18, 0);
AudioControlSGTL5000     sgtl5000_1;

// mount voices for polyphony
byte voiceTone[9], voiceAge[9], currentAge=8;
// mixing filters
float potFiltmixthru, potFiltmixlow, potFiltmixband, potFiltmixhigh, potFiltmixsum;
// velocity
float potVCOamp, veloVCO[9];
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
// timer for glissando and arpeggiator
Metro timer = Metro(5);

void setup() {
  Serial1.begin(31250,SERIAL_8N1);
  Serial3.begin(31250,SERIAL_8N1);
  Serial.begin(9600);
  AudioMemory(50);
  for (byte v=1;v<=8;v++) { voiceTone[v]=255; voiceAge[v]=v; }
  sgtl5000_1.enable(); sgtl5000_1.volume(0.8); sgtl5000_1.unmuteLineout(); sgtl5000_1.lineOutLevel(29);
  mix14.gain(0,0.25); mix14.gain(1,0.25); mix14.gain(2,0.25); mix14.gain(3,0.25);
  mix58.gain(0,0.25); mix58.gain(1,0.25); mix58.gain(2,0.25); mix58.gain(3,0.25);
  mix18.gain(0,0.5); mix18.gain(1,0.5); mix18.gain(2,0); mix18.gain(3,0);
  setVCOmix(0.5,0.5);
  setFiltmix(1,0,0,0);
  setAHDSR(0,500,500,1,500);
  setFilt(440,4,7);
  setVCO1(0,440,WAVEFORM_SINE,1);
  setVCO2(0,440,WAVEFORM_SINE,1);
  setLFOvco(0,10,WAVEFORM_SINE);
  setLFOfilt(0,10,WAVEFORM_SINE);
  delay(1000); }

void loop() {
  byte MIDIinA; static byte MIDIstatusA=0, MIDIchannelA=0, MIDIpara1A=0, MIDIpara2A=0;
  if (Serial1.available() > 0) { MIDIinA = Serial1.read();
    if ((MIDIinA & 128) == 128) { MIDIstatusA=MIDIinA & 240; MIDIchannelA=MIDIinA & 15; MIDIpara1A=255; MIDIpara2A=255; } else {
    if (MIDIpara1A==255) { MIDIpara1A=MIDIinA; } else if (MIDIpara2A==255) { MIDIpara2A=MIDIinA;
      if (MIDIstatusA==0x80) { MIDIsetNoteOff(MIDIchannelA,MIDIpara1A,MIDIpara2A); }
      if (MIDIstatusA==0x90) { MIDIsetNoteOn(MIDIchannelA,MIDIpara1A,MIDIpara2A); }
      // if (MIDIstatusA==0xB0) { MIDIsetControl(MIDIchannelA,MIDIpara1A,MIDIpara2A); }
      // if (MIDIstatusA==0xE0) { MIDIsetPitchbend(MIDIchannelA,MIDIpara1A+(128*MIDIpara2A)); }
      MIDIpara1A=255; MIDIpara2A=255; } } }

  byte MIDIinB; static byte MIDIstatusB=0, MIDIchannelB=0, MIDIpara1B=0, MIDIpara2B=0;
  if (Serial3.available() > 0) { MIDIinB = Serial3.read();
    if ((MIDIinB & 128) == 128) { MIDIstatusB=MIDIinB & 240; MIDIchannelB=MIDIinB & 15; MIDIpara1B=255; MIDIpara2B=255; } else {
    if (MIDIpara1B==255) { MIDIpara1B=MIDIinB; } else if (MIDIpara2B==255) { MIDIpara2B=MIDIinB;
      // if (MIDIstatusB==0x80) { MIDIsetNoteOff(MIDIchannelB,MIDIpara1B,MIDIpara2B); }
      // if (MIDIstatusB==0x90) { MIDIsetNoteOn(MIDIchannelB,MIDIpara1B,MIDIpara2B); }
      if (MIDIstatusB==0xB0) { MIDIsetControl(MIDIchannelB,MIDIpara1B,MIDIpara2B); }
      if (MIDIstatusB==0xE0) { MIDIsetPitchbend(MIDIchannelB,MIDIpara1B+(128*MIDIpara2B)); }
      MIDIpara1B=255; MIDIpara2B=255; } } }
      
  if (timer.check() == 1) { if (potGlissspeed > 1) { doGlissando(); } doArpeggiator(); } }

void MIDIsetNoteOn(byte channel, byte tone, byte velocity) {
  if (potArpspeed<500) { setArpeggiator(1,channel,tone,velocity); } else { dostartPlayNote(channel, tone, velocity); } }

void dostartPlayNote(byte channel, byte tone, byte velocity) {
  byte voice=255; voice=mountVoice(tone);
  if (voice!=255) {
    AudioNoInterrupts();
    lfovco[voice].restart(); lfofilt[voice].restart();
    newfreqVCO1[voice]=(pow(2,(float(tone)-69)/12))*440; newfreqVCO2[voice]=newfreqVCO1[voice]*pow(2,(potVCO2freq*2)-1);
    if (potGlissspeed > 1) {
      curfreqVCO1[voice]=newfreqVCO1[lastVoice]; oldfreqVCO1[voice]=newfreqVCO1[lastVoice];
      curfreqVCO2[voice]=newfreqVCO2[lastVoice]; oldfreqVCO2[voice]=newfreqVCO2[lastVoice];
      vco1[voice].frequency(curfreqVCO1[voice]); vco2[voice].frequency(curfreqVCO2[voice]);
      timer.interval(5); timer.reset(); }
    else {
      curfreqVCO1[voice]=newfreqVCO1[voice]; oldfreqVCO1[voice]=newfreqVCO1[voice];
      curfreqVCO2[voice]=newfreqVCO2[voice]; oldfreqVCO2[voice]=newfreqVCO2[voice];
      vco1[voice].frequency(curfreqVCO1[voice]); vco2[voice].frequency(curfreqVCO2[voice]); }
    veloVCO[voice]=(float(velocity)/127*0.9)+0.1; vco1[voice].amplitude(veloVCO[voice]*potVCOamp); vco2[voice].amplitude(veloVCO[voice]*potVCOamp);
    AudioInterrupts();
    ahdsr[voice].noteOn(); lastVoice=voice; voiceUsage++; } }

void MIDIsetNoteOff(byte channel, byte tone, byte velocity) {
  if (potArpspeed<500) { setArpeggiator(2,channel,tone,velocity); } else { dostopPlayNote(channel, tone, velocity); } }

void dostopPlayNote(byte channel, byte tone, byte velocity) {
  byte voice=255; voice=unmountVoice(tone); if (voice!=255) { ahdsr[voice].noteOff(); voiceUsage--; } }

void doGlissando() {
  for (byte voice=1;voice<=8;voice++) {
    if ((oldfreqVCO1[voice] < newfreqVCO1[voice] and curfreqVCO1[voice] < newfreqVCO1[voice]) or (oldfreqVCO1[voice] > newfreqVCO1[voice] and curfreqVCO1[voice] > newfreqVCO1[voice])) {
      curfreqVCO1[voice]=curfreqVCO1[voice]*pow(newfreqVCO1[voice]/oldfreqVCO1[voice],(1/potGlissspeed));
      curfreqVCO2[voice]=curfreqVCO2[voice]*pow(newfreqVCO2[voice]/oldfreqVCO2[voice],(1/potGlissspeed));
      vco1[voice].frequency(curfreqVCO1[voice]); vco2[voice].frequency(curfreqVCO2[voice]); } } }

void setArpeggiator(byte mode, byte channel, byte tone, byte velocity) {
  byte arpIndex; byte arpToneseq[3];
  if ((potArpmode&96)==0) { arpToneseq[0]=0; arpToneseq[1]=4; arpToneseq[2]=7; }
  if ((potArpmode&96)==32) { arpToneseq[0]=0; arpToneseq[1]=3; arpToneseq[2]=7; }
  if ((potArpmode&96)==64) { arpToneseq[0]=7; arpToneseq[1]=4; arpToneseq[2]=0; }
  if ((potArpmode&96)==96) { arpToneseq[0]=7; arpToneseq[1]=3; arpToneseq[2]=0; }
  if (mode==1) { dostartPlayNote(channel,tone+arpToneseq[0],velocity); }
  if (mode==2) { dostopPlayNote(channel,tone+arpToneseq[0],velocity); }
  arpIndex=freeArpIndex(); if (arpIndex < 99) {
    arpMode[arpIndex]=mode; arpTime[arpIndex]=millis()+potArpspeed; arpChannel[arpIndex]=channel; arpTone[arpIndex]=tone+arpToneseq[1]; arpVelo[arpIndex]=velocity; }
  arpIndex=freeArpIndex(); if (arpIndex < 99) {
    arpMode[arpIndex]=mode; arpTime[arpIndex]=millis()+(2*potArpspeed); arpChannel[arpIndex]=channel; arpTone[arpIndex]=tone+arpToneseq[2]; arpVelo[arpIndex]=velocity; } }

byte freeArpIndex() { byte arpIndex=0; while (arpMode[arpIndex] != 0 and arpIndex < 99) { arpIndex++; } return arpIndex; }

void doArpeggiator() {
  byte arpIndex;
  for (arpIndex=0;arpIndex<99;arpIndex++) {
    if (arpMode[arpIndex] != 0) {
      if (long(millis()-arpTime[arpIndex]) >= 0) {
        if (arpMode[arpIndex] == 1) { arpMode[arpIndex]=0; dostartPlayNote(arpChannel[arpIndex], arpTone[arpIndex], arpVelo[arpIndex]); }
        if (arpMode[arpIndex] == 2) { arpMode[arpIndex]=0; dostopPlayNote(arpChannel[arpIndex], arpTone[arpIndex], arpVelo[arpIndex]); } } } } }

void MIDIsetControl(byte channel, byte control, byte value) {
  float fvalue, lvalue; fvalue=float(value)/127; lvalue=pow(fvalue,2);
  if (control==0) { setAHDSRattack(fvalue*1500); }
  if (control==1) { setAHDSRhold(fvalue*1500); }
  if (control==2) { setAHDSRdecay(fvalue*1500); }
  if (control==3) { setAHDSRsustain(fvalue); }
  if (control==4) { setAHDSRrelease(fvalue*5000); }
  if (control==5) { if (voiceUsage==0) { potArpmode=value; } }
  if (control==6) { if (voiceUsage==0) { potArpspeed=fvalue*500; } }
  if (control==7) { potGlissspeed=(fvalue*99)+1; }
  if (control==8) {
    if ((value&96)==0) { if (waveVCO1 != WAVEFORM_SINE) { setVCO1wave(WAVEFORM_SINE); waveVCO1=WAVEFORM_SINE; } }
    if ((value&96)==32) { if (waveVCO1 != WAVEFORM_SAWTOOTH) { setVCO1wave(WAVEFORM_SAWTOOTH); waveVCO1=WAVEFORM_SAWTOOTH; } }
    if ((value&96)==64) { if (waveVCO1 != WAVEFORM_SQUARE) { setVCO1wave(WAVEFORM_SQUARE); waveVCO1=WAVEFORM_SQUARE; } }
    if ((value&96)==96) { if (waveVCO1 != WAVEFORM_TRIANGLE) { setVCO1wave(WAVEFORM_TRIANGLE); waveVCO1=WAVEFORM_TRIANGLE; } } }
  if (control==9) {
    if ((value&96)==0) { if (waveVCO2 != WAVEFORM_SINE) { setVCO2wave(WAVEFORM_SINE); waveVCO2=WAVEFORM_SINE; } }
    if ((value&96)==32) { if (waveVCO2 != WAVEFORM_SAWTOOTH) { setVCO2wave(WAVEFORM_SAWTOOTH); waveVCO2=WAVEFORM_SAWTOOTH; } }
    if ((value&96)==64) { if (waveVCO2 != WAVEFORM_SQUARE) { setVCO2wave(WAVEFORM_SQUARE); waveVCO2=WAVEFORM_SQUARE; } }
    if ((value&96)==96) { if (waveVCO2 != WAVEFORM_TRIANGLE) { setVCO2wave(WAVEFORM_TRIANGLE); waveVCO2=WAVEFORM_TRIANGLE; } } }
  if (control==10) { setVCOmix(1-fvalue,fvalue); }
  if (control==11) { potVCO2freq=fvalue; for (byte v=1;v<=8;v++) { newfreqVCO2[v]=newfreqVCO1[v]*pow(2,(potVCO2freq*2)-1);
    curfreqVCO2[v]=curfreqVCO1[v]*pow(2,(potVCO2freq*2)-1); oldfreqVCO2[v]=oldfreqVCO1[v]*pow(2,(potVCO2freq*2)-1); vco2[v].frequency(curfreqVCO2[v]); } }
  if (control==12) { potFiltmixthru=fvalue; potFiltmixsum=potFiltmixthru+potFiltmixlow+potFiltmixband+potFiltmixhigh;
    setFiltmix(potFiltmixthru/potFiltmixsum,potFiltmixlow/potFiltmixsum,potFiltmixband/potFiltmixsum,potFiltmixhigh/potFiltmixsum); }
  if (control==13) { potFiltmixlow=fvalue; potFiltmixsum=potFiltmixthru+potFiltmixlow+potFiltmixband+potFiltmixhigh;
    setFiltmix(potFiltmixthru/potFiltmixsum,potFiltmixlow/potFiltmixsum,potFiltmixband/potFiltmixsum,potFiltmixhigh/potFiltmixsum); }
  if (control==14) { potFiltmixband=fvalue; potFiltmixsum=potFiltmixthru+potFiltmixlow+potFiltmixband+potFiltmixhigh;
    setFiltmix(potFiltmixthru/potFiltmixsum,potFiltmixlow/potFiltmixsum,potFiltmixband/potFiltmixsum,potFiltmixhigh/potFiltmixsum); }
  if (control==15) { potFiltmixhigh=fvalue; potFiltmixsum=potFiltmixthru+potFiltmixlow+potFiltmixband+potFiltmixhigh;
    setFiltmix(potFiltmixthru/potFiltmixsum,potFiltmixlow/potFiltmixsum,potFiltmixband/potFiltmixsum,potFiltmixhigh/potFiltmixsum); }
  if (control==16) {
    if ((value&96)==0) { if (waveLFOvco != WAVEFORM_SINE) { setLFOvcowave(WAVEFORM_SINE); waveLFOvco=WAVEFORM_SINE; } }
    if ((value&96)==32) { if (waveLFOvco != WAVEFORM_SAWTOOTH) { setLFOvcowave(WAVEFORM_SAWTOOTH); waveLFOvco=WAVEFORM_SAWTOOTH; } }
    if ((value&96)==64) { if (waveLFOvco != WAVEFORM_SQUARE) { setLFOvcowave(WAVEFORM_SQUARE); waveLFOvco=WAVEFORM_SQUARE; } }
    if ((value&96)==96) { if (waveLFOvco != WAVEFORM_TRIANGLE) { setLFOvcowave(WAVEFORM_TRIANGLE); waveLFOvco=WAVEFORM_TRIANGLE; } } }
  if (control==17) { AudioNoInterrupts(); setLFOvcophase(fvalue*360); AudioInterrupts(); }
  if (control==18) { setLFOvcoamp(fvalue); }
  if (control==19) { setLFOvcofreq(fvalue*10); }
  if (control==24) {
    if ((value&96)==0) { if (waveLFOfilt != WAVEFORM_SINE) { setLFOfiltwave(WAVEFORM_SINE); waveLFOfilt=WAVEFORM_SINE; } }
    if ((value&96)==32) { if (waveLFOfilt != WAVEFORM_SAWTOOTH) { setLFOfiltwave(WAVEFORM_SAWTOOTH); waveLFOfilt=WAVEFORM_SAWTOOTH; } }
    if ((value&96)==64) { if (waveLFOfilt != WAVEFORM_SQUARE) { setLFOfiltwave(WAVEFORM_SQUARE); waveLFOfilt=WAVEFORM_SQUARE; } }
    if ((value&96)==96) { if (waveLFOfilt != WAVEFORM_TRIANGLE) { setLFOfiltwave(WAVEFORM_TRIANGLE); waveLFOfilt=WAVEFORM_TRIANGLE; } } }
  if (control==25) { AudioNoInterrupts(); setLFOfiltphase(fvalue*360); AudioInterrupts(); }
  if (control==26) { setLFOfiltamp(fvalue); }
  if (control==27) { setLFOfiltfreq(fvalue*10); }
  if (control==28) { setFiltfreq(fvalue*1000); }
  if (control==29) { setFiltres((fvalue*5.7)-0.7); }
  if (control==31) { potVCOamp=fvalue; for (byte v=1;v<=8;v++) { vco1[v].amplitude(veloVCO[v]*potVCOamp); vco2[v].amplitude(veloVCO[v]*potVCOamp); } } }

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
  if (voiceTone[1] == tone) { voiceAge[1]=++currentAge; voiceTone[1]=255; return 1; }
  else if (voiceTone[2] == tone) { voiceAge[2]=++currentAge; voiceTone[2]=255; return 2; }
  else if (voiceTone[3] == tone) { voiceAge[3]=++currentAge; voiceTone[3]=255; return 3; }
  else if (voiceTone[4] == tone) { voiceAge[4]=++currentAge; voiceTone[4]=255; return 4; }
  else if (voiceTone[5] == tone) { voiceAge[5]=++currentAge; voiceTone[5]=255; return 5; }
  else if (voiceTone[6] == tone) { voiceAge[6]=++currentAge; voiceTone[6]=255; return 6; }
  else if (voiceTone[7] == tone) { voiceAge[7]=++currentAge; voiceTone[7]=255; return 7; }
  else if (voiceTone[8] == tone) { voiceAge[8]=++currentAge; voiceTone[8]=255; return 8; }
  else { return 255; } }

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

void setVCOmix(float a, float b) { for (byte v=1;v<=8;v++) { mixvco[v].gain(0,a); mixvco[v].gain(1,b); mixvco[v].gain(2,0); mixvco[v].gain(3,0); } }

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
  Serial.println(AudioMemoryUsage()); Serial.println(AudioMemoryUsageMax());
  Serial.println(AudioProcessorUsage()); Serial.println(AudioProcessorUsageMax()); }
