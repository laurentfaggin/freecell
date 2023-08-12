
#include "jeuComplet.h"
#include <filesystem>



std::string cheminDossier = "cartes_img";
std::string extensionFichier = ".png";

JeuComplet::JeuComplet() {
	this->m_cartes = new Carte[52];

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