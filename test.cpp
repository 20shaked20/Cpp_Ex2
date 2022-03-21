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

TEST_CASE("Good input") { // first,third = rows : second,fourth = rows 
	
	//1
	CHECK(tests.read(2, 2,2,Direction::Horizontal, 1) == "---");

}

TEST_CASE("Bad input") {

	// Negative input cases:
    CHECK_THROWS(tests.read(-2, 2,2,Direction::Horizontal, 3)); // negative page
	CHECK_THROWS(tests.read(-2, 2,2,Direction::Horizontal, -3)); // negative size
	CHECK_THROWS(tests.read(2, -2,2,Direction::Horizontal, 3)); // negative row
	CHECK_THROWS(tests.read(2, 2,-2,Direction::Horizontal, 3)); // negative column

	//Out of bounds input:
	CHECK_THROWS(tests.read(2, 101,2,Direction::Horizontal, 3)); // rows are maxed at 100.
	CHECK_THROWS(tests.read(2, 2,2,Direction::Vertical, 99)); // 99+2 = 101 row, bad input.

}

