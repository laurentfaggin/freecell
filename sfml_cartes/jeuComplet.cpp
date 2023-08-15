
#include <filesystem>
#include <iostream>
#include <string>
#include "listeGenerique.h"
#include "jeuComplet.h"
#include "Valeur.h"
#include "Couleur.h"


std::string cheminDossier = "cartes_img/face/";
std::string extensionFichier = ".png";

JeuComplet::JeuComplet()
{
	this->m_cartes = new Liste<Carte>;
	for (int i = 101; i <= 113; ++i) {
		sf::Texture faceCarte;
		int valeur = 1;
		if (!faceCarte.loadFromFile(cheminTexture(i, coeur))) {
			std::cerr << "erreur" << std::endl;
		}
		Carte cartecoeur(valeur, coeur, faceCarte);
		m_cartes->ajouterFin(cartecoeur);

		if (!faceCarte.loadFromFile(cheminTexture(i, carreaux))) {
			std::cerr << "erreur" << std::endl;
		}
		Carte cartecarreaux(valeur, carreaux, faceCarte);
		this->m_cartes->ajouterFin(cartecarreaux);

		if (!faceCarte.loadFromFile(cheminTexture(i, pique))) {
			std::cerr << "erreur" << std::endl;
		}
		Carte cartepique(valeur, pique, faceCarte);
		this->m_cartes->ajouterFin(cartepique);

		if (!faceCarte.loadFromFile(cheminTexture(i, trefle))) {
			std::cerr << "erreur" << std::endl;
		}
		Carte cartetrefle(valeur, trefle, faceCarte);
		this->m_cartes->ajouterFin(cartetrefle);

		++valeur;
	}
}

JeuComplet::~JeuComplet() {
	delete m_cartes;
	m_cartes = nullptr;
}

Liste<Carte>* JeuComplet::getCartes() {
	return this->m_cartes;
}



std::string JeuComplet::couleurToString(Couleur p_couleur) {
	switch (p_couleur) {
	case coeur:
		return "coeur";
	case carreaux:
		return "carreau";
	case pique:
		return "pique";
	case trefle:
		return "trefle";
	default:
		return "back_custom";
	}
}

std::string JeuComplet::cheminTexture(int i, Couleur p_couleur) {
	return cheminDossier + std::to_string(i) + "-" + couleurToString(p_couleur) + extensionFichier;
}