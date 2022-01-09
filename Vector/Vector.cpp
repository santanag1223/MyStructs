#include "Vector.h"
#include <iostream>
using std::size_t;


template <class T>
    Vector<T>::Vector()
    {
        cap =  1;
        cur = -1;
        arr = new T[cap];
    }

template <class T>
    Vector<T>::Vector(size_t capacity)
    {
        cap = capacity;
        arr = new T[cap];
    }

template <class T>
    Vector<T>::~Vector()
    {
        delete[] arr;
    }

template <class T>
    size_t Vector<T>::size() const
    {
        return cur + 1;
    }

template <class T>
    size_t Vector<T>::capacity() const
    {
        return cap;
    }

template <class T>
    void Vector<T>::extend()
    {
        T* newPtr = new T[cap * 2];

        for (int i = 0; i < cap; ++i)
            newPtr[i] = arr[i];
        
        delete[] arr;
        
        arr = newPtr;
        cap *= 2;
    }

template <class T>
    void Vector<T>::append(T value)
    {
        cur += 1;
        if (cur >= cap) {extend();}

        arr[cur] = value;
    }

template <class T>
    bool Vector<T>::is_empty() const
    {
        return (cur == -1);
    }

template <class T>
    T& Vector<T>::operator[](int i) const
    {
        if (i < 0) {
            i *= -1;
            if (i > cur + 1)    {throw std::runtime_error("Index out of bounds");}

            return arr[cur - i + 1];
            }
        else {
            if (i > cur)        {throw std::runtime_error("Index out of bounds");}
            
            return arr[i];
        }
    }

template <class T>
    T& Vector<T>::front(int i) 
    {
        return arr[0];
    }

template <class T>
    T& Vector<T>::back(int i) 
    {
        return arr[cur];
    }

template <class T> 
    std::ostream& operator <<(std::ostream& out, const Vector<T>& v) {    
    if (v.is_empty()){
        out << "{}";
    }
    else {
        out << "{ ";

        for (int i = 0; i < v.size()-1; ++i)
            out << v[i] << ", ";
    
        out << v[v.size()-1] << " }";
    }

    return out;
}

int main() 
{
    Vector<int> v;
    v.append(1);
    v.append(2);
    v.append(3);
    v.append(4);
    v.append(5);
    std::cout << v << std::endl;
    try {
        std::cout << v[0] << std::endl;
        std::cout << v[1] << std::endl;
        std::cout << v[2] << std::endl;
        std::cout << v[3] << std::endl;
        std::cout << v[4] << std::endl;
        std::cout << v[-1] << std::endl;
        std::cout << v[-2] << std::endl;
        std::cout << v[-3] << std::endl;
        std::cout << v[-4] << std::endl;
        std::cout << v[-5] << std::endl;

    }
    catch (std::runtime_error e){
        std::cout << e.what() << std::endl;
    }

    v[0] = 2;
    std::cout<< v;



    return 0;
}