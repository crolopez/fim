#include <iostream>
#include <fim.hpp>

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cout << "Use: ./fim_test <config_path>" << std::endl;
        return 1;
    }

    try {
        FIM_engine core(argv[1]);
    } catch (std::string excp) {
        std::cout << "ERROR: " << excp << std::endl;
        return 1;
    }

    return 0;
}