#include <string.h>
#include <iostream>
#include <iomanip>
#include <stdio.h>

/*
	Класс, представляющий изображение десятичного числа
*/
class DecString{
	private:
		char * str; 	// Сама строка
		int size;		// Размер строки
	public:
		DecString();
		DecString(const char*);
		int length();
		friend std::ostream& operator<<(std::ostream&, const DecString&);
		friend std::istream& operator>>(std::istream&, DecString&);
		char* ShowOct();
		char* ShowDec();
		char* ShowHex();
};