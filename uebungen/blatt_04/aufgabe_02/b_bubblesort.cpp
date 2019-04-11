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

void bubblesort(int *array, int length) {
    string logTag = "Bubblesort";
    printHeader(logTag);    
    
    long timestamp = timeInMilliseconds();

    int x, y;
    for (x = 0; x < length - 1; ++x) {
       for (y = 0; y < length - x - 1; ++y) {
           if (array[y] <= array[y + 1]) {
               int temp = array[y];
               array[y] = array[y + 1];
               array[y + 1] = temp;
           }
       }
    }

    printFooter(logTag, timestamp, array, length);
}

int main (int argc, char *argv[]) {

    int arrayLength = sizeof(a) / sizeof(a[0]);
    
    int bubblesortArray[arrayLength];
    memcpy(bubblesortArray, a, arrayLength * sizeof(int));
    bubblesort(bubblesortArray, arrayLength);

    return 0;
}

