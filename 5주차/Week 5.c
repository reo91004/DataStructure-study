#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    node* next;
    int data;
} node;

typedef struct _linkedList {
    node* head;
    int length;     // insert와 delete 함수 편의를 위해 length 필드 추가
} LinkedList;

LinkedList* init(LinkedList* head);
int insert(LinkedList* list, int pos, int item);
int get_length(LinkedList* list);
int freeList(LinkedList* list);
void print_list(LinkedList* list);
int delete(LinkedList* list, int pos);


int main() {
    
    char command;
    int pos;
    int item;
    LinkedList* head = NULL;
    
    do {
        printf("----------------------------------------------------------------\n");
        printf(" Initialize    = z           Print         = p \n");
        printf(" Insert        = i           Delete        = d \n");
        printf(" Quit          = q\n");
        printf("----------------------------------------------------------------\n");

        printf("Command = ");
        scanf(" %c", &command);

        switch (command) {
        case 'z': case 'Z':
            head = init(head);
            break;
        case 'p': case 'P':
            print_list(head);
            break;
        case 'i': case 'I':
            printf("추가할 위치 추가할 값 = ex)1 10");
            scanf("%d %d", &pos, &item);
            insert(head, pos, item);
            break;
        case 'd': case 'D':
            printf("삭제할 위치 = ");
            scanf("%d", &pos);
            delete(head, pos);
            break;
        
        case 'q': case 'Q':
            freeList(head);
            break;
        default:
            printf("\n       >>>>>   Concentration!!   <<<<<     \n");
            break;
        }

    } while (command != 'q' && command != 'Q');

    return 0;

}

LinkedList* init(LinkedList* head) {
    
    if(head != NULL) {      // 연결리스트가 비어있지 않다면
      free(head);       // 해제
    }
    
		// 리스트 할당
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list -> head = NULL;
    list -> length = 0;
    return list;
}

int freeList(LinkedList* list) {
    
		// 리스트 탐색을 위한 노드 포인터들 선언
		node *cur = list->head;
    node *prev;
  
    // 리스트를 탐색하면서 해제
    while(cur != NULL) {
        prev = cur;
        cur = cur -> next;
        free(prev); // 다시 생각
    }
    
		// 리스트 해제
		free(list);
    
    return 0;
    
}

int get_length(LinkedList* list) {
    
		// 리스트 탐색을 위한 노드 포인터들 선언
		node *cur = list->head;
		node *prev;
    
    int length = 0;
    
    // 리스트 끝까지 탐색
    while(cur != NULL) {
        prev = cur;
				cur = cur -> next;
				length++;
    }
    
    return length;
}

int insert(LinkedList* list, int pos, int item) {

// newNode 생성, 초기화
node *newNode = (node *)malloc(sizeof(node));
newNode->data = item;
newNode->next = NULL;
    
// 리스트 탐색을 위한 노드 포인터들 선언
node *cur = list -> head;
node *prev;

		// 리스트의 위치, pos와 비교를 위한 변수		
    int count = 0;
    
		// 리스트에 노드가 1개도 없을 때
    if(cur == NULL) {
        list -> head = newNode;
        list -> length++;
        return 0;
    }
		// 삽입 위치가 리스트 길이안에 있을 때 (주의. 리스트는 인덱스 0 부터 시작)
    if(pos-1 <= get_length(list)) { // list->length
        
        // 해당 위치까지 리스트 탐색
        while(cur != NULL) {
						// 삽입할 위치에 도착
            if(count == pos-1) {
                break;
            }
						// 탐색
            prev = cur;
            cur = cur -> next;
            count++;
            
        }
        
        // 새로운 노드 연결
        newNode -> next = cur;
        prev -> next = newNode;
        list -> length++;

    } else {    // 접근할 수 없는 삽입 위치
        printf("접근할 수 없는 위치입니다.\n");
        return 1;
    }
    
    return 0;
}

int delete(LinkedList* list, int pos) {
    
		// 리스트 탐색을 위한 노드 포인터들 선언
		node *cur = list -> head;
    node *prev = NULL;

		// 리스트의 위치, pos와 비교를 위한 변수	
    int count = 0;
    
		// 노드가 없을 때
    if(list->head == NULL) return 0;
		// 노드가 1개만 있을 때, 해당 노드 메모리 해제, 연결 재정비
    if(list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        return 0;
    } else {
				// 삭제 위치가 리스트 길이안에 있을 때
        if(pos-1 <= list->length) {
            
            // 해당 위치까지 리스트 탐색
            while(cur != NULL) {
								// 해당 위치에 도착
                if(count == pos -1){
                    break;
                }
								// 탐색
                prev = cur;
				        cur = cur -> next;
                count++;
            }
            
            // 리스트 연결 정비, 노드 메모리 해제
						prev -> next = cur -> next;
            free(cur);
            list -> length--;
        } else {    // 삭제 위치가 리스트 크기보다 클 때
            printf("접근할 수 없는 위치입니다.\n");
            return 1;
        }
        
    }
    return 0;
}

void print_list(LinkedList* list) {
    
    node* cur = list -> head;
    int index = 0;
    
		// 리스트가 초기화되어 있지 않거나, 리스트가 비어 있을 때
    if (list->head == NULL || list == NULL) {
        printf("리스트가 비어있습니다.\n");
        return;
    }
    
		// 리스트 탐색
    while(cur != NULL) {
        printf("%d번째 노드 = %d\n", index+1, cur -> data);
        cur = cur -> next;
				index++;
    }
}