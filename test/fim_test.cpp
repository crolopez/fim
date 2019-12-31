#include <iostream>
#include <fim.hpp>

int main (int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Use: ./fim_test <XXXX>" << "\n";
        return 1;
    }

    return 0;
}