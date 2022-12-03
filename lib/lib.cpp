#include "lib.h"
#include <QFile>
#include <QTextStream>
#include <iostream>

using namespace std;

namespace Lib {
vector<string> parseIn(const string &fileName) {
  QFile file(fileName.c_str());
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    cout << "Failed to open in.txt" << endl;
    return vector<string>();
  }

  vector<string> res;

  QTextStream in(&file);
  while (!in.atEnd()) {
    QString line = in.readLine().trimmed();
    res.push_back(line.toStdString());
  }

  return res;
}
} // namespace Lib
