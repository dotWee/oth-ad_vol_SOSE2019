#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

bool algo1(int a[], int s) {
    int erg;
    
    int length = (sizeof(a) / sizeof(a[0]));
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            if (i == j) {
                //
            } else {
                erg = a[i]+a[j];
                if(s == erg){
                    return true;
                }
            }
        }
    }
    
    return false;
}

int main(int argc, char *argv[])
{

    int a[] = {5, 44, -5, 3, 14, -66, 7, 9, -3};
    int s = 0;
    cout << (algo1(a, s) ? "true" : "false") << endl;

    return 0;
}