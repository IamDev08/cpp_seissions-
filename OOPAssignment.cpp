#include <iostream>
#include <string>
using namespace std;

// Exercise 1, 2, 3, 4 - Student
class Student {
private:
    string name;
    int age;
    string course;

public:
    // Exercise 4: Parameterized Constructor
    Student(string name, int age, string course) {
        this->name = name;
        this->age = age;
        this->course = course;
    }

    // Exercise 3: Display Method
    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Course: " << course << endl;
        cout << endl;
    }
};


// Exercise 5 - Employee
class Employee {
private:
    int id;
    string name;
    double salary;
    string department;

public:
    Employee(int id, string name, double salary, string department) {
        this->id = id;
        this->name = name;
        this->salary = salary;
        this->department = department;
    }

    void display() {
        cout << "Employee ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "Department: " << department << endl;
        cout << endl;
    }
};


// Exercise 6 - BankAccount
class BankAccount {
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    BankAccount(string accountNumber, string accountHolder, double balance) {
        this->accountNumber = accountNumber;
        this->accountHolder = accountHolder;
        this->balance = balance;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: " << balance << endl;
        cout << endl;
    }
};


int main() {

    // Exercise 1 - Basic Class
    cout << "===== EXERCISE 1 =====" << endl;

    Student s1("Dev", 21, "Computer Science");
    s1.display();


    // Exercise 2 - Multiple Objects
    cout << "===== EXERCISE 2 =====" << endl;

    Student s2("Rahul", 20, "Information Technology");
    Student s3("Aman", 22, "Artificial Intelligence");

    s1.display();
    s2.display();
    s3.display();


    // Exercise 3 - Method
    cout << "===== EXERCISE 3 =====" << endl;

    s1.display();


    // Exercise 4 - Constructor
    cout << "===== EXERCISE 4 =====" << endl;

    Student s4("Priya", 21, "Data Science");
    s4.display();


    // Exercise 5 - Employee
    cout << "===== EXERCISE 5 =====" << endl;

    Employee e1(101, "Dev", 45000, "IT");
    e1.display();


    // Exercise 6 - BankAccount
    cout << "===== EXERCISE 6 =====" << endl;

    BankAccount account("ACC1001", "Dev Raut", 10000);

    account.display();

    account.deposit(5000);
    account.withdraw(2000);

    cout << "Final Account Details:" << endl;
    account.display();

    return 0;
}