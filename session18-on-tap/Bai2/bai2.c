#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Them vao dau danh sach
Node *addAtHead(Node *head, int data) {
    Node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

//Them vao cuoi danh sach
Node *addAtTail(Node *head, int data) {
    Node *newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

// Xoa phan tu theo vi tri
Node *deleteAtPosition(Node *head, int position) {
    if (head == NULL) {
        printf("Danh sach rong.\n");
        return head;
    }
    if (position == 0) {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node *temp = head;
    for (int i = 0; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Vi tri khong hop le.\n");
        return head;
    }
    Node *nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    return head;
}

// Tim kiem
int searchElement(Node *head, int key) {
    Node *temp = head;
    int position = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}

// Cap nhat
void updateElement(Node *head, int position, int newValue) {
    Node *temp = head;
    for (int i = 0; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    temp->data = newValue;
}

// In danh sach
void displayList(Node *head) {
    if (head == NULL) {
        printf("Danh sach rong.\n");
        return;
    }
    Node *temp = head;
    printf("Danh sach lien ket: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    int choice, data, position;

    do {
        printf("\nMenu:\n");
        printf("1. Them phan tu vao dau\n");
        printf("2. Them phan tu vao cuoi\n");
        printf("3. Xoa phan tu tai vi tri\n");
        printf("4. Tim kiem phan tu\n");
        printf("5. Cap nhat phan tu\n");
        printf("6. Hien thi danh sach\n");
        printf("7. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Nhap gia tri can them: ");
            scanf("%d", &data);
            head = addAtHead(head, data);
            break;
        case 2:
            printf("Nhap gia tri can them: ");
            scanf("%d", &data);
            head = addAtTail(head, data);
            break;
        case 3:
            printf("Nhap vi tri can xoa: ");
            scanf("%d", &position);
            head = deleteAtPosition(head, position);
            break;
        case 4:
            printf("Nhap gia tri can tim: ");
            scanf("%d", &data);
            position = searchElement(head, data);
            if (position != -1) {
                printf("Phan tu %d o vi tri %d.\n", data, position);
            } else {
                printf("Khong tim thay phan tu %d.\n", data);
            }
            break;
        case 5:
            printf("Nhap vi tri can cap nhat: ");
            scanf("%d", &position);
            printf("Nhap gia tri moi: ");
            scanf("%d", &data);
            updateElement(head, position, data);
            break;
        case 6:
            displayList(head);
            break;
        case 7:
            printf("Thoat chuong trinh.\n");
            break;
        default:
            printf("Lua chon khong hop le.\n");
        }
    } while (choice != 7);

    return 0;
}
