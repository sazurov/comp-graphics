#pragma once

#include <SFML/Graphics.hpp>

class Flower : public sf::Drawable, public sf::Transformable {
public:
  enum class PartType { None, Head, Petal };

  struct PartRef {
    PartType type = PartType::None;
    int index = -1; // индекс лепестка, если type == Petal

    bool isValid() const { return type != PartType::None; }
  };

  Flower();

  void setPosition(const sf::Vector2f &pos);
  using sf::Transformable::setPosition;

  sf::FloatRect getGlobalBounds() const;

  bool contains(const sf::Vector2f &point) const;

  PartRef pickPart(const sf::Vector2f &point) const;

  bool hitBody(const sf::Vector2f &point) const;

  sf::Vector2f getPartWorldPosition(const PartRef &part) const;

  void detachPart(const PartRef &part);

  void setPartWorldPosition(const PartRef &part, const sf::Vector2f &pos);

  void tryAttachBack(const PartRef &part, float snapDistance = 35.f);

private:
  struct PetalData {
    sf::CircleShape shape;
    bool attached = true;
    sf::Vector2f baseOffset{};
  };

  sf::CircleShape m_center;
  bool m_centerAttached = true;
  sf::Vector2f m_centerBaseOffset{0.f, 0.f};

  std::vector<PetalData> m_petals;
  sf::RectangleShape m_stem;
  std::vector<sf::CircleShape> m_leaves;

  virtual void draw(sf::RenderTarget &target,
                    sf::RenderStates states) const override;
};
