#include <stdio.h>
#define TAM 4

void showSolution(int path[][TAM], int n)
{
    int i;
    for (i = 0; i < (n * n); i++)
    {
        printf("%d ", path[i / n][i % n]);
        if ((i + 1) % n == 0)
            printf("\n");
    }
}

int canGoFoward(int maze[][TAM], int x, int y, int n)
{
    return (x < n && maze[y][x] == 1);
}

int canGoDown(int maze[][TAM], int x, int y, int n)
{
    return (y < n && maze[y][x] == 1);
}

void solveMaze(int maze[][TAM], int path[][TAM], int x, int y, int n)
{
    path[y][x] = 1;

    if (path[n - 1][n - 1] == 1)
    {
        showSolution(path, n);
        return;
    }

    if (canGoFoward(maze, x + 1, y, n))
    {
        solveMaze(maze, path, x + 1, y, n);
    }

    if (canGoDown(maze, x, y + 1, n))
    {
        solveMaze(maze, path, x, y + 1, n);
    }

    path[y][x] = 0;

    return;
}

int main()
{
    int maze[TAM][TAM] = {{1, 0, 0, 0},
                          {1, 1, 1, 1},
                          {0, 1, 0, 0},
                          {1, 1, 1, 1}};

    int path[TAM][TAM] = {{0, 0, 0, 0},
                          {0, 0, 0, 0},
                          {0, 0, 0, 0},
                          {0, 0, 0, 0}};
    int i, n = TAM;

    // showSolution(maze,TAM);

    solveMaze(maze, path, 0, 0, TAM);

    return 0;
}