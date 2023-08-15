#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include "cartes.h"
#include "tapis.h"
#include "jeuComplet.h"
#include "mouseEventHandler.h"


void carte();
void jeuComplet();

int main()
{
    //carte();
    jeuComplet();
    return 0;
}


void jeuComplet() {
    sf::VideoMode terminalSize = sf::VideoMode::getDesktopMode();
    unsigned int largeurFenetre = terminalSize.width * 3 / 4;
    unsigned int hauteurFenetre = terminalSize.height * 3 / 4;
    sf::RenderWindow window(sf::VideoMode(largeurFenetre, hauteurFenetre), "AFFICHAGE DES CARTES");
    unsigned int positionFenetreX = (terminalSize.width - largeurFenetre) / 2;
    unsigned int positionFenetreY = (terminalSize.height - hauteurFenetre) / 2;
    window.setPosition(sf::Vector2i(positionFenetreX, positionFenetreY));

    JeuComplet jeu; 

    sf::Vector2f cardPosition(10.f, 10.f);
    sf::Vector2f cardSpacing(100.f, 0.f);
    unsigned int cardWidth = 80; 

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        Liste<Carte>* listeCartes = jeu.getCartes(); 
        float X = cardPosition.x;
        float Y = cardPosition.y;

        for (size_t i = 0; i < listeCartes->nombreDElement(); ++i) {
            Carte carte = listeCartes->obtenir(i);
            carte.echelleAuto(100);
            carte.setPosition(X, Y);
            X += 10;
            Y += 10;
            carte.render(window);
        }

        sf::Vector2u taillefenetre = window.getSize();
        sf::Texture aspectTapis;
        if (!aspectTapis.loadFromFile("cartes_img/HD1.jpg")) {
            std::cerr << "erreur" << std::endl;
        }
        Tapis tapis(aspectTapis);
        tapis.echelleAuto(taillefenetre.x, taillefenetre.y);

        tapis.render(window);
        window.display();
    }
}

void carte() {
    sf::VideoMode terminalSize = sf::VideoMode::getDesktopMode();
    unsigned int largeurFenetre = terminalSize.width * 3 / 4;
    unsigned int hauteurFenetre = terminalSize.height * 3 / 4;
    sf::RenderWindow window(sf::VideoMode(largeurFenetre, hauteurFenetre), "FREECELL");
    unsigned int positionFenetreX = (terminalSize.width - largeurFenetre) / 2;
    unsigned int positionFenetreY = (terminalSize.height - hauteurFenetre) / 2;
    window.setPosition(sf::Vector2i(positionFenetreX, positionFenetreY));
    
    sf::Texture faceCarte;
    if (!faceCarte.loadFromFile("cartes_img/face/113-coeur.png")) {
        std::cerr << "erreur" << std::endl;
    }
    
    Carte carte(valeur_13, coeur, faceCarte);
    carte.echelleAuto(150);
    float centreX = largeurFenetre / 2;
    float centreY = hauteurFenetre / 2;
    carte.setPosition(10, 10);

    sf::Vector2u taillefenetre = window.getSize();
    sf::Texture aspectTapis;
    if (!aspectTapis.loadFromFile("cartes_img/HD1.jpg")) {
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
                    mouseHandler.updateCartePosition(mousePosition, carte, window);                   
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

