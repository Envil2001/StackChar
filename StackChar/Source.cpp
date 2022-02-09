#include <iostream> 
#include <stdlib.h> 
#include <conio.h> 
using namespace std;

#define MAX_SIZE 20
char s[MAX_SIZE]; // компоненти стека
int next = 0; // позиц≥€ стека

struct tstk {
    int inf;
    tstk* a;
};

tstk* add(tstk* sp, int inf) {
    tstk* spt = new tstk;
    spt->inf = inf;
    spt->a = sp;
    return spt;
}

void push(int* mas, int n, int max) {
    tstk* stek = new tstk;
    int x = 0;
    for (int i = 0; i < n; i++) {
        stek->inf = mas[i];
        cout << stek->inf << ' ';
        if (stek->inf == max)
            cout << x << " ";
    }
}

void add1(tstk* sp, int n) { // tstk *t; 
    int* mas = new int[n];

    unsigned int max = 0;
    for (int i = 0; i < n; i++) {
        mas[i] = sp->inf;
        sp = sp->a;
        if (mas[i] > max) {
            max = mas[i];
        }
    }
    cout << "max number is " << max << endl;

    push(mas, n, max);
}

void delstack(tstk* sp) {
    tstk* t;
    while (t = sp) {
        sp = sp->a;
        delete t;
    }
}

void showstack(tstk* sp) {
    while (sp) {
        cout << sp->inf << " ";
        sp = sp->a;
    }
    cout << endl;
}


void main() {
    setlocale(LC_ALL, "Russian");

    tstk* sp = NULL;
    int n, k;
    cout << "введите n-количество элементов" << endl;
    cin >> n;
    while (n <= 0) { cout << "ќшибка! ¬ведите N больше 0:"; cin >> n; }

    for (int i = 0; i < n; i++) {
        cout << "write number ";
        cin >> s[i];
        sp = add(sp, s[i]);
    }

    showstack(sp);
    cout << endl;
    add1(sp, n);
}