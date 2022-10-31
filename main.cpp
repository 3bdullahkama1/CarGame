#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

struct rectangle
{
    int x, y;
    rectangle(int xValue, int yValue) : x(xValue), y(yValue) {}
};

int main()
{

    RenderWindow window(VideoMode(800, 600), "game...");
    rectangle carPosition(350, 450);
    RectangleShape rec;
    rec.setSize(Vector2f(100, 150));
    rec.setPosition(Vector2f(carPosition.x, carPosition.y));
    rec.setFillColor(Color(50, 50, 200));

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::Up && carPosition.y >= 0)
                {
                    carPosition.y -= 3;
                }
                if (event.key.code == Keyboard::Down && carPosition.y <= 450)
                {
                    carPosition.y += 3;
                }
                if (event.key.code == Keyboard::Left && carPosition.x >= 0)
                {
                    carPosition.x -= 3;
                }
                if (event.key.code == Keyboard::Right && carPosition.x <= 700)
                {
                    carPosition.x += 3;
                }
                rec.setPosition(Vector2f(carPosition.x, carPosition.y));
            }
        }

        window.clear();
        window.draw(rec);
        window.display();
    }

    return 0;
}