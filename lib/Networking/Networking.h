#pragma once
#include <string>

#ifndef NETWORKING_H
#define NETWORKING_H

struct vals {
    int sk;
    bool sprint;
};

vals ReturnSessionKey(std::string a);

#endif //NETWORKING_H