#include <iostream>
#include "dotenv.hpp"

int main() {
    std::string value = obtainEnv(".env", "NAME");
    std::cout << value << std::endl; 
    return 0;
}