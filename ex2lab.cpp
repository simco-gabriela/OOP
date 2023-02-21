#include <iostream>

using namespace std;

int string_converter(char* str) {
    int num = 0;
    int semn = 1;
    if (*str == '-') {
        semn = -1;
        str++;
    }
    while (*str >= '0' && *str <= '9') {
        num = num * 10 + (*str - '0');
        str++;
    }
    return num * semn;
}

int main() {
    FILE* file = fopen("in.txt", "r");
    int sum = 0;
    char buffer[100];
    while (fgets(buffer, 100, file) != nullptr) {
        sum += string_converter(buffer);
    }
    fclose(file);
    cout<<"Suma numerelor este: "<<sum<<endl;
    return 0;
}
