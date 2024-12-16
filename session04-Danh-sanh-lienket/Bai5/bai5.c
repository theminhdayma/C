#include <stdio.h>

typedef struct Node {
	int data;
	struct Node *next;
}Node;

Node* createNode(int value) {
		
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

// Them moi phan tu vao giua danh sach
void insertElement(Node** head, int value, int position) {
    Node* newNode = createNode(value);

    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    int index = 0;

    while (temp != NULL && index < position - 1) {
        temp = temp->next;
        index++;
    }

    if (temp == NULL) {
        printf("V? trí chèn không h?p l? (vu?t quá chi?u dài danh sách)\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

//duyet list
void printList(Node *head) {
	Node* temp = head;
	while(temp != NULL) {
		printf("%d -> ",temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

int main() {
	
	Node* head = NULL;
	int n,m,q;
	
	printf("Nhap n: ");
	scanf("%d", &n);
	
	int A[n];
	
	for(int i = 0; i < n; i++) {
		printf("A[%d]: ", i);
		scanf("%d", &A[i]);
	}
	
	for(int i = n - 1; i >= 0; i--) {
		insertHead(&head, A[i]);
	}
	
	printf("Danh sach ban dau: ");
	printList(head);
	
	printf("Nhap gia tri muon chen: ");
	scanf("%d", &m);
	printf("Nhap vi tri muon chen: ");
	scanf("%d", &q);
	
	insertElement(&head, m, q);
	printf("Danh sach sau khi chen: ");
	printList(head);
	
	return 0;
}
