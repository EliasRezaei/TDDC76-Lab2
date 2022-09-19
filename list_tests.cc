#include "catch.hpp"
#include "List.h"

using namespace std;




TEST_CASE ("Constructors and getters")
{


    SECTION("Default constructor")
    {
        List Empty{};
        CHECK( Empty.is_empty() == true );
        CHECK( Empty.size() == 0 );
        
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

        
    }
    SECTION("append")
    {
        List list0{};
        list0.append(5);
        list0.append(10);

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