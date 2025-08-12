#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char b[9] = {'1','2','3','4','5','6','7','8','9'};

bool check(char p) {
    return (b[0]==p && b[1]==p && b[2]==p) ||
           (b[3]==p && b[4]==p && b[5]==p) ||
           (b[6]==p && b[7]==p && b[8]==p) ||
           (b[0]==p && b[3]==p && b[6]==p) ||
           (b[1]==p && b[4]==p && b[7]==p) ||
           (b[2]==p && b[5]==p && b[8]==p) ||
           (b[0]==p && b[4]==p && b[8]==p) ||
           (b[2]==p && b[4]==p && b[6]==p);
}

int main() {
    srand(time(0));
    int pos, turn = 0;
    while (turn < 9) {
        // show board
        for (int i = 0; i < 9; i++) {
            cout << b[i] << " ";
            if ((i+1)%3==0) cout << "\n";
        }
        cout << "Enter position (1-9): ";
        cin >> pos;

        if (pos<1 || pos>9 || b[pos-1]=='X' || b[pos-1]=='O') {
            cout << "Invalid!\n";
            continue;
        }

        b[pos-1] = 'X'; turn++;
        if (check('X')) { cout << "You win!\n"; break; }
        if (turn == 9) break;

        // computer move
        int c;
        do { c = rand()%9; } while (b[c]=='X' || b[c]=='O');
        b[c] = 'O'; turn++;
        cout << "Computer chose " << c+1 << "\n";

        if (check('O')) { 
            for (int i = 0; i < 9; i++) {
                cout << b[i] << " ";
                if ((i+1)%3==0) cout << "\n";
            }
            cout << "Computer wins!\n"; break; 
        }
    }
    if (turn==9 && !check('X') && !check('O')) cout << "Draw!\n";
}
