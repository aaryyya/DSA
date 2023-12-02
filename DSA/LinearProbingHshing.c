#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    int key;
    int value;
} Hash;

Hash* Array[SIZE];
Hash* Item;

int hash(int key) {
    return key % SIZE;
}

void insert(int key, int value) {
    Hash* item = (Hash*) malloc(sizeof(Hash));
    item->key = key;
    item->value = value;

    int index = hash(key);
    while(Array[index] != NULL && Array[index]->key != -1) {
        index++;
        index %= SIZE;
    }
    Array[index] = item;
}

 struct Hash* search(int key) {
    int index = hash(key);
    while(Array[index] != NULL) {
        if(Array[index]->key == key) {
            return Array[index];
        }
        index++;
        index %= SIZE;
    }
    return NULL;
}

void display() {
    for(int i = 0; i < SIZE; i++) {
        if(Array[i] != NULL && Array[i]->key != -1) {
            printf(" (%d,%d)", Array[i]->key, Array[i]->value);
        } else {
            printf(" --");
        }
    }
    printf("\n");
}

int main() {
    Item = (Hash*) malloc(sizeof(Hash));
    Item->key = -1;
    Item->value = -1;

    int choice, key, value;

    while(1) {
        printf("\nHash Table Operations using Linear Probing\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter key and value: ");
                scanf("%d %d", &key, &value);
                insert(key, value);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                Hash* item = search(key);
                if(item != NULL) {
                    printf("Element found: %d\n", item->value);
                } else {
                    printf("Element not found\n");
                }
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}
