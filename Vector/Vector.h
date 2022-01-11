#ifndef HEADER_FILE_NAME
#define HEADER_FILE_NAME

#include <cstddef>


template <class T> struct Vector 
{
private:

    size_t cap;             // capacity of Vector
    size_t cur;             // current index to be set in the Vector
    T*     arr;             // pointer to Vector in memory

public:

    Vector();

    Vector(size_t capacity);

    ~Vector();

    /*
     * Returns the size of Vector
     */
    size_t size() const;

    /*
     * Returns the capacity of Vector
     */
    size_t capacity() const;

    /*
     * Doubles the size of Vector
     */
    void extend();

    /*
     * Add a value to the Vector
     */
    void append(T value);

    /*
     * Returns wheather the vector is empty or not
     */
    bool is_empty() const;

    /*
     * Get the value in Vector at an index
     */
    T& operator[](int i) const;

    /*
     * Get the value at the beginning of the vector
     */
    T& front(int i);

    /*
     * Get the value at the end of the vector
     */
    T& back(int i);
};

#endif