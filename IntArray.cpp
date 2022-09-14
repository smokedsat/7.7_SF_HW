#include "IntArray.h"
#include <iostream>




// ����������, ������������� ������
IntArray::~IntArray()
{
	delete[] m_data;
}

// ������� ��������� ������ � 
void IntArray::Erase()
{
	delete[]m_data;
	m_data = nullptr;
	m_length = 0;
}

// ����� ������ �������� �� ����� �������� ������� ������� ��� �������� ��� ��������
int& IntArray::operator[](int index)
{
	/*if ((index >= 0) && (index < m_length))
	{
		throw "Exception";
	}*/
	return m_data[index];
}

// ������� ���������� ����� �������
int IntArray::getLength() const
{
	return m_length;
};

// ������� ��������� �������� ����� �������, ������� ����� ������ ��� ��� ��������, �� ������� ��� �������� ������� ����� ����. ������� �������� ������
void IntArray::Reallocate(int newLength)
{
	if (newLength <= 0)
	{
		throw "Exception";
	}
	// ������� ������� ��� �������� � �������� ���������
	Erase();

	//�������� ������ ��� ����� ��������
	m_data = new int[newLength];
	m_length = newLength;
};

void IntArray::Resize(int newSize)
{
	if (newSize <= 0)
	{
		throw "Exception";
	}
	if (newSize == m_length)
	{
		throw "Your array is already such size";
	}

	// ��������� ������� ������� ����� ������������� �� ���� ����������� ��������� ������� � ����� ������ � ���������� ��������
	//������� ����� ������ � ����� ��������
	int* data = new int[newSize];

	//���������, ������� ��������� �� ����� ����������� � ����� ������
	if (m_length > 0)
	{
		int elementsToCopy = 0;
		if (newSize > m_length) { elementsToCopy = m_length; }
		if (newSize < m_length) { elementsToCopy = newSize; }
		//�������� ������ ������� � ����� ������
		for (int index = 0; index < elementsToCopy; ++index)
		{
			data[index] = m_data[index];
		}

		//��������� ����� �������� ������.
		for (int index = elementsToCopy; index < newSize; ++index)
		{
			data[index] = 0;
		}
	}

	// ������� ������ ������ � �������, ��� ��� �� ��� ����������� ������ ������ �� ����
	delete[] m_data;
	m_data = data;
	m_length = newSize;
}

void IntArray::InsertBefore(int value, int index)
{
	if (index > m_length)
	{
		throw "Exception";
	}
	if (index < 0)
	{
		throw "Except";
	}
	// ������� ����� ������, ������� ������, ��� �������
	int* data = new int[m_length + 1];


	// �������� ��� �������� �������� ������ ��������	
	for (int before = 0; before < index; before++)
	{
		data[before] = m_data[before];
	}

	//��������� ������� � ���������� ������
	data[index] = value;

	//�������� ��� �������� ����� ������������ ��������
	for (int after = index; after < m_length; ++after)
	{
		data[after + 1] = m_data[after];
	}

	// ������� ������� ������ � ��������� �����
	delete[]m_data;
	m_data = data;
	++m_length;
	
}

void IntArray::RemoveElement(int index)
{
	if (index > m_length)
	{
		throw "Exception";
	}
	if (index < 0)
	{
		throw "Exception";
	}

	//���� ��� ���� ������� � �������, ������ ������� ������ �������
	if (m_length == 1)
	{
		Erase();
		return;
	}

	// ������� ����� ������ �� 1 ������� ������, ��� �������
	int* data = new int[m_length - 1];

	// �������� ��� �������� ������������� 
	for (int before = 0; before < index; ++before)
	{
		data[before] = m_data[before];
	}

	// �������� ��� �������� ����� ���������� ��������
	for (int after = index; after < m_length; ++after)
	{
		data[after - 1] = m_data[after];
	}

	// ������� ������ ������ � ���������� ����� 
	delete[] m_data;
	m_data = data;
	--m_length;
	
}
void IntArray::findElementWithIndex(int index)
{
	if (index > m_length)
	{
		throw " Exception";
	}
	if (index < 0)
	{
		throw " Exception";
	}
	std::cout << m_data[index] << std::endl;
}

void IntArray::getArray()
{
	std::cout << "Array: " << std::endl;
	for (int i = 0; i < getLength(); ++i)
	{
		std::cout << m_data[i] << ' ';
	}
	std::cout << std::endl;
}

void IntArray::insertAtBeginning(int value)
{
	InsertBefore(value, 0);
}
void IntArray::insertAtEnd(int value)
{
	InsertBefore(value, m_length);
}

