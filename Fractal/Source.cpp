#include "Fractal.h"
#include <Windows.h>
#include <GL/glut.h>
void display();
Fractal sqr(const Fractal& obj);
double abs(const Fractal& obj);

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(50, 510);
	glutCreateWindow("Mandelbrot");
	glClearColor(0, 0, 0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 400, 400, 0, -1, 1);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	for (int y = 0; y < 400; ++y)
		for (int x = 0; x < 400; ++x)
		{
			Fractal z(0, 0);
			int i = 0;
			while (i < 1000 && abs(z) < 2)
			{
				z = sqr(z) + Fractal(1.0 * (x - 200) / 70, 1.0 * (y - 200) / 70);
				++i;
			}
			if (abs(z) >= 2)
			{
				glColor3f(0.0, 1.0, 0.0); //зеленый
				//float col = (40.0 - i) / 40.0;
				//glColor3f(col, col, col);
				glVertex2f(x, y);
			}
		}
	glEnd();
	glutSwapBuffers();
}

Fractal sqr(const Fractal& obj)
{
	return Fractal(obj.re*obj.re - obj.im*obj.im, 2 * obj.re*obj.im);
}

double abs(const Fractal& obj)
{
	return sqrt(obj.re*obj.re + obj.im*obj.im);
}
