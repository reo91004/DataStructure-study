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
	isEmpty : 공백 검사 메서드
	params : stack포인터, 이유 = 스택에 직접 접근해서 값을 변경해야하기 때문
	return : int , 이유 = 참, 거짓 판별
*/

int isEmpty (Stack *s) {
    if (s->top == -1)
        return true; // true
    else
        return false; // false
}

/*
	isFull : 포화 검사 메서드
	params : stack포인터, 이유 = 스택에 직접 접근 -> 값 변경
	return : int , 이유 = 참, 거짓 판별
*/

int isFull (Stack *s) {
    if (s->top >= MAX_SIZE - 1)
        return true; // true
    else
        return false; // false
}

/*
	push : 삽입 메서드
	params : stack포인터, int형 변수
	return : void
*/

void Push (Stack *s, int data) {
    if (isFull(s) == true) {
        printf("스택이 전부 차있습니다.\n");
        exit(1);
    }
       
    else {
        s->top += 1;
        s->data[s->top] = data;
    }

}

/*
	pop : 삭제 메서드
    params : stack포인터
	return : int
*/

int Pop (Stack *s) {
    if (isEmpty(s) == true) {
        printf("스택이 비어있습니다.\n");
        exit(1);
    }
    else 
        return s->data[(s->top)--];
}


/*
  peek : 검색 메서드
  params : stack포인터
  return : int
*/

int Peek (Stack *s) {
    if (isEmpty(s) == true) {
        printf("스택이 비어있습니다.\n");
        exit(1);
    }
    else
        printf("%d",s->data[s->top]);
        return s->data[s->top];
}

/*
  printStack : 스택 원소 출력
  params : stack포인터
  return : void
*/

void printStack(Stack *s) {
    if (isEmpty(s) == true) {
        printf("스택이 비어있습니다.\n");
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