#include "iostream"
#include <vector>

#define TYPE_CHECK(T, S)                              \
  while (false) {                                     \
    *(static_cast<T**>(0)) = static_cast<S*>(0);      \
  }


int main() {
//    TYPE_CHECK(int, int);

//    (*(void(*)())0)();
    int a[3] = {1, 2, 3};
    std::cout << a[1] << 2[a] << *(a + 1) << *(1 + a) << std::endl;
    return 0;

}