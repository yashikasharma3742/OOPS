#include <iostream>
#include <vector>
#include <algorithm> // Needed for reverse

using namespace std;

vector<int> decimalToBinary(int decimalNumber) {
    vector<int> binary;
    while (decimalNumber > 0) {
        binary.push_back(decimalNumber % 2);
        decimalNumber /= 2;
    }

    if (binary.empty()) {
        binary.push_back(0);
    }

    reverse(binary.begin(), binary.end());
    return binary;
}

int main() {
    int decimalInput;
    cout << "Enter a decimal number: ";
    cin >> decimalInput;

    vector<int> binary = decimalToBinary(decimalInput);

    cout << "Binary representation: ";
    for (int digit : binary) {
        cout << digit;
    }
    cout << endl;

    return 0;
}
