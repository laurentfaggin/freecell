#pragma once
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <string>
#include "collection.h"


template <class TypeElement>
class Liste : public collection < TypeElement> {
public:
	Liste() {
		this->m_nombreDElements = 0;
		this->m_capacite = 1;
		this->m_liste = new TypeElement[this->m_capacite];
	}
	Liste(int p_capacite) :
		m_nombreDElements(0),
		m_capacite(p_capacite),
		m_liste(nullptr)
	{
		if (p_capacite > 0) {
			m_liste = new TypeElement[p_capacite];
		}
		else {
			throw std::invalid_argument("erreur capacite");
		}
	};

	Liste(const Liste& p_listeACopier) :
		m_nombreDElements(p_listeACopier.m_nombreDElements),
		m_capacite(p_listeACopier.m_capacite)
	{
		this->m_liste = new TypeElement[this->m_capacite];
		for (size_t i = 0; i < p_listeACopier.m_nombreDElements; ++i) {
			this->m_liste[i] = p_listeACopier.m_liste[i];
		}
	}

	Liste(Liste&& p_listeADeplacer) :
		m_nombreDElements(p_listeADeplacer.m_nombreDElements),
		m_capacite(p_listeADeplacer.m_capacite),
		m_liste(p_listeADeplacer.m_liste)
	{
		p_listeADeplacer.m_nombreDElements = 0;
		p_listeADeplacer.m_capacite = 0;
		p_listeADeplacer.m_liste = nullptr;
	}

	~Liste() {
		if (this->m_liste != nullptr) {
			delete[] this->m_liste;
			this->m_liste = nullptr;
		}
	};

	int capacite()const {
		return this->m_capacite;
	}

	int nombreDElement()const {
		return this->m_nombreDElements;
	}

	virtual void ajouterFin(const TypeElement& p_element) {
		agrandirCapaciteSiNessaire();
		this->m_liste[this->m_nombreDElements] = p_element;
		++ this->m_nombreDElements;
	}

	//voir une methode pour modifier la position en modifiant simplement l'index de depart (buffer circulaire)
	virtual void ajouterDebut(const TypeElement& p_element) {
		agrandirCapaciteSiNessaire();
		for (size_t i = this->m_nombreDElements; i > 0; --i) {
			this->m_liste[i] = this->m_liste[i - 1];
		}
		this->m_liste[0] = p_element;

		++this->m_nombreDElements;
	}

	virtual void supprimer(const int& p_index) {
		if (p_index < 0 || p_index >= this->m_nombreDElements) {
			throw std::invalid_argument("Index invalide");
		}
		for (int i = p_index; i < this->m_nombreDElements - 1; i++) {
			this->m_liste[i] = this->m_liste[i + 1];
		}
		-- this->m_nombreDElements;
	};

	virtual void supprimerFin() {
		if (this->m_nombreDElements == 0) {
			throw std::invalid_argument("la liste est vide");
		}
		--this->m_nombreDElements;
	}

	virtual TypeElement obtenir(const int& p_index) const {
		if (p_index >= this->m_nombreDElements) {
			throw std::invalid_argument("la liste n'a pas de valeur acet emplacement");
		}
		return this->m_liste[p_index];
	};

	virtual TypeElement obtenirModifiable(int& p_index) {
		if (p_index >= m_nombreDElements) {
			throw std::invalid_argument("Index invalide");
		}
		return m_liste[p_index];
	}

	virtual void definir(const int& p_index, const TypeElement& p_element) {
		if (p_index >= this->m_nombreDElements) {
			throw std::invalid_argument("La liste contient deja un element");
		}
		this->m_liste[p_index] = p_element;
	};

	virtual std::string toString() {
		std::stringstream affiche;
		/*affiche << "[ ";
		for (int i = 0; i < this->m_nombreDElements; i++) {
			affiche << this->obtenir(i) << " ";
		}
		affiche << "]";*/

		return affiche.str();
	};

	void filtrer_rec(bool(*p_predicat)(TypeElement), const TypeElement* p_tableauAFiltrer, int p_tailleTableauAFiltrer, TypeElement* p_tableauFiltre, int& p_tailleTableauFiltre) {
		if (p_tailleTableauAFiltrer == 0) {
			return;
		}
		filtrer_rec(p_predicat, p_tableauAFiltrer, p_tailleTableauAFiltrer - 1, p_tableauFiltre, p_tailleTableauFiltre);
		if (p_predicat(p_tableauAFiltrer[p_tailleTableauAFiltrer - 1])) {
			p_tableauFiltre[p_tailleTableauFiltre] = p_tableauAFiltrer[p_tailleTableauAFiltrer - 1];
			++p_tailleTableauFiltre;
		}
		//return p_tableauFiltre;
	}


	Liste<TypeElement>* filtrer(int p_tailleTableauAFiltrer, bool(p_predicat)(TypeElement)) {
		Liste<TypeElement>* p_tableauFiltre = new Liste<TypeElement>[p_tailleTableauAFiltrer];
		int p_tailleTableauFiltre = 0;
		filtrer_rec(p_predicat, this->m_liste, this->nombreDElement(), p_tableauFiltre->m_liste, p_tailleTableauFiltre);
		p_tableauFiltre->m_nombreDElements = p_tailleTableauFiltre;
		return p_tableauFiltre;
	}


	template <class TypeElement> friend Liste<TypeElement> operator+ (const Liste<TypeElement>& p_liste, TypeElement p_element);
	template <class TypeElement> friend Liste<TypeElement> operator+ (const Liste<TypeElement>& p_liste1, const Liste<TypeElement>& p_liste2);
	template <class TypeElement> friend Liste<TypeElement>& operator+= (Liste<TypeElement>& p_liste, TypeElement p_element);
	template <class TypeElement> friend Liste<TypeElement>& operator+= (Liste<TypeElement>& p_liste1, const Liste<TypeElement>& p_liste2);
	template <class Typeelement> friend Liste<Typeelement>& operator~ (const Liste<TypeElement>& p_liste);
	template <class TypeElement> friend std::ostream& operator<<(std::ostream& stream, const Liste<TypeElement>& p_liste);
	template <class TypeElement> friend bool operator== (const Liste<TypeElement>& p_liste1, const Liste<TypeElement>& p_liste2);
	template <class TypeElement> friend bool operator!= (const Liste<TypeElement>& p_liste1, const Liste<TypeElement>& p_liste2);
	//template <class TypeElement> friend Liste<TypeElement>* filtrer(Liste<TypeElement>* p_liste, int p_tailleP_liste, bool(p_predicat)(TypeElement));

private:
	int m_nombreDElements;
	int m_capacite;
	TypeElement* m_liste;

	void agrandirCapaciteSiNessaire() {
		if (this->m_nombreDElements == this->m_capacite) {
			TypeElement* nouvelleListe = new TypeElement[this->m_capacite * 2];
			for (int i = 0; i < this->m_nombreDElements; ++i) {
				nouvelleListe[i] = this->m_liste[i];
			}
			delete[] this->m_liste;
			this->m_liste = nouvelleListe;
			this->m_capacite *= 2;
		}
	}
};

