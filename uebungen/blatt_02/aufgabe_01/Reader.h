#ifndef AD_VOL_SOSE2019_READER_H
#define AD_VOL_SOSE2019_READER_H

#include <string>

using namespace std;

class Reader {
public:
    string path;
    
    Reader();
    void set_Path(string Path);
    string getMachine();
};

#endif //AD_VOL_SOSE2019_READER_H