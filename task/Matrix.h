#pragma once
#include <ostream>
using std::ostream;
using std::istream;

class Matrix
{
	// Указатель на двумерный динамический массив.
	int** m_p;
	// Количество строк, количество столбцов.
	int m_row, m_col;
public:
	Matrix();								// Конструктор по умолчанию.
	Matrix(int row, int col);				// Конструктор с 2 параметрами.
	Matrix(const Matrix& matrix);			// Конструктор копирования.
	Matrix(Matrix&& matrix);						// Конструктор переноса.
	~Matrix();								// Деструктор.
	Matrix& operator = (const Matrix& matrix);		// Перегруженный оператор присваивания с копированием.
	Matrix& operator = (Matrix&& matrix);			// Перегруженный оператор присваивания с переносом.

	//// Увеличение на 1 каждого элемента матрицы:
	//Matrix& operator ++();					// Префиксный инкремент.
	//Matrix operator ++(int);				// Постфиксный инкремент.

	//// Уменьшение на 1 каждого элемента матрицы:
	//Matrix& operator --();					// Префиксный декремент.
	//Matrix operator --(int);				// Постфиксный декремент.
	Matrix operator+(const Matrix& matrix) const;	// Сложение матриц.
	Matrix operator*(const Matrix& matrix) const;	// Умножение матриц.
	//int& operator()(int, int);				// Установка / получение значения элемента матрицы.

	friend ostream& operator << (ostream& cout, Matrix& matrix); // Перегруженный оператор <<. Печать матрицы.
	friend istream& operator >> (istream& cin, Matrix& matrix); // Перегруженный оператор >>. Ввод данных в матрицу.

	// Функция автоматической инициализации массива.
	friend Matrix& Init(Matrix& matrix);
};

// Функция автоматической инициализации массива.
Matrix& Init(Matrix& matrix);