#include <SFML/Graphics.hpp>

#define WIDE 800
#define HIGH 600

int main()
{
  sf::RenderWindow window(sf::VideoMode(WIDE,HIGH),"Adventure!");

sf::CircleShape circle(10);

circle.setFillColor(sf::Color::Yellow);

circle.setPosition(100,100);

while(window.isOpen())
  {
    sf::Event event;
    while(window.pollEvent(event))
    {
    if(event.type == sf::Event::Closed)
      {
        window.close();
      }
    }
    window.clear(sf::Color::Blue);

    circle.move(.2,.2);

    window.draw(circle);
    window.display();
  }
}
