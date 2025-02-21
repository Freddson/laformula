#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "cpr/cpr.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;

int main() {
    std::string a, b;
    int sk[3];
    int sprint_sk;
    bool sprint = false;
    std::getline(std::cin, a);
    //Switch for race name specification; hurts to write but can't use switch statements on strings
    if(a == "Miami") { a = "United%20States&location=Miami"; sprint = true;}

    else if(a == "Austin") { a = "United%20States&location=Austin"; sprint = true;}

    else if(a == "Las Vegas") a = "United%20States&location=Las%20Vegas"; 

    else if(a == "Imola") a = "Italy&location=Imola";

    else if(a == "Monza") a = "Italy&location=Monza";

    b = "https://api.openf1.org/v1/sessions?country_name=" + a + "&session_type=Practice&year=2024";
    std::cout << b << std::endl;
    cpr::Response r = cpr::Get(cpr::Url{b});
    //split response to three parts
    std::string text = r.text;
    std::vector<std::string> splitresponse;
    if(!sprint) {
        auto pos = text.find("},");
        while(pos != std::string::npos) {
            splitresponse.push_back(text.substr(0, pos));
            text.erase(0, pos + 2);
            pos = text.find("},");
        }
    }

    else if(sprint == true) {
        splitresponse.push_back(text);
    }

    std::cout << "SIZE: " << splitresponse.size() << std::endl;
    //sprint detection
    if(splitresponse.size() < 2) {
        std::cout << "Selected race weekend is a sprint weekend.\nResults may be less accurate until proper algorithm correction for sprint races.\n";
        text = splitresponse[0];
        text = text.substr(0, text.length() - 1);
        text = text.substr(1, text.length());
        json j = json::parse(text);
        for (auto it = j.begin(); it != j.end(); ++it) {
            if(it.key() == "session_key") sprint_sk = j["session_key"].get<int>();
        }
        std::cout << "SPRINT!\n" << sprint_sk << std::endl; 
        return 0;
    }
    else if(splitresponse.size() > 3) {
        std::cout << "Input is country with more than one race in race calendar!\nSpecify the name of the race (ex. 'Imola', 'Miami').\n";
        return 0;
    }
    text = splitresponse[0] + "}";
    text.erase(text.begin());
    json j = json::parse(text);
    std::cout << j.dump(4) << std::endl;
    //If the correct country is provided, pull the first session_key and save all three (by adding 1 for each lasting session_key)
    
    for (auto it = j.begin(); it != j.end(); ++it) {
        if(it.key() == "session_key") sk[0] = j["session_key"].get<int>(); sk[1] = sk[0] + 1; sk[2] = sk[1] + 1;
    }

    std::cout << sk[0] << " - " << sk[1] << " - " << sk[2] << "\n";

    return 0;
}