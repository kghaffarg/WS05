#ifndef SDDS_SHIP_H__
#define SDDS_SHIP_H__
#include "Engine.h"
namespace sdds {

	const double MIN_STD_POWER = 90.111;
	const double MAX_STD_POWER = 99.999;
	class Ship {
		Engine* m_engines;
		char* m_type;
		int m_engCnt;
		double shipPower() const;
	public:
		Ship();
		Ship(const char* type,Engine* engine , int engcount);
		void setSmpty();
		explicit operator bool() const;
		Ship& operator+=(Engine engine);
		bool operator<(double power) const;
		void display() const;
		~Ship();
		friend bool operator<(double power, const Ship& theShip);

		
	};







}
#endif // !SDDS_SHIP_H_
