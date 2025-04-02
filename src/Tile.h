#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdexcept> 
#include <filesystem>
#include <utility>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <random>
#include <ctime>
#include <chrono>
#include <thread>
#include <set>
class Tiles {
public:
    Tiles(bool bomb, bool show, int prox, bool flag) : bomb(bomb), show(show), prox(prox), flag(flag) {}
    bool show;
    bool bomb;
    int prox;
    bool flag;
};