//Codul cu erori voite primit de la colegul din grup, corectat:     
#include <iostream>
#include <list>
using namespace std;
template <typename T>
list<T> Sort(list<T> l)
{
    list<T> copie;
    typename list<T>::iterator it1;
    typename list<T>::iterator it;
    copie.push_back(*l.begin()); //era copie.push_back(l.begin());
    it = l.begin();
    /*am adaugat: */ it++;
    for (it; it != l.end(); it++)
        //  Eroare logică : În interiorul buclei for (it; it != l.end(); it++), iteratiile se fac cu un iterator it, dar comparatiile 
           //sunt făcute între iteratorul it și iteratori din lista copie.
    {
        int ok = 0;
        for (it1 = copie.begin(); it1 != copie.end(); it1++) //
             if (*it < *it1) 
                 //Trebuie să se fi comparat valorile la care se referă iteratorii folosind operatorul*, astfel : if (*it < *it1).

            {
                //cout << "x"; //Eroare : printeaza un x fara rost 
                copie.insert(it1, *it); // era copie.insert(it1, it); 
                ok = 1;
                break;
             } 

        if (ok == 0)
            copie.push_back(*it); // era copie.push_back(it);
   
       // else if (ok == 1)
       //     copie.push_back(3); //se adauga valoarea 3 in copie, se adauga un element de tip int dar copia e de tip T
    }
    return copie;
}

int main()
{
    list<int> a = { 3, 1, 3, 3, 5, 6 };
    list<int>::iterator it;
    for (it = a.begin(); it != a.end(); it++)
        printf("%d ", *it); //ar fi trebuit sa fie *it, trebuie de utlizat dereferentierea pentru a obtine valoarea iteratorului
    cout << endl;
    a = Sort(a); 
    for (it = a.begin(); it != a.end(); it++)
        printf("%d ", *it);
    cout << endl;
    //nu este return 0;
}
