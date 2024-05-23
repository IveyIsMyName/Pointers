#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"

int** Allocate(int rows, int cols);
void Clear(int** arr, const int rows);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols);
void FillRand(int* arr, const int cols);

void Print(int arr[], int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);

int* insert(int arr[], int& n, const int index, const int value);
int* erase(int arr[], int& n, const int index);

int** push_row_back(int** arr, int& rows, int cols);
int** push_row_front(int** arr, int& rows, int cols);
int** insert_row(int** arr, int& rows, int cols, const int index);

int** pop_row_back(int** arr, int& rows, int cols);
int** pop_row_front(int** arr, int& rows, int cols);
int** erase_row(int** arr, int& rows, int cols, const int index);

int** push_col_back(int** arr, int rows, int& cols);
int** push_col_front(int** arr, int rows, int& cols);
int** insert_col(int** arr, int rows, int& cols, const int index);

int** pop_col_back(int** arr, int rows, int& cols);
int** pop_col_front(int** arr, int rows, int& cols);
int** erase_col(int** arr, int rows, int& cols, const int index);


//#define DYNAMIC_MEMORY_1
//#define SYNTAX
//#define PERFORMANCE_CHECK
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

#ifdef DYNAMIC_MEMORY_2
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
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);

	cout << "Добавляем строку в начало: " << endl;
	arr = push_row_front(arr, rows, cols);
	FillRand(arr[0], cols, 100, 1000);
	Print(arr, rows, cols);

	cout << "Введите индекс для вставки строки: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	if (index < rows)FillRand(arr[index], cols, 100, 1000);
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

	cout << "Добавляем столбец в конце: " << endl;
	arr = push_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Добавляем столбец в начало: " << endl;
	arr = push_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите индекс для вставки столбца: "; cin >> index;
	arr = insert_col(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << "Удаляем последний столбец: " << endl;
	arr = pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Удаляем нулевой столбец: " << endl;
	arr = pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << "Введите индекс для удаления столбца: "; cin >> index;
	arr = erase_col(arr, rows, cols, index);
	Print(arr, rows, cols);


	Clear(arr, rows);
#endif // DYNAMIC_MEMORY_2

#ifdef PERFORMANCE_CHECK
	int rows;
	int cols;
	cout << "Введите количество строк: "; cin >> rows;	//Enter number of rows
	cout << "Введите количество элементов строки: "; cin >> cols;

	int** arr = Allocate(rows, cols);
	cout << "Memory allocated" << endl;
	//FillRand(arr, rows, cols);
	//cout << "Data loaded" << endl;
	cout << "Press any key to add row" << endl;
	system("PAUSE");
	arr = push_row_back(arr, rows, cols);
	cout << "Row added" << endl;
	cout << "To clear memory ";
	system("PAUSE");

	Clear(arr, rows);
#endif // PERFORMANCE_CHECK
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
void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
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
	int** buffer = new int*[rows + 1];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	buffer[rows] = new int[cols] {};
	rows++;
	
	return buffer;
}
int** push_row_front(int** arr, int& rows, int cols)
{
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = new int[cols] {};
	rows++;

	return buffer;
}
int** insert_row(int** arr, int& rows, int cols, const int index)
{
	if (index >= rows)return arr;
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows; i++)
	{
		buffer[i < index ? i : i + 1] = arr[i];
	}
	delete[] arr;
	buffer[index] = new int[cols];
	rows++;

	return buffer;
}
int** pop_row_back(int** arr, int& rows, int cols)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++) buffer[i] = arr[i];
	delete[] arr;

	return buffer;
}
int** pop_row_front(int** arr, int& rows, int cols)
{
	int** buffer = new int* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i + 1];
	delete[] arr;

	return buffer;
}
int** erase_row(int** arr, int& rows, int cols, const int index)
{
	int** buffer = new int*[--rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i < index ? i : i + 1];
	}
	delete[] arr[rows];
	delete[] arr;

	return buffer;
}
int** push_col_back(int** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
	return arr;
}
int** push_col_front(int** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;

	return arr;
}
int** insert_col(int** arr, int rows, int& cols, const int index)
{
	if (index < 0 || index > cols)return arr;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int k = index; k < cols; k++)
		{
			buffer[k + 1] = arr[i][k];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}	
	cols++;

	return arr;
}
int** pop_col_back(int** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;

	return arr;
}
int** pop_col_front(int** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
		for (int j = 1; j < cols; j++)
		{
			buffer[j - 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;

	return arr;
}
int** erase_col (int** arr, int rows, int& cols, const int index)
{
	if (index < 0 || index >= cols)return arr;

	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = index; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;

	return arr;
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
int* erase(int arr[], int& n, const int index)
{
	int* buffer = new int[--n];

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i < index ? i : i + 1];
	}
	delete[]arr;
	arr = buffer;
	
	return arr;
}