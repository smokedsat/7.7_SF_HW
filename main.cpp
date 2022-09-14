#include "IntArray.h"
#include <iostream>
#include <exception>
using namespace std;

int main()
{

    // Создаем массив с 10 элементами
    IntArray arr(10);

    // заполняем массив элеменами от 0 до 10
        for (int i = 0; i < 10; ++i)
        {
            arr[i] = i + 1;
        }

    // Выводим весь массив
        arr.getArray();

        // Resize the array to 8 elements

    try {
        arr.Resize(20);
    }
    catch (const char*)
    {
        cout << "Cant resize" << endl;
    }

    // Выводим весь массив
    arr.getArray();

    // Добавляем 20 перед 8 элементом
    try
    {
        arr.InsertBefore(20, 0);
    }
    catch (const char*)
    {
        cout << "Cant insert before" << endl;
    }

    // Выводим весь массив
    arr.getArray();

    // Удаляем элемент с индексом 3
    try
    {
        arr.RemoveElement(3);
    }
    catch (const char*)
    {
        cout << "Cant remove element" << endl;
    }

    // Выводим весь массив
    arr.getArray();

    // Добавляем 30 в конец 
    try
    {
        arr.insertAtEnd(30);
    }
    catch (const char*)
    {
        cout << "Cant add to the end" << endl;
    }


    // Выводим весь массив
    arr.getArray();

    // Добавляем 40 в начало
    try
    {
        arr.insertAtBeginning(40);
    }
    catch (const char*)
    {
        cout << "Cant add to the begin" << endl;
    }


    // Выводим весь массив
    arr.getArray();

    //Выполняем поиск элемента по индексу
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







