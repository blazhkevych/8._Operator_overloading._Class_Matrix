﻿/*
############################################ ЗАДАНИЕ ###########################################
	Класс «Матрица»
################################################################################################
		СТАТУС : Готово.
		ДОРАБОТКИ:
*
		ИЗВЕСТНЫЕ ОШИБКИ:
*
		ПРОТЕСТИРОВАТЬ:
*
		ВОПРОСЫ:
*
		ВИДЕО: 02:37:15 (начало дз)
################################################################################################
*/
#include <iostream>
#include "Matrix.h"
using std::cout;
using std::cin;
using std::endl;

Matrix f2()
{
	Matrix obj4(3, 3);
	Init(obj4);
	cout << "\n\t\t\tMatrix f2() returned obj4 :";
	cout << obj4;
	return obj4;
}

int main()
{
	srand(time(0));

	// Конструктор по умолчанию.
	Matrix m0;

	// Конструктор с 2 параметрами.
	Matrix m1(3, 3);
	Init(m1);
	cout << "\t\t\tm1:";
	cout << m1;

	// Конструктор с 2 параметрами.
	Matrix m2(3, 3);
	Init(m2);
	cout << "\t\t\tm2:";
	cout << m2;

	//Конструктор копирования.
	Matrix m3 = m1;
	cout << "\t\t\tMatrix m3 = m1;";
	cout << m3;

	// Реализация семантики переноса с использованием r-value ссылок.
	// Конструктор переноса.
	// Сложение матриц.
	Matrix m4 = m1 + m2; // Конструктор переноса.
	cout << "\t\t\tMatrix m4 = m1 + m2;";
	cout << m4;

	// Перегруженный оператор присваивания с копированием.
	Matrix m5(3, 3);
	Init(m5);
	cout << "\t\t\tm5:";
	cout << m5;
	cout << "\t\t\tm5 = m4;";
	m5 = m4; // Присваивание с копированием.
	cout << m5;

	// Перегруженный оператор присваивания с переносом.
	Matrix m6(3, 3);
	cout << "\t\t\tm6 = m2 = f2();";
	m6 = m2 = f2(); // Присваивание с переносом.
	cout << "\t\t\tm6:";
	cout << m6;

	// Умножение матриц.
	Matrix m7(3, 3);
	Init(m7);
	cout << "\t\t\tm7:";
	cout << m7;
	Matrix m8(3, 3);
	Init(m8);
	cout << "\t\t\tm8:";
	cout << m8;
	Matrix m9(3, 3);
	Init(m9);
	cout << "\t\t\tm9:";
	cout << m9;
	cout << "\t\t\tm9 = m7 * m8;";
	m9 = m7 * m8;
	cout << m9;

	// Префиксный инкремент.
	Matrix m11(3, 3);
	Init(m11);
	cout << "\t\t\tm11:";
	cout << m11;
	cout << "\t\t\t++m11;";
	++m11;
	cout << m11;

	// Постфиксный инкремент.
	Matrix m12(3, 3);
	Init(m12);
	cout << "\t\t\tm12:";
	cout << m12;
	cout << "\t\t\tm12++;";
	m12++;
	cout << m12;

	// Префиксный декремент.
	Matrix m13(3, 3);
	Init(m13);
	cout << "\t\t\tm13:";
	cout << m13;
	cout << "\t\t\t--m13;";
	--m13;
	cout << m13;

	// Постфиксный декремент.
	Matrix m14(3, 3);
	Init(m14);
	cout << "\t\t\tm14:";
	cout << m14;
	cout << "\t\t\tm14--;";
	m14--;
	cout << m14;

	// Установка / получение значения элемента матрицы.
	Matrix m15(3, 3);
	Init(m15);
	cout << "\t\t\tm15:";
	cout << m15;
	cout << "\t\t\tm15(1, 2) = 999;";
	m15(1, 2) = 999;
	cout << m15;

	// Перегруженный оператор <<. Печать матрицы.
	// Перегруженный оператор >>. Ввод данных в матрицу.	
	Matrix m10(3, 3);
	cout << "\t\t\tEnter m10:";
	cin >> m10;
	cout << "\t\t\tm10:";
	cout << m10;
}