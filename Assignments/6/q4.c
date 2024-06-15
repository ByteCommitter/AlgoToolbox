#include <stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

void insertionSort(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void merge(int arr[], int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < len1 && j < len2) {
        if (left[i] <= right[j])
            arr[k] = left[i++];
        else
            arr[k] = right[j++];
        k++;
    }

    while (i < len1)
        arr[k++] = left[i++];

    while (j < len2)
        arr[k++] = right[j++];
}

void timSort(int arr[], int n, int k) {
    for (int i = 0; i < n; i+=k)
        insertionSort(arr, i, min(i+k-1, n-1));

    for (int size = k; size < n; size = 2*size) {
        for (int left = 0; left < n; left += 2*size) {
            int mid = left + size - 1;
            int right = min(left + 2*size - 1, n - 1);

            merge(arr, left, mid, right);
        }
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    timSort(arr, n, k);

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}