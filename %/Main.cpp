#include <iostream>
#include <vector>
#include <string>
#include <future> 
#include "Uranus.h"
 
int main() {

    std::vector<std::string> apps = {"1.cpp", "2.cpp", "%.py"};
    std::vector<std::future<void>> futures;
 
    for (const auto& app : apps) {

        futures.push_back(std::async(std::launch::async, Uranus, app));
    }
 

    for (auto& f : futures) {
        f.get();
    }
 
    return 0;
}
