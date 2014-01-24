
/**************************************************

file: 

**************************************************/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "rs232.h"
#include <string>
#include <sstream>
#include "plotter.h"

using namespace std;

int lastX = 0;
int lastY = 0;

int formatCoordinate(int i, unsigned char *a, unsigned char *b);		//Format decimal coordinate in two 2-byte parts
void printCoordinate(int x, int y);										//Prints a coordinate to the console formatted like (a,b)

//Take the plotter to a specific decimal coordinate
int gotoCoor(int x, int y) 
{
	unsigned char xPart1, xPart2, yPart1, yPart2;
	if(formatCoordinate(x, &xPart1, &xPart2) && formatCoordinate(y, &yPart1, &yPart2)) 
	{
		int comPort = 3;
		int success = RS232_OpenComport(comPort, 38400);						//(comport, baudrate)

		unsigned char buffer[5] = { 0x01, xPart1, xPart2, yPart1, yPart2 };	
		int succ = RS232_SendBuf(comPort, buffer, 5);
		lastX = x;
		lastY = y;

		RS232_CloseComport(comPort);
		return 1;
	} 
	else 
	{
		return 0;
	}
}

void getPlotterLocation(int* x, int* y) {
	*x = lastX;
	*y = lastY;
}

void moveDiff(int x, int y) {
	gotoCoor(lastX + x, lastY + y);
}

//Splits an X or Y coordinate in two parts of 1 byte/chars each
//
//coor: An X or Y coordinate in decimal form (up to and including 65535)
//part1: Pointer to the first byte
//part2: Pointer to the second byte

int formatCoordinate(int coor, unsigned char *part1, unsigned char *part2) {
	if(coor < 256) {							//First part can contain a value up to FF / 255 (only 1 part needed)
		*(part1) = 0x00;
		*(part2) = (unsigned char)coor;

		return 1;
	} else if(coor < 65536) {					//Both parts combined can contain a value up to FFFF / 655365 (both parts needed)
		int value = coor / 255;
		int remainder = coor % 255;

		*(part1) = (unsigned char)value;
		*(part2) = (unsigned char)remainder;

		return 1;
	} else {
		cout << "coordinate is too large" << endl;
		return 0;
	}
}

///Makes the plotter follow a square twisted 45 degrees
///and fitted within a regular square of dimensions a x b
//starting and ending in (0,b/2)

void runTwistedSquare(int a, int b) {
	//(0,b/2) --> (a/2, b)
	for(int x=0; x <= a/2;) {
		for(int y=b/2; y <= b;) {
			gotoCoor(x, y);
			x+=2;
			y+=2;
		}
	}

	//(a/2, b) --> (a, b/2)
	for(int x=a/2; x <= a;) {
		for(int y=b; y >= b/2;) {
			gotoCoor(x, y);
			x+=2;
			y-=2;
		}
	}

	//(a, b/2) --> (a/2, 0)
	for(int x=a; x > a/2;) {
		for(int y=b/2; y >= 0;) {
			gotoCoor(x, y);
			x-=2;
			y-=2;
		}
	}

	//(a/2, 0) --> (a, b/2)
	for(int x = a/2; x >= 0;) {
		for(int y = 0; y <= b/2;) {
			gotoCoor(x, y);
			x-=2;
			y+=2;
		}
	}
}

void printCoordinate(int x, int y) {
	cout << "(";
	cout << x;
	cout << ", ";
	cout << y;
	cout << ")" << endl;
}