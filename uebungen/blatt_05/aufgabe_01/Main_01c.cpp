#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void printvector(vector<int> input)
{
    for (int index = 0; index < input.size(); ++index)
    {
        cout << input.at(index) << " ";
    }
    cout << endl;
}

void mergesort(int *input, int left, int right, int *target)
{
    if (right == left + 1)
    {
        return;
    }

    else
    {
        int length = right - left;
        int distance = length / 2;

        int left2 = left, right2 = left + distance;
        mergesort(input, left, left + distance, target);
        mergesort(input, left + distance, right, target);

        int index = 0;
        for (index = 0; index < length; index++)
        {

            int larget;
            if (input[left2] > input[right2])
            {
                larget = left2;
            }
            else
            {
                larget = right2;
            }

            if (left2 < left + distance && (right2 == right || max(input[left2], input[right2]) == input[left2]))
            {
                target[index] = input[left2];
                left2++;
            }
            else
            {
                target[index] = input[right2];
                right2++;
            }
        }

        for (index = left; index < right; index++)
        {
            input[index] = target[index - left];
        }
    }
}

void execmergesort(vector<int> input)
{
    cout << "Input MergeSort:  ";
    printvector(input);

    int target[input.size()];
    mergesort(&input[0], 0, input.size(), target);

    cout << "Result MergeSort: ";
    printvector(input);
}

void heapsort(int *input, int size, int index)
{
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && input[left] > input[largest])
    {
        largest = left;
    }

    if (right < size && input[right] > input[largest])
    {
        largest = right;
    }

    if (largest != index)
    {
        swap(input[index], input[largest]);

        heapsort(input, size, largest);
    }
}

void execheapsort(vector<int> input)
{
    cout << "Input HeapSort:  ";
    printvector(input);

    int size = input.size();

    for (int index = size / 2 - 1; index >= 0; index--)
    {
        heapsort(&input[0], size, index);
    }

    for (int index = size - 1; index >= 0; index--)
    {
        swap(input[0], input[index]);

        heapsort(&input[0], index, 0);
    }

    cout << "Result HeapSort: ";
    printvector(input);
}

int main(int argc, char *argv[])
{

    // Define input
    int arr[] = {-5, 13, -32, 7, -3, 17, 23, 12, -35, 19};
    vector<int> input(begin(arr), end(arr));

    // Mergesort
    vector<int> inputMergesort(input);
    execmergesort(inputMergesort);

    // Heapsort
    vector<int> inputHeapsort(input);
    execheapsort(inputHeapsort);

    return 0;
}
