#include "Circle.hpp"
Circle::Circle() : Figure("Circle")
{
	center = { 0,0 }; //создание значений по умолчанию 
	radius = 0;
}

// Конструктор
Circle::Circle(Point p, double r) : Figure("Circle") {
	center = p;
	radius = r;
}

// Перемещение окружности
void Circle::move(){
	Point p;
	double r;
	cout << "Enter X: ";
	getValue(p.x);
	cout << "Enter Y: ";
	getValue(p.y);
	cout << "Enter radius: ";
	getValue(r);
	center = { p.x, p.y }; //коор-ты центра окружности 
	radius = r;
}
// Вывод информации об окружности
void Circle::display() {
	cout << Figure::type << "<" << center << ", " << radius << ">" << endl;
}

// Площадь круга внутри окружности
double Circle::square() {
	return 3.14159 * radius * radius;
}

// Тип фигуры
string Circle::getType() {
	return Figure::type;
}