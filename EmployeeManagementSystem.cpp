
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Base class Employee
class Employee {
protected:
    int id;
    string name;
    string address;
    string phone;
    string email;

public:
    Employee(int id, string name, string address, string phone, string email) 
        : id(id), name(name), address(address), phone(phone), email(email) {}

    virtual double calculatePay() = 0; // Pure virtual function

    // Getters and Setters
    int getId() { return id; }
    void setId(int id) { this->id = id; }
    string getName() { return name; }
    void setName(string name) { this->name = name; }
    string getAddress() { return address; }
    void setAddress(string address) { this->address = address; }
    string getPhone() { return phone; }
    void setPhone(string phone) { this->phone = phone; }
    string getEmail() { return email; }
    void setEmail(string email) { this->email = email; }
};

// Derived class PermanentEmployee
class PermanentEmployee : public Employee {
private:
    double basicSalary;
    double hra;
    double bonus;

public:
    PermanentEmployee(int id, string name, string address, string phone, string email, double basicSalary, double hra, double bonus) 
        : Employee(id, name, address, phone, email), basicSalary(basicSalary), hra(hra), bonus(bonus) {}

    double calculatePay() override {
        return basicSalary + hra + bonus;
    }
};

// Derived class ContractEmployee
class ContractEmployee : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    ContractEmployee(int id, string name, string address, string phone, string email, double hourlyRate, int hoursWorked) 
        : Employee(id, name, address, phone, email), hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

    double calculatePay() override {
        return hourlyRate * hoursWorked;
    }
};

// Department class
class Department {
private:
    int deptId;
    string deptName;
    vector<Employee*> employees;

public:
    Department(int deptId, string deptName) 
        : deptId(deptId), deptName(deptName) {}

    void addEmployee(Employee* employee) {
        employees.push_back(employee);
    }

    void removeEmployee(Employee* employee) {
        for (auto it = employees.begin(); it != employees.end(); ++it) {
            if (*it == employee) {
                employees.erase(it);
                break;
            }
        }
    }

    // Getters and Setters
    int getDeptId() { return deptId; }
    void setDeptId(int deptId) { this->deptId = deptId; }
    string getDeptName() { return deptName; }
    void setDeptName(string deptName) { this->deptName = deptName; }
    vector<Employee*> getEmployees() { return employees; }
};

// Main function for demonstration
int main() {
    PermanentEmployee emp1(1, "John Doe", "123 Main St", "123-456-7890", "john@example.com", 5000.0, 2000.0, 500.0);
    ContractEmployee emp2(2, "Jane Smith", "456 Elm St", "987-654-3210", "jane@example.com", 50.0, 160);

    Department dept1(1, "HR");
    dept1.addEmployee(&emp1);
    dept1.addEmployee(&emp2);

    cout << "Employee ID: " << emp1.getId() << ", Name: " << emp1.getName() << ", Salary: $" << emp1.calculatePay() << endl;
    cout << "Employee ID: " << emp2.getId() << ", Name: " << emp2.getName() << ", Salary: $" << emp2.calculatePay() << endl;

    return 0;
}
