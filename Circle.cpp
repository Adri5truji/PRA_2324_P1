#include "Circle.h"
#include <cmath>

Circle::Circle(){
	color = "red";
	center.x = 0;
	center.y = 0;
	radius = 1.0;
}
Circle::Circle(std::string color, Point2D center, double radius){
	this->color = color;
	this->center.x = center.x;
	this->center.y = center.y;
	this->radius = radius;
}
Point2D Circle::get_center() const{
	return center;
}
void Circle::set_center(Point2D p){
	center = p;
}
double Circle::get_radius() const{
	return radius;
}
void Circle::set_radius(double r){
	radius = r;
}

std::ostream& operator<<(std::ostream &out, const Circle &c){
	out << "[Circle: color = " << c.color << "; center = (" << c.center.x << "," << c.center.y << "); radius = " << c.radius << "]";
	return out;
}

double Circle::area() const{
	return (pow(3.141592,2) * radius);
}

double Circle::perimeter() const{
	return (2*3.141592*radius);
}

void Circle::translate(double incX, double incY){
	center.x += incX;
	center.y += incY;
}

void Circle::print(){
	std::cout << "[Circle: color = " << color << "; center = (" << center.x << "," << center.y << "); radius = " << radius << "]";
}	
