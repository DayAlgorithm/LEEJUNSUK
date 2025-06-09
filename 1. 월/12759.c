#include <stdio.h>

int board[3][3] = {0};

int is_win(int player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;

    return 0;
}

int main(void) {
    int turn;
    scanf("%d", &turn);

    for (int i = 0; i < 9; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        r--; c--; 

        board[r][c] = turn;

        if (is_win(turn)) {
            printf("%d\n", turn);  
            return 0;
        }

        turn = (turn == 1) ? 2 : 1;
    }

    printf("0\n");  
    return 0;
}
