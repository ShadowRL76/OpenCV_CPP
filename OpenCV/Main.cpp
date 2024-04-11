#include <iostream>
#include <vector>
#include <string>
#include "ColorDetection.h"


int main() {
    std::vector<std::string> cascadeFilePaths;

    // Prompt the user to enter file paths
    std::cout << "Enter the paths to XML files (one per line)," "type 'done' when finished:" << std::endl;
   
    std::string input;
    while (true) {
        std::getline(std::cin, input);
        if (input == "done") {
            break;
        }
        else {
            cascadeFilePaths.push_back(input);
        }
    }

    displayFrame(cascadeFilePaths);
    return EXIT_SUCCESS;
}
