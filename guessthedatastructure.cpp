/*
A0181059A
Abhijit Ravichandran
Lab Group 13
*/

// input and output won't always be in order

#include <bits/stdc++.h>
using namespace std;

int main() {
    int bag_size;
    vector<string> results;
    while (cin >> bag_size) {
        vector<string> possibilities;
        stack<int> stack;
        queue<int> queue;
        priority_queue<int> pqueue;
        vector<int> inputs;
        vector<int> stack_outputs;
        vector<int> queue_outputs;
        vector<int> pqueue_outputs;
        vector<int> outputs;
        for (int i = 0; i < bag_size; i++) {
            int operation, number;
            cin >> operation >> number;
            if (operation == 1) {
                stack.push(number);
                queue.push(number);
                pqueue.push(number);
                inputs.push_back(number);
            }
            else {
                if (find(inputs.begin(), inputs.end(), number) == inputs.end()) {
                    outputs.push_back(number);
                }
                else {
                    stack_outputs.push_back(stack.top());
                    stack.pop();
                    queue_outputs.push_back(queue.front());
                    queue.pop();
                    pqueue_outputs.push_back(pqueue.top());
                    pqueue.pop();
                    outputs.push_back(number);
                    for (int i = 0; i < inputs.size(); i++) {
                        if (inputs[i] == number) {
                            inputs.erase(inputs.begin()+i);
                            break;
                        }
                    }
                }
            }
        }
        /*
        cout << "STACK" << endl;
        for (auto item : stack_outputs) {
            cout << item << endl;
        }
        cout << "QUEUE" << endl;
        for (auto item : queue_outputs)
        {
            cout << item << endl;
        }
        cout << "PQUEUE" << endl;
        for (auto item : pqueue_outputs)
        {
            cout << item << endl;
        }
        cout << "REAL" << endl;
        for (auto item: outputs) {
            cout << item << endl;
        }
        */


        if (stack_outputs == outputs) {
            possibilities.push_back("stack");
        }
        if (queue_outputs == outputs) {
            possibilities.push_back("queue");
        }
        if (pqueue_outputs == outputs) {
            possibilities.push_back("priority queue");
        }

        if (possibilities.size() > 1) {
            results.push_back("not sure");
        }
        else if (possibilities.size() == 1) {
            results.push_back(possibilities[0]);
        }
        else {
            results.push_back("impossible");
        }
    }
    for (auto item : results) {
        cout << item << endl;
    }
}