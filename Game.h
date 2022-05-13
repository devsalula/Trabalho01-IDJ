#ifndef GAME_H
#define GAME_H

#include "SDL_include.h"
#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER
#include "State.h"

#include<string>

class Game {
    private:
        static Game* instance;
        SDL_Window* window;
        SDL_Renderer* renderer;
        State* state;
        Game(string title, int height, int width);


    public:
        static Game& GetInstance();
        ~Game();
        void Run();
        SDL_Renderer* GetRenderer();
        State& GetState();
        Game& GetInstance();
};
#endif