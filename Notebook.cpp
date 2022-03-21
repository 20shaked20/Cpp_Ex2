#include "Notebook.hpp"
#include "Direction.hpp"
using namespace std;
using namespace ariel;

// constructor!
Notebook::Notebook(){
    return;
}

void Notebook::write(unsigned int page, unsigned int row, unsigned int column, Direction dir, string input){
    return;
}

string Notebook::read(unsigned int page, unsigned int row, unsigned int column, Direction dir, int size){
    return "This is read";
}

void Notebook::erase(unsigned int page, unsigned int row, unsigned int column, Direction dir, int size){
    return;
}

void Notebook::show(unsigned int page){
    cout<< "This is a show"<< endl;
}


