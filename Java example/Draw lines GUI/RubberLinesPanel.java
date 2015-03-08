import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Point;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.util.ArrayList;

import javax.swing.JPanel;
@SuppressWarnings("serial") 
public class RubberLinesPanel extends JPanel
{
	private ArrayList<LineSeg>	lines;
	public LineSeg seg;
	Point p1, p2;
	// -----------------------------------------------------------------
	// Constructor: Sets up this panel to listen for mouse events.
	// -----------------------------------------------------------------
	public RubberLinesPanel()
	{   
		lines = new ArrayList<LineSeg>();
		
		LineListener listener = new LineListener();
		addMouseListener(listener);
		addMouseMotionListener(listener);
		setBackground(Color.black);
		setPreferredSize(new Dimension(400, 200));
	}
	// -----------------------------------------------------------------
	// Draws the current line from the intial mouse-pressed point to
	// the current position of the mouse.
	// -----------------------------------------------------------------
	public void paintComponent(Graphics page)
	{
		super.paintComponent(page);
		page.setColor(Color.yellow);
		  for (LineSeg seg : lines)
		      page.drawLine(seg.getPoint1().x, seg.getPoint1().y, seg.getPoint2().x, seg.getPoint2().y);
	
	}
	// *****************************************************************
	// Represents the listener for all mouse events.
	// *****************************************************************
	private class LineListener implements MouseListener, MouseMotionListener
	{
		// --------------------------------------------------------------
		// Captures the initial position at which the mouse button is
		// pressed.
		// --------------------------------------------------------------
		public void mousePressed(MouseEvent event)
		{   
			
			p1 = event.getPoint();
		
		}
		// --------------------------------------------------------------
		// Gets the current position of the mouse as it is dragged and
		// redraws the line to create the rubberband effect.
		// --------------------------------------------------------------
		public void mouseDragged(MouseEvent event){}
		// --------------------------------------------------------------
		// Provide empty definitions for unused event methods.
		// --------------------------------------------------------------
		public void mouseClicked(MouseEvent event){}
		public void mouseReleased(MouseEvent event){
			
			p2 = event.getPoint();
			seg = new LineSeg(p1,p2);
			lines.add(seg);
			repaint();
		}
		public void mouseEntered(MouseEvent event){}
		public void mouseExited(MouseEvent event){}
		public void mouseMoved(MouseEvent event){}
	}
}
