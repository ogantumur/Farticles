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
        c.restart();
        c.getElapsedTime().asSeconds();
        // convert to seconds???
        input();
        update(c.getElapsedTime().asSeconds());
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
    int i = 0;
    while (i < m_particles.size())
    {
        if (m_particles[i].getTTL() > 0.0)
        {
            m_particles[i].update(dtAsSeconds);
            i++;
        }
        else
        {
            m_particles.erase(m_particles.begin() + i);
            // assign i???
        }
    }
}

void Engine::draw()
{
    m_Window.clear();
    for (int i = 0; i < m_particles.size(); i++)
    {
        m_Window.draw(m_particles[i]);
        m_Window.display();
    }
}