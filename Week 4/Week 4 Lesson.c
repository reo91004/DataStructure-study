#include <stdio.h>
#define MAX_SIZE 100

typedef struct _Stack {
    int data[MAX_SIZE];
    int top;
} Stack;

void init(Stack* s) {
    s -> top = -1;
}

// 공백 검사
int isEmpty(Stack* s) {
    return (s->top == -1);
}

// 포화 검사
int isFull(Stack* s) {
    return (s->top == (MAX_SIZE - 1));
}

// 삽입
void push(Stack* s, int item) {
    if(isFull(s)){
        printf("스택이 다 찼습니다\n");
        return;
    }
    else {
        // ++을 먼저 하는 이유 : 초기 top -1
        s->data[++(s->top)] = item;
    }
}

// 삭제
int pop(Stack* s) {
    if(isEmpty(s)){
        printf("스택이 비었습니다.\n");
        return -1;
        // 예제니깐 -1로 했다. -1로 하면 안된다!! 이유 : 스택에 데이터로 -1이 들어갈 수 있기 때문.
    }
    else {
        return s->data[(s->top)--];
    }
}

int main(void) {
    Stack stack;
    init(&stack);
    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);
    push(&stack, 4);
    push(&stack, 5);

    
    
    return 0;
}
