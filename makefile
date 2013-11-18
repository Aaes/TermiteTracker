MAINFILE = Main.java
CONNECTORFILE = TERMESConnector
JAVAFILES = Main.java TERMESConnector.java TERMESGUI.java TERMESImageProcessing.java TERMESCalibratingPanel.java TERMESTrackingPanel.java
CPPFILES = ColorDetector.cpp Contrast.cpp TERMESConnector.cpp ErodeAndDilate.cpp

OSXVERSIONFLAG = -mmacosx-version-min=10.8
JNIPATH = "-I/System/Library/Frameworks/JavaVM.framework/Versions/A/Headers"
JNIPATH2 = "-I/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk/System/Library/Frameworks/JavaVM.framework/Versions/A/Headers"
OPENCVINCLUDEPATH = "-I/usr/local/Cellar/opencv/2.4.6.1/include"

DYNLIBNAME = libTERMESConnector.jnilib
OFILES = Contrast.o ColorDetector.o TERMESConnector.o ErodeAndDilate.o
OPENCVLIBPATH = -L/usr/local/Cellar/opencv/2.4.6.1/lib/
OPENCVLIBS = -lopencv_core.2.4.6 -lopencv_imgproc.2.4.6 -lopencv_highgui.2.4.6 -lopencv_objdetect.2.4.6 -lopencv_features2d.2.4.6

TERMESConnector.o: $(CPPFILES) TERMESConnector.h $(JAVAFILES)
	# 	--- Compile the Java project  --- 
	javac $(JAVAFILES)
	# 	--- Create a header file from the Java file containing the native methods --- 
	javah $(CONNECTORFILE)
	# 	--- Compile the C++ (with jni.h) --- 
	g++ $(OSXVERSIONFLAG) $(JNIPATH) $(JNIPATH2) $(OPENCVINCLUDEPATH) -c $(CPPFILES)
	# 	--- Create a dynamic Library, connecting the two --- 
	g++ $(OSXVERSIONFLAG) -dynamiclib -o $(DYNLIBNAME) $(OFILES) $(OPENCVINCLUDEPATH) $(OPENCVLIBPATH) $(OPENCVLIBS)
	# 	--- DONE! ---
	