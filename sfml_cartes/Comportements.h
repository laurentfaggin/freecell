#pragma once
#include <SFML/Graphics.hpp>

template<class TypeElement>
class Comportements {
public:
	void setDeplacementObject(const sf::Vector2f& deplacement) = 0;
	bool getClickObject() = 0;
	sf::Vector2u getSizeObject() = 0;
	sf::Vector2f getPositionObject() = 0;
};