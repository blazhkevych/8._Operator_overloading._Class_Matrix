#include <iostream>
#include "Matrix.h"
using std::cout;
using std::cin;
using std::endl;

// Конструктор по умолчанию.
Matrix::Matrix() :m_p{ nullptr }, m_row{ 0 }, m_col(0){};
//{
//	m_p = nullptr;
//	m_row = 0;
//	m_col = 0;
//}

// Конструктор с 2 параметрами.
Matrix::Matrix(int row, int col) :m_row{ row }, m_col(col)
{
	/*m_row = row;
	m_col = col;*/
	m_p = new int* [m_row]();
	for (int i = 0; i < m_row; i++)
		m_p[i] = new int[m_col]();
}

//Конструктор копирования.
Matrix::Matrix(const Matrix& matrix) :m_row{ matrix.m_row }, m_col{ matrix.m_col }
{
	/*m_row = matrix.m_row;
	m_col = matrix.m_col;*/
	m_p = new int* [m_row];
	for (int i = 0; i < m_row; i++)
		m_p[i] = new int[m_col];

	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			m_p[i][j] = matrix.m_p[i][j];
		}
	}
}

// Реализация семантики переноса с использованием r-value ссылок.
// Конструктор переноса.
Matrix::Matrix(Matrix&& matrix)
	: m_p{ matrix.m_p }, m_row{ matrix.m_row }, m_col{ matrix.m_col }
{
	// Присваивание.
	/*m_p = matrix.m_p;
	m_row = matrix.m_row;
	m_col = matrix.m_col;*/

	// Обнуление matrix.	
	matrix.m_p = nullptr;
	matrix.m_row = 0;
	matrix.m_col = 0;
}

// Деструктор.
Matrix::~Matrix()
{
	for (int i = 0; i < m_row; i++)
		delete[] m_p[i];
	delete[] m_p;
}

// Перегруженный оператор присваивания с копированием.
Matrix& Matrix::operator=(const Matrix& matrix)
{
	if (this == &matrix) // Если самоприсваивание.
		return *this;

	for (int i = 0; i < m_row; i++) // Очистка принимающего обьекта.
		delete[] m_p[i];
	delete[] m_p;

	m_p = new int* [matrix.m_row]; // Выделение памяти под входящий обьект.
	for (int i = 0; i < matrix.m_row; i++)
		m_p[i] = new int[matrix.m_col];

	// Копируем данные из входящего обьекта в принимающий.
	m_row = matrix.m_row;
	m_col = matrix.m_col;
	for (int i = 0; i < m_row; ++i)
		for (int j = 0; j < m_col; j++)
			m_p[i][j] = matrix.m_p[i][j];

	return *this;
}

// Перегруженный оператор присваивания с переносом.
Matrix& Matrix::operator=(Matrix&& matrix)
{
	if (this == &matrix) // Если самоприсваивание.
		return *this;

	for (int i = 0; i < m_row; i++) // Очистка принимающего обьекта.
		delete[] m_p[i];
	delete[] m_p;

	// Присваивание.
	m_p = matrix.m_p;
	m_row = matrix.m_row;
	m_col = matrix.m_col;

	// Обнуление matrix.	
	matrix.m_p = nullptr;
	matrix.m_row = 0;
	matrix.m_col = 0;

	return *this;
}

// Префиксный инкремент.
Matrix& Matrix::operator++()
{
	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			m_p[i][j] ++;
		}
	}
	return *this;
}

// Постфиксный инкремент.
Matrix Matrix::operator++(int)
{
	Matrix tmp = *this;
	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			m_p[i][j] ++;
		}
	}
	return tmp;
}

// Префиксный декремент.
Matrix& Matrix::operator--()
{
	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			m_p[i][j] --;
		}
	}
	return *this;
}

// Постфиксный декремент.
Matrix Matrix::operator--(int)
{
	Matrix tmp = *this;
	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < m_col; j++)
		{
			m_p[i][j] --;
		}
	}
	return tmp;
}

// Сложение матриц.
Matrix Matrix::operator+(const Matrix& matrix) const
{
	Matrix result(matrix.m_row, matrix.m_col); // Если матрицы одинаковые, выполняем сложение.
	if (m_row == matrix.m_row && m_col == matrix.m_col)
	{
		// Копирование данных из matrix в новый массив.
		for (int i = 0; i < m_row; i++)
			for (int j = 0; j < m_col; j++)
				result.m_p[i][j] = this->m_p[i][j] + matrix.m_p[i][j];
	}
	else // Если разные, возвращаем переданную сюда матрицу.
	{
		return matrix;
	}

	return result;
}

// Умножение матриц.
Matrix Matrix::operator*(const Matrix& matrix) const
{
	Matrix result(m_row, matrix.m_col);

	if (m_col == matrix.m_row)
	{
		for (int i = 0; i < m_row; i++)
		{
			for (int j = 0; j < matrix.m_col; j++)
			{
				for (int q = 0; q < m_col; q++)
				{
					result[i][j] += m_p[i][q] * matrix.m_p[q][j];
				}
			}
		}
	}
	else // Иначе, возвращаем переданную сюда матрицу.
	{
		return matrix;
	}

	return result;
}

// Установка / получение значения элемента матрицы.
int& Matrix::operator()(int row, int col)
{
	return m_p[row][col];
}

// Перегруженный оператор индексации.
int*& Matrix::operator[](int index)
{
	return m_p[index];
}

// Перегруженный оператор <<. Печать матрицы.
ostream& operator<<(ostream& cout, Matrix& matrix)
{
	cout << endl;
	for (int i = 0; i < matrix.m_row; i++)
	{
		for (int j = 0; j < matrix.m_col; j++)
		{
			cout << matrix.m_p[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;

	return cout;
}

// Перегруженный оператор >>. Ввод данных в матрицу.
istream& operator>>(istream& cin, Matrix& matrix)
{

	//Продолжить отсюда. Начать писать эту перегрузку.
	cout << endl;
	for (int i = 0; i < matrix.m_row; i++)
	{
		for (int j = 0; j < matrix.m_col; j++)
			cin >> matrix.m_p[i][j];
	}
	cout << endl;

	return cin;
}

// Функция автоматической инициализации массива.
Matrix& Init(Matrix& matrix)
{
	int min = 10; // Минимальное значение.
	int max = 99; // Максимальное значение.
	for (int i = 0; i < matrix.m_row; i++)
	{
		for (int j = 0; j < matrix.m_col; j++)
			matrix.m_p[i][j] = rand() % (max - min + 1) + min; // Заполняет массив псевдослучайными числами.
	}
	return matrix;
}