#include <iostream>
#include <vector>
#include "MaxSum2D.h"

using namespace std;

int main()
{
    int lines = 2, rows = 3;

    vector<vector<int>> field;

    field.resize(lines);

    for (int i = 0; i < lines; i++)
        field[i].resize(rows);

    cout << "Enter values" << endl;

    for (vector<int> &line : field)
    {
        for (int &entry : line)
        {
            cin >> entry;
        }
    }

    MaxSum2D calcer(lines, rows);
    calcer.set_field(field);
    calcer.calcMaxSum();

    cout << "Max Sum is " << calcer.get_MaxSum() << endl;
    return 0;
}
