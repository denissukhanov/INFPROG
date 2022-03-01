#pragma once
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
	Шаблон класса для хранения списка геометрических фигур
*/
template <class T>
class FigureList {
private:
	vector<T> array; // Непосредственно, список
public:
	// Конструктор по умолчанию
	FigureList() {
		array.resize(0);
	}

	// Конструктор с указанием размерности вектора
	FigureList(int capacity) {
		array.resize(capacity);
	}

	// Добавление фигуры в конец списка
	void addBack(T f) {
		array.push_back(f);
	}

	// Добавление фигуры в начало списка
	void addFront(T f) {
		array.insert(array.begin(), f);
	}

	// Добавление фигуры в указанную позицию
	void add(T f, int pos) {
		array.insert(array.begin() + pos, f);
	}

	// Удаление из конца списка
	void removeBack() {
		array.pop_back();
	}

	// Удаление из начала списка
	void removeFront() {
		array.erase(array.begin());
	}

	// Удаление фигуры из соответствующей позиции
	void remove(int pos) {
		array.erase(array.begin()+pos);
	}

	// Размер списка
	int size() {
		return array.size();
	}

	// Получение последнего элемента списка
	T getBack() {
		return array[array.size() - 1];
	}

	// Получение первого элемента списка
	T getFront() {
		return array[0];
	}

	// Получение элемента списка по указанной позиции
	T get(int pos) {
		return array[pos];
	}

	// Максимальный по площади элемент
	T max() {
		return *max_element(array.begin(), array.end());
	}
};