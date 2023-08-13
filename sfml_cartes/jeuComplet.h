#pragma once
#include <vector>
#include <string>
#include "cartes.h"


class JeuComplet {
public:
	JeuComplet();
	~JeuComplet();

	std::string couleurToString(Couleur p_couleur);
	std::string cheminTexture(Couleur p_couleur);

private:
	Carte* m_cartes;
};
