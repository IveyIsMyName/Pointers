#include <iostream>
using namespace std;
#define tab "\t"

void FillRand(int arr[], int n);
void Print(int arr[], int n);
int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);
int* insert(int arr[], int& n, int index, const int value);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, int index);

void main()
{
	setlocale(LC_ALL, "");
	
	int n = 5;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение в конец массива: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	
	cout << "Введите добавляемое значение в начало массива: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	int index;
	cout << "Введите добавляемое значение на место индекса: "; cin >> value;
	cout << "Введите индекс: "; cin >> index;
	arr = insert(arr, n, index, value);
	Print(arr, n);

	cout << "Массив без последнего элемента: " << endl;
	arr = pop_back(arr, n);
	Print(arr, n);

	cout << "Массив без нулевого элемента: " << endl;
	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "Введите индекс элемента, которые хотите удалить: "; cin >> index;
	arr = erase(arr, n, index);
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

int* push_front(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1]; 
	for (int i = 0; i < n; i++)  
	{
		buffer[i] = arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;				
	arr = buffer;
	arr[0] = value;
	n++;

	return arr;
}


int* insert(int arr[], int& n, int index, const int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++) 
	{
		buffer[i] = arr[i];
	}
	for (int i = n; i > index; i--) {
		buffer[i] = buffer[i - 1];
	}
	delete[] arr;
	buffer[index] = value;
	arr = buffer;
	n++;

	return arr;
}

int* pop_back(int arr[], int& n)
{
	int newSize = n - 1;
	int* buffer = new int[newSize];
	for (int i = 0; i < newSize; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	n = newSize;

	return arr;
}
int* pop_front(int arr[], int& n)
{
	int newSize = n - 1;
	int* buffer = new int[newSize];
	for (int i = 0; i < newSize; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[]arr;
	arr = buffer;
	n = newSize;
	
	return arr;
}
int* erase(int arr[], int& n, int index)
{
	int newSize = n - 1;
	int* buffer = new int[newSize];

	for (int i = 0, j = 0; i < n; i++)
	{
		if (i != index)
		{
			buffer[j++] = arr[i];
		}
	}
	delete[]arr;
	arr = buffer;
	n = newSize;
	
	return arr;
}