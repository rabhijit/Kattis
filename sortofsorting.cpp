#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<string>> list_of_names;
    int input_number;
    cin >> input_number;
    while (input_number != 0) {
        vector<string> input;
        for (int i = 0; i < input_number; i++) {
            string input_name;
            cin >> input_name;
            input.push_back(input_name);
        }
        list_of_names.push_back(input);
        cin >> input_number;
    }
    for (int j = 0; j < list_of_names.size(); j++) {
        vector<string> each_list = list_of_names.at(j);
        bool swaps = true;
        while (swaps) {
            swaps = false;
            for (int k = 0; k < each_list.size() - 1; k++) {
                if (each_list.at(k)[0] > each_list.at(k+1)[0]) {
                    swap(each_list.at(k), each_list.at(k+1));
                    swaps = true;
                }
                else if ((each_list.at(k)[0] == each_list.at(k + 1)[0]) && (each_list.at(k)[1] > each_list.at(k + 1)[1])) {
                    swap(each_list.at(k), each_list.at(k + 1));
                    swaps = true;
                }
            }
        }
        for (int m = 0; m < each_list.size(); m++) {
            cout << each_list.at(m) << endl;
        }
        if (j != (list_of_names.size() - 1)) {
            cout << endl;
        }
    }
}