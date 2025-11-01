#include <iostream>
#define SIZE 10
#define SIZE2 40
using namespace std;

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

// task 2, part 1 - create a function that sorts first half of an array in descending order and second half in ascending order using insertion sort
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

int main()
{
	srand(time(NULL));

	// task 1, part 1
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
	// task 2, part 1
	int array2[SIZE] = { 34, 7, 23, 32, 5, 62, 32, 2, 12, 45 };
	cout << "Original array: ";
	PrintArray(array2, SIZE);
	SortHalves(array2, SIZE);
	cout << "Array with first half sorted in descending order and second half in ascending order: ";
	PrintArray(array2, SIZE);
	// task 3, part 1
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
}
