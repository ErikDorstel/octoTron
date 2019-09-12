#include <Audio.h>

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

byte voiceTone[9]; byte voiceAge[9]; byte currentAge=8;
float potFiltmixthru; float potFiltmixlow; float potFiltmixband; float potFiltmixhigh; float potFiltmixsum;
float freqVCO1; float freqVCO2; float potVCO2freq;

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
  setVCOmix(0.7,0.3);
  setFiltmix(0,0,1,0);
  setAHDSR(4,2.5,35,1,500);
  setFilt(200,4,7);
  setVCO1(1,800,WAVEFORM_TRIANGLE,1);
  setVCO2(1,800,WAVEFORM_SQUARE,1);
  setLFOvco(0,10,WAVEFORM_TRIANGLE);
  setLFOfilt(0,10,WAVEFORM_TRIANGLE);
  delay(700); }

void loop() {
  byte MIDIinA; static byte MIDIstatusA=0; static byte MIDIchannelA=0; static byte MIDIpara1A=0; static byte MIDIpara2A=0;
  if (Serial1.available() > 0) { MIDIinA = Serial1.read();
    if ((MIDIinA & 128) == 128) { MIDIstatusA=MIDIinA & 240; MIDIchannelA=MIDIinA & 15; MIDIpara1A=255; MIDIpara2A=255; } else {
    if (MIDIpara1A==255) { MIDIpara1A=MIDIinA; } else if (MIDIpara2A==255) { MIDIpara2A=MIDIinA;
      if (MIDIstatusA==0x80) { MIDIsetNoteOff(MIDIchannelA,MIDIpara1A,MIDIpara2A); }
      if (MIDIstatusA==0x90) { MIDIsetNoteOn(MIDIchannelA,MIDIpara1A,MIDIpara2A); }
      // if (MIDIstatusA==0xB0) { MIDIsetControl(MIDIchannelA,MIDIpara1A,MIDIpara2A); }
      // if (MIDIstatusA==0xE0) { MIDIsetPitchbend(MIDIchannelA,MIDIpara1A+(128*MIDIpara2A)); }
      MIDIpara1A=255; MIDIpara2A=255; } } }

  byte MIDIinB; static byte MIDIstatusB=0; static byte MIDIchannelB=0; static byte MIDIpara1B=0; static byte MIDIpara2B=0;
  if (Serial3.available() > 0) { MIDIinB = Serial3.read();
    if ((MIDIinB & 128) == 128) { MIDIstatusB=MIDIinB & 240; MIDIchannelB=MIDIinB & 15; MIDIpara1B=255; MIDIpara2B=255; } else {
    if (MIDIpara1B==255) { MIDIpara1B=MIDIinB; } else if (MIDIpara2B==255) { MIDIpara2B=MIDIinB;
      // if (MIDIstatusB==0x80) { MIDIsetNoteOff(MIDIchannelB,MIDIpara1B,MIDIpara2B); }
      // if (MIDIstatusB==0x90) { MIDIsetNoteOn(MIDIchannelB,MIDIpara1B,MIDIpara2B); }
      if (MIDIstatusB==0xB0) { MIDIsetControl(MIDIchannelB,MIDIpara1B,MIDIpara2B); }
      if (MIDIstatusB==0xE0) { MIDIsetPitchbend(MIDIchannelB,MIDIpara1B+(128*MIDIpara2B)); }
      MIDIpara1B=255; MIDIpara2B=255; } } } }

void MIDIsetNoteOn(byte channel, byte tone, byte velocity) {
  byte voice=255; voice=mountVoice(tone);
  freqVCO1=(pow(2,(float(tone)-69)/12))*440; freqVCO2=freqVCO1*pow(2,(potVCO2freq*2)-1);
  if (voice!=255) {
    AudioNoInterrupts();
    lfovco[voice].restart(); lfofilt[voice].restart();
    vco1[voice].frequency(freqVCO1); vco2[voice].frequency(freqVCO2); ahdsr[voice].noteOn();
    AudioInterrupts(); } }

void MIDIsetNoteOff(byte channel, byte tone, byte velocity) {
  byte voice=255; voice=unmountVoice(tone); if (voice!=255) { ahdsr[voice].noteOff(); } }

void MIDIsetControl(byte channel, byte control, byte value) {
  float fvalue; fvalue=float(value)/127;
  if (control==0) { setAHDSRattack(fvalue*1500); }
  if (control==1) { setAHDSRhold(fvalue*1500); }
  if (control==2) { setAHDSRdecay(fvalue*1500); }
  if (control==3) { setAHDSRsustain(fvalue); }
  if (control==4) { setAHDSRrelease(fvalue*1500); }
  if (control==7) { setVCO1amp(fvalue); setVCO2amp(fvalue); }
  if (control==8) {
	  if ((value&96)==0) { setVCO1wave(WAVEFORM_SINE); }
    if ((value&96)==32) { setVCO1wave(WAVEFORM_SAWTOOTH); }
    if ((value&96)==64) { setVCO1wave(WAVEFORM_SQUARE); }
    if ((value&96)==96) { setVCO1wave(WAVEFORM_TRIANGLE); } }
  if (control==9) {
    if ((value&96)==0) { setVCO2wave(WAVEFORM_SINE); }
    if ((value&96)==32) { setVCO2wave(WAVEFORM_SAWTOOTH); }
    if ((value&96)==64) { setVCO2wave(WAVEFORM_SQUARE); }
    if ((value&96)==96) { setVCO2wave(WAVEFORM_TRIANGLE); } }
  if (control==10) { setVCOmix(1-fvalue,fvalue); }
  if (control==11) { potVCO2freq=fvalue; freqVCO2=freqVCO1*pow(2,(potVCO2freq*2)-1); setVCO2freq(freqVCO2); }
  if (control==12) { potFiltmixthru=fvalue; potFiltmixsum=potFiltmixthru+potFiltmixlow+potFiltmixband+potFiltmixhigh;
    setFiltmix(potFiltmixthru/potFiltmixsum,potFiltmixlow/potFiltmixsum,potFiltmixband/potFiltmixsum,potFiltmixhigh/potFiltmixsum); }
  if (control==13) { potFiltmixlow=fvalue; potFiltmixsum=potFiltmixthru+potFiltmixlow+potFiltmixband+potFiltmixhigh;
    setFiltmix(potFiltmixthru/potFiltmixsum,potFiltmixlow/potFiltmixsum,potFiltmixband/potFiltmixsum,potFiltmixhigh/potFiltmixsum); }
  if (control==14) { potFiltmixband=fvalue; potFiltmixsum=potFiltmixthru+potFiltmixlow+potFiltmixband+potFiltmixhigh;
    setFiltmix(potFiltmixthru/potFiltmixsum,potFiltmixlow/potFiltmixsum,potFiltmixband/potFiltmixsum,potFiltmixhigh/potFiltmixsum); }
  if (control==15) { potFiltmixhigh=fvalue; potFiltmixsum=potFiltmixthru+potFiltmixlow+potFiltmixband+potFiltmixhigh;
    setFiltmix(potFiltmixthru/potFiltmixsum,potFiltmixlow/potFiltmixsum,potFiltmixband/potFiltmixsum,potFiltmixhigh/potFiltmixsum); }
  if (control==16) {
    if ((value&96)==0) { setLFOvcowave(WAVEFORM_SINE); }
    if ((value&96)==32) { setLFOvcowave(WAVEFORM_SAWTOOTH); }
    if ((value&96)==64) { setLFOvcowave(WAVEFORM_SQUARE); }
    if ((value&96)==96) { setLFOvcowave(WAVEFORM_TRIANGLE); } }
  if (control==17) { setLFOvcophase(fvalue*360); }
  if (control==18) { setLFOvcoamp(fvalue); }
  if (control==19) { setLFOvcofreq(fvalue*10); }
  if (control==24) {
    if ((value&96)==0) { setLFOfiltwave(WAVEFORM_SINE); }
    if ((value&96)==32) { setLFOfiltwave(WAVEFORM_SAWTOOTH); }
    if ((value&96)==64) { setLFOfiltwave(WAVEFORM_SQUARE); }
    if ((value&96)==96) { setLFOfiltwave(WAVEFORM_TRIANGLE); } }
  if (control==25) { setLFOfiltphase(fvalue*360); }
  if (control==26) { setLFOfiltamp(fvalue); }
  if (control==27) { setLFOfiltfreq(fvalue*10); }
  if (control==28) { setFiltfreq(fvalue*1000); }
  if (control==29) { setFiltres((fvalue*5.7)-0.7); } }

void MIDIsetPitchbend(byte channel, word pitch) { }

byte mountVoice(byte tone) {
  byte voice=255; byte age=0;
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
