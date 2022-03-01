#include "Triangle.hpp"
Triangle::Triangle() : Figure("Triangle")
{

}

Triangle::Triangle(Point np1, Point np2, Point np3) : Figure("Triangle") {
	p1 = np1;
	p2 = np2;
	p3 = np3;
}
//перемещение треугольника по координатам 
void Triangle::move() {
	Point np1 = { 0,0 }, np2 = { 0,0 }, np3 = { 0,0 };
	cout << "Enter point 1 (X Y): ";
	getValue(np1.x);
	getValue(np1.y);
	cout << "Enter point 2 (X Y): ";
	getValue(np2.x);
	getValue(np2.y);
	cout << "Enter point 3 (X Y): ";
	getValue(np3.x);
	getValue(np3.y);
	p1 = np1; //координаты присываются одной переменной Px
	p2 = np2;
	p3 = np3;
}
void Triangle::display() {
	cout << Figure::type << "<" << p1 << ", " << p2 << ", " << p3 << ">" << endl;
}

double Triangle::square() { //площадь треугольника 
	return 0.5 * ((p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y));
}

string Triangle::getType() {//получение типа фигуры, т.е. квадрат, треугольник, круг, окружность и др.
	return Figure::type; 
}
double Triangle::distance(const Point &a, const Point &b) { //рассчитывает дистанцию точек друг от друга на плоскости
	return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}