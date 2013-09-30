//
//  main.cpp
//  TermiteTracker
//
//  Created by Niklas on 9/23/13.
//  Copyright (c) 2013 Niklas Schalck Johansson. All rights reserved.
//

#include <iostream>
#include "MasterThesis.h"
#include "BlobsWorking.h"
#include "ThresholdTest.h"
#include "Program.h"
#include "HSVDetector.h"

int main(int argc, const char * argv[])
{

    //runMasterThesis();
    //runBlobsWorking();
    //SimpleThreshold();
    //runProgram();
    HSVDetection();
    std::cout << "Success!\n";
    return 0;
}

