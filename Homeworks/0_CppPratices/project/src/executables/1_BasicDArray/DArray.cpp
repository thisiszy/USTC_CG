// implementation of class DArray
#include "DArray.h"
#include <iostream>

// default constructor
DArray::DArray() {
	Init();
}

// set an array with default values
DArray::DArray(int nSize, double dValue) {
	m_nSize = nSize;
	m_pData = new double[m_nSize];
	while (nSize--) {
		m_pData[nSize] = dValue;
	}
}

DArray::DArray(const DArray& arr) {
	m_nSize = arr.GetSize();
	m_pData = new double[m_nSize];
	memcpy(m_pData, arr.m_pData, sizeof(double) * m_nSize);
}

// deconstructor
DArray::~DArray() {
	Free();
}

// display the elements of the array
void DArray::Print() const {
	std::cout << "size = " << m_nSize << ": ";
	for (int i = 0; i < m_nSize; i++) {
		std::cout << m_pData[i] << ' ';
	}
	std::cout << std::endl;
}

// initilize the array
void DArray::Init() {
	m_nSize = 0;
	m_pData = NULL;
}

// free the array
void DArray::Free() {
	if (m_pData != NULL) {
		delete[] m_pData;
		m_pData = NULL;
	}
	m_nSize = 0;
}

// get the size of the array
int DArray::GetSize() const {
	return m_nSize; // you should return a correct value
}

// set the size of the array
void DArray::SetSize(int nSize) {
	if (nSize < 0) {
		std::cout << "error" << std::endl;
		exit(0);
	}
	double* temp = new double[nSize]();
	if (nSize > m_nSize) {
		memcpy(temp, m_pData, sizeof(double) * m_nSize);
	}
	else {
		memcpy(temp, m_pData, sizeof(double) * nSize);
	}
	this->Free();
	m_nSize = nSize;
	m_pData = temp;
}

// get an element at an index
const double& DArray::GetAt(int nIndex) const {
	if (nIndex >= m_nSize || nIndex < 0) {
		std::cout << "index error" << std::endl;
		exit(0);
	}
	return m_pData[nIndex]; // you should return a correct value
}

// set the value of an element 
void DArray::SetAt(int nIndex, double dValue) {
	if (nIndex >= m_nSize || nIndex < 0) {
		std::cout << "index error" << std::endl;
		exit(0);
	}
	m_pData[nIndex] = dValue;
}

// overload operator '[]'
const double& DArray::operator[](int nIndex) const {
	if (nIndex >= m_nSize || nIndex < 0) {
		std::cout << "index error" << std::endl;
		exit(0);
	}
	return m_pData[nIndex];
}

// add a new element at the end of the array
void DArray::PushBack(double dValue) {
	double* temp = new double[m_nSize + 1];
	memcpy(temp, m_pData, sizeof(double) * m_nSize);
	temp[m_nSize] = dValue;
	if (m_pData != NULL) delete[] m_pData;
	m_pData = temp;
	m_nSize++;
}

// delete an element at some index
void DArray::DeleteAt(int nIndex) {
	if (nIndex >= m_nSize || nIndex < 0) {
		std::cout << "index error" << std::endl;
		exit(0);
	}
	double* temp = new double[m_nSize - 1];
	memcpy(temp, m_pData, sizeof(double)* nIndex);
	memcpy(temp + nIndex, m_pData + nIndex + 1, sizeof(double)* (m_nSize - nIndex - 1));
	if (m_pData != NULL) delete[] m_pData;
	m_pData = temp;
	m_nSize--;
}

// insert a new element at some index
void DArray::InsertAt(int nIndex, double dValue) {
	if (nIndex > m_nSize || nIndex < 0) {
		std::cout << "index error" << std::endl;
		exit(0);
	}
	double* temp = new double[m_nSize + 1];
	memcpy(temp, m_pData, sizeof(double) * nIndex);
	memcpy(temp + nIndex + 1, m_pData + nIndex, sizeof(double) * (m_nSize - nIndex));
	temp[nIndex] = dValue;
	if (m_pData) delete[] m_pData;
	m_pData = temp;
	m_nSize++;
}

// overload operator '='
DArray& DArray::operator = (const DArray& arr) {
	m_nSize = arr.GetSize();
	m_pData = new double[m_nSize];
	memcpy(m_pData, arr.m_pData, sizeof(double) * m_nSize);
	return *this;
}
