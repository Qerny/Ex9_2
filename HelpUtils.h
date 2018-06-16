#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <cstring>
#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

template <class Type>
//Вспомогательная функция для ввода числа в указанном интервале
Type InputNumber(Type min, Type max, string message)
{
	Type n;
	do
	{
		cout << message;
		while ((!(cin >> n)) || cin.get() != '\n')
		{
			cin.clear();  // восстанавливает поток если он в ошибочном сосотянии
			cin.sync();   // очищает поток от имеющихся символов
			cout << message;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		} 
	} while ((n < min) || (n > max));
	return n;
}

//Ввод текстовой информации
string InputInformation(string message);

//Проверка символа на корректность в имени файла
bool CorrectSymbol(char c);


//Проверка имени файла на коректность
bool CorrectName(string name);

//Ввод имени файла
string InputFileName();