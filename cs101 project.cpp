//CS PROJECT
//2023482 MUHAMMAD NABEEGH
//2023425 MUHAMMAD HAMZA KHAN
//2023447 MUHAMMAD IBRAHIM KHAN
//username = project
//password = giki
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>   

const int MAX_EMPLOYEES = 100;

using namespace std;

bool authenticate() {
    string username, password;
    const string expectedUsername = "project";
    const string expectedPassword = "giki";

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    return (username == expectedUsername && password == expectedPassword);
}


void attendanceManagement(int ids[], const string names[], bool attendanceStatus[], int count) {
    int choice;

    do {
        cout << "\n0. GO BACK" << endl; 
        cout << "1. Mark attendance for employee" << endl;
        cout << "2. Update attendance for employee" << endl;
        cout << "3. Display attendance for employee" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) {
            break;
        }

        int id, i;
        cout << "Enter employee ID: ";
        cin >> id;

        for (i = 0; i < count; ++i) {
            if (ids[i] == id) {
                break;
            }
        }

        if (i == count) {
            cout << "Employee not found." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                attendanceStatus[i] = true;
                cout << "Attendance marked for " << names[i] << "." << endl;
                break;
            case 2:
                attendanceStatus[i] = true;
                cout << "Attendance updated for " << names[i] << "." << endl;
                break;
            case 3:
                cout << "Attendance for " << names[i] << ": " << (attendanceStatus[i] ? "Present" : "Absent") << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 3);
}

void SalaryManagement(int ids[], const string names[], double salaries[], int count) {
    int choice;

    do {
        cout << "\n0. GO BACK" << endl;
        cout << "1. Add salary for employee" << endl;
        cout << "2. Update salary for employee" << endl;
        cout << "3. Display salary for employee" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) {
            break;
        }

        int id, i;
        cout << "Enter employee ID: ";
        cin >> id;

        for (i = 0; i < count; ++i) {
            if (ids[i] == id) {
                break;
            }
        }

        if (i == count) {
            cout << "Employee not found." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter salary: ";
                cin >> salaries[i];
                cout << "Salary added for " << names[i] << "." << endl;
                break;
            case 2:
                cout << "Enter salary: ";
                cin >> salaries[i];
                cout << "Salary updated for " << names[i] << "." << endl;
                break;
            case 3:
                cout << "Salary for " << names[i] << ": " << salaries[i] << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 3);
}
void displaySalarySheet(const int ids[], const string names[], const double salaries[], const bool leaveStatus[], int count) {
    cout << setw(5) << "ID" << setw(20) << "Name" << setw(15) << "Salary" << setw(15) << "Leave Status" << endl;
    
    for (int i = 0; i < count; ++i) {
        cout << setw(5) << ids[i] << setw(20) << names[i] << setw(15) << salaries[i] << setw(15) << (leaveStatus[i] ? "On leave" : "Not on leave") << endl;
    }
}

void displayLoadingAnimation() {
    const int animationDuration = 2;  
    const int framesPerSecond = 5; 

    clock_t start = clock();
    while ((clock() - start) / CLOCKS_PER_SEC < animationDuration) {
        for (int frame = 0; frame < framesPerSecond * animationDuration; ++frame) {
            cout << "\rLoading" << string(frame % 4, '.') << std::flush;
            clock_t delay = CLOCKS_PER_SEC / framesPerSecond;
            clock_t current = clock();
            while (clock() < current + delay) {}
        }
    }
    cout << "\rLoading complete!     \n";
}
void leaveManagement(int ids[], const string names[], bool leaveStatus[], int count) {
    int choice;

    do {
        cout << "\n0. GO BACK" << endl;
        cout << "1. Add leave status for employee" << endl;
        cout << "2. Update leave status for employee" << endl;
        cout << "3. Display leave status for employee" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) {
            
            break;
        }

        int id, i, a;
        cout << "Enter employee ID: ";
        cin >> id;

        for (i = 0; i < count; ++i) {
            if (ids[i] == id) {
                break;
            }
        }

        if (i == count) {
            cout << "Employee not found." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Number of days on leave: ";
                cin >> a;
                cout << "Leave status added for " << names[i] << "." << endl;
                break;
            case 2:
                leaveStatus[i] = true;
                cout << "Leave status updated for " << names[i] << "." << endl;
                break;
            case 3:
                cout << "Leave status for " << names[i] << ": " << (leaveStatus[i] ? "On leave" : "Not on leave") << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 3); 
}

void addEmployee(int ids[], string names[], double salaries[], int& count, string email[]) {
    int choice;

    do {
        cout << "\n0. GO BACK" << endl; 
        cout << "1. Add employee" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) {
            break;
        }

        int id;
        string name, email;
        double salary;

        cout << "Enter employee ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter employee name: ";
        getline(cin, name);
        cout << "Enter employee salary: ";
        cin >> salary;
        cout << "Enter employee email: ";
        cin >> email;

        ids[count] = id;
        names[count] = name;
        salaries[count] = salary;

        count++;

    } while (choice != 1);
}

void displayEmployees(const int ids[], const string names[], const double salaries[], int count) {
    int choice;

    do {
        cout << "\n0. GO BACK" << endl;
        cout << "1. Display employees" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) {
            break;
        }

        cout << setw(5) << "ID" << setw(10) << "Name" << setw(10) << "Salary" << endl;
        for (int i = 0; i < count; ++i) {
            cout << setw(5) << ids[i] << setw(10) << names[i] << setw(10) << salaries[i] << endl;
        }

    } while (choice != 1);
}

void saveData(const int ids[], const string names[], const double salaries[], int count) {
}

int main() {
    cout << "\n WELCOME TO EMPLOYEE MANAGEMENT SYSTEM" << endl;
    cout << "------------------------------------------" << endl;

  if (!authenticate()) {
        cout << "Authentication failed. Exiting program.\n";
        return 1;
    }

    displayLoadingAnimation();

    int employeeIDs[MAX_EMPLOYEES];
    string employeeNames[MAX_EMPLOYEES];
    double employeeSalaries[MAX_EMPLOYEES];
    string employeeEmails[MAX_EMPLOYEES];
    int employeeCount = 0;
    bool leaveStatus[MAX_EMPLOYEES];
    
    int choice;

    do {
        cout << "\n1. ADD EMPLOYEE" << endl;
        cout << "2. DISPLAY EMPLOYEES" << endl;
        cout << "3. SAVE DATA IN FILE" << endl;
        cout << "4. SALARY MANAGEMENT" << endl;
        cout << "5. LEAVE MANAGEMENT" << endl;
        cout << "6. ATTENDANCE MANAGEMENT" << endl;
        cout << "7. VIEW REPORT " << endl;
        cout << "8. EXIT" << endl;
        cout << "----------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 0:
                break;
            case 1:
                addEmployee(employeeIDs, employeeNames, employeeSalaries, employeeCount, employeeEmails);
                break;
            case 2:
                displayEmployees(employeeIDs, employeeNames, employeeSalaries, employeeCount);
                break;
            case 3:
                saveData(employeeIDs, employeeNames, employeeSalaries, employeeCount);
                cout << "Data saved to employee_data.txt.\n";
                break;   
            case 4:
                SalaryManagement(employeeIDs, employeeNames, employeeSalaries, employeeCount);
                break;
            case 5:
                leaveManagement(employeeIDs, employeeNames, leaveStatus, employeeCount);
                break;
            case 6:
                attendanceManagement(employeeIDs, employeeNames, leaveStatus, employeeCount);
                break;
            case 7:
            displaySalarySheet(employeeIDs, employeeNames, employeeSalaries, leaveStatus, employeeCount);
                break;
            case 8:
                 cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
