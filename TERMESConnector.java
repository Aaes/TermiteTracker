
public class TERMESConnector
{

	//Native methods that calls C++ code
	public static native int[] getKeypoints();
	public static native byte[] getNextFrame();
	public static native byte[] getNextOverheadFrame();
	public static native byte[] getNextThresholdFrame();
	public static native void start();
	public static native void releaseCamera();
	
	public static native void setLowerThresholdR(int r);
	public static native void setLowerThresholdG(int g);
	public static native void setLowerThresholdB(int b);
	
	public static native int getLowerThresholdR();
	public static native int getLowerThresholdG();
	public static native int getLowerThresholdB();
	
	public static native void setUpperThresholdR(int r);
	public static native void setUpperThresholdG(int g);
	public static native void setUpperThresholdB(int b);
	
	public static native int getUpperThresholdR();
	public static native int getUpperThresholdG();
	public static native int getUpperThresholdB();
	
	//Loading the dynamic library, connecting the Java GUI and C++ code
    static 
    {
        System.loadLibrary("TERMESConnector");
    }
}
