import java.awt.Color;
import java.awt.Image;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SpringLayout;

@SuppressWarnings("serial")
public class TERMESCalibratingPanel extends JPanel
{
	JLabel leftPicLabel;
	ImageIcon leftIcon;

	JLabel rightPicLabel;
	ImageIcon rightIcon;
	
	SpringLayout layout;
	
	//the size of the video feeds
	int frameHeight;
	int frameWidth;
	double scale = 0.7;
	
	public TERMESCalibratingPanel() {
		layout = new SpringLayout();
		setLayout(layout);
		
		// initialize the left icon and label that will contain the original video
		leftIcon = new ImageIcon();
		leftPicLabel = new JLabel(leftIcon);
		leftPicLabel.setBorder(BorderFactory.createLineBorder(Color.GRAY, 3));
		add(leftPicLabel);

		// initialize the right icon and label that will contain the thresholded video
		rightIcon = new ImageIcon();
		rightPicLabel = new JLabel(rightIcon);
		rightPicLabel.setBorder(BorderFactory.createLineBorder(Color.GRAY, 3));
		add(rightPicLabel);
		
		setLayoutConstraints();
	}
	
	public void startVideo() {
		// poll for the next frame as long as there is one
		byte[] frame;
		while ((frame = TERMESConnector.getNextFrame()) != null) {
			// get the next frame as an image
			Image img = TERMESImageProcessing.convertByteArrayToImage(frame);

			// scale the image if necessary
			if (frameHeight == 0) // then frameWidth is also 0
			{
				frameHeight = (int) determineFrameHeight(img.getWidth(null), img.getHeight(null));
				frameWidth = (int) determineFrameWidth(img.getWidth(null), img.getHeight(null));
			}

			img = img.getScaledInstance(frameWidth, frameHeight, java.awt.Image.SCALE_SMOOTH);

			leftIcon = new ImageIcon(img);
			rightIcon = new ImageIcon(img);

			leftPicLabel.setIcon(leftIcon);
			rightPicLabel.setIcon(rightIcon);

			try {
				Thread.sleep(10);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
	}
	
	public double determineFrameHeight(double width, double height)
	{	
		if(width/height == 16.0/9.0) // 16:9
			return 360 * scale;
		else // 4:3
			return 480 * scale;
	}
	
	public double determineFrameWidth(double width, double height)
	{
		if(width/height == 16.0/9.0) // 16:9
			return 640 * scale;
		else // 4:3
			return 640 * scale;
	}
	
	public void setLayoutConstraints()
	{
		layout.putConstraint(SpringLayout.WEST, leftPicLabel, 50 ,SpringLayout.WEST, this);
		layout.putConstraint(SpringLayout.NORTH, leftPicLabel, 50 ,SpringLayout.NORTH, this);
		
		layout.putConstraint(SpringLayout.WEST, rightPicLabel, 50 ,SpringLayout.EAST, leftPicLabel);
		layout.putConstraint(SpringLayout.NORTH, rightPicLabel, 50 ,SpringLayout.NORTH, this);
	}
}
