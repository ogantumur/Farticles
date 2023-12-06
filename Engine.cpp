#include "Engine.h"

Engine::Engine()
{
    m_Window.create(VideoMode::getDesktopMode(), "Farticles", Style::Default);
}

void Engine::run()
{
    Clock c;
    cout << "Starting Particle unit tests..." << endl;
    Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
    p.unitTests();
    cout << "Unit tests complete.  Starting engine..." << endl;
    while (m_Window.isOpen())
    {
        Time dt = c.restart();
        float dtAsSeconds = dt.asSeconds();

        input();
        update(dtAsSeconds);
        draw();
    }
}

void Engine::input()
{
    Event event;
    while (m_Window.pollEvent(event))
    {
        if (event.type == Event::Closed)
        {
            m_Window.close();
        }
        if (event.type == Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == Mouse::Left)
            {
                for (int i = 0; i < 5; i++)
                {
                    Vector2i pos(event.mouseButton.x, event.mouseButton.y);
                    int numPoints = rand() % 26 + 25;
                    Particle p(m_Window, numPoints, pos);
                    m_particles.push_back(p);
                }
            }
        }
    }
}

void Engine::update(float dtAsSeconds)
{
    auto it = m_particles.begin();
    while (it != m_particles.end())
    {
        if (it->getTTL() > 0.0)
        {
            it->update(dtAsSeconds);
            it++;
        }
        else
        {
            it = m_particles.erase(it);
        }
    }
}

void Engine::draw()
{
    m_Window.clear();
    for (const Particle& particle : m_particles)
    {
        m_Window.draw(particle);
    }
    m_Window.display();
}