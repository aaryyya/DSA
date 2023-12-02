#include <stdio.h>
#include <stdbool.h>

#define size 11
#define Empty -1
#define Deleted -2

int table[size];

int hash1(int key) {
    return key % size;
}

int hash2(int key) {
    return (1 + (key % (size- 1)));
}

int  insert(int key) {
    if (key == Empty || key == Deleted ){
        printf("Key cannot be %d or %d.\n", Empty, Deleted);
        return 0;
    }

    int index = hash1(key);
    int h2 = hash2(key);
    int startIndex = index;

    while (table[index] != Empty&& table[index] != Deleted) {
        index = (index + h2) % size;
        if (index == startIndex) {
            return 0;
        }
    }

    table[index] = key;
    return 1;
}

void display() {
    for (int i = 0; i < size; i++) {
        if (table[i] != Empty && table[i] != Deleted) {
            printf("%d: %d\n", i, table[i]);
        } else {
            printf("%d: -\n", i);
        }
    }
}

int main() {
    for (int i = 0; i < size; i++) {
        table[i] = Empty;
    }

    int n, key;
    printf("How many numbers do you want to insert? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter key %d: ", i + 1);
        scanf("%d", &key);

        if (!insert(key)) {
            printf("Table is full or key already exists. Couldn't insert key %d.\n", key);
        }
    }

    printf("\nHashTable:\n");
    display();

    return 0;
}
