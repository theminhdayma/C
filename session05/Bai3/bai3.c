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

// Xoa phan tu cuoi
void deleteLast(Node** head) {
    if (*head == NULL) {
        printf("Danh sach rong.\n");
        return;
    }

    // Neu chi co 1 phan tu
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    // Tìm ph?n t? k? cu?i
    Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    // Xóa ph?n t? cu?i
    Node* lastNode = temp->next;
    temp->next = NULL;
    free(lastNode);
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
    printf("Danh sach ban dau: \n");
    printList(head);
    
    deleteLast(&head);
    printf("Danh sach sau khi xoa phan tu cuoi cung: \n");
    printList(head);

    return 0;
}

