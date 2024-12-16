#include <stdio.h>

// Dinh nghia 1 node
typedef struct Node {
	int data; // Du lieu cua node
	struct Node *next; // Con tro chi den node tiep theo
}Node;

// Tao node moi
Node* createNode(int value) {
	// Cap phat bo nho
	Node *newNode = (Node*) malloc(sizeof(Node));
	// gan data cho Node
	newNode->data = value;
	// gan vi tri cho Node 
	newNode->next = NULL;
	return newNode;
}

// Them 1 phan tu vao dau list
void insertHead(Node** head, int value) {
	//Tao nut moi
	Node* newNode = createNode(value);
	// tro node moi den head
	newNode->next = *head;
	//cap nhat head tro den not moi
	*head = newNode;
}

// Them 1 phan tu o cuoi dnah sanh
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
}

// Them moi phan tu vao giua danh sach
void insertElement(Node** head, int value, int position) {
	Node* newNode = createNode(value);
	
	if(position == 0) {
		newNode->next = *head;
		*head = newNode;
		return;
	}
	
	Node* temp = *head;
	for(int i = 0; i < position - 1 && temp == NULL; i ++) {
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
}

//duyet list
void printList(Node *head) {
	Node* temp = head;
	while(temp != NULL) {
		printf("%d-> ",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

int main() {
	
	Node* head = NULL;
	int choice;
	
	do {
		printf("==========================MENU================================\n");
		printf("0. Thoat\n");
		printf("1. Them 1 phan tu vao dau\n");
		printf("2. Xem danh sach\n");
		printf("3.Them 1 phan tu vao cuoi\n");
		printf("4.Them 1 phan tu vao giua\n");
		printf("Moi chon\n");
		
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				// Thêm 1 phan tu vao dau danh sach 
				printf("Moi ban nhap vao phan tu dau: ");
				int value;
				scanf("%d", &value);
				//Them vao dau danh sach
				insertHead(&head, value);
				break;
			case 2:				
				//in ra
				printf("Danh sach: \n");
				printList(head);
				break;
			case 3: 
				// Them vao cuoi danh sanh
				printf("Moi ban nhap vao phan tu cuoi: ");
				int value1;
				scanf("%d", &value1);
				//Them vao cuoi
				insertEnd(&head, value1);
				break;
			case 4:
				printf("Moi ban nhap vao vi tri can them\n");
				int pos;
				scanf("%d", &pos);
				printf("Moi ban nhap vao phan tu giua: ");
				int value2;
				scanf("%d", &value2);
				
				insertElement(&head, value2, pos);
				break;
				
			default: 
				printf("Ngu, chon lai diiiii\n");
		}
	}while(choice != 0);
	
	return 0;
}
