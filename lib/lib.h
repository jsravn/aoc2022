#ifndef LIB_H
#define LIB_H

#include "lib_global.h"
#include <string>
#include <vector>

namespace LIB_EXPORT Lib {
std::vector<std::string> parseIn(const std::string &fileName);
}

#endif // LIB_H
