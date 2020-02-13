#include <string>
#include <stdexcept>
#include <iostream>
#include <map>
#include "Student.h"

using namespace std;

Student::Student(const string &name, int regNo) : Person() {
    this->name = name;
    this->regNo = regNo;
}

int Student::getRegNo() const {
    return this->regNo;
}

void Student::addMark(const string &module, float mark) {
    try{
        this->marks.at(module) = mark;
    }catch(out_of_range){
        this->marks.insert(pair<string, float>(module, mark));
    }
}

float Student::getMark(const string &module) const throw(NoMarkException){
    for (pair<string, float> mark : this->marks) {
        if (mark.first == module) {
            return mark.second;
        } else {
            throw NoMarkException();
        }
    }
    throw NoMarkException();
}

ostream &operator<<(ostream &str, const Student &s) {
    str << "[" << s.getRegNo() << "]: " << s.getName();
    return str;
}

map<string, float> Student::getMarks() {
    return this->marks;
}
