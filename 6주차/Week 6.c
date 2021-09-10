#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
#define TRUE 1
#define FALSE 0
#define ERROR -1

typedef struct _circularQueue {
    int front;
    int rear;
    int* queue;
} circularQueue;

circularQueue* init() {
    circularQueue *cQ = (circularQueue*)malloc(sizeof(circularQueue));

    cQ->front = 0;
    cQ->rear = 0;
    cQ->queue = (int *)malloc(sizeof(int)*MAX_SIZE);

    return cQ;
}

int isEmpty(circularQueue *cQ) {
    if (cQ->front == cQ->rear)
        return TRUE;
    else
        return FALSE;
}

int isFull(circularQueue *cQ) {
    if ((cQ->rear + 1) % MAX_SIZE == cQ->front)
        return TRUE;
    else
        return FALSE;
}

int enqueue(circularQueue* cQ, int data) {
    if (isFull(cQ))
    {
        printf("큐가 꽉 차있습니다.\n");
        return ERROR;
    }
    cQ->rear = (cQ->rear + 1) % MAX_SIZE;
    cQ->queue[cQ->rear] = data;

    return TRUE;
}

int dequeue(circularQueue* cQ) {
    if (isEmpty(cQ))
    {
        printf("큐가 비어있습니다..\n");
        return ERROR;
    }
    cQ->front = (cQ->front + 1) % MAX_SIZE;
    return cQ->queue[cQ->front];
}

int main(void) {
    
    circularQueue* cQ = init();
    int data;
    char cmd;
    do {
        printf("\n*****자료구조 튜터링 - 원형 큐*****\n");
        printf("i - enqueue    d - dequeue\n");
        printf("q - exit\n");
        printf("**********************\n");
        printf("명령어를 입력해주세요 : ");
        scanf(" %c",&cmd);
        switch (cmd) {
            case 'i':case 'I':
                printf("삽입할 데이터를 입력해주세요 : ");
                scanf(" %d",&data);
                enqueue(cQ, data);
                break;
            case 'd':case 'D':
                printf("Dequeue...\n");
                int dequeuedData = dequeue(cQ);
                if(dequeuedData == ERROR) {
                    printf("Dequeue Fail\n");
                    break;
                }
                printf("Dequeue된 Data = [%d]\n", dequeuedData);
                break;
            case 'q':case 'Q':
                printf("종료…\n");
                break;
            default:
                printf("존재하지 않는 명령어에요. 다시 입력해주세요\n");
                break;
        }
    } while (cmd != 'q' && cmd != 'Q');
    


    return 0;
}