#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[]) {
  QTextStream out(stdout);

  QFile file("../../aoc2022/day1/in.txt");
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    out << "Failed to open in.txt" << Qt::endl;
    return 1;
  }

  int curSum = 0, maxSum = 0;

  QTextStream in(&file);
  while (!in.atEnd()) {
    QString line = in.readLine().trimmed();
    if (line.isEmpty()) {
      curSum = 0;
    } else {
      curSum += line.toInt();
      maxSum = qMax(curSum, maxSum);
    }
  }

  out << "Max sack is " << maxSum << Qt::endl;
  return 0;
}
