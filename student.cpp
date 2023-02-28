#include "student.h"


using namespace std;

Student::Student() :
name_(""),
mathGrade_(0),
engGrade_(0),
histGrade_(0)
{}



Student::Student(string name, float mathGrade, float engGrade, float histGrade) :
name_(name),
mathGrade_(mathGrade),
engGrade_(engGrade),
histGrade_(histGrade)
{}

void Student::setName(string name) {
name_ = name;
}

string Student::getName() const {
return name_;
}

void Student::setMathGrade(float mathGrade) {
mathGrade_ = mathGrade;
}

float Student::getMathGrade() const {
return mathGrade_;
}

void Student::setEngGrade(float engGrade) {
engGrade_ = engGrade;
}

float Student::getEngGrade() const {
return engGrade_;
}

void Student::setHistGrade(float histGrade) {
histGrade_ = histGrade;
}

float Student::getHistGrade() const {
return histGrade_;
}

float Student::getAverage() const {
return (mathGrade_ + engGrade_ + histGrade_) / 3.0;
}
