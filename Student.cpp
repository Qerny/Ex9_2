#pragma once
#include <cstdio>
#include <sstream>
#include <cmath>
#include <string>
#include <iostream>
#include <string>
#include "HelpUtils.h"
#include "Student.h"


//Конструктор по умолчанию
Student::Student()
{
	int course = 1;
	string group = "";
	string surname = "";
	string numberRecordBook = "";
	string subject = "";
	int mark = 1;
}

//Изменение структуры Student
Student Student::ChangeCompany(Student &result)
{
	if (InputNumber(0, 1, "Do you want to change the course " + to_string(result.course) + " (0 - no, 1 - yes)\nYour choice: ") == 1)
		result.course = InputNumber(1, 6, "Enter the new course: ");
	if (InputNumber(0, 1, "Do you want to change the group " + result.group + " (0 - no, 1 - yes)\nYour choice: ") == 1)
		result.group = InputInformation("Enter the new group: ");
	if (InputNumber(0, 1, "Do you want to change the surname " + result.surname + " (0 - no, 1 - yes)\nYour choice: ") == 1)
		result.surname = InputInformation("Enter the new surname: ");
	if (InputNumber(0, 1, "Do you want to change the number of record book " + result.numberRecordBook + " (0 - no, 1 - yes)\nYour choice: ") == 1)
		result.numberRecordBook = InputInformation("Enter the new number: ");
	if (InputNumber(0, 1, "Do you want to change the subject " + result.subject + " (0 - no, 1 - yes)\nYour choice: ") == 1)
		result.subject = InputInformation("Enter the new subject: ");
	if (InputNumber(0, 1, "Do you want to change the mark " + to_string(result.mark) + " (0 - no, 1 - yes)\nYour choice: ") == 1)
		result.mark = InputNumber(2, 5, "Enter the new group: ");

	return result;
}

//Перегруженный оператор присваивания для структуры Student
Student& Student::operator = (Student st)
{
	course = st.course;
	group = st.group;
	surname = st.surname;
	numberRecordBook = st.numberRecordBook;
	subject = st.subject;
	mark = st.mark;

	return (*this);
}

//Функция ввода структуры Student с консоли
Student InputScreenCompany()
{
	Student st;

	st.course = InputNumber(1, 6, "Enter the course (1-6): ");
	st.group = InputInformation("Enter the group: ");
	st.surname = InputInformation("Enter the surname: ");
	st.numberRecordBook = InputInformation("Enter the number of record book: ");
	st.subject = InputInformation("Enter the name of subject: ");
	st.mark = InputNumber(2, 5, "Enter the mark (2-5): ");

	return st;
}

//Функция вывода структуры Student на консоль
void OutputScreenCompany(Student st)
{
	cout << "Course: " << st.course << endl;
	cout << "Group: " << st.group << endl;
	cout << "Surname: " << st.surname << endl;
	cout << "Number of record book: " << st.numberRecordBook << endl;
	cout << "Subject: " << st.subject << endl;
	cout << "Mark: " << st.mark << endl;
}

//Перевод структуры Student в строку
string ToString(Student st, int i)
{
	string result = "Record - " + to_string(i) + "\n" + "Course: " + to_string(st.course) + "\n" + "Group: " + st.group + "\n" + "Surname: " + st.surname + "\n" + "Number of record book: " + st.numberRecordBook + "\n" + "Subject: " + st.subject + "\n" + "Mark: " + to_string(st.mark) + "\n";
	return result;
}

bool IsEqual(Student st1, Student st2)
{
	return ((st1.course == st2.course) &&
		//(st1.group == st2.group) &&
		(st1.surname == st2.surname) &&
		(st1.numberRecordBook == st2.numberRecordBook) &&
		(st1.subject == st2.subject)); //&&
									   //(st1.mark == st2.mark));
}

//считывание структуры Student из строки
Student ReadFromString(ifstream& input)
{
	Student result;
	string s;
	try
	{
		if (!input.eof())
		{
			getline(input, s);
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Course: ";
			result.course = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Group: ";
			result.group = s.substr(wrd.length(), s.length());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Surname: ";
			result.surname = s.substr(wrd.length(), s.length());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Number of record book: ";
			result.numberRecordBook = s.substr(wrd.length(), s.length());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Subject: ";
			result.subject = s.substr(wrd.length(), s.length());
		}
		if (!input.eof())
		{
			getline(input, s, '\n');
			string wrd = "Mark: ";
			result.mark = atoi(s.substr(wrd.length(), s.length()).c_str());
		}
	}
	catch (...)
	{
		cout << "Error writing to file!" << endl;
	}
	return result;
}

/*Поиск равного элемента по выбранному критерию
type_search - тип поиска:
1 - по группе
2 - по курсу
3 - по номеру зачетной книжки
4 - по фамилии
5 - по оценке*/
bool SearchElement(Student a, Student b, int type_search)
{
	switch (type_search)
	{
	case 1:
		return (a.group == b.group);
	case 2:
		return (a.course == b.course);
	case 3:
		return (a.numberRecordBook == b.numberRecordBook);
	case 4:
		return (a.surname == b.surname);
	case 5:
		return (a.mark == b.mark);
	default:
		return false;
	}
}

/*Ввод критерия поиска в зависимости от выбранного типа
type_search - тип поиска:
1 - по номеру группы
2 - по номеру курса
3 - по номеру зачетки
4 - по фамилии
5 - по оценке*/
Student InputChangeTypeSearch(int type_search)
{
	Student result;
	switch (type_search)
	{
	case 1:
		result.group = InputInformation("Enter the group: ");
		return result;
	case 2:
		result.course = InputNumber(1, 6, "Enter the course: ");
		return result;
	case 3:
		result.numberRecordBook = InputInformation("Enter the number of record book: ");
		return result;
	case 4:
		result.surname = InputInformation("Enter the surname: ");
		return result;
	case 5:
		result.mark = InputNumber(2, 5, "Enter the mark: ");
		return result;
	default:
		return result;
	}
}

/*Сравнение структур по выбранного полю
type_search - тип поиска:
1 - по номеру группы
2 - по номеру курса
3 - по номеру зачетки
4 - по фамилии
5 - по оценке*/
int Sorte(Student a, Student b, int type_search)
{
	switch (type_search)
	{
	case 1:
		if (a.group > b.group) return 1;
		else if (a.group < b.group) return -1;
		else return 0;
	case 2:
		if (a.course > b.course) return 1;
		else if (a.course < b.course) return -1;
		else return 0;
	case 3:
		if (a.numberRecordBook > b.numberRecordBook) return 1;
		else if (a.numberRecordBook < b.numberRecordBook) return -1;
		else return 0;
	case 4:
		if (a.surname > b.surname) return 1;
		else if (a.surname < b.surname) return -1;
		else return 0;
	case 5:
		if (a.mark > b.mark) return 1;
		else if (a.mark < b.mark) return -1;
		else return 0;
	default:
		return -2;
	}
}
