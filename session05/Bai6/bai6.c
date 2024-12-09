#include <stdio.h>
#include <stdlib.h>

// Dinh nghia 1 node
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Tao node moi
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
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

//Thay the gia tri phan tu
void replaceValue(Node** head, int value, int replace) {
    Node* temp = *head;
    
    // Duyet danh sach
    while (temp != NULL) {
        if (temp->data == value) {  
            temp->data = replace;    
            return;               
        }
        temp = temp->next;
    }
    
    printf("Khong tim thay gia tri %d trong danh sach.\n", value);
}

// Tao danh sach
Node* createLinkedList() {
    Node* head = NULL;
    int n, value;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        insertEnd(&head, value);
    }

    return head;
}

// Duyen danh sach theo next
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = createLinkedList();
    int value, replace;
    
    printf("Danh sach ban dau: \n");
    printList(head);
    
    printf("Nhap gia tri thay the: ");
    scanf("%d", &value);
    printf("Nhap gia tri muon thay the: ");
    scanf("%d", &replace);
	
	replaceValue(&head, value, replace);
	
	printf("Danh sach sau khi thay the: \n");
    printList(head);
    
    return 0;
}

