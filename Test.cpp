/**
 * @file test.cpp
 * @author shaked levi
 * @brief This is a tests file for the Notebook project.
 * @version 0.1
 * @date 2022-03-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "doctest.h"
#include "Notebook.hpp"
#include "Direction.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}
// global notebook to be used for good inputs and bad inputs. /* CONSIDER - book for good and for bad.*/
Notebook tests;

TEST_CASE("Write -> Read, Remove -> Read") {

	tests.write(1,1,1,Direction::Horizontal,"BLA");
	CHECK(tests.read(1, 1,1,Direction::Horizontal, 3) == "BLA"); 

	tests.erase(1, 1,1,Direction::Horizontal, 3);
	CHECK(tests.read(1, 1,1,Direction::Horizontal, 3) == "~~~"); 

	tests.write(1,1,1,Direction::Vertical,"BLA");
	CHECK(tests.read(1, 1,1,Direction::Vertical, 3) ==  "B"
														"L"
														"A"); 

	tests.erase(1, 1,1,Direction::Vertical, 3);
	CHECK(tests.read(1, 1,1,Direction::Vertical, 3) == 	"~"
														"~"
														"~");

	tests.write(1,1,1,Direction::Horizontal,"BlaBla-blo");
	CHECK(tests.read(1, 1,1,Direction::Horizontal, 3) == "Bla"); 

	tests.erase(1, 1,1,Direction::Horizontal, 3);
	CHECK(tests.read(1, 1,1,Direction::Horizontal, 3) == "~~~");
	CHECK(tests.read(1, 1,1,Direction::Horizontal, 6) == "~~~Bla");	
	CHECK(tests.read(1, 3,1,Direction::Horizontal, 6) == "Bla-bl");
	
}

TEST_CASE("Negative Input") {

    CHECK_THROWS(tests.read(-2, 2,2,Direction::Horizontal, 3)); // negative page
	CHECK_THROWS(tests.read(-2, 2,2,Direction::Horizontal, -3)); // negative size
	CHECK_THROWS(tests.read(2, -2,2,Direction::Horizontal, 3)); // negative row
	CHECK_THROWS(tests.read(2, 2,-2,Direction::Horizontal, 3)); // negative column
	
}

TEST_CASE("Out Of Bounds Input"){

	CHECK_THROWS(tests.read(2, 101,2,Direction::Horizontal, 3)); // rows are maxed at 100.
	CHECK_THROWS(tests.read(2, 2,2,Direction::Vertical, 99)); // 99+2 = 101 row, bad input.

	CHECK_THROWS(tests.write(2, 101,2,Direction::Vertical, "Bla")); // writing to an unexisting row.

	CHECK_THROWS(tests.erase(2, 101,2,Direction::Vertical, 1)); // erasing from an unexisting row.
	CHECK_THROWS(tests.erase(2, 2,2,Direction::Vertical, 99)); // erasing from an unexisting row.

}
// This might be not right >> check those tests
TEST_CASE("Override Input"){

	tests.write(1,1,1,Direction::Horizontal,"Bla");
	CHECK_THROWS(tests.write(1, 1,1,Direction::Horizontal, "Bla")); // writing to an existing characters.

	tests.erase(1,1,1,Direction::Horizontal,3);
	CHECK_THROWS(tests.erase(1, 1,1,Direction::Horizontal, 3)); // erasing from an already erased characters.
}

TEST_CASE("Bad characters"){

	CHECK_THROWS(tests.write(1,1,1,Direction::Horizontal,"~~~")); // case where trying to write the char ~ which is erase.
	CHECK_THROWS(tests.write(2,2,2, Direction::Horizontal, "$BLA$")); // bad character, we only need normal letters.
	CHECK_THROWS(tests.write(3,3,3,Direction::Horizontal,"Y*O*U")); // bad word.
}
