import javax.swing.JFrame;
public class Problem9_8
{
	/**
	 * @param args
	 */
	public static void main(String[] args)
	{
		JFrame frame = new JFrame("Problem9_8");
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().add(new Problem9_8Panel());
		frame.pack();
		frame.setVisible(true);
	}
}
