#include <string>
#include <SFML/Graphics.hpp>
#include "tapis.h"

Tapis::Tapis(sf::Texture& p_texture)
{
	this->m_sprite.setTexture(p_texture);
}

void Tapis::render(sf::RenderTarget& renderWindow) {
	renderWindow.draw(m_sprite);
}

sf::Texture Tapis::getTexture() {
	return *m_sprite.getTexture();
}

void Tapis::echelleAuto(unsigned int p_largeurFenetre, unsigned int p_hauteurFenetre) {
    sf::Vector2u textureSize = m_sprite.getTexture()->getSize();

    float scaleX = static_cast<float>(p_largeurFenetre) / textureSize.x;
    float scaleY = static_cast<float>(p_hauteurFenetre) / textureSize.y;

    m_sprite.setScale(scaleX, scaleY);
}