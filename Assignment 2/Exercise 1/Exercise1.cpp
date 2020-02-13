#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include "Student.h"

using namespace std;

vector<Student> getStudents(ifstream &inputFile){
    vector<Student> students;

    for(string line; getline(inputFile, line);){
        string regNo = line.substr(0, line.find(' '));
        string firstName = line.substr(regNo.size()+1, line.find(' ') +6);
        string lastName = line.substr(regNo.size() + firstName.size() + 1, 6 + firstName.size());
        string name = firstName + lastName;

        Student s = Student(name, stoi(regNo));
        cout << "Added: " << s << endl;
        students.push_back(s);
    }
    return students;
}

//reg <module, grade>
vector<pair<int, pair<string, float>>> getMarks(ifstream &inputFile){
    cout << "READ MARKS FILE START" << endl;
    vector<pair<int, pair<string, float>>> marks;

    for(string line; getline(inputFile, line);){
        string regNo = line.substr(0, 5);
        string modCode = line.substr(6, 5);
        string grade = line.substr(12, line.size());

        pair<int, pair<string, float>> markLine;
        markLine.first = stoi(regNo);
        markLine.second = pair<string, float>(modCode, stof(grade));
        marks.push_back(markLine);
    }
    cout << "READ MARKS FILE END" << endl;
    return marks;
}

vector<Student> sendMarksToStudent(vector<Student> students, vector<pair<int, pair<string, float>>> marks){
    cout << "SEND MARKS TO STUDENTS START" << endl;
    vector<Student> newStudents;
    for (Student s : students){
        Student s1 = s;
        for (pair<int, pair<string, float>> markLine : marks) {
            if (s.getRegNo() == markLine.first) {
                s1.addMark(markLine.second.first, markLine.second.second);
            }
        }
        newStudents.push_back(s1);
    }

    cout << "SEND MARKS TO STUDENTS END" << endl;
    return newStudents;
}

void viewAllStudents(vector<Student> students){
    cout << "All Students in System:- " << endl << endl;
    for(Student s: students){
        cout << s << " Module Grades:-" << endl;
        for (pair<string, float> module: s.getMarks()){
            try {
                float mark = s.getMark(module.first);
                if (mark != 0) {
                    cout << "Module " << module.first << ": " << mark << endl;
                }
            }
            catch(NoMarkException ex){
            }
        }
        cout << endl;
    }
    cout << endl << endl;
}

string mainMenu(){
    cout << "Please chose a statistic to view:- " << endl;
    cout << "[1]: Names, Minimum, Maximum and Average Marks" << endl;
    cout << "[2]: Display Student and Marks" << endl;
    cout << "[3]: Quit" << endl;
    cout << ">> ";
    string input;
    cin >> input;
    return input;
}

void choiceOne(vector<Student> students){
    cout << endl << "Please enter a mark to filter by: ";
    string input;
    cin >> input;

    //Calculate Bits
    float total = 0;
    float max = 0;
    float min = 100;
    bool foundOne = false;
    for (Student s: students){
        for (pair<string, float> m: s.getMarks()){
            if (m.second < min) min = m.second;
            if (m.second > max) max = m.second;
            total += m.second;
        }
    }
    float average = total / students.size();

    cout << "The average mark is: " << average << endl;
    cout << "The min mark is: " << min << " and the max mark is: " << max << endl;
    cout << "The students who achieved below the provided mark are:- " << endl;
    //Display them
    for (Student s: students){
        for (pair<string, float> m: s.getMarks()){
            if (m.second <= stof(input)){
                cout << s << endl;
                foundOne = true;
            }
        }
    }
    if (!foundOne){
        cout << "No students were found matching the criteria" << endl;
    }
    cout << endl << endl;
}

void choiceTwo(vector<Student> students){
    cout << endl << "Please enter a module to filter by: ";
    string module;
    cin >> module;

    cout << endl << "Please enter a mark to filter by: ";
    string mark;
    cin >> mark;

    bool foundOne = false;

    for (Student s: students){
        for (pair<string, float> marks: s.getMarks()){
            if (module == marks.first){
                if (marks.second >= stof(mark)){
                    cout << "Student: " << s << " has a mark of " << marks.second << " in the module " << module << endl;
                    foundOne = true;
                }
            }
        }
    }
    if (!foundOne){
        cout << "No students were found matching the criteria" << endl;
    }
    cout << endl << endl;
}

int main(){
    cout << endl << "Please enter your students file name: ";
    string stuFile;
    getline(cin, stuFile);
    cout << endl;
    ifstream inputFile(stuFile);
    vector<Student> students = getStudents(inputFile);

    cout << "Please enter your marks file name: ";
    string markFile;
    getline(cin, markFile);
    cout << endl;
    ifstream marksFile(markFile);
    vector<pair<int, pair<string, float>>> marks = getMarks(marksFile);

    students = sendMarksToStudent(students, marks);

    viewAllStudents(students);
    string choice = mainMenu();
    while (choice != "3"){
        if (choice == "1") choiceOne(students);
        if (choice == "2") choiceTwo(students);
        choice = mainMenu();
    }
}