/**/

int gotoCoor(int x, int y);												//Take plotter to specific coordinate
void moveDiff(int x, int y);							//Move plotter (x, y) relative to last received coordinate - (negative xs and ys possible)
void runTwistedSquare(int a, int b);									//An example sequence of moves

void getPlotterLocation(int* x, int* y);