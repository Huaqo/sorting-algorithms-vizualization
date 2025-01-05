#include "header.h"
#include <iostream>
#include <algorithm>

bool (*SelectAlgorithm(int selectedAlgorithm))(int &, int &)
{
    switch (selectedAlgorithm)
    {
    case 0:
        return BubbleSortStep;
    case 1:
        return InsertionSortStep;
    default:
        std::cout << "Invalid algorithm selected!" << std::endl;
        return nullptr;
    }
}

bool BubbleSortStep(int &i, int &j)
{
    if (i >= ARRAY_SIZE - 1)
    {
        j = 0;
        return false;
    }

    if (j >= ARRAY_SIZE - i - 1)
    {
        i++;
        j = 0;
    }

    if (array[j] > array[j + 1])
    {
        std::swap(array[j], array[j + 1]);
    }

    j++;

    return true;
}

bool InsertionSortStep(int &i, int &j)
{
    if (i >= ARRAY_SIZE)
    {
        return false;
    }

    int key = array[i];
    j = i - 1;

    while (j >= 0 && array[j] > key)
    {
        array[j + 1] = array[j];
        j = j - 1;
    }
    array[j + 1] = key;

    i++;
    return true;
}