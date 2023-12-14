#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 3

struct CircularQueue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

void initialize(struct CircularQueue *cq) {
    cq->front = -1;
    cq->rear = -1;
}

int isEmpty(struct CircularQueue *cq) {
    return cq->front == -1;
}

int isFull(struct CircularQueue *cq) {
    return (cq->rear + 1) % MAX_SIZE == cq->front;
}

void enqueue(struct CircularQueue *cq, int value) {
    if (isFull(cq)) {
        printf("Queue is full.\n");
    } else {
        if (isEmpty(cq)) {
            cq->front = 0;
        }
        cq->rear = (cq->rear + 1) % MAX_SIZE;
        cq->items[cq->rear] = value;
        printf("Enqueued: %d\n", value);
    }
}

void dequeue(struct CircularQueue *cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty.\n");
    } else {
        printf("Dequeued: %d\n", cq->items[cq->front]);
        if (cq->front == cq->rear) {
            // Reset the queue when the last element is dequeued
            initialize(cq);
        } else {
            cq->front = (cq->front + 1) % MAX_SIZE;
        }
    }
}

void display(struct CircularQueue *cq) {
    if (isEmpty(cq)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i = cq->front;
        while (i != cq->rear) {
            printf("%d ", cq->items[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", cq->items[cq->rear]);
    }
}

int main() {
    struct CircularQueue cq;
    initialize(&cq);

    int choice, value;
    while (1) {
        printf("\nCircular Queue Operations\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&cq, value);
                break;
            case 2:
                dequeue(&cq);
                break;
            case 3:
                display(&cq);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
