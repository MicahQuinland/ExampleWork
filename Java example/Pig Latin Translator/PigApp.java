import javax.swing.JFrame;

public class PigApp {
	
	public static void main(String[] args)
	{
		JFrame frame = new JFrame("");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		PigGui primary = new PigGui();

		frame.getContentPane().add(primary);
		frame.pack();
		frame.setVisible(true);
		

	}

}
