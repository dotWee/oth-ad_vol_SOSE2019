#include <iostream>
#include <vector>

using namespace std;

const int INPUT_SIZE = 20;
const int BUCKET_K = 10;

void print(vector<int> input) {
    for ( int i = 0; i < input.size(); i++ ) {
        cout << input.at(i) << " ";
    }

    cout << endl;
}

void countingsort(vector<int> input) {
    int *counts = new int[input.size()];

    for (int i = 0; i < input.size(); i++) {
        counts[input.at(i)]++;
    }

    int outputindex = 0;
    for (int j = 0; j < input.size(); j++) {
        while (counts[j]--) {
            input.at(outputindex++) = j;
        }
    }
}

int main (int argc, char *argv[]) {

    vector<int> input;

    int tmp = 1;
    cout << "Geben sie Zahlen für das Array ein (negative Zahlen beenden die Eingabeschleife)" << endl;
    while (tmp >= 0) {
        cin >> tmp;
        input.push_back(tmp);
    }

    countingsort(input);
    cout << "Output: ";

    print(input);
    return 0;
}