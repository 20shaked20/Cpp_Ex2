#include "Notebook.hpp"
#include "Direction.hpp"
using namespace std;
using namespace ariel;

// constructor!
Notebook::Notebook(){
}

void Notebook::write(int page, int row, int column, Direction dir, string input){
}

string Notebook::read(int page,  int row, int column, Direction dir, int size){
    return "This is read";
}

void Notebook::erase( int page, int row, int column, Direction dir, int size){
}

void Notebook::show( int page){
    cout<< "This is show"<< endl;
}


