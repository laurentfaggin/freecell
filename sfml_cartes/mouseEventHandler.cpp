#include "MouseEventHandler.h"
#include <iostream>



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

void MouseEventHandler::updateCartePosition(const sf::Vector2i& mousePosition, Carte& carte, const sf::RenderWindow& window) {
    
    sf::Vector2f cartePosition = carte.getPosition();
    //transformation position souris en coordonnees.
    sf::Vector2f mousePositionFloat = window.mapPixelToCoords(mousePosition);


    //mesure pour ajuster la position de la carte a l'ecran
    carte.setClick(true);
    sf::Vector2u tailleFenetre = window.getSize();
    float tailleCarteX = carte.getSizeCarte().x * carte.getScale().x;
    float tailleCarteY = carte.getSizeCarte().y * carte.getScale().y;
    carte.setPosition(tailleFenetre.x - tailleCarteX -10, cartePosition.y);

    //pour empecher la carte de sortir de la fenetre, fonctionne avec configuration de depart, 
    //mais des qu'on passe en fullscreen la carte sort de l'ecran
   
}

void MouseEventHandler::mouseButtonPressed(const sf::Event::MouseButtonEvent& event, const sf::RenderWindow& window, Carte& carte) {
    if (event.button == sf::Mouse::Left) {
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        //ces deux parametres vont servir a rendre le deplacement fluide, sinon l'affichage est saccade

        updateCartePosition(mousePosition, carte, window);       
    }
}

void MouseEventHandler::mouseButtonReleased(const sf::Event::MouseButtonEvent& event, Carte& carte) {
    if (event.button == sf::Mouse::Left) {
        carte.setClick(false);
        std::cout << "click gauche relache." << std::endl;
    }
}
