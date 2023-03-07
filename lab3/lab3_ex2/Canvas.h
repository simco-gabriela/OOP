#ifndef CANVAS_H_INCLUDED
#define CANVAS_H_INCLUDED
#pragma once

class Canvas
{
private:
    int m_width;
    int m_height;
    char **m_matrix;

public:
    Canvas(int width, int height);
    ~Canvas();

    void DrawCircle(int x, int y, int ray, char ch);
    void FillCircle(int x, int y, int ray, char ch);
    void DrawRect(int left, int top, int right, int bottom, char ch);
    void FillRect(int left, int top, int right, int bottom, char ch);
    void SetPoint(int x, int y, char ch);
    void DrawLine(int x1, int y1, int x2, int y2, char ch);
    void Print();
    void Clear();
};


#endif // CANVAS_H_INCLUDED
