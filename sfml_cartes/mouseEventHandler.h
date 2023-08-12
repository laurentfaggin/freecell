#pragma once
#ifndef MOUSE_EVENT_HANDLER_H
#define MOUSE_EVENT_HANDLER_H

#include <SFML/Graphics.hpp>
#include "cartes.h"

class MouseEventHandler {
public:
	void MouseEvent(const sf::Event& event, const sf::RenderWindow& window, Carte& carte);
	void mouseButtonPressed(const sf::Event::MouseButtonEvent& event, const sf::RenderWindow& window, Carte& carte);
	void mouseButtonReleased(const sf::Event::MouseButtonEvent& event, Carte& carte);
	void updateCartePosition(const sf::Vector2i& mousePosition, Carte& carte, const sf::RenderWindow& window, sf::Time delta);

private:
};

#endif
