#include "Game.h"
#include "State.h"

#include <string>

using namespace std;

Game& Game::GetInstance() {
    if (instance == nullptr) {
        instance = new Game("Game Show", 50, 100);
    }

    return *instance;
}

Game::Game(string title, int height, int width) {
    if (instance != nullptr) {
        exit(EXIT_FAILURE);   // FAILED TO INJECT INSTANCE
    }
    instance = this;

    int sdlInit = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
    if (sdlInit) {
        SDL_Log("Failed to Init SDL: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    int imgInit = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
    if (!imgInit) {
        SDL_Log("Failed to Init IMG: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    int mixInit = Mix_Init(MIX_INIT_OGG);
    if (!mixInit) {
        SDL_Log("Failed to Init Mix: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    int mixOpenAudio = Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    if (mixOpenAudio) {
        SDL_Log("Failed to Init Open Audio: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    Mix_AllocateChannels(32);

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (window == nullptr) {
        SDL_Log("Failed to Create Window: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        SDL_Log("Failed to Create Renderer: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

}

Game::~Game() {
    if (renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }
    if (window != nullptr) {
        SDL_DestroyWindow(window);
    }

    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

State& Game::GetState() {
    return *state;
}

SDL_Renderer* Game::GetRenderer() {
    return renderer;
}

void Game::Run() {
    while (!state->QuitRequested()) {
        state->Update(13);
        state->Render();
        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
}