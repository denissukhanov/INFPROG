#pragma once
#include <iostream>
#include <climits>
using namespace std;

/*
	Структура, представляющая собой точку на плоскости
*/
struct Point {
	double x;
	double y;
};

// Оператор вывода точки для удобства
inline ostream& operator<<(ostream& os, const Point& point) {
	os << "(" << point.x << ";" << point.y << ")";
	return os;
}

/*
	Шаблон функции для обработки ввода значения
*/
template <typename T>
void getValue(T &n){
	while(!(cin >> n)){
		cout << "Incorrect value. Repeat input: ";
		cin.clear();
		cin.ignore(INT_MAX,'\n');
	}
}