
public class TERMESConnector
{

	//Native Methods that calls C++ code
	public static native String test();
	public static native int[] getKeypoints();
	public static native byte[] getNextFrame();
	public static native void start();
	public static native void releaseCamera();
	
	//Loading the dynamic library, connecting the Java GUI and C++ code
    static 
    {
        System.loadLibrary("TERMESConnector");
    }
}
