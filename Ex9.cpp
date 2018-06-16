/*
Результатом должна быть консольная программа с текстовым меню. Программа должна содержать шаблонный класс для управления данными согласно заданию. 
Для хранения данных необходимо выбрать оптимальный с точки зрения задания контейнер.
Предусмотреть операции добавления, изменения и удаления элемента контейнера.
Реализовать ввод и вывод элементов контейнера с использованием потоковых итераторов на экран и в файл.
Реализовать операции поиска по заданным критериям и выборки подмножества элементов по заданным критериям. 
Реализовать поиск в двух вариантах: линейный поиск и двоичный поиск на отсортированном контейнере.
Предусмотреть вывод подмножества выборки на экран и в файл.

Запись в журнале экзаменационной сессии содержит следующую информацию : курс, код группы, фамилия студента, номер зачетной книжки, дисциплина, оценка по дисциплине.
Поиск по группе, по курсу, по номеру зачетной книжки, по фамилии, по оценкам.
*/
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
#include "HelpUtils.h"
#include "VectorOperations.h"
#include "Student.h"
using namespace std;

//Меню
int Menu()
{
	cout << "\n";
	cout << "1 - Add item" << endl;
	cout << "2 - Delete item" << endl;
	cout << "3 - Change item" << endl;
	cout << "4 - Output on display" << endl;
	cout << "5 - Save to file " << endl;
	cout << "6 - Linear search" << endl;
	cout << "7 - Binary search" << endl;
	cout << "8 - Display the subset on the screen" << endl;
	cout << "9 - Save a subset to a file" << endl;
	cout << "0 - Exit" << endl << endl;
	int n = InputNumber(0, 9, "Your choice: ");
	cout << "\n";
	return n;
}

void main()
{
	Task<Student> task;
	bool change = true;
	cout << "\n";
	cout << "1 - Filling the container from the console" << endl;
	cout << "2 - Filling the container from a file " << endl;
	cout << "0 - Exit" << endl << endl;
	int changemenu = InputNumber(0, 2, "Your choice: ");
	switch (changemenu)
	{
	case 1:
		task.ReadFromScreen(InputScreenCompany);
		break;
	
	case 2:
		change = task.ReadFromFile(ReadFromString);
		break;

	default:
		change = false;
		break;
	}
	if (change)
	{
		Student elem;
		vector<Student> subset;
		Student search_elem;
		int numb;
		while (1)
		{
			int n = Menu();
			switch (n)
			{
			case 1:
				task.Add(InputScreenCompany());
				break;

			case 2:
				task.OutputScreen(task.vect, OutputScreenCompany);
				task.Remove(InputNumber(0, task.size(), "Enter the number of the element to remove (0 - if you change your mind to delete): "));
				break;

			case 3:
				task.OutputScreen(task.vect, OutputScreenCompany);
				numb = InputNumber(0, task.size(), "Enter the number of the element to be changed (0 - if you change your mind): ");
				if (numb != 0)
					task.vect[numb - 1] = elem.ChangeCompany(task.vect[numb - 1]);
				break;

			case 4:
				task.OutputScreen(task.vect, OutputScreenCompany);
				break;

			case 5:
				task.OutputFile(task.vect, ToString);
				break;

			case 6:
				numb = InputNumber(1, 5, "Choose the type of search:\n 1 - by group\n 2 - by course\n 3 - by number of record book\n 4 - by surname\n 5 - by mark\n\nYour choice: ");
				search_elem = InputChangeTypeSearch(numb);
				subset = task.LineSearch(search_elem, SearchElement, numb);
				if (subset.size() != 0)
					task.OutputScreen(subset, OutputScreenCompany);
				else
					cout << "Items is not found" << endl;
				break;

			case 7:
				numb = InputNumber(1, 5, "Choose the type of search:\n 1 - by group\n 2 - by course\n 3 - by number of record book\n 4 - by surname\n 5 - by mark\n\n Your choice: ");
				search_elem = InputChangeTypeSearch(numb);
				subset = task.BinarySearch(numb, search_elem, Sorte, SearchElement);
				if (subset.size() != 0)
					task.OutputScreen(subset, OutputScreenCompany);
				else
					cout << "Items is not found" << endl;
				break;

			case 8:
				task.OutputScreen(subset, OutputScreenCompany);
				break;

			case 9:
				task.OutputFile(subset, ToString);
				break;

			default:
				exit(0);
				break;
			}
		}
	}
}