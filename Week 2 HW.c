#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // malloc, free ?븿?닔

void input(int **array, int row, int col);
void output(int **array, int row, int col);

int main()
{
    int row, col;
    printf("행 갯수 입력 : ");
    scanf("%d", &row);
    printf("열 갯수 입력 : ");
    scanf("%d", &col);

    int **array = (int **)malloc(sizeof(int *) * row); // (int **)를 추가했을때와 그러지 않았을 때의 차이점?

    for (int i=0; i<row; i++)
    {
        array[i] = malloc(sizeof(int) * col);
    }

    input(array, row, col);
    output(array, row, col);

    for (int i=0; i<row; i++)
    {
        free(array[i]);
    }

    free(array);

    return 0;
}

void input(int **array, int row, int col)
{
    for (int i=0; i<row; i++)
    {
        for (int j=0; j<col; j++)
        {
            array[i][j] = rand() % 9 + 1;
        }
    }
}

void output(int **array, int row, int col)
{
	for (int i=0; i<row; i++)
	{
		for (int j=0; j<col; j++)
		{
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}
}