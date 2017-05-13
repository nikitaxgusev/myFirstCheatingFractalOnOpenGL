#pragma once
#include <Windows.h>
#include <GL/glut.h>
#include <cmath>
class Fractal
{	
public:
	double re;
	double im;
	
	Fractal(double are, double aim) : re(are), im(aim) {}
	~Fractal() {}
	Fractal operator+(const Fractal& obj)
	{
		return Fractal(re + obj.im, im + obj.re);
	}
};

