#include "IntArray.h"
#include <iostream>
#include <exception>
using namespace std;

int main()
{

    // ������� ������ � 10 ����������
    IntArray arr(10);

    // ��������� ������ ��������� �� 0 �� 10
        for (int i = 0; i < 10; ++i)
        {
            arr[i] = i + 1;
        }

    // ������� ���� ������
        arr.getArray();

        // Resize the array to 8 elements

    try {
        arr.Resize(20);
    }
    catch (const char*)
    {
        cout << "Cant resize" << endl;
    }

    // ������� ���� ������
    arr.getArray();

    // ��������� 20 ����� 8 ���������
    try
    {
        arr.InsertBefore(20, 0);
    }
    catch (const char*)
    {
        cout << "Cant insert before" << endl;
    }

    // ������� ���� ������
    arr.getArray();

    // ������� ������� � �������� 3
    try
    {
        arr.RemoveElement(3);
    }
    catch (const char*)
    {
        cout << "Cant remove element" << endl;
    }

    // ������� ���� ������
    arr.getArray();

    // ��������� 30 � ����� 
    try
    {
        arr.insertAtEnd(30);
    }
    catch (const char*)
    {
        cout << "Cant add to the end" << endl;
    }


    // ������� ���� ������
    arr.getArray();

    // ��������� 40 � ������
    try
    {
        arr.insertAtBeginning(40);
    }
    catch (const char*)
    {
        cout << "Cant add to the begin" << endl;
    }


    // ������� ���� ������
    arr.getArray();

    //��������� ����� �������� �� �������
    try
    {
        arr.findElementWithIndex(5);
    }
    catch (const char*)
    {
        cout << "Cant find element with that index" << endl;
    }
    return 0;



}







