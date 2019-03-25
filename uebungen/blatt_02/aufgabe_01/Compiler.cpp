#include "Compiler.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

//#define DEBUG

Compiler::Compiler(std::string pathToSource, std::string pathToOut) : pathToSource(pathToSource), pathToOut(pathToOut)
{
#ifdef DEBUG
    cout << "Source: " << this->pathToSource << endl;
    cout << "Destination: " << this->pathToOut << endl;
#endif
    compiled = "";
}

void Compiler::doJob()
{
    readIn();
    writeToOut();
}

void Compiler::writeToOut()
{
    ofstream giveOut;
    giveOut.open(pathToOut); //kein zweiter parameter, da inhalt ueberschrieben werden soll
    if (!giveOut)
    {
        cout << "Can not open file to write" << endl;
        return;
    }

    giveOut << compiled << endl;

    giveOut.close();
}

string Compiler::readIn()
{
    ifstream read(pathToSource);

    string line;
    while (!read.eof())
    {
        getline(read, line);
        istringstream iss(line);
        string a, b;
        if (!(iss >> a >> b))
            break;
        pars(a, b);
#ifdef DEBUG
        cout << a << " " << b << endl;
#endif
    }

    read.close();
    return "blaa";
}

void Compiler::pars(string order, string values)
{
    //stoi(string)
    if (order == "add" || order == "ADD")
    {
        compiled = compiled + "01";
        if (stoi(values) < 10)
            compiled = compiled + "0" + values;
        else
            compiled += values;
    }
    else if (order == "sub" || order == "SUB")
    {
        compiled = compiled + "02";
        if (stoi(values) < 10)
            compiled = compiled + "0" + values;
        else
            compiled += values;
    }
    else if (order == "mul" || order == "MUL")
    {
        compiled = compiled + "03";
        if (stoi(values) < 10)
            compiled = compiled + "0" + values;
        else
            compiled += values;
    }
    else if (order == "div" || order == "DIV")
    {
        compiled = compiled + "04";
        if (stoi(values) < 10)
            compiled = compiled + "0" + values;
        else
            compiled += values;
    }
    else if (order == "lda" || order == "LDA")
    {
        compiled = compiled + "05";
        if (stoi(values) < 10)
            compiled = compiled + "0" + values;
        else
            compiled += values;
    }
    else if (order == "ldk" || order == "LDK")
    {
        compiled = compiled + "06";
        if (stoi(values) < 10)
            compiled = compiled + "0" + values;
        else
            compiled += values;
    }
    else if (order == "sta" || order == "STA")
    {
        compiled = compiled + "07";
        if (stoi(values) < 10)
            compiled = compiled + "0" + values;
        else
            compiled += values;
    }
    else if (order == "inp" || order == "INP")
    {
        compiled = compiled + "08";
        if (stoi(values) < 10)
            compiled = compiled + "0" + values;
        else
            compiled += values;
    }
    else if (order == "out" || order == "OUT")
    {
        compiled = compiled + "09";
        if (stoi(values) < 10)
            compiled = compiled + "0" + values;
        else
            compiled += values;
    }
    else if (order == "hlt" || order == "HLT")
    {
        compiled = compiled + "0A";
        if (stoi(values) < 10)
            compiled = compiled + "0" + values;
        else
            compiled += values;
    }
    else if (order == "jmp" || order == "JMP")
    {
        compiled = compiled + "0B";
        if (stoi(values) < 10)
            compiled = compiled + "0" + values;
        else
            compiled += values;
    }
    else if (order == "jez" || order == "JEZ")
    {
        compiled = compiled + "0C";
        if (stoi(values) < 10)
            compiled = compiled + "0" + values;
        else
            compiled += values;
    }
    else
    {
        cout << "Sorry i cant work with this one: " << order << endl;
    }
#ifdef DEBUG
    cout << "Compilat " << compiled << endl;
#endif
}
