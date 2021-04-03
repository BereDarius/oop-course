#include <cmath>
#include <iostream>

using namespace std;

struct Indices {
    int firstIndex;
    int secondIndex;
};

bool cmp(float e1, float e2) {
    return e1 >= e2;
}

float sigmoid(float x) {
    /**
     * Function that returns the value of sigmoid(x)
     * INPUT: x - float
     * OUTPUT: result - float
     */
    return 1 / (1 + exp(-x));
}

Indices smileDetector(const float * array, int len, float threshold, bool (*compare)(float, float)) {
    /**
     * Function that takes in an array of float values (frames), the length of the array and a threshold and returns the
     * longest contiguous subsequence int the array, where the threshold is smaller than or equal to the array's value
     * at that point (probability of smiling is greater than or equal to the threshold)
     * INPUT: array - float[]
     *        len - int
     *        threshold - float
     * OUTPUT: result - Indices
     *
     * Indices - structure that is contained of two integer values:
     *                  - first index
     *                  - second index
     */
    float sigmArr[len];
    for (int i = 0; i < len; i++) {
        sigmArr[i] = sigmoid(array[i]);
    }
    int i = 0, j = 0, count = 0, maxCount = 0, index1, index2;
    while (j < len - 1) {
        if (compare(sigmArr[j], threshold)) {
            count++;
            j++;
        } else {
            j++;
            i = j;
        }
        if (count > maxCount) {
            maxCount = count;
            index1 = i;
            index2 = j;
        }
    }
    if (maxCount == 0) {
        index1 = -1;
        index2 = -1;
    }
    Indices result = { index1, index2 };
    return result;
}

void printMenu() {
    /**
     * Function that prints the menu to the user
     * INPUT: -
     * OUTPUT: -
     */
    cout << "1. Sigmoid;" << endl << "2. Smile Detector;" << endl << "0. Exit;" << endl;
}

void callSigmoid() {
    /**
     * Function that calls the sigmoid function, prompts the user for the needed arguments
     * INPUT: -
     * OUTPUT: -
     */
    float x;
    cout << "Please enter the value of x: ";
    cin >> x;
    cout << "sigmoid(x) = " << sigmoid(x) << endl;
}

void callSmileDetector() {
    /**
     * Function that calls the smileDetector function, prompts the user for the needed arguments
     * INPUT: -
     * OUTPUT: -
     */
    int len;
    cout << "How many frames are there in the array? ";
    cin >> len;
    if (len <= 0) {
        throw;
    }
    float arr[len];
    cout << endl;
    float value;
    for (int i = 0; i < len; i++) {
        cout << "Please enter the value of frame " << i + 1 << ": ";
        cin >> value;
        cout << endl;
        arr[i] = value;
    }
    float th;
    cout << "Please enter the threshold: ";
    cin >> th;
    cout << endl;
    Indices sd = smileDetector(arr, len, th, cmp);
    cout << "Starting index: " << sd.firstIndex << endl << "Second index: " << sd.secondIndex << endl;
}

void callExit() {
    /**
     * Function that is called before ending the program
     * INPUT: -
     * OUTPUT: -
     */
    cout << "Goodbye!! :)" << endl;
}

int readInput() {
    /**
     * Function that prompts the user for an integer for choosing an item from the menu
     * INPUT: -
     * OUTPUT: result - int
     */
    cout << "Please enter your option: ";
    int res;
    cin >> res;
    cout << endl;
    return res;
}

int main() {
    /*cout << "Array 1 = {-6, -4, -2, 0, 2, 4, 6}" << endl;
    const float arr1[7] = {-6, -4, -2, 0, 2, 4, 6};
    const int len1 = sizeof(arr1) / sizeof(*arr1);
    Indices res1 = smileDetector(arr1, len1, 0.5);
    cout << res1.firstIndex << " " << res1.secondIndex << endl;

    cout << "Array 2 = {-6, -4, -2, 0, 2, 4, 6}" << endl;
    const float arr2[7] = {-6, -4, -2, 0, 2, 4, 6};
    const int len2 = sizeof(arr2) / sizeof(*arr2);
    Indices res2 = smileDetector(arr2, len2, 0);
    cout << res2.firstIndex << " " << res2.secondIndex << endl;

    cout << "Array 3 = {-6, -4, -2, -2, -4, -6}" << endl;
    const float arr3[6] = {-6, -4, -2, -2, -4, -6};
    const int len3 = sizeof(arr3) / sizeof(*arr3);
    Indices res3 = smileDetector(arr3, len3, 0.5);
    cout << res3.firstIndex << " " << res3.secondIndex << endl;

    cout << "Array 4 = {0, 6, 4, 0, 2, 4, 6}" << endl;
    const float arr4[7] = {0, 6, 4, 0, 2, 4, 6};
    const int len4 = sizeof(arr4) / sizeof(*arr4);
    Indices res4 = smileDetector(arr4, len4, 0.5);
    cout << res4.firstIndex << " " << res4.secondIndex << endl;

    cout << "Array 5 = {-1, -1, -1, -1, -1, 5, 6}" << endl;
    const float arr5[7] = {-1, -1, -1, -1, -1, 5, 6};
    const int len5 = sizeof(arr5) / sizeof(*arr5);
    Indices res5 = smileDetector(arr5, len5, 0.5);
    cout << res5.firstIndex << " " << res5.secondIndex << endl;*/

    printMenu();
    int input = readInput();

    while (input != 0) {
        switch(input) {
            case 1:
                callSigmoid();
                break;
            case 2:
                callSmileDetector();
                break;
            default:
                cout << "Please enter a valid input (0, 1 or 2)..." << endl;
        }
        input = readInput();
    }
    callExit();

    return 0;
}
