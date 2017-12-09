#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Matrix
{
	int edge = 0;
	int *element = nullptr;
	void changeElement(int line, int column, int element, bool &result);
	void saveToFile(string fileName);
	void print();
	bool isEmpty();

};

Matrix &newMatrix()
{
	Matrix *matrix = new Matrix;
	return *matrix;
}

void initMatrix(Matrix &matrix, int edge)
{
	matrix.edge = edge;
	matrix.element = new int[edge*edge];

	for (int i = 0; i < edge; ++i) {
		for (int j = 0; j < edge; ++j) {
			cin >> matrix.element[i*edge + j];
		}
	}
}

void initMatrix(Matrix &matrix, string fileName, bool &result)
{
	int edge = 0;
	ifstream fin(fileName);

	if (fin.is_open()) {
		fin >> edge;
		matrix.edge = edge;
		matrix.element = new int[edge*edge];
		for (int i = 0; i < edge; ++i) {
			for (int j = 0; j < edge; ++j) {
				fin >> matrix.element[i*edge + j];
			}
		}
		result = true;
	}
	else {
		result = false;
	}
	fin.close();
}

void deleteMatrix(Matrix &matrix)
{
	if (matrix.element != nullptr) {
		delete[] matrix.element;
	}
	Matrix *ptr = &matrix;
	delete ptr;
}

Matrix &operator * (Matrix &matrixOne, Matrix &matrixTwo)
{
	Matrix *resultMatrix = new Matrix;
	if (matrixOne.edge == matrixTwo.edge) {
		resultMatrix->edge = matrixOne.edge;
		resultMatrix->element = new int[resultMatrix->edge*resultMatrix->edge];


		for (int i = 0; i < matrixOne.edge; ++i) {
			for (int j = 0; j < matrixTwo.edge; ++j) {
				resultMatrix->element[i*matrixOne.edge + j] = 0;
				for (int k = 0; k < matrixOne.edge; ++k) {
					resultMatrix->element[i*matrixOne.edge + j] += matrixOne.element[i*matrixOne.edge + k]*matrixTwo.element[k*matrixTwo.edge + j];
				}
			}
		}
	}
	return *resultMatrix;
}

void Matrix::changeElement(int line, int column, int element, bool &result)
{
	--line;
	--column;
	if ((line >= this->edge) || (column >= this->edge) || (column < 0) || (line < 0)) {
		result = false;
	}
	else {
		result = true;
		this->element[line*this->edge + column] = element;
	}
}

void Matrix::saveToFile(string fileName)
{
	ofstream fout(fileName);
	fout << this->edge << '\n';
	for (int i = 0; i < this->edge; ++i) {
		for (int j = 0; j < this->edge; ++j) {
			fout << this->element[i*this->edge + j] << ' ';
		}
		fout << '\n';
	}	
	fout.close();
}


void Matrix::print()
{

	for (int i = 0; i < this->edge; ++i) {
		for (int j = 0; j < this->edge; ++j) {
			cout << this->element[i*this->edge + j] << ' ';
		}
		cout << '\n';
	}
}

void matrixMultiplication(const Matrix &matrixOne, const Matrix &matrixTwo, Matrix &resultMatrix)
{
	if (matrixOne.edge == matrixTwo.edge) {
		resultMatrix.edge = matrixOne.edge;
		resultMatrix.element = new int[resultMatrix.edge*resultMatrix.edge];


		for (int i = 0; i < matrixOne.edge; ++i) {
			for (int j = 0; j < matrixTwo.edge; ++j) {
				resultMatrix.element[i*matrixOne.edge + j] = 0;
				for (int k = 0; k < matrixOne.edge; ++k) {
					resultMatrix.element[i*matrixOne.edge + j] += matrixOne.element[i*matrixOne.edge + k] * matrixTwo.element[k*matrixTwo.edge + j];
				}
			}
		}
	}
}

bool Matrix::isEmpty()
{
	return this->element == nullptr;
}