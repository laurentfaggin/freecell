#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "Couleur.h"
#include "Valeur.h"

class Carte
{
public:
    Carte();
    Carte(int p_valeur, Couleur p_couleur, sf::Texture& p_texture);
    //Carte(Valeur p_valeur, Couleur p_couleur, sf::Texture& p_texture);
    ~Carte();
    void render(sf::RenderTarget& renderWindow);
    void echelleAuto(unsigned int p_largeurCarte);
    void setPosition(float x, float y);
    void setClick(bool click);
    bool getClick();
    int valeur();
    void setDeplacement(const sf::Vector2f& deplacement);
    sf::Vector2f getScale();
    sf::Vector2u getSizeCarte();
    sf::Vector2f getPosition() const;
    sf::Texture getTexture();

   
private:
    sf::Sprite *m_sprite;
    int m_valeur;
    //Valeur m_valeur;
    Couleur m_couleur;
    bool m_click;
    sf::Vector2f m_deplacement;
};