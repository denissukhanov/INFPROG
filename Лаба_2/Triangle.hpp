#pragma once
#include <math.h>
#include "Point.hpp"
#include "Figure.hpp"

/*
	Класс, представляющий треугольник
*/
class Triangle : public Figure
{
private:
	Point p1;
	Point p2;
	Point p3;
	double distance(const Point&, const Point&); // Функция, считающая расстояние между двумя точками на плоскости
public:
	Triangle();
	Triangle(Point, Point, Point);
	void move(); //перемещение объекта
	void display(); //вывод информации о фигуре
	double square(); //площадь фигуры
	string getType(); //получение типа фигуры 
};