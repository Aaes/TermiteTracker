
public class TERMESConnector
{

	public static native String test();
	
	public static native double[] getKeypoints(byte[] image);
	
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
