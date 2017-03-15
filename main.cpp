#include <SFML/Graphics.hpp>
#include <iostream>
#define WIDE 800
#define HIGH 600

#define TILESIZE 32

int main()
{
  sf::RenderWindow window(sf::VideoMode(WIDE,HIGH),"Adventure!");
sf::Texture enemy_texture;
if(!enemy_texture,loadFromFile("assets/enemy2.png"))
{
    std::cout << "ERROR LOADING ENEMY TEXTURE" << std::endl;
    sf::Sprite enemy;
    enemy.setTexture(enemy_texture)
    enemy.setScale(sf::Vector2f(2,2));
}
sf::enemyShape enemy(10);


enemy.setFillColor(sf::Color::Yellow);

enemy.setPosition(100,100);

sf::Font font;
if(!font.loadFromFile("assets/ARCADECLASSIC.TTF"))
{
  std::cout << "Error loading fount!" << std::endl;
}
sf::Text livesDisp;
livesDisp.setFont(font);
livesDisp.setCharacterSize(24);
livesDisp.setColor(sf::Color::White);
livesDisp.setString("test");

  sf::Texture hero_texture;
  if(!hero_texture.loadFromFile("assets/hero.png"))
  {
      std::cout << "Error loading hero texture!" << std::endl;
  }
  sf::Sprite hero;
  hero.setTexture(hero_texture);
  hero.scale(sf::Vector2f(2,2));

sf::Texture wall_texture;
if(!wall_texture.loadFromFile("assets/stone_wall.png"))
{
  std::cout << "Error loading wall texture!" << std::endl;
}

sf::Sprite wall;
wall.setTexture(wall_texture);
wall.setScale(sf::Vector2f(2,2))

int enemyDir = 0;
double heroSpeed = .5;

int lives = 10;
bool takingDamage = false;

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
        if(hero.getGlobleBounds().intersect(wall.getGlobalBounds()))
      {
      hero.move(0,heroSpeed);
      }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && hero.getPosition().y < HIGH-TILESIZE)
    {
      hero.move(0,-heroSpeed);


      if(hero.getGlobleBounds().intersect(wall.getGlobalBounds()))
    {
    hero.move(0,heroSpeed);
    }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && hero.getPosition().x > 0)
    {
      hero.move(heroSpeed,0);
      if(hero.getGlobleBounds().intersect(wall.getGlobalBounds()))
    {
    hero.move(0,-heroSpeed);
    }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && hero.getPosition().x < WIDE-TILESIZE)
    {
      hero.move(-heroSpeed,0);
      if(hero.getGlobleBounds().intersect(wall.getGlobalBounds()))
    {
    hero.move(0,heroSpeed);
    }
    }

    if(hero.getGlobalBounds().intersects(enemy.getGlobalBounds()))
    {

      if(takingDamage == false)
      {
        lives--;
        takingDamage = true;
      }
    }
  else
  {
  takingDamage = false;
  }
  std::cout << lives << std::endl;
  livesDisp.setString(std::to_string(lives));

    window.clear(sf::Color::Blue);

    if(enemyDir == 0)
    {
      enemy.move(.5, 0);
    }
    else
    {
      enemy.move(-.5,0);
    }

    if(enemy.getPosition().x > 780)
    {
      enemyDir = 1;
    }
    if(enemy.getPosition().x < 0)
    {
      enemyDir = 0;
    }
    c
    window.draw(wall);
    window.draw(enemy);
    window.draw(livesDisp);
    window.draw(hero);
    window.display();
  }
}
