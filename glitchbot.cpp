#include <iostream>
using namespace std;

// make a robot that can process instructions and move
// int value_to_increase_by;
// int chosen_direction;
// for every direction, try changing to other two possibilities to see if it works

// 1 set original instructions, 1 set changed instructions
// change each instruction to another possibility, then run robot function
// with changed instructions to see which is the first
// to reach desired final_x and final_y

bool robot(string instructions[], int number_of_instructions, int final_x, int final_y) {
    int index = 0;
    int initial_x = 0;
    int initial_y = 0;
    string directions[4] = {"y+1", "x+1", "y-1", "x-1"};
    string current_direction = "y+1";
    for (int i = 0; i < number_of_instructions; i++) {
        if (instructions[i] == "Forward") {
            if (current_direction == "y+1") {
                initial_y += 1;
            }
            else if (current_direction == "x+1") {
                initial_x += 1;
            }
            else if (current_direction == "y-1") {
                initial_y -= 1;
            }
            else if (current_direction == "x-1") {
                initial_x -= 1;
            }
        }
        else if (instructions[i] == "Left") {
            index -= 1;
            if (index < 0) {
                index = 3;
            }
            current_direction = directions[index];
        }
        else if (instructions[i] == "Right") {
            index += 1;
            if (index > 3) {
                index = 0;
            }
            current_direction = directions[index];
        }
    }
    if (initial_x == final_x && initial_y == final_y) {
        return true;
    }
    else {
        return false;
    }
}


int main() {
    int final_x, final_y;
    cin >> final_x >> final_y;
    int number_of_instructions;
    cin >> number_of_instructions;
    string instructions[number_of_instructions]; // + 10?
    for (int i = 0; i < number_of_instructions; i++) {
        cin >> instructions[i];
    }
    string possibilities[3] = {"Forward", "Left", "Right"};
    string duplicate_instructions[number_of_instructions];
    string change_made;
    bool corrected = false;
    for (int k = 0; k < number_of_instructions; k++) {
        duplicate_instructions[k] = instructions[k];
    }
    for (int j = 0; j < number_of_instructions; j++) {
        if (corrected == true) {
            break;
        }
        for (int m = 0; m < 3; m++) {
            if (instructions[j] != possibilities[m]) {
                duplicate_instructions[j] = possibilities[m];
                change_made = possibilities[m];
            }
            if (robot(duplicate_instructions, number_of_instructions, final_x, final_y) == true) {
                cout << j+1 << " " << change_made << endl;
                corrected = true;
                break;
            }
            else {
                for (int n = 0; n < number_of_instructions; n++) {
                    duplicate_instructions[n] = instructions[n];
                }
            }
        }
    }
}