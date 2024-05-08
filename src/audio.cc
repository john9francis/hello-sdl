#include "audio.hh"
#include <iostream>


AudioPlayer::AudioPlayer(){
  if (SDL_LoadWAV("assets/boing.wav", &wavSpec, &wavBuffer, &wavLength) == NULL) {
    std::cout << "Failed to load WAV file: %s\n" << SDL_GetError() << std::endl;
  }

  // init audio
  if (SDL_Init(SDL_INIT_AUDIO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
  }

  // Open audio device
  audioDevice = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
  if (audioDevice == 0) {
    std::cout << "Failed to open audio device:" << SDL_GetError() << std::endl;
    SDL_FreeWAV(wavBuffer);
  }

  inputs = InputSingleton::GetInstance();
  audioPlaying = false;
}

AudioPlayer::~AudioPlayer(){
  // Cleanup
  SDL_CloseAudioDevice(audioDevice);
  SDL_FreeWAV(wavBuffer);
  SDL_Quit();
}

void AudioPlayer::PlaySound(){
  // Queue audio
  SDL_QueueAudio(audioDevice, wavBuffer, wavLength);
  SDL_PauseAudioDevice(audioDevice, 0); // Start playing audio

}

void AudioPlayer::Update(){
  if (inputs->a_down && !audioPlaying){
    PlaySound();
    audioPlaying = true;
  }

  if (SDL_GetQueuedAudioSize(audioDevice) == 0){
    audioPlaying = false;
  }
}