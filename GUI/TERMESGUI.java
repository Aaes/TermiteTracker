import java.awt.*;
import javax.swing.*;  
import java.awt.image.BufferedImage;
import java.io.ByteArrayOutputStream;
import java.io.File;
import javax.imageio.ImageIO;

@SuppressWarnings("serial")
public class TERMESGUI extends JFrame
 {

	JPanel pane = new JPanel();

	public TERMESGUI() // the frame constructor method
	{
		super("TERMES");
		setBounds(100, 100, 1100, 700);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container con = this.getContentPane(); // inherit main frame
		con.add(pane); // add the panel to frame

		JLabel label = new JLabel(TERMESConnector.test());
		pane.add(label);
		
		//display a picture
		try
		{
			BufferedImage myPicture = ImageIO.read(new File("/Users/Nikolaj/Developer/TermiteTracker/Media/4.jpg"));
			JLabel picLabel = new JLabel(new ImageIcon(myPicture));
			add(picLabel);

		//convert image to bytearray		
		ByteArrayOutputStream baos = new ByteArrayOutputStream();
		ImageIO.write(myPicture, "jpg", baos);
		baos.flush();
		byte[] imageInByte = baos.toByteArray();
		baos.close();
		
		//call C++ getKeypoints and print
		System.out.println("the image byte array cotains " + imageInByte.length + " bytes");
		double[] keypoints = TERMESConnector.getKeypoints(imageInByte);
		for (int i=0; i<keypoints.length; i++) {
			System.out.println(keypoints[i]);
		}
		
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		
		setVisible(true); // display this frame
	}
}
