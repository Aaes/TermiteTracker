//
//  PlotterController.h
//  TermiteTracker
//
//  Created by Niklas on 31/10/13.
//  Copyright (c) 2013 Niklas Schalck Johansson. All rights reserved.
//

#ifndef __TermiteTracker__PlotterController__
#define __TermiteTracker__PlotterController__

#include <iostream>
#include <libusb.h>

int detectDevices();
int connectToDevice(int VendorID, int ProductID);

#endif /* defined(__TermiteTracker__PlotterController__) */
