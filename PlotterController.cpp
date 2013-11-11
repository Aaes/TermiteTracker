//
//  PlotterController.cpp
//  TermiteTracker
//
//  Created by Niklas on 31/10/13.
//  Copyright (c) 2013 Niklas Schalck Johansson. All rights reserved.
//

#include "PlotterController.h"

using namespace std;

void printdev(libusb_device *dev);

int connectToDevice(int VendorID, int ProductID){
    
    libusb_context *ctx = NULL; //a libusb session
    int r; //For return values
    r = libusb_init(&ctx); //initialize a library session
    
    if(r < 0) {
        cout<<"Init Error "<<r<<endl; //there was an error
        return 1;
    }
    
    libusb_set_debug(ctx, 3);
    
    libusb_device_handle *dev_handle = libusb_open_device_with_vid_pid(ctx, VendorID, ProductID);
    
    if(dev_handle == NULL)
        cout<<"Cannot open device"<<endl;
    else
        cout<<"Device Opened"<<endl;
    
    unsigned char *data = new unsigned char[4]; //data to write
    data[0]='a';data[1]='b';data[2]='c';data[3]='d';
    
    int actual;
    
    int interface = 0;
    
    if(libusb_kernel_driver_active(dev_handle, interface) == 1) { //find out if kernel driver is attached
        cout<<"Kernel Driver Active"<<endl;
        if(libusb_detach_kernel_driver(dev_handle, interface) == 0) //detach it
            cout<<"Kernel Driver Detached!"<<endl;
    }
    
    libusb_set_configuration(dev_handle, 1);
    libusb_reset_device (dev_handle);
    
    r = libusb_claim_interface(dev_handle, interface); //claim interface 0 (the first) of device
    
    if(r < 0) {
        cout<<"Cannot Claim Interface"<<endl;
        return 1;
    }
    
    cout<<"Claimed Interface"<<endl;
    cout<<"Data->"<<data<<"<-"<<endl; //just to see the data we want to write : abcd
    cout<<"Writing Data..."<<endl;
    
    r = libusb_bulk_transfer(dev_handle, (2 | LIBUSB_ENDPOINT_OUT), data, 4, &actual, 0); //my device's out endpoint was 2, found with trial- the device had 2 endpoints: 2 and 129 - same as ours
    
    if(r == 0 && actual == 4) //we wrote the 4 bytes successfully
        cout<<"Writing Successful!"<<endl;
    else
        cout<<"Write Error"<<endl;
    
    r = libusb_release_interface(dev_handle, 0); //release the claimed interface
    if(r!=0) {
        cout<<"Cannot Release Interface"<<endl;
        return 1;
    }
    cout<<"Released Interface"<<endl;
    
    
    
    libusb_close(dev_handle); //close the device we opened
    libusb_exit(ctx); //needs to be called to end the session
    
    delete[] data; //delete the allocated memory for data
    return 0;
}


int detectDevices(){
    
    libusb_device **devs; //pointer to pointer of device, used to retrieve a list of devices
    
    libusb_context *ctx = NULL; //a libusb session
    
    int r; //for return values
    
    ssize_t cnt; //holding number of devices in list
    
    r = libusb_init(&ctx); //initialize a library session
    
    if(r < 0) {
        cout<<"Init Error "<<r<<endl; //there was an error
        return 1;
    }
    
    libusb_set_debug(ctx, 3);
    
    cnt = libusb_get_device_list(ctx, &devs);
    
    if(cnt < 0) {
        cout<<"Get Device Error"<<endl; //there was an error
    }
    
    cout<<cnt<<" Devices in list."<<endl;
    
    ssize_t i; //for iterating through the list
    for(i = 0; i < cnt; i++) {
        printdev(devs[i]); //print specs of this device
    }
    libusb_free_device_list(devs, 1); //free the list, unref the devices in it
    
    libusb_exit(ctx); //close the session
    
    return 0;
}

void printdev(libusb_device *dev) {
    
    libusb_device_descriptor desc;
    
    int r = libusb_get_device_descriptor(dev, &desc);
    
    if (r < 0) {
        
        cout<<"failed to get device descriptor"<<endl;
        
        return;
        
    }
    
    cout<<"Number of possible configurations: "<<(int)desc.bNumConfigurations<<"  ";
    
    cout<<"Device Class: "<<(int)desc.bDeviceClass<<"  ";
    
    cout<<"VendorID: "<<desc.idVendor<<"  ";
    
    cout<<"ProductID: "<<desc.idProduct<<endl;
    
    libusb_config_descriptor *config;
    
    libusb_get_config_descriptor(dev, 0, &config);
    
    cout<<"Interfaces: "<<(int)config->bNumInterfaces<<" ||| ";
    
    const libusb_interface *inter;
    
    const libusb_interface_descriptor *interdesc;
    
    const libusb_endpoint_descriptor *epdesc;
    
    for(int i=0; i<(int)config->bNumInterfaces; i++) {
        
        inter = &config->interface[i];
        
        cout<<"Number of alternate settings: "<<inter->num_altsetting<<" | ";
        
        for(int j=0; j<inter->num_altsetting; j++) {
            
            interdesc = &inter->altsetting[j];
            
            cout<<"Interface Number: "<<(int)interdesc->bInterfaceNumber<<" | ";
            
            cout<<"Number of endpoints: "<<(int)interdesc->bNumEndpoints<<" | ";
            
            for(int k=0; k<(int)interdesc->bNumEndpoints; k++) {
                
                epdesc = &interdesc->endpoint[k];
                
                cout<<"Descriptor Type: "<<(int)epdesc->bDescriptorType<<" | ";
                
                cout<<"EP Address: "<<(int)epdesc->bEndpointAddress<<" | ";
                
            }
            
        }
        
    }
    
    cout<<endl<<endl<<endl;
    
    libusb_free_config_descriptor(config);
    
}
