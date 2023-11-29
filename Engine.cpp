#include "Engine.h"

Engine::Engine()
{
    int width = VideoMode::getDesktopMode().width;
    int height = VideoMode::getDesktopMode().height;
    VideoMode vm(width, height);
    RenderWindow window(vm, "Farticles", Style::Default);
}

void Engine::run()
{
    Clock c;
    Particle p;
    while (m_Window )
}

void Engine::input()
{

}

void Engine::update(float dtAsSeconds)
{

}

void Engine::draw()
{

}