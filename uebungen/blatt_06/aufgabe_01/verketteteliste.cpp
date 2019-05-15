#include <cstring>
#include <cstdlib>
#include <iostream>

using namespace std;

struct Kette {
    int data;
    Kette *knoten;
};

Kette *ErsterKnoten = 0;

int main (int argc, char *argv[]) {
    
    int input;
    Kette *node, *old;

    do {
        cout << "Zahl eingeben (0 für Ende)" << endl;

        cin >> input;

        if (input) {
            Kette *node = new Kette();
            node->data = input;
            node->knoten = ErsterKnoten; 

            ErsterKnoten = node;
        }
    } while (input);

    while (ErsterKnoten) {
        cout << ErsterKnoten->data << endl;
        old = ErsterKnoten;
        ErsterKnoten = ErsterKnoten->knoten;
        delete old;
    }
}