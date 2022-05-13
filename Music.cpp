#include "Music.h"
#include "SDL_include.h"

#include<string>

Music::Music() {
    music = nullptr;
}

Music::Music(std::string file) {
    music = nullptr;
    Open(file);
}

void Music::Play(int times) {
    if (music != nullptr) Mix_PlayMusic(music, times);
}

void Music::Stop(int msToStop) {
    int mixFadeOutMusic = Mix_FadeOutMusic(msToStop);
    if (!mixFadeOutMusic) {
        SDL_Log("Failed Operation: %s", SDL_GetError());
    }
}

void Music::Open(std::string file) {
    Mix_Music* error = Mix_LoadMUS(file.c_str());
    if (error == nullptr) {
        SDL_Log("Failed Operation: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

bool Music::IsOpen() {
    return music != nullptr;
}

Music::~Music() {
    Stop(0);
    Mix_FreeMusic(music);
}