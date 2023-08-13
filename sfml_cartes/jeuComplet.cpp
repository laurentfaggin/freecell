
#include <filesystem>
#include <iostream>
#include "jeuComplet.h"



std::string cheminDossier = "cartes_img/face";
std::string extensionFichier = ".png";

JeuComplet::JeuComplet() {
	this->m_cartes = new Carte[52];
	
	for (int i = 0; i < 52; ++i) {
		if (i < 13) {
			int j = 0;
			sf::Texture faceCarte;
			if (!faceCarte.loadFromFile(cheminTexture(coeur))) {
				std::cerr << "erreur" << std::endl;
			}
			Carte carte[j] (i+1, coeur, faceCarte);
			this->m_cartes[i] = carte[j];
		}	
		if (i < 26) {
			int j = 0;
			sf::Texture faceCarte;
			if (!faceCarte.loadFromFile(cheminTexture(carreaux))) {
				std::cerr << "erreur" << std::endl;
			}
			Carte carte(i + 1, carreaux, faceCarte);
			this->m_cartes[i] = carte;
		}
		if (i < 39) {
			int j = 0;
			sf::Texture faceCarte;
			if (!faceCarte.loadFromFile(cheminTexture(pique))) {
				std::cerr << "erreur" << std::endl;
			}
			Carte carte(i + 1, pique, faceCarte);
			this->m_cartes[i] = carte;
		}
		if (i < 52) {
			int j = 0;
			sf::Texture faceCarte;
			if (!faceCarte.loadFromFile(cheminTexture(trefle))) {
				std::cerr << "erreur" << std::endl;
			}
			Carte carte(i + 1, trefle, faceCarte);
			this->m_cartes[i] = carte;
		}
	}	
}

JeuComplet::~JeuComplet() {
	delete[] m_cartes;
	m_cartes = nullptr;
}

std::string JeuComplet::couleurToString(Couleur p_couleur) {
	switch (p_couleur) {
	case coeur:
		return "coeur";
		break;
	case carreaux:
		return "carreaux";
		break;
	case pique:
		return "pique";
		break;
	case trefle:
		return "trefle";
		break;
	default:
		return "back_custom";
	}
}

std::string JeuComplet::cheminTexture(Couleur p_couleur) {
	return cheminDossier + "-" + couleurToString(p_couleur) + extensionFichier;
}