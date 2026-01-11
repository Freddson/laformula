#include <iostream>
#include <string>
#include "Networking.h"
#include "cpr/cpr.h"

using namespace std;

int main() {
    string a;
    int sk[3];
    std::getline(std::cin, a);
    vals result = ReturnSessionKey(a);
    //^ this works, second step from roadmap to come!
    sk[0] = result.sk;
    sk[1] = ++sk[0];
    sk[2] = ++sk[1];
}
