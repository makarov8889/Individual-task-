// binarySearch.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;
const int N=10;

int BinarySearch(int A[], int key) 
{
	int left=0, right=N, mid; //левая граница и правая

	while (left<=right)
	{
		mid=left+(right-left)/2; //средний индекс отрезка [left,right]
		if (key<A[mid])
			right=mid-1; //проверяем какую часть нужно отбросить
		else if (key>A[mid])
			left=mid+1;
		else
			return mid;
	}
	return -1;
}

void main()
{
	setlocale(LC_ALL,"Rus");

	int key; //переменная в которой будет находиться ключ
	int A[N]; //массив на N элементов

	for (int i=0; i<N; i++)
		A[i] = rand()%100 + 10; 

	sort(A, A+10); //сортируем с помощью функции sort 

	cout << "Исходный массив: ";
	for (int i=0; i<N; i++)
		cout << A[i] << " ";
	cout << endl;

	cout << "Искомый элемент: ";
	cin >> key; //считываем ключ

	if (BinarySearch(A, key)==-1)
		cout << "\nЭлемент не найден" << endl;
	else
		cout << "\nНомер элемента: " << BinarySearch(A, key)+1 << endl;

	system("pause");
}
