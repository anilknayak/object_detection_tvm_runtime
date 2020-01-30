#include <cstdlib>
#include <string>
#include <iostream>
#include <cmath>
#include <string>

#include "face_analysis_config.h"

#include "face_analysis.h"

int main(int argc, char* argv[])
{
    if (argc < 2) {
    // report version
    std::cout << argv[0] << " Version " << face_analysis_VERSION_MAJOR  << "."
              << face_analysis_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " Image Path" << std::endl;
    return 1;
    }

    // convert input to double
    const double inputValue = std::stod(argv[1]);
    const double outputValue = 0;
    // calculate square root
    #ifdef USE_FACEDETECTION
        outputValue = detect_face();
    #endif
    std::cout << "Bounding box is " << outputValue << std::endl;
    return 0;
}