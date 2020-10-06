// Su nombre aqui

#define CATCH_CONFIG_MAIN  
#include "catch.hpp"
#include <vector>
#include "DList.h"
using namespace std;


TEST_CASE( "Testing AList class", "[AList]" ) {

    DList L;
    L.append(10);
    L.append(20);
    CHECK(L.to_string()=="<|10,20>");
    L.next();
    CHECK(L.to_string()=="<10|20>");
    L.next();
    CHECK(L.to_string()=="<10,20|>");
    L.next();
    CHECK(L.to_string()=="<10,20|>");
    L.append(30);
    CHECK(L.to_string()=="<10,20|30>");
    L.remove();
    CHECK(L.to_string()=="<10,20|>");
    L.prev();
    L.prev();
    L.remove();
    CHECK(L.to_string()=="<|20>");
    L.append(40); L.append(50); L.append(60);
    L.moveToPos(4);
    CHECK(L.to_string()=="<20,40,50,60|>");

    L.clear();

    L.append(70);
    CHECK(L.to_string()=="<|70>");
    L.insert(66);
    CHECK(L.to_string()=="<|66,70>");
    L.moveToEnd();
    L.insert(77);
    L.moveToEnd();
    CHECK(L.to_string()=="<66,70,77|>");

    L.moveToPos(0);
    CHECK(L.to_string()=="<|66,70,77>");

    L.moveToPos(2);
    CHECK(L.to_string()=="<66,70|77>");
    L.prev();
    CHECK(L.to_string()=="<66|70,77>");

}
