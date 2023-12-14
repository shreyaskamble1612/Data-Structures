#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

struct Heap {
    int data[MAX_HEAP_SIZE];
    int size;
};

void initializeHeap(struct Heap* heap) {
    heap->size = 0;
}

void displayHeap(struct Heap* heap) {
    if (heap->size == 0) {
        printf("Heap is empty.\n");
        return;
    }

    printf("Heap elements: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

void reheapUp(struct Heap* heap, int index) {
    int parent;
    if (index > 0) {
        parent = (index - 1) / 2;
        if (heap->data[index] < heap->data[parent]) {
            int temp = heap->data[index];
            heap->data[index] = heap->data[parent];
            heap->data[parent] = temp;
            reheapUp(heap, parent);
        }
    }
}

void reheapDown(struct Heap* heap, int index) {
    int leftChild, rightChild, minChild;
    leftChild = 2 * index + 1;
    rightChild = 2 * index + 2;
    
    if (leftChild < heap->size) {
        if (rightChild < heap->size && heap->data[rightChild] < heap->data[leftChild]) {
            minChild = rightChild;
        } else {
            minChild = leftChild;
        }
        
        if (heap->data[index] > heap->data[minChild]) {
            int temp = heap->data[index];
            heap->data[index] = heap->data[minChild];
            heap->data[minChild] = temp;
            reheapDown(heap, minChild);
        }
    }
}

void insertHeap(struct Heap* heap, int value) {
    if (heap->size < MAX_HEAP_SIZE) {
        heap->data[heap->size] = value;
        reheapUp(heap, heap->size);
        heap->size++;
        printf("Inserted %d into the heap.\n", value);
    } else {
        printf("Heap is full. Cannot insert %d.\n", value);
    }
}

int deleteHeap(struct Heap* heap) {
    if (heap->size > 0) {
        int deletedValue = heap->data[0];
        heap->data[0] = heap->data[heap->size - 1];
        heap->size--;
        reheapDown(heap, 0);
        return deletedValue;
    } else {
        printf("Heap is empty. Cannot delete.\n");
        return -1;
    }
}

int main() {
    struct Heap heap;
    initializeHeap(&heap);

    int choice, value;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert into Heap\n");
        printf("2. Delete from Heap\n");
        printf("3. Display Heap\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertHeap(&heap, value);
                break;
            case 2:
                value = deleteHeap(&heap);
                if (value != -1) {
                    printf("Deleted value from heap: %d\n", value);
                }
                break;
            case 3:
                displayHeap(&heap);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
