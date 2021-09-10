안녕하세요 선배님, 저번에 진행한 원형 큐에 대해 질문드립니다,,

구조체 포인터라고 검색하면

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

보통 이렇게 미리 구조체를 하나 만들어놓고 그 구조체를 가리키는 예제밖에 보지 못했었는데, 저번에 진행한 수업에서

circularQueue* init() {
    circularQueue *cQ = (circularQueue*)malloc(sizeof(circularQueue));

    cQ->front = 0;
    cQ->rear = 0;
    cQ->queue = (int *)malloc(sizeof(int)*MAX_SIZE);

    return cQ;
}

이러한 코드는 cQ 포인터가 선언되고, 아직 아무것도 가리키고 있지 않은데 cQ->front = 0;이라고 선언할 수 있는 이유를
어렴풋이는 알겠는데 명확하게 스스로 설명하지 못하겠어서 질문드립니다,,

또한 circularQueue* cQ = init(); 코드에서, 구조체 포인터 cQ로 선언했는데 init()는 return값을 cQ로 주는데
이걸 주소값으로 주지 않아도 되는 이유가 궁금합니다.