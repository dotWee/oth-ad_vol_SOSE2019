#ifndef AD_VOL_SOSE2019_COMPILER_H
#define AD_VOL_SOSE2019_COMPILER_H

#include <string>

using namespace std;

class Compiler {
public:
    string compiled;
    string pathToSource;
    string pathToOut;

    Compiler(std::string pathToSource, std::string pathToOut);
    void doJob();
    void writeToOut();
    string readIn();
    void pars(string order, string values);
};

#endif //AD_VOL_SOSE2019_COMPILER_H