#include <iostream>
using namespace std;
#define tab "\t"

void main()
{
	setlocale(LC_ALL, "");

	const int n = 10;
	int arr[n] = { 1,2,3,4,5,6,7,8,9,10 };
	int odd_size = 0;
	int even_size = 0;

	cout << "Исходный массив: ";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
	
	int* odd = new int[odd_size];
	int* even = new int[even_size];
	
	cout << "Массив с четными числами: ";
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 1)
		{
			odd_size++;
			*(odd + i) = *(arr + i);
			cout << *(odd + i) << tab;
		}
	}
	cout << endl;
	
	cout << "Массив с нечетными числами: ";
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			even_size++;
			*(even + i) = *(arr + i);
			cout << *(even + i) << tab;
		}
	}
	cout << endl;
	
}