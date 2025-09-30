#include "Networking.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include "cpr/cpr.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;

vals ReturnSessionKey(std::string a) {
    vals forrace;
    bool sprint;
    int sk;
    int sprint_sk;
    //no switch case possibility :(
    if(a == "Miami") { a = "United%20States&location=Miami"; sprint = true;}

    else if(a == "Austin") { a = "United%20States&location=Austin"; sprint = true;}

    else if(a == "Las Vegas") a = "United%20States&location=Las%20Vegas"; 

    else if(a == "Imola") a = "Italy&location=Imola";

    else if(a == "Monza") a = "Italy&location=Monza";

    std::string b = "https://api.openf1.org/v1/sessions?country_name=" + a + "&session_type=Practice&year=2024";
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
        std::cout << "Selected race weekend is a sprint weekend.\nFunctionality will be added later.\n"; //\nResults may be less accurate until proper algorithm correction for sprint races.\n";
        /*text = splitresponse[0];
        text = text.substr(0, text.length() - 1);
        text = text.substr(1, text.length());
        json j = json::parse(text);
        for (auto it = j.begin(); it != j.end(); ++it) {
            if(it.key() == "session_key") sprint_sk = j["session_key"].get<int>();
        }
        return sprint_sk;
        */
       //i cant be asked to implement sprints rn, will come back to this as i finish up the main functionality of ts
       forrace.sk = 0;
       forrace.sprint = false;
       return forrace;
    }
    else if(splitresponse.size() > 3) {
        std::cout << "Input is country with more than one race in race calendar!\nSpecify the name of the race (ex. 'Imola', 'Miami').\n";
        forrace.sk = 0;
        forrace.sprint = false;
        return forrace;
    }
    text = splitresponse[0] + "}";
    text.erase(text.begin());
    json j = json::parse(text);
    //If the correct country is provided, pull the first session_key and DON'T save all three (by adding 1 for each session_key)
    //Bypass pointer requirement for array return, only return sk[0]
    
    for (auto it = j.begin(); it != j.end(); ++it) {
        if(it.key() == "session_key") sk = j["session_key"].get<int>();
    }

    forrace.sk = sk;
    forrace.sprint = sprint;

    return forrace;
}