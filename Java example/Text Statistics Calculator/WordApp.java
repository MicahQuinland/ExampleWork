
import javax.swing.JFrame;

public class WordApp {
	
	public static void main(String[] args)
	{
		JFrame frame = new JFrame("");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		WordGui primary = new WordGui();

		frame.getContentPane().add(primary);
		frame.pack();
		frame.setVisible(true);
		

	}

}

