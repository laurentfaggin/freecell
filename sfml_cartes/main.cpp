#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include "cartes.h"
#include "tapis.h"
#include "mouseEventHandler.h"

void circle();
void carte();

int main()
{
    //circle();
    carte();
    return 0;
}

void circle() {
    // Obtenez la résolution de l'écran
    sf::VideoMode terminalSize = sf::VideoMode::getDesktopMode();

    // Calcul des dimensions de la fenêtre pour obtenir les 3/4 de la résolution de l'écran
    unsigned int largeurFenetre = terminalSize.width * 3 / 4;
    unsigned int hauteurFenetre = terminalSize.height * 3 / 4;

    // Création fenêtre SFML centrée
    sf::RenderWindow window(sf::VideoMode(largeurFenetre, hauteurFenetre), "cercle");

    // Calcul de la position de la fenêtre pour la centrer
    unsigned int positionFenetreX = (terminalSize.width - largeurFenetre) / 2;
    unsigned int positionFenetreY = (terminalSize.height - hauteurFenetre) / 2;

    // Definition de la position de la fenêtre
    window.setPosition(sf::Vector2i(positionFenetreX, positionFenetreY));

    sf::CircleShape shape(200.f);
    shape.setFillColor(sf::Color::Green);

    float centreX = largeurFenetre / 2;
    float centreY = hauteurFenetre / 2;

    shape.setPosition(centreX - 200, centreY - 200);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}

void carte() {
    sf::VideoMode terminalSize = sf::VideoMode::getDesktopMode();
    unsigned int largeurFenetre = terminalSize.width * 3 / 4;
    unsigned int hauteurFenetre = terminalSize.height * 3 / 4;
    sf::RenderWindow window(sf::VideoMode(largeurFenetre, hauteurFenetre), "Jeu de cartes");
    unsigned int positionFenetreX = (terminalSize.width - largeurFenetre) / 2;
    unsigned int positionFenetreY = (terminalSize.height - hauteurFenetre) / 2;
    window.setPosition(sf::Vector2i(positionFenetreX, positionFenetreY));
    
    sf::Texture faceCarte;
    if (!faceCarte.loadFromFile("cartes_img/R-coeur.png")) {
        std::cerr << "erreur" << std::endl;
    }
    
    Carte carte(1, "coeur", faceCarte);
    carte.echelleAuto(150);
    float centreX = largeurFenetre / 2;
    float centreY = hauteurFenetre / 2;
    carte.setPosition(10, 10);

    sf::Vector2u taillefenetre = window.getSize();
    sf::Texture aspectTapis;
    if (!aspectTapis.loadFromFile("cartes_img/oldcar.jpg")) {
        std::cerr << "erreur" << std::endl;
    }
    Tapis tapis(aspectTapis);
    tapis.echelleAuto(taillefenetre.x, taillefenetre.y);
    MouseEventHandler mouseHandler;
    sf::Clock clock;
    sf::Time delta;

    const float facteurVitesse = 5.5f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            delta = clock.restart();
            mouseHandler.MouseEvent(event, window, carte);
            if (carte.getClick()) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    mouseHandler.updateCartePosition(mousePosition, carte, window, delta);                   
                }
            }
            if (event.type == sf::Event::Closed)
                window.close();
        }



        window.clear();
        tapis.render(window);
        carte.render(window);
        window.display();
    }
}

