#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define tab "\t"

template<typename T>T** Allocate(int rows, int cols);
template<typename T>void Clear(T** arr, const int rows);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n);
void FillRand(char arr[], const int n);
template<typename T>void FillRand(T** arr, const int rows, const int cols);

template<typename T>void Print(T arr[], int n);
template<typename T>void Print(T** arr, const int rows, const int cols);

template<typename T>T* push_back(T arr[], int& n, const T value);
template<typename T>T* push_front(T arr[], int& n, const T value);

template<typename T>T* pop_back(T arr[], int& n);
template<typename T>T* pop_front(T arr[], int& n);

template<typename T>T* insert(T arr[], int& n, int index, const T value);
template<typename T>T* erase(T arr[], int& n, const int index);

template<typename T>T** push_row_back(T** arr, int& rows, int cols);
template<typename T>T** push_row_front(T** arr, int& rows, int cols);
template<typename T>T** insert_row(T** arr, int& rows, int cols, const int index);

template<typename T>T** pop_row_back(T** arr, int& rows, int cols);
template<typename T>T** pop_row_front(T** arr, int& rows, int cols);
template<typename T>T** erase_row(T** arr, int& rows, int cols, const int index);

template<typename T>T** push_col_back(T** arr, int rows, int& cols);
template<typename T>T** push_col_front(T** arr, int rows, int& cols);
template<typename T>T** insert_col(T** arr, int rows, int& cols, const int index);

template<typename T>T** pop_col_back(T** arr, int rows, int& cols);
template<typename T>T** pop_col_front(T** arr, int rows, int& cols);
template<typename T>T** erase_col(T** arr, int rows, int& cols, const int index);


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

	cout << "Добавляем строку в конце: " << endl;
	double** d_arr = Allocate<double>(rows, cols);
	FillRand(d_arr, rows, cols);
	d_arr = push_row_back(d_arr, rows, cols);
	FillRand(d_arr[rows - 1], cols);
	Print(d_arr, rows, cols);

	cout << "Добавляем строку в начало: " << endl;
	d_arr = push_row_front(d_arr, rows, cols);
	FillRand(d_arr[0], cols);
	Print(d_arr, rows, cols);
	
	Clear(d_arr, rows);

	cout << "Введите индекс для вставки строки: "; cin >> index;
	char** c_arr = Allocate<char>(rows, cols);
	FillRand(c_arr, rows, cols);
	c_arr = insert_row(c_arr, rows, cols, index);
	if (index < rows)FillRand(c_arr[index], cols);
	Print(c_arr, rows, cols);

	cout << "Удаляем последнюю строку: " << endl;
	c_arr = pop_row_back(c_arr, rows, cols);
	Print(c_arr, rows, cols);

	cout << "Удаляем нулевую строку: " << endl;
	c_arr = pop_row_front(c_arr, rows, cols);
	Print(c_arr, rows, cols);

	cout << "Введите индекс для удаления строки: "; cin >> index;
	c_arr = erase_row(c_arr, rows, cols, index);
	Print(c_arr, rows, cols);
	
	Clear(c_arr, rows);

	cout << "Добавляем столбец в конце: " << endl;
	int** arr = Allocate<int>(rows, cols);
	FillRand(arr, rows, cols);
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

	cout << "введите индекс для удаления столбца: "; cin >> index;
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

template<typename T>T** Allocate(int rows, int cols)
{
	T** arr = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols];
	}
	return arr;
}

template<typename T>void Clear(T** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

template<typename T>void FillRand(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
	}
}
void FillRand(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 10000;
		arr[i] /= 100;
	}
}
void FillRand(char arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
	}
}

template<typename T>void Print(T arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	//обращение к элементам массива через оператор индексирования[]
	}
	cout << endl;
}
template<typename T>void Print(T** arr, const int rows, const int cols)
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

template<typename T>T** push_row_back(T** arr, int& rows, int cols)
{
	return push_back(arr, rows, new T[cols]{});
}
template<typename T>T** push_row_front(T** arr, int& rows, int cols)
{
	return push_front(arr, rows, new T[cols]{});
}
template<typename T>T** insert_row(T** arr, int& rows, int cols, const int index)
{
	if (index >= rows)return arr;
	return insert(arr, rows, index, new T[cols]{});
}
template<typename T>T** pop_row_back(T** arr, int& rows, int cols)
{
	delete[] arr[rows-1];
	return pop_back(arr, rows);
}
template<typename T>T** pop_row_front(T** arr, int& rows, int cols)
{
	delete[] arr[0];
	return pop_front(arr, rows);
}
template<typename T>T** erase_row(T** arr, int& rows, int cols, const int index)
{
	delete[] arr[index];
	return erase(arr, rows, index);
}
template<typename T>T** push_col_back(T** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = push_back(arr[i], cols, T()); // - значение по умолчанию для шаблонного типа
		cols--;
	}
	cols++;
	
	return arr;
}
template<typename T>T** push_col_front(T** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		arr[i] = push_front(arr[i], cols, T()); // - значение по умолчанию для шаблонного типа
		cols--;
	}
	cols++;

	return arr;
}
template<typename T>T** insert_col(T** arr, int rows, int& cols, const int index)
{
	if (index < 0 || index > cols)return arr;
	
	for (int i = 0; i < rows; i++)
	{
		arr[i] = insert(arr[i], cols, index, T()); // - значение по умолчанию для шаблонного типа
		cols--;
	}
	cols++;
	
	return arr;
}
template<typename T>T** pop_col_back(T** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1];
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
template<typename T>T** pop_col_front(T** arr, int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1];
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
template<typename T>T** erase_col (T** arr, int rows, int& cols, const int index)
{
	if (index < 0 || index >= cols)return arr;

	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1];
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
template<typename T>T* push_back(T arr[], int& n, const T value)
{
	T* buffer = new T[n + 1]; //буферный массив
	for (int i = 0; i < n; i++)  // копируем значение
	{
		buffer[i] = arr[i];
	}
	delete[] arr;				//удаляет исходный массив
	arr = buffer;				//подменяем адрес в указателе 'arr'
	buffer[n] = value;
	n++;						//добавляем новое значение в конец

	return buffer;
}
template<typename T>T* push_front(T arr[], int& n, const T value)
{
	T* buffer = new T[n + 1]; 
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
template<typename T>T* insert(T arr[], int& n, int index, const T value)
{
	T* buffer = new T[n + 1];
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
template<typename T>T* pop_back(T arr[], int& n)
{
	int newSize = n - 1;
	T* buffer = new T[newSize];
	for (int i = 0; i < newSize; i++)
	{
		buffer[i] = arr[i];
	}
	delete[]arr;
	arr = buffer;
	n = newSize;

	return arr;
}
template<typename T>T* pop_front(T arr[], int& n)
{
	int newSize = n - 1;
	T* buffer = new T[newSize];
	for (int i = 0; i < newSize; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[]arr;
	arr = buffer;
	n = newSize;
	
	return arr;
}
template<typename T>T* erase(T arr[], int& n, const int index)
{
	T* buffer = new T[--n];

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i < index ? i : i + 1];
	}
	delete[]arr;
	arr = buffer;
	
	return arr;
}