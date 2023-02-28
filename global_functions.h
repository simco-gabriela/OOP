#ifndef GLOBAL_FUNCTIONS_H_INCLUDED
#define GLOBAL_FUNCTIONS_H_INCLUDED
#include "student.h"

using namespace std;

int compareByName(const Student& s1, const Student& s2);
int compareByMathGrade(const Student& s1, const Student& s2);
int compareByEngGrade(const Student& s1, const Student& s2);
int compareByHistGrade(const Student& s1, const Student& s2);
int compareByAverage(const Student& s1, const Student& s2);

#endif // GLOBAL_FUNCTIONS_H_INCLUDED
