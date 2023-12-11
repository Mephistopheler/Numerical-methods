#include "Rules.h"

using namespace std;



int main() {
    const double e = 1e-8;
    double Result = SimpsonRule(0, 1.047, 2, e);
    std::cout << "Solution:" << Result << '\n';
    Result = SimpsonRule(0, 4, 1, 2, 2, 2, e);
    std::cout << "Solution:" << Result << '\n';
    return 0;
}