#include <bits/stdc++.h>
using namespace std;

int main() {
	double width, no_words;
	int counter = 1;
	while (cin >> width >> no_words) {
		if (width == 0 && no_words == 0) {
			break;
		}
		map<string, double> fruits;
		double max_occurrences = 0;
		for (int i = 0; i < no_words; i++) {
			string input_fruit;
			double number;
			cin >> input_fruit >> number;
			if (number >= 5) {
				fruits[input_fruit] = number;
			}
			if (number >= 5 && number > max_occurrences) {
				max_occurrences = number;
			}
		}
		map<string, pair<double, double>> details; // height, width
		for (auto it = fruits.begin(); it != fruits.end(); it++) {
			double point_size = 8 + ceil((40 * (it->second - 4)) / (max_occurrences - 4) );
			double width = ceil((9.0/16.0) * (float)(it->first).length() * point_size);
			details[it->first] = make_pair(point_size, width);
		}
		int count_width = 0;
		int count_height = 0;
		int max_height = 0;
		for (auto it2 = details.begin(); it2 != details.end(); it2++) {
			if (count_width + it2->second.second > width) {
				count_height += fmax(max_height, it2->second.first);
				count_width = it2->second.second;
				max_height = it2->second.first;
			}
			else {
				count_width += it2->second.second;
				if (it2->second.first > max_height) {
					max_height = it2->second.first;
				}
			}
			if (it2 == prev(details.end())) {
				count_height += fmax(max_height, it2->second.first);
			}	
		}
		cout << "CLOUD " << counter << ": " << count_height << "\n";
		counter++;
	}
}
