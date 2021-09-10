#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_SIZE 100

typedef struct _Stack {
    int data[MAX_SIZE];
    int top;
} Stack;

void init(Stack *s) {
    s -> top = -1;
}

/*
	isEmpty : ���� �˻� �޼���
	params : stack������, ���� = ���ÿ� ���� �����ؼ� ���� �����ؾ��ϱ� ����
	return : int , ���� = ��, ���� �Ǻ�
*/

int isEmpty (Stack *s) {
    if (s->top == -1)
        return true; // true
    else
        return false; // false
}

/*
	isFull : ��ȭ �˻� �޼���
	params : stack������, ���� = ���ÿ� ���� ���� -> �� ����
	return : int , ���� = ��, ���� �Ǻ�
*/

int isFull (Stack *s) {
    if (s->top >= MAX_SIZE - 1)
        return true; // true
    else
        return false; // false
}

/*
	push : ���� �޼���
	params : stack������, int�� ����
	return : void
*/

void Push (Stack *s, int data) {
    if (isFull(s) == true) {
        printf("������ ���� ���ֽ��ϴ�.\n");
        exit(1);
    }
       
    else {
        s->top += 1;
        s->data[s->top] = data;
    }

}

/*
	pop : ���� �޼���
    params : stack������
	return : int
*/

int Pop (Stack *s) {
    if (isEmpty(s) == true) {
        printf("������ ����ֽ��ϴ�.\n");
        exit(1);
    }
    else 
        return s->data[(s->top)--];
}


/*
  peek : �˻� �޼���
  params : stack������
  return : int
*/

int Peek (Stack *s) {
    if (isEmpty(s) == true) {
        printf("������ ����ֽ��ϴ�.\n");
        exit(1);
    }
    else
        printf("%d",s->data[s->top]);
        return s->data[s->top];
}

/*
  printStack : ���� ���� ���
  params : stack������
  return : void
*/

void printStack(Stack *s) {
    if (isEmpty(s) == true) {
        printf("������ ����ֽ��ϴ�.\n");
        exit(1);
    }

    for (int i=0; i<=s->top; i++)
        printf("%d\n",s->data[i]);
}

int main(void) {
    Stack stack;
    init(&stack);
    Push(&stack, 1);
    Push(&stack, 3);
    Push(&stack, 5);
    Push(&stack, 7);
    printStack(&stack);
    printf("\n");
    Pop(&stack);
    printStack(&stack);
    printf("\n");
    Peek(&stack);
    
    return 0; 
}