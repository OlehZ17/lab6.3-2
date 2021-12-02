#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i);
void Print(int* a, const int size, int i);
void Find(int* a, const int size, int& max, int i);

void Create(int* a, const int size, const int Low, const int High, int i) {
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
    cout << setw(5) << a[i];
    if (i < size - 1)
        Print(a, size, i + 1);
    else
        cout << endl;
}

void Find(int* a, const int size, int& max, int i) {
    if (a[i] % 2 == 0) {
        if (a[i] > max)
            max = a[i];
    }
    if (i < size - 1)
        return Find(a, size, max, i + 1);
}

int main()
{
    SetConsoleOutputCP(1251);

    srand((unsigned)time(NULL));
    const int n = 5;
    int a[n];
    int max = 0;

    int Low = -10;
    int High = 100;
    int r = 0;

    Create(a, n, Low, High, 0);
    cout << "Масив = "; Print(a, n, 0);

    Find(a, n, max, 0);
    cout << "Максимальний парний елемент = " << max << endl;
}