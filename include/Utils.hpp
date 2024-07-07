#pragma once
#include <SDL3/SDL.h>
#include <stdlib.h>

/** Check pointer */
static inline void* CP(void *ptr) {
    if(ptr == nullptr) {
        SDL_Log("%s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    return ptr;
}

/** Check code */
static inline void CC(int code) {
    if(code < 0) {
        SDL_Log("%s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    return;
}