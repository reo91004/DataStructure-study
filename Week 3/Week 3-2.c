#include <stdio.h>

int main(void)
{
    int apple[3][2];
    //apple은 주소 100에 선언되었다.
    int banana[2][3];
    //banana는 주소 500에 선언되었다.

    printf("%p \n", apple); // 100, 108, 110(100 + 16 = 110)
    printf("%p \n", apple+1); 
    printf("%p \n", apple+2);

    printf("%p \n", banana); // 500, 50c, 518
    printf("%p \n", banana+1); // 500 + 12(c) = 50c
    printf("%p \n", banana+2); // 510 + 8 = 518

}