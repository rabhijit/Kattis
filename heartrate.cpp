#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    int number;
    cin >> number;
    float minimum[number];
    float calculated[number];
    float maximum[number];
    int b;
    float p;
    for (int i = 0; i < number; i++) {
        cin >> b >> p;
        calculated[i] = (60 / p) * b;
        minimum[i] = calculated[i] - (60/p);
        maximum[i] = calculated[i] + (60/p);
    }

    for (int j = 0; j < number; j++) {
        printf("%0.4f %0.4f %0.4f\n", minimum[j], calculated[j], maximum[j]);
    }

}