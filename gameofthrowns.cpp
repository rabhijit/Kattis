// Game of Throwns

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL); // I hope C++ users don't get accidental TLE due to missing this line
  int n, k; // 1 <= n <= 30 (number of students), 1 <= k <= 100 (number of commands from the teacher)
  cin >> n >> k; // just read
  vector<int> commands;
  int chosen = 0;

  while (k--) { // now we throw the eggs around (or undo)
    int m;
    string cmd; // we do not really know what comes next, is it a command "undo m" or a single integer, we read as string first
    cin >> cmd;
    if (cmd == "undo") { // if we see a word "undo", then the format will be "undo m"
      cin >> m; // so we read m next
      for (int j = 0; j < m; j++) {
        int reverse_command = commands.back();
        if (reverse_command < 0) {
          reverse_command = abs(reverse_command);
          chosen += (reverse_command);
        }
        else {
          chosen -= (reverse_command);
        }
        commands.pop_back();
        if (chosen < 0) {
          chosen = n + chosen;
        }
      }

      // what should we do with "undo m"?




    }
    else { // this "cmd" is actually integer m :o
      m = stol(cmd); // there is a built-in command to convert string to integer
      commands.push_back(m);
      if (m < 0) {
        m = abs(m);
        chosen -= (m);
      }
      else {
        chosen += (m);
      }
      if (chosen >= n) {
        chosen -= n;
      }


      // what should we do with this throw command with parameter m?



    }
  }

  // now what should be printed out at the end....
  int ans = chosen; // change this
  ans = (ans + 10000 * n) % n;

  cout << ans << endl;
  return 0;
}