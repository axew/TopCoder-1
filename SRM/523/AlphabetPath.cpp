#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
#define ALL(a)  (a).begin(),(a).end()
#define REP(i,n) for(int i=0;i<(n);++i)
const double EPS = 1e-10;
const double PI  = acos(-1.0);
#define dump(x) cerr << "  (L" << __LINE__ << ") " << #x << " = " << (x) << endl;
#define dumpv(x) cerr << "  (L" << __LINE__ << ") " << #x << " = "; REP(q,(x).size()) cerr << (x)[q] << " "; cerr << endl;
template<typename T1, typename T2>
ostream& operator<<(ostream& s, const pair<T1, T2>& d) {return s << "(" << d.first << "," << d.second << ")";}

const int DR[] = {-1, 1, 0, 0};
const int DC[] = {0, 0, -1, 1};

class AlphabetPath {
public:
  string doesItExist(vector <string> letterMaze) {
    int N = letterMaze.size();
    int M = letterMaze[0].size();
    int curR = -1, curC = -1;
    REP(i, N) REP(j, M) if (letterMaze[i][j] == 'A') {
      curR = i;
      curC = j;
    }
    if (curR == -1) return "NO";

    char cur = 'B';
    while (true) {
      bool found = false;
      REP(k, 4) {
        int nr = curR + DR[k];
        int nc = curC + DC[k];
        if (nr >= 0 && nr < N && nc >= 0 && nc < M && letterMaze[nr][nc] == cur) {
          if (cur == 'Z') return "YES";
          curR = nr;
          curC = nc;
          cur++;
          
          found = true;
          break;
        }
      }
      if (!found) break;
    }
    return "NO";
  }
};



// BEGIN CUT HERE
namespace moj_harness {
	int run_test_case(int);
	void run_test(int casenum = -1, bool quiet = false) {
		if (casenum != -1) {
			if (run_test_case(casenum) == -1 && !quiet) {
				cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
			}
			return;
		}
		
		int correct = 0, total = 0;
		for (int i=0;; ++i) {
			int x = run_test_case(i);
			if (x == -1) {
				if (i >= 100) break;
				continue;
			}
			correct += x;
			++total;
		}
		
		if (total == 0) {
			cerr << "No test cases run." << endl;
		} else if (correct < total) {
			cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
		} else {
			cerr << "All " << total << " tests passed!" << endl;
		}
	}
	
	int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
		cerr << "Example " << casenum << "... "; 
		
		string verdict;
		vector<string> info;
		char buf[100];
		
		if (elapsed > CLOCKS_PER_SEC / 200) {
			sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
			info.push_back(buf);
		}
		
		if (expected == received) {
			verdict = "PASSED";
		} else {
			verdict = "FAILED";
		}
		
		cerr << verdict;
		if (!info.empty()) {
			cerr << " (";
			for (int i=0; i<(int)info.size(); ++i) {
				if (i > 0) cerr << ", ";
				cerr << info[i];
			}
			cerr << ")";
		}
		cerr << endl;
		
		if (verdict == "FAILED") {
			cerr << "    Expected: \"" << expected << "\"" << endl; 
			cerr << "    Received: \"" << received << "\"" << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			string letterMaze[]       = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			string letterMaze[]       = {"ADEHI..Z",
 "BCFGJK.Y",
 ".PONML.X",
 ".QRSTUVW"}
;
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			string letterMaze[]       = {"ACBDEFGHIJKLMNOPQRSTUVWXYZ"};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			string letterMaze[]       = {"ABC.......",
 "...DEFGHIJ",
 "TSRQPONMLK",
 "UVWXYZ...."};
			string expected__         = "NO";

			clock_t start__           = clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			string letterMaze[]       = {"..............",
 "..............",
 "..............",
 "...DEFGHIJK...",
 "...C......L...",
 "...B......M...",
 "...A......N...",
 "..........O...",
 "..ZY..TSRQP...",
 "...XWVU.......",
 ".............."};
			string expected__         = "YES";

			clock_t start__           = clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			string letterMaze[]       = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string letterMaze[]       = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			string letterMaze[]       = ;
			string expected__         = ;

			clock_t start__           = clock();
			string received__         = AlphabetPath().doesItExist(vector <string>(letterMaze, letterMaze + (sizeof letterMaze / sizeof letterMaze[0])));
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
		default:
			return -1;
		}
	}
}
 

int main(int argc, char *argv[]) {
	if (argc == 1) {
		moj_harness::run_test();
	} else {
		for (int i=1; i<argc; ++i)
			moj_harness::run_test(atoi(argv[i]));
	}
}
// END CUT HERE
