#include <string>
#include <SFML/Graphics.hpp>
#include "cartes.h"

Carte::Carte() { ; }

Carte::Carte(Valeur p_valeur, Couleur p_couleur, sf::Texture& p_texture) :m_valeur(p_valeur), m_couleur(p_couleur) {
	this->m_sprite = new sf::Sprite(p_texture);
}

Carte::~Carte() { ; }

void Carte::render(sf::RenderTarget& renderWindow) {
	renderWindow.draw(*m_sprite);
}

void Carte::echelleAuto(unsigned int largeurCarte) {
	sf::Vector2u textureSize = m_sprite->getTexture()->getSize();
	float scale = static_cast<float>(largeurCarte) / textureSize.x;
	m_sprite->setScale(scale, scale);
}

void Carte::setPosition(float x, float y) {
	m_sprite->setPosition(x, y);
}

void Carte::setClick(bool click) {
	m_click = click;;
}

void Carte::setDeplacement(const sf::Vector2f& deplacement) {
	this->m_deplacement = deplacement;
}

sf::Vector2f Carte::getScale() {
	return this->m_sprite->getScale();
}

bool Carte::getClick() {
	return this->m_click;
}

sf::Vector2u Carte::getSizeCarte() {
	return m_sprite->getTexture()->getSize();
}

sf::Vector2f Carte::getPosition() const {
	return m_sprite->getPosition();
}

sf::Texture Carte::getTexture() {
	return *m_sprite->getTexture();
}


