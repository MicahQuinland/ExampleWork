import javax.swing.JFrame;
public class Problem9_10st
{
	/**
	 * @param args
	 */
	public static void main(String[] args)
	{
		JFrame frame = new JFrame("Problem9_10st");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().add(new Problem9_10Panel());
		frame.pack();
		frame.setVisible(true);
	}
}
