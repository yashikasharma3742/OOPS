#include <iostream>
class calculateSalary;
using namespace std;


class Employee {
public:
    
    virtual double calculateSalary() const = 0;
};


class FullTimeEmployee : public Employee {
private:
    double baseSalary;
    
public:
    
    FullTimeEmployee(double salary) : baseSalary(salary) {}

    
    virtual double calculateSalary() const override {
       
        return baseSalary;
    }
};


class PartTimeEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;   

public:
   
    PartTimeEmployee(double rate, int hours) : hourlyRate(rate), hoursWorked(hours) {}

   
    virtual double calculateSalary() const override {
       
        return hourlyRate * hoursWorked;
    }
};


class Manager : public Employee {
private:
    double baseSalary;
    double bonus;      
public:
   
    Manager(double salary, double mgrBonus) : baseSalary(salary), bonus(mgrBonus) {}

    
    virtual double calculateSalary() const override {
       
        return baseSalary + bonus;
    }
};

int main() {
  
    FullTimeEmployee fullTimeEmp(5000.0);
    PartTimeEmployee partTimeEmp(20.0, 30);
    Manager manager(6000.0, 1500.0);

    
    std::cout << "Full-time employee salary: " << fullTimeEmp.calculateSalary() << std::endl;
    std::cout << "Part-time employee salary: " << partTimeEmp.calculateSalary() << std::endl;
    std::cout << "Manager salary: " << manager.calculateSalary() << std::endl;

    return 0;
}
