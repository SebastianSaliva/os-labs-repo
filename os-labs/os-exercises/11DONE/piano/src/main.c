#include <alsa/asoundlib.h>
#include <curses.h>
#include <math.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <structs.h>
#include <time.h>
#include <unistd.h>

#include "functions.h"
#define SAMPLE_RATE 192000
#define CHANNELS 1
#define PI 3.141594
#define ENVELOPE_MS 0
#define ENVE_START_MS 1
#define ENVE_END_MS 1
#include <signal.h>

// struct Piano {
//   double notes[124];
// };
// struct PianoNotes {
//   double A0, As0, Bb0, B0, C1, Cs1, Db1, D1, Ds1, Eb1, E1, F1, Fs1, Gb1, G1,
//       Gs1, Ab1, A1, As1, Bb1, B1, C2, Cs2, Db2, D2, Ds2, Eb2, E2, F2, Fs2,
//       Gb2, G2, Gs2, Ab2, A2, As2, Bb2, B2, C3, Cs3, Db3, D3, Ds3, Eb3, E3,
//       F3, Fs3, Gb3, G3, Gs3, Ab3, A3, As3, Bb3, B3, C4, Cs4, Db4, D4, Ds4,
//       Eb4, E4, F4, Fs4, Gb4, G4, Gs4, Ab4, A4, As4, Bb4, B4, C5, Cs5, Db5,
//       D5, Ds5, Eb5, E5, F5, Fs5, Gb5, G5, Gs5, Ab5, A5, As5, Bb5, B5, C6,
//       Cs6, Db6, D6, Ds6, Eb6, E6, F6, Fs6, Gb6, G6, Gs6, Ab6, A6, As6, Bb6,
//       B6, C7, Cs7, Db7, D7, Ds7, Eb7, E7, F7, Fs7, Gb7, G7, Gs7, Ab7, A7,
//       As7, Bb7, B7, C8;

//   struct Piano Notes;
// };

#define ENTER_ASCII 13
#define SPACE_ASCII 32
#define MAX_AMP 32767

// struct Piano PIANO;
// struct PianoNotes PIANOnotes;
int break_loop = 0;
int data_buffer_full = 0;
unsigned int volume = MAX_AMP / 2;
double duration = 1;
double tone = 440.0;
int oct = 1;
snd_pcm_t* handle;

void signal_handler(int signum) {
  if (signum == SIGUSR1) {
    data_buffer_full = 1;
    play_tone(1, 440, MAX_AMP);
    data_buffer_full = 0;
  }
}
struct Piano PIANO;
struct PianoNotes PIANOnotes;
void* FetchKeyStrokes() {
  keypad(stdscr, TRUE);
  noecho();

  int key_stroke;
  while (!break_loop) {
    while (data_buffer_full) {
      usleep(1000);
    }

    while (!data_buffer_full) {
      key_stroke = getch();

      data_buffer_full = 1;
    }
    switch (key_stroke) {
      case 'a':
        tone = PIANO.notes[1 * oct];
        kill(getpid(), SIGUSR1);
        break;
      case 'b':
        tone = PIANO.notes[2 * oct];
        kill(getpid(), SIGUSR1);
        break;
      case 'c':
        tone = PIANO.notes[3 * oct];
        kill(getpid(), SIGUSR1);
        break;
      case 'd':
        tone = PIANO.notes[4 * oct];
        kill(getpid(), SIGUSR1);
        break;
      case 'e':
        tone = PIANO.notes[5 * oct];
        kill(getpid(), SIGUSR1);
        break;
      case 'f':
        tone = PIANO.notes[6 * oct];
        kill(getpid(), SIGUSR1);
        break;
      case 'g':
        tone = PIANO.notes[7 * oct];
        kill(getpid(), SIGUSR1);
        break;
      case 'h':
        tone = PIANO.notes[8 * oct];
        kill(getpid(), SIGUSR1);
        break;
      case 'i':
        tone = PIANO.notes[9] * oct;
        kill(getpid(), SIGUSR1);
        break;
      case 'j':
        tone = PIANO.notes[10 * oct];
        kill(getpid(), SIGUSR1);
        break;
      case 'k':
        tone = PIANO.notes[11 * oct];
        kill(getpid(), SIGUSR1);
        break;
      case 'l':
        tone = PIANO.notes[12 * oct];
        kill(getpid(), SIGUSR1);
        break;
      case 'm':
        tone = PIANO.notes[13 * oct];
        kill(getpid(), SIGUSR1);
        break;
      case 'n':
        tone = PIANO.notes[14 * oct];
        kill(getpid(), SIGUSR1);
        break;
      case 'o':
        tone = PIANO.notes[15 * oct];
        kill(getpid(), SIGUSR1);
        break;
      case 'p':
        tone = PIANO.notes[16 * oct];
        kill(getpid(), SIGUSR1);
        break;
      case 'q':
        tone = PIANO.notes[17 * oct];
        kill(getpid(), SIGUSR1);
        break;
      case 'r':
        tone = PIANO.notes[18 * oct];
        kill(getpid(), SIGUSR1);
        break;
      case 's':
        tone = PIANO.notes[19 * oct];
        kill(getpid(), SIGUSR1);
        break;
      case 't':
        tone = PIANO.notes[20 * oct];
        kill(getpid(), SIGUSR1);
        break;
      case 'u':
        tone = PIANO.notes[21 * oct];
        kill(getpid(), SIGUSR1);
        break;
      case 'v':
        tone = PIANO.notes[22 * oct];
        kill(getpid(), SIGUSR1);
        break;
      case 'w':
        tone = PIANO.notes[23 * oct];
        kill(getpid(), SIGUSR1);
        break;
      case 'x':
        tone = PIANO.notes[24 * oct];
        kill(getpid(), SIGUSR1);
        break;
      case 'y':
        tone = PIANO.notes[25 * oct];
        kill(getpid(), SIGUSR1);
        break;
      case 'z':
        tone = PIANO.notes[26 * oct];
        kill(getpid(), SIGUSR1);
        break;
      case SPACE_ASCII:
        break;
      case ENTER_ASCII:
        break_loop = 1;
        break;
      case '+':
        if (volume < MAX_AMP) volume += 100;
        break;
      case '-':
        if (1 < volume) volume -= 100;
        break;
      case '9':
        if (duration < 5) duration += 0.2;
        break;
      case '0':
        if (0.25 < duration) duration -= 0.2;
        break;
      case '7':
        if (oct < 5) oct++;
        break;
      case '8':
        if (oct > 1) oct--;
        break;
    }
  }
}
snd_pcm_t* handle;
// void play_tone(double duration_seconds, double frequency, unsigned int amp) {
//   if (data_buffer_full)
//     return;
//   else
//     data_buffer_full = 1;

//   snd_pcm_sframes_t frames;
//   int err;

//   // Calculate number of frames
//   snd_pcm_uframes_t frames_to_deliver =
//       (snd_pcm_uframes_t)(duration_seconds * SAMPLE_RATE);
//   snd_pcm_uframes_t envelope_samples = 0;
//   if (ENVELOPE_MS != 0) {
//     envelope_samples = ENVELOPE_MS * SAMPLE_RATE / 1000;
//   }
//   // Allocate buffer for samples
//   short* buffer = malloc(frames_to_deliver * sizeof(short));
//   if (buffer == NULL) {
//     fprintf(stderr, "Unable to allocate buffer\n");
//     exit(1);
//   }

//   // Generate a 440 Hz sine wave
//   for (snd_pcm_uframes_t i = 0; i < frames_to_deliver; i++) {
//     double t = (double)i / SAMPLE_RATE;

//     if (ENVELOPE_MS != 0) {
//       double envelope = 1.0;
//       // Apply attack envelope

//       if (ENVE_START_MS) {
//         if (i < envelope_samples) {
//           envelope = (double)i / envelope_samples;
//         }
//       }
//       // Apply release envelope
//       if (ENVE_END_MS) {
//         if (i > frames_to_deliver - envelope_samples) {
//           envelope = (double)(frames_to_deliver - i) / envelope_samples;
//         }
//       }

//       buffer[i] = volume * envelope * sin(2 * PI * frequency * t);
//       continue;
//     }
//     buffer[i] = volume * sin((2 * PI * frequency * t));
//   }

//   // Write samples to PCM device
//   frames = snd_pcm_writei(handle, buffer, frames_to_deliver);
//   data_buffer_full = 0;
//   if (frames < 0) {
//     frames = snd_pcm_recover(handle, frames, 0);
//   }
//   if (frames < 0) {
//     fprintf(stderr, "snd_pcm_writei failed: %s\n", snd_strerror(frames));
//   }
//   if (frames > 0 && frames < frames_to_deliver) {
//     fprintf(stderr, "Short write (expected %lu, wrote %li)\n",
//             frames_to_deliver, frames);
//   }

//   // Clean up
//   free(buffer);
//   // snd_pcm_close(handle);
// }

int row, col = 0;
int counter_val = 0;

int main() {
  struct sigaction sa;
  sa.sa_handler = signal_handler;
  sigaction(SIGUSR1, &sa, NULL);

  initialize_pcm();

  fill_pianos(&PIANO, &PIANOnotes);
  initscr();
  curs_set(0);
  getmaxyx(stdscr, row, col);
  sleep(1);
  pthread_t p_fetch_key_strokes;
  pthread_create(&p_fetch_key_strokes, NULL, FetchKeyStrokes, NULL);

  while (!break_loop) {
    clear();
    getmaxyx(stdscr, row, col);
    mvprintw(0, 0, "%d", counter_val);

    refresh();
    usleep(100000);
  }

  pthread_join(p_fetch_key_strokes, NULL);
  endwin();
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