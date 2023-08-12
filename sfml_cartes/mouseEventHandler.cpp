#include "MouseEventHandler.h"
#include <iostream>
#include <chrono>



void MouseEventHandler::MouseEvent(const sf::Event& event, const sf::RenderWindow& window, Carte& carte) {
    switch (event.type) {
    case sf::Event::MouseButtonPressed:
        mouseButtonPressed(event.mouseButton, window, carte);
        break;
    case sf::Event::MouseButtonReleased:
        mouseButtonReleased(event.mouseButton, carte);
        break;
    }
}

void MouseEventHandler::updateCartePosition(const sf::Vector2i& mousePosition, Carte& carte, const sf::RenderWindow& window, sf::Time delta) {
    
    sf::Vector2f cartePosition = carte.getPosition();
    //transformation position souris en coordonnees.
    sf::Vector2f mousePositionFloat = window.mapPixelToCoords(mousePosition);
    //valeur que j'utilise plus bas pour essayer d'ajuster la vitesse de la souris avec le deplacement de la carte.
    const float facteurVitesse = 5.5f;

    //mesure pour ajuster la position de la carte a l'ecran
    sf::Vector2f deplacement = sf::Vector2f(mousePositionFloat - carte.getPosition()) * (delta.asSeconds() * facteurVitesse);
    carte.setClick(true);
    sf::Vector2f nouvellePosition = carte.getPosition() + deplacement;
    sf::Vector2u tailleFenetre = window.getSize();
    float tailleCarteX = carte.getSizeCarte().x * carte.getScale().x;
    float tailleCarteY = carte.getSizeCarte().y * carte.getScale().y;

    //pour empecher la carte de sortir de la fenetre, fonctionne avec configuration de depart, 
    //mais des qu'on passe en fullscreen la carte sort de l'ecran
    nouvellePosition.x = std::max(nouvellePosition.x, 0.0f);
    nouvellePosition.x = std::min(nouvellePosition.x, static_cast<float>(tailleFenetre.x - tailleCarteX));
    nouvellePosition.y = std::max(nouvellePosition.y, 0.0f);
    nouvellePosition.y = std::min(nouvellePosition.y, static_cast<float>(tailleFenetre.y - tailleCarteY));

    carte.setPosition(nouvellePosition.x, nouvellePosition.y);
}

void MouseEventHandler::mouseButtonPressed(const sf::Event::MouseButtonEvent& event, const sf::RenderWindow& window, Carte& carte) {
    if (event.button == sf::Mouse::Left) {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        //ces deux parametres vont servir a rendre le deplacement fluide, sinon l'affichage est saccade
        sf::Clock clock;
        sf::Time delta = clock.restart();
        updateCartePosition(mousePosition, carte, window, delta);       
    }
}

void MouseEventHandler::mouseButtonReleased(const sf::Event::MouseButtonEvent& event, Carte& carte) {
    if (event.button == sf::Mouse::Left) {
        carte.setClick(false);
        std::cout << "click gauche relache." << std::endl;
    }
}
