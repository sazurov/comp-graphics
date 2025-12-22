#pragma once

#include "Flower.hpp"
#include <SFML/Graphics.hpp>

class Application {
public:
  Application(unsigned int width = 800, unsigned int height = 600);

  void run();

private:
  enum class DragKind { None, WholeFlower, FlowerPart };

  sf::RenderWindow m_window;
  Flower m_flower;

  DragKind m_dragKind = DragKind::None;
  Flower::PartRef m_dragPart{};
  sf::Vector2f m_dragOffset{};
  void processEvents();
  void handleMousePressed(const sf::Event::MouseButtonEvent &event);
  void handleMouseReleased(const sf::Event::MouseButtonEvent &event);
  void handleMouseMoved(const sf::Event::MouseMoveEvent &event);
  void update();
  void render();
};
