
public class TERMESConnector
{

	//Native Methods that calls C++ code
	public static native String test();
	public static native double[] getKeypoints(byte[] image);
	
	//Loading the dynamic library, connecting the Java GUI and C++ code
    static 
    {
        System.loadLibrary("TERMESConnector");
    }
    /*
	
	public static String test() 
	{
		return "LOL";
	}
	
	public static double[] getKeypoints(byte[] image) 
	{
		return new double[2];
	}
    */
}
