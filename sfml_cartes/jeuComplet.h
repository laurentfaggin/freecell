#pragma once
#include <string>
#include "cartes.h"
#include "listeGenerique.h"


class JeuComplet {
public:
	JeuComplet();
	~JeuComplet();
	Liste<Carte>* getCartes();

	std::string couleurToString(Couleur p_couleur);
	std::string cheminTexture(int i, Couleur p_couleur);

private:
	Liste<Carte>* m_cartes;
};
