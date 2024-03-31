#include <iostream>
class max;
using namespace std;


int maximum(int *a, int *b, int *c) {
    int max = *a;
    if (*b > max) {
        max = *b;
    }
    if (*c > max) {
        max = *c;
    }
    return max;
}

int main() {
    int num1, num2, num3;

    
    std::cout << "Enter three integers: ";
    std::cin >> num1 >> num2 >> num3;

    
    int max = maximum(&num1, &num2, &num3);

    
    std::cout << "Maximum number among " << num1 << ", " << num2 << ", and " << num3 << " is: " << max << std::endl;

    return 0;
}


