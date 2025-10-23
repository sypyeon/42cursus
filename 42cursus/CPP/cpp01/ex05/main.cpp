#include "Harl.hpp"
#include <iostream>

int main() {
    Harl harl;
    
    std::cout << "=== Harl's Complaints ===" << std::endl;
    std::cout << std::endl;
    
    std::cout << "Testing DEBUG level:" << std::endl;
    harl.complain("DEBUG");
    std::cout << std::endl;
    
    std::cout << "Testing INFO level:" << std::endl;
    harl.complain("INFO");
    std::cout << std::endl;
    
    std::cout << "Testing WARNING level:" << std::endl;
    harl.complain("WARNING");
    std::cout << std::endl;
    
    std::cout << "Testing ERROR level:" << std::endl;
    harl.complain("ERROR");
    std::cout << std::endl;
    
    std::cout << "Testing invalid level:" << std::endl;
    harl.complain("INVALID");
    std::cout << std::endl;
    
    std::cout << "Testing empty level:" << std::endl;
    harl.complain("");

    return 0;
}
