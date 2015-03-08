//============================================================================
// Name        : Rectangle calculations.cpp
// Author      : Juan Micah Quinland
// Version     :
// Description : Use function call operators to find the maximum of a vector
//				 of Rectangles, first by Area, then by Perimeter.			
//============================================================================

#include <iostream>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
using namespace std;

class Rectangle{

public :
int getLength(){
	return Length;
}
int getWidth(){
	return Width;
}
explicit Rectangle(int bottom=0, int side=0)
				 :Length{bottom}, Width{side}{}	

~Rectangle(){
}
	
private:
int Length;
int Width;
};

template<typename Object, typename Comparison>
const Object & findmax(vector <Object> & rect, Comparison differ) {
	
	int max = 0;
	
	for(int i=0; i<rect.size(); ++i)
		if(differ(rect[max], rect[i])) 
			max = i;
	
	return rect[max];
	
}

class Area
{
	public:
		bool operator()(Rectangle & lhs, Rectangle & rhs) 
		{ return lhs.getLength()*lhs.getWidth() < rhs.getLength()*rhs.getWidth(); }  
};

class Perimeter
{
	public:
		bool operator()(Rectangle & lhs, Rectangle & rhs) 
		{
		 return 2*(lhs.getLength()+lhs.getWidth()) < 2*(rhs.getLength()+rhs.getWidth());
		 
		 } 
		
};

int main(){
	
vector<Rectangle> CompareTest;
	
CompareTest.push_back(Rectangle(7, 2)); 
CompareTest.push_back(Rectangle(4, 4));
	
Rectangle MaximumArea = findmax(CompareTest, Area{});
Rectangle MaximumPerimeter = findmax(CompareTest, Perimeter{});
	
cout << "The largest rectangle by Area:\n Length = " << MaximumArea.getLength(); 
cout << ", Width = "<< MaximumArea.getWidth() << endl << endl;
cout << "The largest rectangle by Perimeter:\n Length = " << MaximumPerimeter.getLength(); 
cout << ", Width = "<< MaximumPerimeter.getWidth() << endl << endl;
	
return 0;	
}

