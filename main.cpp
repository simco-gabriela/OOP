#include <iostream>
#include "student.h"
#include "global_functions.h"

int main() {
    string nume1, nume2;
    cin>>nume1;
    float nota_m1, nota_m2, nota_eng1, nota_eng2, nota_ist1, nota_ist2;
    cin>>nota_m1>>nota_eng1>>nota_ist1;
    cin>>nota_m2>>nota_eng2>>nota_ist2;
 Student student1(nume1, nota_m1, nota_eng1, nota_ist1);
 Student student2(nume2, nota_m2, nota_eng2, nota_ist2);

  cout << "Media primului student: " << student1.getAverage() << endl;
  cout << "Media studentului al doilea: " << student2.getAverage() << endl;

  cout << "Comparare dupa nume: " << compareByName(student1, student2) << endl;
  cout << "Comparare dupa nota la matematica: " << compareByMathGrade(student1, student2) << endl;
  cout << "Comparare dupa nota la engleza: " << compareByEngGrade(student1, student2) << endl;
  cout << "Comparare dupa nota la istorie: " << compareByHistGrade(student1, student2) << endl;
  cout << "Comparare dupa medie: " << compareByAverage(student1, student2) << endl;

  return 0;
}
