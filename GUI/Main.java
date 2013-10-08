public class Main {
	
	public static void main(String[] args) {
		@SuppressWarnings("unused")
		TERMESGUI gui = new TERMESGUI();
	}
	
	public static native String test();
	
	public static native double[] getKeypoints(byte[] image);
	
    static {
        System.loadLibrary("Main");
    }

}
