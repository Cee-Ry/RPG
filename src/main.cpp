#include <SFML/Graphics.hpp>

// for libraries that doesn't support cross platform
#ifdef __linux__ 
  #include <X11/Xlib.h>
#elif _WIN32
#endif

void close_window(sf::RenderWindow &window);

int main() {
  // get screen resolution
  #ifdef __linux__ // for linux via X11
    Display* display = XOpenDisplay(NULL);
    int screen = DefaultScreen(display);
    const float WIDTH = (float)XDisplayWidth(display, screen);
    const float HEIGHT = (float)XDisplayHeight(display, screen);
    XCloseDisplay(display);
  #elif _WIN32 // for Windows
  #endif 
  
  sf::RenderWindow window;
  window.create(sf::VideoMode({(unsigned int)WIDTH, (unsigned int)HEIGHT}), "RougeLIke");
  
  sf::Texture background;
  if (!background.loadFromFile("assets/textures/backgrounds/bg.png")) return -1;
  sf::Sprite background_sprite(background);
  background_sprite.setScale(sf::Vector2f(WIDTH / background.getSize().x, HEIGHT / background.getSize().y));

  sf::Font font;
  if (!font.openFromFile("assets/fonts/HackNerdFont-Bold.ttf")) return -1;

  sf::Text title(font, "Role Playing Game", 24);
  title.setFillColor(sf::Color::White);

  while(window.isOpen()) {
    close_window(window);

    window.clear(sf::Color::Black);
    window.draw(background_sprite);
    window.draw(title);
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
