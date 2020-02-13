#ifndef _STUDENT_H_
#define _STUDENT_H_

#include <string>
#include <map>
#include <stdexcept>
#include "Person.h"

using namespace std;

class NoMarkException: public exception
{
};

class Student: public Person
{   public:
        Student(const string &name, int regNo);

		int getRegNo() const;

		void addMark(const string& module, float mark);

		float getMark(const string &module) const throw (NoMarkException);

		map<string, float> getMarks();

    private:
	   int regNo;
	   map<string, float> marks;

    friend ostream& operator<<(ostream &str, const Student &s);
};

#endif
