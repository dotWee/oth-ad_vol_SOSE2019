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

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quicksort_r(int *begin, int *end)
{
    int *ptr;
    int *split;
    if (end - begin <= 1)
        return;

    ptr = begin;
    split = begin + 1;
    while (++ptr <= end) {
        if (*ptr < *begin) {
            swap(ptr, split);
            ++split;
        }
    }
    swap(begin, split - 1);
    quicksort_r(begin, split - 1);
    quicksort_r(split, end);
}

void quicksort(int *array, int length) {
    string logTag = "Quicksort";
    printHeader(logTag);

    long timestamp = timeInMilliseconds();

    // select random index
    int randomPosition = std::rand() % (length - 1);
    int *randomValue = &array[randomPosition];

    cout << logTag << ": Zufälliges Pivot-Element - position=" 
        << randomPosition << " value=" << *randomValue << endl;

    quicksort_r(&array[0], randomValue);
//    quicksort_r(&array[rand() % length], &array[length - 1]);

    printFooter(logTag, timestamp, array, length);
}

int main (int argc, char *argv[]) {

    int arrayLength = sizeof(a) / sizeof(a[0]);
    
    int quicksortArray[arrayLength];
    memcpy(quicksortArray, a, arrayLength * sizeof(int));
    quicksort(quicksortArray, arrayLength);

    return 0;
}

