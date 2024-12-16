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

//Tim gia tri lon nhat
int searchMaxValue(Node* head) {
    if (head == NULL) {
        printf("Danh sach rong.\n");
        return -1; 
    }

    int max = head->data; 
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data > max) {
            max = temp->data;
        }
        temp = temp->next;
    }

    return max;
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
	
	printf("Danh sach: ");
	printList(head);
	
	int value = searchMaxValue(head);
	
	printf("Gia tri lon nhat trong danh sach la: %d", value);
	
	return 0;
}
