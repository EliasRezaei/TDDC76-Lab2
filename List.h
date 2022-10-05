#ifndef LIST_H
#define LIST_H

#include <string>
// Information om komplettering:
// Kompletteringen kan gälla hela filen och alla filer i labben,
// så får ni komplettering på en sak, kan samma sak förekomma på
// fler ställen utan att jag skrivit det.
//
// Komplettering lämnas in via sendlab efter senast en (1) vecka
//
// Har ni frågor om kompletteringen kan ni maila mig på:
// maria.axelsson@liu.se

//Komplettering. Ni har skrivit public två gånger?
//Komplettering. Inkonsekvent koduppdelning.

// Svar: tanken var att ha public: private: för alla metoder
//      Och sedan public: och private: för instansvariabler.

//Ni har med sort() bara som deklaration?
// Tagits bort

class List
{
public:
    List(); // empty list
    ~List();

    // copy constructor
    List(const List& list_to_copy);
    // Copy assignment operator
    List& operator=(const List& rhs_list);

    // Move constructor:
    List(List&& list_to_move);
    // Move assignment operator:
    List& operator=(List&& rhs_list);


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
    public:
        Node(int value);
        void erase();
        int get_nth_node(int n) const;
        std::string to_string() const;
        Node* pop_last();

        void deep_copy(List* new_list);



        int m_value;
        Node* m_next;
    };
    Node* m_head; // first element
    Node* m_tail; // last element
    unsigned int m_size;
};

#endif
