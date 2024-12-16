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
    Node* newNode = createNode(value);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
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

// Chen danh sach con vao danh sach chinh
void insertSublist(Node** head1, Node* head2, int position) {
    if (*head1 == NULL || head2 == NULL) {
        printf("Danh sach chinh hoac danh sach con rong.\n");
        return;
    }

    // So luong phan tu danh sach chinh
    int count = 0;
    Node* temp1 = *head1;
    while (temp1 != NULL) {
        count++;
        temp1 = temp1->next;
    }

    // Kiem tra vi tri hop le
    if (position < 0 || position > count) {
        printf("Vi tri chen khong hop le.\n");
        return;
    }

    if (position == 0) {
        Node* last = head2;
        while (last->next != NULL) {
            last = last->next;
        }
        
        // Noi ds con vao ds chinh
        last->next = *head1;
        if (*head1 != NULL) {
            (*head1)->prev = last;
        }
        
        *head1 = head2; // Cap nhat head
        return;
    }

    temp1 = *head1;
    for (int i = 0; i < position - 1; i++) {
        temp1 = temp1->next;
    }

    Node* temp2 = head2;
    while (temp2->next != NULL) {
        temp2 = temp2->next;
    }

    temp2->next = temp1->next;
    if (temp1->next != NULL) {
        temp1->next->prev = temp2;
    }

    temp1->next = head2;
    head2->prev = temp1;
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

int main() {
    Node* head1 = createLinkedList();
    Node* head2 = createLinkedList();
    int position;
    
    printf("Danh sach chinh: \n");
    printList(head1);
    
    printf("Danh sach con: \n");
    printList(head2);
    
    printf("Nhap vi tri chen: ");
    scanf("%d", &position);
    
    insertSublist(&head1, head2, position);
    
    printf("Danh sach chinh sau khi chen: \n");
    printList(head1);
    
    return 0;
}

