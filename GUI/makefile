Main.o: Main.cpp Main.h Main.java TERMESGUI.java
	javac Main.java
	javah Main
	g++ "-I/System/Library/Frameworks/JavaVM.framework/Versions/A/Headers" "-I/Developer/SDKs/MacOSX10.6.sdk/System/Library/Frameworks/JavaVM.framework/Versions/A/Headers" "-I/usr/local/Cellar/opencv/2.4.6.1/include" -c Main.cpp
	g++ -dynamiclib -o libMain.jnilib Main.o -I /usr/local/Cellar/opencv/2.4.6.1/include/ -L /usr/local/Cellar/opencv/2.4.6.1/lib/ -lopencv_highgui -lopencv_features2d -lopencv_imgproc -lopencv_objdetect -lopencv_core