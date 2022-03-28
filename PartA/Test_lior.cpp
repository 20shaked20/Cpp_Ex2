#include "doctest.h"
#include "Notebook.hpp"
#include "Direction.hpp"
using namespace ariel;


string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}
	ariel::Notebook notebook;

TEST_CASE("Good input") {
    notebook.write(2,0,0, Direction::Horizontal,"lior");
	CHECK(notebook.read(2,0,0,Direction::Horizontal, 4)=="lior");

    notebook.write(3,0,0, Direction::Horizontal,"lior-nagar");
	CHECK(notebook.read(3,0,0,Direction::Horizontal, 10)=="lior-nagar");

    notebook.erase(3,0,0, Direction::Horizontal,10);
	CHECK(notebook.read(3,0,0,Direction::Horizontal,10)=="~~~~~~~~~~");

    notebook.write(100,100,50, Direction::Horizontal, "abcd");
	CHECK(notebook.read(100,99,51, Direction::Vertical,3)=="_b_");  
		
	notebook.erase(100,99,51, Direction::Vertical,3);
    CHECK(notebook.read(100,99,51,Direction::Vertical,3)=="~~~");
	
    notebook.write(0,0,0, Direction::Horizontal,"check_the_code");
	CHECK(notebook.read(0,0,0,Direction::Horizontal, 14)=="check_the_code");

    notebook.erase(0,0,0, Direction::Horizontal,14);
	CHECK(notebook.read(0,0,0,Direction::Horizontal,14)=="~~~~~~~~~~~~~~");

    CHECK(notebook.read(14,0,0,Direction::Horizontal,3)=="___");

    CHECK(notebook.read(50,3,3,Direction::Vertical,5)=="_____");

    notebook.write(10,3,3, Direction::Vertical,"check_the_code");
	CHECK(notebook.read(10,3,3,Direction::Vertical, 14)=="check_the_code");

    notebook.write(10,3,87, Direction::Horizontal,"check_my_code");
	CHECK(notebook.read(10,3,87,Direction::Horizontal, 13)=="check_my_code");

	CHECK(notebook.read(10,1,87,Direction::Vertical,5)=="__c__");

    notebook.erase(10,1,87, Direction::Vertical,2);
	CHECK(notebook.read(10,1,87,Direction::Vertical,5)=="~~c__");

    notebook.erase(10,3,80, Direction::Horizontal,5);
	CHECK(notebook.read(10,3,80,Direction::Horizontal,20)=="~~~~~__check_my_code");



							                                                                                          
                                          
}
TEST_CASE("Bad input") {
    CHECK_THROWS(notebook.write(100,99,52, Direction::Vertical, "xyz"));
    CHECK_THROWS(notebook.write(-5,1,1, Direction::Horizontal,"lior"));
    CHECK_THROWS(notebook.write(5,-1,1, Direction::Horizontal,"lior"));
    CHECK_THROWS(notebook.write(-3,-1,-1, Direction::Horizontal,"lior"));
    CHECK_THROWS(notebook.write(100,100,100, Direction::Horizontal, "xyz"));
    CHECK_THROWS(notebook.write(3,0,0, Direction::Horizontal,"liorro"));
   

}
