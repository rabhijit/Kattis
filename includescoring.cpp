/*
A0181059A
Abhijit Ravichandran
(no lab group assigned yet)
(no TA)
*/

/*
5
6 179 65 1
6 179 65 1
6 179 65 0
5 4 3 0
1 1 1 0
*/

/*
36
6 179 65 1
6 305 86 1
6 324 96 0
6 390 112 1
5 280 97 0
4 79 45 1
4 94 49 1
4 126 55 1
4 160 100 1
4 173 76 0
4 214 106 1
4 221 110 1
4 226 96 1
4 384 103 0
3 35 26 1
3 90 56 0
3 113 83 1
3 137 106 0
3 171 101 1
3 184 104 0
3 195 65 1
2 14 11 1
2 15 10 1
2 17 11 1
2 19 12 1
2 20 13 1
2 21 14 0
2 30 19 0
2 30 19 0
2 36 27 1
2 36 27 1
2 36 27 1
2 36 27 1
2 36 27 1
2 52 31 0
2 69 23 1
*/

/*
41
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
*/

#include <bits/stdc++.h>
using namespace std;

bool s_sort(vector<int> stat1, vector<int> stat2) {
    return (stat1.at(0) > stat2.at(0));
}

bool p_sort(vector<int> stat1, vector<int> stat2) {
    return (stat1.at(1) < stat2.at(1));
}

bool f_sort(vector<int> stat1, vector<int> stat2) {
    return (stat1.at(2) < stat2.at(2));
}

int scoring_table(int rank) {
    int ranks[30] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30};
    int scores[30] = {100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    if (rank <= 30) {
        for (int i = 0; i < 30; i++) {
            if (ranks[i] == rank) {
                return scores[i];
            }
        }
    }
    else {
        return 0;
    }
}

int main() {
    int contestants;
    cin >> contestants;
    vector<vector<int>> stats;
    vector<int> indiv_stats;
    for (int i = 0; i < contestants; i++) {
        int s, p, f, o, tie = 0;
        cin >> s >> p >> f >> o;
        indiv_stats.push_back(s); indiv_stats.push_back(p);
        indiv_stats.push_back(f); indiv_stats.push_back(o);
        for (int j = 0; j < stats.size(); j++) {
            if (stats.at(j).at(0) == s && stats.at(j).at(1) == p && stats.at(j).at(2) == f) {
                tie = 1;
                break;
            }
        }
        indiv_stats.push_back(tie);
        stats.push_back(indiv_stats);
        indiv_stats.clear();
    }
    vector<vector<int>> duplicate_stats = stats;
    stable_sort(stats.begin(), stats.end(), f_sort);
    stable_sort(stats.begin(), stats.end(), p_sort);
    stable_sort(stats.begin(), stats.end(), s_sort);
    /*
    for (int z = 0; z < stats.size(); z++) {
        for (int zi = 0; zi < stats.at(z).size(); zi++) {
            cout << stats.at(z).at(zi) << " ";
        }
        cout << endl;
    }
    */

    vector<int> new_order;
    for (int q = 0; q < duplicate_stats.size(); q++) {
        for (int r = 0; r < stats.size(); r++) {
            if (duplicate_stats.at(q).at(0) == stats.at(r).at(0) && duplicate_stats.at(q).at(1) == stats.at(r).at(1) && duplicate_stats.at(q).at(2) == stats.at(r).at(2) && duplicate_stats.at(q).at(3) == stats.at(r).at(3)) {
                new_order.push_back(r);
                break;
            }
        }
    }
    /*
    for (int z = 0; z < new_order.size(); z++) {
        cout << new_order.at(z) << endl;
    }
    */

    vector<int> scores;
    int tie_counter = 0;
    float tie_score = 0;

    /* change below algorithm to one based on new_order instead
    (if same rank, do some division to all of same rank etc)
    initializze a vector with all 0 values and later call all values that
    have been added into it */
    for (int k = 0; k < new_order.size(); k++) {
        if (new_order.at(k) <= 29) {
            // if .at(k) already in scores: modify value
        }
    }

    for (int k = 0; k < contestants; k++) {
        if (stats.at(k).at(4) == 1) {
            if (tie_counter == 0) {
                tie_score += scoring_table(k);
                for (int m = k; m < contestants; m++) {
                    if (stats.at(m).at(4) == 0) {
                        break;
                    }
                    tie_score += scoring_table(m+1);
                    tie_counter++;
                }
                tie_score /= (tie_counter + 1);
                tie_score = ceil(tie_score);
                scores.back() = (tie_score+stats.at(k-1).at(3));
                scores.push_back(tie_score+stats.at(k).at(3));
            }
            else {
                scores.push_back(tie_score+stats.at(k).at(3));
            }
        }
        else {
            tie_counter = 0;
            tie_score = 0;
            scores.push_back(scoring_table(k+1)+stats.at(k).at(3));
        }
    }
    for (int n = 0; n < contestants; n++) {
        cout << scores.at(new_order.at(n)) << endl;
    }
}