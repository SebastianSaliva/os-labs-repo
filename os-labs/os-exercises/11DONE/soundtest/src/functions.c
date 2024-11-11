#include "functions.h"

#include <stdio.h>

#include "structs.h"

void PrintTest() { printf("Test\n"); }

struct PianoNotes getPianoNotes() {
  struct PianoNotes pianoNotes = {
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
  return pianoNotes;
}
struct Piano getPiano() {
  struct Piano piano = {
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
  return piano;
}

// void play_tone(float duration_seconds, double frequency, int amp) {
//     snd_pcm_t *handle;
//     snd_pcm_sframes_t frames;
//     int err;

//     // Open PCM device for playback
//     if ((err = snd_pcm_open(&handle, "default", SND_PCM_STREAM_PLAYBACK, 0))
//     < 0) {
//         fprintf(stderr, "Unable to open PCM device: %s\n",
//         snd_strerror(err)); exit(1);
//     }

//     // Set parameters
//     if ((err = snd_pcm_set_params(handle,
//                                   SND_PCM_FORMAT_S16_LE,
//                                   SND_PCM_ACCESS_RW_INTERLEAVED,
//                                   CHANNELS,
//                                   SAMPLE_RATE,
//                                   1,
//                                   500000)) < 0) {   // 0.5 sec buffer
//         fprintf(stderr, "Unable to set parameters: %s\n", snd_strerror(err));
//         exit(1);
//     }

//     // Calculate number of frames
//     snd_pcm_uframes_t frames_to_deliver =
//     (snd_pcm_uframes_t)(duration_seconds * SAMPLE_RATE);

//     // Allocate buffer for samples
//     short *buffer = malloc(frames_to_deliver * sizeof(short));
//     if (buffer == NULL) {
//         fprintf(stderr, "Unable to allocate buffer\n");
//         exit(1);
//     }

//     // Generate a 440 Hz sine wave
//     for (snd_pcm_uframes_t i = 0; i < frames_to_deliver; i++) {
//         buffer[i] = amp * sin((2 * PI * frequency * i) / SAMPLE_RATE);
//     }

//     // Write samples to PCM device
//     frames = snd_pcm_writei(handle, buffer, frames_to_deliver);
//     if (frames < 0) {
//         frames = snd_pcm_recover(handle, frames, 0);
//     }
//     if (frames < 0) {
//         fprintf(stderr, "snd_pcm_writei failed: %s\n", snd_strerror(frames));
//     }
//     if (frames > 0 && frames < frames_to_deliver) {
//         fprintf(stderr, "Short write (expected %lu, wrote %li)\n",
//         frames_to_deliver, frames);
//     }

//     // Wait for playback to complete
//     snd_pcm_drain(handle);

//     // Clean up
//     free(buffer);
//     snd_pcm_close(handle);
// }