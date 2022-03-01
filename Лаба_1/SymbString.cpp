#include "SymbString.hpp"

/**
 * Конструктор по умолчанию
 * @date 2021-11-08
 * @returns {any}
 */
SymbString::SymbString(){}		

/**
 * Конструктор
 * @date 2021-11-08
 * @param {const char *} строка для инициализации
 * @returns {any}
 */
SymbString::SymbString(const char * s){
	int len = strlen(s);
	str = new char[len+1];
	strcpy(str, s);
}

/**
 * Длина строки
 * @date 2021-11-08
 * @returns {int} Длина строки
 */
int SymbString::length(){
	return size;
}

/**
 * Перегрузка оператора вывода в поток
 * @date 2021-11-08
 * @param {std::ostream&} ссылка на поток вывода
 * @param {const SymbString&} объект класса SymbString
 * @returns {std::ostream&} ссылка на поток вывода
 */
std::ostream& operator<<(std::ostream& os, const SymbString& s){
	os << s.str;
	return os;
}

/**
 * Перегрузка оператора вывода в поток
 * @date 2021-11-08
 * @param {std::istream&} ссылка на поток ввода
 * @param {const SymbString&} объект класса SymbString
 * @returns {std::istream&} ссылка на поток ввода
 */
std::istream& operator>>(std::istream& is, SymbString &s){
	char c;
	char buf[1024];
	int cnt = 0;
	bool fail = false;
	// Посимвольно читаем содержимое входного потока, сохраняя в буфер,
	// пока не встретится символ перевода строки
	while(((c = is.get()) != '\n')){
		buf[cnt] = c;
		cnt++;
	}
	buf[cnt] = '\0';
	// Копируем содержимое в поле класса
	s.str = new char[cnt+1];
	strcpy(s.str, buf);
	return is;
}