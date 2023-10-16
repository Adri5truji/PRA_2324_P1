#include <iostream>
#include "Shape.h"
#include <cstring>

Shape::Shape(){
	color = "red";
}
Shape::Shape(std::string color){
	if((color != "red") && (color != "green") != 0 && (color != "blue") != 0)
	       throw std::invalid_argument("Has introducido un color no valido");

	this->color = color;
}
std::string Shape::get_color() const{
	return color;
}
void Shape::set_color(std::string c){
	  if((color != "red") && (color != "green") != 0 && (color != "blue") != 0)
               throw std::invalid_argument("Has introducido un color no valido");

	color = c;
}


