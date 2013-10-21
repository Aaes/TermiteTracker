TERMESConnector.o: TERMESConnector.cpp TERMESConnector.h Main.java TERMESGUI.java TERMESConnector.java TERMESImageProcessing.java 
	# --- Compile the Java project  --- 
	javac Main.java
	# --- Create a header file from the Java file containing the native methods --- 
	javah TERMESConnector
	# --- Compile the C++ (with jni.h) --- 
	g++ "-I/System/Library/Frameworks/JavaVM.framework/Versions/A/Headers" "-I/Developer/SDKs/MacOSX10.6.sdk/System/Library/Frameworks/JavaVM.framework/Versions/A/Headers" "-I/usr/local/Cellar/opencv/2.4.6.1/include" -c TERMESConnector.cpp
	# --- Create a dynamic Library, connecting the two --- 
	g++ -dynamiclib -o libTERMESConnector.jnilib TERMESConnector.o -I /usr/local/Cellar/opencv/2.4.6.1/include/ -L /usr/local/Cellar/opencv/2.4.6.1/lib/ -lopencv_highgui -lopencv_features2d -lopencv_imgproc -lopencv_objdetect -lopencv_core
	# --- DONE! ---