#ifndef HEADER_FILE_NAME
#define HEADER_FILE_NAME

#include <cstddef>


template <class T> struct LLNode
{
    T          val;
    LLNode<T>* next;
    LLNode<T>* last;

    LLNode(T value);

    LLNode(T value, LLNode<T>* n);

    LLNode(T value, LLNode<T>* n, LLNode<T>* l);

};


template <class T> struct LinkedList 
{
private:

    size_t     size;
    LLNode<T>* head;

public:

    LinkedList(T node);

    LinkedList(LLNode<T> node);

    ~LinkedList();

    /*
     * Returns the size of LinkedList
     */
    size_t size() const;

    /*
     * Add a value to the end of the LinkedList
     */
    void append(T value);

    /*
     * Return wheather the LinkedList is empty or not
     */
    bool is_empty() const;

    /*
     * Return the first node of the LinkedList
     */
    T& head(int i);

    /*
     * Return the last node of the LinkedList
     */
    T& tail(int i);
};

#endif