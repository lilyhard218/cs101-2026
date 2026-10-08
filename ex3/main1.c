#include <iostream>
using namespace std;

void print_sp(int i, int n) {
    for (int j = 0; j < n - i; j++) {
        cout << " ";
    }
}

void print_num(int n) {
    for (int j = 0; j < n; j++) {
        cout << n;
        if (j < n - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

int main() {
    int rows = 6;

    for (int i = 1; i <= rows; i++) {
        print_sp(i, rows);
        print_num(i);
    }

    return 0;
}
