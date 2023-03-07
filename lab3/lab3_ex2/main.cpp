#include "Canvas.h"
#include <iostream>

using namespace std;

int main()
{
    Canvas canvas(40, 20);
// canvas.DrawCircle(10, 10, 6, '*');
//    canvas.FillCircle(10, 10, 6, '#');
//    canvas.DrawRect(2, 2, 18, 8, '-');
//    canvas.FillRect(2, 2, 18, 8, '+');
// canvas.DrawLine(5, 15, 35, 15, '-');
    canvas.Print();

 //  canvas.Clear();
//    canvas.DrawCircle(20, 10, 8, '*');
//    canvas.FillCircle(20, 10, 5, '#');
//    canvas.DrawRect(5, 5, 35, 15, '-');
//    canvas.FillRect(10, 8, 30, 12, '+');
//    canvas.DrawLine(1, 1, 12, 12, '=');
//    canvas.Print();

    return 0;
}

