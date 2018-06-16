#pragma once
#include <cstdio>
#include <sstream>
#include <cmath>
#include <string>
#include <iostream>
#include <string>
#include "HelpUtils.h"

class Student {
public:
	int course;
	string group;
	string surname;
	string numberRecordBook;
	string subject;
	int mark;

	//Конструктор по умолчанию
	Student();

	//Изменение структуры Student
	Student ChangeCompany(Student &result);

	//Перегруженный оператор присваивания для структуры Student
	Student& operator = (Student st);
};

//Функция ввода структуры Student с консоли
Student InputScreenCompany();

//Функция вывода структуры Student на консоль
void OutputScreenCompany(Student st);

//Перевод структуры Student в строку
string ToString(Student st, int i);

bool IsEqual(Student st1, Student st2);

//считывание структуры Student из строки
Student ReadFromString(ifstream& input);

/*Поиск равного элемента по выбранному критерию
type_search - тип поиска:
	1 - по группе
	2 - по курсу
	3 - по номеру зачетной книжки
	4 - по фамилии
	5 - по оценке*/
bool SearchElement(Student a, Student b, int type_search);

/*Ввод критерия поиска в зависимости от выбранного типа 
type_search - тип поиска:
	1 - по номеру группы
	2 - по номеру курса
	3 - по номеру зачетки
	4 - по фамилии
	5 - по оценке*/
Student InputChangeTypeSearch(int type_search);

/*Сравнение структур по выбранного полю
type_search - тип поиска:
1 - по номеру группы
2 - по номеру курса
3 - по номеру зачетки
4 - по фамилии
5 - по оценке*/
int Sorte(Student a, Student b, int type_search);