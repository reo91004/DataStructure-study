#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void) {
    char* arr[3];
    char tmp[30];    //문자를 받을 char 배열 30자 까지만 받자
    int len, i;
 
    for (i = 0; i < 3; i++) 
    {
        printf("[%d] : ", i);    
        scanf("%s", tmp);        //문자열 입력받기
        len = strlen(tmp) + 1;    //문자열 길이 + 1 할당 ('\0' 문자 포함)
        printf("[%d] : tmp \t주소 : %p\n", i, &tmp);    //tmp 주소 출력
 
        arr[i] = (char*)malloc(sizeof(char) * len);    //메모리 할당
        printf("[%d] : arr[%d]\t주소 : %p\n\n", i, i, &arr[i]);    //할당받은 arr[i] 메모리 주소 출력
 
        strcpy(arr[i], tmp);    //문자열을 arr[i]가 가리키고 있는 메모리로 복사
    }
 
    printf("\n");
    for (i = 0; i < 3; i++) 
    {
        printf("arr[%d] = %s\t주소 : %p\n", i, arr[i], &arr[i]);
    }
 
    for (i = 0; i < 3; i++) 
    {
        free(arr[i]);    //메모리 해제
    }
    return 0;
}