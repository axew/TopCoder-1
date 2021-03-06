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


class CountingSeries {
public:
  bool isInAP(LL n, LL a, LL b) {
    return n >= a && (n - a) % b == 0;
  }

  long long countThem(long long a, long long b, long long c, long long d, long long upperBound) {
    LL numAP = (a <= upperBound ? (upperBound - a) / b + 1 : 0);
    LL numGP = 0;
    LL numCommon = 0;

    if (d == 1) {
      if (c <= upperBound) {
        numGP = 1;
        if (isInAP(c, a, b)) numCommon = 1;
      }
    } else {
      LL cur = c;
      while (cur <= upperBound) {
        numGP ++;
        if (isInAP(cur, a, b)) numCommon++;
        cur *= d;
      }
    }

    return numAP + numGP - numCommon;
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
	
	int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
			long long a               = 1;
			long long b               = 1;
			long long c               = 1;
			long long d               = 2;
			long long upperBound      = 1000;
			long long expected__      = 1000;

			clock_t start__           = clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 1: {
			long long a               = 3;
			long long b               = 3;
			long long c               = 1;
			long long d               = 2;
			long long upperBound      = 1000;
			long long expected__      = 343;

			clock_t start__           = clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 2: {
			long long a               = 40;
			long long b               = 77;
			long long c               = 40;
			long long d               = 100000;
			long long upperBound      = 40;
			long long expected__      = 1;

			clock_t start__           = clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 3: {
			long long a               = 452;
			long long b               = 24;
			long long c               = 4;
			long long d               = 5;
			long long upperBound      = 600;
			long long expected__      = 10;

			clock_t start__           = clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}
		case 4: {
			long long a               = 234;
			long long b               = 24;
			long long c               = 377;
			long long d               = 1;
			long long upperBound      = 10000;
			long long expected__      = 408;

			clock_t start__           = clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 5: {
			long long a               = ;
			long long b               = ;
			long long c               = ;
			long long d               = ;
			long long upperBound      = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			long long a               = ;
			long long b               = ;
			long long c               = ;
			long long d               = ;
			long long upperBound      = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
			return verify_case(casenum, expected__, received__, clock()-start__);
		}*/
/*      case 7: {
			long long a               = ;
			long long b               = ;
			long long c               = ;
			long long d               = ;
			long long upperBound      = ;
			long long expected__      = ;

			clock_t start__           = clock();
			long long received__      = CountingSeries().countThem(a, b, c, d, upperBound);
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
