#include <stdio.h>
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void hashing(int table[], int tsize, int arr[], int N)
 {
    for (int i = 0; i < N; i++) {
        int hv = arr[i] % tsize;
        if (table[hv] == -1)
            table[hv] = arr[i];
        else
        {
            for (int j = 0; j < tsize; j++)
             {
                int t = (hv + j * j) % tsize;
                if (table[t] == -1) {
                    table[t] = arr[i];
                    break;
                }
            }
        }
    }
    printArray(table, N);
}

int main() {
 int N,L;
 printf("Enter table size:");
 scanf("%d",&L);
 int hash_table[L];
    for (int i = 0; i < L; i++) {
        hash_table[i] = -1;
    }
printf("Enter no of entries:");
 scanf("%d",&N);
 int arr[N];
 printf("Enter value:");
 for(int i=0;i<N;i++)
 {
     scanf("%d",&arr[i]);
 }
    hashing(hash_table, L, arr, N);
    return 0;
}
