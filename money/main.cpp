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

typedef std::vector<std::pair<producer, consumer>> prodcons;

int main(int argc, char **argv) {
  int64_t np, nc;
  std::cin >> np >> nc;

  std::vector<producer> ps;

  prodcons potentials;
  std::pair<producer, consumer> bestpair;
  int64_t bestscore;

  ps.reserve(np);

  for (int64_t i = 0; i < np; ++i) {
    producer p;
    std::cin >> p.cost >> p.from;
    ps.push_back(p);
  }

  std::sort(ps.begin(), ps.end(), prodsort); // s ==> l
  int64_t minprodday = ps.begin()->from;
  int64_t maxprodday = (ps.end() - 1)->from;

  bestscore = 0;
  for (int64_t i = 0; i < nc; ++i) {
    consumer c;
    std::cin >> c.price >> c.to;

    for (auto p : ps) {
      if (p.from >= c.to)
        break;
      int64_t score = p.get_profit(c);
      if (score > bestscore) { // potential
        bestpair.first = p;
        bestpair.second = c;
        bestscore = score;
      }
    }
  }

  std::cout << bestscore;
  return 0;
}