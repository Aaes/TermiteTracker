import java.awt.Color;
import java.awt.Image;
import java.util.ArrayList;
import java.util.Hashtable;
import java.util.Iterator;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JSlider;
import javax.swing.JSpinner;
import javax.swing.SpinnerModel;
import javax.swing.SpinnerNumberModel;
import javax.swing.SpringLayout;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;

@SuppressWarnings("serial")
public class TERMESCalibratingPanel extends JPanel implements ChangeListener
{
	JLabel leftPicLabel;
	ImageIcon leftIcon;

	JLabel rightPicLabel;
	ImageIcon rightIcon;
	
	JLabel leftPicTitleLabel;
	JLabel rightPicTitleLabel;
	
	JLabel leftSlidersTitle;
	JLabel rightSlidersTitle;
	
	JLabel lowerThresholdRlabel;
	JSlider lowerThresholdRSlider;
	JSpinner lowerThresholdRSpinner;
	
	JLabel lowerThresholdGlabel;
	JSlider lowerThresholdGSlider;
	JSpinner lowerThresholdGSpinner;
	
	JLabel lowerThresholdBlabel;
	JSlider lowerThresholdBSlider;
	JSpinner lowerThresholdBSpinner;
	
	JLabel upperThresholdRlabel;
	JSlider upperThresholdRSlider;
	JSpinner upperThresholdRSpinner;
	
	JLabel upperThresholdGlabel;
	JSlider upperThresholdGSlider;
	JSpinner upperThresholdGSpinner;
	
	JLabel upperThresholdBlabel;
	JSlider upperThresholdBSlider;
	JSpinner upperThresholdBSpinner;
	
	SpringLayout layout;
	
	//the size of the video feeds
	int frameHeight;
	int frameWidth;
	double scale = 0.7;
	
	public TERMESCalibratingPanel() 
	{
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
		
		//create title label for the video feeds
		leftPicTitleLabel = new JLabel("Original");
		add(leftPicTitleLabel);
		rightPicTitleLabel = new JLabel("Threshold");
		add(rightPicTitleLabel);
		
		createSliders();
		
		setLayoutConstraints();
	}
	
	public void createSliders()
	{
		//titles
		leftSlidersTitle = new JLabel("Lower Thresholding Bounds");
		rightSlidersTitle  = new JLabel("Upper Thresholding Bounds");
		add(leftSlidersTitle);
		add(rightSlidersTitle);
		
		//RGB labels
		lowerThresholdRlabel = new JLabel("R:");
		add(lowerThresholdRlabel);
		lowerThresholdGlabel = new JLabel("G:");
		add(lowerThresholdGlabel);
		lowerThresholdBlabel = new JLabel("B:");
		add(lowerThresholdBlabel);
		
		upperThresholdRlabel = new JLabel("R:");
		add(upperThresholdRlabel);
		upperThresholdGlabel = new JLabel("G:");
		add(upperThresholdGlabel);
		upperThresholdBlabel = new JLabel("B:");
		add(upperThresholdBlabel);
		
		//Threshold sliders
		ArrayList<JSlider> thresholdSliders = new ArrayList<JSlider>();
		int thresholdMin = 0;
		int thresholdMax = 255;

		lowerThresholdRSlider = new JSlider(JSlider.HORIZONTAL, thresholdMin, thresholdMax, TERMESConnector.getLowerThresholdR());
		thresholdSliders.add(lowerThresholdRSlider);
		lowerThresholdGSlider = new JSlider(JSlider.HORIZONTAL, thresholdMin, thresholdMax, TERMESConnector.getLowerThresholdG());
		thresholdSliders.add(lowerThresholdGSlider);
		lowerThresholdBSlider = new JSlider(JSlider.HORIZONTAL, thresholdMin, thresholdMax, TERMESConnector.getLowerThresholdB());
		thresholdSliders.add(lowerThresholdBSlider);
		
		upperThresholdRSlider = new JSlider(JSlider.HORIZONTAL, thresholdMin, thresholdMax, TERMESConnector.getUpperThresholdR());
		thresholdSliders.add(upperThresholdRSlider);
		upperThresholdGSlider = new JSlider(JSlider.HORIZONTAL, thresholdMin, thresholdMax, TERMESConnector.getUpperThresholdG());
		thresholdSliders.add(upperThresholdGSlider);
		upperThresholdBSlider = new JSlider(JSlider.HORIZONTAL, thresholdMin, thresholdMax, TERMESConnector.getUpperThresholdB());
		thresholdSliders.add(upperThresholdBSlider);

		//Create the label table
		Hashtable<Integer,JLabel> thresholdLabelTable = new Hashtable<Integer,JLabel>();
		thresholdLabelTable.put(thresholdMin, new JLabel("" + thresholdMin));
		thresholdLabelTable.put(thresholdMax, new JLabel("" + thresholdMax));
		
		for (JSlider jSlider : thresholdSliders) {
			jSlider.setLabelTable(thresholdLabelTable);
			jSlider.setMajorTickSpacing(10);
			jSlider.setPaintLabels(true);
			jSlider.setPaintTicks(true);
			jSlider.addChangeListener(this);
			add(jSlider);
		}
		
		//Threshold spinners
		ArrayList<JSpinner> thresholdSpinners = new ArrayList<JSpinner>();
		
		SpinnerModel lowerThresholdRModel = new SpinnerNumberModel(TERMESConnector.getLowerThresholdR(), thresholdMin, thresholdMax, 1);
		lowerThresholdRSpinner = new JSpinner(lowerThresholdRModel);
		thresholdSpinners.add(lowerThresholdRSpinner);
		
		SpinnerModel lowerThresholdGModel = new SpinnerNumberModel(TERMESConnector.getLowerThresholdG(), thresholdMin, thresholdMax, 1);
		lowerThresholdGSpinner = new JSpinner(lowerThresholdGModel);
		thresholdSpinners.add(lowerThresholdGSpinner);
		
		SpinnerModel lowerThresholdBModel = new SpinnerNumberModel(TERMESConnector.getLowerThresholdB(), thresholdMin, thresholdMax, 1);
		lowerThresholdBSpinner = new JSpinner(lowerThresholdBModel);
		thresholdSpinners.add(lowerThresholdBSpinner);
		
		SpinnerModel upperThresholdRModel = new SpinnerNumberModel(TERMESConnector.getUpperThresholdR(), thresholdMin, thresholdMax, 1);
		upperThresholdRSpinner = new JSpinner(upperThresholdRModel);
		thresholdSpinners.add(upperThresholdRSpinner);
		
		SpinnerModel upperThresholdGModel = new SpinnerNumberModel(TERMESConnector.getUpperThresholdG(), thresholdMin, thresholdMax, 1);
		upperThresholdGSpinner = new JSpinner(upperThresholdGModel);
		thresholdSpinners.add(upperThresholdGSpinner);
		
		SpinnerModel upperThresholdBModel = new SpinnerNumberModel(TERMESConnector.getUpperThresholdB(), thresholdMin, thresholdMax, 1);
		upperThresholdBSpinner = new JSpinner(upperThresholdBModel);
		thresholdSpinners.add(upperThresholdBSpinner);
		
		for (JSpinner jSpinner : thresholdSpinners) {
			jSpinner.addChangeListener(this);
			add(jSpinner);
		}

	}
	
	public void startVideo() 
	{
		// poll for the next frame as long as there is one
		byte[] frame;
		while ((frame = TERMESConnector.getNextFrame()) != null) {
			// get the next frame as an image
			Image imgOriginal = TERMESImageProcessing.convertByteArrayToImage(frame);

			// scale the image if necessary
			if (frameHeight == 0) // then frameWidth is also 0
			{
				frameHeight = (int) determineFrameHeight(imgOriginal.getWidth(null), imgOriginal.getHeight(null));
				frameWidth = (int) determineFrameWidth(imgOriginal.getWidth(null), imgOriginal.getHeight(null));
			}

			imgOriginal = imgOriginal.getScaledInstance(frameWidth, frameHeight, java.awt.Image.SCALE_SMOOTH);

			leftIcon = new ImageIcon(imgOriginal);
			leftPicLabel.setIcon(leftIcon);
			
			Image imgThreshold = TERMESImageProcessing.convertByteArrayToImage(frame);

			// scale the image if necessary
			if (frameHeight == 0) // then frameWidth is also 0
			{
				frameHeight = (int) determineFrameHeight(imgThreshold.getWidth(null), imgThreshold.getHeight(null));
				frameWidth = (int) determineFrameWidth(imgThreshold.getWidth(null), imgThreshold.getHeight(null));
			}

			imgThreshold = imgThreshold.getScaledInstance(frameWidth, frameHeight, java.awt.Image.SCALE_SMOOTH);

			rightIcon = new ImageIcon(imgThreshold);
			rightPicLabel.setIcon(rightIcon);

			try {
				Thread.sleep(TERMESGUI.imageRefreshDelay);
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
		//left video feed
		layout.putConstraint(SpringLayout.WEST, leftPicLabel, 50 ,SpringLayout.WEST, this);
		layout.putConstraint(SpringLayout.NORTH, leftPicLabel, 50 ,SpringLayout.NORTH, this);
		
		//right video feed
		layout.putConstraint(SpringLayout.WEST, rightPicLabel, 50 ,SpringLayout.EAST, leftPicLabel);
		layout.putConstraint(SpringLayout.NORTH, rightPicLabel, 50 ,SpringLayout.NORTH, this);
		
		//left title label
		layout.putConstraint(SpringLayout.WEST, leftPicTitleLabel, 0 ,SpringLayout.WEST, leftPicLabel);
		layout.putConstraint(SpringLayout.SOUTH, leftPicTitleLabel, -5 ,SpringLayout.NORTH, leftPicLabel);
		
		//right title label
		layout.putConstraint(SpringLayout.WEST, rightPicTitleLabel, 0 ,SpringLayout.WEST, rightPicLabel);
		layout.putConstraint(SpringLayout.SOUTH, rightPicTitleLabel, -5 ,SpringLayout.NORTH, rightPicLabel);
		
		//Left Sliders Title
		layout.putConstraint(SpringLayout.WEST, leftSlidersTitle, 0 ,SpringLayout.WEST, leftPicLabel);
		layout.putConstraint(SpringLayout.NORTH, leftSlidersTitle, 5 ,SpringLayout.SOUTH, leftPicLabel);
		
		//Lower Threshold R Slider
		layout.putConstraint(SpringLayout.WEST, lowerThresholdRSlider, -10 ,SpringLayout.WEST, leftPicLabel);
		layout.putConstraint(SpringLayout.NORTH,  lowerThresholdRSlider, 25 ,SpringLayout.SOUTH, leftPicLabel);
		layout.putConstraint(SpringLayout.EAST,  lowerThresholdRSlider, -50 ,SpringLayout.EAST, leftPicLabel);
		
		//Lower Threshold R Spinner
		layout.putConstraint(SpringLayout.WEST, lowerThresholdRSpinner, 5 ,SpringLayout.EAST, lowerThresholdRSlider);
		layout.putConstraint(SpringLayout.NORTH, lowerThresholdRSpinner, 0 ,SpringLayout.NORTH, lowerThresholdRSlider);
		
		//R label
		layout.putConstraint(SpringLayout.EAST, lowerThresholdRlabel, 3 ,SpringLayout.WEST, lowerThresholdRSlider);
		layout.putConstraint(SpringLayout.NORTH, lowerThresholdRlabel, 6 ,SpringLayout.NORTH, lowerThresholdRSlider);
		
		//Lower Threshold G Slider
		layout.putConstraint(SpringLayout.WEST, lowerThresholdGSlider, -10 ,SpringLayout.WEST, leftPicLabel);
		layout.putConstraint(SpringLayout.NORTH,  lowerThresholdGSlider, 15 ,SpringLayout.SOUTH, lowerThresholdRSlider);
		layout.putConstraint(SpringLayout.EAST,  lowerThresholdGSlider, -50 ,SpringLayout.EAST, leftPicLabel);
		
		//Lower Threshold G Spinner
		layout.putConstraint(SpringLayout.WEST, lowerThresholdGSpinner, 5 ,SpringLayout.EAST, lowerThresholdGSlider);
		layout.putConstraint(SpringLayout.NORTH, lowerThresholdGSpinner, 0 ,SpringLayout.NORTH, lowerThresholdGSlider);
		
		//G label
		layout.putConstraint(SpringLayout.EAST, lowerThresholdGlabel, 3 ,SpringLayout.WEST, lowerThresholdGSlider);
		layout.putConstraint(SpringLayout.NORTH, lowerThresholdGlabel, 6 ,SpringLayout.NORTH, lowerThresholdGSlider);
		
		//Lower Threshold B Slider
		layout.putConstraint(SpringLayout.WEST, lowerThresholdBSlider, -10 ,SpringLayout.WEST, leftPicLabel);
		layout.putConstraint(SpringLayout.NORTH,  lowerThresholdBSlider, 15 ,SpringLayout.SOUTH, lowerThresholdGSlider);
		layout.putConstraint(SpringLayout.EAST,  lowerThresholdBSlider, -50 ,SpringLayout.EAST, leftPicLabel);
		
		//Lower Threshold B Spinner
		layout.putConstraint(SpringLayout.WEST, lowerThresholdBSpinner, 5 ,SpringLayout.EAST, lowerThresholdBSlider);
		layout.putConstraint(SpringLayout.NORTH, lowerThresholdBSpinner, 0 ,SpringLayout.NORTH, lowerThresholdBSlider);
		
		//B label
		layout.putConstraint(SpringLayout.EAST, lowerThresholdBlabel, 3 ,SpringLayout.WEST, lowerThresholdBSlider);
		layout.putConstraint(SpringLayout.NORTH, lowerThresholdBlabel, 6 ,SpringLayout.NORTH, lowerThresholdBSlider);
		
		//Right Sliders Title
		layout.putConstraint(SpringLayout.WEST, rightSlidersTitle, 0 ,SpringLayout.WEST, rightPicLabel);
		layout.putConstraint(SpringLayout.NORTH, rightSlidersTitle, 5 ,SpringLayout.SOUTH, rightPicLabel);
		
		//Upper Threshold R Slider
		layout.putConstraint(SpringLayout.WEST, upperThresholdRSlider, -10 ,SpringLayout.WEST, rightPicLabel);
		layout.putConstraint(SpringLayout.NORTH,  upperThresholdRSlider, 25 ,SpringLayout.SOUTH, rightPicLabel);
		layout.putConstraint(SpringLayout.EAST,  upperThresholdRSlider, -50 ,SpringLayout.EAST, rightPicLabel);
		
		//Upper Threshold R Spinner
		layout.putConstraint(SpringLayout.WEST, upperThresholdRSpinner, 5 ,SpringLayout.EAST, upperThresholdRSlider);
		layout.putConstraint(SpringLayout.NORTH, upperThresholdRSpinner, 0 ,SpringLayout.NORTH, upperThresholdRSlider);
		
		//R label
		layout.putConstraint(SpringLayout.EAST, upperThresholdRlabel, 3 ,SpringLayout.WEST, upperThresholdRSlider);
		layout.putConstraint(SpringLayout.NORTH, upperThresholdRlabel, 6 ,SpringLayout.NORTH, upperThresholdRSlider);
		
		//Upper Threshold G Slider
		layout.putConstraint(SpringLayout.WEST, upperThresholdGSlider, -10 ,SpringLayout.WEST,rightPicLabel);
		layout.putConstraint(SpringLayout.NORTH,  upperThresholdGSlider, 15 ,SpringLayout.SOUTH, upperThresholdRSlider);
		layout.putConstraint(SpringLayout.EAST,  upperThresholdGSlider, -50 ,SpringLayout.EAST, rightPicLabel);
		
		//Upper Threshold G Spinner
		layout.putConstraint(SpringLayout.WEST, upperThresholdGSpinner, 5 ,SpringLayout.EAST, upperThresholdGSlider);
		layout.putConstraint(SpringLayout.NORTH, upperThresholdGSpinner, 0 ,SpringLayout.NORTH, upperThresholdGSlider);
		
		//G label
		layout.putConstraint(SpringLayout.EAST, upperThresholdGlabel, 3 ,SpringLayout.WEST, upperThresholdGSlider);
		layout.putConstraint(SpringLayout.NORTH, upperThresholdGlabel, 6 ,SpringLayout.NORTH, upperThresholdGSlider);
		
		//Upper Threshold B Slider
		layout.putConstraint(SpringLayout.WEST, upperThresholdBSlider, -10 ,SpringLayout.WEST, rightPicLabel);
		layout.putConstraint(SpringLayout.NORTH,  upperThresholdBSlider, 15 ,SpringLayout.SOUTH, upperThresholdGSlider);
		layout.putConstraint(SpringLayout.EAST,  upperThresholdBSlider, -50 ,SpringLayout.EAST, rightPicLabel);
		
		//Upper Threshold B Spinner
		layout.putConstraint(SpringLayout.WEST, upperThresholdBSpinner, 5 ,SpringLayout.EAST, upperThresholdBSlider);
		layout.putConstraint(SpringLayout.NORTH, upperThresholdBSpinner, 0 ,SpringLayout.NORTH, upperThresholdBSlider);
		
		//B label
		layout.putConstraint(SpringLayout.EAST, upperThresholdBlabel, 3 ,SpringLayout.WEST, upperThresholdBSlider);
		layout.putConstraint(SpringLayout.NORTH, upperThresholdBlabel, 6 ,SpringLayout.NORTH, upperThresholdBSlider);
	}

	/**
	 * Called when a spinner or slider changes value
	 */
	@Override
	public void stateChanged(ChangeEvent e) {
		//Lower Threshold R Slider
		if(e.getSource().equals(lowerThresholdRSpinner))
		{
			Integer currentValue = (Integer)lowerThresholdRSpinner.getValue();
			lowerThresholdRSlider.setValue(currentValue);
			TERMESConnector.setLowerThresholdR(currentValue);
		}
		//Lower Threshold R Spinner
		else if (e.getSource().equals(lowerThresholdRSlider))
		{
			Integer currentValue = (Integer)lowerThresholdRSlider.getValue();
			lowerThresholdRSpinner.setValue(currentValue);
			TERMESConnector.setLowerThresholdR(currentValue);
		}
		//Lower Threshold G Slider
		if(e.getSource().equals(lowerThresholdGSpinner))
		{
			Integer currentValue = (Integer)lowerThresholdGSpinner.getValue();
			lowerThresholdGSlider.setValue(currentValue);
			TERMESConnector.setLowerThresholdG(currentValue);
		}
		//Lower Threshold G Spinner
		else if (e.getSource().equals(lowerThresholdGSlider))
		{
			Integer currentValue = (Integer)lowerThresholdGSlider.getValue();
			lowerThresholdGSpinner.setValue(currentValue);
			TERMESConnector.setLowerThresholdG(currentValue);
		}
		//Lower Threshold B Slider
		if(e.getSource().equals(lowerThresholdBSpinner))
		{
			Integer currentValue = (Integer)lowerThresholdBSpinner.getValue();
			lowerThresholdBSlider.setValue(currentValue);
			TERMESConnector.setLowerThresholdB(currentValue);
		}
		//Lower Threshold B Spinner
		else if (e.getSource().equals(lowerThresholdBSlider))
		{
			Integer currentValue = (Integer)lowerThresholdBSlider.getValue();
			lowerThresholdBSpinner.setValue(currentValue);
			TERMESConnector.setLowerThresholdB(currentValue);
		}
		//Upper Threshold R Slider
		if(e.getSource().equals(upperThresholdRSpinner))
		{
			Integer currentValue = (Integer)upperThresholdRSpinner.getValue();
			upperThresholdRSlider.setValue(currentValue);
			TERMESConnector.setUpperThresholdR(currentValue);
		}
		//Upper Threshold R Spinner
		else if (e.getSource().equals(upperThresholdRSlider))
		{
			Integer currentValue = (Integer)upperThresholdRSlider.getValue();
			upperThresholdRSpinner.setValue(currentValue);
			TERMESConnector.setUpperThresholdR(currentValue);
		}
		//Upper Threshold G Slider
		if(e.getSource().equals(upperThresholdGSpinner))
		{
			Integer currentValue = (Integer)upperThresholdGSpinner.getValue();
			upperThresholdGSlider.setValue(currentValue);
			TERMESConnector.setUpperThresholdG(currentValue);
		}
		//Upper Threshold G Spinner
		else if (e.getSource().equals(upperThresholdGSlider))
		{
			Integer currentValue = (Integer)upperThresholdGSlider.getValue();
			upperThresholdGSpinner.setValue(currentValue);
			TERMESConnector.setUpperThresholdG(currentValue);
		}
		//Upper Threshold B Slider
		if(e.getSource().equals(upperThresholdBSpinner))
		{
			Integer currentValue = (Integer)upperThresholdBSpinner.getValue();
			upperThresholdBSlider.setValue(currentValue);
			TERMESConnector.setUpperThresholdB(currentValue);
		}
		//Upper Threshold B Spinner
		else if (e.getSource().equals(upperThresholdBSlider))
		{
			Integer currentValue = (Integer)upperThresholdBSlider.getValue();
			upperThresholdBSpinner.setValue(currentValue);
			TERMESConnector.setUpperThresholdB(currentValue);
		}
	}
}
