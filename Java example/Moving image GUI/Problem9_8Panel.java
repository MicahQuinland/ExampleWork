import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JPanel;
import javax.swing.Timer;

@SuppressWarnings("serial") 
public class Problem9_8Panel extends JPanel
{
	private final int	WIDTH	= 300, HEIGHT = 100;
	private final int	DELAY	= 10;                                 // Sets rectangle speed
	private Timer		timer;
	private int			x, y, moveX;
	public Problem9_8Panel()
	{
		timer = new Timer(DELAY, new Problem9_8PanelListener());
		x = 0;                                                        // Sets default position for bar
		y = 40;
		moveX = 4;
		setPreferredSize(new Dimension(WIDTH, HEIGHT));
		setBackground(Color.white);
		
		timer.start();
	}
	public void paintComponent(Graphics page)
	{
		super.paintComponent(page);
		
		if (x < 90){                                                    // Left side image
		page.setColor(Color.yellow);
		page.fillRect(x,y,100,10);
		}
		if (x >70 && x < 130){
			
			page.setColor(Color.yellow);
			page.fillRect(x,y,50,10);
			page.setColor(Color.blue);                                 // Transition image
			page.fillRect((50+x),y,50,10);
			
		}
		if (x > 130){
			page.setColor(Color.blue);
			page.fillRect(x,y,100,10);                                // Right side image
			}
		page.setColor(Color.red);
		page.fillRect(150,0,1,100);
	}
	private class Problem9_8PanelListener implements ActionListener
	{
		public void actionPerformed(ActionEvent event)
		{
			x += moveX;
			if (x <= 0 || x >= WIDTH - 100)                              // Movements
				moveX = moveX * -1;	
			repaint();
		}
	}
}