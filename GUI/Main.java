
public class Main {
	
	public static void main(String[] args) {
		@SuppressWarnings("unused")
		TERMESGUI gui = new TERMESGUI();
	}
	
	public static native String test();
	
    static {
        System.loadLibrary("Main");
    }

}
