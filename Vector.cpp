// Better Vector Data Structure
#include <cstddef>
using std::size_t;

template <class T> struct Vector 
{
    
private:
    size_t cap = 1;         // capacity of Vector
    size_t cur = 0;         // current index to be set in the Vector
    T* arr = nullptr;       // pointer to Vector in memory

public:
    Vector()
    {
        arr = new T[cap];
    }

    Vector(size_t size)
    {
        cap = size;
        arr = new T[cap];
    }

    ~Vector()
    {
        delete[] arr;
    }

    /*
     * Doubles the size of Vector
     *
     */
    void extend()
    {
        T* newPtr = new T[cap * 2];

        for (int i = 0; i < cap; ++i)
            newPtr[i] = arr[i];
        
        delete[] arr;
        
        arr = newPtr;
        cap *= 2;
    }

    /*
     * Add a value to the Vector
     *
     */
    void append(T value)
    {
        if (cur >= cap) {expand();}

        arr[cur] = value;
        cur += 1;
    }

    /*
     * Get the value in Vector at an index
     *
     */
    T operator[](int i)
    {
        if (i < 0)
        {
            i *= -1;
            if (i >= cap)
            { 
                throw "Index out of bounds";
                return *((T*)nullptr);
            }
        }
        else
        {
            if (i >= cap) {throw "Index out of bounds";}
            else
            {
                
            }

        }
    }

    int& operator[](int i)
    {
        return a[i];
    }

    /*
     * Get a range of values from the Vector
     *
     */
    Vector<T> operator[](int start, int end)
    {

    }

};