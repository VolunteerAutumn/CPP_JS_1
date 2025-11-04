#include <iostream>
#include <ctime>
#include <utility>
using namespace std;

#define SIZE 10
#define SIZE2 40
#define SIZE3 100

// task 1, part 1
template <typename T>
void PrintArray(T arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void SortInOrder(int arr[], int size, bool descending = false)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (descending)
            {
                if (arr[j] < arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
            else
            {
                if (arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
}

// task 2, part 1
template <typename T>
void InsertionSort(T arr[], int size, bool descending = false)
{
    for (int i = 1; i < size; i++)
    {
        T key = arr[i];
        int j = i - 1;
        if (descending)
        {
            while (j >= 0 && arr[j] < key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
        }
        else
        {
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
        }
        arr[j + 1] = key;
    }
}

void SortHalves(int arr[], int size)
{
    int mid = size / 2;
    InsertionSort(arr, mid, true);
    InsertionSort(arr + mid, size - mid, false);
}

// task 3, part 1
template <typename T>
void FillArrayRandomly(T arr[], int size, T start, T end)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = start + rand() % (end - start + 1);
    }
}

template <typename T>
pair<int, int> FindNegativeElements(T arr[], int size)
{
    int leftmost = -1;
    int rightmost = -1;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < 0)
        {
            if (leftmost == -1)
            {
                leftmost = i;
            }
            rightmost = i;
        }
    }
    return make_pair(leftmost, rightmost);
}

// =============================
// NEW TASKS BELOW (RECURSION + OVERLOADING)
// =============================

// Task 1: Recursive power function
int Power(int base, int exp)
{
    if (exp == 0)
        return 1;
    return base * Power(base, exp - 1);
}

// Task 2: Recursive function printing N stars
void PrintStars(int n)
{
    if (n <= 0) return;
    cout << "*";
    PrintStars(n - 1);
}

// Task 3: Recursive sum between a and b
int RangeSum(int a, int b)
{
    if (a > b) return 0;
    return a + RangeSum(a + 1, b);
}

// Task 4: Find position of minimal-sum sequence of 10 elements in 100-element array
int MinSumSequencePos(int arr[], int start, int size)
{
    if (start + 10 > size)
        return start;

    int currentSum = 0;
    for (int i = start; i < start + 10; i++)
        currentSum += arr[i];

    int nextPos = MinSumSequencePos(arr, start + 1, size);

    int nextSum = 0;
    for (int i = nextPos; i < nextPos + 10 && i < size; i++)
        nextSum += arr[i];

    return (currentSum < nextSum) ? start : nextPos;
}

// Task 5: Overloaded max functions
int MaxValue(int a, int b)
{
    return (a > b) ? a : b;
}

int MaxValue(int a, int b, int c)
{
    return MaxValue(MaxValue(a, b), c);
}

int MaxValue(int arr[], int size)
{
    int maxVal = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];
    return maxVal;
}

int MaxValue(int arr[][SIZE], int rows)
{
    int maxVal = arr[0][0];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < SIZE; j++)
            if (arr[i][j] > maxVal)
                maxVal = arr[i][j];
    return maxVal;
}

int MaxValue(int arr[][SIZE][SIZE], int dim)
{
    int maxVal = arr[0][0][0];
    for (int i = 0; i < dim; i++)
        for (int j = 0; j < SIZE; j++)
            for (int k = 0; k < SIZE; k++)
                if (arr[i][j][k] > maxVal)
                    maxVal = arr[i][j][k];
    return maxVal;
}

// =============================
// MAIN PROGRAM
// =============================
int main()
{
    srand(time(NULL));

    // --- Your original tasks ---
    int array[SIZE] = { 34, 7, 23, 32, 5, 62, 32, 2, 12, 45 };
    PrintArray(array, SIZE);
    cout << endl;
    cout << "Do you want to sort in descending order? (1 for yes, 0 for no) >>> ";
    bool desc;
    cin >> desc;
    SortInOrder(array, SIZE, desc);
    cout << "Sorted array: ";
    PrintArray(array, SIZE);
    cout << endl;

    int array2[SIZE] = { 34, 7, 23, 32, 5, 62, 32, 2, 12, 45 };
    cout << "Original array: ";
    PrintArray(array2, SIZE);
    SortHalves(array2, SIZE);
    cout << "Array with first half sorted in descending order and second half in ascending order: ";
    PrintArray(array2, SIZE);

    int array3[SIZE2];
    FillArrayRandomly(array3, SIZE2, -20, 20);
    cout << "Randomly filled array: ";
    PrintArray(array3, SIZE2);
    pair<int, int> negIndices = FindNegativeElements(array3, SIZE2);
    if (negIndices.first != -1 && negIndices.second != -1 && negIndices.first != negIndices.second)
    {
        cout << "Elements between leftmost and rightmost negatives: ";
        for (int i = negIndices.first; i <= negIndices.second; i++)
        {
            cout << array3[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Not enough negative elements to display between." << endl;
    }

    SortInOrder(array3 + negIndices.first, negIndices.second - negIndices.first + 1, false);
    cout << "Array after sorting elements between leftmost and rightmost negatives in ascending order: ";
    PrintArray(array3, SIZE2);

    cout << "\n==============================\n";
    cout << "NEW TASKS:\n";

    // Task 1
    int base, exp;
    cout << "Enter base and exponent for power calculation >>> ";
    cin >> base >> exp;
    cout << base << "^" << exp << " = " << Power(base, exp) << endl;

    // Task 2
    int stars;
    cout << "Enter number of stars >> ";
    cin >> stars;
    PrintStars(stars);
    cout << endl;

    // Task 3
    int a, b;
    cout << "Enter range [a, b] for sum >>> ";
    cin >> a >> b;
    cout << "Sum = " << RangeSum(a, b) << endl;

    // Task 4
    int arr4[SIZE3];
    FillArrayRandomly(arr4, SIZE3, -50, 50);
    int pos = MinSumSequencePos(arr4, 0, SIZE3);
    cout << "Position of minimal 10-number sequence: " << pos << endl;

    // Task 5
    int x = 10, y = 22, z = 5;
    cout << "Max of two ints (" << x << ", " << y << ") = " << MaxValue(x, y) << endl;
    cout << "Max of three ints (" << x << ", " << y << ", " << z << ") = " << MaxValue(x, y, z) << endl;

    int oneD[SIZE] = { 1, 5, 8, 3, 12, 0, 19, 4, 6, 11 };
    cout << "Max in 1D array: " << MaxValue(oneD, SIZE) << endl;

    int twoD[SIZE][SIZE];
    FillArrayRandomly(twoD[0], SIZE * SIZE, 0, 100);
    cout << "Max in 2D array: " << MaxValue(twoD, SIZE) << endl;

    int threeD[SIZE][SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
        FillArrayRandomly(threeD[i][0], SIZE * SIZE, 0, 500);
    cout << "Max in 3D array: " << MaxValue(threeD, SIZE) << endl;

    return 0;
}
