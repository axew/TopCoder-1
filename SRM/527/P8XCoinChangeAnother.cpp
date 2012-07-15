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


class P8XCoinChangeAnother {
public:
  vector<long long> solve(int N, long long coins_sum, long long coins_count) {
    vector<LL> res;
    for (int i = 0; i < N; i++) {
      LL min_after = 2LL * coins_count;
      if (coins_sum >= min_after) {
        if (coins_sum & 1) {
          res.push_back(1);
          coins_sum -= 1;
          coins_count -= 1;
        } else {
          res.push_back(0);
        }
      } else {
        LL exceed = min_after - coins_sum;
        res.push_back(exceed);
        coins_sum -= exceed;
        coins_count -= exceed;
      }
      coins_sum >>= 1;
    }

    if (coins_sum == 0 && coins_count == 0) {
      return res;
    } else {
      return vector<LL>();
    }
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
	
	template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

	int verify_case(int casenum, const vector<long long> &expected, const vector<long long> &received, clock_t elapsed) { 
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
			cerr << "    Expected: " << expected << endl; 
			cerr << "    Received: " << received << endl; 
		}
		
		return verdict == "PASSED";
	}

	int run_test_case(int casenum) {
		switch (casenum) {
		case 0: {
			int N                     = 2;
			long long coins_sum       = 4;
			long long coins_count     = 3;
			long long expected__[]    = {2, 1};

			clock_t start__           = clock();
			vector<long long> received__ = P8XCoinChangeAnother().solve(N, coins_sum, coins_count);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 1: {
			int N                     = 3;
			long long coins_sum       = 6;
			long long coins_count     = 3;
			long long expected__[]    = {0, 3, 0};

			clock_t start__           = clock();
			vector<long long> received__ = P8XCoinChangeAnother().solve(N, coins_sum, coins_count);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 2: {
			int N                     = 2;
			long long coins_sum       = 8;
			long long coins_count     = 1;
			long long expected__[]    = {};

			clock_t start__           = clock();
			vector<long long> received__ = P8XCoinChangeAnother().solve(N, coins_sum, coins_count);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
		case 3: {
			int N                     = 1;
			long long coins_sum       = 10000000000LL;
			long long coins_count     = 10000000000LL;
			long long expected__[]    = {10000000000LL};

			clock_t start__           = clock();
			vector<long long> received__ = P8XCoinChangeAnother().solve(N, coins_sum, coins_count);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}

		// custom cases

    case 4: {
			int N                     = 12;
			long long coins_sum       = 7;
			long long coins_count     = 2;
			long long expected__[]    = {};

			clock_t start__           = clock();
			vector<long long> received__ = P8XCoinChangeAnother().solve(N, coins_sum, coins_count);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}
/*      case 5: {
			int N                     = ;
			long long coins_sum       = ;
			long long coins_count     = ;
			long long expected__[]    = ;

			clock_t start__           = clock();
			vector<long long> received__ = P8XCoinChangeAnother().solve(N, coins_sum, coins_count);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
		}*/
/*      case 6: {
			int N                     = ;
			long long coins_sum       = ;
			long long coins_count     = ;
			long long expected__[]    = ;

			clock_t start__           = clock();
			vector<long long> received__ = P8XCoinChangeAnother().solve(N, coins_sum, coins_count);
			return verify_case(casenum, vector<long long>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
