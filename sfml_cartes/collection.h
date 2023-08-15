#pragma once
#include <string>
template< class TypeElement>
class collection {
public:
	virtual std::string toString() = 0;
	virtual void ajouterFin(const TypeElement& p_element) = 0;
	virtual void ajouterDebut(const TypeElement& p_element) = 0;
	virtual void supprimer(const int& p_index) = 0;
	virtual void supprimerFin() = 0;
	virtual TypeElement obtenir(const int& p_index) const = 0;
	virtual TypeElement obtenirModifiable(int& p_index) = 0;
	virtual void definir(const int& p_index, const TypeElement& p_element) = 0;
};
