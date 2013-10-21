import java.awt.*;
import javax.swing.*;  
import java.awt.image.BufferedImage;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.IOException;
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
		
		displayPicture();
		
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

			// convert image to bytearray
			ByteArrayOutputStream baos = new ByteArrayOutputStream();
			ImageIO.write(myPicture, "jpg", baos);
			baos.flush();
			byte[] imageInByte = baos.toByteArray();
			baos.close();

			// call C++ getKeypoints and print
			System.out.println("the image byte array cotains " + imageInByte.length + " bytes");
			
			double[] keypoints = TERMESConnector.getKeypoints(imageInByte);
			for (int i = 0; i < keypoints.length; i++) {
				System.out.println(keypoints[i]);
			}
			
			picLabel = new JLabel(new ImageIcon(convertByteArrayToImage(Arrays.copyOfRange(imageInByte, 0, imageInByte.length/2))));
			add(picLabel);

		} 
		catch (Exception e) 
		{
			e.printStackTrace();
		}
	}
	
	public static BufferedImage convertByteArrayToImage(byte[] input)
	{
		ByteArrayInputStream bis = new ByteArrayInputStream(input);
		BufferedImage image = null;
		try 
		{
			image = ImageIO.read(bis);
		} 
		catch (IOException e) 
		{
			// TODO Auto-generated catch block
			System.err.println("Conversion form byte[] to BufferedImage not succesful");
			e.printStackTrace();
		}
		if(image == null)
			System.out.println("OH GAWD");
		return image;
	}
}
