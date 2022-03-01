#include <iostream>
#include <memory>
#include "Point.hpp"
#include "Figure.hpp"
#include "Circle.hpp"
#include "Triangle.hpp"
#include "FigureList.hpp"
using namespace std;
int main() {
	/*
		Объект, представляющий собой список различных фигур.
		Внутри FigureList - вектор определенного типа.
		Возникает задача хранить объекты различных типов. Подход к решению задачи следующий:
		1. Создан абстрактный класс Figure, наполненный необходимыми чисто виртуальными функциями.
		2. От него отнаследованы два класса - Circle, Triangle. 
		При этом, создать объект класса с типом Figure не получится, поскольку, передавая объекты потомков по значению,
		мы потеряем всю информацию об объекте класса потомка и останется информация только об объекте базового класса, а в базовый класс - у нас абстрактный
		Как итог - получим ошибку.
		Поэтому логичнее всего передавать в список ссылки на объекты. 
		Хранение объектов разных типов в контейнере возможно при помощи конструкции shared_ptr (vector<ClassName&> - недопустимая конструкция)
		У этого типа (shared_ptr) есть несколько полезных свойств: В качестве типа объекта, который оборачивается в shared_ptr, мы передаем просто тип базового класса
		И при этом, shared_ptr будет вести себя как ссылка. Т.е. мы кладем туда объекты производных классов и обращаемся к интерфейсу базового класса. 
		Сформировать такой "умный указатель" можно при помощи конструкции make_shared<тип дочернего класса>(args...).
	*/
	FigureList<shared_ptr<Figure>> fl;
	int rc = 0;
	while (true) {
		cout << "Select menu item:" << endl
			<< "0. Exit" << endl
			<< "1. Add circle back" << endl
			<< "2. Add circle front" << endl
			<< "3. Add circle to pos" << endl
			<< "4. Add triangle back" << endl
			<< "5. Add triangle front" << endl
			<< "6. Add triangle to pos" << endl
			<< "7. Remove from beginning" << endl
			<< "8. Remove from end" << endl
			<< "9. Remove from position" << endl
			<< "10. Get first element" << endl
			<< "11. Get last element" << endl
			<< "12. Get element in position" << endl
			<< "13. Move figure" << endl
			<< "14. Get figure with max square" << endl
			<< "15. Display figure list" << endl
			<< "Select menu item: ";
		getValue(rc);
		switch (rc) {
		// Выход
		case 0:
			return 0;
		break;
		// Добавление окружности в конец
		case 1:
		{
			Point p; //создаем точку p
			cout << "Enter X Y: "; 
			getValue(p.x); //система получает значение для P от х
			getValue(p.y); //система получает значение для P от y
			double radius; //создается переменная под радиус
			cout << "Enter radius: ";
			getValue(radius); //система получает значение радиуса введенное через консоль 
			shared_ptr<Figure> shc = make_shared<Circle>(p, radius); // Формируем shared_ptr на объект класса окружности и передаем параметры конструктора
			fl.addBack(shc); // Кладем в список этот элемент
		}
		break;
		// Добавление окружности в начало списка
		case 2:
		{
			Point p;
			double radius;
			cout << "Enter X Y: ";
			getValue(p.x);
			getValue(p.y);
			cout << "Enter radius: ";
			getValue(radius);
			shared_ptr<Figure> shc = make_shared<Circle>(p, radius);
			fl.addFront(shc);
		}
		break;
		// Добавление окружности в конкретную позицию
		case 3:
		{
			Point p;
			double radius;
			cout << "Enter X Y: ";
			getValue(p.x);
			getValue(p.y);
			cout << "Enter radius: ";
			getValue(radius);
			int pos;
			cout << "Enter position: ";
			getValue(pos); 
			if (pos >= fl.size() || pos < 0) { //сравниваем новую позицию с текущей
				cout << "Error! Position not exists!" << endl; //выводим сообщение об ошибке 
			}
			else {
				shared_ptr<Figure> shc = make_shared<Circle>(p, radius);
				fl.add(shc, pos);
			}
		}
		break;
		// Добавление треугольника в конец
		case 4:
		{
			Point p1, p2, p3;
			cout << "Enter point 1 (X Y): ";
			getValue(p1.x);
			getValue(p1.y);
			cout << "Enter point 2 (X Y): ";
			getValue(p2.x);
			getValue(p2.y);
			cout << "Enter point 3 (X Y): ";
			getValue(p3.x);
			getValue(p3.y);
			shared_ptr<Figure> shc = make_shared<Triangle>(p1,p2,p3);
			fl.addBack(shc);
		}
		break;
		// Добавление треугольника в начало
		case 5:
		{
			Point p1, p2, p3;
			cout << "Enter point 1 (X Y): ";
			getValue(p1.x);
			getValue(p1.y);
			cout << "Enter point 2 (X Y): ";
			getValue(p2.x);
			getValue(p2.y);
			cout << "Enter point 3 (X Y): ";
			getValue(p3.x);
			getValue(p3.y);
			shared_ptr<Figure> shc = make_shared<Triangle>(p1, p2, p3);
			fl.addFront(shc);
		}
		break;
		// Добавление треугольника в конкретную позицию
		case 6:
		{
			Point p1, p2, p3;
			cout << "Enter point 1 (X Y): ";
			getValue(p1.x);
			getValue(p1.y);
			cout << "Enter point 2 (X Y): ";
			getValue(p2.x);
			getValue(p2.y);
			cout << "Enter point 3 (X Y): ";
			getValue(p3.x);
			getValue(p3.y);
			int pos;
			cout << "Enter position: ";
			getValue(pos);
			if (pos >= fl.size() || pos < 0) {
				cout << "Error! Position not exists!" << endl;
			}
			else {
				shared_ptr<Figure> shc = make_shared<Triangle>(p1, p2, p3);
				fl.add(shc, pos);
			}
		}
		break;
		// Удаление из начала
		case 7: {
			if (fl.size()) { //удаляются значение из fl.size 
				fl.removeFront();
			}
			else {
				cout << "List is empty!" << endl;
			}
 		}
		break;
		// Удаление из конца
		case 8: {
			if (fl.size()) {
				fl.removeBack();
			}
			else {
				cout << "List is empty!" << endl;
			}
		}
		break;
		// Удаление из конкретной позиции
		case 9: {
			int pos;
			cout << "Enter position: ";
			getValue(pos);
			if (pos < 0 || pos >= fl.size()) { //снова сравниваем новую позицию со старой 
				cout << "Error! Position not exists!" << endl;
			}
			else {
				fl.remove(pos);
			}
		}
		break;
		// Вывести первый элемент списка
		case 10:
		{
			if (fl.size() > 0) {
				fl.getFront()->display();
			}
			else {
				cout << "List is empty!" << endl;
			}
		}
		break;
		// Вывести последний элемент списка
		case 11:
		{
			if (fl.size() > 0) {
				fl.getBack()->display();
			}
			else {
				cout << "List is empty!" << endl;
			}
		}
		break;
		// Вывести элемент списка, находящийся в конкретной позиции
		case 12:
		{
			int pos;
			cout << "Enter position: ";
			getValue(pos);
			if (pos < 0 || pos >= fl.size()) {
				cout << "Error! Position not exists!" << endl;
			}
			else {
				fl.get(pos)->display();
			}
		}
		break;
		// Перемещение объекта
		case 13:
		{
			int pos;
			cout << "Enter position in list: ";
			getValue(pos);
			if (pos >= fl.size() || pos < 0) {
				cout << "Error! Element not found!";
			}
			else {
				shared_ptr<Figure> obj = fl.get(pos);
				obj->move();
			}
		}
		break;

		// Вывод элемента списка, имеющего максимальную площадь
		case 14: 
		{
			fl.max()->display();
		}
		break;
		// Вывод всего списка на экран
		case 15:
		{
			for (int i = 0; i < fl.size(); i++) {
				fl.get(i)->display();
			}
		}
			break;
		default:
			cout << "Undefined menu item!" << endl;
			break;
		};
	}
	return 0;
}