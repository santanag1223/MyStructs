#include "LinkedList.h"
#include <iostream>
using std::size_t;


// LLNode Function Definitions

template <class T>
    LLNode<T>::LLNode(T value)
    {
        val  = value;
        next = nullptr;
        prev = nullptr;
    }

template <class T>
    LLNode<T>::LLNode(T value, LLNode<T>* n)
    {
        val  = value;
        next = n;
        prev = nullptr;
    }
    
template <class T>
    LLNode<T>::LLNode(T value, LLNode<T>* n, LLNode<T>* p)
    {
        val  = value;
        next = n;
        prev = p;
    }

// LinkedList Function Definitions

template <class T>
    LinkedList<T>::LinkedList()
    {
        size = 0;
        head = nullptr;
    }

template <class T>
    LinkedList<T>::LinkedList(LLNode<T>* node)
    {
        size = 1;
        head = node;

        while (node->next != nullptr)
            ++size;
            node = node->next;
    }

template <class T>
    LinkedList<T>::~LinkedList()
    {
        LLNode<T>* curr = head;
        LLNode<T>* temp;

        while (curr->next != nullptr)
            temp = curr;
            curr = curr->next;
            delete temp;
        delete curr;
    }

template <class T>
    size_t LinkedList<T>::length() const
    {
        return size;
    }

template <class T>
    void LinkedList<T>::append(T value) 
    {
        LLNode<T>* newNode = new LLNode<T>(value);

        if (head == nullptr) {
            head = newNode;
            ++size;
        }
        else {

        LLNode<T>* curr = head;

        while (curr->next != nullptr)
            curr = curr->next;

        curr->next = newNode;
        newNode->prev = curr;
        head->prev = newNode;
        ++size;
        }
    }

template <class T>
    void LinkedList<T>::append_front(T value) 
    {
        LLNode<T>* newNode = new LLNode<T>(value, head, head->prev);
        head->prev = newNode;
        head = newNode;
        ++size;
    }

template <class T>
    void LinkedList<T>::insert_after(T value, size_t index) 
    {
        if (index >= size) {throw std::runtime_error("Invalid Index");}
        
        LLNode<T>* curr = head;
        for (int i = 0; i < index; ++i)
            curr = curr->next;

        LLNode<T>* newNode = new LLNode<T>(value, curr->next, curr);
        curr->next = newNode;
        ++size;
    }

template <class T>
    bool LinkedList<T>::is_empty() const
    {
        return (size == 0);
    }

template <class T>
    T& LinkedList<T>::head_value()
    {
        if (head == nullptr) {throw std::runtime_error("The LinkedList is empty.");}
        return head->val;
    }

template <class T>
    LLNode<T>* LinkedList<T>::head_node() const
    {
        if (head == nullptr) {throw std::runtime_error("The LinkedList is empty.");}
        return head;
    }

template <class T>
    T& LinkedList<T>::tail_value()
    {
        if (head == nullptr) {throw std::runtime_error("The LinkedList is empty.");}
        return head->prev->val;
    }

template <class T>
    LLNode<T>* LinkedList<T>::tail_node() const
    {
        if (head == nullptr) {throw std::runtime_error("The LinkedList is empty.");}
        return head->prev;
    }

template <class T>
    std::ostream& operator<<(std::ostream& out, const LinkedList<T> LL)
    {
        LLNode<T>* curr = LL.head_node();
        out << "[";
        
        while (curr->next != nullptr)
            out << curr->val << ", ";
            curr = curr->next;
             
        out << curr->val << "]" << std::endl;

        return out;
    }

int main()
{
    LinkedList<int> LL = LinkedList<int>();
    
    std::cout << "Linked List is empty? : " << LL.is_empty() << std::endl;
    std::cout << "Linked List length?   : "     << LL.length()     << std::endl;

    LL.append(1);
    // LL.append(2);
    // LL.append(3);
    // LL.append(4);
    // LL.append_front(0);

    // std::cout << LL;
    // std::cout << LL.length();

    return 0;
}