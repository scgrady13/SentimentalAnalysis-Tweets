//
// Created by Sean Grady on 2/16/2022.
//
#include "catch.hpp"
#include "DSString.h"
using namespace std;
TEST_CASE("=, .equals and ==", "[DSString]") {
    DSString testWord("Hello World");
    DSString testWord2("Hello World");
    DSString testWord3("fail");
    DSString testWord4("NewWord");
    SECTION("TESTING .equals") {
        REQUIRE(testWord.equals(testWord2)); //passes
        REQUIRE(testWord.equals(testWord4)); //fails

    }
}
//    SECTION("TESTING .equals"){
//        REQUIRE(testWord.equals(testWord2); //passes
//        REQUIRE(testWord.equals(testWord3); //fails
//    }
//}
//    SECTOION("TESTING ="){
//        testWord = testWord4;
//        REQUIRE(testWord.equals(testWord4)); //passes
//        REQUIRE(testWord.equals(testWord2)); //fails
//
//    }
//
//}
//TEST_CASE("+ operator", "[DSString]"){
//    DSString testWord1("Hello");
//    DSString testWord2("World");
//    DSString testWord3("HelloWorld");
//    SECTION("adding words"){
//        DSSTring newWord = testWord1 + testWord2;
//        REQUIRE(newWord == testWord3);//passes
//        REQUIRE(newWord == testWord1); //fails
//    }
//}
