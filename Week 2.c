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

    strcpy(p1.name, "�Ѹ�");
    p1.age = 11;
    strcpy(p1.department, "����");

    printf("�̸� : %s\n", p1.name);
    printf("���� : %d\n", p1.age);
    printf("�а� : %s\n\n", p1.department);

    setPerson(p1);

    printf("�̸� : %s\n", p1.name);
    printf("���� : %d\n", p1.age);
    printf("�а� : %s\n", p1.department);
    printf("�ּ� : %s\n", p1.address);

    return 0;
    
}

void setPerson(Person p2)
{
    strcpy(p2.name, "��浿");
    p2.age = 40;
    strcpy(p2.address, "�����");
}