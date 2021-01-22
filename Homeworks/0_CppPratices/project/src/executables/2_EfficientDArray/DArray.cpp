// implementation of class DArray
#include "DArray.h"
#include <iostream>
using namespace std;

// default constructor
DArray::DArray() {
	Init();
}

// set an array with default values
DArray::DArray(int nSize, double dValue) {
	Init();
	this->Reserve(nSize);
	m_nSize = nSize;
	memset(m_pData, dValue, sizeof(double) * m_nSize);
}

DArray::DArray(const DArray& arr) {
	Init();
	this->Reserve(arr.GetSize());
	m_nSize = arr.GetSize();
	memcpy(m_pData, arr.m_pData, sizeof(double) * m_nSize);
}

// deconstructor
DArray::~DArray() {
	Free();
}

// display the elements of the array
void DArray::Print() const {
	cout << "size = " << m_nSize << ": ";
	for (int i = 0; i < m_nSize; i++) {
		cout << m_pData[i] << ' ';
	}
	cout << endl;
}

// initilize the array
void DArray::Init() {
	m_nSize = 0;
	m_pData = nullptr;
	m_nMax = 0;
}

// free the array
void DArray::Free() {
	delete[] m_pData;
	m_pData = nullptr;
	m_nSize = 0;
	m_nMax = 0;
}

// get the size of the array
int DArray::GetSize() const {
	return m_nSize; // you should return a correct value
}

// set the size of the array
void DArray::SetSize(int nSize) {
	if (nSize < 0) {
		cout << "error" << endl;
		exit(0);
	}
	if (nSize > m_nMax) {
		this->Reserve(nSize);
	}
	memset(m_pData + m_nSize, 0, sizeof(double) * (m_nMax - m_nSize));
	m_nSize = nSize;
}

// get an element at an index
const double& DArray::GetAt(int nIndex) const {
	if (nIndex >= m_nSize || nIndex < 0) {
		cout << "index error" << endl;
		exit(0);
	}
	return m_pData[nIndex]; // you should return a correct value
}

// set the value of an element 
void DArray::SetAt(int nIndex, double dValue) {
	if (nIndex >= m_nSize || nIndex < 0) {
		cout << "index error" << endl;
		exit(0);
	}
	m_pData[nIndex] = dValue;
}

// overload operator '[]'
const double& DArray::operator[](int nIndex) const {
	if (nIndex >= m_nSize || nIndex < 0) {
		cout << "index error" << endl;
		exit(0);
	}
	return m_pData[nIndex];
}

// add a new element at the end of the array
void DArray::PushBack(double dValue) {
	if (m_nSize >= m_nMax) {
		this->Reserve(m_nSize + 1);
	}
	m_pData[m_nSize] = dValue;
	m_nSize++;
}

// delete an element at some index
void DArray::DeleteAt(int nIndex) {
	if (nIndex >= m_nSize || nIndex < 0) {
		cout << "index error" << endl;
		exit(0);
	}
	for (int i = nIndex; i < m_nSize - 1; i++) {
		m_pData[i] = m_pData[i + 1];
	}
	m_nSize--;
}

// insert a new element at some index
void DArray::InsertAt(int nIndex, double dValue) {
	if (nIndex > m_nSize || nIndex < 0) {
		cout << "index error" << endl;
		exit(0);
	}
	if (m_nSize >= m_nMax) {
		this->Reserve(m_nSize + 1);
	}
	for (int i = m_nSize; i > nIndex; i--) {
		m_pData[i] = m_pData[i - 1];
	}
	m_pData[nIndex] = dValue;
	m_nSize++;
}

// overload operator '='
DArray& DArray::operator = (const DArray& arr) {
	this->Reserve(arr.GetSize());
	m_nSize = arr.GetSize();
	m_pData = new double[m_nSize];
	memcpy(m_pData, arr.m_pData, sizeof(double) * m_nSize);
	return *this;
}

void DArray::Reserve(int nSize) {
	if (nSize < 0) {
		cout << "size error" << endl;
		exit(0);
	}
	int shift_count = 0;
	while (nSize) {
		shift_count++;
		nSize >>= 1;
	};
	m_nMax = 1 << shift_count;
	double* temp = new double[m_nMax];
	memcpy(temp, m_pData, m_nSize * sizeof(double));
	delete[] m_pData;
	m_pData = temp;
}