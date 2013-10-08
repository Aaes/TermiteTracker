import java.awt.*;
import javax.swing.*;  

@SuppressWarnings("serial")
public class TERMESGUI extends JFrame
 {

	JPanel pane = new JPanel();

	public TERMESGUI() // the frame constructor method
	{
		super("TERMES");
		setBounds(100, 100, 500, 400);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		Container con = this.getContentPane(); // inherit main frame
		con.add(pane); // add the panel to frame

		JLabel label = new JLabel(Main.test());
		pane.add(label);
		
		setVisible(true); // display this frame
	}
}
