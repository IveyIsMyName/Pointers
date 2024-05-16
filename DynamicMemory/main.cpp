#include <iostream>
using namespace std;
#define tab "\t"

void FillRand(int arr[], int n);
void Print(int arr[], int n);
int* push_back(int arr[], int& n, const int value);

void main()
{
	setlocale(LC_ALL, "");
	int n = 5;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	delete[] arr;
}

void FillRand(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
	//обращение к элементам массива через арифметику указателей и оператор разыменования
}
void Print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	//обращение к элементам массива через оператор индексирования[]
	}
	cout << endl;
}

int* push_back(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1]; //буферный массив
	for (int i = 0; i < n; i++)  // копируем значение
	{
		buffer[i] = arr[i];
	}
	delete[] arr;				//удаляет исходный массив
	arr = buffer;				//подменяем адрес в указателе 'arr'
	arr[n] = value;
	n++;						//добавляем новое значение в конец
	return arr;
}