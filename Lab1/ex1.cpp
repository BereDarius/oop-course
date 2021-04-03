#include <cstdio>
#include <iostream>
using namespace std;

/*string decrypt(const string& text, int n) {
    if (n == 0 || n == 26) {
        return text;
    } else if (n < 0) {
        n = 26 + n;
    } else if (n > 26) {
        n = 26 - n;
    }
    string result = "";
    const string lowerAlphabet = "abcdefghijklmnopqrstuvwxyz";
    const string upperAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (char c : text) {
        if (lowerAlphabet.find(c) != string::npos || upperAlphabet.find(c) != string::npos) {
            if (islower(c)) {
                if (lowerAlphabet.find(c) + n >= 26) {
                    result += lowerAlphabet[lowerAlphabet.find(c) + n - 26];
                } else {
                    result += lowerAlphabet[lowerAlphabet.find(c) + n];
                }
            } else if (isupper(c)) {
                if (upperAlphabet.find(c) + n >= 26) {
                    result += upperAlphabet[upperAlphabet.find(c) + n - 26];
                } else {
                    result += upperAlphabet[upperAlphabet.find(c) + n];
                }
            }
        } else {
            result += c;
        }
    }
    return result;
}*/

int main() {
    /*
     * EXERCISE 1
     */

    /*char name[100];
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello, %s!", name);*/

    /*
     * EXERCISE 2
     */

    /*int i = 9, j = 8, k = 7, l = 6;
    for (i = 9; i > j; i--) {
        for (j = i - 1; j > k; j--) {
            for (k = j - 1; k > l; k--) {
                l = 24 - (i + j + k);
                if (i + j + k + l == 24) {
                    cout << to_string(i) + to_string(j) + to_string(k) + to_string(l) << endl;
                }
            }
        }
    }*/

    /*
     * EXERCISE 3
     */

    /*struct DATE {
        int day;
        string month;
        int year;
    } date;

    int year;

    cout << "Please enter the year: ";
    cin >> year;
    date.year = year;

    int A = year % 19;
    int B = year % 4;
    int C = year % 7;
    int D = (19 * A + 24) % 30;
    int E = (2 * B + 4 * C + 6 * D + 5) % 7;

    date.day = 22 + E + D;

    if (date.day > 31) {
        date.month = "April";
        date.day = date.day - 31;
    } else {
        date.month = "March";
    }

    cout << date.day << " " << date.month << " " << date.year;

    return 0;*/

    /*string message;
    int num;
    cout << "Please enter the message to be decrypted: ";
    getline(cin, message);
    cout << endl << "Please enter the number: ";
    cin >> num;
    cout << endl << decrypt(message, -num);*/

}
