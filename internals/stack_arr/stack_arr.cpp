#include "iostream"
#include <vector>
using namespace std;

class Stack_vec {
    vector<int> s;
    // push pop topval
    void push(int val) { s.push_back(val); }

    int pop() {
        if (s.empty()) {
            return -1;
        }
        int ret = s.back();
        s.pop_back();
        return ret;
    }
    int topval() { return s.empty() ? -1 : s.back(); }
};

/* class Stack_arr { */
/*   public: */
/*     int s[]; */
/*     Stack_arr(int n) { this->s = int[n]; } */
/**/
/*     void push(int val) {} */
/* }; */

int main() {
    cout << "";
    return 0;
}
