#pragma once
#include <string>

struct Matrix
{
	//Замена элемента
	void changeElement(int line, int column, int element, bool &result);

	//Проверка пустосты матрицы
	bool isEmpty();

	//Сохранение матрицы в файл 
	void saveToFile(std::string fileName);

	//Вывод матрицы в консоль 
	void print();

};

//Объявление матрицы 
Matrix &newMatrix();

// Инициализация матрицы (Консольный ввод)
void initMatrix(Matrix &matrix, int edge);

// Инициализация матрицы (Файловый ввод)
void initMatrix(Matrix &matrix, std::string fileName, bool &result);

//Умножениие матриц 
void matrixMultiplication(const Matrix &matrixOne, const Matrix &matrixTwo, Matrix &resultMatrix);

//Умножение матриц
Matrix &operator * (Matrix &matrixOne, Matrix &matrixTwo);

//Зачистка матрицы
void deleteMatrix(Matrix &matrix);
