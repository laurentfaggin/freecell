#pragma once
#include "cartes.h"
#include "jeuComplet.h"

class GamePlay {
public:
	GamePlay();
	~GamePlay();
private:
	Carte* m_cartesMelangees[8][20];
	Carte* m_cartesTriees[4];
};
