#include <iostream>
#include <stdio.h>
#include "SymbString.hpp"
#include "DecString.hpp"

using namespace std;
const int MAX_SIZE = 1024;

int main(){

	SymbString s_str(""); // Символьная строка	
	DecString d_str (""); // Строка, представляющая число в десятичной записи
	// Ввод символьной строки
	cout << "Enter symbol string: ";
	cin >> s_str;
	cout << "Symbol string: " << s_str << endl;

	// Ввод десятичого числа в виде строки с проверкой корректности ввода
	while(true){
		cout << "Enter decimal string: ";
		cin >> d_str;
		// Проверка бита fail (устанавливается в перегружаемом методе)
		if(cin.fail()){
			cout << "Incorrect input." << endl;
			continue;
		}
		else{
			break;
		}
	}
	// Вывод результата методов согласно заданию
	cout << "DEC = " << d_str.ShowDec() << endl;
	cout << "HEX = " << d_str.ShowHex() << endl;
	cout << "OCT = " << d_str.ShowOct() << endl;
	return 0;
}