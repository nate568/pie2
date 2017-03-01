#include <SFML/Graphics.hpp>
#include <iostream>
#define WIDE 800
#define HIGH 600

int main()
{
  sf::RenderWindow window(sf::VideoMode(WIDE,HIGH),"Adventure!");

sf::CircleShape circle(10);

circle.setFillColor(sf::Color::Yellow);

circle.setPosition(100,100);

  sf::RectangleShape hero(sf::Vector2f(11,11));
  hero.setFillColor(sf::Color::Black);
  hero.setPosition(400,300);
int circleDir = 0;
double heroSpeed = .5;

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

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && hero.getPosition().y > 0)
    {
      hero.move(0,-heroSpeed);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && hero.getPosition().y < HIGH-hero.getSize().y)
    {
      hero.move(0,heroSpeed);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && hero.getPosition().x > 0)
    {
      hero.move(-heroSpeed,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && hero.getPosition().x < WIDE-hero.getSize().x)
    {
      hero.move(heroSpeed,0);
    }

    if(hero.getGlobalBounds().intersects(circle.getGlobalBounds()))
    {
      std::cout << "touching" << std::endl;
    }
    window.clear(sf::Color::Blue);

    if(circleDir == 0)
    {
      circle.move(.5, 0);
    }
    else
    {
      circle.move(-.5,0);
    }

    if(circle.getPosition().x > 780)
    {
      circleDir = 1;
    }
    if(circle.getPosition().x < 0)
    {
      circleDir = 0;
    }
    window.draw(hero);
    window.draw(circle);
    window.display();
  }
}
