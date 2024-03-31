 #include <iostream>

class MyClass {
private:
    int value;

public:
    
    MyClass(int val) : value(val) {}

    
    int getValue() const {
        return value;
    }

   
    friend MyClass operator+(const MyClass& obj1, const MyClass& obj2);

   
    friend MyClass operator-(const MyClass& obj1, const MyClass& obj2);
};


MyClass operator+(const MyClass& obj1, const MyClass& obj2) {
  
    int resultValue = obj1.value + obj2.value;
    return MyClass(resultValue);
}


MyClass operator-(const MyClass& obj1, const MyClass& obj2) {
    
    int resultValue = obj1.value - obj2.value;
    return MyClass(resultValue);
}

int main() {
    MyClass obj1(55);
    MyClass obj2(3);

    
    MyClass sum = obj1 + obj2;
    std::cout << "Sum: " << sum.getValue() << std::endl;

    
    MyClass difference = obj1 - obj2;
    std::cout << "Difference: " << difference.getValue() << std::endl;

    return 0;
}

