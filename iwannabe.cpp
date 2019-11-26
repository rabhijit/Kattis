#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<tuple<int, int, int>> pokemon;
	for (int i = 0; i < n; i++) {
		int x, y, z; cin >> x >> y >> z;
		pokemon.push_back(make_tuple(x, y, z));
	}
	unordered_set<int> chosen;
	sort(pokemon.begin(), pokemon.end(), [](tuple<int, int, int> t1, tuple<int, int, int> t2) {
		return get<0>(t1) > get<0>(t2);
	});
	for (int j = 0; j < k; j++) {
		chosen.insert(get<0>(pokemon[j]));
	}
	sort(pokemon.begin(), pokemon.end(), [](tuple<int, int, int> t1, tuple<int, int, int> t2) {
		return get<1>(t1) > get<1>(t2);
	});
	for (int j = 0; j < k; j++) {
		chosen.insert(get<0>(pokemon[j]));
	}
	sort(pokemon.begin(), pokemon.end(), [](tuple<int, int, int> t1, tuple<int, int, int> t2) {
		return get<2>(t1) > get<2>(t2);
	});
	for (int j = 0; j < k; j++) {
		chosen.insert(get<0>(pokemon[j]));
	}
	cout << chosen.size() << "\n";
	
}
