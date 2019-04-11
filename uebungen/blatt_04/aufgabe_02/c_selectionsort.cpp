#include <cstring>
#include <cstdlib>
#include <iostream>
#include <sys/time.h>

using namespace std;

static int a[] = { -5, 13, -32, 7, -3, 17, 23, 12, -35, 19 };

long long timeInMilliseconds(void) {
    struct timeval tv;

    gettimeofday(&tv,NULL);
    return (((long long)tv.tv_sec)*1000)+(tv.tv_usec/1000);
}

void printHeader(string logTag) {
    cout << logTag << ": Starte Sortierung." << endl;    
}

void printFooter(string logTag, long timestamp, int *array, int length) {
    cout << logTag << ": Array={";
    for (int i = 0; i < length; ++i) {
        std::cout << array[i] << ", ";
    }
    cout << "}" << endl;

    cout << logTag << ": Sortierung dauerte " << (timeInMilliseconds() - timestamp) << "ms." << endl;
}

void selectionsort(int *array, int length) {
    string logTag = "Selectionsort";
    printHeader(logTag);   

    long timestamp = timeInMilliseconds();

    int x, y, z, max;
    for (x = 0; x < length - 1; x++) {
        max = x;
        for (y = x + 1; y < length; y++) {
            if (array[y] >= array[max])
                max = y;
        }

        z = array[max];
        array[max] = array[x];
        array[x] = z;
    }
    
    printFooter(logTag, timestamp, array, length);
}

int main (int argc, char *argv[]) {

    int arrayLength = sizeof(a) / sizeof(a[0]);

    int selectionsortArray[arrayLength];
    memcpy(selectionsortArray, a, arrayLength * sizeof(int));
    selectionsort(selectionsortArray, arrayLength);

    return 0;
}

