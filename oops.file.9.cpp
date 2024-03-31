include <iostream>

class StringOperation {
private:
    std::string str;

public:
    
    StringOperation(const std::string& s) : str(s) {}

    
    int findLength() {
        int length = 0;
        while (str[length] != '\0') {
            length++;
        }
        return length;
    }

    
    std::string findReverse() {
        std::string reversedStr;
        int length = findLength();
        for (int i = length - 1; i >= 0; i--) {
            reversedStr += str[i];
        }
        return reversedStr;
    }

   
    std::string concatenate(const std::string& otherStr) {
        std::string concatenatedStr = str;
        int length = findLength();
        int otherLength = otherStr.length();
        for (int i = 0; i < otherLength; i++) {
            concatenatedStr += otherStr[i];
        }
        return concatenatedStr;
    }

    
    bool compare(const std::string& otherStr) {
        int length = findLength();
        int otherLength = otherStr.length();
        if (length != otherLength) {
            return false;
        }
        for (int i = 0; i < length; i++) {
            if (str[i] != otherStr[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::string inputStr1, inputStr2;
    std::cout << "Enter first string: ";
    std::cin >> inputStr1;
    std::cout << "Enter second string: ";
    std::cin >> inputStr2;

    StringOperation strOp1(inputStr1);
    StringOperation strOp2(inputStr2);

   
    std::cout << "Length of the first string: " << strOp1.findLength() << std::endl;

    
    std::cout << "Reverse of the first string: " << strOp1.findReverse() << std::endl;

    
    std::cout << "Concatenated string: " << strOp1.concatenate(inputStr2) << std::endl;

   
    if (strOp1.compare(inputStr2)) {
        std::cout << "The two strings are equal." << std::endl;
    } else {
        std::cout << "The two strings are not equal." << std::endl;
    }

    return 0;
}

