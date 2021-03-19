#ifndef LIST_HPP
#define LIST_HPP
#include <cstring>
#include <iostream>
#include <string>
#include "exceptions.hpp"

const size_t DEFAULT_CAPACITY = 5;
const size_t DEFAULT_CAPACITY_STEP = 5;

template <class T>
class List
{

    size_t capacity, length, cap_step;
    T *buffer;

public:
    List<T>(size_t cap, size_t c_step) : capacity(cap), length(0), cap_step(c_step)
    {
        buffer = new T[capacity];
    }

    List<T>(size_t cap) : List(cap, DEFAULT_CAPACITY_STEP) {}

    List<T>() : List(DEFAULT_CAPACITY) {}

    List<T>(const List &l) : capacity(l.capacity), length(l.length), cap_step(l.cap_step)
    {
        buffer = new T[capacity];
        std::memcpy(buffer, l.buffer, length * sizeof(T));
    }

    ~List<T>()
    {
        delete[] buffer;
    }

    List &operator=(List l)
    {
        capacity = l.capacity;
        length = l.length;
        std::swap(buffer, l.buffer);
        return *this;
    }
    T &operator[](size_t index)
    {

        if (index > length)
        {
            throw BadIndex(index, length);
        }
        return buffer[index];
    }

    friend std::ostream &operator<<(std::ostream &os, const List &l)
    {
        for (int i = 0; i < l.length; i++)
        {
            os << l.buffer[i] << " ";
        }
        return os;
    }

    void push(T el)
    {
        if (length == capacity)
        {
            extend();
        }
        buffer[length] = el;

        length++;
        return;
    }

    void extend()
    {
        capacity += cap_step;
        T *tempbuffer;
        tempbuffer = new T[capacity];
        std::memcpy(tempbuffer, buffer, length * sizeof(T));
        std::swap(buffer, tempbuffer);
        delete[] tempbuffer;
        std::cout << "Memory extended by " << cap_step << std::endl;
    }

    void print()
    {
        for (int i = 0; i < length; i++)
        {
            std::cout << buffer[i] << " ";
        }
        std::cout << std::endl;
    }

    int count() { return length; }
};
#endif