// LABA-6.2.cpp
// Шах Владислав Ігорьович
// Лабораторна робота № 6.2
// Опрацювання одновимірних масивів ітераційними та рекурсивними способами
// Варіант 32 (Рекурсивний спосіб)

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

// Рекурсивне формування масиву випадковими числами
void Create(int* a, const int size, const int Low, const int High, int i)
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

// Рекурсивне виведення елементів масиву
void Print(const int* a, const int size, int i)
{
    cout << setw(5) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

// Рекурсивний пошук максимального елемента
int Max(const int* a, const int size, int i, int max)
{
    if (i >= size)
        return max;
    if (a[i] > max)
        max = a[i];
    return Max(a, size, i + 1, max);
}

// Рекурсивний пошук мінімального елемента
int Min(const int* a, const int size, int i, int min)
{
    if (i >= size)
        return min;
    if (a[i] < min)
        min = a[i];
    return Min(a, size, i + 1, min);
}

// Рекурсивна функція пошуку максимального та мінімального елементів одночасно
void MaxMin(const int* a, const int size, int i, int& max, int& min)
{
    if (i >= size)
        return;
    if (a[i] > max)
        max = a[i];
    if (a[i] < min)
        min = a[i];
    MaxMin(a, size, i + 1, max, min);
}

#ifndef UNIT_TESTING
int main()
{
    srand((unsigned)time(NULL));

    const int n = 15;
    int a[n];
    const int Low = -40;
    const int High = 50;

    cout << "Lab 6.2 (Recursive) Variant 32" << endl;
    cout << "Find maximum and minimum elements of 1D array" << endl << endl;

    Create(a, n, Low, High, 0);

    cout << "Array:" << endl;
    Print(a, n, 0);

    int maxVal = a[0];
    int minVal = a[0];
    MaxMin(a, n, 1, maxVal, minVal);

    cout << "Maximum element = " << maxVal << endl;
    cout << "Minimum element = " << minVal << endl;

    return 0;
}
#endif
