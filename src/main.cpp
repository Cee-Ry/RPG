#include <SFML/Graphics.hpp>

void close_window(sf::RenderWindow &window);

int main() {
  sf::RenderWindow window;
  window.create(sf::VideoMode({1366, 768}), "RougeLIke");

  while(window.isOpen()) {
    close_window(window);

    window.clear(sf::Color::Black);
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
