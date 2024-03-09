#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

ll n;
vb sieve;
vl prime;

void Find() {
  for (auto i = 2; i < 10000; ++i) {
    if (!sieve[i]) {
      continue;
    }

    prime.push_back(i);

    for (auto j = i + i; j < 10000; j += i) {
      sieve[j] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;

  sieve = vb(10000, true);
  sieve[0] = false;
  sieve[1] = false;
  Find();

  for (auto i = 0; i < prime.size() - 1; ++i) {
    const auto& m = prime[i] * prime[i + 1];
    if (n < m) {
      cout << m;
      return 0;
    }
  }

  return 0;
}