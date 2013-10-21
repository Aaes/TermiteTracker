import java.awt.*;
import javax.swing.*;  
import java.awt.image.BufferedImage;
import java.io.File;
import java.util.Arrays;

import javax.imageio.ImageIO;

@SuppressWarnings("serial")
public class TERMESGUI extends JFrame
 {

	JPanel pane = new JPanel();
	SpringLayout layout;
	
	JLabel picLabel;

	public TERMESGUI()
	{
		InitializeWindow(); 

		//test label
		JLabel label = new JLabel(TERMESConnector.test());
		pane.add(label);
		
		//displayPicture();
		picLabel = new JLabel(new ImageIcon(TERMESImageProcessing.convertByteArrayToImage(TERMESConnector.getFrame())));
		add(picLabel);
		
		setLayoutConstraints();
		setVisible(true); // display this frame
		
		
	}
	
	public void InitializeWindow()
	{
		setTitle("TERMES");
		setBounds(100, 100, 1100, 700);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container con = this.getContentPane(); 
		con.add(pane);
		
		layout = new SpringLayout();
		setLayout(layout);
	}
	
	public void setLayoutConstraints()
	{
		layout.putConstraint(SpringLayout.WEST, picLabel, 50 ,SpringLayout.WEST, pane);
		layout.putConstraint(SpringLayout.NORTH, picLabel, 50 ,SpringLayout.NORTH, pane);
	}
	
	public void displayPicture() {
		try 
		{
			BufferedImage myPicture = ImageIO.read(new File("/Users/Nikolaj/Developer/TermiteTracker/Media/4.jpg"));

			byte[] imageInByte = TERMESImageProcessing.convertImageToByteArray(myPicture);
			
			// call C++ getKeypoints and print
			System.out.println("the image byte array cotains " + imageInByte.length + " bytes");
			
			double[] keypoints = TERMESConnector.getKeypoints(imageInByte);
			for (int i = 0; i < keypoints.length; i++) {
				System.out.println(keypoints[i]);
			}
			
			picLabel = new JLabel(new ImageIcon(TERMESImageProcessing.convertByteArrayToImage(Arrays.copyOfRange(imageInByte, 0, imageInByte.length/2))));
			add(picLabel);

		} 
		catch (Exception e) 
		{
			e.printStackTrace();
		}
	}
}
