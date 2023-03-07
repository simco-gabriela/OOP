#include <iostream>
#include <cmath>
#include "Canvas.h"

using namespace std;


Canvas::Canvas(int width, int height)
{
    m_width = width;
    m_height = height;
    m_matrix = new char* [height];
    for (int i = 0; i < height; i++)
    {
        m_matrix[i] = new char[width];
        for (int j = 0; j < width; j++)
        {
            m_matrix[i][j] = '.';
        }
    }
}


Canvas::~Canvas()
{
    for (int i = 0; i < m_height; i++)
        delete[] m_matrix[i];
    delete[] m_matrix;
}
//
//const char V_LINE = '|';
//const char H_LINE = '-';

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    int x1 = x - ray, x2 = x + ray;
    int y1 = y - ray, y2 = y + ray;
    double r2 = pow(ray, 2);
    for (int i = x1; i <= x2; i++)
    {
        int j = y + round(sqrt(r2 - pow(i - x, 2)));
        if (j >= y1 && j <= y2)
            SetPoint(i, j, ch);
        j = y - round(sqrt(r2 - pow(i - x, 2)));
        if (j >= y1 && j <= y2)
            SetPoint(i, j, ch);
    }
    for (int j = y1; j <= y2; j++)
    {
        int i = x + round(sqrt(r2 - pow(j - y, 2)));
        if (i >= x1 && i <= x2)
            SetPoint(i, j, ch);
        i = x - round(sqrt(r2 - pow(j - y, 2)));
        if (i >= x1 && i <= x2)
            SetPoint(i, j, ch);
    }
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    int x1 = x - ray, x2 = x + ray;
    int y1 = y - ray, y2 = y + ray;
    for (int i = x1; i <= x2; i++)
    {
        for (int j = y1; j <= y2; j++)
        {
            if (pow(i - x, 2) + pow(j - y, 2) <= pow(ray, 2))
                SetPoint(i, j, ch);
        }
    }
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
    DrawLine(left, top, right, top, ch);
    DrawLine(left, bottom, right, bottom, ch);
    DrawLine(left, top, left, bottom, ch);
    DrawLine(right, top, right, bottom, ch);
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
    for (int i = left + 1; i < right; i++)
    {
        for (int j = top + 1; j < bottom; j++)
        {
            SetPoint(i, j, ch);
        }
    }
}


void Canvas::SetPoint(int x, int y, char ch)
{
    if (x >= 0 && x < m_width && y >= 0 && y < m_height)
        m_matrix[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = x1<x2 ? 1: -1;
    int sy = y1<y2 ? 1: -1;
    int err = dx - dy;
    while (true)
    {
        SetPoint(x1, y1, ch);
        if (x1 == x2 && y1 == y2)
            break;
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

void Canvas::Print()
{
    for (int i = 0; i < m_height; i++)
    {
        for (int j = 0; j < m_width; j++)
        {
            std::cout << m_matrix[i][j];
        }
        std::cout << std::endl;
    }
}


void Canvas::Clear()
{
    for (int i = 0; i < m_height; i++)
        for (int j = 0; j < m_width; j++)
            m_matrix[i][j] = ' ';
}



