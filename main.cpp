/**
 * Demo program for notebook exercise.
 *
 * Author: Erel Segal-Halevi
 * Edited by: Tal Zichlinsky
 * Since : 2022-01
 */

#include "Notebook.hpp"
#include "Direction.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
    ariel::Notebook notebook;
    try
    {
        string flag;
        int page = 0;
        int row = 0;
        int column = 0;
        string input;
        Direction dir;
        string dir_check;
        int length = 0;
        while (true)
        {
            std::cout << "Menu: \n 1.Exit \n 2.Write \n 3.Read \n 4.Erase \n 5.Show" << std::endl;
            cin >> flag;
            if (flag == "Exit")
            {
                break;
            }
            if (flag == "Write")
            {
                cout << "insert : page,row,column" << endl;
                cin >> page;
                cin >> row;
                cin >> column;
                cout << "insert direction to write : Horizontal / Vertical" << endl;
                cin >> dir_check;
                cout << "insert : input" << endl;
                cin >> input;

                if (dir_check == "Horizontal")
                {
                    dir = Direction::Horizontal;
                }
                else
                {
                    dir = Direction::Vertical;
                }

                notebook.write(page, row, column, dir, input);
            }
            if (flag == "Erase" || flag == "Read")
            {
                cout << "insert : page,row,column" << endl;
                cin >> page;
                cin >> row;
                cin >> column;
                cout << "insert direction to erase or read : Horizontal / Vertical" << endl;
                cin >> dir_check;
                cout << "insert : length" << endl;
                cin >> length;

                if (dir_check == "Horizontal")
                {
                    dir = Direction::Horizontal;
                }
                else
                {
                    dir = Direction::Vertical;
                }
                if (flag == "Erase")
                {
                    notebook.erase(page, row, column, dir, length);
                }
                else
                {
                    cout << notebook.read(page, row, column, dir, length) << endl;
                }
            }

            if (flag == "Show")
            {
                cout << "insert page you'd like to read from" << endl;
                cin >> page;
                notebook.show(page);
            }
        }
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
    }
}