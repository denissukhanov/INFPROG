#pragma once
#include "Point.hpp"
#include "Figure.hpp"
using namespace std;
/*
	Класс, представляющий окружность
*/
class Circle : public Figure
{
private:
	Point center;
	double radius;
	std::string type;
public:
	Circle();
	Circle(Point, double);
	void move();			// Перемещение объекта
	void display();			// Вывод информации об объекте
	double square();		// Площадь
	string getType();		// Получение типа фигуры
};