#include <string.h>
#include <iostream>

/*
	Класс, представляющий произвольную строку символов
*/
class SymbString{
	private:
		char * str;		// Строка
		int size;		// Длина строки
	public:
		SymbString();
		SymbString(const char*);
		int length();
		friend std::ostream& operator<<(std::ostream&, const SymbString&);
		friend std::istream& operator>>(std::istream&, SymbString&);
};