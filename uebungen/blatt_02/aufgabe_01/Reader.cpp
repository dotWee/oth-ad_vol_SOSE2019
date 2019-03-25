#include "Reader.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

void Reader::set_Path(string Path)
{
    path = Path;
}

string Reader::getMachine()
{
    ifstream read(path);
    
    string line, command;
    while (!read.eof())
    {
        getline(read, line);
        istringstream iss(line);
        if (!(iss >> command))
            break;
        cout << command << endl;
    }

    read.close();
    return command;
}
