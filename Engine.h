#ifndef SDDS_ENGINE_H__
#define SDDS_ENGINE_H__
namespace sdds {
	const int TYPE_MAX_SIZE = 30;
	class Engine {
		double m_size;
		char m_type[TYPE_MAX_SIZE + 1];
	public:
		Engine();
		Engine(const char* type, double size);
		void setEmpty();
		double get() const;
		void display() const;

	};

















}
#endif // !SDDS_ENGINE_H__

