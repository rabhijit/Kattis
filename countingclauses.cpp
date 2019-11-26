#include <iostream>
#include <string>
using namespace std;

int main() {
    int clauses, variables;
    int trash1, trash2, trash3;
    cin >> clauses >> variables;
    for (int i = 0; i < clauses; i++) {
        cin >> trash1 >> trash2 >> trash3;
    }
    if (clauses >= 8) {
        cout << "satisfactory" << endl;
    }
    else {
        cout << "unsatisfactory" << endl;
    }

}