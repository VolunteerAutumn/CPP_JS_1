#include <iostream>
#include <cmath>
#include <tuple>
using namespace std;

#define SIZE 20
#define MATRIXSIZE 10


template <typename T>
void FillArrayRandomly(T arr[], int size, T start, T end)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = start + rand() % (end - start + 1);
    }
}
template <typename T>
void PrintArray(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
template <typename T, size_t ROWS, size_t COLS>



// TASK 1
bool IsLeapYear(int year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int DaysInMonth(int month, int year)
{
    switch (month)
    {
    case 1: return 31;
    case 2: return IsLeapYear(year) ? 29 : 28;
    case 3: return 31;
    case 4: return 30;
    case 5: return 31;
    case 6: return 30;
    case 7: return 31;
    case 8: return 31;
    case 9: return 30;
    case 10: return 31;
    case 11: return 30;
    case 12: return 31;
    default: return 0;
    }
}

long long DaysFromStart(int day, int month, int year)
{
    long long totalDays = 0;

    for (int i = 1; i < year; i++)
        totalDays += IsLeapYear(i) ? 366 : 365;
    for (int i = 1; i < month; i++)
        totalDays += DaysInMonth(i, year);
    totalDays += day;

    return totalDays;
}

int DaysBetweenDates(int d1, int m1, int y1, int d2, int m2, int y2)
{
    long long days1 = DaysFromStart(d1, m1, y1);
    long long days2 = DaysFromStart(d2, m2, y2);

    return abs((int)(days2 - days1));
}

// TASK 2
double AvgInArray(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return static_cast<double>(sum) / size;
}

// TASK 3
tuple<int, int, int> FindNegPosZer(int arr[], int size)
{
    int neg = 0, pos = 0, zero = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            neg++;
        }
        else if (arr[i] > 0)
        {
            pos++;
        }
        else
        {
            zero++;
        }
    }
    return make_tuple(neg, pos, zero);
}


// ================================================================================
int main()
{
    srand(time(NULL));

    // TASK 1
    int d1, m1, y1, d2, m2, y2;
    cout << "Enter first date (day month year) >>> ";
    cin >> d1 >> m1 >> y1;
    cout << "Enter second date (day month year) >>> ";
    cin >> d2 >> m2 >> y2;
    cout << "\nDifference between dates: " << DaysBetweenDates(d1, m1, y1, d2, m2, y2) << " days." << endl;

    // TASK 2
    int arr[SIZE];
    FillArrayRandomly(arr, SIZE, -100, 100);
	cout << "\nArray elements: ";
    PrintArray(arr, SIZE);
    cout << "Average value in array: " << AvgInArray(arr, SIZE) << endl;

    // TASK 3
    int negatives, positives, zeros;
    tie(negatives, positives, zeros) = FindNegPosZer(arr, SIZE);
    cout << "There are " << negatives << " negative elements in this array, " << positives << " positive elements in this array, " << zeros << " zeros in the array." << endl;
}
