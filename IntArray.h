#pragma once

class IntArray 
{
private:
	int m_length{};
	int* m_data{};

public:
	IntArray() = default;
	// �����������, ���������� � ���� ����� �����(����� �������)
	IntArray(int length) : m_length(length)
	{
		/*// ���������� ��� ����� ������� <=0
		if (length <= 0)
		{
			throw "Exception in the constructor";
		}*/
		// ���������� ����� ������� ����� length
		m_data = new int [length] {};
	};

	~IntArray();
	void Erase();
	int& operator[](int index);
	int getLength() const;
	void Reallocate(int newLength);
	void Resize(int newSize);
	void InsertBefore(int value, int index);
	void RemoveElement(int index);
	void insertAtBeginning(int value);
	void insertAtEnd(int value);
	void findElementWithIndex(int index);
	void getArray();
};
