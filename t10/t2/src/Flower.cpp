#include "../include/Flower.hpp"
#include <cmath>

Flower::Flower() {
  m_center.setRadius(25.f);
  m_center.setFillColor(sf::Color(255, 215, 0)); // золотистый
  m_center.setOrigin(m_center.getRadius(), m_center.getRadius());
  m_center.setPosition(m_centerBaseOffset);

  const int petalCount = 8;
  const float petalRadius = 20.f;
  const float petalDistance = 40.f;

  for (int i = 0; i < petalCount; ++i) {
    PetalData pd;
    pd.shape = sf::CircleShape(petalRadius);
    pd.shape.setFillColor(sf::Color(255, 105, 180)); // розовый
    pd.shape.setOrigin(petalRadius, petalRadius);

    float angle = 2.f * 3.1415926f * i / petalCount;
    sf::Vector2f offset(std::cos(angle) * petalDistance,
                        std::sin(angle) * petalDistance);
    pd.baseOffset = offset;
    pd.shape.setPosition(offset);
    pd.attached = true;
    m_petals.push_back(pd);
  }

  m_stem.setSize(sf::Vector2f(15.f, 160.f));
  m_stem.setFillColor(sf::Color(34, 139, 34)); // тёмно-зелёный
  m_stem.setOrigin(m_stem.getSize().x / 2.f, 0.f);
  m_stem.setPosition(0.f, m_center.getRadius());

  const float leafRadius = 18.f;
  for (int i = 0; i < 2; ++i) {
    sf::CircleShape leaf(leafRadius, 30);
    leaf.setFillColor(sf::Color(50, 205, 50)); // ярко-зелёный
    leaf.setOrigin(leafRadius, leafRadius);
    float y = m_center.getRadius() + 40.f + i * 40.f;
    float x = (i % 2 == 0) ? -25.f : 25.f;
    leaf.setPosition(x, y);
    leaf.setScale(1.4f, 0.8f);
    m_leaves.push_back(leaf);
  }
}

void Flower::setPosition(const sf::Vector2f &pos) {
  sf::Transformable::setPosition(pos);
}

sf::FloatRect Flower::getGlobalBounds() const {
  sf::FloatRect bounds(-80.f, -30.f, 160.f, 230.f);
  sf::Transform transform = getTransform();
  return transform.transformRect(bounds);
}

bool Flower::contains(const sf::Vector2f &point) const {
  return getGlobalBounds().contains(point);
}

Flower::PartRef Flower::pickPart(const sf::Vector2f &point) const {
  sf::Vector2f centerWorld;
  if (m_centerAttached) {
    centerWorld = getPosition() + m_centerBaseOffset;
  } else {
    centerWorld = m_center.getPosition();
  }
  float r = m_center.getRadius();
  sf::Vector2f d = point - centerWorld;
  if (d.x * d.x + d.y * d.y <= r * r) {
    return PartRef{PartType::Head, -1};
  }

  for (std::size_t i = 0; i < m_petals.size(); ++i) {
    const auto &pd = m_petals[i];
    sf::Vector2f petalWorld;
    if (pd.attached) {
      petalWorld = getPosition() + pd.baseOffset;
    } else {
      petalWorld = pd.shape.getPosition();
    }
    float pr = pd.shape.getRadius();
    sf::Vector2f dp = point - petalWorld;
    if (dp.x * dp.x + dp.y * dp.y <= pr * pr) {
      return PartRef{PartType::Petal, static_cast<int>(i)};
    }
  }

  return PartRef{};
}

bool Flower::hitBody(const sf::Vector2f &point) const {
  return getGlobalBounds().contains(point);
}

sf::Vector2f Flower::getPartWorldPosition(const PartRef &part) const {
  if (!part.isValid()) {
    return getPosition();
  }

  if (part.type == PartType::Head) {
    if (m_centerAttached) {
      return getPosition() + m_centerBaseOffset;
    }
    return m_center.getPosition();
  }

  if (part.type == PartType::Petal && part.index >= 0 &&
      static_cast<std::size_t>(part.index) < m_petals.size()) {
    const auto &pd = m_petals[static_cast<std::size_t>(part.index)];
    if (pd.attached) {
      return getPosition() + pd.baseOffset;
    }
    return pd.shape.getPosition();
  }

  return getPosition();
}

void Flower::detachPart(const PartRef &part) {
  if (!part.isValid())
    return;

  if (part.type == PartType::Head) {
    if (m_centerAttached) {
      m_centerAttached = false;
      m_center.setPosition(getPosition() + m_centerBaseOffset);
    }
    return;
  }

  if (part.type == PartType::Petal && part.index >= 0 &&
      static_cast<std::size_t>(part.index) < m_petals.size()) {
    auto &pd = m_petals[static_cast<std::size_t>(part.index)];
    if (pd.attached) {
      pd.attached = false;
      pd.shape.setPosition(getPosition() + pd.baseOffset);
    }
  }
}

void Flower::setPartWorldPosition(const PartRef &part,
                                  const sf::Vector2f &pos) {
  if (!part.isValid())
    return;

  if (part.type == PartType::Head) {
    if (!m_centerAttached) {
      m_center.setPosition(pos);
    }
    return;
  }

  if (part.type == PartType::Petal && part.index >= 0 &&
      static_cast<std::size_t>(part.index) < m_petals.size()) {
    auto &pd = m_petals[static_cast<std::size_t>(part.index)];
    if (!pd.attached) {
      pd.shape.setPosition(pos);
    }
  }
}

void Flower::tryAttachBack(const PartRef &part, float snapDistance) {
  if (!part.isValid())
    return;

  const float snap2 = snapDistance * snapDistance;

  if (part.type == PartType::Head) {
    if (!m_centerAttached) {
      sf::Vector2f worldNow = m_center.getPosition();
      sf::Vector2f target = getPosition() + m_centerBaseOffset;
      sf::Vector2f d = worldNow - target;
      if (d.x * d.x + d.y * d.y <= snap2) {
        m_centerAttached = true;
        m_center.setPosition(m_centerBaseOffset);
      }
    }
    return;
  }

  if (part.type == PartType::Petal && part.index >= 0 &&
      static_cast<std::size_t>(part.index) < m_petals.size()) {
    auto &pd = m_petals[static_cast<std::size_t>(part.index)];
    if (!pd.attached) {
      sf::Vector2f worldNow = pd.shape.getPosition();
      sf::Vector2f target = getPosition() + pd.baseOffset;
      sf::Vector2f d = worldNow - target;
      if (d.x * d.x + d.y * d.y <= snap2) {
        pd.attached = true;
        pd.shape.setPosition(pd.baseOffset);
      }
    }
  }
}

void Flower::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  sf::RenderStates flowerStates = states;
  flowerStates.transform *= getTransform();

  target.draw(m_stem, flowerStates);

  for (const auto &leaf : m_leaves) {
    target.draw(leaf, flowerStates);
  }

  for (const auto &pd : m_petals) {
    if (pd.attached) {
      target.draw(pd.shape, flowerStates);
    } else {
      target.draw(pd.shape, states);
    }
  }

  if (m_centerAttached) {
    target.draw(m_center, flowerStates);
  } else {
    target.draw(m_center, states);
  }
}
