#include <stdio.h>

/*
- 삽입 정렬 : 키 값을 정렬되어 있는 부분에서 어디에 삽입해야 할지를 중점으로 생각
- 선택 정렬 : 정렬되어 있지 않은 부분에서 최솟값을 찾는 과정을 반복하여 정렬
- 버블 정렬 : 인접한 두 원소를 비교, 교환을 반복하여 정렬
*/

void InsertSort(int arr[], int size);
void SelectSort(int arr[], int size);
void BubbleSort(int arr[], int size);
void QuickSort(int arr[], int start, int end);

int main()
{
    int arr[] = { 100, 53, 56, 32, 38 };

    QuickSort(arr, 0, 4);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

void InsertSort(int arr[], int size)
{
    int val;
    int i, j;

    for (i = 1; i < size; i++)
    {
        val = arr[i]; // 초기값 설정

        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > val) // 만약 arr[j]가 val보다 크면 자리바꿈
                arr[j + 1] = arr[j];
            else
                break;
        }

        arr[j + 1] = val;
    }
}

void SelectSort(int arr[], int size)
{
    int min, i, j;
    int temp;

    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void BubbleSort(int arr[], int size)
{
    int i, j;
    int temp;

    for (i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void QuickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int pivot = start;
    int i = pivot + 1;
    int j = end;
    int temp;

    while (i <= j)
    {
        while (i <= end && arr[i] <= arr[pivot])
            i++;

        while (j > start && arr[i] >= arr[pivot])
            j--;

        if (i > j)
        {
            temp = arr[j];
            arr[j] = arr[pivot];
            arr[pivot] = temp;
        }
        else
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    QuickSort(arr, start, j - 1);
    QuickSort(arr, j + 1, end);
}