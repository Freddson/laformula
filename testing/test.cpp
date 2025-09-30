#include <iostream>
#include "Networking.h"
#include "cpr/cpr.h"

using namespace std;


int main() {
    std::string a, b;
    int sk[3];
    int sprint_sk;

    std::getline(std::cin, a);
    vals result = ReturnSessionKey(a);
    //^ this works, second step from roadmap to come!
    sk[0] = result.sk;
}