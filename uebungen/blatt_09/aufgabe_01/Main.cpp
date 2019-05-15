#include <iostream>
#include <vector>

using namespace std;

int main (int argc, char *argv[]) {
    
    int hashValue;
    int inputValue;

    vector<int> hashTable;
    vector<int> valueTable;

    cout << "Geben sie Zahlen ein, für das der Wert der Hashfunktion h(s) berechnet werden soll (Negative Zahlen beenden die Eingabeschleife)" << endl << endl;
    while (inputValue >= 0) {
        cout << "s = ";

        cin >> inputValue;
        valueTable.push_back(inputValue);
    
        hashValue = inputValue % 9;
        hashTable.push_back(hashValue);

        cout << "h(" << inputValue << ") = " << hashValue << endl;
    }

    return 0;
}