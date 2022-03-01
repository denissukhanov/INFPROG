#include "DecString.hpp"
#include <climits>

DecString::DecString(){}	

/**
 * Constructor
 * @param {const char*}
 */
DecString::DecString(const char * s){
	int len = strlen(s);
	str = new char[len+1];
	strcpy(str, s);
}

/**
 * Получение длины строки
 * @date 2021-11-08
 * @returns {int} длина строки
 */
int DecString::length(){
	return size;
}

/**
 * Перегрузка оператора вывода в поток
 * @date 2021-11-08
 * @param {std::ostream&} ссылка на поток вывода
 * @param {const DecString&} объект класса DecString
 * @returns {std::ostream&} ссылка на поток вывода
 */
std::ostream& operator<<(std::ostream& os, const DecString& s){
	os << s.str;
	return os;
}
/**
 * Перегрузка оператора вывода в поток
 * @param {std::istream&} ссылка на поток ввода
 * @param {const DecString&} ссылка на объект класса DecString
 * @returns {std::istream&} ссылка на поток ввода
 */
std::istream& operator>>(std::istream& is, DecString &s){
	char c;
	char buf[1024];
	int cnt = 0;
	bool fail = false;
	is.clear(); // Сброс всех флагов потока
	// Посимвольное чтение из входного потока и сохранение в буфер
	// До тех пор, пока не будет прочитан символ новой строки
	while(((c = is.get()) != '\n')){
		// Проверка корректности ввода: допустимо вводить только цифры 0-9
		// Если встретился иной символ - устанавливаем флаг ошибки и выходим из цикла
		if(c < '0' || c > '9'){
			is.ignore(INT_MAX, '\n'); // Очищаем входной поток
			fail = true;
			break;
		}
		buf[cnt] = c;
		cnt++;
	}
	// В случае, если была обнаружена ошибка, выполняем очистку потока
	// иначе, содержимое буфера копируем в поле str
	if(fail){
		is.setstate(std::ios_base::failbit); // Выставляем флаг fail
	}
	else{
		buf[cnt] = '\0';
		s.str = new char[cnt+1];
		strcpy(s.str, buf);
	}
	return is;
}

/**
 * Предоставляет строку в восьмеричном формате числа
 * @date 2021-11-08
 * @returns {char*} Текущая строка в восьмеричном формате
 */
char* DecString::ShowOct(){
	char * result = new char[1024];
	sprintf(result, "%o", std::atoll(str));
	return result;
}
/**
 * Предоставляет строку в десятичном формате числа
 * @returns {char*} Текущая строка в десятичном формате
 */
char* DecString::ShowDec(){
	return str;
}
/**
 * Предоставляет строку в шестнадцатеричном формате числа
 * @returns {char*} Текущая строка в шестнадцатеричном формате
 */
char* DecString::ShowHex(){
	char * result = new char[1024];
	sprintf(result, "%x", std::atoll(str));
	return result;
}