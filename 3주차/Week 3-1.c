#include <stdio.h>

int main(void) {
	int arr2d[3][3];
	// arr2d는 주소 100에 선언되었다.
	
	//%p는 포인터 주소를 가리키는 형식, 16진수
	printf("%p \n", arr2d);    // 100
	printf("%p \n", arr2d[0]); // 100
	printf("%p \n", &(arr2d[0][0])); // 100

	printf("%p \n", arr2d[1]); // 10c
	printf("%p \n", &(arr2d[1][0])); // 10c

    // 4바이트 -> 3개 = 12바이트 112
    // 16진수 : 0~9, A, B, C, D, E, F

	//%lu는 부호가 없는 long형 출력, unsigned long 
	printf("size : %lu\n", sizeof(arr2d));    // 32
	printf("size : %lu\n", sizeof(arr2d[0])); // 12
	printf("size : %lu\n", sizeof(arr2d[1])); // 12
	printf("size : %lu\n", sizeof(arr2d[2])); // 12
    
	return 0;
}
