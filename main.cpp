#include <iostream>
#include <string.h>

using namespace std;

int comparare(char* a, char* b) {
    if (strlen(a) != strlen(b)) {
        return strlen(b) - strlen(a);
    } else {
        return strcmp(a, b);
    }
}


int main() {
    cout<<"Introduceti o propozitie: "<<endl;
    char input[100];
    scanf("%[^\n]", input);

    char* words[100];
    int contor = 0;
    char* token = strtok(input, " ");
    while (token != nullptr) {
        words[contor++] = token;
        token = strtok(nullptr, " ");
    }

    char* aux;

 for (int i = 0; i < contor-1; i++) {
        for (int j = i + 1; j < contor; j++) {
            if (comparare(words[i], words[j]) > 0) {
                aux = words[i];
                words[i] = words[j];
                words[j] = aux;
            }
        }
    }

    for (int i = 0; i < contor; i++) {
        cout<<words[i]<<endl;
    }

    return 0;
}
