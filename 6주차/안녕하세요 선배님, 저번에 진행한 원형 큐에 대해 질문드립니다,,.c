�ȳ��ϼ��� �����, ������ ������ ���� ť�� ���� �����帳�ϴ�,,

����ü �����Ͷ�� �˻��ϸ�

#include <stdio.h> 

struct Point 
{ 
    int x; int y; 
}; 

int main() 
{ 
    struct Point pt = { 100 , 200 }; 
    struct Point *ppt = &pt; 
    printf("pt.x = %d : pt.y = %d\n" , ppt->x , ppt->y);

    return 0; 
}

���� �̷��� �̸� ����ü�� �ϳ� �������� �� ����ü�� ����Ű�� �����ۿ� ���� ���߾��µ�, ������ ������ ��������

circularQueue* init() {
    circularQueue *cQ = (circularQueue*)malloc(sizeof(circularQueue));

    cQ->front = 0;
    cQ->rear = 0;
    cQ->queue = (int *)malloc(sizeof(int)*MAX_SIZE);

    return cQ;
}

�̷��� �ڵ�� cQ �����Ͱ� ����ǰ�, ���� �ƹ��͵� ����Ű�� ���� ������ cQ->front = 0;�̶�� ������ �� �ִ� ������
���ǲ�̴� �˰ڴµ� ��Ȯ�ϰ� ������ �������� ���ϰھ �����帳�ϴ�,,

���� circularQueue* cQ = init(); �ڵ忡��, ����ü ������ cQ�� �����ߴµ� init()�� return���� cQ�� �ִµ�
�̰� �ּҰ����� ���� �ʾƵ� �Ǵ� ������ �ñ��մϴ�.