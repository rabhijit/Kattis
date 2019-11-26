#include <iostream>
#include <cmath>
using namespace std;

// read every 5 chars, skip 1, read next 5...

int number_reader(char ascii_number[7][6]) {
    int x_count = 0;
    int dot_count = 0;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 5; j++) {
            if (ascii_number[i][j] == 'x') {
                x_count++;
            }
            else if (ascii_number[i][j] == '.') {
                dot_count++;
            }
        }
    }

    if (x_count == 20) {
        return 0;
    }
    else if (x_count == 7) {
        return 1;
    }
    else if (x_count == (35-16) && ascii_number[2][4] == 'x' && ascii_number[4][0] == 'x') {
        return 2;
    }
    else if (x_count == (35-16) && ascii_number[2][4] == 'x' && ascii_number[4][4] == 'x') {
        return 3;
    }
    else if (x_count == (35-21)) {
        return 4;
    }
    else if (x_count == (35-16) && ascii_number[2][0] == 'x' && ascii_number[4][4] == 'x') {
        return 5;
    }
    else if (x_count == (35-14) && ascii_number[1][0] == 'x' && ascii_number[1][4] != 'x') {
        return 6;
    }
    else if (x_count == 11) {
        return 7;
    }
    else if (x_count == (35-12)) {
        return 8;
    }
    else if (x_count == (35-14) && ascii_number[1][4] == 'x') {
        return 9;
    }
    else if (x_count == 9) {
        return -1; // plus operator
    }
}

void ascii_creator(int result)
{
    string result_string = to_string(result);
    string zero[7] = {"xxxxx",
                      "x...x",
                      "x...x",
                      "x...x",
                      "x...x",
                      "x...x",
                      "xxxxx"};

    string one[7] = {"....x",
                     "....x",
                     "....x",
                     "....x",
                     "....x",
                     "....x",
                     "....x"};

    string two[7] = {"xxxxx",
                     "....x",
                     "....x",
                     "xxxxx",
                     "x....",
                     "x....",
                     "xxxxx"};

    string three[7] = {"xxxxx",
                       "....x",
                       "....x",
                       "xxxxx",
                       "....x",
                       "....x",
                       "xxxxx"};

    string four[7] = {"x...x",
                      "x...x",
                      "x...x",
                      "xxxxx",
                      "....x",
                      "....x",
                      "....x"};

    string five[7] = {"xxxxx",
                      "x....",
                      "x....",
                      "xxxxx",
                      "....x",
                      "....x",
                      "xxxxx"};

    string six[7] = {"xxxxx",
                     "x....",
                     "x....",
                     "xxxxx",
                     "x...x",
                     "x...x",
                     "xxxxx"};

    string seven[7] = {"xxxxx",
                       "....x",
                       "....x",
                       "....x",
                       "....x",
                       "....x",
                       "....x"};

    string eight[7] = {"xxxxx",
                       "x...x",
                       "x...x",
                       "xxxxx",
                       "x...x",
                       "x...x",
                       "xxxxx"};

    string nine[7] = {"xxxxx",
                      "x...x",
                      "x...x",
                      "xxxxx",
                      "....x",
                      "....x",
                      "xxxxx"};

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < result_string.size(); j++)
        {
            if (result_string[j] == '1')
            {
                cout << one[i];
            }
            if (result_string[j] == '2')
            {
                cout << two[i];
            }
            if (result_string[j] == '3')
            {
                cout << three[i];
            }
            if (result_string[j] == '4')
            {
                cout << four[i];
            }
            if (result_string[j] == '5')
            {
                cout << five[i];
            }
            if (result_string[j] == '6')
            {
                cout << six[i];
            }
            if (result_string[j] == '7')
            {
                cout << seven[i];
            }
            if (result_string[j] == '8')
            {
                cout << eight[i];
            }
            if (result_string[j] == '9')
            {
                cout << nine[i];
            }
            if (result_string[j] == '0')
            {
                cout << zero[i];
            }
            if (j != (result_string.size() -1 )) {
                cout << "."; }
        }
        cout << endl;
    }
}

int main() {
    char input_digits[100][7][6];
    char *initial_input;
    initial_input = (char*)new char;
    int digit_count;
    for (int i = 0; i < 7; i++) {
        cin >> initial_input;
        int j = 0;
        int k = 0;
        digit_count = 0;
        while (initial_input[j] != '\0') {
            if (j == (5 + (digit_count * 6))) {
                k = 0;
                digit_count++;
            }
            else {
                input_digits[digit_count][i][k] = initial_input[j];
                k++;
            }
            j++;
        }
    }

    long translated_left = 0;
    long translated_right = 0;
    int m = 0;
    int n = 0;

    int left_length = 0;
    int right_length = 0;

    while (number_reader(input_digits[n]) != -1) {
        n++;
    }

    left_length = n;
    right_length = digit_count - n;

    while (number_reader(input_digits[m]) != -1) {
        translated_left += (pow(10, (left_length-(m+1))) * number_reader(input_digits[m]));
        m++;
    }

    while (m+1 <= digit_count) {
        translated_right += pow(10, digit_count - (m+1)) * number_reader(input_digits[m+1]);
        m++;
    }
    int result = translated_left + translated_right;
    ascii_creator(result);

}