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
	int n;
	
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
	
	printList(head);
	
	return 0;
}
