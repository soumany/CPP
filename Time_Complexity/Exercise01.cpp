#include <iostream>
#include <cstdlib> // include this header for `rand()` function
using namespace std;

void constantTime() {
    cout << "(a).Hello World.\n";
}

void linearTime(int n) {
    for (int i = 1; i <= n; i++) {
        cout << "(b).Hello World!!!\n";
    }
}

void logarithmicTime(int n) {
    int i = 1;
    while (i <= n) {
        cout << "(c).Hello World !!!\n";
        i = i * 2;
    }
}

void linearTime1(int a, int b, int n) {
    for (int i = 0; i < n; i++) {
        a = a + rand();
        cout << a << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        b = b + rand();
        cout << b << " ";
    }
    cout << endl;
}

void quadraticTime(int value, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            value += 1;
            cout << value << " ";
        }
    }
}

int main() {
    int a = 0, b = 0;
    int value = 0;
    int n;
  
    cout << "Enter n value: " << endl;
    cin >> n;

    constantTime();
    cout << "=========================\n";
    linearTime(n);
    cout << "=========================\n";
    logarithmicTime(n);
    cout << "=========================\n";
    linearTime1(a, b, n);
    cout << "=========================\n";
    quadraticTime(value, n);

    return 0;
}
