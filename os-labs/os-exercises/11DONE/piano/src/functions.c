#include "functions.h"

#include <alsa/asoundlib.h>
#include <curses.h>
#include <math.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "functions.h"
#include "structs.h"

#define ENTER_ASCII 13
#define SPACE_ASCII 32
#define MAX_AMP 32767
extern struct Piano PIANO;
extern struct PianoNotes PIANOnotes;
extern int break_loop;
extern int data_buffer_full;
extern int volume;
extern float duration;
extern double tone;
extern int oct;
extern snd_pcm_t* handle;
#define SAMPLE_RATE 192000
#define CHANNELS 1
#define PI 3.141594
#define ENVELOPE_MS 0
#define ENVE_START_MS 1
#define ENVE_END_MS 1

void play_tone(float duration_seconds, double frequency, int amp) {
  if (data_buffer_full)
    return;
  else
    data_buffer_full = 1;

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

      if (ENVE_START_MS) {
        if (i < envelope_samples) {
          envelope = (double)i / envelope_samples;
        }
      }
      // Apply release envelope
      if (ENVE_END_MS) {
        if (i > frames_to_deliver - envelope_samples) {
          envelope = (double)(frames_to_deliver - i) / envelope_samples;
        }
      }

      buffer[i] = volume * envelope * sin(2 * PI * frequency * t);
      continue;
    }
    buffer[i] = volume * sin((2 * PI * frequency * t));
  }

  // Write samples to PCM device
  frames = snd_pcm_writei(handle, buffer, frames_to_deliver);
  data_buffer_full = 0;
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

  // Clean up
  free(buffer);
  // snd_pcm_close(handle);
}

void fill_pianos(struct Piano* piano, struct PianoNotes* pianonotes) {
  double notes[] = {
      27.50,   29.14,   30.87,   32.70,   34.65,   36.71,   38.89,   41.20,
      43.65,   46.25,   49.00,   51.91,   55.00,   58.27,   61.74,   65.41,
      69.30,   73.42,   77.78,   82.41,   87.31,   92.50,   98.00,   103.83,
      110.00,  116.54,  123.47,  130.81,  138.59,  146.83,  155.56,  164.81,
      174.61,  185.00,  196.00,  207.65,  220.00,  233.08,  246.94,  261.63,
      277.18,  293.66,  311.13,  329.63,  349.23,  369.99,  392.00,  415.30,
      440.00,  466.16,  493.88,  523.25,  554.37,  587.33,  622.25,  659.25,
      698.46,  739.99,  783.99,  830.61,  880.00,  932.33,  987.77,  1046.50,
      1108.73, 1174.66, 1244.51, 1318.51, 1396.91, 1479.98, 1567.98, 1661.22,
      1760.00, 1864.66, 1975.53, 2093.00, 2217.46, 2349.32, 2489.02, 2637.02,
      2793.83, 2959.96, 3135.96, 3322.44, 3520.00, 3729.31, 3951.07, 4186.01};

  for (int i = 0; i < 88; i++) {
    piano->notes[i] = notes[i];
    pianonotes->notes[i] = notes[i];
  }

  pianonotes->A0 = 27.50;
  pianonotes->As0 = 29.14;
  pianonotes->Bb0 = 29.14;
  pianonotes->B0 = 30.87;
  pianonotes->C1 = 32.70;
  pianonotes->Cs1 = 34.65;
  pianonotes->Db1 = 34.65;
  pianonotes->D1 = 36.71;
  pianonotes->Ds1 = 38.89;
  pianonotes->Eb1 = 38.89;
  pianonotes->E1 = 41.20;
  pianonotes->F1 = 43.65;
  pianonotes->Fs1 = 46.25;
  pianonotes->Gb1 = 46.25;
  pianonotes->G1 = 49.00;
  pianonotes->Gs1 = 51.91;
  pianonotes->Ab1 = 51.91;
  pianonotes->A1 = 55.00;
  pianonotes->As1 = 58.27;
  pianonotes->Bb1 = 58.27;
  pianonotes->B1 = 61.74;
  pianonotes->C2 = 65.41;
  pianonotes->Cs2 = 69.30;
  pianonotes->Db2 = 69.30;
  pianonotes->D2 = 73.42;
  pianonotes->Ds2 = 77.78;
  pianonotes->Eb2 = 77.78;
  pianonotes->E2 = 82.41;
  pianonotes->F2 = 87.31;
  pianonotes->Fs2 = 92.50;
  pianonotes->Gb2 = 92.50;
  pianonotes->G2 = 98.00;
  pianonotes->Gs2 = 103.83;
  pianonotes->Ab2 = 103.83;
  pianonotes->A2 = 110.00;
  pianonotes->As2 = 116.54;
  pianonotes->Bb2 = 116.54;
  pianonotes->B2 = 123.47;
  pianonotes->C3 = 130.81;
  pianonotes->Cs3 = 138.59;
  pianonotes->Db3 = 138.59;
  pianonotes->D3 = 146.83;
  pianonotes->Ds3 = 155.56;
  pianonotes->Eb3 = 155.56;
  pianonotes->E3 = 164.81;
  pianonotes->F3 = 174.61;
  pianonotes->Fs3 = 185.00;
  pianonotes->Gb3 = 185.00;
  pianonotes->G3 = 196.00;
  pianonotes->Gs3 = 207.65;
  pianonotes->Ab3 = 207.65;
  pianonotes->A3 = 220.00;
  pianonotes->As3 = 233.08;
  pianonotes->Bb3 = 233.08;
  pianonotes->B3 = 246.94;
  pianonotes->C4 = 261.63;
  pianonotes->Cs4 = 277.18;
  pianonotes->Db4 = 277.18;
  pianonotes->D4 = 293.66;
  pianonotes->Ds4 = 311.13;
  pianonotes->Eb4 = 311.13;
  pianonotes->E4 = 329.63;
  pianonotes->F4 = 349.23;
  pianonotes->Fs4 = 369.99;
  pianonotes->Gb4 = 369.99;
  pianonotes->G4 = 392.00;
  pianonotes->Gs4 = 415.30;
  pianonotes->Ab4 = 415.30;
  pianonotes->A4 = 440.00;
  pianonotes->As4 = 466.16;
  pianonotes->Bb4 = 466.16;
  pianonotes->B4 = 493.88;
  pianonotes->C5 = 523.25;
  pianonotes->Cs5 = 554.37;
  pianonotes->Db5 = 554.37;
  pianonotes->D5 = 587.33;
  pianonotes->Ds5 = 622.25;
  pianonotes->Eb5 = 622.25;
  pianonotes->E5 = 659.25;
  pianonotes->F5 = 698.46;
  pianonotes->Fs5 = 739.99;
  pianonotes->Gb5 = 739.99;
  pianonotes->G5 = 783.99;
  pianonotes->Gs5 = 830.61;
  pianonotes->Ab5 = 830.61;
  pianonotes->A5 = 880.00;
  pianonotes->As5 = 932.33;
  pianonotes->Bb5 = 932.33;
  pianonotes->B5 = 987.77;
  pianonotes->C6 = 1046.50;
  pianonotes->Cs6 = 1108.73;
  pianonotes->Db6 = 1108.73;
  pianonotes->D6 = 1174.66;
  pianonotes->Ds6 = 1244.51;
  pianonotes->Eb6 = 1244.51;
  pianonotes->E6 = 1318.51;
  pianonotes->F6 = 1396.91;
  pianonotes->Fs6 = 1479.98;
  pianonotes->Gb6 = 1479.98;
  pianonotes->G6 = 1567.98;
  pianonotes->Gs6 = 1661.22;
  pianonotes->Ab6 = 1661.22;
  pianonotes->A6 = 1760.00;
  pianonotes->As6 = 1864.66;
  pianonotes->Bb6 = 1864.66;
  pianonotes->B6 = 1975.53;
  pianonotes->C7 = 2093.00;
  pianonotes->Cs7 = 2217.46;
  pianonotes->Db7 = 2217.46;
  pianonotes->D7 = 2349.32;
  pianonotes->Ds7 = 2489.02;
  pianonotes->Eb7 = 2489.02;
  pianonotes->E7 = 2637.02;
  pianonotes->F7 = 2793.83;
  pianonotes->Fs7 = 2959.96;
  pianonotes->Gb7 = 2959.96;
  pianonotes->G7 = 3135.96;
  pianonotes->Gs7 = 3322.44;
  pianonotes->Ab7 = 3322.44;
  pianonotes->A7 = 3520.00;
  pianonotes->As7 = 3729.31;
  pianonotes->Bb7 = 3729.31;
  pianonotes->B7 = 3951.07;
  pianonotes->C8 = 4186.01;

  return;
};