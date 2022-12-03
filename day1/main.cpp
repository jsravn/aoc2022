#include <QFile>
#include <QTextStream>
#include <queue>

using namespace Qt;
using namespace std;

int main(int argc, char *argv[]) {
  QTextStream out(stdout);

  QFile file("../../aoc2022/day1/in.txt");
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    out << "Failed to open in.txt" << Qt::endl;
    return 1;
  }

  priority_queue<int> snacks;
  int curSum = 0;

  QTextStream in(&file);
  while (!in.atEnd()) {
    QString line = in.readLine().trimmed();
    if (line.isEmpty()) {
      snacks.push(curSum);
      curSum = 0;
    } else {
      curSum += line.toInt();
    }
  }
  snacks.push(curSum);

  int top3 = 0;
  top3 += snacks.top();
  snacks.pop();
  top3 += snacks.top();
  snacks.pop();
  top3 += snacks.top();
  snacks.pop();

  out << top3 << endl;

  return 0;
}
