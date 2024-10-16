#include <alsa/asoundlib.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SAMPLE_RATE 44100
#define CHANNELS 1
struct PianoNotes {
  double A0;
  double As0;
  double Bb0;
  double B0;
  double C1;
  double Cs1;
  double Db1;
  double D1;
  double Ds1;
  double Eb1;
  double E1;
  double F1;
  double Fs1;
  double Gb1;
  double G1;
  double Gs1;
  double Ab1;
  double A1;
  double As1;
  double Bb1;
  double B1;
  double C2;
  double Cs2;
  double Db2;
  double D2;
  double Ds2;
  double Eb2;
  double E2;
  double F2;
  double Fs2;
  double Gb2;
  double G2;
  double Gs2;
  double Ab2;
  double A2;
  double As2;
  double Bb2;
  double B2;
  double C3;
  double Cs3;
  double Db3;
  double D3;
  double Ds3;
  double Eb3;
  double E3;
  double F3;
  double Fs3;
  double Gb3;
  double G3;
  double Gs3;
  double Ab3;
  double A3;
  double As3;
  double Bb3;
  double B3;
  double C4;
  double Cs4;
  double Db4;
  double D4;
  double Ds4;
  double Eb4;
  double E4;
  double F4;
  double Fs4;
  double Gb4;
  double G4;
  double Gs4;
  double Ab4;
  double A4;
  double As4;
  double Bb4;
  double B4;
  double C5;
  double Cs5;
  double Db5;
  double D5;
  double Ds5;
  double Eb5;
  double E5;
  double F5;
  double Fs5;
  double Gb5;
  double G5;
  double Gs5;
  double Ab5;
  double A5;
  double As5;
  double Bb5;
  double B5;
  double C6;
  double Cs6;
  double Db6;
  double D6;
  double Ds6;
  double Eb6;
  double E6;
  double F6;
  double Fs6;
  double Gb6;
  double G6;
  double Gs6;
  double Ab6;
  double A6;
  double As6;
  double Bb6;
  double B6;
  double C7;
  double Cs7;
  double Db7;
  double D7;
  double Ds7;
  double Eb7;
  double E7;
  double F7;
  double Fs7;
  double Gb7;
  double G7;
  double Gs7;
  double Ab7;
  double A7;
  double As7;
  double Bb7;
  double B7;
  double C8;
};

// Initialize the struct with the correct frequencies
struct PianoNotes piano = {.A0 = 27.50,
                           .As0 = 29.14,
                           .Bb0 = 29.14,
                           .B0 = 30.87,
                           .C1 = 32.70,
                           .Cs1 = 34.65,
                           .Db1 = 34.65,
                           .D1 = 36.71,
                           .Ds1 = 38.89,
                           .Eb1 = 38.89,
                           .E1 = 41.20,
                           .F1 = 43.65,
                           .Fs1 = 46.25,
                           .Gb1 = 46.25,
                           .G1 = 49.00,
                           .Gs1 = 51.91,
                           .Ab1 = 51.91,
                           .A1 = 55.00,
                           .As1 = 58.27,
                           .Bb1 = 58.27,
                           .B1 = 61.74,
                           .C2 = 65.41,
                           .Cs2 = 69.30,
                           .Db2 = 69.30,
                           .D2 = 73.42,
                           .Ds2 = 77.78,
                           .Eb2 = 77.78,
                           .E2 = 82.41,
                           .F2 = 87.31,
                           .Fs2 = 92.50,
                           .Gb2 = 92.50,
                           .G2 = 98.00,
                           .Gs2 = 103.83,
                           .Ab2 = 103.83,
                           .A2 = 110.00,
                           .As2 = 116.54,
                           .Bb2 = 116.54,
                           .B2 = 123.47,
                           .C3 = 130.81,
                           .Cs3 = 138.59,
                           .Db3 = 138.59,
                           .D3 = 146.83,
                           .Ds3 = 155.56,
                           .Eb3 = 155.56,
                           .E3 = 164.81,
                           .F3 = 174.61,
                           .Fs3 = 185.00,
                           .Gb3 = 185.00,
                           .G3 = 196.00,
                           .Gs3 = 207.65,
                           .Ab3 = 207.65,
                           .A3 = 220.00,
                           .As3 = 233.08,
                           .Bb3 = 233.08,
                           .B3 = 246.94,
                           .C4 = 261.63,
                           .Cs4 = 277.18,
                           .Db4 = 277.18,
                           .D4 = 293.66,
                           .Ds4 = 311.13,
                           .Eb4 = 311.13,
                           .E4 = 329.63,
                           .F4 = 349.23,
                           .Fs4 = 369.99,
                           .Gb4 = 369.99,
                           .G4 = 392.00,
                           .Gs4 = 415.30,
                           .Ab4 = 415.30,
                           .A4 = 440.00,
                           .As4 = 466.16,
                           .Bb4 = 466.16,
                           .B4 = 493.88,
                           .C5 = 523.25,
                           .Cs5 = 554.37,
                           .Db5 = 554.37,
                           .D5 = 587.33,
                           .Ds5 = 622.25,
                           .Eb5 = 622.25,
                           .E5 = 659.25,
                           .F5 = 698.46,
                           .Fs5 = 739.99,
                           .Gb5 = 739.99,
                           .G5 = 783.99,
                           .Gs5 = 830.61,
                           .Ab5 = 830.61,
                           .A5 = 880.00,
                           .As5 = 932.33,
                           .Bb5 = 932.33,
                           .B5 = 987.77,
                           .C6 = 1046.50,
                           .Cs6 = 1108.73,
                           .Db6 = 1108.73,
                           .D6 = 1174.66,
                           .Ds6 = 1244.51,
                           .Eb6 = 1244.51,
                           .E6 = 1318.51,
                           .F6 = 1396.91,
                           .Fs6 = 1479.98,
                           .Gb6 = 1479.98,
                           .G6 = 1567.98,
                           .Gs6 = 1661.22,
                           .Ab6 = 1661.22,
                           .A6 = 1760.00,
                           .As6 = 1864.66,
                           .Bb6 = 1864.66,
                           .B6 = 1975.53,
                           .C7 = 2093.00,
                           .Cs7 = 2217.46,
                           .Db7 = 2217.46,
                           .D7 = 2349.32,
                           .Ds7 = 2489.02,
                           .Eb7 = 2489.02,
                           .E7 = 2637.02,
                           .F7 = 2793.83,
                           .Fs7 = 2959.96,
                           .Gb7 = 2959.96,
                           .G7 = 3135.96,
                           .Gs7 = 3322.44,
                           .Ab7 = 3322.44,
                           .A7 = 3520.00,
                           .As7 = 3729.31,
                           .Bb7 = 3729.31,
                           .B7 = 3951.07,
                           .C8 = 4186.01};
void play_tone(float duration_seconds, float frequency) {
  snd_pcm_t *handle;
  snd_pcm_sframes_t frames;
  int err;

  // Open PCM device for playback
  if ((err = snd_pcm_open(&handle, "default", SND_PCM_STREAM_PLAYBACK, 0)) <
      0) {
    fprintf(stderr, "Unable to open PCM device: %s\n", snd_strerror(err));
    exit(1);
  }

  // Set parameters
  if ((err = snd_pcm_set_params(handle, SND_PCM_FORMAT_S16_LE,
                                SND_PCM_ACCESS_RW_INTERLEAVED, CHANNELS,
                                SAMPLE_RATE, 1,
                                500000)) < 0) {  // 0.5 sec buffer
    fprintf(stderr, "Unable to set parameters: %s\n", snd_strerror(err));
    exit(1);
  }

  // Calculate number of frames
  snd_pcm_uframes_t frames_to_deliver =
      (snd_pcm_uframes_t)(duration_seconds * SAMPLE_RATE);

  // Allocate buffer for samples
  short *buffer = malloc(frames_to_deliver * sizeof(short));
  if (buffer == NULL) {
    fprintf(stderr, "Unable to allocate buffer\n");
    exit(1);
  }

  // Generate a sine wave of the specified frequency
  for (snd_pcm_uframes_t i = 0; i < frames_to_deliver; i++) {
    buffer[i] = 32767 * sin((2 * M_PI * frequency * i) / SAMPLE_RATE);
  }

  // Write samples to PCM device
  frames = snd_pcm_writei(handle, buffer, frames_to_deliver);
  if (frames < 0) {
    frames = snd_pcm_recover(handle, frames, 0);
  }
  if (frames < 0) {
    fprintf(stderr, "snd_pcm_writei failed: %s\n", snd_strerror(frames));
  }
  if (frames > 0 && frames < frames_to_deliver) {
    fprintf(stderr, "Short write (expected %lu, wrote %li)\n",
            frames_to_deliver, frames);
  }

  // Wait for playback to complete
  snd_pcm_drain(handle);

  // Clean up
  free(buffer);
  snd_pcm_close(handle);
}

int main() {
  // play_tone(0.1, piano.A5);  // Play tone for 1 second

  for (size_t i = 0; i < sizeof(struct PianoNotes) / sizeof(double); i++) {
    double *ptr = (double *)&piano + i;
    play_tone(0.1, *ptr);  // Play tone for 1 second
    usleep(100000);
    // printf("Attribute %zu: %d\n", i, *ptr);
  }
  return 0;
}