#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define N 8

int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

void to_coordinates(char* position, int* x, int* y) {
    *x = position[0] - 'a';  
    *y = position[1] - '1';  
}

int bfs(int start_x, int start_y, int end_x, int end_y) {
    bool visited[N][N] = {false};  
    int queue[2 * N * N][2];  
    int front = 0, rear = 0; 
    int level[N][N] = {0};  

    queue[rear][0] = start_x;
    queue[rear][1] = start_y;
    rear++;
    visited[start_x][start_y] = true;

    while (front < rear) {
        int x = queue[front][0];
        int y = queue[front][1];
        front++;

        if (x == end_x && y == end_y) {
            return level[x][y];
        }

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]) {
                visited[nx][ny] = true;
                level[nx][ny] = level[x][y] + 1;
                queue[rear][0] = nx;
                queue[rear][1] = ny;
                rear++;
            }
        }
    }

    return -1;  
}

int main() {
    char start[3], end[3];
    while (scanf("%s %s", start, end) != EOF) {
        int start_x, start_y, end_x, end_y;
        to_coordinates(start, &start_x, &start_y);
        to_coordinates(end, &end_x, &end_y);

        if (start_x == end_x && start_y == end_y) {
            printf("To get from %s to %s takes 0 knight moves.\n", start, end);
        } else {
            int moves = bfs(start_x, start_y, end_x, end_y);
            printf("To get from %s to %s takes %d knight moves.\n", start, end, moves);
        }
    }

    return 0;
}
