#include "List.h"
#include <stdexcept>
#include <iostream>

// empty list
List::List()
: m_head{nullptr}, m_tail{0}, m_size{0} 
{

}

List::~List()
{
    erase();
}

// copy constructor 
List::List(const List& list_to_copy)
{
    if (list_to_copy.is_empty())
    {
        m_head = nullptr;
        m_tail = nullptr;
        m_size = 0;
    }
    else
    {
        list_to_copy.m_head->deep_copy(this);
    }
    // recursive method on list_to_copy
    //newlist.append()
}

// copy assignment operator
List& List::operator=(const List& rhs_list)
{
    // check self assignemnt 
    if (this == &rhs_list)
    {
        return *this;
    }
    else if (rhs_list.is_empty())
    {
        m_head = nullptr;
        m_tail = nullptr;
        m_size = 0;
    }
    else
    {
        rhs_list.m_head->deep_copy(this);
    }
    return *this;
}

// Move constructor:
List::List(List&& list_to_move)
    : m_head{list_to_move.m_head}, m_tail{list_to_move.m_tail}, m_size{list_to_move.m_size}
{
    list_to_move.m_head = nullptr;
    list_to_move.m_tail = nullptr;
    list_to_move.m_size = 0;
}

// Move assignment operator:
List& List::operator=(List&& rhs_list)
{
    //TODO: might not need to check for self assignment:
    if(this == &rhs_list)
        return (*this);
    else
    {
        m_head = rhs_list.m_head;
        m_tail = rhs_list.m_tail;
        m_size = rhs_list.m_size;

        rhs_list.m_head = nullptr;
        rhs_list.m_tail = nullptr;
        rhs_list.m_size = 0;
        return *this;
    }
}

void List::prepend(int value)
{
    if (is_empty())
    {
        m_head = new Node{value};
        m_tail = m_head;
    }
    else
    {
        Node* temp = new Node{value};
        temp->m_next = m_head;
        m_head = temp; 
    }
    m_size++;
}

void List::append(int value)
{
    if (is_empty())
    {
        m_head = new Node{value}; 
        m_tail = m_head;
    }
    else 
    {
        m_tail->m_next = new Node{value};
        m_tail = m_tail->m_next;
    }
    m_size++;
}

void List::pop_first()
{
    //ska ta bort första elementen.
    if(is_empty())
    {
        throw std::out_of_range ("List is empty");
    }
    else
    {
        Node* old_head = m_head;
        m_head = old_head->m_next;
        delete old_head;
    }
}

void List::pop_last()
{
    if(is_empty())
    {
        throw std::out_of_range ("List is empty");
    }
    else
    {
        Node* secondToLastNode = m_head->pop_last();  // starts recursion
        m_tail = secondToLastNode;
    }
}

List::Node* List::Node::pop_last()
{
    // Base case:
    if (m_next->m_next == nullptr) // when (this) is the second to last node.
    {
        delete m_next;  // then delete the last node
        m_next = nullptr;       // set this->m_next to nullptr
        return this;            // return this so that we can set m_tail to this
    }
    // recursion case
    else
    {
        return m_next->pop_last();
    }
}


bool List::is_empty() const
{   
    return (m_head == nullptr);
}

std::string List::to_string() const
{
    if (is_empty())
        return "[]";
    else
        return "[" + m_head->to_string() + "]";
}

int List::front() const
{
    if (is_empty())
    {
        throw std::out_of_range ("List is empty");
    }
    else
    {
        return(m_head->m_value);
    }
}

int List::back() const
{
    if (is_empty())
    {
        throw std::out_of_range ("List is empty");
    }
    else
    {
        return(m_tail->m_value);
    }
}

int List::get(int pos) const
{
    if (is_empty())
    {
        throw std::out_of_range ("List is empty");
    }
    else if (m_size < pos + 1 || pos <0)
    { // TODO: test
    
        throw std::out_of_range ("List does not contain a element at position: " + std::to_string(pos) + " ");
    }
    else
    {
        return m_head->get_nth_node(pos);
    }

}

void List::erase()
{
    if (!is_empty()) // only erase if there is something there to erase
    {
        m_head->erase(); // deletes all nodes after the head
        delete m_head;  // deletes m_head
        m_head = nullptr;   // set m_head to nullptr
        m_size = 0;        
    }
}


int List::size() const
{
    return (m_size);
}



List::Node::Node(int x)
    : m_value(x), m_next(nullptr)
{

}

void List::Node::erase()
{
    if (m_next->m_next == nullptr)
    {
        // if we are on the second to last node, remove the last one
        delete m_next;
    }
    else
    {
        m_next->erase();
        // after removing all subsequent nodes. Delete it
        delete m_next;
    }
}


int List::Node::get_nth_node(int n) const
{
    // termination condition, (this) is the node to get
    if (n == 0)
    {
        return m_value;
    }
    else
    {
        return (m_next->get_nth_node(n - 1));
    }
}

std::string List::Node::to_string() const
{
    if (m_next == nullptr)
    {
        return std::to_string(m_value);
    }
    else
    {
        return std::to_string(m_value) + ", " + m_next->to_string();
    }
}

void List::Node::deep_copy(List* new_list)
{
    // BaseCase: we are at the last node
    if (m_next == nullptr)
    {
        new_list->append(m_value);
    }
    else
    {
        new_list->append(this->m_value);
        m_next->deep_copy(new_list);
    }
}

