#pragma once
#include <memory>

class IntArray {
private:
    int m_length{};
    std::unique_ptr<int[]> m_data;

public:
    IntArray() = default;
    IntArray(int length);
    ~IntArray();

    // Copy constructor
    IntArray(const IntArray& other);

    // Copy assignment operator
    IntArray& operator=(const IntArray& other);

    // Move constructor
    IntArray(IntArray&& other) noexcept;

    // Move assignment operator
    IntArray& operator=(IntArray&& other) noexcept;

    void Erase();
    int& operator[](int index);
    const int& operator[](int index) const; // Const version for read-only access
    int getLength() const;
    void Reallocate(int newLength);
    void Resize(int newSize);
    void InsertBefore(int value, int index);
    void RemoveElement(int index);
    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    int findElementWithIndex(int index) const; // Return the found element
    void printArray() const; // Renamed for clarity
};
