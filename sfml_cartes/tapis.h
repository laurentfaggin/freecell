#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Tapis {
public:
	Tapis(sf::Texture& p_texture);
	void render(sf::RenderTarget& renderWindow);
	void echelleAuto(unsigned int p_largeurFenetre, unsigned int p_hauteurFenetre);
	sf::Texture getTexture();

private:
	sf::Sprite m_sprite;
};
