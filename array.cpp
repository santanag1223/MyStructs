#include <string>
// Better Arrary Data Structure

using std::size_t;

template< class T, size_t N> 
struct array {
    
    public:
    size_t capacity = 0;

    array(size_t size) {
        capacity = size
    }

    ~array() {

    }

    void extend() {
        // double the size of array
    }

    void add_elem() {
        // add element to array
    }

    T std::operator[](array const &obj, int i){
        // get value at element at i
    }

    array(T) std::operator[](array const &obj, string range){
        // get values from range given by the string
    }

    private:

    int* arr = new int[capacity]



};