//Usage of the cpr library + the OpenF1 API to pull JSON-format delta times of all drivers in all practice sessions of a race (to be provided by the user via an ID)
#include "deltatimes.h"
#include "cpr/cpr.h"
#include "nlohmann/json.hpp"
#include <iostream>

using json = nlohmann::json;

int main() {
    cpr::Response r = cpr::Get(cpr::Url{"https://api.openf1.org/v1/drivers?driver_number=16"});
    json j = json::parse(r.text);
    std::cout << j.dump(4) << std::endl;
    return 0;
}