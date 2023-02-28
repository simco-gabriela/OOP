#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED
#include <string>

using namespace std;

class Student {
public:
Student();
Student(string name, float mathGrade, float engGrade, float historyGrade);
void setName(string name);
string getName() const;
void setMathGrade(float grade);
float getMathGrade() const;
void setEngGrade(float grade);
float getEngGrade() const;
void setHistGrade(float grade);
float getHistGrade() const;
float getAverage() const;

private:
string name_;
float mathGrade_;
float engGrade_;
float histGrade_;
};


#endif // STUDENT_H_INCLUDED
