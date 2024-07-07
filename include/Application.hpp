#pragma once
#include <SDL3/SDL.h>

class Application
{
public:
    void Initialize();
    void Shutdown();
    void Run();

private:
    void Input();
    void Update();
    void Render();
    float GetDeltaTime();

    bool m_IsRunning = true;
    SDL_Window *m_Window;
    SDL_Renderer *m_Renderer;
    uint64_t m_TicksCount;

    uint32_t m_Width = 1200;
    uint32_t m_Height = 800;
    const char* m_WindowName = "Application";
};