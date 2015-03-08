
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
public class PigGui extends JPanel
{
	private JLabel		Inputlabel, Result, Output;
	private JTextArea     words;
	private JScrollPane   scroll;
	private JButton       Enter;
	
	public PigGui()
	{
		Inputlabel = new JLabel("Enter the Sentence (no punctuation)");
		Enter = new JButton("Enter");
		Output = new JLabel("Translation: ");
		Result = new JLabel("---");
		words = new JTextArea(5,20);
	   		
		scroll = new JScrollPane(words, 
				   JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
		Enter.addActionListener(new TempListener());

		add(Inputlabel);
		add(scroll);
		add(Enter);
		add(Output);
		add(Result);

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
			
			String result;
			
			String sentence = words.getText();
		   
				System.out.println();
				result = PigLatinTranslator.translate(sentence);	
			
			System.out.println("My event :" + event.toString());
			Result.setText(result);
			
		}
	}
}


