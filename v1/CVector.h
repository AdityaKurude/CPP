#ifndef CVECTOR_H
#define CVECTOR_H

#include <iostream>
#include <string>
#include <cassert>
#include <cstring>
//#include <vector>
#include <new>          // std::bad_alloc
#include <exception>
using namespace std;

#define DEF_CAP 5   // default capacity per template class object

template <class T>
class Vector
{
public:
    typedef T * iterator;

    //    Default parameterless constructor.
    Vector();

    //    Constructor with size as a input
    Vector(unsigned int size);

    //    copy constructor
    Vector(const Vector<T> & v);

    //    Returns the number of elements that the container has currently allocated space for.
    unsigned int capacity() const { return m_capacity; }

    //    Returns the number of elements in the container
    unsigned int size() const { return m_size; }

    //    Appends the given element value to the end of the container.
    //    1) The new element is initialized as a copy of value.
    //    2) value is moved into the new element.
    void push_back(const T & value);

    //    Removes the last element of the container.
    //    Calling pop_back on an empty container is undefined.
    void pop_back();

    //    Returns a reference to the first element in the container.
    //    Calling front on an empty container is undefined.
    T & front();

    //    Returns reference to the last element in the container.
    //    Calling back on an empty container is undefined.
    T & back();

    //    Returns a reference to the element at specified location pos. No bounds checking is performed.
    T & operator[](unsigned int index);

    //    Returns an iterator to the first element of the container.
    iterator begin() { return m_buffer; }

    //    Returns an iterator to the element following the last element of the container
    iterator end() { return (m_buffer + (m_size -1)); }

    //    Inserts elements befor the specified position in the container
    iterator insert( iterator pos, const T& value );

    //    Removes elements at specified position in the container.
    iterator erase( iterator pos );

    //    Implements quickSort
    void sort();

#ifdef DEBUG
    void print_vec() {
        for(int i = 0; i < m_size;i++)
            cout<<" index = "<<i<<" val = "<<m_buffer[i]<<endl;
    }
#endif

private:

    void swap(int a, int b);
    int partition (int low, int high);
    void quickSort(int low, int high);


    unsigned int m_size;
    unsigned int m_capacity;
    T m_buffer[DEF_CAP];
};

// Definitions of the functions

template<class T>//
Vector<T>::Vector():
    m_capacity(DEF_CAP),
    m_size(0)
{
}

template<class T>
Vector<T>::Vector(const Vector<T> & v)
{
    if (DEF_CAP <= m_size ) {
        throw std::bad_alloc();
        return;
    }

    m_size = v.m_size;
    m_capacity = v.m_capacity;
    for (int i = 0; i < m_size; i++)
        m_buffer[i] = v.m_buffer[i];
}

template<class T>
Vector<T>::Vector(unsigned int size)
{
    if (DEF_CAP < size) {
        throw std::bad_alloc();
        return;
    }
    m_capacity = (DEF_CAP - size);
    m_size = size;
}

template<class T>
void Vector<T>::push_back(const T & v)
{
    if (DEF_CAP <= m_size) {
        throw std::bad_alloc();
        return;
    }
    m_buffer [m_size++] = v;
    m_capacity = (DEF_CAP - m_size);

#ifdef DEBUG
    cout<<"push_back size"<<m_size<<endl;
#endif
}
template<class T>//
void Vector<T>::pop_back()
{
    if(0 == m_size) {
        throw std::runtime_error("Accessing invalid positions");
        return;
    }

    m_size--;
    m_capacity++;
}
template<class T>//
T& Vector<T>::front()
{
    if(0 == m_size)
        throw std::runtime_error("Accessing invalid positions");

    return m_buffer[0];
}
template<class T>//
T& Vector<T>::back()
{
    if(0 == m_size)
        throw std::runtime_error("Accessing invalid positions");

    return m_buffer[m_size - 1];
}

template<class T>//
T& Vector<T>::operator[](unsigned int index)
{
    if((index < 0) || (index == m_size))
        throw std::runtime_error("Accessing invalid positions");

    return m_buffer[index];
}

template<class T>
typename Vector<T>::iterator Vector<T>::insert(typename Vector<T>::iterator pos, const T &value)
{
    typename Vector<T>::iterator itr = m_buffer;

    // if the vector is full, no more insertion possible
    if(DEF_CAP == m_size) {
        throw std::bad_alloc();
        return itr;
    }

    int count = 0;
    while (itr != pos) {
        count++;
        itr++;
    }
    for(int index = m_size; index > count; index--) {
        m_buffer[index] = m_buffer[index -1];
    }
    m_buffer[count] = value;
    m_size++;

#ifdef DEBUG
    cout<<" final size in insert = "<<m_size<<endl;
#endif
    return itr;
}

template<class T>
typename Vector<T>::iterator Vector<T>::erase(typename Vector<T>::iterator pos)
{
    typename Vector<T>::iterator itr = m_buffer;

    if(0 == m_size) {
        throw std::runtime_error("Accessing invalid positions");
        return itr;
    }
    int count = 0;
    while (itr != pos) {
        count++;
        itr++;
    }
    // if the position to be deleted is not the last position then only move the elements
    if(DEF_CAP > m_size) {
        for(int index = count; index < m_size; index++) {
            m_buffer[index] = m_buffer[index +1];
        }
    }
    m_size--;
#ifdef DEBUG
    cout<<" final size in erase = "<<m_size<<endl;
#endif
    return itr;
}

template<class T>
void Vector<T>::sort()
{
    quickSort(0, m_size -1);
}

// A utility function to swap two elements
template<class T>
void Vector<T>:: swap(int a, int b)
{
    T temp = m_buffer[a];
    m_buffer[a] = m_buffer[b];
    m_buffer[b] = temp;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
    array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
template<class T>
int Vector<T>::partition (int low, int high)
{
    T& pivot = m_buffer[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (m_buffer[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(i, j);
        }
    }
    swap(i + 1, high);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
template<class T>
void Vector<T>::quickSort(int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

class testA {
public:
    int val;
    int val2;
    testA() {
        //        cout<<"Class testA ctor"<<endl;
    }
//    testA(const testA& temp) {
//        //        cout<<" Clss testA copy ctor"<<endl;
//        val = temp.val;
//        val2 = temp.val2;
//    }
    ~testA() {
        //        cout<<"Class testA dtor"<<endl;
    }
    bool operator <= (const testA& obj) {
        if( (val <= obj.val) && (val2 <= obj.val2))
                return true;
    return false;
    }
};

#endif
