#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"

void FillRand(int** arr, const int rows, const int cols);
void FillRand(int* arr, const int cols);

void Print(int arr[], int n);
void Print(int** arr, const int rows, const int cols);

int** Allocate(int rows, int cols);
void Clear(int** arr, const int rows);

int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);

int** push_row_back(int** arr, int& rows, int cols);
int** push_row_front(int** arr, int& rows, int cols);
int** insert_row(int** arr, int& rows, int cols, int index);
int** pop_row_back(int** arr, int& rows, int cols);
int** pop_row_front(int** arr, int& rows, int cols);
int** erase_row(int** arr, int& rows, int cols, int index);

int* insert(int arr[], int& n, int index, const int value);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);

int* erase(int arr[], int& n, int index);

//#define DYNAMIC_MEMORY_1
//#define SYNTAX
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
	
#ifdef DYNAMIC_MEMORY_1
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
#endif // DYNAMIC_MEMORY_1 

#ifdef SYNTAX
	int rows = 3;
	int cols = 4;

	int** arr = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
#endif // SYNTAX

	int rows;
	int cols;
	int index;
	
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	int** arr = Allocate(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Добавляем строку в конце: " << endl;
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Добавляем строку в начало: " << endl;
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите индекс для вставки строки: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << "Удаляем последнюю строку: " << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Удаляем нулевую строку: " << endl;
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите индекс для удаления строки: "; cin >> index;
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	Clear(arr, rows);

}


void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void FillRand(int* arr, const int cols)
{
	for (int i = 0; i < cols; i++)
	{
		arr[i] = rand() % 100;
	}
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
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << *( *(arr + i) + j) << tab;
		}
		cout << endl;
	}
	cout << endl;
}

int** Allocate(int rows, int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}
void Clear(int** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
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
int** push_row_back(int** arr, int& rows, int cols)
{
	int* newRow = new int[cols];
	FillRand(newRow, cols);
	int** buffer = Allocate(rows + 1, cols);
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	buffer[rows] = newRow;
	delete[] arr;
	rows++;
	return buffer;
}
int** push_row_front(int** arr, int& rows, int cols)
{
	int* newRow = new int[cols];
	FillRand(newRow, cols);
	int** buffer = Allocate(rows + 1, cols);
	for (int j = 0; j < cols; j++)buffer[0][j] = newRow[j];
	for (int i = 0; i <  rows; i++)
		for (int j = 0; j < cols; j++)
		{
			buffer[i + 1][j] = arr[i][j];
		}
	Clear(arr, rows);
	rows++;

	return buffer;
}
int** insert_row(int** arr, int& rows, int cols, int index)
{
	int* newRow = new int[cols];
	FillRand(newRow, cols);
	int** buffer = Allocate(rows + 1, cols);
	for (int i = 0, j = 0; i < rows + 1; i++)
	{
		if (i == index)
		{
			for (int k = 0; k < cols; k++)buffer[i][k] = newRow[k];
		}
		else
		{
			for (int k = 0; k < cols; k++)buffer[i][k] = arr[j][k];
			j++;
		}
	}
	Clear(arr, rows);
	rows++;

	return buffer;
}
int** pop_row_back(int** arr, int& rows, int cols)
{
	int** buffer = Allocate(rows - 1, cols);
	for (int i = 0; i < rows - 1; i++)
		for (int j = 0; j < cols; j++)
			buffer[i][j] = arr[i][j];
	Clear(arr, rows);
	rows--;

	return buffer;
}
int** pop_row_front(int** arr, int& rows, int cols)
{
	int** buffer = Allocate(rows - 1, cols);
	for (int i = 1; i < rows; i++)
		for (int j = 0; j < cols; j++)
			buffer[i - 1][j] = arr[i][j];
	Clear(arr, rows);
	rows--;

	return buffer;
}
int** erase_row(int** arr, int& rows, int cols, int index)
{
	int** buffer = Allocate(rows - 1, cols);
	for (int i = 0; i < index; i++)
		for (int j = 0; j < cols; j++)
			buffer[i][j] = arr[i][j];
	
	for (int i = index + 1; i < rows; i++)
		for (int j = 0; j < cols; j++)
			buffer[i - 1][j] = arr[i][j];
	Clear(arr, rows);
	rows--;

	return buffer;
}
int* push_front(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1]; 
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
	/*for (int i = 0; i < n; i++) 
	{
		buffer[i] = arr[i];
	}
	for (int i = n; i > index; i--) {
		buffer[i] = buffer[i - 1];
	}*/
	for (int i = 0; i < n; i++)
	{
		buffer[i < index ? i : i + 1] = arr[i];
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
			buffer[j] = arr[i];
			j++;
		}
	}
	delete[]arr;
	arr = buffer;
	n = newSize;
	
	return arr;
}