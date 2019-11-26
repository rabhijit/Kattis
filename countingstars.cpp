#include <bits/stdc++.h>
using namespace std;

int main() {
	int counter = 1;
	int lines, pixels;
	while (cin >> lines >> pixels) {
		set<int> this_line;
		set<int> last_line;
		int no_stars = 0;
		for (int i = 0; i < lines; i++) {
			bool old_star = false;
			char last_input = '0';
			for (int j = 0; j < pixels; j++) {
				char input; cin >> input;
				if (i == 0) {
					if (input == '-' && old_star == false) {
						this_line.insert(j);
						old_star = true; 
						no_stars++;		
					}
					else if (input == '-' && old_star == true) {
						this_line.insert(j);
					}
					else if (input == '#' && old_star == true) {
						old_star = false;
					}  
				}
				else {
					if (input == '-') {
						if (last_line.find(j) != last_line.end()) {
							old_star = true;		
						}
						this_line.insert(j);
					}
					if ((input == '#' && old_star == false && last_input == '-') || (j == pixels - 1 && old_star == false && last_input == '#')) {
						no_stars++;
					}
					last_input = input;
				}
			}
			last_line = this_line;
			this_line.clear();	
		}
		cout << "Case " << counter << ": " << no_stars << endl;
		counter++;
	}
}
