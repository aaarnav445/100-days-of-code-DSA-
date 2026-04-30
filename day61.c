#include <stdio.h>
#include <stdbool.h>

void dfs(int** isConnected, int n, int city, bool* visited) {
    visited[city] = true;

    for (int i = 0; i < n; i++) {
        if (isConnected[city][i] == 1 && !visited[i]) {
            dfs(isConnected, n, i, visited);
        }
    }
}

int findCircleNum(int** isConnected, int n) {
    bool visited[200] = {false};
    int provinces = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(isConnected, n, i, visited);
            provinces++;
        }
    }

    return provinces;
}

int main() {
    int n = 3;

    // Create matrix
    int a[3][3] = {
        {1,1,0},
        {1,1,0},
        {0,0,1}
    };

    // Convert to pointer array
    int* isConnected[3];
    for (int i = 0; i < n; i++) {
        isConnected[i] = a[i];
    }

    int result = findCircleNum(isConnected, n);

    printf("Provinces = %d\n", result);

    return 0;
}