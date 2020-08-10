#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Ship.h"
using namespace std;
namespace sdds {
	Ship::Ship() {
		setSmpty();
	}

	Ship::Ship(const char* type, Engine* engine, int engcount) {
		if (type == nullptr || type[0] == '\0' || engine == nullptr || engcount == 0)
		{
			setSmpty();
		}
		else {
			m_type = new char[strlen(type) + 1];
			strcpy(m_type, type);
			m_engines = new Engine[engcount];
			for (int i = 0; i < engcount; i++) {
				m_engines[i] = engine[i];
			}
			m_engCnt = engcount;
		}
	}
	void Ship::setSmpty() {
		m_engCnt = 0;
	}

	 Ship::operator bool() const {

		return m_engCnt != 0;
	}

	Ship& Ship::operator+=(Engine engine) {
		if ( m_engCnt == 0) {
			cout << "The object is not valid! Engine cannot be added!" << endl;
		}
		else {
			Engine* temp;
			temp = new Engine[m_engCnt + 1];
			for (int i = 0; i < m_engCnt; i++) {
				temp[i] = m_engines[i];

			}
			temp[m_engCnt] = engine;
			m_engCnt++;
			delete[] m_engines;
			m_engines = temp;
		}
		return *this;
	}


		double Ship::shipPower() const{
		double powersum = 0;

		for (int i = 0; i < m_engCnt; i++) {
			powersum += m_engines[i].get();
		}
		return powersum * 5;
		}



	bool Ship::operator<(double power) const {
		return power > shipPower();
		
	}

	void Ship::display() const {
		if (m_engCnt == 0) {
			cout << "No available data" << endl;
		}
		else {
			cout << m_type << " - ";
			cout.setf(ios::fixed);
			cout.precision(2);
			cout.width(6);
			cout << shipPower() << endl;
			for (int i = 0; i < m_engCnt; i++) {
				cout.setf(ios::fixed);
				cout.precision(2);
				m_engines[i].display();
				cout.setf(ios::fixed);
				cout.precision(3);
			}
		}

	}


	 bool operator<(double power, const Ship& theShip) {
		return power < theShip.shipPower();
	}




	Ship::~Ship() {

		if (m_engCnt != 0) {
			delete[] m_engines;
			delete[] m_type;

			m_engines = nullptr;
			m_type = nullptr;
		}
	

	}




}