#include <iostream>
#include "global_functions.h"

using namespace std;

int compareByName(const Student& student1, const Student& student2) {
if (student1.getName() == student2.getName()) {
return 0;
}
else if (student1.getName() > student2.getName()) {
return 1;
}
else {
return -1;
}}

int compareByMathGrade(const Student& student1, const Student& student2) {
if (student1.getMathGrade() == student2.getMathGrade()) {
return 0;
}
else if (student1.getMathGrade() > student2.getMathGrade()) {
return 1;
}
else {
return -1;
}
}

int compareByEngGrade(const Student& student1, const Student& student2) {
if (student1.getEngGrade() == student2.getEngGrade()) {
return 0;
}
else if (student1.getEngGrade() > student2.getEngGrade()) {
return 1;
}
}

int compareByHistGrade(const Student& student1, const Student& student2) {
if (student1.getHistGrade() == student2.getHistGrade()) {
return 0;
}
else if (student1.getHistGrade() > student2.getHistGrade()) {
return 1;
}
else {
return -1;
}
}

int compareByAverage(const Student& student1, const Student& student2)
{
    if(student1.getAverage() == student2.getAverage()){
        return 0;
    }
  else if(student1.getAverage() > student2.getAverage()){
    return 1;
  }
  else return -1;
}


