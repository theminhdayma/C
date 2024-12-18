#include <stdio.h>

// Dinh nghia 1 node
typedef struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
} Node;

// Tao node moi
Node* createNode(int value) {
	// Cap nhat bo nho 
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = value;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	return newNode;
}

// Them 1 phan tu vao dau list
void insertHead(Node** head, int value) {
	Node* newNode = createNode(value);
	newNode->next = *head;
	if(*head != NULL) {
		(*head)->prev = newNode;
	}
	*head= newNode;
}

// Them 1 phan tu o cuoi danh sanh
void insertEnd(Node** head, int value) {
	// Tao Node
	Node* newNode = createNode(value);
	
	if(*head == NULL) {
		*head = newNode;
		return;
	}
	Node* temp = *head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}

// Chen vao vi tri bat ky 
void insertElement(Node** head, int value, int position){
	Node* newNode = createNode(value);
	// kiem postion < 0 ko hop le 
	// vi tri position 0 ==> chen vao dau danh sach 
	
	// tim vi tri 
	if(position == 0){
		newNode->next = *head;
		*head = newNode;
		return;
	}
	
	Node* temp = *head;
	
	for(int i=0; temp != NULL && i<position - 1; i++){
		temp = temp->next;
	}
	
	newNode->next = temp->next;
	temp->prev = newNode;
	temp->next = newNode;
	newNode->prev = temp;
}

// Xóa phần tử đầu danh sách
void deleteHead(Node** head) {
    if (*head == NULL) {
        printf("Danh sách rỗng, không thể xóa phần tử đầu.\n");
        return;
    }
    Node* temp = *head;
    *head = temp->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
    printf("Xóa phần tử đầu thành công.\n");
}

// Xóa phần tử cuối danh sách
void deleteEnd(Node** head) {
    if (*head == NULL) {
        printf("Danh sách rỗng, không thể xóa phần tử cuối.\n");
        return;
    }
    Node* temp = *head;
    if (temp->next == NULL) {
        *head = NULL;
        free(temp);
        printf("Xóa phần tử cuối thành công.\n");
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    printf("Xóa phần tử cuối thành công.\n");
}

//duyet list next
void printList(Node *head) {
	Node* temp = head;
	while(temp != NULL) {
		printf("%d <-> ",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

// Duyệt danh sáchprev
void printListReverse(Node* head) {
    if (head == NULL) {
        printf("Danh sách rỗng.\n");
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Giải phóng bộ nhớ
void freeList(Node** head) {
    Node* temp = *head;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    *head = NULL;
    printf("Giải phóng bộ nhớ thành công.\n");
}

int main() {
	
	Node* head = NULL;
	int choice;
	
	do {
		printf("==========================MENU================================\n");
		printf("0. Thoat\n");
		printf("1.Them 1 phan tu vao dau\n");
		printf("2.Them 1 phan tu vao cuoi\n");
		printf("3.Them 1 phan tu vao giua\n");
		printf("4. Xem danh sach\n");
		printf("5. Xóa phần tử đầu danh sách\n");
        printf("6. Xóa phần tử cuối danh sách\n");
        printf("7. Xem danh sách (từ đầu đến cuối)\n");
        printf("8. Xem danh sách (từ cuối lên đầu)\n");
        printf("9. Giải phóng danh sách\n");
		printf("Moi chon\n");
		
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				printf("Moi ban nhap gia tri phan tu de them vao dau danh sach: ");
				int value;
				scanf("%d", &value);
				insertHead(&head, value);
				break;
			case 2:				
				printf("Moi ban nhap gia tri phan tu de them vao cuoi danh sach: ");
				int value1;
				scanf("%d", &value1);
				insertEnd(&head, value1);
				break;
			case 3: 
				printf("Moi ban nhap vao vi tri can them\n");
				int pos;
				scanf("%d", &pos);
				printf("Moi ban nhap gia tri phan tu de them vao giua: ");
				int value2;
				scanf("%d", &value2);
				
				insertElement(&head, value2, pos);
				break;
			case 4:
				printf("Danh sach: ");
				printList(head);
				break;
			case 5:
                deleteHead(&head);
                break;
            case 6:
                deleteEnd(&head);
                break;
			case 7:
                printf("Danh sách ngược: ");
                printListReverse(head);
                break;
            case 8:
                freeList(&head);
                break;
			default: 
				printf("Ngu, chon lai diiiii\n");
		}
	}while(choice != 0);
	
	return 0;
}
