import java.awt.*;

import javax.swing.*;  
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

@SuppressWarnings("serial")
public class TERMESGUI extends JFrame
 {
	
	JPanel pane;

	public TERMESGUI()
	{
		InitializeWindow(); 
		
		//test label
		JLabel label = new JLabel(TERMESConnector.test());
		pane.add(label);
				
		//setup input feeds
		TERMESConnector.start();

		setVisible(true); // display this frame
		
		((TERMESCalibratingPanel) pane).startVideo();
	}
	
	public void InitializeWindow()
	{
		setTitle("TERMES");
		setBounds(100, 100, 1100, 700);
		
		pane = new TERMESCalibratingPanel();
		
		Container con = this.getContentPane(); 
		con.add(pane);
		
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
}
