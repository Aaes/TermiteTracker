import java.awt.*;
import javax.swing.*;  
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

@SuppressWarnings("serial")
public class TERMESGUI extends JFrame
 {

	JPanel pane = new JPanel();
	SpringLayout layout;
	
	JLabel picLabel;
	ImageIcon icon;
	
	int frameHeight;
	int frameWidth;

	public TERMESGUI()
	{
		InitializeWindow(); 

		//test label
		JLabel label = new JLabel(TERMESConnector.test());
		pane.add(label);
		
		//setup input feed
		TERMESConnector.start();
		
		//initialize the icon and label that will contain the video
		icon = new ImageIcon();
		picLabel = new JLabel(icon);
		add(picLabel);
		
		setLayoutConstraints();
		setVisible(true); // display this frame
		
		//poll for the next frame as long as there is one
		byte[] frame;
		while((frame = TERMESConnector.getNextFrame()) != null)
		{
			//get the next frame as an image
			Image img = TERMESImageProcessing.convertByteArrayToImage(frame); 
			
			//scale the image if necessary
			if (frameHeight == 0) //then frameWidth is also 0
			{
				frameHeight = determineFrameHeight(img.getWidth(null), img.getHeight(null));
				frameWidth = determineFrameWidth(img.getWidth(null), img.getHeight(null));
			}
			
			img = img.getScaledInstance(frameWidth, frameHeight ,java.awt.Image.SCALE_SMOOTH );  
			
			icon = new ImageIcon(img);

			picLabel.setIcon(icon);
			
			try {
				Thread.sleep(10);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
	}
	
	public void InitializeWindow()
	{
		setTitle("TERMES");
		setBounds(100, 100, 1100, 700);
		
		Container con = this.getContentPane(); 
		con.add(pane);
		
		layout = new SpringLayout();
		setLayout(layout);
		
		//see to that the camera is released when the window is closed 
		// (if this isn't done, the application will crash when it is closed)
		this.addWindowListener( new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent we) {
               TERMESConnector.releaseCamera();
               System.exit(0);
            }
        } );
	}
	
	public void setLayoutConstraints()
	{
		layout.putConstraint(SpringLayout.WEST, picLabel, 50 ,SpringLayout.WEST, pane);
		layout.putConstraint(SpringLayout.NORTH, picLabel, 50 ,SpringLayout.NORTH, pane);
	}
	
	public int determineFrameHeight(double width, double height)
	{	
		if(width/height == 16.0/9.0) // 16:9
			return 360;
		else // 4:3
			return 480;
	}
	
	public int determineFrameWidth(double width, double height)
	{
		if(width/height == 16.0/9.0) // 16:9
			return 640;
		else // 4:3
			return 640;
	}
	
}
