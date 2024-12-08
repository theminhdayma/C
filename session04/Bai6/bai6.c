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

// Xoa phan tu theo vi tri
void deleteAtPosition(Node** head, int position) {
    if (*head == NULL) {
        printf("Danh sách r?ng\n");
        return;
    }

    Node* temp = *head;

    // Xóa ph?n t? d?u tiên
    if (position == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Duy?t d?n node tru?c v? trí c?n xóa
    Node* prev = NULL;
    int index = 0;
    while (temp != NULL && index < position) {
        prev = temp;
        temp = temp->next;
        index++;
    }

    // N?u v? trí không h?p l?
    if (temp == NULL) {
        printf("V? trí không h?p l?\n");
        return;
    }

    // Xóa node t?i v? trí
    prev->next = temp->next;
    free(temp);
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
	int n, pos;
	
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
	
	printf("Danh sanh ban dau: ");
	printList(head);
	
	printf("Nhap vi tri can xoa: ");
	scanf("%d", &pos);
	deleteAtPosition(&head, pos);
	
	printf("Danh sach sau khi xoa: ");
	printList(head);
	
	return 0;
}
