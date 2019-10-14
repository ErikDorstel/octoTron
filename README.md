# octoTron
Polyphonic Teensy 3.6 Synthesizer with MIDI Control
### This project implement a Teensy 3.6 based Synthesizer with two MIDI inputs.
The Synthesizer has the following characteristics:
* eight voices
* two LFO (sine,sawtooth,square,triangle) per voice
* two VCO (sine,sawtooth,square,triangle) with multiplier per voice
* one 12dB VCF (lowpass,highpass,bandpass) per voice
* one AHDSR generator per voice
* keyboard velocity
* glissando effect
* arpeggiator effect (three tone chord, major/minor, up/down, variable speed)
* one MIDI input for a MIDI keyboard
* one MIDI input for a MIDI controller like https://github.com/ErikDorstel/midiKnobs

The project uses the Teensy Audio Library to implement the synthesizer components like VCO, LFO ... . This graphic shows the connections of the components used.
![image note found](https://raw.githubusercontent.com/ErikDorstel/octoTron/master/documentation/ADT%20schematic.png)

The octoTron source code uses a new feature in the audio library. To restart an LFO with an absolute phase angle, the file synth_waveform.h must be changed. This pull request contains the changes needed https://github.com/PaulStoffregen/Audio/pull/275 .

The hardware used is very similar to https://github.com/ErikDorstel/stringFlow . The only difference is the use of a second MIDI In port. The octoTron Synthesizer use this second MIDI In port to connect a MIDI controller. The assigned MIDI controller numbers and the schematic are part of the documentation.
