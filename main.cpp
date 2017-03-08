#include <SFML/Graphics.hpp>
#include <iostream>
#define WIDE 800
#define HIGH 600

#define TILESIZE 32

int main()
{
  sf::RenderWindow window(sf::VideoMode(WIDE,HIGH),"Adventure!");

sf::CircleShape circle(10);

circle.setFillColor(sf::Color::Yellow);

circle.setPosition(100,100);

  sf::Texture hero_texture;
  if(!hero_texture.loadFromFile("assets/hero.png"))
  {
      std::cout << "Error loading hero texture!" << std::endl;
  }
  sf::Sprite hero;
  hero.setTexture(hero_texture);
  hero.Scale(sf::Vector2f(2,2));

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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && hero.getPosition().y < HIGH-TILESIZE)
    {
      hero.move(0,heroSpeed);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && hero.getPosition().x > 0)
    {
      hero.move(-heroSpeed,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && hero.getPosition().x < WIDE-TILESIZE)
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
