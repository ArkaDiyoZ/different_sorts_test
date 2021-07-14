#pragma once
#include<iostream>
#include<math.h>
#include <fstream>
#include<ctime>
#include<string>
#include<random>
#include"functions.h"
using namespace std;

void generate(int num)
{
	int *randomDigits = new int[num];
	srand(time(NULL));
	random_device rd;
	mt19937_64 gen(rd());
	uniform_int_distribution<unsigned long long> dis;
	int temp;
	for (int i = 0; i < num; i++)
	{
		//x = a + rand() % b;
		randomDigits[i] = 10000000 + dis(gen) % 99999999; //10000000  ... 99999999
	}

	ofstream out;
	out.open("Mass.txt");
	if (out.is_open())
	{
		for (int i = 0; i < num; i++)
		{
			out << randomDigits[i] << " ";
		}
	}

	cout << "End of program" << endl;
	out.close();
	delete[] randomDigits;
}
void read_in(int *mass, int num, string path) {


	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "ќшибка открыти€ !" << endl;
	}
	else
	{
		for (int i = 0; i < num; i++)
		{
			fin >> mass[i];
		}

	}
}
void mass_copy(int *mas1, int *mas2, int num)
{

	for (int i = 0; i < num; i++)
	{
		mas2[i] = mas1[i];
	}


}
void reverce(int *mass1, int num)
{
	int time;
	for (int i = 0; i < num - i - 1; i++) {
		time = mass1[i];
		mass1[i] = mass1[num - i - 1];
		mass1[num - i - 1] = time;
	}
};
void write_in(int *mass, int num, string path) {


	ofstream out;
	out.open(path);
	if (!out.is_open())
	{
		cout << "ќшибка открыти€ !" << endl;
	}
	else
	{
		for (int i = 0; i < num; i++)
		{
			out << mass[i] << " ";
		}

	}
}
void bubble(int*mass, int num)
{
	int temp;
	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - i - 1; j++) {
			if (mass[j] > mass[j + 1]) {
				temp = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = temp;
			}
		}
	}

}
void QuickSort(int *mass, int n)//она же сортировка ’оара
{
	int x, w, i, j;
	x = mass[n / 2];
	i = 0; j = n - 1;
	do
	{
		while (mass[i] < x) i++;
		while (x < mass[j]) j--;
		if (i <= j)
		{
			w = mass[i];
			mass[i] = mass[j];
			mass[j] = w;
			i++; j--;
		}
	} while (i < j);
	if (j > 0)
		QuickSort(mass, j + 1);
	if (i < n - 1)
		QuickSort(mass + i, n - i);
}
void ShakerSort(int *mass, int num)
{
	int j, k = num - 1, left = 1, right = num - 1, x;
	do
	{
		for (j = right; j >= left; j--)
			if (mass[j - 1] > mass[j])
			{
				x = mass[j - 1];
				mass[j - 1] = mass[j];
				mass[j] = x;
				k = j;
			}
		left = k + 1;
		for (j = left; j <= right; j++)
			if (mass[j - 1] > mass[j])
			{
				x = mass[j - 1];
				mass[j - 1] = mass[j];
				mass[j] = x;
				k = j;
			}
		right = k - 1;
	} while (left < right);
}
void BinaryInsertion(int *mass, int num)
{
	int i, j, m, left, right, x;
	for (i = 1; i < num; i++)
	{
		x = mass[i]; left = 0; right = i;
		while (left < right)
		{
			m = left + (right - left) / 2;
			if (mass[m] <= x)
				left = m + 1;
			else
				right = m;
		}
		for (j = i; j > right; mass[j] = mass[j - 1], j--);
		mass[right] = x;
	}
}
int getMax(int *arr, int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}
void countSort(int *arr, int n, int exp)
{
	int *output = new int[n];
	int i, count[10] = { 0 };

	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;


	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];


	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}


	for (i = 0; i < n; i++)
		arr[i] = output[i];
}
void radixsort(int *arr, int n)
{
	int m = getMax(arr, n);
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}
void bub(int num,int*mass,int*mass_cpy) 
{
	clock_t t1, t2;
	//-----ѕ”«џ–≈ ---------------------------------
	//его нет в задании, но дл€ теста был реализован, медленный он,конечно
	//все значени€ записаны в файлы с названи€ми сортировок, где можно проверить их работу
	cout << "+---------------------------+" << endl;
	mass_copy(mass, mass_cpy, num);
	t1 = clock();
	bubble(mass_cpy, num);
	t2 = clock();
	cout << (t2 - t1)*0.001 << " - bubble time" << endl;
	//write_in(mass_cpy, num, "bubble.txt");

	t1 = clock();
	bubble(mass_cpy, num);
	t2 = clock();
	cout << (t2 - t1)*0.001 << " - bubble time resort" << endl;

	reverce(mass_cpy, num);//перевернули

	t1 = clock();
	bubble(mass_cpy, num);
	t2 = clock();
	cout << (t2 - t1)*0.001 << " - bubble time reverce" << endl;

	cout << "+---------------------------+" << endl;
	//--------------------------------------------

};
void quic(int num, int*mass, int*mass_cpy_q) 
{
	clock_t t1, t2;
	//-----Ѕџ—“–јя--------------------------------
	cout << "+---------------------------+" << endl;
	mass_copy(mass, mass_cpy_q, num);

	t1 = clock();
	QuickSort(mass_cpy_q, num);
	t2 = clock();
	cout << (t2 - t1)*0.001 << " - quick time" << endl;
	//write_in(mass_cpy_q, num, "quick.txt");

	t1 = clock();
	QuickSort(mass_cpy_q, num);
	t2 = clock();
	cout << (t2 - t1)*0.001 << " - quick time resort" << endl;

	reverce(mass_cpy_q, num);//перевернули

	t1 = clock();
	QuickSort(mass_cpy_q, num);
	t2 = clock();
	cout << (t2 - t1)*0.001 << " - quick time reverce" << endl;

	cout << "+---------------------------+" << endl;
	//--------------------------------------------



}
void razr(int num, int*mass, int*mass_cpy_r) 
{
	//-----ѕќ–ј«–яƒЌјя----------------------------
	cout << "+---------------------------+" << endl;
	clock_t t1, t2;
	mass_copy(mass, mass_cpy_r, num);

	t1 = clock();
	QuickSort(mass_cpy_r, num);
	t2 = clock();
	cout << (t2 - t1)*0.001 << " - radix time" << endl;
	//write_in(mass_cpy_r, num, "radix.txt");

	t1 = clock();
	QuickSort(mass_cpy_r, num);
	t2 = clock();
	cout << (t2 - t1)*0.001 << " - radix time resort" << endl;

	reverce(mass_cpy_r, num);//перевернули

	t1 = clock();
	QuickSort(mass_cpy_r, num);
	t2 = clock();
	cout << (t2 - t1)*0.001 << " - radix time reverce" << endl;


	cout << "+---------------------------+" << endl;
	//--------------------------------------------


}
void shake(int num, int*mass, int*mass_cpy_s) 
{
	//------Ў≈… ≈–Ќјя------------------------------
	cout << "+---------------------------+" << endl;
	clock_t t1, t2;
	mass_copy(mass, mass_cpy_s, num);

	t1 = clock();
	ShakerSort(mass_cpy_s, num);
	t2 = clock();
	cout << (t2 - t1)*0.001 << " - shake time" << endl;
	//write_in(mass_cpy_s, num, "shake.txt");

	t1 = clock();
	ShakerSort(mass_cpy_s, num);
	t2 = clock();
	cout << (t2 - t1)*0.001 << " - shake time resort" << endl;

	reverce(mass_cpy_s, num);//перевернули

	t1 = clock();
	ShakerSort(mass_cpy_s, num);
	t2 = clock();
	cout << (t2 - t1)*0.001 << " - shake time reverce" << endl;

	cout << "+---------------------------+" << endl;
	//--------------------------------------------

}
void bin(int num, int*mass, int*mass_cpy_b) 
{
	//------Ѕ»Ќј–Ќџћ»-----------------------------
	cout << "+---------------------------+" << endl;
	clock_t t1, t2;
	mass_copy(mass, mass_cpy_b, num);

	t1 = clock();
	BinaryInsertion(mass_cpy_b, num);
	t2 = clock();
	cout << (t2 - t1)*0.001 << " - binisert time" << endl;
	//write_in(mass_cpy_b, num, "bins.txt");

	t1 = clock();
	BinaryInsertion(mass_cpy_b, num);
	t2 = clock();
	cout << (t2 - t1)*0.001 << " - binisert time resort" << endl;

	reverce(mass_cpy_b, num);//перевернули

	t1 = clock();
	BinaryInsertion(mass_cpy_b, num);
	t2 = clock();
	cout << (t2 - t1)*0.001 << " - binisert time reverce" << endl;


	cout << "+---------------------------+" << endl;
	//--------------------------------------------

}