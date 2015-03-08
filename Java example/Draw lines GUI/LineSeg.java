import java.awt.Point;

public class LineSeg {
	
	public Point	point1	= null, point2 = null;
	
	public LineSeg(Point point1,Point point2){
		this.point1 = point1;
		this.point2 = point2;
	}
	
	Point getPoint1(){
		return point1;
}

	Point getPoint2(){
		return point2;
}

}