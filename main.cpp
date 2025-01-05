#include <raylib.h>
#include "header.h"
#include <thread>
#include <chrono>
#include <cmath>
#include <iostream>

#define HQGREY \
    CLITERAL(Color) { 41, 37, 36, 255 }
#define HQGREEN \
    CLITERAL(Color) { 62, 98, 26, 255 }

int array[ARRAY_SIZE];

void ShuffleArray()
{
    for (int i = ARRAY_SIZE - 1; i > 0; i--)
    {
        int j = GetRandomValue(0, i);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
};

int main()
{
    const int screenWidth = 1600;
    const int screenHeight = 900;
    InitWindow(screenWidth, screenHeight, "Sorting Algorithms Visualization");
    SetTargetFPS(240);

    Color bubbleSortTextColor = HQGREEN;
    Color insertionSortTextColor = WHITE;
    const char *bubbleSortText = "Bubble Sort";
    const char *insertionSortText = "Insertion Sort";
    int fontSize = 40;

    int bubbleSortTextWidth = MeasureText(bubbleSortText, fontSize);
    int insertionSortTextWidth = MeasureText(insertionSortText, fontSize);

    float padding = 10.0f;
    Rectangle btnBoundsBubble = {10, 10, (float)bubbleSortTextWidth + 2 * padding, (float)fontSize + 2 * padding};
    Rectangle btnBoundsInsert = {10, 50, (float)insertionSortTextWidth + 2 * padding, (float)fontSize + 2 * padding};

    Vector2 mousePoint = {0.0f, 0.0f};

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = (i * screenHeight) / ARRAY_SIZE;
    }

    ShuffleArray();

    int choosenalgorithm = 0;
    bool (*sortingAlgorithmStep)(int &, int &) = SelectAlgorithm(choosenalgorithm);
    int i = 0, j = 0;

    while (!WindowShouldClose())
    {

        mousePoint = GetMousePosition();

        if (CheckCollisionPointRec(mousePoint, btnBoundsBubble))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                choosenalgorithm = 0;
                sortingAlgorithmStep = SelectAlgorithm(choosenalgorithm);
                ShuffleArray();
                i = 0;
                j = 0;
                bubbleSortTextColor = HQGREEN;
                insertionSortTextColor = WHITE;
            }
        }

        if (CheckCollisionPointRec(mousePoint, btnBoundsInsert))
        {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
            {
                choosenalgorithm = 1;
                sortingAlgorithmStep = SelectAlgorithm(choosenalgorithm);
                ShuffleArray();
                i = 0;
                j = 0;
                bubbleSortTextColor = WHITE;
                insertionSortTextColor = HQGREEN;
            }
        }

        if (sortingAlgorithmStep && !sortingAlgorithmStep(i, j))
        {
            sortingAlgorithmStep = nullptr;
        }

        // Render
        BeginDrawing();
        ClearBackground(HQGREY);
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            DrawRectangle(i * (screenWidth / ARRAY_SIZE), screenHeight - array[i], screenWidth / ARRAY_SIZE, array[i], HQGREEN);
        }
        DrawText(bubbleSortText, 10, 10, fontSize, bubbleSortTextColor);
        DrawText(insertionSortText, 10, 50, fontSize, insertionSortTextColor);
        EndDrawing();

        // Delay
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    CloseWindow();
}