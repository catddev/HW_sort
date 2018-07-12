#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<math.h>
#include<time.h>
#include <Windows.h>
#include <iostream>
#include <iomanip> 

using namespace std;

int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

start:

	cout << "Задача № ";
	cin >> tn;

	switch (tn)
	{
	case 1:
	{
		// Необходимо отсортировать первые две трети массива в порядке возрастания
		// если среднее арифметическое всех элементов больше нуля;
		// иначе - лишь первую треть.
		// остальную часть массива не сортировать а расположить в обратном порядке.

		const int size_max = 20;
		int a[size_max];
		int n;

		double sum = 0;
		int i, pass;
		int border;

		cout << "введите количество элементов массива до 20 элементов включительно: ";
		cin >> n;
		for (i = 0; i < n; i++)
		{
			a[i] = -15 + rand() % 50;
			cout << a[i] << " ";
		}
		cout << endl;

		for (i = 0; i < n; i++)
			sum = sum + a[i];
		cout << "average = " << sum / n << endl;

		if (sum / n > 0)
		{
			border = n - n / 3;
			cout << "border = " << border << endl;
			for (pass = 1; pass < border; pass++)
			{
				i = pass;
				while ((a[i] < a[i - 1]) && i > 0)
				{
					swap(a[i], a[i - 1]);
					i--;
				}
			}
		}
		else
		{
			border = n / 3;
			for (pass = 1; pass < border; pass++)
			{
				i = pass;
				while ((a[i] < a[i - 1]) && i > 0)
				{
					swap(a[i], a[i - 1]);
					i--;
				}
			}
		}

		int center = n - (n - border) / 2;
		int k;
		for (i = border, k = n - 1; i < center; i++, k--)
			swap(a[i], a[k]);

		cout << "sorted part: ";
		for (i = 0; i < border; i++)
			cout << a[i] << " ";
		cout << "reverse order part: ";
		for (i = border; i<n; i++)
			cout << a[i] << " ";

		cout << endl << endl;
	}
	break;
	case 2: // Реализовать Сортировку выбором
	{
		const int n = 8;
		double a[n] = { 4, 7, 0, 20, 17, 11, 1, 18 };

		int i = 0;
		double min_e;
		int k = 0;


		for (int pass = 0; pass < n - 1; pass++)
		{
			min_e = a[n - 1];

			for (i = pass + 1; i < n; i++)
			{
				if (a[i] <= min_e)
				{
					min_e = a[i];
					k = i;
				}
			}
			if (min_e<a[pass]) swap(a[k], a[pass]);
		}

		for (int i = 0; i < n; i++)
			cout << a[i] << " ";

		cout << endl << endl;
	}
	break;
	default:
		cout << "нет такой задачи" << endl << endl;
	}
	goto start;

	system("pause");
	return 0;
}