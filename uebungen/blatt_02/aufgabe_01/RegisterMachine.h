#ifndef AD_VOL_SOSE2019_REGISTERMACHINE_H
#define AD_VOL_SOSE2019_REGISTERMACHINE_H

#include <string>

using namespace std;

class RegisterMachine {
public:
    int amountR;
    int pc;
    string order;

    RegisterMachine();
    RegisterMachine(int amount);
    ~RegisterMachine();
    
    int runProgramm();
    void set_Order(string order);
    void add(int reg);
    void sub(int reg);
    void div(int reg);
    void lda(int reg);
    void out(int reg);
    void inp(int reg);
    int hlt(int value);
    void jmp(int value);
    void jez(int value);
    void sta(int reg);
    void mul(int reg);
    void ldk(int value);

    void set_Path(string Path);
    string getMachine();

    int* registers;
};

#endif //AD_VOL_SOSE2019_REGISTERMACHINE_H