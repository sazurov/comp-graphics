#include "../include/Application.hpp"

Application::Application(unsigned int width, unsigned int height)
    : m_window(sf::VideoMode(width, height), "Flower Drag-and-Drop") {
  m_window.setVerticalSyncEnabled(true);

  sf::Vector2f center(static_cast<float>(width) / 2.f,
                      static_cast<float>(height) / 2.f - 50.f);
  m_flower.setPosition(center);
}

void Application::run() {
  while (m_window.isOpen()) {
    processEvents();
    update();
    render();
  }
}

void Application::processEvents() {
  sf::Event event{};
  while (m_window.pollEvent(event)) {
    switch (event.type) {
    case sf::Event::Closed:
      m_window.close();
      break;
    case sf::Event::MouseButtonPressed:
      handleMousePressed(event.mouseButton);
      break;
    case sf::Event::MouseButtonReleased:
      handleMouseReleased(event.mouseButton);
      break;
    case sf::Event::MouseMoved:
      handleMouseMoved(event.mouseMove);
      break;
    default:
      break;
    }
  }
}

void Application::handleMousePressed(const sf::Event::MouseButtonEvent &event) {
  if (event.button != sf::Mouse::Left)
    return;

  sf::Vector2i pixelPos(event.x, event.y);
  sf::Vector2f worldPos = m_window.mapPixelToCoords(pixelPos);

  Flower::PartRef part = m_flower.pickPart(worldPos);
  if (part.isValid()) {
    m_dragKind = DragKind::FlowerPart;
    m_dragPart = part;

    m_flower.detachPart(m_dragPart);

    sf::Vector2f partPos = m_flower.getPartWorldPosition(m_dragPart);
    m_dragOffset = partPos - worldPos;
    return;
  }

  if (m_flower.hitBody(worldPos)) {
    m_dragKind = DragKind::WholeFlower;
    m_dragOffset = m_flower.getPosition() - worldPos;
  }
}

void Application::handleMouseReleased(
    const sf::Event::MouseButtonEvent &event) {
  if (event.button != sf::Mouse::Left)
    return;

  if (m_dragKind == DragKind::FlowerPart && m_dragPart.isValid()) {
    m_flower.tryAttachBack(m_dragPart, 40.f);
  }

  m_dragKind = DragKind::None;
  m_dragPart = Flower::PartRef{};
}

void Application::handleMouseMoved(const sf::Event::MouseMoveEvent &event) {
  if (m_dragKind == DragKind::None)
    return;

  sf::Vector2i pixelPos(event.x, event.y);
  sf::Vector2f worldPos = m_window.mapPixelToCoords(pixelPos);

  if (m_dragKind == DragKind::WholeFlower) {
    m_flower.setPosition(worldPos + m_dragOffset);
  } else if (m_dragKind == DragKind::FlowerPart && m_dragPart.isValid()) {
    m_flower.setPartWorldPosition(m_dragPart, worldPos + m_dragOffset);
  }
}

void Application::render() {
  m_window.clear(sf::Color(135, 206, 235)); // светло-голубой фон (небо)

  sf::RectangleShape ground(
      sf::Vector2f(static_cast<float>(m_window.getSize().x), 150.f));
  ground.setFillColor(sf::Color(60, 179, 113));
  ground.setPosition(0.f, static_cast<float>(m_window.getSize().y) -
                              ground.getSize().y);
  m_window.draw(ground);

  m_window.draw(m_flower);

  m_window.display();
}
