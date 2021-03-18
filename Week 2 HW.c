#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // malloc, free ?��?��

void input(int **array, int row, int col);
void output(int **array, int row, int col);

int main()
{
    int row, col;
    printf("�� ���� �Է� : ");
    scanf("%d", &row);
    printf("�� ���� �Է� : ");
    scanf("%d", &col);

    int **array = (int **)malloc(sizeof(int *) * row); // (int **)�� �߰��������� �׷��� �ʾ��� ���� ������?

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