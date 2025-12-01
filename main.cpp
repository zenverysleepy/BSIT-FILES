#include <iostream>
using namespace std;

int main() {

    string usernames[10];
    string passwords[10];
    int userCount = 0;

    while (true) {
        int choice;
        cout << "\n==== Tic Tac Toe ====\n";
        cout << "1. Sign Up\n";
        cout << "2. Sign In\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            string u, p;
            cout << "Enter username: ";
            cin >> u;
            cout << "Enter password: ";
            cin >> p;

            int exists = 0;
            for (int i = 0; i < userCount; i++) {
                if (usernames[i] == u) {
                    exists = 1;
                }
            }

            if (exists == 1) {
                cout << "Username already exists!\n";
            } else {
                usernames[userCount] = u;
                passwords[userCount] = p;
                userCount++;
                cout << "Sign up successful!\n";
            }
        }
        else if (choice == 2) {

            string u, p;
            cout << "Username: ";
            cin >> u;
            cout << "Password: ";
            cin >> p;

            int ok = 0;
            for (int i = 0; i < userCount; i++) {
                if (usernames[i] == u && passwords[i] == p) {
                    ok = 1;
                }
            }

            if (ok == 1) {
                cout << "Welcome " << u << "!\n";

                char again = 'y';
                while (again == 'y' || again == 'Y') {

                    char board[3][3] = {
                        {'1','2','3'},
                        {'4','5','6'},
                        {'7','8','9'}
                    };

                    char player = 'X';
                    int moves = 0;

                    while (moves < 9) {

                        cout << "\n";
                        for (int i = 0; i < 3; i++) {
                            cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
                            if (i < 2) cout << "-----------\n";
                        }

                        int pos;
                        cout << "Player " << player << " choose 1-9: ";
                        cin >> pos;

                        int row = (pos - 1) / 3;
                        int col = (pos - 1) % 3;

                        if (board[row][col] != 'X' && board[row][col] != 'O') {
                            board[row][col] = player;
                            moves++;

                            int win = 0;

                            if (board[0][0] == player && board[0][1] == player && board[0][2] == player) win = 1;
                            if (board[1][0] == player && board[1][1] == player && board[1][2] == player) win = 1;
                            if (board[2][0] == player && board[2][1] == player && board[2][2] == player) win = 1;

                            if (board[0][0] == player && board[1][0] == player && board[2][0] == player) win = 1;
                            if (board[0][1] == player && board[1][1] == player && board[2][1] == player) win = 1;
                            if (board[0][2] == player && board[1][2] == player && board[2][2] == player) win = 1;

                            if (board[0][0] == player && board[1][1] == player && board[2][2] == player) win = 1;
                            if (board[0][2] == player && board[1][1] == player && board[2][0] == player) win = 1;

                            if (win == 1) {
                                cout << "\n";
                                for (int i = 0; i < 3; i++) {
                                    cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << "\n";
                                    if (i < 2) cout << "-----------\n";
                                }
                                cout << "\nPlayer " << player << " wins!\n";
                                break;
                            }

                            if (player == 'X') player = 'O';
                            else player = 'X';
                        }
                        else {
                            cout << "Spot already taken!\n";
                        }
                    }

                    if (moves == 9) {
                        cout << "\nIt's a draw!\n";
                    }

                    cout << "Play again? (y/n): ";
                    cin >> again;
                }

            } else {
                cout << "Wrong username or password!\n";
            }
        }
        else if (choice == 3) {
            cout << "Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
