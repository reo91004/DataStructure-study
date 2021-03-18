#include <stdio.h>
#include <string.h>

typedef struct _Person
{
        char name[10];
        int age;
        char department[20];
        char address[20];
} Person;

void setPerson();

int main()
{
    Person p1;

    strcpy(p1.name, "둘리");
    p1.age = 11;
    strcpy(p1.department, "남극");

    printf("이름 : %s\n", p1.name);
    printf("나이 : %d\n", p1.age);
    printf("학과 : %s\n\n", p1.department);

    setPerson(p1);

    printf("이름 : %s\n", p1.name);
    printf("나이 : %d\n", p1.age);
    printf("학과 : %s\n", p1.department);
    printf("주소 : %s\n", p1.address);

    return 0;
    
}

void setPerson(Person p2)
{
    strcpy(p2.name, "고길동");
    p2.age = 40;
    strcpy(p2.address, "서울시");
}