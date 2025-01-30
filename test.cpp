#include <string>
#include <iostream>
#include "cpr/cpr.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;

int main() {
    std::string a, b;
    std::getline(std::cin, a);
    b = "https://api.openf1.org/v1/drivers?driver_number=" + a;
    cpr::Response r = cpr::Get(cpr::Url{b});
    json j = json::parse(r.text);
    std::cout << j.dump(4) << std::endl;
    return 0;
}