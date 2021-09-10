#include <stdio.h>

/*
- ���� ���� : Ű ���� ���ĵǾ� �ִ� �κп��� ��� �����ؾ� ������ �������� ����
- ���� ���� : ���ĵǾ� ���� ���� �κп��� �ּڰ��� ã�� ������ �ݺ��Ͽ� ����
- ���� ���� : ������ �� ���Ҹ� ��, ��ȯ�� �ݺ��Ͽ� ����
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
        val = arr[i]; // �ʱⰪ ����

        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > val) // ���� arr[j]�� val���� ũ�� �ڸ��ٲ�
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