#include "iostream"
#include "map"
#include "algorithm"
using std::cin;
using std::cout;
using std::map;
int main() {
    int H, N;
    cin >> H >> N;
    int HI[50];
    map<int, int> m;
    for (int i = 0; i < N; i++) {
        cin >> HI[i];
        m[i] = std::abs(HI[i] - H);
    }
    //    std::sort(m.begin(), m.end());

    int i = 0, j = N - 1;
    while(i < j) {
        while(v[i] < H) i++;
        while(v[j] > H) j--;
        std::swap(v[i], v[j]);
    }
    for(auto &i : v) {
        cout << i <<" ";
    }
    return 0;
}