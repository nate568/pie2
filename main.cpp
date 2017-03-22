#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#define WIDE 800
#define HIGH 640

#define TILESIZE 32

bool testColl(sf::Sprite a, sf::Sprite b)
{
  return a.getGlobalBounds().intersects(b.getGlobalBounds());
}

  bool testWallColl(sf::Sprite a, std::vector<sf::Sprite> walls)
  {
    for(int i=0; i<walls.size(); i++)
    {
      if(a.getGlobalBounds().intersects(walls[i].getGlobalBounds()))
      {
        return true;
      }
    }
    return false;
  }

int main()
{  sf::RenderWindow window(sf::VideoMode(WIDE,HIGH),"Adventure!");

int tileW = WIDE/TILESIZE;
int tileH = WIDE/TILESIZE;

std::vector<std::vector<bool> > map;

for(int i=0; i<tileH; i++)
{
  std::vector<bool> temp;
  for(int j=0; j<tileW; j++)
    {
    temp.push_back(false);
  }
  map.push_back(temp);
}

map[12][3] = true;
map[12][4] = true;

  for(int i=0; i<map.size(); i++)
  {
    for(int j=0; j<map.size(); j++)
    {
      if(map[i][j] == true)
      {
        std::cout << '0';
      }
      else
      {
        std::cout << ' ';
      }
    }
    std::cout << std::endl;
  }
sf::Texture enemy_texture;
if(!enemy_texture.loadFromFile("assets/enemy2.png"))
{
    std::cout << "ERROR LOADING ENEMY TEXTURE" << std::endl;
}

sf::Sprite enemy;
enemy.setTexture(enemy_texture);
enemy.setScale(sf::Vector2f(2,2));

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




std::vector<sf::Sprite> wallArr;
for(int i=0; i<map.size(); i++)
{
  for(int j=0; j<map.size(); j++)
  {
    if(map[i][j] == true)
    {
      sf::Sprite temp;
      temp.setTexture(wall_texture);
      temp.setScale(sf::Vector2f(2,2));
      temp.setPosition(j*TILESIZE,i*TILESIZE);
      wallArr.push_back(temp);
    }
  }
}

sf::Texture grass_texture;
if(!grass_texture.loadFromFile("assets/grass.png"))
{
  std::cout << "Error loading grass texture!" << std::endl;
}

sf::Sprite grass;
grass.setTexture(grass_texture);
grass.setScale(sf::Vector2f(2,2));


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
      if(testWallColl(hero,wallArr))
      {
        hero.move(0,heroSpeed);
      }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && hero.getPosition().y < HIGH-TILESIZE)
    {
      hero.move(0,heroSpeed);


      if(testWallColl(hero,wallArr))
      {
        hero.move(0,-heroSpeed);
      }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && hero.getPosition().x > 0)
    {
      hero.move(-heroSpeed,0);
      if(testWallColl(hero,wallArr))
      {
      hero.move(heroSpeed,0);
      }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && hero.getPosition().x < WIDE-TILESIZE)
    {
      hero.move(heroSpeed,0);
      if(testWallColl(hero,wallArr))
      {
      hero.move(-heroSpeed,0);
      }
    }

    if(testWallColl(hero,wallArr))
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
  //std::cout << lives << std::endl;
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

      for(int i=0; i<tileH ; i++)
      {
        for(int j=0; j<tileW ; j++)
        {
          grass.setPosition(j*TILESIZE, i*TILESIZE);
          window.draw(grass);
      }
    }
    window.draw(enemy);
    for(int i=0; i<wallArr.size(); i++)
    {
        window.draw(wallArr[i]);
    }
    window.draw(livesDisp);
    window.draw(hero);
    window.display();
  }
}
