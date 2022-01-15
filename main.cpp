#include <iostream>
#include <stdlib.h>
#include <math.h>
#include "Complex.h"
using namespace std;

int main(int argc, char *argv[]) {
    int N = atoi(argv[1]);
    cout << N << " complex roots of unity" << endl;
    for (int k = 0; k < N; k++) {
        double theta = 2.0*3.14159*k/N;
        Complex t(cos(theta), sin(theta));
        Complex x = t;
        cout << k << ": " << t << " ";
        for (int j = 0; j < N; j++) {
            x *= t;
        }
        cout << x << endl;
    }
}
