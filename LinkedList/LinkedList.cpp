#include "LinkedList.h"
#include <iostream>

// LLNode Function Definitions

template <class T>
    LLNode<T>::LLNode(T value)
    {
        val  = value;
        next = nullptr;
        last = nullptr;
    }

template <class T>
    LLNode<T>::LLNode(T value, LLNode<T>* n)
    {
        val  = value;
        next = next;
        last = nullptr;
    }
    
template <class T>
    LLNode<T>::LLNode(T value, LLNode<T>* n, LLNode<T>* l)
    {
        val  = value;
        next = next;
        last = last;
    }

// LinkedList Function Definitions

template <class T>
    LinkedList<T>::LinkedList(T value)
    {
        size = 1;
        head = new LLNode(value);
    }

template <class T>
    LinkedList<T>::LinkedList(LLNode<T> node)
    {
        size = 1;
        head = node;
    }