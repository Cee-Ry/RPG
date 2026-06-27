#include <SFML/Graphics.hpp>
#include <string>

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
  int total_buttons = 8;
  sf::Texture buttons[total_buttons];

  if (!background.loadFromFile("assets/textures/backgrounds/bg.png")) return -1;
  for (int i = 0; i < total_buttons; i++) {
    std::string buttons_path = "assets/textures/ui/buttons/button" + std::to_string(i+1) + ".png";
    if (!buttons[i].loadFromFile(buttons_path)) return 0;;
  }

  sf::Sprite background_sprite(background);
  sf::Sprite btn_new_run(buttons[0]);
  sf::Sprite btn_continue(buttons[1]);

  background_sprite.setScale(sf::Vector2f(WIDTH / background.getSize().x, HEIGHT / background.getSize().y));

  btn_new_run.setScale(sf::Vector2f(1.0f, 1.0f));
  float btn_width = buttons[0].getSize().x;
  float btn_height = (HEIGHT * 0.20f);
  btn_new_run.move(sf::Vector2f((WIDTH / 2) - (btn_width / 2), btn_height));

  sf::Font font;
  if (!font.openFromFile("assets/fonts/HackNerdFont-Bold.ttf")) return -1;

  sf::Text title(font, "Role Playing Game", 38);
  sf::FloatRect titleBounds = title.getLocalBounds();
  float title_width = titleBounds.size.x;
  title.setPosition(sf::Vector2f((WIDTH / 2) - (title_width / 2), 40.0f));
  title.setFillColor(sf::Color::White);

  while(window.isOpen()) {
    close_window(window);

    window.clear(sf::Color::Black);
    window.draw(background_sprite);
    window.draw(title);
    window.draw(btn_new_run);
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
