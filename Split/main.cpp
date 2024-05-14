#include <iostream>
using namespace std;
#define tab "\t"

void FillRand(int arr[],const int n);
void Print(int arr[],const int n);
void OddArray(int arr[],const int n, int odd[], int odd_size);
void EvenArray(int arr[],const int n, int odd[], int odd_size);

void main()
{
	setlocale(LC_ALL, "");
	
	const int n = 10;
	int arr[n];
	int odd_size = 0;
	int even_size = 0;
	
	FillRand(arr, n);
	cout << "Исходный массив: " << endl;
	Print(arr, n);
	int* odd = new int[odd_size];
	int* even = new int[even_size];
	cout << "Массив с четными числами: " << endl;
	OddArray(arr, n, odd, odd_size);
	cout << "Массив с нечетными числами: " << endl;
	EvenArray(arr, n, even, even_size);
}

void OddArray(int arr[], const int n, int odd[], int odd_size)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 1)
		{
			odd_size++;
			odd[i] = *(arr + i);
			cout << odd[i] << tab;
		}
	}
	cout << endl;
}
void EvenArray(int arr[], const int n, int even[], int even_size)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0)
		{
			even_size++;
			even[i] = *(arr + i);
			cout << even[i] << tab;
		}
	}
	cout << endl;
}
void FillRand(int arr[],const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand()%100+1;
	}
}
void Print(int arr[],const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}
