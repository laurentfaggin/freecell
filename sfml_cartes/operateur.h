#pragma once
#include <string>
#include "listeGenerique.h"


template< class TypeElement>
Liste<TypeElement> operator+(const Liste<TypeElement>& p_liste, TypeElement p_element)
{
    Liste<TypeElement> liste(p_liste);
    liste.ajouterFin(p_element);
    return liste;
}

template< class TypeElement>
Liste<TypeElement>& operator+=(Liste<TypeElement>& p_liste, TypeElement p_element)
{
    p_liste.ajouterFin(p_element);
    return p_liste;
}

template< class TypeElement>
Liste<TypeElement> operator+(const Liste<TypeElement>& p_liste1, const Liste<TypeElement>& p_liste2)
{
    int capacite = p_liste1.m_nombreDElements + p_liste2.m_nombreDElements;
    if (capacite == 0) {
        capacite = 1;
    }
    Liste<TypeElement> nouvelleListe(capacite);
    for (size_t i = 0; i < p_liste1.m_nombreDElements; ++i)
    {
        nouvelleListe.ajouterFin(p_liste1.m_liste[i]);
    }
    for (size_t i = 0; i < p_liste2.m_nombreDElements; ++i)
    {
        nouvelleListe.ajouterFin(p_liste2.m_liste[i]);
    }
    return nouvelleListe;
}

template<class TypeElement>
Liste<TypeElement>& operator+=(Liste<TypeElement>& p_liste1, const Liste<TypeElement>& p_liste2)
{
    for (size_t i = 0; i < p_liste2.m_nombreDElements; ++i)
    {
        p_liste1.ajouterFin(p_liste2.m_liste[i]);
    }
    return p_liste1;
}

template<class TypeElement>
bool operator==(const Liste<TypeElement>& p_liste1, const Liste<TypeElement>& p_liste2) {
    bool listeIdentique = p_liste1.nombreDElement() == p_liste2.nombreDElement();
    for (size_t i = 0; i < p_liste1.nombreDElement() && listeIdentique; ++i) {
        listeIdentique = p_liste1.obtenir() == p_liste2.obtenir();
    }
    return listeIdentique;
}

template<class TypeElement>
bool operator!=(const Liste<TypeElement>& p_liste1, const Liste<TypeElement>& p_liste2) {
    bool listeDifferente = p_liste1.nombreDElement() != p_liste2.nombreDElement();
    for (size_t i = 0; i < p_liste1.nombreDElement() && !listeDifferente; ++i) {
        listeDifferente = p_liste1.obtenir() != p_liste2.obtenir();
    }
    return listeDifferente;
}

template<class TypeElement>
Liste<TypeElement> operator~(const Liste<TypeElement>& p_liste) {
    Liste<TypeElement>nouvelleListe(p_liste.nombreDElement());
    for (size_t i = 0; i < p_liste.nombreDElement() / 2; ++i) {
        TypeElement valeurDebut = p_liste.obtenir(i);
        TypeElement valeurFin = p_liste.obtenir(p_liste.nombreDElement() - 1 - i);
        nouvelleListe.definir(i, valeurDebut);
        nouvelleListe.definir(p_liste.nombreDElement() - 1 - i, valeurFin);
    }
    return nouvelleListe;
}

template<class TypeElement>
std::ostream& operator<<(std::ostream& stream, const Liste<TypeElement>& p_liste) {
    stream << "Liste: [ ";
    for (size_t i = 0; i < p_liste.m_nombreDElements; ++i) {
        stream << p_liste.m_liste[i];
        stream << " ";
    }
    stream << "]";
    stream << std::endl;
    return stream;
}