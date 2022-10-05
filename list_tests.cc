#include "catch.hpp"
#include "List.h"

using namespace std;




TEST_CASE ("Constructors and getters")
{

    SECTION("Default constructor")
    {
        List Empty{};
        CHECK( Empty.is_empty()); // removed == true
        CHECK( Empty.size() == 0 );
    } 

    SECTION("copy construsct")
    {
        List original_list{};   //default
        original_list.append(78);
        original_list.append(79);
        original_list.append(80);

        List copied_list{original_list};

        CHECK( original_list.to_string() == copied_list.to_string() );
        List empty_list{};   //default

        List copied_empty_list{empty_list}; // creates a new object called copied_empty_list
        CHECK( empty_list.to_string() == copied_empty_list.to_string() );
    }

        SECTION("copy assignment operator")
    {
        List original_list{};   //default
        original_list.append(78);
        original_list.append(79);
        original_list.append(80);

        List list_a;
        list_a = original_list; // Copy assignment operator is called

        CHECK( original_list.to_string() == list_a.to_string() );

        List empty_list{};   //default
        List assigned_empty_list = empty_list; // creates a new object called copied_empty_list
        CHECK( empty_list.to_string() == assigned_empty_list.to_string() );

        // self assignment
        list_a = list_a;
        CHECK( list_a.to_string() == "[78, 79, 80]" );
    }
    
    SECTION("move constructor")
    {
        List original_list{};   //default
        original_list.append(78);
        original_list.append(79);
        original_list.append(80);

        List new_moved_list{std::move(original_list)};

        CHECK(new_moved_list.to_string() == "[78, 79, 80]");
        CHECK(original_list.to_string() == "[]");

        List empty_list{};   //default
        List moved_empty_list{empty_list};
        CHECK(moved_empty_list.to_string() == "[]");
    }
        SECTION("move assignment")
    {
        List original_list{};   //default
        original_list.append(78);
        original_list.append(79);
        original_list.append(80);

        List new_moved_list = std::move(original_list);

        CHECK(new_moved_list.to_string() == "[78, 79, 80]");
        CHECK(original_list.to_string() == "[]");
        CHECK(original_list.size() == 0);

        List empty_list{};   //default
        List moved_empty_list{empty_list};
        CHECK(moved_empty_list.to_string() == "[]");

        // self assignment:

        new_moved_list = new_moved_list;
        CHECK(new_moved_list.to_string() == "[78, 79, 80]");




    }
}

TEST_CASE("pre/append")
{

    SECTION("Prepend")
    {
    List list0{};
    list0.append(5);
    list0.append(10);
    list0.prepend(200);
    CHECK(list0.front() == 200);

    CHECK( list0.size() == 3);


        
    }
    SECTION("append")
    {
        List list0{};
        list0.append(5);
        list0.append(10);
        list0.append(0);

        CHECK(list0.to_string() == "[5, 10, 0]");
        CHECK(list0.size() == 3);

    }

    SECTION("Get")
    {
        List list0{};
        list0.append(5);
        list0.append(10);
        list0.append(0);

        CHECK(list0.get(0) == 5);
        CHECK(list0.get(1) == 10);
        CHECK(list0.get(2) == 0);
        CHECK_THROWS(list0.get(7) == 0);



    }
}


TEST_CASE("front/back")
{
    List list0{};
    list0.append(5);
    list0.append(25);
    list0.append(125);
    List lista1{};
    


    SECTION("when empty")
    {
        CHECK_THROWS(lista1.front() == 3);
    }

    SECTION("front")
    {
        CHECK( list0.front() == 5);
    }
    SECTION("back")
    {
        CHECK( list0.back() == 125);
    }
}



TEST_CASE("erase")
{
    SECTION("erase")
    {
    List list0{};
    list0.append(5);
    list0.append(10);
    list0.prepend(200);

    list0.erase();
    CHECK(list0.to_string() == "[]");

    }


}



TEST_CASE("poplast/ popfirst")
{
    List list0{};
    list0.append(5);
    list0.append(25);
    list0.append(125);
    list0.append(52525);

    

    SECTION("poplast")
    {
        list0.pop_last();
        CHECK( list0.to_string() == "[5, 25, 125]");
    }

    SECTION("popfirst")
    {
        list0.pop_first();
        CHECK( list0.to_string() == "[25, 125, 52525]");
    }
}


TEST_CASE("str")
{
    SECTION("Prepend")
    {
        List list0{};
        list0.append(5);
        list0.append(10);

        CHECK(list0.to_string() == "[5, 10]");


    }


}
