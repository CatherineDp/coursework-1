#pragma once
#include <string>

struct Matrix
{
	//������ ��������
	void changeElement(int line, int column, int element, bool &result);

	//�������� �������� �������
	bool isEmpty();

	//���������� ������� � ���� 
	void saveToFile(std::string fileName);

	//����� ������� � ������� 
	void print();

};

//���������� ������� 
Matrix &newMatrix();

// ������������� ������� (���������� ����)
void initMatrix(Matrix &matrix, int edge);

// ������������� ������� (�������� ����)
void initMatrix(Matrix &matrix, std::string fileName, bool &result);

//���������� ������ 
void matrixMultiplication(const Matrix &matrixOne, const Matrix &matrixTwo, Matrix &resultMatrix);

//��������� ������
Matrix &operator * (Matrix &matrixOne, Matrix &matrixTwo);

//�������� �������
void deleteMatrix(Matrix &matrix);
