//#define DEBUG  

#include <string>
#include <iostream>
#include "RegisterMachine.h"

RegisterMachine::RegisterMachine()
{
    amountR=8;
    registers = new int[amountR];
}

RegisterMachine::RegisterMachine(int amount) : amountR(amountR)
{
    registers = new int[amountR];
}

RegisterMachine::~RegisterMachine()
{
    delete registers;
}

void RegisterMachine::set_Order(string order)
{
    this->order = order;
}

int RegisterMachine::runProgramm()
{
    //to do dafuer sorgen, dass auch die werte bei denen buchstaben drin sind richtig gewandel werden in hex
    pc=0;
    bool run = true;

    while(run)
    {
        string correntOrder = order.substr(pc*4, 4); //hohlt sich immer neuen befehl
        string commandS = correntOrder.substr(0, 2);
        int command = stoi(commandS, 0, 16);  //fuer eine richtige umwandlung der befehle auch wenn diese in hex sind
        string values = correntOrder.substr(2, 2);
        
        #ifdef DEBUG
            cout << "correntOrder " << correntOrder << " commandS " << commandS << " command " << command << endl;
            cout << " values " << values << endl;
        #endif

        switch (command)
        {
            case 0x01:
                #ifdef DEBUG
                    cout << "in add" << endl;
                #endif
                add(stoi(values));  //stoi = string to integer
                break;
            case 0x02:
                #ifdef DEBUG
                cout << "in sub" << endl;
                #endif
                sub(stoi(values));  
                break;
            case 0x03:
                #ifdef DEBUG
                cout << "in mul" << endl;
                #endif
                mul(stoi(values));  
                break;
            case 0x04:
                #ifdef DEBUG
                cout << "in div" << endl;
                #endif
                div(stoi(values));  
                break;
            case 0x05:
                #ifdef DEBUG
                cout << "in lda" << endl;
                #endif
                lda(stoi(values));  
                break;
            case 0x06:
                #ifdef DEBUG
                cout << "in ldk" << endl;
                #endif
                ldk(stoi(values));  
                break;
            case 0x07:
                #ifdef DEBUG
                cout << "in sta" << endl;
                #endif
                sta(stoi(values));  
                break;
            case 0x08:
                #ifdef DEBUG
                cout << "in inp" << endl;
                #endif
                inp(stoi(values));  
                break;
            case 0x09:
                #ifdef DEBUG
                cout << "in out" << endl;
                #endif
                out(stoi(values));  
                break;
            case 0x0A:
                #ifdef DEBUG
                cout << "in hlt" << endl;
                #endif
                run = false;
                return hlt(stoi(values));  
                break;
            case 0x0B:
                #ifdef DEBUG
                cout << "in jmp" << endl;
                #endif
                jmp(stoi(values)); //intern wird pc um 1 kleiner gemacht als noetig, dann ist es passend wenn nachher ++ kommt 
                break;
            case 0x0C:
                #ifdef DEBUG
                cout << "in jez" << endl;
                #endif
                jez(stoi(values)); //intern wird pc um 1 kleiner gemacht als noetig, dann ist es passend wenn nachher ++ kommt 
                break;   
            default:
                cout << "go to cry" << endl;
                break;   
        }
        pc++;
    }
    return -1;
}

void RegisterMachine::add(int reg)
{
    if(reg <0 || reg >=amountR)
    {
        cout << "Core is dumped, you want to work on wrong register!!" << endl;
        return;
    }
    
    registers[0]+=registers[reg];
}

void RegisterMachine::sub(int reg)
{
    if(reg <0 || reg >=amountR)
    {
        cout << "Core is dumped, you want to work on wrong register!!" << endl;
        return;
    }
    
    registers[0]-=registers[reg];
}

void RegisterMachine::mul(int reg)
{
    if(reg <0 || reg >=amountR)
    {
        cout << "Core is dumped, you want to work on wrong register!!" << endl;
        return;
    }
    
    registers[0]*=registers[reg];
}

void RegisterMachine::div(int reg)
{
    if(reg <0 || reg >=amountR)
    {
        cout << "Core is dumped, you want to work on wrong register!!" << endl;
        return;
    }
    if(registers[reg] == 0)
        cout << "To divide by zero is still not allowed" << endl;
    
    registers[0]/=registers[reg];
}

void RegisterMachine::lda(int reg)
{
    if(reg <0 || reg >=amountR)
    {
        cout << "Core is dumped, you want to work on wrong register!!" << endl;
        return;
    }
    
    registers[0]=registers[reg];
}

void RegisterMachine::ldk(int value)
{
    registers[0]=value;
}

void RegisterMachine::sta(int reg)
{
    if(reg <0 || reg >=amountR)
    {
        cout << "Core is dumped, you want to work on wrong register!!" << endl;
        return;
    }
    
    registers[reg]=registers[0];
}

void RegisterMachine::inp(int reg)
{
    if(reg <0 || reg >=amountR)
    {
        cout << "Core is dumped, you want to work on wrong register!!" << endl;
        return;
    }
    
    cin >> registers[reg];
}

void RegisterMachine::out(int reg)
{
    if(reg <0 || reg >=amountR)
    {
        cout << "Core is dumped, you want to work on wrong register!!" << endl;
        return;
    }
    
    cout << "Sum up to now " <<registers[reg] << endl;
}

int RegisterMachine::hlt(int value)
{
    if (value == 99)
    {
        cout << "Programm finished successfully" << endl;
        return 0;
    }
    else
    {
        cout << "Programm exited with Value " << value << endl;
        return value;
    }
}

void RegisterMachine::jmp(int value)
{
    pc = value -1 ; //da bei mir es mit zeile 0 los geht    
    pc--; //da nach dem switch um 1 erhoeht wird
}

void RegisterMachine::jez(int value)
{
    #ifdef DEBUG
        cout << "register0        " << registers[0] << endl;
    #endif
    if(registers[0] == 0)
    {
        #ifdef DEBUG
            cout << "Will jump in jez" << endl;
        #endif
        if(value-1>=0)
        {
            pc = value-1;  //da bei mir die erse zeile nr. 0 hat
            pc--; //da nach dem switch um 1 erhoeht wird
        }
    }
}

