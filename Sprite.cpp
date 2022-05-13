#include "Sprite.h"
#include "Game.h"

#include "SDL_include.h"

Sprite::Sprite() {
    texture = nullptr;
}

Sprite::Sprite(string file) {
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite() {
    SDL_DestroyTexture(texture);
}

void Sprite::Open(string file) {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }
    
    SDL_Texture* textureLoaded = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
    if (textureLoaded == nullptr) {
        SDL_Log("Failed to load Texture: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    
    int textureDimensions = SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    // SetClip(0, 0, )
}

void Sprite::SetClip(int x, int y, int w, int h) {
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::Render(int x, int y) {
    SDL_Rect* dst;
    dst->x = x;
    dst->y = y;
    dst->w = clipRect.w;
    dst->h = clipRect.h;
    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, dst);
}

int Sprite::GetHeight() {
    return height;
}

int Sprite::GetWidth() {
    return width;
}

bool Sprite::IsOpen() {
    return texture != nullptr;
}
