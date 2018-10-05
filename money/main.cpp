#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <vector>

class consumer {
public:
  int64_t to;
  int64_t price;
};

bool conssort(const consumer &c1,
              const consumer &c2) { // sorted from small to large
  return (c1.to < c2.to);
}

class producer {
public:
  int64_t from;
  int64_t cost;

  int64_t get_profit(const consumer &c) {
    if ((from < c.to) && (c.price > cost))
      return ((c.to - from) * (c.price - cost));
    return 0;
  }
};

bool prodsort(const producer &p1,
              const producer &p2) { // sorted from small to large
  return (p1.from < p2.from);
}

int main(int argc, char **argv) {
  int64_t np, nc;
  std::cin >> np >> nc;

  std::vector<producer> ps;
  std::vector<consumer> cs;

  ps.reserve(np);
  cs.reserve(nc);

  for (int64_t i = 0; i < np; ++i) {
    producer p;
    std::cin >> p.cost >> p.from;
    ps.push_back(p);
  }

  std::sort(ps.begin(), ps.end(), prodsort); // s ==> l
  int64_t minprodday = ps.begin()->from;
  int64_t maxprodday = (ps.end() - 1)->from;

  for (int64_t i = 0; i < nc; ++i) {
    consumer c;
    std::cin >> c.price >> c.to;
    // if (maxprodday >= (c.to - 1))
    cs.push_back(c);
  }
  std::sort(cs.begin(), cs.end(), conssort); // s ==> l
  int64_t minconsday = cs.begin()->to - 1;
  int64_t maxconsday = (cs.end() - 1)->to - 1;

  int64_t maxprofit = 0;
  for (auto cons : cs) {      // first the smallest consumers
    if (cons.to < minprodday) // no producer available
      break;
    for (auto prod : ps) {       // first the latest producers
      if (prod.from < cons.to) { // production starts on time
        int64_t profit = prod.get_profit(cons);
        if (profit > maxprofit)
          maxprofit = profit;
      } else
        break;
    }
  }

  std::cout << maxprofit;
  return 0;
}