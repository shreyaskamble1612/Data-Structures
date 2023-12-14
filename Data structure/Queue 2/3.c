#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Deque {
    int items[MAX_SIZE];
    int front;
    int rear;
};

void initialize(struct Deque *dq) {
    dq->front = -1;
    dq->rear = -1;
}

int isEmpty(struct Deque *dq) {
    return dq->front == -1;
}

int isFull(struct Deque *dq) {
    return (dq->front == 0 && dq->rear == MAX_SIZE - 1) ||
           (dq->front == dq->rear + 1);
}

void insertFront(struct Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full.\n");
    } else {
        if (isEmpty(dq)) {
            dq->front = dq->rear = 0;
        } else if (dq->front == 0) {
            dq->front = MAX_SIZE - 1;
        } else {
            dq->front--;
        }
        dq->items[dq->front] = value;
        printf("Inserted at front: %d\n", value);
    }
}

void insertRear(struct Deque *dq, int value) {
    if (isFull(dq)) {
        printf("Deque is full.\n");
    } else {
        if (isEmpty(dq)) {
            dq->front = dq->rear = 0;
        } else if (dq->rear == MAX_SIZE - 1) {
            dq->rear = 0;
        } else {
            dq->rear++;
        }
        dq->items[dq->rear] = value;
        printf("Inserted at rear: %d\n", value);
    }
}

void deleteFront(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
    } else {
        printf("Deleted from front: %d\n", dq->items[dq->front]);
        if (dq->front == dq->rear) {
            
            initialize(dq);
        } else if (dq->front == MAX_SIZE - 1) {
            dq->front = 0;
        } else {
            dq->front++;
        }
    }
}

void deleteRear(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
    } else {
        printf("Deleted from rear: %d\n", dq->items[dq->rear]);
        if (dq->front == dq->rear) {
        
            initialize(dq);
        } else if (dq->rear == 0) {
            dq->rear = MAX_SIZE - 1;
        } else {
            dq->rear--;
        }
    }
}

void display(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty.\n");
    } else {
        printf("Deque elements: ");
        int i = dq->front;
        while (1) {
            printf("%d ", dq->items[i]);
            if (i == dq->rear) {
                break;
            }
            i = (i + 1) % MAX_SIZE;
        }
        printf("\n");
    }
}

int main() {
    struct Deque dq;
    initialize(&dq);

    int choice, value;
    while (1) {
        printf("\nDeque Operations\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                insertFront(&dq, value);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                insertRear(&dq, value);
                break;
            case 3:
                deleteFront(&dq);
                break;
            case 4:
                deleteRear(&dq);
                break;
            case 5:
                display(&dq);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
