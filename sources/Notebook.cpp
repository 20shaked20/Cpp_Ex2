#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>

#include "Notebook.hpp"

/*Boundings*/
int start_row = INT_MAX;
int end_row = 0;
int start_line = INT_MAX;
int end_line = 0;

std::vector<int> pages; /*pages checker, if it was written or not */


ariel::Notebook::Notebook(){
    std::unordered_map<int,std::unordered_map<int,std::unordered_map<int,char>>> notebook;
}

void input_check(int page, int row, int column, ariel::Direction dir, string const &input,int size){


    int word_len = input.length();
    int const bounds = 100;
    int const special_bounds_case = 101;
    if(size == special_bounds_case && column == 0 && dir == Direction::Vertical){ // is a good case to consider.
        return;
    }

    /* Negative case */
    if(page < 0 || row < 0 || column < 0 || size < 0){
        __throw_out_of_range("Negative values");
        exit(1);
    }
    
    if(word_len + row > bounds && dir == Direction::Vertical){
        return;
    }
     /* Out of bounds in rows case */
    if( column > bounds || word_len + column > bounds || column + size > bounds) {
        __throw_out_of_range("Row length can't exceed 100");
        exit(1);
    }

   
}

void ariel::Notebook::write(int page, int row, int column, Direction dir, string input){
    /**
     * @brief The way i implement this method -
     * i take the input string and split it into vector of chars.
     * then i inesrt in the right Direction to the notebook.
     * all this i do while considering the excpetions:
     * 1. rows are maxed at 100.
     * 2. do not overwrite already in written places. ( at your own risk, jibresh can be made )
     * -> / note that by default char is 0, hence its empty to writing /
     * 
     */

    /* INPUT CHECKINGS */ 
    int word_len = input.length(); /* size of the input */
    int tmp_column = column;
    int tmp_row = row;
    for(unsigned long i = 0; i< word_len; ++i){
        if(std::isprint(input[i]) == 0){
            __throw_invalid_argument("cannot write special chars");
        }
        if(input[i] == '~'){
            __throw_invalid_argument("Bad character inputs");
        }
        if(dir == ariel::Direction::Horizontal) {
            if(notebook[page][tmp_row][column] == '_') {continue;} // handle '_'
            if(notebook[page][row][tmp_column] != 0  ){ /* Empty */
                __throw_invalid_argument("Overwriting an existing char");
            }
            tmp_column++;
        }
        if(dir == ariel::Direction::Vertical) {
            if(notebook[page][tmp_row][column] == '_') {continue;} // handle '_'
            if(notebook[page][tmp_row][column] != 0){ /* Empty */
                __throw_invalid_argument("Overwriting an existing char");
            }
            tmp_row++;
        }
    }
    input_check(page,row,column,dir,input, 0); 
    /* this checks if a page is already in the written pages */
    if(std::find(pages.begin(),pages.end(),page) == pages.end()){
        pages.push_back(page);
    }
    


    /* Globals for show method */
    if(end_row < row + word_len){
        end_row = row + word_len;
    }
    if(start_row >= row){
        start_row = row;
    }

    if(end_line < column + word_len){
        end_line = column + word_len;
        
    }
    if(start_line >= column){
        start_line = column;
    }

   
    vector<char> split;
    copy(input.begin(), input.end(), back_inserter(split)); /* vector of the input chars */

    unsigned long i = 0; /* iterator */

    /* Horizontal Case */
    if(dir == ariel::Direction::Horizontal) { 
        for(i = 0; i<word_len; ++i) {
                notebook[page][row][column] = split.at(i);
                column++;
        }
    }

    /*Vertical Case */
    if(dir == ariel::Direction::Vertical) { 
        for(i = 0; i<word_len; ++i) {
                notebook[page][row][column] = split.at(i);
                row++;
        }
    }
}

string ariel::Notebook::read(int page,  int row, int column, ariel::Direction dir, int size){
    /**
     * @brief The implemenation of this method is basic, read from the notebook according to:
     * Direction, size ( how many characters to read )
     * 
     */
    input_check(page,row,column,dir," ",size);

    string part_of_book;

    /* Horizontal Case */ 
    if(dir == ariel::Direction::Horizontal){ 
        for(int i = 0; i<size; ++i){
            if(notebook[page][row][column] == 0){
                part_of_book += "_";
            }else{
                part_of_book += notebook[page][row][column];
            }
            column++;

        }
    }

    /* Vertical Case */
    if(dir == ariel::Direction::Vertical){ 
        for(int i = 0; i<size; ++i){
            if(notebook[page][row][column] == 0){
                part_of_book += "_";
            }else{
                part_of_book += notebook[page][row][column];
            }
            row++;

        }
    }

    return part_of_book;
}

void ariel::Notebook::erase( int page, int row, int column, ariel::Direction dir, int size){
    /**
     * @brief This method is used in order to erase a certain chars inside the notebook.
     * the symbol ~ represents an erased char.
     * 
     */

    input_check(page,row,column,dir," ",size);

    /* Horizontal Case */ 
    if(dir == ariel::Direction::Horizontal){ 
        for(int i = 0; i<size; ++i){
            notebook[page][row][column] = '~';
            column++;

        }
    }

    /* Vertical Case */
    if(dir == ariel::Direction::Vertical){ 
        for(int i = 0; i<size; ++i){
            notebook[page][row][column] = '~';
            row++;

        }
    }
}

void ariel::Notebook::show( int page ){
    /*Neg value*/
    if(page < 0)
    {
        std::__throw_out_of_range("Negative page");
    }

    /*Empty page case */
    if(std::find(pages.begin(),pages.end(),page) == pages.end()){
        cout << "Empty Page: " << page << endl;
        return;
    }

    std::cout<< "PAGE NUMBER: "<< page <<endl; /*Prints the page number */
    std::cout<< "---------------------------------------------------------------" << endl;
    int curr_row = start_row-1;
    while(curr_row < end_row){
        /* keeps the row number */
        string print_line = to_string(curr_row)+") ";
        int curr_line = start_line;
        while(curr_line < end_line){
            /*create the line */
            char ch = notebook[page][curr_row][curr_line];
            if(ch == 0){ /*Empty case */
                print_line+="_";
            }
            else{
                    print_line+=ch;
            }
            ++curr_line;
        }
        /*This checks if the line is empty or not */
        std::cout << print_line << endl; /*Prints the line and closes the row*/
        ++curr_row;
    }
    std::cout<< "---------------------------------------------------------------" << endl;
}


