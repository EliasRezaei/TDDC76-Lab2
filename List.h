#include <string>





class List
{
public:
    List(); // empty list
    ~List();

    // copy constructor 
    List(const List& list);
    // Copy assignment operator
    List& operator=(const List& list);

    void prepend(int value);
    void append(int value);

    void pop_first();
    void pop_last();

    bool is_empty() const;
    std::string to_string() const;

    int front() const;
    int back() const;

    int get(int pos) const;
    void erase();
    int size() const;



private:
    struct Node
    {
        Node(int value);

        int m_value;
        Node* m_next;
    };


    Node* m_head; // first element
    Node* m_tail; // last element

    unsigned int m_size; // last element



public:

};
