import javax.swing.*;  
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

@SuppressWarnings("serial")
public class TERMESGUI extends JFrame implements ActionListener
{
	//the time the program waits before polling for a new frame
	public static int imageRefreshDelay = 5;
	
	JPanel pane;
	TERMESCalibratingPanel calibrationPanel;
	TERMESTrackingPanel trackingPanel;
	
	JMenu menu;
	JMenuBar menuBar;
	JMenuItem calibratemode;
	JMenuItem trackingmode;

	public TERMESGUI()
	{
		InitializeWindow(); 
		createMenu();
				
		//setup input feeds
		TERMESConnector.start();

		setVisible(true); // display this frame
		
		startVideoFeeds();
	}
	
	public void InitializeWindow()
	{
		setTitle("TERMES");
		setBounds(100, 100, 1100, 700);
		
		calibrationPanel = new TERMESCalibratingPanel();
		trackingPanel = new TERMESTrackingPanel();
		pane = calibrationPanel;
		
		setContentPane(pane);
		
		//see to that the camera is released when the window is closed 
		//(if this isn't done, the application will crash when it is closed)
		this.addWindowListener( new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent we) {
               TERMESConnector.releaseCamera();
               System.exit(0);
            }
        } );
	}
	
	public void createMenu()
	{
		//Create the menu bar.
		menuBar = new JMenuBar();

		//Build the first menu.
		menu = new JMenu("Change mode");
		menuBar.add(menu);

		//a group of JMenuItems
		calibratemode = new JMenuItem("Calibration Mode");
		calibratemode.addActionListener(this);
		menu.add(calibratemode);
		
		trackingmode = new JMenuItem("Tracking Mode");
		trackingmode.addActionListener(this);
		menu.add(trackingmode);
		
		setJMenuBar(menuBar);
	}
	
	public void startVideoFeeds()
	{
		//video feed for the calibration panel
		Thread videofeed1 = new Thread(new Runnable() {
			  @Override
			  public void run() {
				  calibrationPanel.startVideo();
			  }
			});
		//video feed for the tracking panel
		Thread videofeed2 = new Thread(new Runnable() {
			  @Override
			  public void run() {
				  trackingPanel.startVideo();
			  }
			});
		
		videofeed1.start();
		videofeed2.start();
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		if(e.getSource().equals(calibratemode))
		{
			if(!(pane instanceof TERMESCalibratingPanel))
			{
				pane = calibrationPanel;
				setContentPane(pane);
				validate();
			}
		}
		else if (e.getSource().equals(trackingmode))
		{
			if(!(pane instanceof TERMESTrackingPanel))
			{
				pane = trackingPanel;
				setContentPane(pane);
				validate();
			}
		}
	}
}
