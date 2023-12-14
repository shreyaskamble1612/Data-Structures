#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 4

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};


void initialize(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}


int isEmpty(struct Queue *q) {
    return q->front == -1;
}


int isFull(struct Queue *q) {
    return q->rear == MAX_SIZE - 1;
}


void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full.\n");
    } else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
        printf("Enqueued: %d\n", value);
    }
}


void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Dequeued: %d\n", q->items[q->front]);
        if (q->front == q->rear) {
            
            initialize(q);
        } else {
            q->front++;
        }
    }
}

void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Queue q;
    initialize(&q);

    int choice, value;
    while (1) {
        printf("\nQueue Operations\n");
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
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
