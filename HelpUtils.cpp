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
#include "HelpUtils.h"
using namespace std;

//Ввод текстовой информации
string InputInformation(string message)
{
	string a;
	cout << message;
	cin >> a;
	return a;
}

//Проверка символа на корректность в имени файла
bool CorrectSymbol(char c)
{
	switch (c)
	{
	case '.':
	case '*':
	case '?':
	case '<':
	case '>':
	case ':':
	case '|':
	case '/':
		return false;
	default:
		return true;
	}
}

//Проверка имени файла на коректность
bool CorrectName(string name)
{
	int i = 0;
	bool goodsm = true;
	for (int i = 0; (i < name.length() && goodsm); i++)
		goodsm = CorrectSymbol(name[i]);
	return goodsm;
}

//Ввод имени файла
string InputFileName()
{

	string filename;
	do
	{
		cout << "Enter the file name (without an extension): ";
		cin >> filename;
		if (filename.length() > 35)
			filename.erase(filename.begin(), filename.begin() + 35);
		if (CorrectName(filename))
		{
			filename = filename + ".txt";
			break;
		}
		else
			cout << "Invalid file name\n";
	} while (true);

	return filename;
}
