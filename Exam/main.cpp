﻿//Ипользуя переменную типа unsigned char и цикл вывести на экран таблицу ASCIII-символов БЕЗ ЕДИНОЙ ОПЕРАЦИИ СРАВНЕНИЯ.
#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	int counter = 0;

	unsigned char c = 0;
	do
	{
		cout << c << "\t";
		c++;
		counter++;
	} while (c);

	cout << "\n" "Количество символов: " << counter; //256 символов

	/*for (unsigned char i = 1; i; i++)
	{
		cout << i << "\t";
		counter++;
	}
	cout << "\n" "Количество символов: " << counter;*/ //255 символов
}