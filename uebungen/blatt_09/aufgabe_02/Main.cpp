#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int h_hash(int s) { // s = key
    int m = 1000;
    float x = ((sqrt(5) - 1) / 2);

    return (int) (m * ((int)(s * x) % 1));
}

int main (int argc, char *argv[]) {

    // Für jedes Argument
    for (int i = 0; i < argc; i++) {
        cout << "h(" << argv[i] << ")=" << h_hash(atoi(argv[i])) << endl;
    }

    return 0;
}