#include "List.h"
#include <stdexcept>

// empty list
List::List()
: m_head{nullptr}, m_tail{0}, m_size{0} 
{

}

List::~List()
{

}

// copy constructor 
List::List(const List& list)
{

}

// copy assignment operator
List& List::operator=(const List& list)
{

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

}

void List::pop_last()
{
    
}

bool List::is_empty() const
{   
    return (m_head == nullptr);
}

std::string List::to_string() const
{

    return "";    
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

    

}

void List::erase()
{
    
}


int List::size() const
{
    return (m_size);
}



List::Node::Node(int x)
    : m_value(x), m_next(nullptr)
{

}


