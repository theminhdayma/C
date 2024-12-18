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

// Them moi phan tu vao vi tri bat ky trong danh sach
void insertElement(Node** head, int value, int position) {
    Node* newNode = createNode(value); // Tạo node mới
    
    // Trường hợp thêm vào đầu danh sách
    if (position == 0 || *head == NULL) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    int i = 0;

    // Duyệt đến vị trí cần chèn hoặc đến node cuối cùng
    while (i < position - 1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }

    // Chèn node mới vào vị trí
    newNode->next = temp->next;
    temp->next = newNode;
}

// Xoa phan tu o dau danh sach
void deleteHead(Node** head) {
    if (*head == NULL) {
        printf("Danh sach rong, khong the xoa.\n");
        return;
    }
    Node* temp = *head; // Lưu con trỏ trỏ đến node đầu
    *head = (*head)->next; // Cập nhật head trỏ đến node tiếp theo
    free(temp); // Giải phóng bộ nhớ của node đầu
    printf("Da xoa phan tu dau danh sach.\n");
}

// Xoa phan tu o cuoi danh sach
void deleteEnd(Node** head) {
    if (*head == NULL) {
        printf("Danh sach rong, khong the xoa.\n");
        return;
    }

    // Trường hợp danh sách chỉ có 1 phần tử
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Da xoa phan tu cuoi danh sach.\n");
        return;
    }

    Node* temp = *head;
    // Duyệt đến node kế cuối
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next); // Giải phóng node cuối
    temp->next = NULL; // Cập nhật node kế cuối thành NULL
    printf("Da xoa phan tu cuoi danh sach.\n");
}

// Tim kiem phan tu trong danh sach
void searchElement(Node* head, int key) {
    Node* temp = head;
    int position = 0; 
    int found = 0;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Phan tu %d tim thay tai vi tri %d.\n", key, position);
            found = 1;
        }
        temp = temp->next;
        position++;
    }

    if (!found) {
        printf("Khong tim thay phan tu %d trong danh sach.\n", key);
    }
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
		printf("5. Xoa phan tu dau danh sach\n");
		printf("6. Xoa phan tu cuoi danh sach\n");
		printf("7. Tim kiem mot phan tu\n");
		printf("Moi chon\n");
		
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				// Th�m 1 phan tu vao dau danh sach 
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
			case 5:
				// Xóa phần tử đầu danh sách
				deleteHead(&head);
				break;

			case 6:
				// Xóa phần tử cuối danh sách
				deleteEnd(&head);
				break;
			case 7: 
				// Tìm kiếm phần tử trong danh sách
				printf("Nhap vao phan tu can tim: ");
				int key;
				scanf("%d", &key);
				searchElement(head, key);
				break;
			default: 
				printf("Ngu, chon lai diiiii\n");
		}
	}while(choice != 0);
	
	return 0;
}
