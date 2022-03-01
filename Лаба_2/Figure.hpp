#pragma once
#include <string>
#include <iostream>
using namespace std;
/*
	Абстрактный класс, представляющий геометричкскую фигуру.
*/
class Figure {
protected:
	const string type = "Abstract figure";
public:
	Figure(const string& t = "abstract figure") : type(t)
	{

	}
	virtual void move() = 0;		// Перемещение фигуры
	virtual void display() = 0;		// Вывод информации о фигуре
	virtual double square() = 0;	// Плозщадь фигуры
	virtual string getType() = 0;	// Получение типа фигуры
	
	// Перегрузка операторов сравнения
	virtual bool operator == (Figure* rhs) { return square() == rhs->square(); }
	virtual bool operator > (Figure* rhs) { return square() > rhs->square(); }
	virtual bool operator < (Figure* rhs) { return square() < rhs->square(); }
};