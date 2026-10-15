#include <iostream>
using namespace std;

void print_sp(int i, int n) {
    for (int sp = 0; sp < n - i; sp++) {
        cout << " ";
    }
}

void print_num(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d",n);
    }
     printf("\n");
}

int main() {
    int rows = 6;

    for (int i = 0; i <= rows; i++) {
        print_sp(i, rows);
        print_num(i);
    }

    return 0;
}
