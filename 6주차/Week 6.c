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
        printf("ť�� �� ���ֽ��ϴ�.\n");
        return ERROR;
    }
    cQ->rear = (cQ->rear + 1) % MAX_SIZE;
    cQ->queue[cQ->rear] = data;

    return TRUE;
}

int dequeue(circularQueue* cQ) {
    if (isEmpty(cQ))
    {
        printf("ť�� ����ֽ��ϴ�..\n");
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
        printf("\n*****�ڷᱸ�� Ʃ�͸� - ���� ť*****\n");
        printf("i - enqueue    d - dequeue\n");
        printf("q - exit\n");
        printf("**********************\n");
        printf("��ɾ �Է����ּ��� : ");
        scanf(" %c",&cmd);
        switch (cmd) {
            case 'i':case 'I':
                printf("������ �����͸� �Է����ּ��� : ");
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
                printf("Dequeue�� Data = [%d]\n", dequeuedData);
                break;
            case 'q':case 'Q':
                printf("���ᡦ\n");
                break;
            default:
                printf("�������� �ʴ� ��ɾ��. �ٽ� �Է����ּ���\n");
                break;
        }
    } while (cmd != 'q' && cmd != 'Q');
    


    return 0;
}