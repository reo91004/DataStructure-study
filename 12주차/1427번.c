#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 11

void BubbleSort(char arr[], int size)
{
	int i, j;
	char temp;

	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main()
{
	char num[MAX];
	int* temp;
	scanf("%s", &num);

	BubbleSort(num, strlen(num));

	for (int i = 0; i < strlen(num); i++)
	{
		printf("%c", num[i]);
	}
	
	return 0;
}
