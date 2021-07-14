#include<iostream>
#include<string>
#include<math.h>
#include<random>
#include"functions.h"
#include<time.h>

int main() 
{
	setlocale(LC_ALL, "Russian");
	int num = 150000;//менять количество элементов
	int *mass = new int[num], *mass_cpy_q = new int[num], *mass_cpy_s = new int[num], *mass_cpy_b = new int[num], *mass_cpy_r = new int[num], *mass_cpy_buble = new int[num];

	generate(num);
	read_in(mass, num, "Mass.txt");

	num = 50000;
	cout << "При кол-ве элементов: " << num << endl;
	bub(num, mass,mass_cpy_buble);
	quic(num, mass, mass_cpy_q);
	razr(num, mass, mass_cpy_r);
	shake(num, mass, mass_cpy_s);
	bin(num, mass, mass_cpy_b);
	num = 90000;
	cout << "При кол-ве элементов: " << num << endl;
	bub(num, mass, mass_cpy_buble);
	quic(num, mass, mass_cpy_q);
	razr(num, mass, mass_cpy_r);
	shake(num, mass, mass_cpy_s);
	bin(num, mass, mass_cpy_b);
	num = 120000;
	cout << "При кол-ве элементов: " << num << endl;
	bub(num, mass, mass_cpy_buble);
	quic(num, mass, mass_cpy_q);
	razr(num, mass, mass_cpy_r);
	shake(num, mass, mass_cpy_s);
	bin(num, mass, mass_cpy_b);
	num = 150000;
	cout << "При кол-ве элементов: " << num << endl;
	bub(num, mass, mass_cpy_buble);
	quic(num, mass, mass_cpy_q);
	razr(num, mass, mass_cpy_r);
	shake(num, mass, mass_cpy_s);
	bin(num, mass, mass_cpy_b);

	delete[] mass;
	delete[] mass_cpy_b;
	delete[] mass_cpy_buble;
	delete[] mass_cpy_r;
	delete[] mass_cpy_q;
	delete[] mass_cpy_s;
	
	system("Pause");
	return 0;
}