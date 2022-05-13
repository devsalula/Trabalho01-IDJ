#include "State.h"
#include "Sprite.h"
#include "SDL_include.h"

State::State() {
    quitRequested = false;
    bg = Sprite("img/ocean.jpg");
    music = Music("audio/stageState.ogg");
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
    bg.Render(0, 0);
}

bool State::QuitRequested() {
    return quitRequested;
}