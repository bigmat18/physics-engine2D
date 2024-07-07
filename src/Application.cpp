#include "Application.hpp"
#include "Utils.hpp"
#include <iostream>
#include <imgui.h>
#include <imgui_impl_sdl3.h>
#include <imgui_impl_sdlrenderer3.h>

void Application::Initialize()
{
    CC(SDL_Init(SDL_INIT_VIDEO));
    m_Window   =   static_cast<SDL_Window *>(CP(SDL_CreateWindow(m_WindowName, m_Width, m_Height, SDL_WINDOW_RESIZABLE)));
    m_Renderer =   static_cast<SDL_Renderer*>(CP(SDL_CreateRenderer(m_Window, NULL)));

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    ImGui::StyleColorsDark();

    ImGui_ImplSDL3_InitForSDLRenderer(m_Window, m_Renderer);
    ImGui_ImplSDLRenderer3_Init(m_Renderer);

    m_TicksCount = SDL_GetTicks();
}

void Application::Shutdown()
{
    SDL_DestroyWindow(m_Window);
    SDL_DestroyRenderer(m_Renderer);
    SDL_Quit();
}

void Application::Run()
{
    while (m_IsRunning)
    {
        Input();
        Update();
        Render();
    }
}

void Application::Input()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        ImGui_ImplSDL3_ProcessEvent(&event);
        switch (event.type)
        {
        case SDL_EVENT_QUIT:
            m_IsRunning = false;
            break;
        }
    }
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_ESCAPE])
        m_IsRunning = false;
}

void Application::Update()
{
    float deltaTime = GetDeltaTime();
}

void Application::Render()
{
    ImGui_ImplSDLRenderer3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();

    bool show_demo_window = false;
    if (show_demo_window)
        ImGui::ShowDemoWindow(&show_demo_window);

    ImGui::Render();

    SDL_RenderClear(m_Renderer);

    SDL_SetRenderDrawColor(m_Renderer, 0, 0, 255, 255);
    SDL_FRect rect = {0.0f, 0.0f, 50.0f, 50.0f};
    SDL_RenderFillRect(m_Renderer, &rect);

    ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), m_Renderer);
    SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
    SDL_RenderPresent(m_Renderer);
}

float Application::GetDeltaTime() {
    uint64_t now = SDL_GetTicks();
    float deltaTime = now - m_TicksCount;
    m_TicksCount = now;

    if (deltaTime > 0.05f)
        deltaTime = 0.05f;

    return deltaTime;
}