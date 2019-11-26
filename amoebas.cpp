/*
A0181059A
Abhijit Ravichandran
Lab Group 13
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 110

int rows, cols;
int dr[] = { 0, 1, 0,-1, -1, 1, -1, 1}; // E/S/W/N
int dc[] = {-1, 0, 1, 0, -1, 1, 1, -1};
char grid[MAX][MAX];

void flood_fill(int r, int c) {
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '.') return;
    grid[r][c] = '.';
    for (int d = 0; d < 8; d++) {
        flood_fill(r+dr[d], c+dc[d]);
    }
}

int main() {
    scanf("%d %d", &rows, &cols);
    for (int i = 0; i < rows; i++) {
        scanf("%s", &grid[i]);
    }
    int ans = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            if (grid[i][j] == '#') {
                ans++;
                flood_fill(i, j);
        }
    }
    printf("%d\n", ans);
}



