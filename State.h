#ifndef STATE_H
#define STATE_H

#include "Music.h"
#include "Sprite.h"
#include "SDL_include.h"
#define INCLUDE_SDL

class State {
    private:
        Sprite bg;
        Music music;
        bool quitRequested;
    
    public:
        State();
        bool QuitRequested();
        void LoadAssets();
        void Update(float dt);
        void Render();
};
#endif