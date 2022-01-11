#ifndef HEADER_FILE_NAME
#define HEADER_FILE_NAME

#include <cstddef>
using std::size_t;


template <class T> struct LLNode
{
    T          val;
    LLNode<T>* next;
    LLNode<T>* prev;

    LLNode(T value);

    LLNode(T value, LLNode<T>* n);

    LLNode(T value, LLNode<T>* n, LLNode<T>* p);

};


template <class T> struct LinkedList 
{
private:

    size_t     size;
    LLNode<T>* head;

public:

    LinkedList();

    LinkedList(LLNode<T>* node);

    ~LinkedList();

    /*
     * Returns the size of LinkedList
     */
    size_t length() const;

    /*
     * Add a value to the end of the LinkedList
     */
    void append(T value);

    /*
     * Add a value to the front of the LinkedList
     */
    void append_front(T value);

    /*
     * Insert a value after the index in the LinkedList
     */
    void insert_after(T value, size_t index);

    /*
     * Return wheather the LinkedList is empty or not
     */
    bool is_empty() const;

    /*
     * Return the first node of the LinkedList
     */
    T& head_value();

    /*
     * Return the first node of the LinkedList
     */
    LLNode<T>* head_node() const;

    /*
     * Return the last node of the LinkedList
     */
    T& tail_value();

    /*
     * Return the last node of the LinkedList
     */
    LLNode<T>* tail_node() const;
};

#endif