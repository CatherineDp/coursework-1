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
		cout << "0 - �����\n";
		cout << "1 - ���� ������� ��������� �������\n";
		cout << "2 - ������ ������� �� �����\n";
		cout << endl;
		cout << "������� �����: ";
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
			cout << "������� ����������� �������: ";
			cin >> edge;
			cout << "������� �������� �������: ";
			initMatrix(matrix, edge);
			break;
		}
		case 2:
		{
			string fileName = "";
			bool result = 0;
			cout << " ������� ��� �����: ";
			cin >> fileName;
			initMatrix(matrix, fileName, result);
			if (result) {
				matrix.print();
			}
			else {
				cout << "������ ����� �� ����������!" << endl;
			}
			break;
		}
		default:
		{
			cout << "������������ ����!" << endl;
			break;
		}

		}
		if (!matrix.isEmpty()) {
			break;
		}
	}
	while (true) {

		int option;
		cout << "0 - �����\n";
		cout << "1 - ����� ������� � �������\n";
		cout << "2 - ������ �������� � �������\n";
		cout << "3 - �������� �� �������\n";
		cout << "4 - ��������� �������\n";
		cout << endl;
		cout << "������� �����: ";
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
			cout << "������� ����� ������: ";
			cin >> line;
			cout << "������� ����� �������: ";
			cin >> column;
			cout << "������� �������: ";
			cin >> element;
			matrix.changeElement(line, column, element, result);
			if (result) {
				matrix.print();
			}
			else {

				cout << "�������� ����!" << endl;
			}
			break;
		}
		case 3:
		{
			while (true)
			{
				int option, edge;
				cout << endl;
				cout << "�������� ��� ����� ������� �������, �� ������� ����� ����������� ���������:\n\n";
				cout << "1 - ���� ������� ��������� �������\n";
				cout << "2 - ������ ������� �� �����\n\n";
				cout << "������� �����: ";
				cin >> option;
				cout << endl;
				if (option == 1) {
					cout << "������� ����������� �������: ";
					cin >> edge;
					cout << "������� �������� �������: ";
					Matrix &matrixTwo = newMatrix();
					Matrix &resultMatrix = newMatrix();

					initMatrix(matrixTwo, edge);
					matrixMultiplication(matrix, matrixTwo, resultMatrix);
					if (resultMatrix.isEmpty()) {
						cout << "����� ����������!" << endl;
					}
					else
					{
						cout << "���������:\n\n";
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

					cout << "������� ��� �����: ";
					cin >> fileName;
					initMatrix(matrixTwo, fileName, result);
					if (result) {
						matrixTwo.print();
					}
					else {
						cout << "������ ����� �� ����������!" << endl;
					}
					/*Matrix &resultMatrix = matrix * matrixTwo;*/
					matrixMultiplication(matrix, matrixTwo, resultMatrix);

					if (resultMatrix.isEmpty()) {
						cout << "����� ����������!" << endl;
					}
					else
					{
						cout << "���������: \n";
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
			cout << "������� ��� �����: ";
			cin >> fileName;
			matrix.saveToFile(fileName);
			//resultMatrix.saveToFile(fileName);
			break;
		}
		default:
		{
			cout << "������������ ����!" << endl;
			break;
		}
		}
	}
	deleteMatrix(matrix);
	system("pause");
	return 0;
}