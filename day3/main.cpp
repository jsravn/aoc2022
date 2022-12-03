#include "lib.h"
#include <QFile>
#include <QTextStream>
#include <algorithm>
#include <iostream>
#include <set>

using namespace Qt;
using namespace std;
using namespace Lib;

set<char> createCompartment(const string &items) {
  set<char> comp;
  for (const auto &item : items) {
    comp.insert(item);
  }
  return comp;
}

int priority(char c) {
  if ('a' <= c && c <= 'z') {
    return 1 + (c - 'a');
  } else {
    return 27 + (c - 'A');
  }
}

int main(int argc, char *argv[]) {
  auto lines = parseIn("../../aoc2022/day3/in.txt");

  auto prioritiesSum = 0;
  for (const auto &line : lines) {
    auto halfIdx = line.length() / 2;
    auto first = createCompartment(line.substr(0, halfIdx));
    auto second = createCompartment(line.substr(halfIdx, line.length()));

    vector<char> dupes;
    set_intersection(first.begin(), first.end(), second.begin(), second.end(), back_inserter(dupes));
    if (dupes.size() == 1) {
      auto prio = priority(dupes[0]);
      prioritiesSum += prio;
    } else {
      cout << "bug: should have one dupe but had " << dupes.size() << endl;

      cout << line << endl;
      cout << string(first.begin(), first.end()) << endl;
      cout << string(second.begin(), second.end()) << endl;
      return 1;
    }
  }

  auto groupPrioritiesSum = 0;
  for (auto group = 0; group < lines.size() / 3; group += 1) {
    auto first = createCompartment(lines[group * 3]);
    auto second = createCompartment(lines[group * 3 + 1]);
    auto third = createCompartment(lines[group * 3 + 2]);

    vector<char> dupes;
    set_intersection(first.begin(), first.end(), second.begin(), second.end(), back_inserter(dupes));
    vector<char> dupes2;
    set_intersection(dupes.begin(), dupes.end(), third.begin(), third.end(), back_inserter(dupes2));

    if (dupes2.size() == 1) {
      auto prio = priority(dupes2[0]);
      cout << "adding " << dupes2[0] << " with priority " << prio << endl;
      groupPrioritiesSum += prio;
    } else {
      cout << "bug: should have one dupe but had " << dupes.size() << endl;
      return 1;
    }
  }

  cout << "part 1: " << prioritiesSum << endl;
  cout << "part 2: " << groupPrioritiesSum << endl;

  return 0;
}
