#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Engine.h"
using namespace std;
namespace sdds {
	Engine::Engine() {
		setEmpty();
	}
	Engine::Engine(const char* type, double size ) {
	
				strcpy(m_type, type);
			   m_size = size;
		
	}
	void Engine::setEmpty() {
		m_size = 0;
		m_type[0] = '\0';
	}

	double Engine::get() const {
		return m_size;
	}
	

	void Engine::display() const {
	
		cout << m_size << " liters - " << m_type << endl;
	
	}












}