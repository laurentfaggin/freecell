#include "GamePlay.h"

GamePlay::GamePlay() {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 20; ++j) {
			m_cartesMelangees[i][j] = nullptr;			
		}
	}

	for (int i = 0; i < 4; ++i) {		
		m_cartesTriees[i] = nullptr;		
	}
}

GamePlay::~GamePlay() {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 20; ++j) {
			if (m_cartesMelangees[i][j] != nullptr) {
				delete (m_cartesMelangees[i][j]);
				m_cartesMelangees[i][j] = nullptr;
			}
		}
	}

	for (int i = 0; i < 4; ++i) {
		if (m_cartesTriees[i] != nullptr) {
			delete m_cartesTriees[i];
			m_cartesTriees[i] = nullptr;
		}
	}
}