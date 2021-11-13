/*
  Set with custom operator
  Use case: Create a set of pairs where set is sorted in decreasing order first element 
  and if first elements are same then in increasing order of second element
*/


// Method 1
auto cmp = [](pair<int, int> a, pair<int, int> b) {
  // YOUR ORDERING LOGIC
  if(a.first > b.first) return true;
  if(a.first < b.first) return false;
  return a.second < b.second;
};

std::set<pll, decltype(cmp)> sp(cmp);


// Method 2 : https://codeforces.com/blog/entry/77373
struct cmp {
  bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
    // YOUR ORDERING LOGIC
    int lena = a.second - a.first + 1;
    int lenb = b.second - b.first + 1;
    if (lena == lenb) return a.first < b.first;
    return lena > lenb;
  }
};
set<pair<int, int>, cmp> segs;
