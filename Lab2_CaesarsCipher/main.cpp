#include <iostream>

using namespace std;

string decrypt(const string& text, int n) {
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
}

void breakCipher() {
    cout << "Please enter the text: " << endl;
    string text;
    getline(cin, text);
    cout << endl;
    int i = 0;
    string response;
    cout << decrypt(text, i) << endl;
    cout << "Is the text intelligible? " << endl;
    getline(cin, response);
    while (response == "NO" ||
           response == "No" ||
           response == "nO" ||
           response == "no" ||
           response == "N" ||
           response == "n") {
        if (i == 26) {
            break;
        }
        i++;
        cout << decrypt(text, i) << endl;
        cout << "Is the text intelligible? " << endl;
        getline(cin, response);
    }
    if (i == 26) {
        cout << "No intelligible possibility found...";
    }
    cout << "Decrypted";
}

int main() {
    breakCipher();
    return 0;
}
