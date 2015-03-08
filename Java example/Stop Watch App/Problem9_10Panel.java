import java.awt.Color;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.Timer;


@SuppressWarnings("serial")
public class Problem9_10Panel extends JPanel
{
	//Defines the labels and buttons

	private JTextField 	mytext;
	private final int	DELAY	= 1000;                                 // Sets rectangle speed
	private Timer		timer;
	private JButton		start, stop, clear;
	private int			x, moveX;
	private JLabel     seconds,blank;

	public Problem9_10Panel()
	{
		//Defines the labels, text field, and buttons
		timer = new Timer(DELAY, new Problem9_8PanelListener());
		x = 0;                                                        // Sets default clock
		moveX = 1;
		blank = new JLabel("");
		blank.setBackground(Color.white);
		mytext = new JTextField();
		mytext.setBorder(BorderFactory.createEmptyBorder(4,4,4,4));
		seconds = new JLabel("seconds");
		seconds.setBorder(BorderFactory.createLineBorder(Color.white, 3));
		start = new JButton("start");
	    start.addActionListener(new ButtonListener1());
		start.setBorder(BorderFactory.createLineBorder(Color.red, 3));
		stop = new JButton("stop");
		stop.addActionListener(new ButtonListener2());
        stop.setBorder(BorderFactory.createLineBorder(Color.red, 3));
		clear = new JButton("clear");
		clear.addActionListener(new ButtonListenerC());
		clear.setBorder(BorderFactory.createLineBorder(Color.red, 3));
		setLayout(new GridLayout(2,3));
		add(blank);
		add(mytext);
		add(seconds);
		add(start);
		add(stop);
		add(clear);

		setPreferredSize(new Dimension(400, 200));
		setBackground(Color.GRAY);
		
	}
	
	private class ButtonListener1 implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			timer.start();
		}
	}
	private class ButtonListener2 implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			timer.stop();
		}
	}
	
	private class ButtonListenerC implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			x = 0;
			mytext.setText(Integer.toString(x));
		}
	}
	private class Problem9_8PanelListener implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			x += moveX;
			mytext.setText(Integer.toString(x));
		}
	}
}