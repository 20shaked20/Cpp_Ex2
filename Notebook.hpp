/**
 * @file Notebook.hpp 
 * @author shaked levi
 * @brief This is a header file for the class notebook
 * @version 0.1
 * @date 2022-03-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>

using namespace std;

namespace ariel{
    
    class Notebook {
        
        private:
            // dynamic array. < consider vector usage.
            unsigned int page;
            unsigned int row;
            unsigned int column;

        public:

            /**
             * @brief This method writes to a given page the given input.
             * 
             * @param page represents a page in the book
             * @param row represents a row to start writing from
             * @param column represeting the column to start the writing from.
             * @param dir Horizontal -> left to right, Vertical -> up to down.
             * @param input string represting the input to enter into the page.
             */
           void write(unsigned int page, unsigned int row, unsigned int column, Direction dir, string input);

           /**
            * @brief this method is used to read a certain block from the notebook.
            * the params are the same as the above, i will not state them again, there is a single change.
            * @param page 
            * @param row 
            * @param column 
            * @param dir 
            * @param size -> represting how many rows/columns to read, the decsion is based on the direction.
            * @return string of the required block.
            */
           string read(unsigned int page, unsigned int row, unsigned int column, Direction dir, int size);

           /**
            * @brief this method is used to remove a certain block from the notebook.
            * the params are the same as the above, i will not state them again, there is a single change.
            * @param page 
            * @param row 
            * @param column 
            * @param dir 
            * @param size -> represting how many rows/columns to remove, the decsion is based on the direction.
            */
           void erase(unsigned int page, unsigned int row, unsigned int column, Direction dir, int size);
           
           /**
            * @brief Shows the notebooks given page.
            * 
            * @param page represents a page in the notebook.
            */
           void show(unsigned int page);
    };
}