#include "IntArray.h"
#include <iostream>




// Деструктор, освобождающий память
IntArray::~IntArray()
{
	delete[] m_data;
}

// Удаляет созданный массив и 
void IntArray::Erase()
{
	delete[]m_data;
	m_data = nullptr;
	m_length = 0;
}

// Через данный оператор мы можем изменить элемент массива или получить его значение
int& IntArray::operator[](int index)
{
	/*if ((index >= 0) && (index < m_length))
	{
		throw "Exception";
	}*/
	return m_data[index];
}

// Функция возвращает длину массива
int IntArray::getLength() const
{
	return m_length;
};

// Функция позволяет изменить длину массива, выделив новую память под его элементы, но удалить все элементы массива перед этим. Функция работает быстро
void IntArray::Reallocate(int newLength)
{
	if (newLength <= 0)
	{
		throw "Exception";
	}
	// Сначала удаляем все элементы и обнуляем указатели
	Erase();

	//Выделяем память под новые элементы
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

	// Изменение размера массива будет производиться за счет копирования элементов массива в новый массив с измененным размером
	//Создаем новый массив с новым размером
	int* data = new int[newSize];

	//Вычисляем, сколько элементов мы можем скопировать в новый массив
	if (m_length > 0)
	{
		int elementsToCopy = 0;
		if (newSize > m_length) { elementsToCopy = m_length; }
		if (newSize < m_length) { elementsToCopy = newSize; }
		//Копируем каждый элемент в новый массив
		for (int index = 0; index < elementsToCopy; ++index)
		{
			data[index] = m_data[index];
		}

		//Заполняем новые элементы нулями.
		for (int index = elementsToCopy; index < newSize; ++index)
		{
			data[index] = 0;
		}
	}

	// Удаляем старый массив с данными, так как мы уже скопировали нужные данные из него
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
	// Создаем новый массив, который больше, чем прошлый
	int* data = new int[m_length + 1];


	// Копируем все элементы согласно старым индексам	
	for (int before = 0; before < index; before++)
	{
		data[before] = m_data[before];
	}

	//Добавляем элемент в выделенный массив
	data[index] = value;

	//Копируем все значения после вставленного элемента
	for (int after = index; after < m_length; ++after)
	{
		data[after + 1] = m_data[after];
	}

	// Удаляем прежний массив и заполняем новый
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

	//Если это один элемент в массиве, просто удаляем массив целиком
	if (m_length == 1)
	{
		Erase();
		return;
	}

	// Создаем новый массив на 1 элемент меньше, чем прежний
	int* data = new int[m_length - 1];

	// Копируем все элементы поиндексально 
	for (int before = 0; before < index; ++before)
	{
		data[before] = m_data[before];
	}

	// Копируем все значения после удаленного элемента
	for (int after = index; after < m_length; ++after)
	{
		data[after - 1] = m_data[after];
	}

	// Удаляем старый массив и используем новый 
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

