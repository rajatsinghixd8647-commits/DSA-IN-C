#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000
#define HASH_SIZE 20011

// Hash map entry
typedef struct Entry {
    int prefix_sum;
    int index;
    struct Entry* next;
} Entry;

Entry* hashMap[HASH_SIZE];

// Hash function
int hashFunc(int key) {
    return abs(key % HASH_SIZE);
}

// Insert into hash map (only if not already present)
void insert(int prefix_sum, int index) {
    int h = hashFunc(prefix_sum);
    Entry* curr = hashMap[h];
    while (curr) {
        if (curr->prefix_sum == prefix_sum) return; // keep first occurrence
        curr = curr->next;
    }
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    newEntry->prefix_sum = prefix_sum;
    newEntry->index      = index;
    newEntry->next       = hashMap[h];
    hashMap[h]           = newEntry;
}

// Search hash map
int search(int prefix_sum) {
    int h = hashFunc(prefix_sum);
    Entry* curr = hashMap[h];
    while (curr) {
        if (curr->prefix_sum == prefix_sum) return curr->index;
        curr = curr->next;
    }
    return INT_MIN; // not found
}

// Free hash map memory
void freeMap() {
    for (int i = 0; i < HASH_SIZE; i++) {
        Entry* curr = hashMap[i];
        while (curr) {
            Entry* tmp = curr;
            curr = curr->next;
            free(tmp);
        }
        hashMap[i] = NULL;
    }
}

int longestZeroSumSubarray(int* arr, int n) {
    memset(hashMap, 0, sizeof(hashMap));

    insert(0, -1);  // prefix sum 0 exists before index 0

    int prefixSum = 0;
    int maxLen    = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        int prevIndex = search(prefixSum);

        if (prevIndex != INT_MIN) {
            // subarray from (prevIndex+1) to i has sum = 0
            int len = i - prevIndex;
            if (len > maxLen) maxLen = len;
        } else {
            insert(prefixSum, i);
        }
    }

    freeMap();
    return maxLen;
}

int main() {
    int arr[MAX_SIZE];
    int n = 0;

    printf("Enter array elements (press Enter after last number, Ctrl+Z/Ctrl+D to finish):\n");

    while (scanf("%d", &arr[n]) == 1) {
        n++;
    }

    if (n == 0) {
        printf("Empty array!\n");
        return 1;
    }

    printf("\nArray: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    int result = longestZeroSumSubarray(arr, n);
    printf("Length of longest subarray with sum 0: %d\n", result);

    // Print the actual subarray
    if (result > 0) {
        memset(hashMap, 0, sizeof(hashMap));
        insert(0, -1);

        int prefixSum = 0, start = -1, end = -1;

        for (int i = 0; i < n; i++) {
            prefixSum += arr[i];
            int prevIndex = search(prefixSum);

            if (prevIndex != INT_MIN) {
                if (i - prevIndex == result) {
                    start = prevIndex + 1;
                    end   = i;
                    break;
                }
            } else {
                insert(prefixSum, i);
            }
        }

        freeMap();

        if (start != -1) {
            printf("Subarray: [");
            for (int i = start; i <= end; i++) {
                printf("%d", arr[i]);
                if (i < end) printf(", ");
            }
            printf("]\n");
        }
    }

    return 0;
}
