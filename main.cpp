#include "iostream"
#include <vector>

#define TYPE_CHECK(T, S)                              \
  while (false) {                                     \
    *(static_cast<T**>(0)) = static_cast<S*>(0);      \
  }
int main() {
    TYPE_CHECK(int, int);
    return 0;
}