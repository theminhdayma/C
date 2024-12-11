#include <stdio.h>
#include <stdlib.h>


// Cau truc danh sach lien ket doi
typedef struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
} Node;

// Cau truc ham doi 
typedef struct Queue {
	Node* front;
	Node* rear;
} Queue;

//Khoi tao ham doi rong
void initializeQueue(Queue *queue) {
	queue->front = NULL;
	queue->rear = NULL;
}

//Kiemtra ham doi 
int isEmpty(Queue *queue) {
	return queue->front == NULL;
}

// Them vao hang doi
void enqueue(Queue *queue, int value) {
	Node *newNode = (Node*) malloc(sizeof(Node));
	if(!newNode) {
		printf("Khong du bo nho de cap phat\n");
		return;
	}
	
	newNode->data = value;
	newNode->next = NULL;
	newNode->prev = queue->rear;
	
	if(isEmpty(queue)) {
		queue->front = newNode;
	} else {
		queue->rear = newNode;
	}
	queue->rear = newNode;
	printf("Da them %d vao hang doi\n", value);
	
}

//Xoa khoi hang doi
void dequeue(Queue *queue) {
	if(isEmpty(queue)) {
		printf("Hang doi rong \n");
		return -1;
	} else {
		Node *temp = queue->front;
		int value = temp->data;
		queue->front = queue->front->next;

		if(queue->front == NULL) {
			queue->rear = NULL;
		} else {
			queue->front->prev = NULL;
		}

		free(temp);
		return value;
	}
}

// In cac phan tu trong hang doi
void printQueue(Queue *queue) {
	if(isEmpty(queue)) {
		printf("Hang doi rong\n");
	} else {
		Node *curent = queue->front;
		while (curent != NULL)
		{
			printf("%d", curent->data);
			curent = curent->next;
		}
	}
}

int main() {
	Queue queue;
	initializeQueue(&queue);

	int value;
	printf("Nhap gia tri de them vao hang doi: ");
	scanf("%d", &value);
	enqueue(&queue, value);
	if(isEmpty(&queue)) {
		printf("Ham doi rong\n");
	} else {
		printf("Ham doi khong rong\n");
	}

	dequeue(&queue);
	if(isEmpty(&queue)) {
		printf("Ham doi rong\n");
	} else {
		printf("Ham doi khong rong\n");
	}

	return 0;
}

