#include <iostream>
#include "matrix.h"
#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Matrix &matrix = newMatrix();
	while (true) {

		int option;
		cout << "0 - Выход\n";
		cout << "1 - Ввод матрицы используя консоль\n";
		cout << "2 - Чтение матрицы из файла\n";
		cout << endl;
		cout << "Введите опцию: ";
		cin >> option;

		switch (option) {
		case 0:
		{
			deleteMatrix(matrix);
			exit(0);
			break;
		}
		case 1:
		{
			int edge = 0;
			cout << "Введите размерность матрицы: ";
			cin >> edge;
			cout << "Введите элементы матрицы: ";
			initMatrix(matrix, edge);
			break;
		}
		case 2:
		{
			string fileName = "";
			bool result = 0;
			cout << " Введите имя файла: ";
			cin >> fileName;
			initMatrix(matrix, fileName, result);
			if (result) {
				matrix.print();
			}
			else {
				cout << "Такого файла не существует!" << endl;
			}
			break;
		}
		default:
		{
			cout << "Неправильный ввод!" << endl;
			break;
		}

		}
		if (!matrix.isEmpty()) {
			break;
		}
	}
	while (true) {

		int option;
		cout << "0 - Выход\n";
		cout << "1 - Вывод матрицы в консоль\n";
		cout << "2 - Замена элемента в матрице\n";
		cout << "3 - Умножить на матрицу\n";
		cout << "4 - Сохранить матрицу\n";
		cout << endl;
		cout << "Введите опцию: ";
		cin >> option;
		switch (option)
		{
		case 0:
		{
			deleteMatrix(matrix);
			exit(0);
			break;
		}
		case 1:
		{
			matrix.print();
			break;

		}
		case 2:
		{
			int line, column, element;
			bool result = 0;
			cout << "Введите номер строки: ";
			cin >> line;
			cout << "Введите номер столбца: ";
			cin >> column;
			cout << "Введите элемент: ";
			cin >> element;
			matrix.changeElement(line, column, element, result);
			if (result) {
				matrix.print();
			}
			else {

				cout << "Неверный ввод!" << endl;
			}
			break;
		}
		case 3:
		{
			while (true)
			{
				int option, edge;
				cout << endl;
				cout << "Выберете как будет введена матрица, на которую будет произведено умножение:\n\n";
				cout << "1 - Ввод матрицы используя консоль\n";
				cout << "2 - Чтение матрицы из файла\n\n";
				cout << "Введите опцию: ";
				cin >> option;
				cout << endl;
				if (option == 1) {
					cout << "Введите размерность матрицы: ";
					cin >> edge;
					cout << "Введите элементы матрицы: ";
					Matrix &matrixTwo = newMatrix();
					Matrix &resultMatrix = newMatrix();

					initMatrix(matrixTwo, edge);
					matrixMultiplication(matrix, matrixTwo, resultMatrix);
					if (resultMatrix.isEmpty()) {
						cout << "Ответ неопределён!" << endl;
					}
					else
					{
						cout << "Результат:\n\n";
						resultMatrix.print();

					}

					deleteMatrix(matrixTwo);
					deleteMatrix(resultMatrix);
					break;
				}
				else {
					string fileName = "";
					bool result = 0;
					Matrix &matrixTwo = newMatrix();
					Matrix &resultMatrix = newMatrix();

					cout << "Введите имя файла: ";
					cin >> fileName;
					initMatrix(matrixTwo, fileName, result);
					if (result) {
						matrixTwo.print();
					}
					else {
						cout << "Такого файла не существует!" << endl;
					}
					/*Matrix &resultMatrix = matrix * matrixTwo;*/
					matrixMultiplication(matrix, matrixTwo, resultMatrix);

					if (resultMatrix.isEmpty()) {
						cout << "Ответ неопределён!" << endl;
					}
					else
					{
						cout << "Результат: \n";
						resultMatrix.print();
					}
					deleteMatrix(resultMatrix);
					deleteMatrix(matrixTwo);
					break;
				}
			}

			break;
		}
		case 4:
		{
			string fileName = "";
			cout << "Введите имя файла: ";
			cin >> fileName;
			matrix.saveToFile(fileName);
			//resultMatrix.saveToFile(fileName);
			break;
		}
		default:
		{
			cout << "Неправильный ввод!" << endl;
			break;
		}
		}
	}
	deleteMatrix(matrix);
	system("pause");
	return 0;
}