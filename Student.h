#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include<iostream>
#include<string>

using namespace std;

class Student
{
private:
    unsigned long long FN;
    string FirstName, LastName;
    int Grade;
public:
    Student(unsigned long long =0, string = "", string = "");

    unsigned long long getFN() const;
    string getFirstName() const;
    string getLastName() const;
    void setFN(const unsigned long long);
    void setFirstName(const string);
    void setLastName(const string);

    friend bool operator<(const Student&, const Student&);
    friend bool operator==(Student&, const Student&);

	friend ostream& operator<<(ostream&, const Student&);
	friend istream& operator>>(istream&, Student&);
};

Student::Student(unsigned long long fn, string fname, string lname)
{
	FN = fn;
	FirstName = fname;
	LastName = lname;
}

unsigned long long Student::getFN() const
{
    return FN;
}
string Student::getFirstName() const
{
	return FirstName;
}
string Student::getLastName() const
{
	return LastName;
}

void Student::setFN(const unsigned long long fn)
{
    FN = fn;
    return;
}
void Student::setFirstName(const string fname)
{
    FirstName = fname;
    return;
}
void Student::setLastName(const string lname)
{
    LastName = lname;
    return;
}

bool operator<(const Student& st1, const Student& st2)
{
    return (st1.FN < st2.FN);
}
bool operator==(Student& st1, const Student&st2)
{
    return (st1.FN == st2.FN);
}

ostream& operator<<(ostream & os, const Student & obj)
{
	os << obj.FN << ' ' << obj.FirstName << ' ' << obj.LastName << '\n';
	return os;
}

istream& operator>>(istream& is, Student& obj)
{
	is >> obj.FN >> obj.FirstName >> obj.LastName;
	return is;
}


#endif // STUDENT_H_INCLUDED
