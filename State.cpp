#include "State.h"
#include "Sprite.h"
#include "SDL_include.h"

State::State() {
    quitRequested = false;
    bg = Sprite("img/ocean.jpg");
}

void State::LoadAssets() {
    //TODO: LOAD GAME ASSETS
}

void State::Update(float dt) {
    if(SDL_QuitRequested() == SDL_TRUE) {
        quitRequested = true;
    }
}

void State::Render() {
    // TODO: Call bg Render
}

bool State::QuitRequested() {
    return quitRequested;
}