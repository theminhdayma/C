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

// Xoa cac phan tu chan 
void deleteEven(Node** head) {
    Node* temp = *head;
    
    while (temp != NULL) {
        if (temp->data % 2 == 0) { 
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            } else {
                *head = temp->next;
            }
            
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            
            temp = temp->next;
        } else {
            temp = temp->next;
        }
    }
}

// Sap xep danh sach tang dan
void sortList(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    Node* temp1 = *head;
    Node* temp2;
    
    while (temp1 != NULL) {
        temp2 = temp1->next;
        while (temp2 != NULL) {
            if (temp1->data > temp2->data) {
                
                int tempData = temp1->data;
                temp1->data = temp2->data;
                temp2->data = tempData;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
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

	deleteEven(&head);  
    sortList(&head);  

    printf("Danh sach sau khi xoa so chan va sap xep: \n");
    printList(head);
    
    return 0;
}
