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


TEST_CASE("Good input") { // first,third = rows : second,fourth = rows 

	//1
	CHECK((Notebook::read(2, 2,2,Direction::Horizontal, 1 )) == ("---"));

}

TEST_CASE("Bad input") {
	//1
    CHECK_THROWS(Notebook::write(-2, 2,2,Direction::Horizontal, "blabla" )); // negative rows

}

