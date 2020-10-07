#include <algorithm>
#include <cassert>
#include <climits>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../utils/PrintUtils.hpp"
#include "../utils/VectorUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// https://leetcode.com/problems/check-if-it-is-a-straight-line/
// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() { // NOLINT
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  int sumDigits(int n) {
    if (n <= 9)
      return n;
    int total = 0;
    while (n > 0) {
      total += n % 10;
      n /= 10;
    }
    return total;
  }

  int countLargestGroup(int n) {
    assert(n <= 10000);
    vector<int> freq(37, 0);
    int largestSize = INT_MIN;
    int maxFrequency = 0;
    for (int i = 1; i <= n; i++) {
      int sum = sumDigits(i);
      ++freq[sum];
      if (freq[sum] > largestSize) {
        largestSize = freq[sum];
        maxFrequency = 1;
      } else if (freq[sum] == largestSize) {
        ++maxFrequency;
      }
    }
    return maxFrequency;
  }
};

void test1() {
  cout << boolalpha;
  vector<int> arr{8, 1, 2, 2, 3};

  // cout << "4 ? " << Solution().countLargestGroup(13) << endl;
  cout << "1 ? " << Solution().countLargestGroup(20) << endl;
}

void test2() {}

void test3() {}