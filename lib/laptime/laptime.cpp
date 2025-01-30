#include "laptime.h"
#include <random>

namespace laptime {
double StartReactionTime::reactiontime() {
    //first-lap start reaction time between 0.05s and 0.4s
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(5, 40); // define the range
    
    double reactiontime = distr(gen);
    reactiontime = reactiontime / 100 + 5;
    return reactiontime;
    }

    
}