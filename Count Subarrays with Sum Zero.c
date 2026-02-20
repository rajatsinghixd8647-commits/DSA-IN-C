#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long count = 0;
    long long prefixSum = 0;

    int offset = 100000;
    int size = 200001;
    int *freq = (int *)calloc(size, sizeof(int));

    freq[offset] = 1;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];
        count += freq[prefixSum + offset];
        freq[prefixSum + offset]++;
    }

    printf("%lld", count);

    free(arr);
    free(freq);
    return 0;
}