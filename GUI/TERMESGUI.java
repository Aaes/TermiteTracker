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

	public TERMESGUI()
	{
		InitializeWindow(); 

		//test label
		JLabel label = new JLabel(TERMESConnector.test());
		pane.add(label);
		
		TERMESConnector.start();
		
		icon = new ImageIcon();
		picLabel = new JLabel(icon);
		add(picLabel);
		
		setLayoutConstraints();
		setVisible(true); // display this frame
		
		this.addWindowListener( new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent we) {
               TERMESConnector.releaseCamera();
               System.exit(0);
            }
        } );
		
		byte[] frame;
		while((frame = TERMESConnector.getNextFrame()) != null)
		{
			icon = new ImageIcon(TERMESImageProcessing.convertByteArrayToImage(frame));
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
		//setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
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
	
}
