#include "lib.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <utility>

using namespace Lib;
using namespace std;

pair<int, int> parseRange(const string &range) {
  auto rangeIdx = range.find("-");
  auto left = range.substr(0, rangeIdx);
  auto right = range.substr(rangeIdx + 1, range.size());
  auto leftVal = stoi(left);
  auto rightVal = stoi(right);
  return make_pair(leftVal, rightVal);
}

vector<pair<int, int>> parseLine(const string &line) {
  auto lineIdx = line.find(",");
  auto left = line.substr(0, lineIdx);
  auto right = line.substr(lineIdx + 1, line.size());

  return {parseRange(left), parseRange(right)};
}

int main(int argc, char *argv[])
{
  auto lines = parseIn("../../aoc2022/day4/in.txt");

  auto contains = 0, overlaps = 0;
  for (const auto &line : lines) {
    if (line.empty()) {
      continue;
    }

    auto ranges = parseLine(line);
    sort(ranges.begin(), ranges.end(), [](pair<int, int> a, pair<int, int> b) {
      return a.first == b.first ? b.second < a.second : a.first < b.first;
    });

    cout << line << endl;
    if (ranges[1].first <= ranges[0].second) {
      overlaps += 1;
      if (ranges[1].second <= ranges[0].second) {
        contains += 1;
      }
    }
  }

  cout << "part1: " << contains << endl;
  cout << "part2: " << overlaps << endl;

  return 0;
}
