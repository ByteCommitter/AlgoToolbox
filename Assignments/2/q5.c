#include <stdio.h>

int find_block(int N, int K, int blocks[N][N]) {
    int left = 0, right = N * N - 1;
    while (left <= right) {
        int mid =(left+right)/ 2;
        if (blocks[mid / N][mid % N] == K) {
            return 1;
        } else if (blocks[mid / N][mid % N] < K) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}

int main() {
    int N;
    scanf("%d", &N);
    int blocks[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &blocks[i][j]);
        }
    }

    if (find_block(N, K, blocks)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}