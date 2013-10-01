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
#include "Program.h"
#include "HSVDetector.h"
#include "ThresholdHSVExample.h"

int main(int argc, const char * argv[])
{
	//runExample1(argc, argv);
	//runVideoCapture1(argc, argv);
	//runVideoCapture2(argc, argv);
	//runBlobTest(argc, argv);
	//runContourExample(argc, argv);
	//runMasterThesis();
	//runBlobsWorking();
    //runMasterThesis();
    //runBlobsWorking();
    //SimpleThreshold();
    runProgram();
    //runThresholdHSVExample();
    //HSVDetection();
    std::cout << "Success!\n";
    return 0;
}
