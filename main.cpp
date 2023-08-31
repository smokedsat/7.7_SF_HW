#include "IntArray.h"  // Including the class header file
#include <iostream>

int main() {
    try {
        // Creating an instance of the IntArray class with an initial length of 10
        IntArray arr(10);

        // Filling the array with values from 1 to 10
        for (int i = 0; i < 10; ++i) {
            arr[i] = i + 1;
        }

        // Printing the contents of the array
        arr.printArray();

        // Resizing the array to 20 elements
        arr.Resize(20);

        // Printing the contents of the array after resizing
        arr.printArray();

        // Inserting the number 20 at the beginning
        arr.insertAtBeginning(20);

        // Printing the contents of the array after insertion
        arr.printArray();

        // Removing the element at index 3
        arr.RemoveElement(3);

        // Printing the contents of the array after removal
        arr.printArray();

        // Inserting the number 30 at the end of the array
        arr.insertAtEnd(30);

        // Printing the contents of the array after inserting at the end
        arr.printArray();

        // Inserting the number 40 at the beginning of the array
        arr.insertAtBeginning(40);

        // Printing the contents of the array after inserting at the beginning
        arr.printArray();

        // Finding and printing the element at index 5
        int elementAtIndex5 = arr.findElementWithIndex(5);
        std::cout << "Element with index 5: " << elementAtIndex5 << std::endl;
    }
    catch (const std::exception& e) {
        // Handling any exceptions that might occur
        std::cerr << "There is an error: " << e.what() << std::endl;
    }

    return 0;
}







