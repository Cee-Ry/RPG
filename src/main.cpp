#include <SFML/Graphics.hpp>

void close_window(sf::RenderWindow &window);

int main() {
  const float WIDTH = 1366.0f;
  const float HEIGHT = 768.0f;
  
  sf::RenderWindow window;
  window.create(sf::VideoMode({(int)WIDTH, (int)HEIGHT}), "RougeLIke");
  
  sf::Texture background;

  if (!background.loadFromFile("assets/textures/backgrounds/bg.png")) return -1;

  sf::Sprite background_sprite(background);

  background_sprite.setScale(sf::Vector2f(WIDTH / background.getSize().x, HEIGHT / background.getSize().y));

  while(window.isOpen()) {
    close_window(window);

    window.clear(sf::Color::Black);
    window.draw(background_sprite);
    window.display();
  }

  return 0;
}

// making this func to make the main loop look cleaner
void close_window(sf::RenderWindow &window) {
  while(const std::optional event = window.pollEvent()) 
    if (event->is<sf::Event::Closed>()) 
      window.close();
}
