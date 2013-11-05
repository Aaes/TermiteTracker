import javax.swing.JPanel;
import javax.swing.SpringLayout;


@SuppressWarnings("serial")
public class TERMESTrackingPanel extends JPanel 
{
	SpringLayout layout;
	
	//the size of the video feeds
	int frameHeight;
	int frameWidth;
	double scale = 0.7;
	
	public TERMESTrackingPanel() 
	{
		layout = new SpringLayout();
		setLayout(layout);
		
		setLayoutConstraints();
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
		
	}

}
