#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

#define SIZE 10

// ==========================================================
// TASK 1
// ==========================================================

// ==========================================================
// INT VERSION
// ==========================================================
void ProcessMatrix(int matrix[SIZE][SIZE])
{
    // Initialize
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = rand() % 100 - 50;

    // Print
    cout << "Integer matrix:\n";
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
    cout << endl;

    // Find min & max on the main diagonal
    int minVal = matrix[0][0], maxVal = matrix[0][0];
    for (int i = 0; i < SIZE; i++)
    {
        if (matrix[i][i] < minVal) minVal = matrix[i][i];
        if (matrix[i][i] > maxVal) maxVal = matrix[i][i];
    }
    cout << "Min on diagonal: " << minVal << endl;
    cout << "Max on diagonal: " << maxVal << endl << endl;

    // Sort each row ascending
    for (int i = 0; i < SIZE; i++)
        sort(matrix[i], matrix[i] + SIZE);

    cout << "Matrix after row-wise sorting:\n";
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

// ==========================================================
// DOUBLE VERSION
// ==========================================================
void ProcessMatrix(double matrix[SIZE][SIZE])
{
    // 1️ Initialize
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = (rand() % 1000 - 500) / 10.0;

    // 2️ Print
    cout << "Double matrix:\n";
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
    cout << endl;

    // 3️ Find min & max on diagonal
    double minVal = matrix[0][0], maxVal = matrix[0][0];
    for (int i = 0; i < SIZE; i++)
    {
        if (matrix[i][i] < minVal) minVal = matrix[i][i];
        if (matrix[i][i] > maxVal) maxVal = matrix[i][i];
    }
    cout << "Min on diagonal: " << minVal << endl;
    cout << "Max on diagonal: " << maxVal << endl << endl;

    // 4️ Sort each row ascending
    for (int i = 0; i < SIZE; i++)
        sort(matrix[i], matrix[i] + SIZE);

    cout << "Matrix after row-wise sorting:\n";
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

// ==========================================================
// CHAR VERSION
// ==========================================================
void ProcessMatrix(char matrix[SIZE][SIZE])
{
    // 1️ Initialize
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = 'A' + rand() % 26;

    // 2️ Print
    cout << "Char matrix:\n";
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
    cout << endl;

    // 3️ Find min & max on diagonal (by ASCII)
    char minVal = matrix[0][0], maxVal = matrix[0][0];
    for (int i = 0; i < SIZE; i++)
    {
        if (matrix[i][i] < minVal) minVal = matrix[i][i];
        if (matrix[i][i] > maxVal) maxVal = matrix[i][i];
    }
    cout << "Min on diagonal: " << minVal << endl;
    cout << "Max on diagonal: " << maxVal << endl << endl;

    // 4️ Sort each row ascending
    for (int i = 0; i < SIZE; i++)
        sort(matrix[i], matrix[i] + SIZE);

    cout << "Matrix after row-wise sorting:\n";
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
    cout << endl;
}

// ==========================================================
// TASK 2
// ==========================================================

int FindGCD(int a, int b)
{
    if (b == 0) return a;
    return FindGCD(b, a % b);
}

// ==========================================================
// TASK 3
// ==========================================================

int BullsAndCows(string secret = "", int attempt = 1)
{
    if (secret == "")
    {
        int num = rand() % 9000 + 1000;
        secret = to_string(num);
        cout << "(Secret number generated!) Try to guess the 4-digit number.\n";
    }

    string guess;
    cout << "Attempt " << attempt << " → Enter your guess: ";
    cin >> guess;

    if (guess.length() != 4 || !isdigit(guess[0]))
    {
        cout << "❌ Invalid input! Enter exactly 4 digits.\n";
        return BullsAndCows(secret, attempt);
    }

    int bulls = 0, cows = 0;
    for (int i = 0; i < 4; i++)
    {
        if (guess[i] == secret[i])
            bulls++;
        else if (secret.find(guess[i]) != string::npos)
            cows++;
    }

    if (bulls == 4)
    {
        cout << "You guessed it! The number was " << secret << ".\n";
        cout << "You needed " << attempt << " attempts!\n";
        return attempt;
    }

    cout << "Bulls: " << bulls << ", Cows: " << cows << "\n\n";
    return BullsAndCows(secret, attempt + 1);
}


// ==========================================================
// MAIN
// ==========================================================
int main()
{
    srand(time(NULL));

    int intMatrix[SIZE][SIZE];
    double doubleMatrix[SIZE][SIZE];
    char charMatrix[SIZE][SIZE];

    ProcessMatrix(intMatrix);
    ProcessMatrix(doubleMatrix);
    ProcessMatrix(charMatrix);

	int a, b;
	cout << "Enter two integers to find their GCD >>> ";
	cin >> a >> b;
	cout << "GCD(" << a << ", " << b << ") = " << FindGCD(a, b) << endl << endl;
    BullsAndCows();
	return 0;
}
