#include <iostream>
#include "Matrix.h"
using std::cout;
using std::cin;
using std::endl;

// Конструктор по умолчанию.
Matrix::Matrix()
{
	m_p = nullptr;
	m_row = 0;
	m_col = 0;
}

// Конструктор с 2 параметрами.
Matrix::Matrix(int row, int col) // Проверено.
{
	m_row = row;
	m_col = col;
	m_p = new int* [m_row];
	for (int i = 0; i < m_row; i++)
		m_p[i] = new int[m_col];
}

//Конструктор копирования.
Matrix::Matrix(const Matrix& matrix) // Проверено.
{
	m_row = matrix.m_row;
	m_col = matrix.m_col;
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
Matrix::Matrix(Matrix&& matrix) // Проверено.
{
	// Присваивание.
	m_p = matrix.m_p;
	m_row = matrix.m_row;
	m_col = matrix.m_col;

	// Обнуление matrix.	
	matrix.m_p = nullptr;
	matrix.m_row = 0;
	matrix.m_col = 0;
}

// Деструктор.
Matrix::~Matrix() // Проверено.
{
	for (int i = 0; i < m_row; i++)
		delete[] m_p[i];
	delete[] m_p;
}

// Перегруженный оператор присваивания с копированием.
Matrix& Matrix::operator=(const Matrix& matrix) // Проверено.
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
Matrix& Matrix::operator=(Matrix&& matrix) // Проверено.
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

// Сложение матриц.
Matrix Matrix::operator+(const Matrix& matrix) const // Проверено.
{
	Matrix result(matrix.m_row, matrix.m_col); // Если матрицы одинаковые, выполняем сложение.
	if (m_row == matrix.m_row && m_col == matrix.m_col)
	{
		// Копирование данных из matrix в новый массив.
		for (int i = 0; i < m_row; i++)
		{
			for (int j = 0; j < m_col; j++)
			{
				result.m_p[i][j] = this->m_p[i][j] + matrix.m_p[i][j];
			}
		}
	}
	else // Если разные, возвращаем переданную сюда матрицу.
	{
		return matrix;
	}

	return result;
}

// Умножение матриц.
Matrix Matrix::operator*(const Matrix& matrix) const // Проверено.
{
	Matrix result(matrix.m_row, matrix.m_col); // Если матрицы одинаковые, выполняем сложение.
	if (m_row == matrix.m_row && m_col == matrix.m_col)
	{
		// Копирование данных из matrix в новый массив.
		for (int i = 0; i < m_row; i++)
		{
			for (int j = 0; j < m_col; j++)
			{
				result.m_p[i][j] = this->m_p[i][j] * matrix.m_p[i][j];
			}
		}
	}
	else // Если разные, возвращаем переданную сюда матрицу.
	{
		return matrix;
	}

	return result;
}

// Перегруженный оператор <<. Печать матрицы.
ostream& operator<<(ostream& cout, Matrix& matrix) // Проверено.
{
	cout << endl;
	for (int i = 0; i < p.m_row; i++)
	{
		for (int j = 0; j < p.m_col; j++)
		{
			cout << p.m_p[i][j] << '\t';
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

	/*cout << endl;
	v.Clear();
	for (int i = 0; i < v.m_size; i++)
	{
		cout << "vector[" << i << "] = ";
		cin >> v.m_vect[i];
	}
	return cin;*/
}

// Функция автоматической инициализации массива.
Matrix& Init(Matrix& matrix) // Проверено.
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