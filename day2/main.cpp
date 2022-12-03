#include <QCoreApplication>
#include <QFile>
#include <iostream>

using namespace Qt;
using namespace std;

enum Play { rock = 1, paper, scissors };
enum Outcome { lost = 0, draw = 3, won = 6 };

Outcome play(Play opp, Play user) {
  switch (opp) {
  case rock:
    switch (user) {
    case rock:
      return draw;
    case paper:
      return won;
    case scissors:
      return lost;
    }

  case paper:
    switch (user) {
    case rock:
      return lost;
    case paper:
      return draw;
    case scissors:
      return won;
    }

  case scissors:
    switch (user) {
    case rock:
      return won;
    case paper:
      return lost;
    case scissors:
      return draw;
    }
  }
}

Play parse(QChar in, int offset) {
  switch (in.unicode() - offset) {
  case 0:
    return rock;
  case 1:
    return paper;
    break;
  case 2:
    return scissors;
    break;
  }
}

int main(int argc, char *argv[])
{
  QFile file("../../aoc2022/day2/in.txt");
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    cout << "Failed to open in.txt" << endl;
    return 1;
  }

  int score = 0;

  QTextStream in(&file);
  while (!in.atEnd()) {
    QString line = in.readLine().trimmed();
    if (line.isEmpty()) {
      continue;
    }

    auto opp = parse(line[0], 'A');
    auto player = parse(line[2], 'X');
    auto outcome = play(opp, player);

    score += outcome + player;
  }

  cout << "score: " << score << endl;

  return 0;
}
