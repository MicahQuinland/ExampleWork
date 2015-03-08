
import java.awt.Color;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JScrollPane;
import javax.swing.JButton;

@SuppressWarnings("serial")
public class WordGui extends JPanel
{
	private JLabel		Inputlabel, StatsBox, number, average, Wcount, AWL, Ccount, Ccout;
	private JTextArea     words;
	private JScrollPane   scroll;
	private JButton       Enter;
	
	public WordGui()
	{
		Inputlabel = new JLabel("Enter the Sentence");
		Enter = new JButton("Enter");
		StatsBox = new JLabel("StatsBox: ");
		Wcount = new JLabel("Word Count: ");
		AWL = new JLabel("Averge Word Lenth: ");
		Ccount = new JLabel("Character Count");
		number = new JLabel("---");
		average = new JLabel("---");
		Ccout = new JLabel("---");
		words = new JTextArea(5,20);
	   		
		scroll = new JScrollPane(words, 
				   JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
		Enter.addActionListener(new TempListener());

		add(Inputlabel);
		add(scroll);
		add(Enter);
		add(StatsBox);
		add(Wcount);
		add(number);
		add(Ccount);
		add(Ccout);
		add(AWL);
		add(average);
		

		setPreferredSize(new Dimension(300, 75));
		setBackground(Color.white);
	}

	private class TempListener implements ActionListener
	{
		// --------------------------------------------------------------
		// Performs the conversion when the enter key is pressed in
		// the text field.
		// --------------------------------------------------------------
		public void actionPerformed(ActionEvent event)
		{
			System.out.println(event.getActionCommand());

			int i = 0, spaces = 0, length = 0, Twords = 0, letters = 0, avgW;
			
		    String input = words.getText();
		    length = input.length();
		    String j;
			for (i = 0; i < length; i++)
			{
			  j = input.substring(i, i + 1);

			   if (j.equalsIgnoreCase(" ") == true)
				spaces++;
			  else 
				letters++;	  
			}
		       
			System.out.println("My event :" + event.toString());
			Twords = (spaces + 1);
			avgW = (letters/Twords);

			number.setText(Integer.toString(Twords));
			average.setText(Integer.toString(avgW));
			Ccout.setText(Integer.toString(letters));
			
		}
	}
}


