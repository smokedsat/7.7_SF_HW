#include "IntArray.h"
#include <iostream>
#include <memory>
#include <stdexcept>
#include <algorithm>

IntArray::IntArray(IntArray&& other) noexcept
    : m_length(other.m_length), m_data(std::move(other.m_data)) {
    other.m_length = 0;
}

IntArray& IntArray::operator=(IntArray&& other) noexcept {
    if (this != &other) {
        m_length = other.m_length;
        m_data = std::move(other.m_data);
        other.m_length = 0;
    }
    return *this;
}

IntArray::IntArray(int length) : m_length(length) {
    if (length <= 0) {
        throw std::invalid_argument("Length must be positive");
    }
    m_data = std::make_unique<int[]>(m_length);
}

IntArray::~IntArray() {}

void IntArray::Erase() {
    m_data.reset();
    m_length = 0;
}

int& IntArray::operator[](int index) {
    if (index < 0 || index >= m_length) {
        throw std::out_of_range("Index out of bounds");
    }
    return m_data[index];
}

int IntArray::getLength() const {
    return m_length;
}

void IntArray::Reallocate(int newLength) {
    if (newLength <= 0) {
        throw std::invalid_argument("Incorrect length in reallocating");
    }
    m_data = std::make_unique<int[]>(newLength);
    m_length = newLength;
}

void IntArray::Resize(int newSize) {
    if (newSize <= 0) {
        throw std::invalid_argument("Incorrect size. It must be greater than 0.");
    }
    if (newSize == m_length) {
        throw std::invalid_argument("Your array is already that size");
    }
    auto newData = std::make_unique<int[]>(newSize);
    const int elementsToCopy = std::min(m_length, newSize);
    std::copy(m_data.get(), m_data.get() + elementsToCopy, newData.get());
    m_data = std::move(newData);
    m_length = newSize;
}

void IntArray::InsertBefore(int value, int index) {
    if (index < 0 || index > m_length) {
        throw std::out_of_range("Invalid index for insertion");
    }
    auto newData = std::make_unique<int[]>(m_length + 1);
    std::copy(m_data.get(), m_data.get() + index, newData.get());
    newData[index] = value;
    std::copy(m_data.get() + index, m_data.get() + m_length, newData.get() + index + 1);
    m_data = std::move(newData);
    ++m_length;
}

void IntArray::RemoveElement(int index) {
    if (index < 0 || index >= m_length) {
        throw std::out_of_range("Invalid index for removal");
    }
    if (m_length == 1) {
        Erase();
        return;
    }
    auto newData = std::make_unique<int[]>(m_length - 1);
    std::copy(m_data.get(), m_data.get() + index, newData.get());
    std::copy(m_data.get() + index + 1, m_data.get() + m_length, newData.get() + index);
    m_data = std::move(newData);
    --m_length;
}


// Example implementation for the new methods:
int IntArray::findElementWithIndex(int index) const {
    if (index < 0 || index >= m_length) {
        throw std::out_of_range("Index out of bounds");
    }
    return m_data[index];
}

void IntArray::printArray() const {
    std::cout << "Array:" << std::endl;
    for (int i = 0; i < getLength(); ++i) {
        std::cout << m_data[i] << ' ';
    }
    std::cout << std::endl;
}

void IntArray::insertAtBeginning(int value) {
    InsertBefore(value, 0);
}

void IntArray::insertAtEnd(int value) {
    InsertBefore(value, m_length);
}
