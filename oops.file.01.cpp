#include<iostream>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
#include<windows.h>
#include<cstdio>

using namespace std;

void setConsoleColor(WORD c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

class Employee
{
    char *name;
    char *designation;
    int salary;
    char *phone;
    char *city;

public:
    Employee() {
        cout << "\n Default Constructor Invoked \n";
        name = nullptr;
        designation = nullptr;
        phone = nullptr;
        city = nullptr;
    } // default Constructor

    Employee(const char *an, const char *ad, int as, const char *ap, const char *ac)
    {
        cout << "\n Parametrized Constructor Invoked \n";
        name = new char[strlen(an) + 1];
        strcpy(name, an);
        designation = new char[strlen(ad) + 1];
        strcpy(designation, ad);
        phone = new char[strlen(ap) + 1];
        strcpy(phone, ap);
        salary = as;
        city = new char[strlen(ac) + 1];
        strcpy(city, ac);
    }

    Employee(const Employee &aob)
    {
        cout << "\n Copy Constructor Invoked \n";
        name = new char[strlen(aob.name) + 1];
        strcpy(name, aob.name);
        designation = new char[strlen(aob.designation) + 1];
        strcpy(designation, aob.designation);
        phone = new char[strlen(aob.phone) + 1];
        strcpy(phone, aob.phone);
        salary = aob.salary;
        city = new char[strlen(aob.city) + 1];
        strcpy(city, aob.city);
    }

    ~Employee()
    {
        cout << "\n Destructor Invoked and resources are going to be freed";
        delete[] name;
        delete[] designation;
        delete[] city;
        delete[] phone;
    }

    void show()
    {
        setConsoleColor(FOREGROUND_BLUE);
        cout << setw(15) << left << name << "  ";
        cout << setw(13) << left << designation << "  ";
        cout << setw(8) << right << salary << " ";
        cout << setw(10) << right << phone << " ";
        cout << setw(20) << left << city << endl;
    }

    static void drawHeader()
    {
        setConsoleColor(FOREGROUND_RED);
        cout << setw(15) << left << "Name" << "  ";
        cout << setw(13) << left << "Designation" << "  ";
        cout << setw(8) << left << "Salary" << " ";
        cout << setw(10) << left << "Phone" << " ";
        cout << setw(20) << left << "City" << endl;
    }

    static void drawLine(int frequency = 74, char symbol = '-')
    {
        int i;
        setConsoleColor(FOREGROUND_GREEN);
        for (i = 0; i <= frequency; i++)
            cout << symbol;
        cout << endl;
    }

    const char *retDesignation() const
    {
        return designation;
    }

    const char *retCity() const
    {
        return city;
    }

    const char *retName() const
    {
        return name;
    }

    int retSalary() const
    {
        return salary;
    }
};

int main()
{
    int n, i;
    char empname[20], empdesig[20], empphone[20], empcity[20];
    int empsalary;
    Employee ob1("Vikas", "Professor", 120000, "9416378016", "Umbala");

    ob1.show();

    cout << " Enter Details of Employees " << endl;

    cout << "Name:  ";
    cin.getline(empname, 20);
    cout << "Designation:  ";
    cin.getline(empdesig, 20);
    cout << "Salary: ";
    cin >> empsalary;
    cout << "Phone: ";
    cin >> empphone;
    cout << "City: ";
    cin >> empcity;

    Employee ob2(empname, empdesig, empsalary, empphone, empcity);
    ob2.show();
    Employee ob3 = ob2;
    ob3.show();

    return 0;
}
