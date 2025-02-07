#include <iostream>
#include <algorithm>

void bubbleSort(int arr[], int size) 
{
    for (int i = 0; i < size - 1; ++i) 
    {
        for (int j = 0; j < size - i - 1; ++j) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

enum class SortingDirection 
{ 
    ByRows, 
    ByColumns 
};

const int ROWS = 3;
const int COLUMNS = 3;

void sort(int arr[ROWS][COLUMNS], SortingDirection direction) 
{
    if (direction == SortingDirection::ByRows) 
    {
        for (int i = 0; i < ROWS; ++i) 
        {
            for (int k = 0; k < COLUMNS - 1; ++k) 
            {
                for (int j = 0; j < COLUMNS - k - 1; ++j) 
                {
                    if (arr[i][j] > arr[i][j + 1]) 
                    {
                        std::swap(arr[i][j], arr[i][j + 1]);
                    }
                }
            }
        }
    }
    else if (direction == SortingDirection::ByColumns) 
    {
        for (int j = 0; j < COLUMNS; ++j) 
        {
            for (int k = 0; k < ROWS - 1; ++k) 
            {
                for (int i = 0; i < ROWS - k - 1; ++i) 
                {
                    if (arr[i][j] > arr[i + 1][j]) 
                    {
                        std::swap(arr[i][j], arr[i + 1][j]);
                    }
                }
            }
        }
    }
}


void printArray(int arr[ROWS][COLUMNS]) 
{
    for (int i = 0; i < ROWS; ++i) 
    {
        for (int j = 0; j < COLUMNS; ++j) 
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int arr1D[] = { 54, 32, 99, 121, 35, 68 };
    int size = sizeof(arr1D) / sizeof(arr1D[0]);
    bubbleSort(arr1D, size);
    std::cout << "Here's your sorted array: ";
    for (int i = 0; i < size; ++i) 
    {
        std::cout << arr1D[i] << " ";
    }
    std::cout << std::endl;

    int arr2D[ROWS][COLUMNS] = { {41, 32, 33}, {42, 45, 36}, {27, 48, 39} };
    sort(arr2D, SortingDirection::ByRows);
    std::cout << "Your array sorted by rows: " << std::endl;
    printArray(arr2D);

    int arr2D_ColSort[ROWS][COLUMNS] = { {30, 27, 12}, {92, 53, 47}, {89, 24, 61} };
    sort(arr2D_ColSort, SortingDirection::ByColumns);
    std::cout << "Your array sorted by columns: " << std::endl;
    printArray(arr2D_ColSort);

    return 0;
}