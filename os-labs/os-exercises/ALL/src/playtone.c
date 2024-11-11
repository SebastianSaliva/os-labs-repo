#include <alsa/asoundlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define SAMPLE_RATE 192000
#define CHANNELS 1
#define PI 3.141594
#define ENVELOPE_MS 5
snd_pcm_t* handle;
void play_tone(float duration_seconds, double frequency, int amp) {
  snd_pcm_sframes_t frames;
  int err;

  // Calculate number of frames
  snd_pcm_uframes_t frames_to_deliver =
      (snd_pcm_uframes_t)(duration_seconds * SAMPLE_RATE);
  snd_pcm_uframes_t envelope_samples = 0;
  if (ENVELOPE_MS != 0) {
    envelope_samples = ENVELOPE_MS * SAMPLE_RATE / 1000;
  }
  // Allocate buffer for samples
  short* buffer = malloc(frames_to_deliver * sizeof(short));
  if (buffer == NULL) {
    fprintf(stderr, "Unable to allocate buffer\n");
    exit(1);
  }

  // Generate a 440 Hz sine wave
  for (snd_pcm_uframes_t i = 0; i < frames_to_deliver; i++) {
    double t = (double)i / SAMPLE_RATE;

    if (ENVELOPE_MS != 0) {
      double envelope = 1.0;
      // Apply attack envelope
      if (i < envelope_samples) {
        envelope = (double)i / envelope_samples;
      }
      // Apply release envelope
      else if (i > frames_to_deliver - envelope_samples) {
        envelope = (double)(frames_to_deliver - i) / envelope_samples;
      }

      buffer[i] = amp * envelope * sin(2 * PI * frequency * t);
      continue;
    }
    buffer[i] = amp * sin((2 * PI * frequency * t));
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
  // snd_pcm_drain(handle);

  // Clean up
  free(buffer);
  // snd_pcm_close(handle);
}
struct PianoNotes {
  double A0, As0, Bb0, B0, C1, Cs1, Db1, D1, Ds1, Eb1, E1, F1, Fs1, Gb1, G1,
      Gs1, Ab1, A1, As1, Bb1, B1, C2, Cs2, Db2, D2, Ds2, Eb2, E2, F2, Fs2, Gb2,
      G2, Gs2, Ab2, A2, As2, Bb2, B2, C3, Cs3, Db3, D3, Ds3, Eb3, E3, F3, Fs3,
      Gb3, G3, Gs3, Ab3, A3, As3, Bb3, B3, C4, Cs4, Db4, D4, Ds4, Eb4, E4, F4,
      Fs4, Gb4, G4, Gs4, Ab4, A4, As4, Bb4, B4, C5, Cs5, Db5, D5, Ds5, Eb5, E5,
      F5, Fs5, Gb5, G5, Gs5, Ab5, A5, As5, Bb5, B5, C6, Cs6, Db6, D6, Ds6, Eb6,
      E6, F6, Fs6, Gb6, G6, Gs6, Ab6, A6, As6, Bb6, B6, C7, Cs7, Db7, D7, Ds7,
      Eb7, E7, F7, Fs7, Gb7, G7, Gs7, Ab7, A7, As7, Bb7, B7, C8;
};
struct Piano {
  double notes[124];
};

void initialize_pcm();
void clean_up_pcm();
void fill_pianos(struct Piano* PIANO, struct PianoNotes* PIANOnotes);

int main() {
  struct Piano PIANO;
  struct PianoNotes PIANOnotes;
  fill_pianos(&PIANO, &PIANOnotes);

  initialize_pcm();
  // play_tone(0.1, piano.A5);  // Play tone for 1 second

  int amplitude = 32767;

  for (double i = 0; i < 4186; i++) {
    // printf("%d:%lf\n", i, freq);
    play_tone(1, i, amplitude);
  }
  // bool sw = false;
  // for (int i = 0; i < 1000; i++) {
  //   int o = 16;
  //   if (i % 16) sw = !sw;
  //   if (sw) o += 16;
  //   double freq = PIANO.notes[i % 16 + o];
  //   printf("%d:%lf\n", i, freq);
  //   play_tone(0.1, freq, amplitude);
  // }
  // for (int i = 0; i < 124; i++) {
  //   double freq = PIANO.notes[i];
  //   printf("%d:%lf\n", i, freq);
  //   play_tone(1, freq, amplitude);
  // }

  cleanup_pcm();
  return 0;
}
void initialize_pcm() {
  // Open PCM device for playback
  int err;
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
};

void cleanup_pcm() {
  snd_pcm_drain(handle);
  snd_pcm_close(handle);
};

void fill_pianos(struct Piano* piano, struct PianoNotes* pianonotes) {
  double notes = {
      27.50,   29.14,   29.14,   30.87,   32.70,   34.65,   34.65,   36.71,
      38.89,   38.89,   41.20,   43.65,   46.25,   46.25,   49.00,   51.91,
      51.91,   55.00,   58.27,   58.27,   61.74,   65.41,   69.30,   69.30,
      73.42,   77.78,   77.78,   82.41,   87.31,   92.50,   92.50,   98.00,
      103.83,  103.83,  110.00,  116.54,  116.54,  123.47,  130.81,  138.59,
      138.59,  146.83,  155.56,  155.56,  164.81,  174.61,  185.00,  185.00,
      196.00,  207.65,  207.65,  220.00,  233.08,  233.08,  246.94,  261.63,
      277.18,  277.18,  293.66,  311.13,  311.13,  329.63,  349.23,  369.99,
      369.99,  392.00,  415.30,  415.30,  440.00,  466.16,  466.16,  493.88,
      523.25,  554.37,  554.37,  587.33,  622.25,  622.25,  659.25,  698.46,
      739.99,  739.99,  783.99,  830.61,  830.61,  880.00,  932.33,  932.33,
      987.77,  1046.50, 1108.73, 1108.73, 1174.66, 1244.51, 1244.51, 1318.51,
      1396.91, 1479.98, 1479.98, 1567.98, 1661.22, 1661.22, 1760.00, 1864.66,
      1864.66, 1975.53, 2093.00, 2217.46, 2217.46, 2349.32, 2489.02, 2489.02,
      2637.02, 2793.83, 2959.96, 2959.96, 3135.96, 3322.44, 3322.44, 3520.00,
      3729.31, 3729.31, 3951.07, 4186.01};
  for (int i = 0; i < 130; i++) {
    piano->notes[i] = notes[i];
  }
  return;
};
