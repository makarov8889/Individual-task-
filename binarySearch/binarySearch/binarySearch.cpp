// binarySearch.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;
const int N=10;

int BinarySearch(int A[], int key) 
{
	int left=0, right=N, mid; //����� ������� � ������

	while (left<=right)
	{
		mid=left+(right-left)/2; //������� ������ ������� [left,right]
		if (key<A[mid])
			right=mid-1; //��������� ����� ����� ����� ���������
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

	int key; //���������� � ������� ����� ���������� ����
	int A[N]; //������ �� N ���������

	for (int i=0; i<N; i++)
		A[i] = rand()%100 + 10; 

	sort(A, A+10); //��������� � ������� ������� sort 

	cout << "�������� ������: ";
	for (int i=0; i<N; i++)
		cout << A[i] << " ";
	cout << endl;

	cout << "������� �������: ";
	cin >> key; //��������� ����

	if (BinarySearch(A, key)==-1)
		cout << "\n������� �� ������" << endl;
	else
		cout << "\n����� ��������: " << BinarySearch(A, key)+1 << endl;

	system("pause");
}
