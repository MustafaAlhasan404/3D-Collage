#include <GL/glut.h>
#include <math.h>
double k = 0;
double ex = 0;
double open = 0;
double ez = 0;
double light = false; double SPIN = 0;
GLUquadricObj* a = gluNewQuadric();
double up = 0;
double th = 0;
double c = 0;
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case VK_ESCAPE: /* Escape key */
		exit(0);
	break; case 'a':
		up += 1;
		break;
	case 's':
		up -= 1;
		break;

	case 'l':
		if (light) { light = false; }
		else { light = true; }
		break;

	case 'k':
		glDisable(GL_LIGHTING);
		break;

	case 'z':
		glEnable(GL_LIGHTING);
		break;

	case 'O':
		open -= 3.14 / 6;
		break;
	case'v':
		//if (c == 0)
		c = c + 3.14;
		//else
			//c = 0;
		break;

	default:
		break;
	}
}
void special(int key, int x, int y) {

	switch (key)
	{
	case GLUT_KEY_RIGHT: /* Escape key */
		th = th + 0.1;
		break;
	case GLUT_KEY_LEFT: /* Escape key */
		th = th - 0.1;
		break;
	case GLUT_KEY_UP: /* Escape key */
		ex = ex + cos(th) * 10;
		ez = ez + sin(th) * 10;
		break;
	case GLUT_KEY_DOWN: /* Escape key */
		ex = ex - cos(th) * 10;
		ez = ez - sin(th) * 10;
		break;
	default:
		break;
	}




}
void mouse(int key, int state, int x, int y) {

	switch (key)
	{
	case GLUT_RIGHT_BUTTON: /* Escape key */
		if (state == GLUT_DOWN)

			if (state == GLUT_UP)

				break;
		//case GLUT_LEFT_BUTTON: /* Escape key */
			//if (state == GLUT_UP)
			//k++;
			//break;
	default:
		break;
	}




}
void InitGL(void)
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(1.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations
	//chair list
	{
		glNewList(1, GL_COMPILE);

		//back of chair
		glPushMatrix();
		glColor3ub(139, 69, 19);
		glTranslated(80.3, -2, 50);
		glRotated(86, 0, 0, 1);
		glScaled(1.1, 0.1, 1);
		glutSolidCube(3);
		glPopMatrix();



		//ground of chair

		glPushMatrix();
		glColor3ub(139, 69, 19);
		glTranslated(78, -4.5, 50);
		//glRotated(0, 0, 0, 1);
		glScaled(1, 0.1, 1.2);
		glutSolidCube(3);
		glPopMatrix();

		//horizontal supports

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(79, -4.6, 50.8);
		glRotated(-90, 0, 1, 0);
		glScaled(0.1, 0.07, 1);
		glutSolidCube(3);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(79, -4.6, 49.2);
		glRotated(90, 0, 1, 0);
		glScaled(0.1, 0.07, 1);
		glutSolidCube(3);
		glPopMatrix();

		//vertical supports

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(80.44, -3.22, 49.2);
		glRotated(90, 1, 0, 0);
		glScaled(0.1, 0.07, 1);
		glutSolidCube(3);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(80.44, -3.22, 50.8);
		glRotated(90, 1, 0, 0);
		glScaled(0.1, 0.07, 1);
		glutSolidCube(3);
		glPopMatrix();

		//crisscross

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(78.8, -6, 50);
		glRotated(90, 0, 0, 1);
		glScaled(0.1, 0.05, 1.4);
		glutSolidCube(3);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(77.2, -6, 50);
		glRotated(90, 0, 0, 1);
		glScaled(0.1, 0.05, 1.4);
		glutSolidCube(3);
		glPopMatrix();

		//chair legs

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(78.8, -5.8, 48);
		glRotated(90, 1, 0, 0);
		glScaled(0.1, 0.06, 0.8);
		glutSolidCube(3);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(78.8, -5.8, 52);
		glRotated(90, 1, 0, 0);
		glScaled(0.1, 0.06, 0.8);
		glutSolidCube(3);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(77.2, -5.8, 48);
		glRotated(90, 1, 0, 0);
		glScaled(0.1, 0.06, 0.8);
		glutSolidCube(3);
		glPopMatrix();

		// cylinders // 
		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(76.8, -4.6, 52);
		glRotated(90, 0, 1, 0);
		glScaled(0.1, 0.1, 0.8);
		gluCylinder(a, 2, 2, 3, 10, 10);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(77, -4.6, 48);
		glRotated(90, 0, 1, 0);
		glScaled(0.1, 0.1, 0.8);
		gluCylinder(a, 2, 2, 2.5, 10, 10);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(77.2, -5.8, 52);
		glRotated(90, 1, 0, 0);
		glScaled(0.1, 0.06, 0.8);
		glutSolidCube(3);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(78, -6, 52);
		glRotated(90, 0, 1, 0);
		glScaled(0.1, 0.05, 0.6);
		glutSolidCube(3);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(78, -6, 48);
		glRotated(90, 0, 1, 0);
		glScaled(0.1, 0.05, 0.6);
		glutSolidCube(3);
		glPopMatrix();

		//stand carrier

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(77.2, -3, 48);
		glRotated(90, 1, 0, 0);
		glScaled(0.1, 0.1, 0.8);
		gluCylinder(a, 1.5, 1.5, 2, 10, 10);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(78.8, -3, 48);
		glRotated(90, 1, 0, 0);
		glScaled(0.1, 0.1, 0.8);
		gluCylinder(a, 1.5, 1.5, 2, 10, 10);
		glPopMatrix();

		/*glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(77.2, -3, 52);
		glRotated(90, 1, 0, 0);
		glScaled(0.1, 0.1, 0.8);
		gluCylinder(a, 1.5, 1.5, 2, 10, 10);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(78.8, -3, 52);
		glRotated(90, 1, 0, 0);
		glScaled(0.1, 0.1, 0.8);
		gluCylinder(a, 1.5, 1.5, 2, 10, 10);
		glPopMatrix();*/

		glEndList();
	};
	//godfather tabels
	{

		glNewList(2, GL_COMPILE);

		glPushMatrix();
		glColor3ub(139, 69, 19);
		glTranslated(360, -5, 4);
		//glRotated(0, 0, 0, 1);
		glScaled(3, 0.1, 3);
		glutSolidCube(3);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(360, -5, 7);
		glRotated(90, 1, 0, 0);
		//	glScaled(2, 0.1, 1.8);
		gluCylinder(a, 0.5, 0.5, 4.4, 10, 10);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(360, -5, 1);
		glRotated(90, 1, 0, 0);
		//	glScaled(2, 0.1, 1.8);
		gluCylinder(a, 0.5, 0.5, 4.4, 10, 10);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(360, -9.3, 7);
		glRotated(180, 1, 0, 0);
		glScaled(1, 0.1, 1);
		glutSolidSphere(1, 50, 50);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(360, -9.3, 1);
		glRotated(180, 1, 0, 0);
		glScaled(1, 0.1, 1);
		glutSolidSphere(1, 50, 50);
		glPopMatrix();

		//back of chair
		glPushMatrix();
		glColor3ub(139, 69, 19);
		glTranslated(359, -4, 14);
		glRotated(-90, 1, 0, 0);
		glScaled(1, 0.2, 1);
		glutSolidSphere(1.4, 50, 50);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(139, 69, 19);
		glTranslated(359, -4, -7);
		glRotated(90, 1, 0, 0);
		glScaled(1, 0.2, 1);
		glutSolidSphere(1.4, 50, 50);
		glPopMatrix();


		//ground of chair

		glPushMatrix();
		glColor3ub(139, 69, 19);
		glTranslated(359, -6, 12);
		glRotated(180, 1, 0, 0);
		glScaled(1, 0.1, 1);
		glutSolidSphere(2, 50, 50);
		glPopMatrix();


		glPushMatrix();
		glColor3ub(139, 69, 19);
		glTranslated(359, -6, -5);
		glRotated(180, 1, 0, 0);
		glScaled(1, 0.1, 1);
		glutSolidSphere(2, 50, 50);
		glPopMatrix();

		// cylinders // 
		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(359, -5.2, 14.2);
		glRotated(90, 1, 0, 0);
		glScaled(0.1, 0.1, 0.8);
		gluCylinder(a, 1, 1, 1, 20, 20);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(359, -5.2, -7.2);
		glRotated(90, 1, 0, 0);
		glScaled(0.1, 0.1, 0.8);
		gluCylinder(a, 1, 1, 1, 20, 20);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(359, -6.1, 14.2);
		glRotated(180, 1, 0, 0);
		glScaled(0.1, 0.1, 0.8);
		gluCylinder(a, 1, 1, 1, 20, 20);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(359, -6.1, -7.2);
		glRotated(-180, 0, 0, 1);
		glScaled(0.1, 0.1, 0.8);
		gluCylinder(a, 1, 1, 1, 20, 20);
		glPopMatrix();

		//chair legs

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(359, -6.1, 11.2);
		glRotated(90, 1, 0, 0);
		//glScaled(0.2, 0.1, 0.8);
		gluCylinder(a, 0.1, 0.1, 3.2, 10, 10);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(360, -6.1, -6.4);
		glRotated(90, 1, 0, 0);
		//glScaled(0.2, 0.1, 0.8);
		gluCylinder(a, 0.1, 0.1, 3.2, 10, 10);
		glPopMatrix();


		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(358.6, -6.1, 12.4);
		glRotated(90, 1, 0, 0);
		//glScaled(0.2, 0.1, 0.8);
		gluCylinder(a, 0.1, 0.1, 3.2, 10, 10);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(359, -6.1, -3.8);
		glRotated(90, 1, 0, 0);
		//glScaled(0.2, 0.1, 0.8);
		gluCylinder(a, 0.1, 0.1, 3.2, 10, 10);
		glPopMatrix();


		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(359.6, -6.1, 13.4);
		glRotated(90, 1, 0, 0);
		//glScaled(0.2, 0.1, 0.8);
		gluCylinder(a, 0.1, 0.1, 3.2, 10, 10);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(360, -6.1, -4.9);
		glRotated(90, 1, 0, 0);
		//glScaled(0.2, 0.1, 0.8);
		gluCylinder(a, 0.1, 0.1, 3.2, 10, 10);
		glPopMatrix();


		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(360, -6.1, 11.8);
		glRotated(90, 1, 0, 0);
		//glScaled(0.2, 0.1, 0.8);
		gluCylinder(a, 0.1, 0.1, 3.2, 10, 10);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(359, -6.1, -4.59);
		glRotated(90, 1, 0, 0);
		//glScaled(0.2, 0.1, 0.8);
		gluCylinder(a, 0.1, 0.1, 3.2, 10, 10);
		glPopMatrix();

		glEndList();

	};
	{
		glNewList(3, GL_COMPILE);
		//godfather counter


		glPushMatrix();
		glColor3ub(188, 143, 144);
		glTranslated(376, -4, 3);
		glScaled(1, 2, 3.4);
		glutSolidCube(4.2);
		glPopMatrix();
		//supports
		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(376, -5, -2);
		glRotated(90, 1, 0, 0);
		//	glScaled(2, 0.1, 1.8);
		gluCylinder(a, 0.5, 0.5, 4.4, 10, 10);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(376, -5, 8);
		glRotated(90, 1, 0, 0);
		//	glScaled(2, 0.1, 1.8);
		gluCylinder(a, 0.5, 0.5, 4.4, 10, 10);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(376, 4, -2);
		glRotated(90, 1, 0, 0);
		//glScaled(1, 2, 1);
		gluCylinder(a, 0.5, 0.5, 20.4, 10, 10);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(376, 4, 8);
		glRotated(90, 1, 0, 0);
		//	glScaled(2, 0.1, 1.8);
		gluCylinder(a, 0.5, 0.5, 20.4, 10, 10);
		glPopMatrix();


		glPushMatrix();
		glColor3ub(188, 143, 144);
		glTranslated(376, 4, 3);
		glScaled(1, 0.1, 3.4);
		glutSolidCube(4.2);
		glPopMatrix();

		glEndList();


	};
	{
		//counter2
		glNewList(4, GL_COMPILE);


		glPushMatrix();
		glColor3ub(188, 143, 144);
		glTranslated(378, -4, 5);
		glScaled(3.4, 2, 1);
		glutSolidCube(4.2);
		glPopMatrix();

		//supports
		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(372, -7, 4);
		glRotated(90, 1, 0, 0);
		//	glScaled(2, 0.1, 1.8);
		gluCylinder(a, 0.5, 0.5, 2.4, 10, 10);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(383, -7, 4);
		glRotated(90, 1, 0, 0);
		//	glScaled(2, 0.1, 1.8);
		gluCylinder(a, 0.5, 0.5, 2.4, 10, 10);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(372, 4, 4);
		glRotated(90, 1, 0, 0);
		//glScaled(1, 2, 1);
		gluCylinder(a, 0.5, 0.5, 20.4, 10, 10);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(383, 4, 4);
		glRotated(90, 1, 0, 0);
		//	glScaled(2, 0.1, 1.8);
		gluCylinder(a, 0.5, 0.5, 20.4, 10, 10);
		glPopMatrix();


		glPushMatrix();
		glColor3ub(188, 143, 144);
		glTranslated(378, 4, 4);
		glScaled(3.4, 0.1, 1);
		glutSolidCube(4.2);
		glPopMatrix();
		glEndList();

	};
	{
		glNewList(5, GL_COMPILE);
		//fire extinguisher
		glPushMatrix();
		glColor3ub(178, 34, 34);
		glTranslated(100, 0, 0);
		glScaled(0.6, 2, 3);
		glutSolidCube(2);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(128, 128, 128);
		glTranslated(100, 0, 2);
		gluCylinder(a, 0.2, 0.2, 2, 40, 40);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(128, 128, 128);
		//glRotated(120, 1, 0, 1);
		glTranslated(100, 0, 4);
		glScaled(1.4, 0.5, 1);
		//gluCylinder(a, 0.2, 0.2, 2, 40, 40);
		glutSolidCube(1);
		glPopMatrix();

		glEndList();
	};
	{
		glNewList(6, GL_COMPILE);
		//??? ?????
		glPushMatrix();
		glColor3ub(165, 42, 42);
		glRotated(90, 1, 0, 0);
		glTranslated(370, -5, 3.3);
		glScaled(1, 1, 1);
		gluCylinder(a, 2, 2, 6, 50, 50);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(0, 0, 0);
		//glRotated(90, 1, 0, 0);
		glTranslated(371, -3, -5);
		glScaled(1, 0.2, 1);
		glutSolidSphere(3, 30, 30);
		glPopMatrix();
		glEndList();
	}
	{
		glNewList(7, GL_COMPILE);
		glPushMatrix();
		glTranslated(299.9, -5.7, -27.4);

		glScaled(0.01, 1, 1);
		glColor3ub(255, 255, 255);
		glutSolidCube(4);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(299.9, -5.7, -26.4);
		glRotatef(90, 1, 0, 0);
		glColor3ub(0, 0, 0);
		gluSphere(a, 0.22, 200, 200);
		glPopMatrix();
		glEndList();
	}

	//doctor pc 
	{
		glNewList(8, GL_COMPILE);

		//Walls
		{
			//right wall
			glPushMatrix();
			glColor3ub(141, 69, 19);
			glTranslated(300, -1.7, 50);
			glRotated(90, 0, 0, 1);
			glScaled(1.2 * 2, 0.1 * 2, 1 * 2);
			glutSolidCube(3);
			glPopMatrix();

			//left wall

			glPushMatrix();
			glColor3ub(141, 69, 19);
			glTranslated(306, -1.7, 50);
			glRotated(90, 0, 0, 1);
			glScaled(1.2 * 2, 0.1 * 2, 1 * 2);
			glutSolidCube(3);
			glPopMatrix();

			//topwall

			glPushMatrix();
			glColor3ub(139, 69, 19);
			glTranslated(303, 2.2, 50);
			glRotated(90, 0, 1, 0);
			glScaled(1 * 2, 0.1 * 2, 1.1 * 2);
			glutSolidCube(3);
			glPopMatrix();

			//groundwall

			glPushMatrix();
			glColor3ub(139, 69, 19);
			glTranslated(302.95, -5, 50);
			glRotated(90, 0, 1, 0);
			glScaled(1 * 2, 0.1 * 2, 1 * 2);
			glutSolidCube(3);
			glPopMatrix();

			//backwall

			glPushMatrix();
			glColor3ub(139, 69, 19);
			glTranslated(302.95, -1.4, 52.8);
			glRotated(90, 1, 0, 0);
			glScaled(1 * 2, 0.1 * 2, 1.3 * 2);
			glutSolidCube(3);
			glPopMatrix();

			//stand

			glPushMatrix();
			glColor3ub(50, 50, 50);
			glTranslated(303, -2, 50);
			glRotated(90, 0, 1, 0);
			glScaled(1 * 2, 0.05 * 2, 0.9 * 2);
			glutSolidCube(3);
			glPopMatrix();
		};

		//pc case
		{
			glPushMatrix();
			glColor3ub(0, 0, 0);
			glTranslated(302.6, -4, 50);
			glRotated(90, 0, 0, 1);
			glScaled(0.45 * 1.5, 0.3 * 1.5, 1 * 1.5);
			glutSolidCube(3);
			glPopMatrix();
		};

		//keyboard and mouse
		{

			glPushMatrix();
			glColor3ub(0, 0, 0);
			glTranslated(303.4, -1.8, 49.4);
			glRotated(90, 0, 1, 0);
			glRotatef(-15, 0, 1, 0);
			glScaled(0.2 * 1.5, 0.01 * 1.5, 0.4 * 1.5);
			glutSolidCube(3);
			glPopMatrix();

			glPushMatrix();
			glColor3ub(0, 0, 0);
			glTranslated(302, -1.6, 49.2);
			glRotated(90, 0, 1, 0);
			glRotatef(-15, 0, 1, 0);
			glScaled(1.3 * 1.5, 0.6 * 1.5, 0.8 * 1.5);
			glutSolidSphere(0.25, 10, 10);
			glPopMatrix();
		}

		//monitor
		{
			//screen
			glPushMatrix();
			glColor3ub(0, 0, 0);
			glTranslated(303, 0, 51);
			glRotatef(-15, 0, 1, 0);
			glRotated(90, 0, 0, 1);
			glScaled(0.4 * 2, 0.44 * 2, 0.1 * 2);
			glutSolidCube(3);
			glPopMatrix();

			//screen light

			glPushMatrix();
			glColor3ub(255, 255, 0);
			glTranslated(303.05, 0, 50.5);
			glRotatef(-15, 0, 1, 0);
			glRotated(90, 0, 0, 1);
			glScaled(0.45 * 2, 0.5 * 2, 0);
			glutSolidCube(2);
			glPopMatrix();

			//base
			glPushMatrix();
			glColor3ub(105, 105, 105);
			glTranslated(302.98, 0, 51);
			glRotatef(-15, 0, 1, 0);
			glRotated(90, 1, 0, 0);
			glScaled(0.1 * 2, 0.1 * 2, 1 * 2);
			gluCylinder(a, 1, 1, 1, 4, 4);
			glPopMatrix();

			//base
			glPushMatrix();
			glColor3ub(105, 105, 105);
			glTranslated(303, -1.6, 51);
			glRotatef(-15, 0, 1, 0);
			glRotated(90, 0, 1, 0);
			glScaled(0.1 * 2, 0.15 * 2, 0.5 * 2);
			glutSolidSphere(1, 30, 30);
			glPopMatrix();
		}

		glEndList();
	}
	// stand //
	{
		glNewList(9, GL_COMPILE);
		glColor3ub(218, 165, 32);
		//glTranslated(78, -3.1, 50);
		glScaled(0.8, 0.1, 1.4);
		glutSolidCube(3);
		glEndList();
	};

	//board///
	{
		glNewList(10, GL_COMPILE);
		glPushMatrix();
		glTranslatef(0, 0, 0);
		glRotatef(90, 1, 0, 0);
		glColor3ub(255, 255, 255);
		glScalef(0.04, 1, 0.5);
		glutSolidCube(8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 0, -4);
		glRotatef(90, 1, 0, 0);
		glColor3ub(194, 197, 204);
		glScalef(0.03, 0.03, 0.5);
		glutSolidCube(8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 0, 4);
		glRotatef(90, 1, 0, 0);
		glColor3ub(194, 197, 204);
		glScalef(0.03, 0.03, 0.5);
		glutSolidCube(8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 2, 0);
		glRotatef(90, 1, 0, 0);
		glColor3ub(194, 197, 204);
		glScalef(0.03, 1.03, 0.03);
		glutSolidCube(8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, -2, 0);
		glRotatef(90, 1, 0, 0);
		glColor3ub(194, 197, 204);
		glScalef(0.03, 1.03, 0.03);
		glutSolidCube(8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, -2, 4);
		glRotatef(90, 1, 0, 0);
		glColor3ub(136, 140, 141);
		glScalef(0.03, 0.03, 0.03);
		glutSolidCube(8);
		glPopMatrix();


		glPushMatrix();
		glTranslatef(0, 2, 4);
		glRotatef(90, 1, 0, 0);
		glColor3ub(136, 140, 141);
		glScalef(0.03, 0.03, 0.03);
		glutSolidCube(8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, -2, -4);
		glRotatef(90, 1, 0, 0);
		glColor3ub(136, 140, 141);
		glScalef(0.03, 0.03, 0.03);
		glutSolidCube(8);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 2, -4);
		glRotatef(90, 1, 0, 0);
		glColor3ub(136, 140, 141);
		glScalef(0.03, 0.03, 0.03);
		glutSolidCube(8);
		glPopMatrix();
		glEndList();
	}
	//PRACTICAL
	{
		glNewList(11, GL_COMPILE);//foot of chair
		glPushMatrix();
		glRotatef(-90, 1, 0, 0);
		gluCylinder(a, 1, 1, 6, 10, 10);
		glTranslatef(0, 0, -1);
		glColor3ub(255, 255, 255);
		glutSolidSphere(1.5, 10, 10);
		glPopMatrix();
		glEndList();


		glNewList(12, GL_COMPILE);//feet of chair
		glPushMatrix();
		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslatef(-4, 0, 0);
		glRotatef(-45, 0, 0, 1);
		glCallList(11);
		glPopMatrix();
		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslatef(4, 0, 0);
		glRotatef(45, 0, 0, 1);

		glCallList(11);
		glPopMatrix();

		glRotatef(90, 0, 1, 0);
		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslatef(4, 0, 0);
		glRotatef(45, 0, 0, 1);

		glCallList(11);
		glPopMatrix();
		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslatef(-4, 0, 0);
		glRotatef(-45, 0, 0, 1);
		glCallList(11);
		glPopMatrix();
		glPopMatrix();
		glEndList();


		glNewList(13, GL_COMPILE);
		glPushMatrix();//here desk of chair
		glColor3ub(0, 5, 255);
		glRotatef(90, 1, 0, 0);
		glScalef(1, 1, 0.5);
		glutSolidTorus(5, 5, 100, 100);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(0, 30, 0);
		glRotatef(90, 1, 0, 0);
		gluCylinder(a, 3.5, 2.5, 10, 10, 10);
		glRotatef(-90, 1, 0, 0);
		glTranslatef(0, -13, 0);
		glCallList(12);
		glPopMatrix();
		glTranslatef(0, 0, 5);

		glPushMatrix();
		GLUquadricObj* w1 = gluNewQuadric();
		glScalef(5, 2, 1);
		glTranslatef(0, 0.6, -10);
		glRotatef(-90, 0.6, 0, 0);
		glRotatef(45, 0, 0, 1);
		gluCylinder(w1, 2, 1, 7, 4, 7);
		glPopMatrix();
		glEndList();
	}

	// small trash
	{
		glNewList(14, GL_COMPILE);
		glPushMatrix();
		glColor3ub(192, 192, 192);
		glTranslated(0, -2, 0);
		glRotated(90, 1, 0, 0);
		GLUquadricObj* a = gluNewQuadric();
		gluCylinder(a, 1.5, 1.09, 3.5, 100, 100);
		glPopMatrix();


		glPushMatrix();
		glColor3ub(255, 0, 0);
		glTranslated(0, -2, 0);
		glRotated(90, 1, 0, 0);
		glutSolidTorus(0.09, 1.5, 20, 20);
		glPopMatrix();



		glEndList();
	}

	//cooler
	{
		glNewList(15, GL_COMPILE);
		glPushMatrix();
		glColor3ub(222, 184, 135);
		glTranslated(0, -5.3, 0);
		glScaled(1, 2.5, 1);
		glutSolidCube(3);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(176, 194, 222);
		glRotated(-90, 1, 0, 0);
		glTranslated(0, 0, -2);
		//glScaled(4, 1, 1);
		gluCylinder(a, 1.5, 1.5, 4.2, 20, 20);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(112, 128, 144);
		glTranslated(-1, -3.3, 0);
		glScaled(1.4, 0.3, 1);
		glutSolidSphere(1.4, 20, 20);
		glPopMatrix();


		glPushMatrix();
		glColor3ub(112, 128, 144);
		glTranslated(-1, -4.5, 0);
		glScaled(1.2, 0.3, 1);
		glutSolidSphere(1.4, 20, 20);
		glPopMatrix();


		glPushMatrix();
		glColor3ub(70, 130, 180);
		glTranslated(0, 2.2, 0);
		glScaled(1, 0.1, 1);
		glutSolidSphere(2, 20, 20);
		glPopMatrix();
		glEndList();
	}

	//door
	{
		glNewList(16, GL_COMPILE);
		glPushMatrix();
		glTranslated(0, -4, 0);
		glColor3ub(235, 183, 121);
		glScaled(0, 16, 5);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslated(0, -4, 1.8);
		glColor3ub(139, 69, 19);
		glutSolidSphere(0.4, 30, 10);
		glPopMatrix();
		glEndList();
	}
	//door frame
	{
		glNewList(17, GL_COMPILE);
		glPushMatrix();
		glColor3ub(139, 69, 19);
		glTranslated(0, -4, 4);
		glScaled(0, 16, 3.1);
		glutSolidCube(1);
		glPopMatrix();
		glEndList();
	}


	{
		{	//dr.chair

			GLUquadricObj* a = gluNewQuadric();
			glNewList(18, GL_COMPILE);//dr.chair wheels
			glPushMatrix();
			glRotatef(-90, 1, 0, 0);
			gluCylinder(a, 1, 1, 10, 10, 10);
			glTranslatef(0, 0, -1);
			glColor3ub(1, 1, 1);
			glutSolidSphere(1.4, 10, 10);
			glPopMatrix();
			glEndList();

		}

		glNewList(19, GL_COMPILE);//dr.chair feet
		glPushMatrix();
		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslatef(-6, 0, 0);
		glRotatef(-45, 0, 0, 1);
		glCallList(18);
		glPopMatrix();
		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslatef(6, 0, 0);
		glRotatef(45, 0, 0, 1);
		glCallList(18);
		glPopMatrix();
		glRotatef(90, 0, 1, 0);
		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslatef(6, 0, 0);
		glRotatef(45, 0, 0, 1);
		glCallList(18);
		glPopMatrix();
		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslatef(-6, 0, 0);
		glRotatef(-45, 0, 0, 1);
		glCallList(18);
		glPopMatrix();
		glPopMatrix();
		glEndList();
	};

	{
		glNewList(20, GL_COMPILE);
		glPushMatrix();//the rest of the dr.chair //desk
		glColor3ub(50, 50, 50);
		glRotatef(90, 1, 0, 0);
		glScalef(1, 1, 0.5);
		glutSolidTorus(7, 7, 100, 100);
		glPopMatrix();


		///////////////////////////////////
		/////hands
		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslatef(1, 10, -12);
		glRotatef(90, 1, 0, 0);
		gluCylinder(a, 1, 0.8, 8, 10, 10);
		glPopMatrix();


		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslatef(-7, 10, -12);
		glRotatef(90, 1, 0, 0);
		gluCylinder(a, 1, 0.8, 8, 10, 10);
		glPopMatrix();


		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslatef(-7.7, 10, -12);
		glRotatef(90, 0, 1, 0);
		gluCylinder(a, 1, 1, 9.5, 10, 10);
		glPopMatrix();

		///////////////////



		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslatef(1, 10, 10.8);
		glRotatef(90, 1, 0, 0);
		gluCylinder(a, 1, 0.8, 8, 10, 10);
		glPopMatrix();


		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslatef(-7, 10, 10.8);
		glRotatef(90, 1, 0, 0);
		gluCylinder(a, 1, 0.8, 8, 10, 10);
		glPopMatrix();


		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslatef(-7.7, 10, 10.8);
		glRotatef(90, 0, 1, 0);
		gluCylinder(a, 1, 1, 9.5, 10, 10);
		glPopMatrix();
		//////////////////////////
		////bases
		glPushMatrix();
		glColor3ub(0, 0, 0);
		glRotatef(90, 1, 0, 0);
		gluCylinder(a, 2.5, 2.5, 10, 10, 10);
		glRotatef(-90, 1, 0, 0);
		glTranslatef(0, -13, 0);
		glCallList(19);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(10, 15, 0);
		glRotatef(90, 1, 0, 0);
		glScalef(0.5, 1, 1);
		gluCylinder(a, 2, 2, 12, 10, 10);
		glPopMatrix();
		/////////back
		glPushMatrix();
		GLUquadricObj* w1 = gluNewQuadric();

		glColor3ub(50, 50, 50);
		glTranslatef(6, 20, 0);
		glRotatef(90, 0, 1, 0);
		glScalef(1, 1, 0.5);
		glutSolidTorus(6.4, 6.4, 100, 100);
		glPopMatrix();
		glEndList();
	};
	{
		glNewList(21, GL_COMPILE);
		//doctor's table
		glPushMatrix();
		GLUquadricObj* a = gluNewQuadric();
		glScaled(3, 3, 3);
		glTranslated(-300, -1, -40);
		//stand

		glPushMatrix();
		glColor3ub(139, 69, 19);
		glTranslated(303, -2, 50);
		glRotated(90, 0, 1, 0);
		glScaled(0.5, 0.03, 1);
		glutSolidCube(7);
		glPopMatrix();


		//legs

		glPushMatrix();
		glColor3ub(139, 69, 19);
		glTranslated(306.5, -3, 50);
		glRotated(90, 0, 1, 0);
		glScaled(0.7, 0.4, 0.03);
		glutSolidCube(5);
		glPopMatrix();



		glPushMatrix();
		glColor3ub(139, 69, 19);
		glTranslated(299.6, -3, 50);
		glRotated(90, 0, 1, 0);
		glScaled(0.7, 0.4, 0.03);
		glutSolidCube(5);
		glPopMatrix();

		//monitor
		glPushMatrix();
		glTranslatef(-0.4, 0, 0);

		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslated(303, -1, 50);
		glRotatef(-15, 0, 1, 0);
		glRotated(90, 0, 0, 1);
		glScaled(0.4, 0.44, 0.1);
		glutSolidCube(3);
		glPopMatrix();

		//screen light

		glPushMatrix();
		glColor3ub(255, 255, 0);
		glTranslated(303.05, -1, 49.8);
		glRotatef(-15, 0, 1, 0);
		glRotated(90, 0, 0, 1);
		glScaled(0.45, 0.5, 0);
		glutSolidCube(2);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(302.98, -1, 50);
		glRotatef(-15, 0, 1, 0);
		glRotated(90, 1, 0, 0);
		glScaled(0.1, 0.1, 1);
		gluCylinder(a, 1, 1, 1, 4, 4);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(303, -1.8, 50);
		glRotatef(-15, 0, 1, 0);
		glRotated(90, 0, 1, 0);
		glScaled(0.1, 0.15, 0.5);
		glutSolidSphere(1, 30, 30);
		glPopMatrix();

		glPopMatrix();

		//keyboard and mouse



		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslated(303.4, -1.8, 49.4);
		glRotated(90, 0, 1, 0);
		glRotatef(-15, 0, 1, 0);
		glScaled(0.2, 0.01, 0.4);
		glutSolidCube(3);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslated(302.4, -1.8, 49.2);
		glRotated(90, 0, 1, 0);
		glRotatef(-15, 0, 1, 0);
		glScaled(1.3, 0.6, 0.8);
		glutSolidSphere(0.25, 10, 10);
		glPopMatrix();

		glPopMatrix();
		glEndList();
	};
	{
		glNewList(22, GL_COMPILE);
		{




			//stand

			glPushMatrix();
			glColor3ub(139, 69, 19);
			glTranslated(0, -2, 0);
			glRotated(90, 0, 1, 0);
			glScaled(1, 0.07, 1);
			glutSolidCube(3.2);
			glPopMatrix();


			//legs

				//corners
			//top right
			glColor3ub(139, 69, 19);

			glPushMatrix();
			glTranslated(1.5, -2.7, 1.5);
			glRotated(90, 0, 1, 0);
			glScaled(0.15, 1, 0.15);
			glutSolidCube(1.3);
			glPopMatrix();

			//down right
			glPushMatrix();
			glTranslated(1.5, -2.7, -1.5);
			glRotated(90, 0, 1, 0);
			glScaled(0.15, 1, 0.15);
			glutSolidCube(1.3);
			glPopMatrix();





			//top left
			glPushMatrix();
			glTranslated(-1.5, -2.7, 1.5);
			glRotated(90, 0, 1, 0);
			glScaled(0.15, 1, 0.15);
			glutSolidCube(1.3);
			glPopMatrix();

			//down left
			glPushMatrix();
			glTranslated(-1.5, -2.7, -1.5);
			glRotated(90, 0, 1, 0);
			glScaled(0.15, 1, 0.15);
			glutSolidCube(1.3);
			glPopMatrix();

		}
		glEndList();
	};
	{
		glNewList(23, GL_COMPILE); {
			// fayez's table
			{

				{




					//stand

					glPushMatrix();
					glColor3ub(139, 69, 19);
					glTranslated(303, -2, 50);
					glRotated(90, 0, 1, 0);
					glScaled(0.5, 0.03, 1);
					glutSolidCube(7);
					glPopMatrix();


					//legs


					glPushMatrix();
					glColor3ub(139, 69, 19);
					glTranslated(306.4, -3, 51.62);
					glRotated(90, 0, 1, 0);
					glScaled(0.07, 1, 0.07);
					glutSolidCube(2);
					glPopMatrix();


					glPushMatrix();
					glColor3ub(139, 69, 19);
					glTranslated(299.6, -3, 51.62);
					glRotated(90, 0, 1, 0);
					glScaled(0.07, 1, 0.07);
					glutSolidCube(2);
					glPopMatrix();


					glPushMatrix();
					glColor3ub(139, 69, 19);
					glTranslated(306.4, -3, 48.28);
					glRotated(90, 0, 1, 0);
					glScaled(0.07, 1, 0.07);
					glutSolidCube(2);
					glPopMatrix();


					glPushMatrix();
					glColor3ub(139, 69, 19);
					glTranslated(299.5, -3, 48.28);
					glRotated(90, 0, 1, 0);
					glScaled(0.07, 1, 0.07);
					glutSolidCube(2);
					glPopMatrix();

				};





				//monitor
				glPushMatrix();
				glTranslatef(-0.4, 0, 0);
				{
					glPushMatrix();
					glColor3ub(0, 0, 0);
					glTranslated(303, -1, 50);
					glRotatef(-15, 0, 1, 0);
					glRotated(90, 0, 0, 1);
					glScaled(0.4, 0.44, 0.1);
					glutSolidCube(3);
					glPopMatrix();

					//screen light

					glPushMatrix();
					glColor3ub(255, 255, 0);
					glTranslated(303.05, -1, 49.8);
					glRotatef(-15, 0, 1, 0);
					glRotated(90, 0, 0, 1);
					glScaled(0.45, 0.5, 0);
					glutSolidCube(2);
					glPopMatrix();

					glPushMatrix();
					glColor3ub(105, 105, 105);
					glTranslated(302.98, -1, 50);
					glRotatef(-15, 0, 1, 0);
					glRotated(90, 1, 0, 0);
					glScaled(0.1, 0.1, 1);
					gluCylinder(a, 1, 1, 1, 4, 4);
					glPopMatrix();

					glPushMatrix();
					glColor3ub(105, 105, 105);
					glTranslated(303, -1.8, 50);
					glRotatef(-15, 0, 1, 0);
					glRotated(90, 0, 1, 0);
					glScaled(0.1, 0.15, 0.5);
					glutSolidSphere(1, 30, 30);
					glPopMatrix();
				}
				glPopMatrix();

				//keyboard and mouse

				{

					glPushMatrix();
					glColor3ub(0, 0, 0);
					glTranslated(303.4, -1.8, 49.4);
					glRotated(90, 0, 1, 0);
					glRotatef(-15, 0, 1, 0);
					glScaled(0.2, 0.01, 0.4);
					glutSolidCube(3);
					glPopMatrix();

					glPushMatrix();
					glColor3ub(0, 0, 0);
					glTranslated(302.4, -1.8, 49.2);
					glRotated(90, 0, 1, 0);
					glRotatef(-15, 0, 1, 0);
					glScaled(1.3, 0.6, 0.8);
					glutSolidSphere(0.25, 10, 10);
					glPopMatrix();
				}

			}


		}
		glEndList();

	};
	{
		glNewList(24, GL_COMPILE);
		{


			//guest's chairs

			glPushMatrix();//the rest of the dr.chair //desk
			glColor3ub(36, 37, 38);
			glTranslatef(-1.4, 1, 0);
			glRotatef(90, 1, 0, 0);
			glScalef(1.3, 1.3, 0.1);
			glutSolidCube(19);
			glPopMatrix();


			///////////////////////////////////
			/////hands



			glPushMatrix();
			glColor3ub(0, 0, 0);
			glTranslatef(-7, 10, -12);
			glRotatef(90, 1, 0, 0);
			gluCylinder(a, 1, 0.8, 8, 10, 10);
			glPopMatrix();


			glPushMatrix();
			glColor3ub(0, 0, 0);
			glTranslatef(-7.7, 10, -12);
			glRotatef(90, 0, 1, 0);
			gluCylinder(a, 1, 1, 19, 10, 10);
			glPopMatrix();

			///////////////////


			glPushMatrix();
			glColor3ub(0, 0, 0);
			glTranslatef(-7, 10, 10.8);
			glRotatef(90, 1, 0, 0);
			gluCylinder(a, 1, 0.8, 8, 10, 10);
			glPopMatrix();


			glPushMatrix();
			glColor3ub(0, 0, 0);
			glTranslatef(-7.7, 10, 10.8);
			glRotatef(90, 0, 1, 0);
			gluCylinder(a, 1, 1, 19, 10, 10);
			glPopMatrix();
			//////////////////////////
			////bases
			glPushMatrix();
			glColor3ub(0, 0, 0);
			glRotatef(90, 1, 0, 0);
			gluCylinder(a, 2.5, 2.5, 10, 10, 10);
			glRotatef(-90, 1, 0, 0);
			glTranslatef(0, -13, 0);
			glCallList(19);
			glPopMatrix();


			/////////back
			glPushMatrix();
			GLUquadricObj* w1 = gluNewQuadric();

			glColor3ub(36, 37, 38);
			glTranslatef(12, 15.6, 0);
			glRotatef(90, 0, 1, 0);
			glScalef(1.18, 1.5, 0.1);
			glutSolidCube(21);
			glPopMatrix();

		}
		glEndList();

	};
	{
		glNewList(25, GL_COMPILE); {
			//meeting table

	//stand

			glPushMatrix();
			glColor3ub(139, 69, 19);
			glTranslated(303, -2, 50);
			glRotated(90, 0, 1, 0);
			glScaled(0.5, 0.03, 1);
			glutSolidCube(7);
			glPopMatrix();


			//legs


			glPushMatrix();
			glColor3ub(139, 69, 19);
			glTranslated(306.4, -3, 51.62);
			glRotated(90, 0, 1, 0);
			glScaled(0.07, 1, 0.07);
			glutSolidCube(2);
			glPopMatrix();


			glPushMatrix();
			glColor3ub(139, 69, 19);
			glTranslated(299.6, -3, 51.62);
			glRotated(90, 0, 1, 0);
			glScaled(0.07, 1, 0.07);
			glutSolidCube(2);
			glPopMatrix();


			glPushMatrix();
			glColor3ub(139, 69, 19);
			glTranslated(306.4, -3, 48.28);
			glRotated(90, 0, 1, 0);
			glScaled(0.07, 1, 0.07);
			glutSolidCube(2);
			glPopMatrix();


			glPushMatrix();
			glColor3ub(139, 69, 19);
			glTranslated(299.5, -3, 48.28);
			glRotated(90, 0, 1, 0);
			glScaled(0.07, 1, 0.07);
			glutSolidCube(2);
			glPopMatrix();


		}

		glEndList();
	};
	{
		glNewList(26, GL_COMPILE); {
			glPushMatrix();
			glPushMatrix();
			glColor3ub(255, 255, 255);
			glutSolidCube(3);
			glPopMatrix();

			glPushMatrix();
			glColor3ub(136, 140, 141);
			glTranslated(-1.5, -0.8, 0);
			glRotated(90, 0, 1, 0);
			glScaled(1, 0.05, 0.01);
			glutSolidCube(3);
			glPopMatrix();

			glPushMatrix();
			glColor3ub(0, 0, 0);
			glTranslated(-1.5, -0.3, 0);
			glRotated(90, 0, 1, 0);
			glScaled(1, 0.09, 0.01);
			glutSolidCube(3);
			glPopMatrix();

			glPushMatrix();
			glColor3ub(0, 0, 0);
			glTranslated(-1.5, 0.7, 1.2);
			glRotated(90, 0, 1, 0);
			glScaled(0.05, 0.05, 0.01);
			glutSolidCube(3);
			glPopMatrix();

			glPopMatrix();

		}

		glEndList();
	};
	//practcal tables
	{
		glNewList(100, GL_COMPILE);
		//right wall
		glPushMatrix();
		glColor3ub(139, 69, 19);
		glTranslated(299.5, -2, 50);
		glRotated(90, 0, 0, 1);
		glScaled(1 * 1.5, 0.1 * 1.5, 1 * 1.5);
		glutSolidCube(3);
		glPopMatrix();

		//left wall

		glPushMatrix();
		glColor3ub(139, 69, 19);
		glTranslated(305, -2, 50);
		glRotated(90, 0, 0, 1);
		glScaled(1 * 1.5, 0.1 * 1.5, 1 * 1.5);
		glutSolidCube(3);
		glPopMatrix();

		//stand

		glPushMatrix();
		glColor3ub(139, 69, 19);
		glTranslated(302.3, -2, 50);
		glRotated(90, 0, 1, 0);
		glScaled(1 * 1.5, 0.1 * 1.5, 1.3 * 1.5);
		glutSolidCube(3);
		glPopMatrix();

		//seperater

		glPushMatrix();
		glColor3ub(139, 69, 19);
		glTranslated(301.8, -3.15, 50);
		glRotated(90, 0, 0, 1);
		glScaled(0.47 * 1.5, 0.05 * 1.5, 1.3 * 1.5);
		glutSolidCube(3);
		glPopMatrix();

		//pc case

		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslated(301.1, -3.5, 50);
		glRotated(90, 0, 0, 1);
		glScaled(0.45 * 1.2, 0.3 * 1, 1 * 1.2);
		glutSolidCube(3);
		glPopMatrix();

		//monitor
		{

			glPushMatrix();
			glColor3ub(0, 0, 0);
			glTranslated(302, -0.5, 51);
			glRotatef(-15, 0, 1, 0);
			glRotated(90, 0, 0, 1);
			glScaled(0.4 * 1.5, 0.44 * 1.5, 0.1 * 1.5);
			glutSolidCube(3);
			glPopMatrix();

			//screen light

			glPushMatrix();
			glColor3ub(255, 255, 0);
			glTranslated(302.1, -0.5, 50.7);
			glRotatef(-15, 0, 1, 0);
			glRotated(90, 0, 0, 1);
			glScaled(0.45 * 1.5, 0.5 * 1.5, 0);
			glutSolidCube(2);
			glPopMatrix();

			//screen holder


			glPushMatrix();
			glColor3ub(105, 105, 105);
			glTranslated(302, -1, 51);
			glRotatef(-15, 0, 1, 0);
			glRotated(90, 1, 0, 0);
			glScaled(0.1 * 1.35, 0.1 * 1.3, 1 * 1.3);
			gluCylinder(a, 1, 1, 1, 4, 4);
			glPopMatrix();

			glPushMatrix();
			glColor3ub(105, 105, 105);
			glTranslated(302, -1.8, 51);
			glRotatef(-15, 0, 1, 0);
			glRotated(90, 0, 1, 0);
			glScaled(0.1 * 1.3, 0.15 * 1.3, 0.5 * 1.3);
			glutSolidSphere(1, 30, 30);
			glPopMatrix();

		};
		//keyboard and mouse

		{

			glPushMatrix();
			glColor3ub(0, 0, 0);
			glTranslated(303, -1.7, 49.4);
			glRotated(90, 0, 1, 0);
			glRotatef(-15, 0, 1, 0);
			glScaled(0.2 * 1.5, 0.01 * 1.5, 0.4 * 1.5);
			glutSolidCube(3);
			glPopMatrix();

			glPushMatrix();
			glColor3ub(0, 0, 0);
			glTranslated(301.5, -1.8, 49.2);
			glRotated(90, 0, 1, 0);
			glRotatef(-15, 0, 1, 0);
			glScaled(1.3 * 1.3, 0.6 * 1.3, 0.8 * 1.3);
			glutSolidSphere(0.25, 10, 10);
			glPopMatrix();
		}

		glEndList();
	}
	/*float Po[] = { 300, 8, 110, 1 };
	glLightfv(GL_LIGHT0, GL_POSITION, Po);

	float diffuse[] = { 1,1,1,0 };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);

	float ambient[] = { 0.2,0.2,0.2,0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);

	float specular[] = { 1,0,1,0 };
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);*/
}

void ReSizeGLScene(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 0.1f, 500.0f);
	//gluOrtho2D(-50, 50, -10, 80);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void DrawGLScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(ex, up, ez, ex + cos(th), up, ez + sin(th), 0, 1, 0);


	glEnable(GL_COLOR_MATERIAL);

	float pos[] = { 0, 8, 0, 1 };
	glLightfv(GL_LIGHT0, GL_POSITION, pos);
	float dif[] = { 1,1,1,0 };
	float dif0[] = { 0,0,0,0 };
	float ambient[] = { 0.2,0.2,0.2,0 };
	float ambient0[] = { 0,0,0,0 };
	float specular[] = { 1,0,1,0 };
	float specular0[] = { 0,0,0,0 };
	if (light) {
		glLightfv(GL_LIGHT0, GL_DIFFUSE, dif);
		glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
		glLightfv(GL_LIGHT0, GL_AMBIENT, ambient0);
	}
	else {
		glLightfv(GL_LIGHT0, GL_DIFFUSE, dif0);
		glLightfv(GL_LIGHT0, GL_SPECULAR, specular0);
		glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	}


	//////////////////////////////// morning/////////////////////////////////////////
	glPushMatrix();

	GLUquadricObj* c1 = gluNewQuadric();

	glPushMatrix();
	glTranslatef(280, 40, -25);
	glColor3ub(255, 255, 255);
	glRotated(90, 1, 0, 0);
	glScalef(1, 1, 1);
	gluCylinder(c1, 3, 3, 50, 200, 200);


	glPopMatrix();
	glPopMatrix();

	glPushMatrix();

	GLUquadricObj* c2 = gluNewQuadric();

	glPushMatrix();
	glTranslatef(290, 40, 25);
	glColor3ub(255, 255, 255);
	glRotated(90, 1, 0, 0);
	glScalef(1, 1, 1);
	gluCylinder(c2, 3, 3, 50, 200, 200);


	glPopMatrix();
	glPopMatrix();
	//////////////////////////////////////////////
	glPushMatrix();
	glColor3ub(239, 211, 211);
	glBegin(GL_QUADS);

	//first one behind camera
	glVertex3d(-29, -4, -14);
	glVertex3d(-29, 6, -14);
	glVertex3d(-29, 6, 0);
	glVertex3d(-29, -4, 0);

	glVertex3d(-29, -4, -46);
	glVertex3d(-29, 6, -46);
	glVertex3d(-29, 6, -32);
	glVertex3d(-29, -4, -32);

	glVertex3d(-29, -4, 16);
	glVertex3d(-29, 6, 16);
	glVertex3d(-29, 6, 30);
	glVertex3d(-29, -4, 30);

	////////////////////////////////////////////////
	glVertex3d(-29, 26, -14);
	glVertex3d(-29, 36, -14);
	glVertex3d(-29, 36, 0);
	glVertex3d(-29, 26, 0);

	glVertex3d(-29, 26, -46);
	glVertex3d(-29, 36, -46);
	glVertex3d(-29, 36, -32);
	glVertex3d(-29, 26, -32);

	glVertex3d(-29, 26, 16);
	glVertex3d(-29, 36, 16);
	glVertex3d(-29, 36, 30);
	glVertex3d(-29, 26, 30);

	glEnd();
	glPopMatrix();

	//////////////////////////////////////////////////////////////////////////////////////////

	/////////////////////////////////////////////////////////////////////////

	glPushMatrix();
	glColor3ub(239, 211, 211);
	glBegin(GL_QUADS);

	///  wall of DSL that has mashareb

	glVertex3d(8, 39, 5);
	glVertex3d(8, 23, 5);
	glVertex3d(8, 23, 55);
	glVertex3d(8, 39, 55);

	glVertex3d(8, 39, 55);
	glVertex3d(8, 23, 55);
	glVertex3d(24, 23, 55);
	glVertex3d(24, 39, 55);

	/// wall behind stairs phL
	glVertex3d(8, 39, 92);
	glVertex3d(8, 23, 92);
	glVertex3d(85, 23, 92);
	glVertex3d(85, 39, 92);

	glVertex3d(85, 39, 92);
	glVertex3d(85, 23, 92);
	glVertex3d(85, 23, 55);
	glVertex3d(85, 39, 55);



	//the wall right to DSL door
	glVertex3d(8, 39, 5);
	glVertex3d(24, 39, 5);
	glVertex3d(24, 23, 5);
	glVertex3d(8, 23, 5);

	//the top wall of DSL door
	glVertex3d(24, 39, 5);
	glVertex3d(32, 39, 5);
	glVertex3d(32, 35, 5);
	glVertex3d(24, 35, 5);



	//the wall left to DSL door and right to LCL door
	glVertex3d(32, 39, 5);
	glVertex3d(90, 39, 5);
	glVertex3d(90, 23, 5);
	glVertex3d(32, 23, 5);

	//the top wall of LCL door
	glVertex3d(90, 39, 5);
	glVertex3d(98, 39, 5);
	glVertex3d(98, 35, 5);
	glVertex3d(90, 35, 5);

	//the wall left to LCL door and right to Arduino lab door
	glVertex3d(98, 39, 5);
	glVertex3d(146, 39, 5);
	glVertex3d(146, 23, 5);
	glVertex3d(98, 23, 5);

	//the top wall of Arduino lab door
	glVertex3d(146, 39, 5);
	glVertex3d(154, 39, 5);
	glVertex3d(154, 35, 5);
	glVertex3d(146, 35, 5);

	//the wall left to Arduino lab door and right to CL-10 door
	glVertex3d(154, 39, 5);
	glVertex3d(202, 39, 5);
	glVertex3d(202, 23, 5);
	glVertex3d(154, 23, 5);

	//the top wall of CL-10 door
	glVertex3d(202, 39, 5);
	glVertex3d(210, 39, 5);
	glVertex3d(210, 35, 5);
	glVertex3d(202, 35, 5);

	//the wall left to CL-10 door until the end of the corridor
	glVertex3d(210, 39, 5);
	glVertex3d(258, 39, 5);
	glVertex3d(258, 23, 5);
	glVertex3d(210, 23, 5);

	//the back wall of CL-10
	glVertex3d(258, 39, 5);
	glVertex3d(258, 23, 5);
	glVertex3d(258, 23, 55);
	glVertex3d(258, 39, 55);



	// CL-10

	// first window in CL-10
	glVertex3d(258, 39, 55);
	glVertex3d(258, 23, 55);
	glVertex3d(246, 23, 55);
	glVertex3d(246, 39, 55);

	glVertex3d(246, 39, 55);
	glVertex3d(246, 35, 55);
	glVertex3d(238, 35, 55);
	glVertex3d(238, 39, 55);

	glVertex3d(246, 27, 55);
	glVertex3d(246, 23, 55);
	glVertex3d(238, 23, 55);
	glVertex3d(238, 27, 55);

	glVertex3d(238, 39, 55);
	glVertex3d(238, 23, 55);
	glVertex3d(234, 23, 55);
	glVertex3d(234, 39, 55);
	//end

	// second window in CL-10
	glVertex3d(234, 39, 55);
	glVertex3d(234, 35, 55);
	glVertex3d(226, 35, 55);
	glVertex3d(226, 39, 55);

	glVertex3d(234, 27, 55);
	glVertex3d(234, 23, 55);
	glVertex3d(226, 23, 55);
	glVertex3d(226, 27, 55);

	glVertex3d(226, 39, 55);
	glVertex3d(226, 23, 55);
	glVertex3d(222, 23, 55);
	glVertex3d(222, 39, 55);
	//end

	//third window in CL-10
	glVertex3d(222, 39, 55);
	glVertex3d(222, 35, 55);
	glVertex3d(214, 35, 55);
	glVertex3d(214, 39, 55);

	glVertex3d(222, 27, 55);
	glVertex3d(222, 23, 55);
	glVertex3d(214, 23, 55);
	glVertex3d(214, 27, 55);


	glVertex3d(214, 39, 55);
	glVertex3d(214, 23, 55);
	glVertex3d(210, 23, 55);
	glVertex3d(210, 39, 55);

	//end

	// the wall between the board wall and the nearest window
	glVertex3d(210, 39, 55);
	glVertex3d(210, 23, 55);
	glVertex3d(202, 23, 55);
	glVertex3d(202, 39, 55);


	//board wall in CL-10
	glVertex3d(202, 39, 55);
	glVertex3d(202, 23, 55);
	glVertex3d(200, 23, 5);
	glVertex3d(200, 39, 5);

	//END OF CL-10

	//Ardino lab

	// first window in Ardino lab
	glVertex3d(202, 39, 55);
	glVertex3d(202, 23, 55);
	glVertex3d(190, 23, 55);
	glVertex3d(190, 39, 55);

	glVertex3d(190, 39, 55);
	glVertex3d(190, 35, 55);
	glVertex3d(182, 35, 55);
	glVertex3d(182, 39, 55);

	glVertex3d(190, 27, 55);
	glVertex3d(190, 23, 55);
	glVertex3d(182, 23, 55);
	glVertex3d(182, 27, 55);

	glVertex3d(182, 39, 55);
	glVertex3d(182, 23, 55);
	glVertex3d(178, 23, 55);
	glVertex3d(178, 39, 55);
	//end

	// second window in Ardino lab
	glVertex3d(178, 39, 55);
	glVertex3d(178, 35, 55);
	glVertex3d(170, 35, 55);
	glVertex3d(170, 39, 55);

	glVertex3d(178, 27, 55);
	glVertex3d(178, 23, 55);
	glVertex3d(170, 23, 55);
	glVertex3d(170, 27, 55);

	glVertex3d(170, 39, 55);
	glVertex3d(170, 23, 55);
	glVertex3d(166, 23, 55);
	glVertex3d(166, 39, 55);

	//third window in Ardino lab
	glVertex3d(166, 39, 55);
	glVertex3d(166, 35, 55);
	glVertex3d(158, 35, 55);
	glVertex3d(158, 39, 55);

	glVertex3d(166, 27, 55);
	glVertex3d(166, 23, 55);
	glVertex3d(158, 23, 55);
	glVertex3d(158, 27, 55);

	glVertex3d(158, 39, 55);
	glVertex3d(158, 23, 55);
	glVertex3d(146, 23, 55);
	glVertex3d(146, 39, 55);

	//board wall in Ardino lab
	glVertex3d(146, 39, 55);
	glVertex3d(146, 23, 55);
	glVertex3d(144, 23, 5);
	glVertex3d(144, 39, 5);

	//END OF Ardino lab

	//LCL
	//first window
	glVertex3d(146, 39, 55);
	glVertex3d(146, 23, 55);
	glVertex3d(134, 23, 55);
	glVertex3d(134, 39, 55);

	glVertex3d(134, 39, 55);
	glVertex3d(134, 35, 55);
	glVertex3d(126, 35, 55);
	glVertex3d(126, 39, 55);

	glVertex3d(134, 27, 55);
	glVertex3d(134, 23, 55);
	glVertex3d(126, 23, 55);
	glVertex3d(126, 27, 55);

	glVertex3d(126, 39, 55);
	glVertex3d(126, 23, 55);
	glVertex3d(122, 23, 55);
	glVertex3d(122, 39, 55);

	//second window in LCL
	glVertex3d(122, 39, 55);
	glVertex3d(122, 35, 55);
	glVertex3d(114, 35, 55);
	glVertex3d(114, 39, 55);

	glVertex3d(122, 27, 55);
	glVertex3d(122, 23, 55);
	glVertex3d(114, 23, 55);
	glVertex3d(114, 27, 55);

	glVertex3d(114, 39, 55);
	glVertex3d(114, 23, 55);
	glVertex3d(110, 23, 55);
	glVertex3d(110, 39, 55);

	//third window in LCL
	glVertex3d(110, 39, 55);
	glVertex3d(110, 35, 55);
	glVertex3d(102, 35, 55);
	glVertex3d(102, 39, 55);

	glVertex3d(110, 27, 55);
	glVertex3d(110, 23, 55);
	glVertex3d(102, 23, 55);
	glVertex3d(102, 27, 55);

	glVertex3d(102, 39, 55);
	glVertex3d(102, 23, 55);
	glVertex3d(90, 23, 55);
	glVertex3d(90, 39, 55);

	//board wall in LCL
	glVertex3d(90, 39, 55);
	glVertex3d(90, 23, 55);
	glVertex3d(88, 23, 5);
	glVertex3d(88, 39, 5);

	//DSL
	//first window
	glVertex3d(90, 39, 55);
	glVertex3d(90, 23, 55);
	glVertex3d(78, 23, 55);
	glVertex3d(78, 39, 55);

	glVertex3d(78, 39, 55);
	glVertex3d(78, 35, 55);
	glVertex3d(70, 35, 55);
	glVertex3d(70, 39, 55);

	glVertex3d(78, 27, 55);
	glVertex3d(78, 23, 55);
	glVertex3d(70, 23, 55);
	glVertex3d(70, 27, 55);

	glVertex3d(70, 39, 55);
	glVertex3d(70, 23, 55);
	glVertex3d(66, 23, 55);
	glVertex3d(66, 39, 55);


	//second window
	glVertex3d(66, 39, 55);
	glVertex3d(66, 35, 55);
	glVertex3d(58, 35, 55);
	glVertex3d(58, 39, 55);

	glVertex3d(66, 27, 55);
	glVertex3d(66, 23, 55);
	glVertex3d(58, 23, 55);
	glVertex3d(58, 27, 55);

	glVertex3d(58, 39, 55);
	glVertex3d(58, 23, 55);
	glVertex3d(54, 23, 55);
	glVertex3d(54, 39, 55);

	//third window 
	glVertex3d(54, 39, 55);
	glVertex3d(54, 35, 55);
	glVertex3d(46, 35, 55);
	glVertex3d(46, 39, 55);

	glVertex3d(54, 27, 55);
	glVertex3d(54, 23, 55);
	glVertex3d(46, 23, 55);
	glVertex3d(46, 27, 55);

	glVertex3d(46, 39, 55);
	glVertex3d(46, 23, 55);
	glVertex3d(24, 23, 55);
	glVertex3d(24, 39, 55);

	//board wall
	glVertex3d(24, 39, 55);
	glVertex3d(24, 23, 55);
	glVertex3d(22, 23, 5);
	glVertex3d(22, 39, 5);


	//main hall
	//wall behind cl-10
	glVertex3d(258, 39, 55);
	glVertex3d(258, 23, 55);
	glVertex3d(258, 23, 105);
	glVertex3d(258, 39, 105);
	//right wall of the window
	glVertex3d(258, 39, 105);
	glVertex3d(258, 23, 105);
	glVertex3d(273, 23, 105);
	glVertex3d(273, 39, 105);
	//top wall of the window
	glVertex3d(273, 39, 105);
	glVertex3d(273, 35, 105);
	glVertex3d(293, 35, 105);
	glVertex3d(293, 39, 105);
	//lower wall of the window
	glVertex3d(273, 27, 105);
	glVertex3d(273, 23, 105);
	glVertex3d(293, 23, 105);
	glVertex3d(293, 27, 105);
	//left wall of the window
	glVertex3d(293, 39, 105);
	glVertex3d(293, 23, 105);
	glVertex3d(305, 23, 105);
	glVertex3d(305, 39, 105);
	// wall between window and cl-4
	glVertex3d(305, 39, 105);
	glVertex3d(305, 23, 105);
	glVertex3d(305, 23, 95);
	glVertex3d(305, 39, 95);
	//right wall of cl-4
	glVertex3d(305, 39, 95);
	glVertex3d(305, 23, 95);
	glVertex3d(308, 23, 95);
	glVertex3d(308, 39, 95);
	//board wall of cl-4
	glVertex3d(308, 39, 95);
	glVertex3d(308, 23, 95);
	glVertex3d(308, 23, 145);
	glVertex3d(308, 39, 145);
	//right wall of cl-4
	glVertex3d(308, 39, 145);
	glVertex3d(308, 23, 145);
	glVertex3d(364, 23, 145);
	glVertex3d(364, 39, 145);
	//back wall of cl-4
	glVertex3d(364, 39, 145);
	glVertex3d(364, 23, 145);
	glVertex3d(364, 23, 95);
	glVertex3d(364, 39, 95);
	//top wall of cl-4 door
	glVertex3d(308, 39, 95);
	glVertex3d(308, 35, 95);
	glVertex3d(316, 35, 95);
	glVertex3d(316, 39, 95);
	//right wall of cl-5
	glVertex3d(364, 39, 145);
	glVertex3d(364, 23, 145);
	glVertex3d(420, 23, 145);
	glVertex3d(420, 39, 145);
	//back wall of cl-5
	glVertex3d(420, 39, 145);
	glVertex3d(420, 23, 145);
	glVertex3d(420, 23, 95);
	glVertex3d(420, 39, 95);
	//right wall of cl-6
	glVertex3d(420, 39, 145);
	glVertex3d(420, 23, 145);
	glVertex3d(476, 23, 145);
	glVertex3d(476, 39, 145);
	//back wall of cl-5
	glVertex3d(476, 39, 145);
	glVertex3d(476, 23, 145);
	glVertex3d(476, 23, 95);
	glVertex3d(476, 39, 95);
	//wall between cl-4 and cl-5
	glVertex3d(316, 39, 95);
	glVertex3d(316, 23, 95);
	glVertex3d(374, 23, 95);
	glVertex3d(374, 39, 95);

	glVertex3d(374, 39, 95);
	glVertex3d(374, 35, 95);
	glVertex3d(382, 35, 95);
	glVertex3d(382, 39, 95);


	//wall between cl-5 and cl-6
	glVertex3d(382, 39, 95);
	glVertex3d(382, 23, 95);
	glVertex3d(440, 23, 95);
	glVertex3d(440, 39, 95);

	//door of cl-6
	glVertex3d(440, 39, 95);
	glVertex3d(440, 35, 95);
	glVertex3d(448, 35, 95);
	glVertex3d(448, 39, 95);

	//wall between cl-6 and ARWP
	glVertex3d(448, 39, 95);
	glVertex3d(448, 23, 95);
	glVertex3d(496, 23, 95);
	glVertex3d(496, 39, 95);

	glVertex3d(496, 23, 95);
	glVertex3d(496, 39, 95);
	glVertex3d(496, 39, 64);
	glVertex3d(496, 23, 64);


	// right wall of ARWP
	glVertex3d(523, 39, 64);
	glVertex3d(523, 23, 64);
	glVertex3d(480, 23, 64);
	glVertex3d(480, 39, 64);

	//ARWP door
	glVertex3d(480, 39, 64);
	glVertex3d(480, 35, 64);
	glVertex3d(472, 35, 64);
	glVertex3d(472, 39, 64);

	glVertex3d(472, 39, 64);
	glVertex3d(472, 23, 64);
	glVertex3d(305, 23, 64);
	glVertex3d(305, 39, 64);

	//ARWP
	glVertex3d(518, 39, 64);
	glVertex3d(518, 23, 64);
	glVertex3d(518, 23, 8);
	glVertex3d(518, 39, 8);

	glVertex3d(518, 39, 8);
	glVertex3d(518, 23, 8);
	glVertex3d(468, 23, 8);
	glVertex3d(468, 39, 8);

	glVertex3d(468, 39, 8);
	glVertex3d(468, 23, 8);
	glVertex3d(468, 23, 64);
	glVertex3d(468, 39, 64);

	//right wall of cl-7's corridor
	glVertex3d(305, 39, 64);
	glVertex3d(305, 23, 64);
	glVertex3d(305, 23, -40);
	glVertex3d(305, 39, -40);

	//wall between cl-7 and stairs
	glVertex3d(320, 39, -70);
	glVertex3d(320, 23, -70);
	glVertex3d(320, 23, -125);
	glVertex3d(320, 39, -125);

	// cl-7
	// wall with windows in real life not here ^_^
	glVertex3d(320, 39, -125);
	glVertex3d(320, 23, -125);
	glVertex3d(380, 23, -125);
	glVertex3d(380, 39, -125);

	//الحيط يلي بالصدر 
	glVertex3d(380, 39, -125);
	glVertex3d(380, 23, -125);
	glVertex3d(380, 23, -70);
	glVertex3d(380, 39, -70);

	// الحيط اليمين تبع الكوريرور الصغير
	glVertex3d(305, 39, -40);
	glVertex3d(305, 23, -40);
	glVertex3d(450, 23, -40);
	glVertex3d(450, 39, -40);

	// الحيط اليمين لباب غرفة المدرسين
	glVertex3d(380, 39, -40);
	glVertex3d(380, 23, -40);
	glVertex3d(380, 23, -45);
	glVertex3d(380, 39, -45);

	// باب غرفة المدرسين
	glVertex3d(380, 39, -45);
	glVertex3d(380, 35, -45);
	glVertex3d(380, 35, -53);
	glVertex3d(380, 39, -53);

	// الحيط اليمين لباب غرفة المدرسين الاولى
	glVertex3d(390, 39, -40);
	glVertex3d(390, 23, -40);
	glVertex3d(390, 23, -48);
	glVertex3d(390, 39, -48);

	// عتبة الباب
	glVertex3d(390, 39, -48);
	glVertex3d(390, 35, -48);
	glVertex3d(390, 35, -56);
	glVertex3d(390, 39, -56);


	// الحيط اليسار
	glVertex3d(390, 39, -56);
	glVertex3d(390, 23, -56);
	glVertex3d(390, 23, -90);
	glVertex3d(390, 39, -90);

	//عتبة باب غرفة المدرسين الجوانية
	glVertex3d(390, 39, -90);
	glVertex3d(390, 35, -90);
	glVertex3d(382, 35, -90);
	glVertex3d(382, 39, -90);

	glVertex3d(382, 39, -90);
	glVertex3d(382, 23, -90);
	glVertex3d(380, 23, -90);
	glVertex3d(380, 39, -90);

	//الحيط اليساري للغرفة اذا فايتين من جهة الباب
	glVertex3d(380, 39, -90);
	glVertex3d(380, 23, -90);
	glVertex3d(380, 23, -140);
	glVertex3d(380, 39, -140);

	//الحيط المقابل الباب
	glVertex3d(380, 39, -140);
	glVertex3d(380, 23, -140);
	glVertex3d(436, 23, -140);
	glVertex3d(436, 39, -140);

	// الحيط يلي بالصدر
	glVertex3d(436, 39, -140);
	glVertex3d(436, 23, -140);
	glVertex3d(436, 23, -90);
	glVertex3d(436, 39, -90);

	//الحيط الواصل بين الحيط يلي بالصدر والباب
	glVertex3d(436, 39, -90);
	glVertex3d(436, 23, -90);
	glVertex3d(390, 23, -90);
	glVertex3d(390, 39, -90);

	// الحيط الصدراني لقاعة المدرسين الاولى
	glVertex3d(436, 39, -90);
	glVertex3d(436, 23, -90);
	glVertex3d(436, 23, -40);
	glVertex3d(436, 39, -40);


	// الحيط اليسار بين القاعة السابعة وغرفة المدرسين
	glVertex3d(380, 39, -53);
	glVertex3d(380, 23, -53);
	glVertex3d(380, 23, -70);
	glVertex3d(380, 39, -70);

	//الحيط اليمين لباب السابعة
	glVertex3d(380, 23, -70);
	glVertex3d(380, 39, -70);
	glVertex3d(332, 39, -70);
	glVertex3d(332, 23, -70);

	//عتبة باب السابعة
	glVertex3d(332, 39, -70);
	glVertex3d(332, 35, -70);
	glVertex3d(320, 35, -70);
	glVertex3d(320, 39, -70);

	// الحيط اليسار لباب السابعة
	glVertex3d(324.5, 39, -70);
	glVertex3d(324.5, 23, -70);
	glVertex3d(320, 23, -70);
	glVertex3d(320, 39, -70);

	//wall behind stairs
	glVertex3d(320, 39, -125);
	glVertex3d(320, 23, -125);
	glVertex3d(285, 23, -125);
	glVertex3d(285, 39, -125);

	glVertex3d(285, 39, -125);
	glVertex3d(285, 23, -125);
	glVertex3d(285, 23, -90);
	glVertex3d(285, 39, -90);

	//windows where security sits
	glVertex3d(285, 39, -90);
	glVertex3d(285, 23, -90);
	glVertex3d(280, 23, -90);
	glVertex3d(280, 39, -90);
	//width is 15
	glVertex3d(280, 39, -90);
	glVertex3d(280, 35, -90);
	glVertex3d(260, 35, -90);
	glVertex3d(260, 39, -90);

	glVertex3d(280, 27, -90);
	glVertex3d(280, 23, -90);
	glVertex3d(255, 23, -90);
	glVertex3d(255, 27, -90);


	glVertex3d(260, 39, -90);
	glVertex3d(260, 23, -90);
	glVertex3d(255, 23, -90);
	glVertex3d(255, 39, -90);

	glVertex3d(255, 39, -90);
	glVertex3d(255, 23, -90);
	glVertex3d(255, 23, -40);
	glVertex3d(255, 39, -40);


	glEnd();
	glPopMatrix();



	glPushMatrix();
	glTranslated(-250, 31, 87);
	//glRotated(180, 0, 1, 0);
	glColor3ub(239, 211, 211);

	glBegin(GL_QUADS);

	//the wall right to cl-01 door
	glVertex3d(1, 8, 5);
	glVertex3d(24, 8, 5);
	glVertex3d(24, -8, 5);
	glVertex3d(1, -8, 5);

	//the top wall of  cl-01 door
	glVertex3d(24, 8, 5);
	glVertex3d(32, 8, 5);
	glVertex3d(32, 4, 5);
	glVertex3d(24, 4, 5);

	//the wall left to  cl-01 door and right to  cl-02 door
	glVertex3d(32, 8, 5);
	glVertex3d(90, 8, 5);
	glVertex3d(90, -8, 5);
	glVertex3d(32, -8, 5);

	//the top wall of cl-02 door
	glVertex3d(90, 8, 5);
	glVertex3d(98, 8, 5);
	glVertex3d(98, 4, 5);
	glVertex3d(90, 4, 5);

	//the wall left to cl-02 door and right to cl-03 door
	glVertex3d(98, 8, 5);
	glVertex3d(146, 8, 5);
	glVertex3d(146, -8, 5);
	glVertex3d(98, -8, 5);

	//the top wall of cl-03 door
	glVertex3d(146, 8, 5);
	glVertex3d(154, 8, 5);
	glVertex3d(154, 4, 5);
	glVertex3d(146, 4, 5);

	//the wall left to cl-03 door and right to PHL door
	glVertex3d(154, 8, 5);
	glVertex3d(202, 8, 5);
	glVertex3d(202, -8, 5);
	glVertex3d(154, -8, 5);

	//the top wall of PHL door
	glVertex3d(202, 8, 5);
	glVertex3d(210, 8, 5);
	glVertex3d(210, 4, 5);
	glVertex3d(202, 4, 5);

	//the wall left to PHL door until the end of the corridor
	glVertex3d(210, 8, 5);
	glVertex3d(258, 8, 5);
	glVertex3d(258, -8, 5);
	glVertex3d(210, -8, 5);

	//the back wall of PHL
	glVertex3d(258, 8, 5);
	glVertex3d(258, -8, 5);
	glVertex3d(258, -8, 55);
	glVertex3d(258, 8, 55);

	// PHL

	// first window in PHL
	glVertex3d(258, 8, 55);
	glVertex3d(258, -8, 55);
	glVertex3d(246, -8, 55);
	glVertex3d(246, 8, 55);

	glVertex3d(246, 8, 55);
	glVertex3d(246, 4, 55);
	glVertex3d(238, 4, 55);
	glVertex3d(238, 8, 55);

	glVertex3d(246, -4, 55);
	glVertex3d(246, -8, 55);
	glVertex3d(238, -8, 55);
	glVertex3d(238, -4, 55);

	glVertex3d(238, 8, 55);
	glVertex3d(238, -8, 55);
	glVertex3d(234, -8, 55);
	glVertex3d(234, 8, 55);
	//end

	// second window in PHL
	glVertex3d(234, 8, 55);
	glVertex3d(234, 4, 55);
	glVertex3d(226, 4, 55);
	glVertex3d(226, 8, 55);

	glVertex3d(234, -4, 55);
	glVertex3d(234, -8, 55);
	glVertex3d(226, -8, 55);
	glVertex3d(226, -4, 55);

	glVertex3d(226, 8, 55);
	glVertex3d(226, -8, 55);
	glVertex3d(222, -8, 55);
	glVertex3d(222, 8, 55);
	//end

	//third window in PHL
	glVertex3d(222, 8, 55);
	glVertex3d(222, 4, 55);
	glVertex3d(214, 4, 55);
	glVertex3d(214, 8, 55);

	glVertex3d(222, -4, 55);
	glVertex3d(222, -8, 55);
	glVertex3d(214, -8, 55);
	glVertex3d(214, -4, 55);


	glVertex3d(214, 8, 55);
	glVertex3d(214, -8, 55);
	glVertex3d(210, -8, 55);
	glVertex3d(210, 8, 55);

	//end

	// the wall between the board wall and the nearest window
	glVertex3d(210, 8, 55);
	glVertex3d(210, -8, 55);
	glVertex3d(202, -8, 55);
	glVertex3d(202, 8, 55);


	//board wall in PHL
	glVertex3d(202, 8, 55);
	glVertex3d(202, -8, 55);
	glVertex3d(200, -8, 5);
	glVertex3d(200, 8, 5);

	//END OF PHL

	//CL-03

	// first window in CL-03
	glVertex3d(202, 8, 55);
	glVertex3d(202, -8, 55);
	glVertex3d(190, -8, 55);
	glVertex3d(190, 8, 55);

	glVertex3d(190, 8, 55);
	glVertex3d(190, 4, 55);
	glVertex3d(182, 4, 55);
	glVertex3d(182, 8, 55);

	glVertex3d(190, -4, 55);
	glVertex3d(190, -8, 55);
	glVertex3d(182, -8, 55);
	glVertex3d(182, -4, 55);

	glVertex3d(182, 8, 55);
	glVertex3d(182, -8, 55);
	glVertex3d(178, -8, 55);
	glVertex3d(178, 8, 55);
	//end

	// second window in CL-03
	glVertex3d(178, 8, 55);
	glVertex3d(178, 4, 55);
	glVertex3d(170, 4, 55);
	glVertex3d(170, 8, 55);

	glVertex3d(178, -4, 55);
	glVertex3d(178, -8, 55);
	glVertex3d(170, -8, 55);
	glVertex3d(170, -4, 55);

	glVertex3d(170, 8, 55);
	glVertex3d(170, -8, 55);
	glVertex3d(166, -8, 55);
	glVertex3d(166, 8, 55);

	//third window in CL-03
	glVertex3d(166, 8, 55);
	glVertex3d(166, 4, 55);
	glVertex3d(158, 4, 55);
	glVertex3d(158, 8, 55);

	glVertex3d(166, -4, 55);
	glVertex3d(166, -8, 55);
	glVertex3d(158, -8, 55);
	glVertex3d(158, -4, 55);

	glVertex3d(158, 8, 55);
	glVertex3d(158, -8, 55);
	glVertex3d(146, -8, 55);
	glVertex3d(146, 8, 55);

	//board wall in CL-03
	glVertex3d(146, 8, 55);
	glVertex3d(146, -8, 55);
	glVertex3d(144, -8, 5);
	glVertex3d(144, 8, 5);

	//END OF CL-03

	//CL-02
	//first window
	glVertex3d(146, 8, 55);
	glVertex3d(146, -8, 55);
	glVertex3d(134, -8, 55);
	glVertex3d(134, 8, 55);

	glVertex3d(134, 8, 55);
	glVertex3d(134, 4, 55);
	glVertex3d(126, 4, 55);
	glVertex3d(126, 8, 55);

	glVertex3d(134, -4, 55);
	glVertex3d(134, -8, 55);
	glVertex3d(126, -8, 55);
	glVertex3d(126, -4, 55);

	glVertex3d(126, 8, 55);
	glVertex3d(126, -8, 55);
	glVertex3d(122, -8, 55);
	glVertex3d(122, 8, 55);

	//second window in CL-02
	glVertex3d(122, 8, 55);
	glVertex3d(122, 4, 55);
	glVertex3d(114, 4, 55);
	glVertex3d(114, 8, 55);

	glVertex3d(122, -4, 55);
	glVertex3d(122, -8, 55);
	glVertex3d(114, -8, 55);
	glVertex3d(114, -4, 55);

	glVertex3d(114, 8, 55);
	glVertex3d(114, -8, 55);
	glVertex3d(110, -8, 55);
	glVertex3d(110, 8, 55);

	//third window in CL-02
	glVertex3d(110, 8, 55);
	glVertex3d(110, 4, 55);
	glVertex3d(102, 4, 55);
	glVertex3d(102, 8, 55);

	glVertex3d(110, -4, 55);
	glVertex3d(110, -8, 55);
	glVertex3d(102, -8, 55);
	glVertex3d(102, -4, 55);

	glVertex3d(102, 8, 55);
	glVertex3d(102, -8, 55);
	glVertex3d(90, -8, 55);
	glVertex3d(90, 8, 55);

	//board wall in CL-02
	glVertex3d(90, 8, 55);
	glVertex3d(90, -8, 55);
	glVertex3d(88, -8, 5);
	glVertex3d(88, 8, 5);

	//CL-01
	//first window
	glVertex3d(90, 8, 55);
	glVertex3d(90, -8, 55);
	glVertex3d(78, -8, 55);
	glVertex3d(78, 8, 55);

	glVertex3d(78, 8, 55);
	glVertex3d(78, 4, 55);
	glVertex3d(70, 4, 55);
	glVertex3d(70, 8, 55);

	glVertex3d(78, -4, 55);
	glVertex3d(78, -8, 55);
	glVertex3d(70, -8, 55);
	glVertex3d(70, -4, 55);

	glVertex3d(70, 8, 55);
	glVertex3d(70, -8, 55);
	glVertex3d(66, -8, 55);
	glVertex3d(66, 8, 55);


	//second window
	glVertex3d(66, 8, 55);
	glVertex3d(66, 4, 55);
	glVertex3d(58, 4, 55);
	glVertex3d(58, 8, 55);

	glVertex3d(66, -4, 55);
	glVertex3d(66, -8, 55);
	glVertex3d(58, -8, 55);
	glVertex3d(58, -4, 55);

	glVertex3d(58, 8, 55);
	glVertex3d(58, -8, 55);
	glVertex3d(54, -8, 55);
	glVertex3d(54, 8, 55);

	//third window 
	glVertex3d(54, 8, 55);
	glVertex3d(54, 4, 55);
	glVertex3d(46, 4, 55);
	glVertex3d(46, 8, 55);

	glVertex3d(54, -4, 55);
	glVertex3d(54, -8, 55);
	glVertex3d(46, -8, 55);
	glVertex3d(46, -4, 55);

	glVertex3d(46, 8, 55);
	glVertex3d(46, -8, 55);
	glVertex3d(24, -8, 55);
	glVertex3d(24, 8, 55);

	//board wall
	glVertex3d(24, 8, 55);
	glVertex3d(24, -8, 55);
	glVertex3d(22, -8, 5);
	glVertex3d(22, 8, 5);

	// end of CL-01

	// wall between CL-01 and offices
	glVertex3d(1, 8, 5);
	glVertex3d(1, -8.1, 5);
	glVertex3d(0, -8.1, -178);
	glVertex3d(0, 8, -178);


	glEnd();
	glPopMatrix();
	////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////

	glPushMatrix();
	glTranslated(15, 31, -85);
	glRotated(180, 0, 1, 0);
	glColor3ub(239, 211, 211);

	glBegin(GL_QUADS);

	//the wall right to Fayez office door
	glVertex3d(8, 8, 5);
	glVertex3d(24, 8, 5);
	glVertex3d(24, -8, 5);
	glVertex3d(8, -8, 5);

	//the top wall of  Fayez office door
	glVertex3d(24, 8, 5);
	glVertex3d(32, 8, 5);
	glVertex3d(32, 4, 5);
	glVertex3d(24, 4, 5);

	//the wall left to  Fayez office door and right to BANA office
	glVertex3d(32, 8, 5);
	glVertex3d(90, 8, 5);
	glVertex3d(90, -8, 5);
	glVertex3d(32, -8, 5);

	//the top wall of BANA office
	glVertex3d(90, 8, 5);
	glVertex3d(98, 8, 5);
	glVertex3d(98, 4, 5);
	glVertex3d(90, 4, 5);

	//the wall left to BANA office and right to مكتب الدكاترة الاول
	glVertex3d(98, 8, 5);
	glVertex3d(146, 8, 5);
	glVertex3d(146, -8, 5);
	glVertex3d(98, -8, 5);

	//the top wall of مكتب الدكاترة الاول door
	glVertex3d(146, 8, 5);
	glVertex3d(154, 8, 5);
	glVertex3d(154, 4, 5);
	glVertex3d(146, 4, 5);

	//the wall left to مكتب الدكاترة الاول door and right to مكتب الدكاترة التاني door
	glVertex3d(154, 8, 5);
	glVertex3d(202, 8, 5);
	glVertex3d(202, -8, 5);
	glVertex3d(154, -8, 5);

	//the top wall of مكتب الدكاترة التاني door
	glVertex3d(202, 8, 5);
	glVertex3d(210, 8, 5);
	glVertex3d(210, 4, 5);
	glVertex3d(202, 4, 5);

	//the wall left to مكتب الدكاترة التاني door until the end of the corridor
	glVertex3d(210, 8, 5);
	glVertex3d(265, 8, 5);
	glVertex3d(265, -8, 5);
	glVertex3d(210, -8, 5);

	//the back wall of مكتب الدكاترة التاني
	glVertex3d(258, 8, 5);
	glVertex3d(258, -8, 5);
	glVertex3d(258, -8, 55);
	glVertex3d(258, 8, 55);


	// مكتب الدكاترة التاني

	// first window in مكتب الدكاترة التاني
	glVertex3d(258, 8, 55);
	glVertex3d(258, -8, 55);
	glVertex3d(246, -8, 55);
	glVertex3d(246, 8, 55);

	glVertex3d(246, 8, 55);
	glVertex3d(246, 4, 55);
	glVertex3d(238, 4, 55);
	glVertex3d(238, 8, 55);

	glVertex3d(246, -4, 55);
	glVertex3d(246, -8, 55);
	glVertex3d(238, -8, 55);
	glVertex3d(238, -4, 55);

	glVertex3d(238, 8, 55);
	glVertex3d(238, -8, 55);
	glVertex3d(234, -8, 55);
	glVertex3d(234, 8, 55);
	//end

	// second window in مكتب الدكاترة التاني
	glVertex3d(234, 8, 55);
	glVertex3d(234, 4, 55);
	glVertex3d(226, 4, 55);
	glVertex3d(226, 8, 55);

	glVertex3d(234, -4, 55);
	glVertex3d(234, -8, 55);
	glVertex3d(226, -8, 55);
	glVertex3d(226, -4, 55);

	glVertex3d(226, 8, 55);
	glVertex3d(226, -8, 55);
	glVertex3d(222, -8, 55);
	glVertex3d(222, 8, 55);
	//end

	//third window in مكتب الدكاترة التاني
	glVertex3d(222, 8, 55);
	glVertex3d(222, 4, 55);
	glVertex3d(214, 4, 55);
	glVertex3d(214, 8, 55);

	glVertex3d(222, -4, 55);
	glVertex3d(222, -8, 55);
	glVertex3d(214, -8, 55);
	glVertex3d(214, -4, 55);


	glVertex3d(214, 8, 55);
	glVertex3d(214, -8, 55);
	glVertex3d(210, -8, 55);
	glVertex3d(210, 8, 55);

	//end

	// the wall between the board wall and the nearest window
	glVertex3d(210, 8, 55);
	glVertex3d(210, -8, 55);
	glVertex3d(202, -8, 55);
	glVertex3d(202, 8, 55);


	//board wall in مكتب الدكاترة التاني
	glVertex3d(202, 8, 55);
	glVertex3d(202, -8, 55);
	glVertex3d(200, -8, 5);
	glVertex3d(200, 8, 5);
	//we connect between 202 and 200 rather than 202 to leave 2cm between the board wall and the right wall of the door

	//END OF مكتب الدكاترة التاني

	//مكتب الدكاترة الاول 

	// first window in مكتب الدكاترة الاول
	glVertex3d(202, 8, 55);
	glVertex3d(202, -8, 55);
	glVertex3d(190, -8, 55);
	glVertex3d(190, 8, 55);

	glVertex3d(190, 8, 55);
	glVertex3d(190, 4, 55);
	glVertex3d(182, 4, 55);
	glVertex3d(182, 8, 55);

	glVertex3d(190, -4, 55);
	glVertex3d(190, -8, 55);
	glVertex3d(182, -8, 55);
	glVertex3d(182, -4, 55);

	glVertex3d(182, 8, 55);
	glVertex3d(182, -8, 55);
	glVertex3d(178, -8, 55);
	glVertex3d(178, 8, 55);
	//end

	// second window in مكتب الدكاترة الاول
	glVertex3d(178, 8, 55);
	glVertex3d(178, 4, 55);
	glVertex3d(170, 4, 55);
	glVertex3d(170, 8, 55);

	glVertex3d(178, -4, 55);
	glVertex3d(178, -8, 55);
	glVertex3d(170, -8, 55);
	glVertex3d(170, -4, 55);

	glVertex3d(170, 8, 55);
	glVertex3d(170, -8, 55);
	glVertex3d(166, -8, 55);
	glVertex3d(166, 8, 55);

	//third window in مكتب الدكاترة الاول
	glVertex3d(166, 8, 55);
	glVertex3d(166, 4, 55);
	glVertex3d(158, 4, 55);
	glVertex3d(158, 8, 55);

	glVertex3d(166, -4, 55);
	glVertex3d(166, -8, 55);
	glVertex3d(158, -8, 55);
	glVertex3d(158, -4, 55);

	glVertex3d(158, 8, 55);
	glVertex3d(158, -8, 55);
	glVertex3d(146, -8, 55);
	glVertex3d(146, 8, 55);

	//board wall in مكتب الدكاترة الاول
	glVertex3d(146, 8, 55);
	glVertex3d(146, -8, 55);
	glVertex3d(144, -8, 5);
	glVertex3d(144, 8, 5);

	//END OF مكتب الدكاترة الاول

	//BANA office
	//first window
	glVertex3d(146, 8, 55);
	glVertex3d(146, -8, 55);
	glVertex3d(134, -8, 55);
	glVertex3d(134, 8, 55);

	glVertex3d(134, 8, 55);
	glVertex3d(134, 4, 55);
	glVertex3d(126, 4, 55);
	glVertex3d(126, 8, 55);

	glVertex3d(134, -4, 55);
	glVertex3d(134, -8, 55);
	glVertex3d(126, -8, 55);
	glVertex3d(126, -4, 55);

	glVertex3d(126, 8, 55);
	glVertex3d(126, -8, 55);
	glVertex3d(122, -8, 55);
	glVertex3d(122, 8, 55);

	//second window in BANA office
	glVertex3d(122, 8, 55);
	glVertex3d(122, 4, 55);
	glVertex3d(114, 4, 55);
	glVertex3d(114, 8, 55);

	glVertex3d(122, -4, 55);
	glVertex3d(122, -8, 55);
	glVertex3d(114, -8, 55);
	glVertex3d(114, -4, 55);

	glVertex3d(114, 8, 55);
	glVertex3d(114, -8, 55);
	glVertex3d(110, -8, 55);
	glVertex3d(110, 8, 55);

	//third window in BANA office
	glVertex3d(110, 8, 55);
	glVertex3d(110, 4, 55);
	glVertex3d(102, 4, 55);
	glVertex3d(102, 8, 55);

	glVertex3d(110, -4, 55);
	glVertex3d(110, -8, 55);
	glVertex3d(102, -8, 55);
	glVertex3d(102, -4, 55);

	glVertex3d(102, 8, 55);
	glVertex3d(102, -8, 55);
	glVertex3d(90, -8, 55);
	glVertex3d(90, 8, 55);

	//board wall in BANA office
	glVertex3d(90, 8, 55);
	glVertex3d(90, -8, 55);
	glVertex3d(88, -8, 5);
	glVertex3d(88, 8, 5);

	//Fayez office
	//first window
	glVertex3d(90, 8, 55);
	glVertex3d(90, -8, 55);
	glVertex3d(78, -8, 55);
	glVertex3d(78, 8, 55);

	glVertex3d(78, 8, 55);
	glVertex3d(78, 4, 55);
	glVertex3d(70, 4, 55);
	glVertex3d(70, 8, 55);

	glVertex3d(78, -4, 55);
	glVertex3d(78, -8, 55);
	glVertex3d(70, -8, 55);
	glVertex3d(70, -4, 55);

	glVertex3d(70, 8, 55);
	glVertex3d(70, -8, 55);
	glVertex3d(66, -8, 55);
	glVertex3d(66, 8, 55);


	//second window
	glVertex3d(66, 8, 55);
	glVertex3d(66, 4, 55);
	glVertex3d(58, 4, 55);
	glVertex3d(58, 8, 55);

	glVertex3d(66, -4, 55);
	glVertex3d(66, -8, 55);
	glVertex3d(58, -8, 55);
	glVertex3d(58, -4, 55);

	glVertex3d(58, 8, 55);
	glVertex3d(58, -8, 55);
	glVertex3d(54, -8, 55);
	glVertex3d(54, 8, 55);

	//third window 
	glVertex3d(54, 8, 55);
	glVertex3d(54, 4, 55);
	glVertex3d(46, 4, 55);
	glVertex3d(46, 8, 55);

	glVertex3d(54, -4, 55);
	glVertex3d(54, -8, 55);
	glVertex3d(46, -8, 55);
	glVertex3d(46, -4, 55);

	glVertex3d(46, 8, 55);
	glVertex3d(46, -8, 55);
	glVertex3d(24, -8, 55);
	glVertex3d(24, 8, 55);

	//board wall
	glVertex3d(24, 8, 55);
	glVertex3d(24, -8, 55);
	glVertex3d(22, -8, 5);
	glVertex3d(22, 8, 5);

	// end of Fayez office

	glEnd();
	glPopMatrix();

	////////////////////////////////////////////////////////////////////////////////////////////////
	// 






	//////////////////// END OF SECOND FLOOR /////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////







	glPushMatrix();
	glTranslated(263, 0, -35);
	glRotated(180, 0, 1, 0);
	glBegin(GL_QUADS);
	//the wall right to ice-05 door
	glVertex3d(8, 39, 5);
	glVertex3d(24, 39, 5);
	glVertex3d(24, 23, 5);
	glVertex3d(8, 23, 5);

	//the top wall of ice-05 door
	glVertex3d(24, 39, 5);
	glVertex3d(32, 39, 5);
	glVertex3d(32, 35, 5);
	glVertex3d(24, 35, 5);



	//the wall left to ice-05 door and right to ice-07 door
	glVertex3d(32, 39, 5);
	glVertex3d(90, 39, 5);
	glVertex3d(90, 23, 5);
	glVertex3d(32, 23, 5);

	//the top wall of ice-07 door
	glVertex3d(90, 39, 5);
	glVertex3d(98, 39, 5);
	glVertex3d(98, 35, 5);
	glVertex3d(90, 35, 5);

	//the wall left to ice-07 door and right to ice-09 door
	glVertex3d(98, 39, 5);
	glVertex3d(146, 39, 5);
	glVertex3d(146, 23, 5);
	glVertex3d(98, 23, 5);

	//the top wall of ice-09 door
	glVertex3d(146, 39, 5);
	glVertex3d(154, 39, 5);
	glVertex3d(154, 35, 5);
	glVertex3d(146, 35, 5);

	//the wall left to ice-09 door and right to ice-11 door
	glVertex3d(154, 39, 5);
	glVertex3d(202, 39, 5);
	glVertex3d(202, 23, 5);
	glVertex3d(154, 23, 5);

	//the top wall of ice-11 door
	glVertex3d(202, 39, 5);
	glVertex3d(210, 39, 5);
	glVertex3d(210, 35, 5);
	glVertex3d(202, 35, 5);

	//the wall left to ice-11 door until the end of the corridor
	glVertex3d(210, 39, 5);
	glVertex3d(258, 39, 5);
	glVertex3d(258, 23, 5);
	glVertex3d(210, 23, 5);

	//the back wall of ice-11
	glVertex3d(258, 39, 5);
	glVertex3d(258, 23, 5);
	glVertex3d(258, 23, 55);
	glVertex3d(258, 39, 55);




	/*

	1------4-------6------12
	-      -       -      -
	-      5-------7      -
	-      -       -      -
	-      -       -      -
	-      -       -      -
	-      8-------10     -
	-      -       -      -
	2------3-------9------11


	 We draw each window using this method:

	 draw from 1-->2-->3-->4 (the wall left to the window)
	 then  4-->5-->7-->6     (the wall top to the window)
	 then  8-->3-->9-->10     (the wall under the window)
	 then  6-->9-->11-->12    (the wall right to the window)

	from 1-->4  12cm
	from 4-->6  8cm
	from 6-->12  4cm if there is a window next to it  (OR)  12 cm if it is the last window
	because it will continue to the board wall



	*/


	// ICE-11

	// first window in ice-11
	glVertex3d(258, 39, 55);
	glVertex3d(258, 23, 55);
	glVertex3d(246, 23, 55);
	glVertex3d(246, 39, 55);

	glVertex3d(246, 39, 55);
	glVertex3d(246, 35, 55);
	glVertex3d(238, 35, 55);
	glVertex3d(238, 39, 55);

	glVertex3d(246, 27, 55);
	glVertex3d(246, 23, 55);
	glVertex3d(238, 23, 55);
	glVertex3d(238, 27, 55);

	glVertex3d(238, 39, 55);
	glVertex3d(238, 23, 55);
	glVertex3d(234, 23, 55);
	glVertex3d(234, 39, 55);
	//end

	// second window in ice-11
	glVertex3d(234, 39, 55);
	glVertex3d(234, 35, 55);
	glVertex3d(226, 35, 55);
	glVertex3d(226, 39, 55);

	glVertex3d(234, 27, 55);
	glVertex3d(234, 23, 55);
	glVertex3d(226, 23, 55);
	glVertex3d(226, 27, 55);

	glVertex3d(226, 39, 55);
	glVertex3d(226, 23, 55);
	glVertex3d(222, 23, 55);
	glVertex3d(222, 39, 55);
	//end

	//third window in ice-11
	glVertex3d(222, 39, 55);
	glVertex3d(222, 35, 55);
	glVertex3d(214, 35, 55);
	glVertex3d(214, 39, 55);

	glVertex3d(222, 27, 55);
	glVertex3d(222, 23, 55);
	glVertex3d(214, 23, 55);
	glVertex3d(214, 27, 55);


	glVertex3d(214, 39, 55);
	glVertex3d(214, 23, 55);
	glVertex3d(210, 23, 55);
	glVertex3d(210, 39, 55);

	//end

	// the wall between the board wall and the nearest window
	glVertex3d(210, 39, 55);
	glVertex3d(210, 23, 55);
	glVertex3d(202, 23, 55);
	glVertex3d(202, 39, 55);


	//board wall in ice-11
	glVertex3d(202, 39, 55);
	glVertex3d(202, 23, 55);
	glVertex3d(200, 23, 5);
	glVertex3d(200, 39, 5);
	//we connect between 202 and 200 rather than 202 to leave 2cm between the board wall and the right wall of the door

	//END OF ICE-11

	//ICE-09

	// first window in ice-09
	glVertex3d(202, 39, 55);
	glVertex3d(202, 23, 55);
	glVertex3d(190, 23, 55);
	glVertex3d(190, 39, 55);

	glVertex3d(190, 39, 55);
	glVertex3d(190, 35, 55);
	glVertex3d(182, 35, 55);
	glVertex3d(182, 39, 55);

	glVertex3d(190, 27, 55);
	glVertex3d(190, 23, 55);
	glVertex3d(182, 23, 55);
	glVertex3d(182, 27, 55);

	glVertex3d(182, 39, 55);
	glVertex3d(182, 23, 55);
	glVertex3d(178, 23, 55);
	glVertex3d(178, 39, 55);
	//end

	// second window in ice-09
	glVertex3d(178, 39, 55);
	glVertex3d(178, 35, 55);
	glVertex3d(170, 35, 55);
	glVertex3d(170, 39, 55);

	glVertex3d(178, 27, 55);
	glVertex3d(178, 23, 55);
	glVertex3d(170, 23, 55);
	glVertex3d(170, 27, 55);

	glVertex3d(170, 39, 55);
	glVertex3d(170, 23, 55);
	glVertex3d(166, 23, 55);
	glVertex3d(166, 39, 55);

	//third window in ice-09
	glVertex3d(166, 39, 55);
	glVertex3d(166, 35, 55);
	glVertex3d(158, 35, 55);
	glVertex3d(158, 39, 55);

	glVertex3d(166, 27, 55);
	glVertex3d(166, 23, 55);
	glVertex3d(158, 23, 55);
	glVertex3d(158, 27, 55);

	glVertex3d(158, 39, 55);
	glVertex3d(158, 23, 55);
	glVertex3d(146, 23, 55);
	glVertex3d(146, 39, 55);

	//board wall in ice-09
	glVertex3d(146, 39, 55);
	glVertex3d(146, 23, 55);
	glVertex3d(144, 23, 5);
	glVertex3d(144, 39, 5);

	//END OF ICE-09

	//ICE-07
	//first window
	glVertex3d(146, 39, 55);
	glVertex3d(146, 23, 55);
	glVertex3d(134, 23, 55);
	glVertex3d(134, 39, 55);

	glVertex3d(134, 39, 55);
	glVertex3d(134, 35, 55);
	glVertex3d(126, 35, 55);
	glVertex3d(126, 39, 55);

	glVertex3d(134, 27, 55);
	glVertex3d(134, 23, 55);
	glVertex3d(126, 23, 55);
	glVertex3d(126, 27, 55);

	glVertex3d(126, 39, 55);
	glVertex3d(126, 23, 55);
	glVertex3d(122, 23, 55);
	glVertex3d(122, 39, 55);

	//second window in ice-07
	glVertex3d(122, 39, 55);
	glVertex3d(122, 35, 55);
	glVertex3d(114, 35, 55);
	glVertex3d(114, 39, 55);

	glVertex3d(122, 27, 55);
	glVertex3d(122, 23, 55);
	glVertex3d(114, 23, 55);
	glVertex3d(114, 27, 55);

	glVertex3d(114, 39, 55);
	glVertex3d(114, 23, 55);
	glVertex3d(110, 23, 55);
	glVertex3d(110, 39, 55);

	//third window in ice-07
	glVertex3d(110, 39, 55);
	glVertex3d(110, 35, 55);
	glVertex3d(102, 35, 55);
	glVertex3d(102, 39, 55);

	glVertex3d(110, 27, 55);
	glVertex3d(110, 23, 55);
	glVertex3d(102, 23, 55);
	glVertex3d(102, 27, 55);

	glVertex3d(102, 39, 55);
	glVertex3d(102, 23, 55);
	glVertex3d(90, 23, 55);
	glVertex3d(90, 39, 55);

	//board wall in ice-07
	glVertex3d(90, 39, 55);
	glVertex3d(90, 23, 55);
	glVertex3d(88, 23, 5);
	glVertex3d(88, 39, 5);

	//ICE-05
	//first window
	glVertex3d(90, 39, 55);
	glVertex3d(90, 23, 55);
	glVertex3d(78, 23, 55);
	glVertex3d(78, 39, 55);

	glVertex3d(78, 39, 55);
	glVertex3d(78, 35, 55);
	glVertex3d(70, 35, 55);
	glVertex3d(70, 39, 55);

	glVertex3d(78, 27, 55);
	glVertex3d(78, 23, 55);
	glVertex3d(70, 23, 55);
	glVertex3d(70, 27, 55);

	glVertex3d(70, 39, 55);
	glVertex3d(70, 23, 55);
	glVertex3d(66, 23, 55);
	glVertex3d(66, 39, 55);


	//second window
	glVertex3d(66, 39, 55);
	glVertex3d(66, 35, 55);
	glVertex3d(58, 35, 55);
	glVertex3d(58, 39, 55);

	glVertex3d(66, 27, 55);
	glVertex3d(66, 23, 55);
	glVertex3d(58, 23, 55);
	glVertex3d(58, 27, 55);

	glVertex3d(58, 39, 55);
	glVertex3d(58, 23, 55);
	glVertex3d(54, 23, 55);
	glVertex3d(54, 39, 55);

	//third window 
	glVertex3d(54, 39, 55);
	glVertex3d(54, 35, 55);
	glVertex3d(46, 35, 55);
	glVertex3d(46, 39, 55);

	glVertex3d(54, 27, 55);
	glVertex3d(54, 23, 55);
	glVertex3d(46, 23, 55);
	glVertex3d(46, 27, 55);

	glVertex3d(46, 39, 55);
	glVertex3d(46, 23, 55);
	glVertex3d(24, 23, 55);
	glVertex3d(24, 39, 55);

	//board wall
	glVertex3d(24, 39, 55);
	glVertex3d(24, 23, 55);
	glVertex3d(22, 23, 5);
	glVertex3d(22, 39, 5);


	glEnd();
	glPopMatrix();



	///////////////////////////////////////////////////////////////////////////////

	//ground
	glPushMatrix();
	glColor3ub(122, 117, 117);
	glTranslated(0, -8, 0);
	glScaled(150, 0.1, 50);
	glutSolidCube(12);
	glPopMatrix();





	//glNewList(18, GL_COMPILE);
	//glPushMatrix();//the rest of the dr.chair //desk
	//glColor3ub(50, 50, 50);
	//glRotatef(90, 1, 0, 0);
	//glScalef(1, 1, 0.5);
	//glutSolidTorus(7, 7, 100, 100);
	//glPopMatrix();


	/////////////////////////////////////
	///////hands
	//glPushMatrix();
	//glColor3ub(0, 0, 0);
	//glTranslatef(1, 10, -12);
	//glRotatef(90, 1, 0, 0);
	//gluCylinder(a, 1, 0.8, 8, 10, 10);
	//glPopMatrix();


	//glPushMatrix();
	//glColor3ub(0, 0, 0);
	//glTranslatef(-7, 10, -12);
	//glRotatef(90, 1, 0, 0);
	//gluCylinder(a, 1, 0.8, 8, 10, 10);
	//glPopMatrix();


	//glPushMatrix();
	//glColor3ub(0, 0, 0);
	//glTranslatef(-7.7, 10, -12);
	//glRotatef(90, 0, 1, 0);
	//gluCylinder(a, 1, 1, 9.5, 10, 10);
	//glPopMatrix();

	/////////////////////



	//glPushMatrix();
	//glColor3ub(0, 0, 0);
	//glTranslatef(1, 10, 10.8);
	//glRotatef(90, 1, 0, 0);
	//gluCylinder(a, 1, 0.8, 8, 10, 10);
	//glPopMatrix();


	//glPushMatrix();
	//glColor3ub(0, 0, 0);
	//glTranslatef(-7, 10, 10.8);
	//glRotatef(90, 1, 0, 0);
	//gluCylinder(a, 1, 0.8, 8, 10, 10);
	//glPopMatrix();


	//glPushMatrix();
	//glColor3ub(0, 0, 0);
	//glTranslatef(-7.7, 10, 10.8);
	//glRotatef(90, 0, 1, 0);
	//gluCylinder(a, 1, 1, 9.5, 10, 10);
	//glPopMatrix();
	////////////////////////////
	//////bases
	//glPushMatrix();
	//glColor3ub(0, 0, 0);
	//glRotatef(90, 1, 0, 0);
	//gluCylinder(a, 2.5, 2.5, 10, 10, 10);
	//glRotatef(-90, 1, 0, 0);
	//glTranslatef(0, -13, 0);
	//glCallList(17);
	//glPopMatrix();

	//glPushMatrix();
	//glTranslatef(10, 15, 0);
	//glRotatef(90, 1, 0, 0);
	//glScalef(0.5, 1, 1);
	//gluCylinder(a, 2, 2, 12, 10, 10);
	//glPopMatrix();
	///////////back
	//glPushMatrix();
	//GLUquadricObj* w1 = gluNewQuadric();

	//glColor3ub(50, 50, 50);
	//glTranslatef(6, 20, 0);
	//glRotatef(90, 0, 1, 0);
	//glScalef(1, 1, 0.5);
	//glutSolidTorus(6.4, 6.4, 100, 100);
	//glPopMatrix();
	//glEndList();

	//2nd ceil behind ice-4 stairs

	glPushMatrix();
	glTranslated(178, 15.5, 0);
	glScaled(18, 1.2, 50);
	glColor3ub(122, 117, 117);
	glutSolidCube(12);
	glPopMatrix();

	//ceil in front of stairs
	glPushMatrix();
	glTranslated(-115, 15.5, 0);
	glScaled(23, 1.2, 50);
	glColor3ub(122, 117, 117);
	glutSolidCube(12);
	glPopMatrix();

	//ceil top of ice-17
	glPushMatrix();
	glTranslated(47, 15.5, -120);
	glScaled(3.8, 1.2, 30);
	glColor3ub(122, 117, 117);
	glutSolidCube(12);
	glPopMatrix();

	//ceil top of ice-4
	glPushMatrix();
	glTranslated(47, 15.5, 180);
	glScaled(3.8, 1.2, 15);
	glColor3ub(122, 117, 117);
	glutSolidCube(12);
	glPopMatrix();

	// godfather ceil
	glPushMatrix();
	glTranslated(400, 15.5, 0);
	glScaled(13, 1.2, 50);
	glColor3ub(122, 117, 117);
	glutSolidCube(12);
	glPopMatrix();

	//ceil infont of stairs
	glPushMatrix();
	glTranslated(304, 15.5, 110);
	glScaled(3, 1.2, 34);
	glColor3ub(122, 117, 117);
	glutSolidCube(12);
	glPopMatrix();

	// stairs before stairs
	glPushMatrix();
	glTranslated(304, 5, -190);
	glScaled(3, 2.8, 8);
	glColor3ub(122, 117, 117);
	glutSolidCube(12);
	glPopMatrix();

	//// ceil top of mosque
	glPushMatrix();
	glTranslated(600, 15.5, 0);
	glScaled(20, 1.2, 50);
	glColor3ub(122, 117, 117);
	glutSolidCube(12);
	glPopMatrix();

	//3rd floor
	glPushMatrix();
	glColor3ub(122, 117, 117);
	glTranslated(0, 39, 0);
	glScaled(150, 0.1, 50);
	glutSolidCube(12);
	glPopMatrix();



	//////////////////////////////////////////


	//// cooler neaar closets ////////

	glPushMatrix();
	glScaled(0.8, 0.7, 0.8);
	glTranslated(277, -2, 65);

	glPushMatrix();
	glColor3ub(222, 184, 135);
	glTranslated(100, -5.3, 0);
	glScaled(1, 2.5, 1);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(176, 194, 222);
	glRotated(-90, 1, 0, 0);
	glTranslated(100, 0, -2);
	//glScaled(4, 1, 1);
	gluCylinder(a, 1.5, 1.5, 4.2, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(112, 128, 144);
	glTranslated(99, -3.3, 0);
	glScaled(1.4, 0.3, 1);
	glutSolidSphere(1.4, 20, 20);
	glPopMatrix();


	glPushMatrix();
	glColor3ub(112, 128, 144);
	glTranslated(99, -4.5, 0);
	glScaled(1.2, 0.3, 1);
	glutSolidSphere(1.4, 20, 20);
	glPopMatrix();


	glPushMatrix();
	glColor3ub(70, 130, 180);
	glTranslated(100, 2.2, 0);
	glScaled(1, 0.1, 1);
	glutSolidSphere(2, 20, 20);
	glPopMatrix();

	glPopMatrix();

	///////// end cooler neaar ice-13 /////////


		///////// mshareb next to ice-4


	glPushMatrix();

	glTranslated(6, 0, 20);
	glScaled(3, 3, 3);
	glRotated(90, 0, 1, 0);


	glPushMatrix();
	glColor3ub(192, 192, 192);
	glTranslated(0, -2, 0);
	glRotated(90, 0, 1, 0);
	glScaled(0.2, 0.5, 1.5);
	glutSolidCube(4);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(128, 128, 128);
	glTranslated(0, -1.74, 0.4);
	glRotated(90, 0, 1, 0);
	glScaled(0.01, 0.63, 1.5);
	glutSolidCube(4);
	glPopMatrix();


	glPushMatrix();
	glColor3ub(169, 169, 169);
	glTranslated(0, -1, -0.04);
	glRotated(90, 0, 1, 0);
	glScaled(0.2, 0.02, 1.5);
	glutSolidCube(4.22);
	glPopMatrix();



	glPushMatrix();
	glColor3ub(128, 128, 128);
	glTranslated(-2, -0.93, -0.04);
	glRotated(90, 1, 0, 0);
	glutSolidTorus(0.03, 0.23, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(128, 128, 128);
	glTranslated(0, -0.93, -0.04);
	glRotated(90, 1, 0, 0);
	glutSolidTorus(0.03, 0.23, 20, 20);
	glPopMatrix();


	glPushMatrix();
	glColor3ub(128, 128, 128);
	glTranslated(2, -0.93, -0.04);
	glRotated(90, 1, 0, 0);
	glutSolidTorus(0.03, 0.23, 20, 20);
	glPopMatrix();




	glPopMatrix();

	//////////// end//////////////////////

	////////// mshareb next to ice-15


	glPushMatrix();

	glTranslated(465, 0, 93);
	glScaled(3, 3, 3);




	glPushMatrix();
	glColor3ub(192, 192, 192);
	glTranslated(0, -2, 0);
	glRotated(90, 0, 1, 0);
	glScaled(0.2, 0.5, 1.5);
	glutSolidCube(4);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(128, 128, 128);
	glTranslated(0, -1.74, 0.4);
	glRotated(90, 0, 1, 0);
	glScaled(0.01, 0.63, 1.5);
	glutSolidCube(4);
	glPopMatrix();


	glPushMatrix();
	glColor3ub(169, 169, 169);
	glTranslated(0, -1, -0.04);
	glRotated(90, 0, 1, 0);
	glScaled(0.2, 0.02, 1.5);
	glutSolidCube(4.22);
	glPopMatrix();



	glPushMatrix();
	glColor3ub(128, 128, 128);
	glTranslated(-2, -0.93, -0.04);
	glRotated(90, 1, 0, 0);
	glutSolidTorus(0.03, 0.23, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(128, 128, 128);
	glTranslated(0, -0.93, -0.04);
	glRotated(90, 1, 0, 0);
	glutSolidTorus(0.03, 0.23, 20, 20);
	glPopMatrix();


	glPushMatrix();
	glColor3ub(128, 128, 128);
	glTranslated(2, -0.93, -0.04);
	glRotated(90, 1, 0, 0);
	glutSolidTorus(0.03, 0.23, 20, 20);
	glPopMatrix();




	glPopMatrix();


	/////////// trash can near closets

	glPushMatrix();
	glTranslated(303, -2, 56);


	glPushMatrix();
	glColor3ub(192, 192, 192);
	glTranslated(0, -2, 0);
	glRotated(90, 1, 0, 0);
	GLUquadricObj* a = gluNewQuadric();
	gluCylinder(a, 1.5, 1.09, 3.5, 100, 100);
	glPopMatrix();


	glPushMatrix();
	glColor3ub(255, 0, 0);
	glTranslated(0, -2, 0);
	glRotated(90, 1, 0, 0);
	glutSolidTorus(0.09, 1.5, 20, 20);
	glPopMatrix();

	glPopMatrix();

	///////// end ///////////////


	////////// trash can in corridor 

	glPushMatrix();

	glTranslated(50, -2, 3);


	glPushMatrix();
	glColor3ub(192, 192, 192);
	glTranslated(0, -2, 0);
	glRotated(90, 1, 0, 0);
	GLUquadricObj* aa = gluNewQuadric();
	gluCylinder(aa, 1.5, 1.09, 3.5, 100, 100);
	glPopMatrix();


	glPushMatrix();
	glColor3ub(255, 0, 0);
	glTranslated(0, -2, 0);
	glRotated(90, 1, 0, 0);
	glutSolidTorus(0.09, 1.5, 20, 20);
	glPopMatrix();

	glPopMatrix();

	/// second one
	glPushMatrix();

	glTranslated(180, -2, -37);


	glPushMatrix();
	glColor3ub(192, 192, 192);
	glTranslated(0, -2, 0);
	glRotated(90, 1, 0, 0);
	GLUquadricObj* aaa = gluNewQuadric();
	gluCylinder(aaa, 1.5, 1.09, 3.5, 100, 100);
	glPopMatrix();


	glPushMatrix();
	glColor3ub(255, 0, 0);
	glTranslated(0, -2, 0);
	glRotated(90, 1, 0, 0);
	glutSolidTorus(0.09, 1.5, 20, 20);
	glPopMatrix();

	glPopMatrix();


	////first chair in the hallway near ice-13

	glPushMatrix();

	glTranslated(-35, -4, 45);
	//stand

	glPushMatrix();
	glColor3ub(0, 0, 255);
	glTranslated(303, -2, 50);
	glRotated(90, 0, 1, 0);
	glScaled(0.3, 0.05, 1);
	glutSolidCube(8);
	glPopMatrix();


	//legs

//corners
	//top right
	glColor3ub(0, 0, 0);
	glPushMatrix();

	glTranslated(306.9, -3, 51.2);
	glRotated(90, 0, 1, 0);
	glScaled(0.07, 1, 0.07);
	glutSolidCube(1.6);
	glPopMatrix();

	glPushMatrix();
	glTranslated(304.3, -3, 51.2);
	glRotated(90, 0, 1, 0);
	glScaled(0.07, 1, 0.07);
	glutSolidCube(1.6);
	glPopMatrix();

	glPushMatrix();
	glTranslated(301.7, -3, 51.2);
	glRotated(90, 0, 1, 0);
	glScaled(0.07, 1, 0.07);
	glutSolidCube(1.6);
	glPopMatrix();



	//down right
	glPushMatrix();
	glTranslated(299.1, -3, 51.2);
	glRotated(90, 0, 1, 0);
	glScaled(0.07, 1, 0.07);
	glutSolidCube(1.6);
	glPopMatrix();

	//connecting the legs on the right
	glBegin(GL_QUADS);
	glVertex3d(306.9, -3.5, 51.2);
	glVertex3d(304.3, -3.5, 51.2);
	glVertex3d(304.3, -3.3, 51.2);
	glVertex3d(306.9, -3.3, 51.2);

	glVertex3d(301.7, -3.5, 51.2);
	glVertex3d(304.3, -3.5, 51.2);
	glVertex3d(304.3, -3.3, 51.2);
	glVertex3d(301.7, -3.3, 51.2);

	glVertex3d(301.7, -3.5, 51.2);
	glVertex3d(299.1, -3.5, 51.2);
	glVertex3d(299.1, -3.3, 51.2);
	glVertex3d(301.7, -3.3, 51.2);
	glEnd();



	//top left
	glPushMatrix();
	glTranslated(306.9, -3, 48.8);
	glRotated(90, 0, 1, 0);
	glScaled(0.07, 1, 0.07);
	glutSolidCube(1.6);
	glPopMatrix();

	glPushMatrix();
	glTranslated(304.3, -3, 48.8);
	glRotated(90, 0, 1, 0);
	glScaled(0.07, 1, 0.07);
	glutSolidCube(1.6);
	glPopMatrix();


	glPushMatrix();
	glTranslated(301.7, -3, 48.8);
	glRotated(90, 0, 1, 0);
	glScaled(0.07, 1, 0.07);
	glutSolidCube(1.6);
	glPopMatrix();

	//down left
	glPushMatrix();
	glTranslated(299.1, -3, 48.8);
	glRotated(90, 0, 1, 0);
	glScaled(0.07, 1, 0.07);
	glutSolidCube(1.6);
	glPopMatrix();


	//connecting the legs on the left
	glBegin(GL_QUADS);
	glVertex3d(306.9, -3.5, 48.8);
	glVertex3d(304.3, -3.5, 48.8);
	glVertex3d(304.3, -3.3, 48.8);
	glVertex3d(306.9, -3.3, 48.8);

	glVertex3d(301.7, -3.5, 48.8);
	glVertex3d(304.3, -3.5, 48.8);
	glVertex3d(304.3, -3.3, 48.8);
	glVertex3d(301.7, -3.3, 48.8);

	glVertex3d(301.7, -3.5, 48.8);
	glVertex3d(299.1, -3.5, 48.8);
	glVertex3d(299.1, -3.3, 48.8);
	glVertex3d(301.7, -3.3, 48.8);
	glEnd();


	//connecting right and left
	glBegin(GL_QUADS);
	glVertex3d(299.1, -3.5, 48.8);
	glVertex3d(299.1, -3.5, 51.2);
	glVertex3d(299.1, -3.3, 51.2);
	glVertex3d(299.1, -3.3, 48.8);


	glVertex3d(306.9, -3.5, 48.8);
	glVertex3d(306.9, -3.5, 51.2);
	glVertex3d(306.9, -3.3, 51.2);
	glVertex3d(306.9, -3.3, 48.8);
	glEnd();



	glPopMatrix();

	////second chair in the hallway infront of godfather

	glPushMatrix();

	glTranslated(-5, -4, 50);
	//stand

	glPushMatrix();
	glColor3ub(0, 0, 255);
	glTranslated(303, -2, 50);
	glRotated(90, 0, 1, 0);
	glScaled(0.3, 0.05, 1);
	glutSolidCube(8);
	glPopMatrix();


	//legs

//corners
	//top right
	glColor3ub(0, 0, 0);
	glPushMatrix();

	glTranslated(306.9, -3, 51.2);
	glRotated(90, 0, 1, 0);
	glScaled(0.07, 1, 0.07);
	glutSolidCube(1.6);
	glPopMatrix();

	glPushMatrix();
	glTranslated(304.3, -3, 51.2);
	glRotated(180, 0, 1, 0);
	glScaled(0.07, 1, 0.07);
	glutSolidCube(1.6);
	glPopMatrix();

	glPushMatrix();
	glTranslated(301.7, -3, 51.2);
	glRotated(90, 0, 1, 0);
	glScaled(0.07, 1, 0.07);
	glutSolidCube(1.6);
	glPopMatrix();



	//down right
	glPushMatrix();
	glTranslated(299.1, -3, 51.2);
	glRotated(90, 0, 1, 0);
	glScaled(0.07, 1, 0.07);
	glutSolidCube(1.6);
	glPopMatrix();

	//connecting the legs on the right
	glBegin(GL_QUADS);
	glVertex3d(306.9, -3.5, 51.2);
	glVertex3d(304.3, -3.5, 51.2);
	glVertex3d(304.3, -3.3, 51.2);
	glVertex3d(306.9, -3.3, 51.2);

	glVertex3d(301.7, -3.5, 51.2);
	glVertex3d(304.3, -3.5, 51.2);
	glVertex3d(304.3, -3.3, 51.2);
	glVertex3d(301.7, -3.3, 51.2);

	glVertex3d(301.7, -3.5, 51.2);
	glVertex3d(299.1, -3.5, 51.2);
	glVertex3d(299.1, -3.3, 51.2);
	glVertex3d(301.7, -3.3, 51.2);
	glEnd();



	//top left
	glPushMatrix();
	glTranslated(306.9, -3, 48.8);
	glRotated(90, 0, 1, 0);
	glScaled(0.07, 1, 0.07);
	glutSolidCube(1.6);
	glPopMatrix();

	glPushMatrix();
	glTranslated(304.3, -3, 48.8);
	glRotated(90, 0, 1, 0);
	glScaled(0.07, 1, 0.07);
	glutSolidCube(1.6);
	glPopMatrix();


	glPushMatrix();
	glTranslated(301.7, -3, 48.8);
	glRotated(90, 0, 1, 0);
	glScaled(0.07, 1, 0.07);
	glutSolidCube(1.6);
	glPopMatrix();

	//down left
	glPushMatrix();
	glTranslated(299.1, -3, 48.8);
	glRotated(90, 0, 1, 0);
	glScaled(0.07, 1, 0.07);
	glutSolidCube(1.6);
	glPopMatrix();


	//connecting the legs on the left
	glBegin(GL_QUADS);
	glVertex3d(306.9, -3.5, 48.8);
	glVertex3d(304.3, -3.5, 48.8);
	glVertex3d(304.3, -3.3, 48.8);
	glVertex3d(306.9, -3.3, 48.8);

	glVertex3d(301.7, -3.5, 48.8);
	glVertex3d(304.3, -3.5, 48.8);
	glVertex3d(304.3, -3.3, 48.8);
	glVertex3d(301.7, -3.3, 48.8);

	glVertex3d(301.7, -3.5, 48.8);
	glVertex3d(299.1, -3.5, 48.8);
	glVertex3d(299.1, -3.3, 48.8);
	glVertex3d(301.7, -3.3, 48.8);
	glEnd();


	//connecting right and left
	glBegin(GL_QUADS);
	glVertex3d(299.1, -3.5, 48.8);
	glVertex3d(299.1, -3.5, 51.2);
	glVertex3d(299.1, -3.3, 51.2);
	glVertex3d(299.1, -3.3, 48.8);


	glVertex3d(306.9, -3.5, 48.8);
	glVertex3d(306.9, -3.5, 51.2);
	glVertex3d(306.9, -3.3, 51.2);
	glVertex3d(306.9, -3.3, 48.8);
	glEnd();



	glPopMatrix();







	///////////////////////// end ////////////////////////////////////



	////fridge
	//glPushMatrix();
	//glTranslated(363, -1, 50);
	//glColor3ub(216, 199, 144);
	//glScaled(3.3, 7, 3);
	//glutSolidCube(2);
	//glPopMatrix();
	//glPushMatrix();
	//glTranslated(363, 0, 48.8);
	//glColor3ub(176, 196, 222);
	//glScaled(2.5, 5, 2.3);
	//glutSolidCube(2);
	//glPopMatrix();
	//glPushMatrix();
	//glColor3ub(105, 105, 105);
	//glTranslated(365, -4.6, 52);
	//glRotated(90, 0, 1, 0);
	//glScaled(0.1, 0.1, 0.8);
	//gluCylinder(a, 2, 2, 3, 10, 10);
	//glPopMatrix();

	//2nd floor
	/*
		glPushMatrix();
	glTranslated(0, 21, 0);
	glScaled(150, 0.1, 50);
	glColor3b(0, 0, 0);
	glutSolidCube(12);
	glPopMatrix();

	*/



	////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////// drawinf from ice-1 to ice-4


	glPushMatrix();
	glTranslated(-250, 0, 87);
	//glRotated(180, 0, 1, 0);
	glColor3ub(239, 211, 211);

	glBegin(GL_QUADS);

	//the wall right to ice-01 door
	glVertex3d(1, 8, 5);
	glVertex3d(24, 8, 5);
	glVertex3d(24, -8, 5);
	glVertex3d(1, -8, 5);

	//the top wall of ice-01 door
	glVertex3d(24, 8, 5);
	glVertex3d(32, 8, 5);
	glVertex3d(32, 4, 5);
	glVertex3d(24, 4, 5);

	//the wall left to ice-01 door and right to ice-02 door
	glVertex3d(32, 8, 5);
	glVertex3d(90, 8, 5);
	glVertex3d(90, -8, 5);
	glVertex3d(32, -8, 5);

	//the top wall of ice-02 door
	glVertex3d(90, 8, 5);
	glVertex3d(98, 8, 5);
	glVertex3d(98, 4, 5);
	glVertex3d(90, 4, 5);

	//the wall left to ice-02 door and right to ice-03 door
	glVertex3d(98, 8, 5);
	glVertex3d(146, 8, 5);
	glVertex3d(146, -8, 5);
	glVertex3d(98, -8, 5);

	//the top wall of ice-03 door
	glVertex3d(146, 8, 5);
	glVertex3d(154, 8, 5);
	glVertex3d(154, 4, 5);
	glVertex3d(146, 4, 5);

	//the wall left to ice-03 door and right to ice-4 door
	glVertex3d(154, 8, 5);
	glVertex3d(202, 8, 5);
	glVertex3d(202, -8, 5);
	glVertex3d(154, -8, 5);

	//the top wall of ice-4 door
	glVertex3d(202, 8, 5);
	glVertex3d(210, 8, 5);
	glVertex3d(210, 4, 5);
	glVertex3d(202, 4, 5);

	//the wall left to ice-4 door until the end of the corridor
	glVertex3d(210, 8, 5);
	glVertex3d(258, 8, 5);
	glVertex3d(258, -8, 5);
	glVertex3d(210, -8, 5);

	//the back wall of ice-4
	glVertex3d(258, 8, 5);
	glVertex3d(258, -8, 5);
	glVertex3d(258, -8, 55);
	glVertex3d(258, 8, 55);

	// ICE-4

	// first window in ice-4
	glVertex3d(258, 8, 55);
	glVertex3d(258, -8, 55);
	glVertex3d(246, -8, 55);
	glVertex3d(246, 8, 55);

	glVertex3d(246, 8, 55);
	glVertex3d(246, 4, 55);
	glVertex3d(238, 4, 55);
	glVertex3d(238, 8, 55);

	glVertex3d(246, -4, 55);
	glVertex3d(246, -8, 55);
	glVertex3d(238, -8, 55);
	glVertex3d(238, -4, 55);

	glVertex3d(238, 8, 55);
	glVertex3d(238, -8, 55);
	glVertex3d(234, -8, 55);
	glVertex3d(234, 8, 55);
	//end

	// second window in ice-4
	glVertex3d(234, 8, 55);
	glVertex3d(234, 4, 55);
	glVertex3d(226, 4, 55);
	glVertex3d(226, 8, 55);

	glVertex3d(234, -4, 55);
	glVertex3d(234, -8, 55);
	glVertex3d(226, -8, 55);
	glVertex3d(226, -4, 55);

	glVertex3d(226, 8, 55);
	glVertex3d(226, -8, 55);
	glVertex3d(222, -8, 55);
	glVertex3d(222, 8, 55);
	//end

	//third window in ice-4
	glVertex3d(222, 8, 55);
	glVertex3d(222, 4, 55);
	glVertex3d(214, 4, 55);
	glVertex3d(214, 8, 55);

	glVertex3d(222, -4, 55);
	glVertex3d(222, -8, 55);
	glVertex3d(214, -8, 55);
	glVertex3d(214, -4, 55);


	glVertex3d(214, 8, 55);
	glVertex3d(214, -8, 55);
	glVertex3d(210, -8, 55);
	glVertex3d(210, 8, 55);

	//end

	// the wall between the board wall and the nearest window
	glVertex3d(210, 8, 55);
	glVertex3d(210, -8, 55);
	glVertex3d(202, -8, 55);
	glVertex3d(202, 8, 55);


	//board wall in ice-4
	glVertex3d(202, 8, 55);
	glVertex3d(202, -8, 55);
	glVertex3d(200, -8, 5);
	glVertex3d(200, 8, 5);

	//END OF ICE-4

	//ICE-03

	// first window in ice-03
	glVertex3d(202, 8, 55);
	glVertex3d(202, -8, 55);
	glVertex3d(190, -8, 55);
	glVertex3d(190, 8, 55);

	glVertex3d(190, 8, 55);
	glVertex3d(190, 4, 55);
	glVertex3d(182, 4, 55);
	glVertex3d(182, 8, 55);

	glVertex3d(190, -4, 55);
	glVertex3d(190, -8, 55);
	glVertex3d(182, -8, 55);
	glVertex3d(182, -4, 55);

	glVertex3d(182, 8, 55);
	glVertex3d(182, -8, 55);
	glVertex3d(178, -8, 55);
	glVertex3d(178, 8, 55);
	//end

	// second window in ice-3
	glVertex3d(178, 8, 55);
	glVertex3d(178, 4, 55);
	glVertex3d(170, 4, 55);
	glVertex3d(170, 8, 55);

	glVertex3d(178, -4, 55);
	glVertex3d(178, -8, 55);
	glVertex3d(170, -8, 55);
	glVertex3d(170, -4, 55);

	glVertex3d(170, 8, 55);
	glVertex3d(170, -8, 55);
	glVertex3d(166, -8, 55);
	glVertex3d(166, 8, 55);

	//third window in ice-3
	glVertex3d(166, 8, 55);
	glVertex3d(166, 4, 55);
	glVertex3d(158, 4, 55);
	glVertex3d(158, 8, 55);

	glVertex3d(166, -4, 55);
	glVertex3d(166, -8, 55);
	glVertex3d(158, -8, 55);
	glVertex3d(158, -4, 55);

	glVertex3d(158, 8, 55);
	glVertex3d(158, -8, 55);
	glVertex3d(146, -8, 55);
	glVertex3d(146, 8, 55);

	//board wall in ice-3
	glVertex3d(146, 8, 55);
	glVertex3d(146, -8, 55);
	glVertex3d(144, -8, 5);
	glVertex3d(144, 8, 5);

	//END OF ICE-3

	//ICE-2
	//first window
	glVertex3d(146, 8, 55);
	glVertex3d(146, -8, 55);
	glVertex3d(134, -8, 55);
	glVertex3d(134, 8, 55);

	glVertex3d(134, 8, 55);
	glVertex3d(134, 4, 55);
	glVertex3d(126, 4, 55);
	glVertex3d(126, 8, 55);

	glVertex3d(134, -4, 55);
	glVertex3d(134, -8, 55);
	glVertex3d(126, -8, 55);
	glVertex3d(126, -4, 55);

	glVertex3d(126, 8, 55);
	glVertex3d(126, -8, 55);
	glVertex3d(122, -8, 55);
	glVertex3d(122, 8, 55);

	//second window in ice-2
	glVertex3d(122, 8, 55);
	glVertex3d(122, 4, 55);
	glVertex3d(114, 4, 55);
	glVertex3d(114, 8, 55);

	glVertex3d(122, -4, 55);
	glVertex3d(122, -8, 55);
	glVertex3d(114, -8, 55);
	glVertex3d(114, -4, 55);

	glVertex3d(114, 8, 55);
	glVertex3d(114, -8, 55);
	glVertex3d(110, -8, 55);
	glVertex3d(110, 8, 55);

	//third window in ice-2
	glVertex3d(110, 8, 55);
	glVertex3d(110, 4, 55);
	glVertex3d(102, 4, 55);
	glVertex3d(102, 8, 55);

	glVertex3d(110, -4, 55);
	glVertex3d(110, -8, 55);
	glVertex3d(102, -8, 55);
	glVertex3d(102, -4, 55);

	glVertex3d(102, 8, 55);
	glVertex3d(102, -8, 55);
	glVertex3d(90, -8, 55);
	glVertex3d(90, 8, 55);

	//board wall in ice-2
	glVertex3d(90, 8, 55);
	glVertex3d(90, -8, 55);
	glVertex3d(88, -8, 5);
	glVertex3d(88, 8, 5);

	//ICE-1
	//first window
	glVertex3d(90, 8, 55);
	glVertex3d(90, -8, 55);
	glVertex3d(78, -8, 55);
	glVertex3d(78, 8, 55);

	glVertex3d(78, 8, 55);
	glVertex3d(78, 4, 55);
	glVertex3d(70, 4, 55);
	glVertex3d(70, 8, 55);

	glVertex3d(78, -4, 55);
	glVertex3d(78, -8, 55);
	glVertex3d(70, -8, 55);
	glVertex3d(70, -4, 55);

	glVertex3d(70, 8, 55);
	glVertex3d(70, -8, 55);
	glVertex3d(66, -8, 55);
	glVertex3d(66, 8, 55);


	//second window
	glVertex3d(66, 8, 55);
	glVertex3d(66, 4, 55);
	glVertex3d(58, 4, 55);
	glVertex3d(58, 8, 55);

	glVertex3d(66, -4, 55);
	glVertex3d(66, -8, 55);
	glVertex3d(58, -8, 55);
	glVertex3d(58, -4, 55);

	glVertex3d(58, 8, 55);
	glVertex3d(58, -8, 55);
	glVertex3d(54, -8, 55);
	glVertex3d(54, 8, 55);

	//third window 
	glVertex3d(54, 8, 55);
	glVertex3d(54, 4, 55);
	glVertex3d(46, 4, 55);
	glVertex3d(46, 8, 55);

	glVertex3d(54, -4, 55);
	glVertex3d(54, -8, 55);
	glVertex3d(46, -8, 55);
	glVertex3d(46, -4, 55);

	glVertex3d(46, 8, 55);
	glVertex3d(46, -8, 55);
	glVertex3d(24, -8, 55);
	glVertex3d(24, 8, 55);

	//board wall
	glVertex3d(24, 8, 55);
	glVertex3d(24, -8, 55);
	glVertex3d(22, -8, 5);
	glVertex3d(22, 8, 5);

	// end of ice-1

	// wall between ice-1 and offices
	glVertex3d(1, 8, 5);
	glVertex3d(1, -8, 5);
	glVertex3d(0, -8, -178);
	glVertex3d(0, 8, -178);


	glEnd();
	glPopMatrix();

	////////



	///////////////////////////////////////////////////////////////////////////////////////////////////////

		// offices and ice-17


	glPushMatrix();
	glTranslated(15, 0, -85);
	glRotated(180, 0, 1, 0);
	glColor3ub(239, 211, 211);

	glBegin(GL_QUADS);

	//the wall right to ice-17 door
	glVertex3d(8, 8, 5);
	glVertex3d(24, 8, 5);
	glVertex3d(24, -8, 5);
	glVertex3d(8, -8, 5);

	//the top wall of ice-17 door
	glVertex3d(24, 8, 5);
	glVertex3d(32, 8, 5);
	glVertex3d(32, 4, 5);
	glVertex3d(24, 4, 5);

	//the wall left to ice-17 door and right to الشؤون
	glVertex3d(32, 8, 5);
	glVertex3d(90, 8, 5);
	glVertex3d(90, -8, 5);
	glVertex3d(32, -8, 5);

	//the top wall of الشؤون
	glVertex3d(90, 8, 5);
	glVertex3d(98, 8, 5);
	glVertex3d(98, 4, 5);
	glVertex3d(90, 4, 5);

	//the wall left to الشؤون and right to مكتب الدكاترة الاول
	glVertex3d(98, 8, 5);
	glVertex3d(146, 8, 5);
	glVertex3d(146, -8, 5);
	glVertex3d(98, -8, 5);

	//the top wall of مكتب الدكاترة الاول door
	glVertex3d(146, 8, 5);
	glVertex3d(154, 8, 5);
	glVertex3d(154, 4, 5);
	glVertex3d(146, 4, 5);

	//the wall left to مكتب الدكاترة الاول door and right to مكتب الدكاترة التاني door
	glVertex3d(154, 8, 5);
	glVertex3d(202, 8, 5);
	glVertex3d(202, -8, 5);
	glVertex3d(154, -8, 5);

	//the top wall of مكتب الدكاترة التاني door
	glVertex3d(202, 8, 5);
	glVertex3d(210, 8, 5);
	glVertex3d(210, 4, 5);
	glVertex3d(202, 4, 5);

	//the wall left to مكتب الدكاترة التاني door until the end of the corridor
	glVertex3d(210, 8, 5);
	glVertex3d(265, 8, 5);
	glVertex3d(265, -8, 5);
	glVertex3d(210, -8, 5);

	//the back wall of مكتب الدكاترة التاني
	glVertex3d(258, 8, 5);
	glVertex3d(258, -8, 5);
	glVertex3d(258, -8, 55);
	glVertex3d(258, 8, 55);


	// مكتب الدكاترة التاني

	// first window in مكتب الدكاترة التاني
	glVertex3d(258, 8, 55);
	glVertex3d(258, -8, 55);
	glVertex3d(246, -8, 55);
	glVertex3d(246, 8, 55);

	glVertex3d(246, 8, 55);
	glVertex3d(246, 4, 55);
	glVertex3d(238, 4, 55);
	glVertex3d(238, 8, 55);

	glVertex3d(246, -4, 55);
	glVertex3d(246, -8, 55);
	glVertex3d(238, -8, 55);
	glVertex3d(238, -4, 55);

	glVertex3d(238, 8, 55);
	glVertex3d(238, -8, 55);
	glVertex3d(234, -8, 55);
	glVertex3d(234, 8, 55);
	//end

	// second window in مكتب الدكاترة التاني
	glVertex3d(234, 8, 55);
	glVertex3d(234, 4, 55);
	glVertex3d(226, 4, 55);
	glVertex3d(226, 8, 55);

	glVertex3d(234, -4, 55);
	glVertex3d(234, -8, 55);
	glVertex3d(226, -8, 55);
	glVertex3d(226, -4, 55);

	glVertex3d(226, 8, 55);
	glVertex3d(226, -8, 55);
	glVertex3d(222, -8, 55);
	glVertex3d(222, 8, 55);
	//end

	//third window in مكتب الدكاترة التاني
	glVertex3d(222, 8, 55);
	glVertex3d(222, 4, 55);
	glVertex3d(214, 4, 55);
	glVertex3d(214, 8, 55);

	glVertex3d(222, -4, 55);
	glVertex3d(222, -8, 55);
	glVertex3d(214, -8, 55);
	glVertex3d(214, -4, 55);


	glVertex3d(214, 8, 55);
	glVertex3d(214, -8, 55);
	glVertex3d(210, -8, 55);
	glVertex3d(210, 8, 55);

	//end

	// the wall between the board wall and the nearest window
	glVertex3d(210, 8, 55);
	glVertex3d(210, -8, 55);
	glVertex3d(202, -8, 55);
	glVertex3d(202, 8, 55);


	//board wall in مكتب الدكاترة التاني
	glVertex3d(202, 8, 55);
	glVertex3d(202, -8, 55);
	glVertex3d(200, -8, 5);
	glVertex3d(200, 8, 5);
	//we connect between 202 and 200 rather than 202 to leave 2cm between the board wall and the right wall of the door

	//END OF مكتب الدكاترة التاني

	//مكتب الدكاترة الاول 

	// first window in مكتب الدكاترة الاول
	glVertex3d(202, 8, 55);
	glVertex3d(202, -8, 55);
	glVertex3d(190, -8, 55);
	glVertex3d(190, 8, 55);

	glVertex3d(190, 8, 55);
	glVertex3d(190, 4, 55);
	glVertex3d(182, 4, 55);
	glVertex3d(182, 8, 55);

	glVertex3d(190, -4, 55);
	glVertex3d(190, -8, 55);
	glVertex3d(182, -8, 55);
	glVertex3d(182, -4, 55);

	glVertex3d(182, 8, 55);
	glVertex3d(182, -8, 55);
	glVertex3d(178, -8, 55);
	glVertex3d(178, 8, 55);
	//end

	// second window in مكتب الدكاترة الاول
	glVertex3d(178, 8, 55);
	glVertex3d(178, 4, 55);
	glVertex3d(170, 4, 55);
	glVertex3d(170, 8, 55);

	glVertex3d(178, -4, 55);
	glVertex3d(178, -8, 55);
	glVertex3d(170, -8, 55);
	glVertex3d(170, -4, 55);

	glVertex3d(170, 8, 55);
	glVertex3d(170, -8, 55);
	glVertex3d(166, -8, 55);
	glVertex3d(166, 8, 55);

	//third window in مكتب الدكاترة الاول
	glVertex3d(166, 8, 55);
	glVertex3d(166, 4, 55);
	glVertex3d(158, 4, 55);
	glVertex3d(158, 8, 55);

	glVertex3d(166, -4, 55);
	glVertex3d(166, -8, 55);
	glVertex3d(158, -8, 55);
	glVertex3d(158, -4, 55);

	glVertex3d(158, 8, 55);
	glVertex3d(158, -8, 55);
	glVertex3d(146, -8, 55);
	glVertex3d(146, 8, 55);

	//board wall in مكتب الدكاترة الاول
	glVertex3d(146, 8, 55);
	glVertex3d(146, -8, 55);
	glVertex3d(144, -8, 5);
	glVertex3d(144, 8, 5);

	//END OF مكتب الدكاترة الاول

	//الشؤون
	//first window
	glVertex3d(146, 8, 55);
	glVertex3d(146, -8, 55);
	glVertex3d(134, -8, 55);
	glVertex3d(134, 8, 55);

	glVertex3d(134, 8, 55);
	glVertex3d(134, 4, 55);
	glVertex3d(126, 4, 55);
	glVertex3d(126, 8, 55);

	glVertex3d(134, -4, 55);
	glVertex3d(134, -8, 55);
	glVertex3d(126, -8, 55);
	glVertex3d(126, -4, 55);

	glVertex3d(126, 8, 55);
	glVertex3d(126, -8, 55);
	glVertex3d(122, -8, 55);
	glVertex3d(122, 8, 55);

	//second window in الشؤون
	glVertex3d(122, 8, 55);
	glVertex3d(122, 4, 55);
	glVertex3d(114, 4, 55);
	glVertex3d(114, 8, 55);

	glVertex3d(122, -4, 55);
	glVertex3d(122, -8, 55);
	glVertex3d(114, -8, 55);
	glVertex3d(114, -4, 55);

	glVertex3d(114, 8, 55);
	glVertex3d(114, -8, 55);
	glVertex3d(110, -8, 55);
	glVertex3d(110, 8, 55);

	//third window in الشؤون
	glVertex3d(110, 8, 55);
	glVertex3d(110, 4, 55);
	glVertex3d(102, 4, 55);
	glVertex3d(102, 8, 55);

	glVertex3d(110, -4, 55);
	glVertex3d(110, -8, 55);
	glVertex3d(102, -8, 55);
	glVertex3d(102, -4, 55);

	glVertex3d(102, 8, 55);
	glVertex3d(102, -8, 55);
	glVertex3d(90, -8, 55);
	glVertex3d(90, 8, 55);

	//board wall in الشؤون
	glVertex3d(90, 8, 55);
	glVertex3d(90, -8, 55);
	glVertex3d(88, -8, 5);
	glVertex3d(88, 8, 5);

	//ICE-17
	//first window
	glVertex3d(90, 8, 55);
	glVertex3d(90, -8, 55);
	glVertex3d(78, -8, 55);
	glVertex3d(78, 8, 55);

	glVertex3d(78, 8, 55);
	glVertex3d(78, 4, 55);
	glVertex3d(70, 4, 55);
	glVertex3d(70, 8, 55);

	glVertex3d(78, -4, 55);
	glVertex3d(78, -8, 55);
	glVertex3d(70, -8, 55);
	glVertex3d(70, -4, 55);

	glVertex3d(70, 8, 55);
	glVertex3d(70, -8, 55);
	glVertex3d(66, -8, 55);
	glVertex3d(66, 8, 55);


	//second window
	glVertex3d(66, 8, 55);
	glVertex3d(66, 4, 55);
	glVertex3d(58, 4, 55);
	glVertex3d(58, 8, 55);

	glVertex3d(66, -4, 55);
	glVertex3d(66, -8, 55);
	glVertex3d(58, -8, 55);
	glVertex3d(58, -4, 55);

	glVertex3d(58, 8, 55);
	glVertex3d(58, -8, 55);
	glVertex3d(54, -8, 55);
	glVertex3d(54, 8, 55);

	//third window 
	glVertex3d(54, 8, 55);
	glVertex3d(54, 4, 55);
	glVertex3d(46, 4, 55);
	glVertex3d(46, 8, 55);

	glVertex3d(54, -4, 55);
	glVertex3d(54, -8, 55);
	glVertex3d(46, -8, 55);
	glVertex3d(46, -4, 55);

	glVertex3d(46, 8, 55);
	glVertex3d(46, -8, 55);
	glVertex3d(24, -8, 55);
	glVertex3d(24, 8, 55);

	//board wall
	glVertex3d(24, 8, 55);
	glVertex3d(24, -8, 55);
	glVertex3d(22, -8, 5);
	glVertex3d(22, 8, 5);

	// end of ice-17

	glEnd();
	glPopMatrix();






	/////////////////////////////////////////////////////////////////////////////////////////////////////
		// Set the color to grey

	///// stairs besides ice-04 /////////////////////////////////////////////////////////

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(26, -7, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(29, -5.5, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(32, -4, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(35, -2.5, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(38, -1, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(41, 0.5, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(44, 2, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(47, 3.5, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(50, 5, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(60, 6.5, 73.5);
	glScaled(6, 0.5, 12);
	glutSolidCube(3);
	glPopMatrix();



	/////////////// end stairs /////////////////////////////////////////

	///// stairs besides ice-04 /////////////////////////////////////////////////////////

	glPushMatrix();

	glRotatef(180, 0, 1, 0);
	glTranslatef(-75.5, 15, -147);

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(26, -7, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(29, -5.5, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(32, -4, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(35, -2.5, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(38, -1, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(41, 0.5, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(44, 2, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(47, 3.5, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(50, 5, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();



	glPopMatrix();
	/////////////// end stairs /////////////////////////////////////////


	///// stairs besides godfather /////////////////////////////////////////////////////////

	glPushMatrix();
	glTranslated(230, 0, -75);
	glRotated(90, 0, 1, 0);



	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(26, -7, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(29, -5.5, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(32, -4, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(35, -2.5, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(38, -1, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(41, 0.5, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(44, 2, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(47, 3.5, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(50, 5, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(60, 6.5, 73.5);
	glScaled(6, 0.5, 12);
	glutSolidCube(3);
	glPopMatrix();



	/////////////// end stairs /////////////////////////////////////////

	///// stairs besides ice-04 /////////////////////////////////////////////////////////

	glPushMatrix();

	glRotatef(180, 0, 1, 0);
	glTranslatef(-75.5, 15, -147);

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(26, -7, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(29, -5.5, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(32, -4, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(35, -2.5, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(38, -1, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(41, 0.5, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(44, 2, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(47, 3.5, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(255, 204, 153);
	glTranslated(50, 5, 64.5);
	glScaled(1, 0.5, 6);
	glutSolidCube(3);
	glPopMatrix();



	glPopMatrix();
	/////////////// end stairs /////////////////////////////////////////


	glPopMatrix();



	//box between ice-01 to ice-04 and offices
	glPushMatrix();
	glColor3f(0.8, 0.5, 0.5);
	glTranslated(-130, 0, 3);
	glScaled(20, 2, 12);
	glutSolidCube(10);
	glPopMatrix();

	// box between CL-01 to PHL and offices
	glPushMatrix();
	glColor3f(0.8, 0.5, 0.5);
	glTranslated(-130, 32, 3);
	glScaled(20, 2, 12);
	glutSolidCube(10);
	glPopMatrix();



	//border of map
	glPushMatrix();
	glEnable(GL_QUADS);
	glColor3b(0, 0, 255);
	glVertex3f(8, 0, 4);
	glVertex3f(8, 0, 4);
	glVertex3f(-8, 0, 4);
	glVertex3f(-8, 0, 4);
	glEnd();
	glPopMatrix();


	//table
	glPushMatrix();
	glColor3ub(139, 69, 19);
	glTranslated(360, -2, 3);
	glScaled(1, 0.1, 3.4);
	glutSolidCube(4.2);
	glPopMatrix();
	//caffe machain
	glPushMatrix();
	glColor3ub(139, 0, 0);
	glTranslated(360, -0.5, 3);
	glScaled(1, 1.4, 1);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(0, 0, 0);
	glTranslated(360.3, 1, 3);
	glScaled(1.6, 0.1, 1);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(128, 128, 128);
	//glRotated(-90, 1, 0, 0);
	glTranslated(360.5, -0.5, 3);
	glScaled(1.6, 0.2, 1);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();



	// ?????
	glPushMatrix();
	glColor3ub(112, 128, 144);
	glTranslated(440, 0, 20);
	//glRotated(0, 0, 0, 1);
	glScaled(1, 3.4, 1);
	glutSolidCube(5);
	glPopMatrix();

	//wall inside godfather
	glPushMatrix();
	glColor3ub(112, 128, 144);
	glTranslated(330, 0, -8);
	//glRotated(90, 0, 0, 1);
	glScaled(9.6, 3.4, 1);
	glutSolidCube(5);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(112, 128, 144);
	glTranslated(356, 0, 13.5);
	//glRotated(45, 1, 0, 0);
	glScaled(1, 3.4, 9.6);
	glutSolidCube(5);
	glPopMatrix();


	/////////////////Yaman Section ///////////////////////////////
	glPushMatrix();
	glColor3ub(239, 211, 211);
	glBegin(GL_QUADS);

	///  wall of ice-5 that has mashareb

	glVertex3d(8, 8, 5);
	glVertex3d(8, -8, 5);
	glVertex3d(8, -8, 55);
	glVertex3d(8, 8, 55);

	glVertex3d(8, 8, 55);
	glVertex3d(8, -8, 55);
	glVertex3d(24, -8, 55);
	glVertex3d(24, 8, 55);

	/// wall behind stairs ice-4
	glVertex3d(8, 8, 92);
	glVertex3d(8, -8, 92);
	glVertex3d(85, -8, 92);
	glVertex3d(85, 8, 92);

	glVertex3d(85, 8, 92);
	glVertex3d(85, -8, 92);
	glVertex3d(85, -8, 55);
	glVertex3d(85, 8, 55);



	//the wall right to ice-05 door
	glVertex3d(8, 8, 5);
	glVertex3d(24, 8, 5);
	glVertex3d(24, -8, 5);
	glVertex3d(8, -8, 5);

	//the top wall of ice-05 door
	glVertex3d(24, 8, 5);
	glVertex3d(32, 8, 5);
	glVertex3d(32, 4, 5);
	glVertex3d(24, 4, 5);



	//the wall left to ice-05 door and right to ice-07 door
	glVertex3d(32, 8, 5);
	glVertex3d(90, 8, 5);
	glVertex3d(90, -8, 5);
	glVertex3d(32, -8, 5);

	//the top wall of ice-07 door
	glVertex3d(90, 8, 5);
	glVertex3d(98, 8, 5);
	glVertex3d(98, 4, 5);
	glVertex3d(90, 4, 5);

	//the wall left to ice-07 door and right to ice-09 door
	glVertex3d(98, 8, 5);
	glVertex3d(146, 8, 5);
	glVertex3d(146, -8, 5);
	glVertex3d(98, -8, 5);

	//the top wall of ice-09 door
	glVertex3d(146, 8, 5);
	glVertex3d(154, 8, 5);
	glVertex3d(154, 4, 5);
	glVertex3d(146, 4, 5);

	//the wall left to ice-09 door and right to ice-11 door
	glVertex3d(154, 8, 5);
	glVertex3d(202, 8, 5);
	glVertex3d(202, -8, 5);
	glVertex3d(154, -8, 5);

	//the top wall of ice-11 door
	glVertex3d(202, 8, 5);
	glVertex3d(210, 8, 5);
	glVertex3d(210, 4, 5);
	glVertex3d(202, 4, 5);

	//the wall left to ice-11 door until the end of the corridor
	glVertex3d(210, 8, 5);
	glVertex3d(258, 8, 5);
	glVertex3d(258, -8, 5);
	glVertex3d(210, -8, 5);

	//the back wall of ice-11
	glVertex3d(258, 8, 5);
	glVertex3d(258, -8, 5);
	glVertex3d(258, -8, 55);
	glVertex3d(258, 8, 55);




	/*

	1------4-------6------12
	-      -       -      -
	-      5-------7      -
	-      -       -      -
	-      -       -      -
	-      -       -      -
	-      8-------10     -
	-      -       -      -
	2------3-------9------11


	 We draw each window using this method:

	 draw from 1-->2-->3-->4 (the wall left to the window)
	 then  4-->5-->7-->6     (the wall top to the window)
	 then  8-->3-->9-->10     (the wall under the window)
	 then  6-->9-->11-->12    (the wall right to the window)

	from 1-->4  12cm
	from 4-->6  8cm
	from 6-->12  4cm if there is a window next to it  (OR)  12 cm if it is the last window
	because it will continue to the board wall



	*/


	// ICE-11

	// first window in ice-11
	glVertex3d(258, 8, 55);
	glVertex3d(258, -8, 55);
	glVertex3d(246, -8, 55);
	glVertex3d(246, 8, 55);

	glVertex3d(246, 8, 55);
	glVertex3d(246, 4, 55);
	glVertex3d(238, 4, 55);
	glVertex3d(238, 8, 55);

	glVertex3d(246, -4, 55);
	glVertex3d(246, -8, 55);
	glVertex3d(238, -8, 55);
	glVertex3d(238, -4, 55);

	glVertex3d(238, 8, 55);
	glVertex3d(238, -8, 55);
	glVertex3d(234, -8, 55);
	glVertex3d(234, 8, 55);
	//end

	// second window in ice-11
	glVertex3d(234, 8, 55);
	glVertex3d(234, 4, 55);
	glVertex3d(226, 4, 55);
	glVertex3d(226, 8, 55);

	glVertex3d(234, -4, 55);
	glVertex3d(234, -8, 55);
	glVertex3d(226, -8, 55);
	glVertex3d(226, -4, 55);

	glVertex3d(226, 8, 55);
	glVertex3d(226, -8, 55);
	glVertex3d(222, -8, 55);
	glVertex3d(222, 8, 55);
	//end

	//third window in ice-11
	glVertex3d(222, 8, 55);
	glVertex3d(222, 4, 55);
	glVertex3d(214, 4, 55);
	glVertex3d(214, 8, 55);

	glVertex3d(222, -4, 55);
	glVertex3d(222, -8, 55);
	glVertex3d(214, -8, 55);
	glVertex3d(214, -4, 55);


	glVertex3d(214, 8, 55);
	glVertex3d(214, -8, 55);
	glVertex3d(210, -8, 55);
	glVertex3d(210, 8, 55);

	//end

	// the wall between the board wall and the nearest window
	glVertex3d(210, 8, 55);
	glVertex3d(210, -8, 55);
	glVertex3d(202, -8, 55);
	glVertex3d(202, 8, 55);


	//board wall in ice-11
	glVertex3d(202, 8, 55);
	glVertex3d(202, -8, 55);
	glVertex3d(200, -8, 5);
	glVertex3d(200, 8, 5);
	//we connect between 202 and 200 rather than 202 to leave 2cm between the board wall and the right wall of the door

	//END OF ICE-11

	//ICE-09

	// first window in ice-09
	glVertex3d(202, 8, 55);
	glVertex3d(202, -8, 55);
	glVertex3d(190, -8, 55);
	glVertex3d(190, 8, 55);

	glVertex3d(190, 8, 55);
	glVertex3d(190, 4, 55);
	glVertex3d(182, 4, 55);
	glVertex3d(182, 8, 55);

	glVertex3d(190, -4, 55);
	glVertex3d(190, -8, 55);
	glVertex3d(182, -8, 55);
	glVertex3d(182, -4, 55);

	glVertex3d(182, 8, 55);
	glVertex3d(182, -8, 55);
	glVertex3d(178, -8, 55);
	glVertex3d(178, 8, 55);
	//end

	// second window in ice-09
	glVertex3d(178, 8, 55);
	glVertex3d(178, 4, 55);
	glVertex3d(170, 4, 55);
	glVertex3d(170, 8, 55);

	glVertex3d(178, -4, 55);
	glVertex3d(178, -8, 55);
	glVertex3d(170, -8, 55);
	glVertex3d(170, -4, 55);

	glVertex3d(170, 8, 55);
	glVertex3d(170, -8, 55);
	glVertex3d(166, -8, 55);
	glVertex3d(166, 8, 55);

	//third window in ice-09
	glVertex3d(166, 8, 55);
	glVertex3d(166, 4, 55);
	glVertex3d(158, 4, 55);
	glVertex3d(158, 8, 55);

	glVertex3d(166, -4, 55);
	glVertex3d(166, -8, 55);
	glVertex3d(158, -8, 55);
	glVertex3d(158, -4, 55);

	glVertex3d(158, 8, 55);
	glVertex3d(158, -8, 55);
	glVertex3d(146, -8, 55);
	glVertex3d(146, 8, 55);

	//board wall in ice-09
	glVertex3d(146, 8, 55);
	glVertex3d(146, -8, 55);
	glVertex3d(144, -8, 5);
	glVertex3d(144, 8, 5);

	//END OF ICE-09

	//ICE-07
	//first window
	glVertex3d(146, 8, 55);
	glVertex3d(146, -8, 55);
	glVertex3d(134, -8, 55);
	glVertex3d(134, 8, 55);

	glVertex3d(134, 8, 55);
	glVertex3d(134, 4, 55);
	glVertex3d(126, 4, 55);
	glVertex3d(126, 8, 55);

	glVertex3d(134, -4, 55);
	glVertex3d(134, -8, 55);
	glVertex3d(126, -8, 55);
	glVertex3d(126, -4, 55);

	glVertex3d(126, 8, 55);
	glVertex3d(126, -8, 55);
	glVertex3d(122, -8, 55);
	glVertex3d(122, 8, 55);

	//second window in ice-07
	glVertex3d(122, 8, 55);
	glVertex3d(122, 4, 55);
	glVertex3d(114, 4, 55);
	glVertex3d(114, 8, 55);

	glVertex3d(122, -4, 55);
	glVertex3d(122, -8, 55);
	glVertex3d(114, -8, 55);
	glVertex3d(114, -4, 55);

	glVertex3d(114, 8, 55);
	glVertex3d(114, -8, 55);
	glVertex3d(110, -8, 55);
	glVertex3d(110, 8, 55);

	//third window in ice-07
	glVertex3d(110, 8, 55);
	glVertex3d(110, 4, 55);
	glVertex3d(102, 4, 55);
	glVertex3d(102, 8, 55);

	glVertex3d(110, -4, 55);
	glVertex3d(110, -8, 55);
	glVertex3d(102, -8, 55);
	glVertex3d(102, -4, 55);

	glVertex3d(102, 8, 55);
	glVertex3d(102, -8, 55);
	glVertex3d(90, -8, 55);
	glVertex3d(90, 8, 55);

	//board wall in ice-07
	glVertex3d(90, 8, 55);
	glVertex3d(90, -8, 55);
	glVertex3d(88, -8, 5);
	glVertex3d(88, 8, 5);

	//ICE-05
	//first window
	glVertex3d(90, 8, 55);
	glVertex3d(90, -8, 55);
	glVertex3d(78, -8, 55);
	glVertex3d(78, 8, 55);

	glVertex3d(78, 8, 55);
	glVertex3d(78, 4, 55);
	glVertex3d(70, 4, 55);
	glVertex3d(70, 8, 55);

	glVertex3d(78, -4, 55);
	glVertex3d(78, -8, 55);
	glVertex3d(70, -8, 55);
	glVertex3d(70, -4, 55);

	glVertex3d(70, 8, 55);
	glVertex3d(70, -8, 55);
	glVertex3d(66, -8, 55);
	glVertex3d(66, 8, 55);


	//second window
	glVertex3d(66, 8, 55);
	glVertex3d(66, 4, 55);
	glVertex3d(58, 4, 55);
	glVertex3d(58, 8, 55);

	glVertex3d(66, -4, 55);
	glVertex3d(66, -8, 55);
	glVertex3d(58, -8, 55);
	glVertex3d(58, -4, 55);

	glVertex3d(58, 8, 55);
	glVertex3d(58, -8, 55);
	glVertex3d(54, -8, 55);
	glVertex3d(54, 8, 55);

	//third window 
	glVertex3d(54, 8, 55);
	glVertex3d(54, 4, 55);
	glVertex3d(46, 4, 55);
	glVertex3d(46, 8, 55);

	glVertex3d(54, -4, 55);
	glVertex3d(54, -8, 55);
	glVertex3d(46, -8, 55);
	glVertex3d(46, -4, 55);

	glVertex3d(46, 8, 55);
	glVertex3d(46, -8, 55);
	glVertex3d(24, -8, 55);
	glVertex3d(24, 8, 55);

	//board wall
	glVertex3d(24, 8, 55);
	glVertex3d(24, -8, 55);
	glVertex3d(22, -8, 5);
	glVertex3d(22, 8, 5);

	////////// drawing ice-13 to ice-15
	/////////////////Yaman Section ///////////////////////////////

	////////// end drawing ice-13 to ice-15
	// 

	//main hall
	//wall behind ice-11
	glVertex3d(258, 8, 55);
	glVertex3d(258, -8, 55);
	glVertex3d(258, -8, 105);
	glVertex3d(258, 8, 105);
	//right wall of the window
	glVertex3d(258, 8, 105);
	glVertex3d(258, -8, 105);
	glVertex3d(273, -8, 105);
	glVertex3d(273, 8, 105);
	//top wall of the window
	glVertex3d(273, 8, 105);
	glVertex3d(273, 4, 105);
	glVertex3d(293, 4, 105);
	glVertex3d(293, 8, 105);
	//lower wall of the window
	glVertex3d(273, -4, 105);
	glVertex3d(273, -8, 105);
	glVertex3d(293, -8, 105);
	glVertex3d(293, -4, 105);
	//left wall of the window
	glVertex3d(293, 8, 105);
	glVertex3d(293, -8, 105);
	glVertex3d(305, -8, 105);
	glVertex3d(305, 8, 105);
	// wall between window and ice-13
	glVertex3d(305, 8, 105);
	glVertex3d(305, -8, 105);
	glVertex3d(305, -8, 95);
	glVertex3d(305, 8, 95);
	//right wall of ice-13
	glVertex3d(305, 8, 95);
	glVertex3d(305, -8, 95);
	glVertex3d(308, -8, 95);
	glVertex3d(308, 8, 95);
	//board wall of ice-13
	glVertex3d(308, 8, 95);
	glVertex3d(308, -8, 95);
	glVertex3d(308, -8, 145);
	glVertex3d(308, 8, 145);
	//right wall of ice-13
	glVertex3d(308, 8, 145);
	glVertex3d(308, -8, 145);
	glVertex3d(364, -8, 145);
	glVertex3d(364, 8, 145);
	//back wall of ice-13
	glVertex3d(364, 8, 145);
	glVertex3d(364, -8, 145);
	glVertex3d(364, -8, 95);
	glVertex3d(364, 8, 95);
	//top wall of ice-13 door
	glVertex3d(308, 8, 95);
	glVertex3d(308, 4, 95);
	glVertex3d(316, 4, 95);
	glVertex3d(316, 8, 95);
	//right wall of ice-14
	glVertex3d(364, 8, 145);
	glVertex3d(364, -8, 145);
	glVertex3d(420, -8, 145);
	glVertex3d(420, 8, 145);
	//back wall of ice-14
	glVertex3d(420, 8, 145);
	glVertex3d(420, -8, 145);
	glVertex3d(420, -8, 95);
	glVertex3d(420, 8, 95);
	//right wall of ice-15
	glVertex3d(420, 8, 145);
	glVertex3d(420, -8, 145);
	glVertex3d(476, -8, 145);
	glVertex3d(476, 8, 145);
	//back wall of ice-14
	glVertex3d(476, 8, 145);
	glVertex3d(476, -8, 145);
	glVertex3d(476, -8, 95);
	glVertex3d(476, 8, 95);
	//wall between ice-13 and ice-14
	glVertex3d(316, 8, 95);
	glVertex3d(316, -8, 95);
	glVertex3d(374, -8, 95);
	glVertex3d(374, 8, 95);

	glVertex3d(374, 8, 95);
	glVertex3d(374, 4, 95);
	glVertex3d(382, 4, 95);
	glVertex3d(382, 8, 95);


	//wall between ice-14 and ice-15
	glVertex3d(382, 8, 95);
	glVertex3d(382, -8, 95);
	glVertex3d(440, -8, 95);
	glVertex3d(440, 8, 95);

	//door of ice-15
	glVertex3d(440, 8, 95);
	glVertex3d(440, 4, 95);
	glVertex3d(448, 4, 95);
	glVertex3d(448, 8, 95);

	//wall between ice-15 and girls mosque
	glVertex3d(448, 8, 95);
	glVertex3d(448, -8, 95);
	glVertex3d(496, -8, 95);
	glVertex3d(496, 8, 95);

	glVertex3d(448, 8, 145);
	glVertex3d(448, -8, 145);
	glVertex3d(600, -8, 145);
	glVertex3d(600, 8, 145);

	glVertex3d(600, 8, 145);
	glVertex3d(600, -8, 145);
	glVertex3d(600, -8, 50);
	glVertex3d(600, 8, 50);

	glVertex3d(600, 8, 50);
	glVertex3d(600, -8, 50);
	glVertex3d(518, -8, 20);
	glVertex3d(518, 8, 20);

	//mosque door
	glVertex3d(496, 8, 95);
	glVertex3d(496, 4, 95);
	glVertex3d(504, 4, 95);
	glVertex3d(504, 8, 95);

	//wall between mosque and bathrooms
	glVertex3d(504, 8, 95);
	glVertex3d(504, -8, 95);
	glVertex3d(524, -8, 95);
	glVertex3d(524, 8, 95);

	//girls bathroom door
	glVertex3d(524, 8, 95);
	glVertex3d(524, 4, 95);
	glVertex3d(532, 4, 95);
	glVertex3d(532, 8, 95);

	//wall between boys and girls bathroom 
	glVertex3d(532, 8, 95);
	glVertex3d(532, -8, 95);
	glVertex3d(538, -8, 95);
	glVertex3d(538, 8, 95);

	//boys bathroom door
	glVertex3d(538, 8, 95);
	glVertex3d(538, 4, 95);
	glVertex3d(546, 4, 95);
	glVertex3d(546, 8, 95);

	//wall between boys bathroom and boys mosque
	glVertex3d(546, 8, 95);
	glVertex3d(546, -8, 95);
	glVertex3d(556, -8, 95);
	glVertex3d(556, 8, 95);

	glVertex3d(556, 8, 95);
	glVertex3d(556, -8, 95);
	glVertex3d(568, -8, 80);
	glVertex3d(568, 8, 80);

	glVertex3d(568, 8, 80);
	glVertex3d(568, -8, 80);
	glVertex3d(568, -8, 75);
	glVertex3d(568, 8, 75);

	//boys mosque door
	glVertex3d(568, 8, 75);
	glVertex3d(568, 4, 75);
	glVertex3d(568, 4, 67);
	glVertex3d(568, 8, 67);

	glVertex3d(568, 8, 67);
	glVertex3d(568, -8, 67);
	glVertex3d(568, -8, 64);
	glVertex3d(568, 8, 64);

	glVertex3d(568, 8, 64);
	glVertex3d(568, -8, 64);
	glVertex3d(548, -8, 64);
	glVertex3d(548, 8, 64);

	//windows between mosque and ice-16
	glVertex3d(548, 8, 64);
	glVertex3d(548, 4, 64);
	glVertex3d(523, 4, 64);
	glVertex3d(523, 8, 64);

	glVertex3d(548, -4, 64);
	glVertex3d(548, -8, 64);
	glVertex3d(523, -8, 64);
	glVertex3d(523, -4, 64);

	//wall between windows and ice-16
	glVertex3d(523, 8, 64);
	glVertex3d(523, -8, 64);
	glVertex3d(480, -8, 64);
	glVertex3d(480, 8, 64);

	//ice-16 door
	glVertex3d(480, 8, 64);
	glVertex3d(480, 4, 64);
	glVertex3d(472, 4, 64);
	glVertex3d(472, 8, 64);

	glVertex3d(472, 8, 64);
	glVertex3d(472, -8, 64);
	glVertex3d(305, -8, 64);
	glVertex3d(305, 8, 64);

	//ice-16
	glVertex3d(518, 8, 64);
	glVertex3d(518, -8, 64);
	glVertex3d(518, -8, 8);
	glVertex3d(518, 8, 8);

	glVertex3d(518, 8, 8);
	glVertex3d(518, -8, 8);
	glVertex3d(468, -8, 8);
	glVertex3d(468, 8, 8);

	glVertex3d(468, 8, 8);
	glVertex3d(468, -8, 8);
	glVertex3d(468, -8, 64);
	glVertex3d(468, 8, 64);

	//godfather
	glVertex3d(305, 8, -115);
	glVertex3d(305, -8, -115);
	glVertex3d(405, -8, -115);
	glVertex3d(405, 8, -115);

	glVertex3d(405, 8, -115);
	glVertex3d(405, -8, -115);
	glVertex3d(468, -8, -10);
	glVertex3d(468, 8, -10);

	glVertex3d(468, 8, -10);
	glVertex3d(468, -8, -10);
	glVertex3d(468, -8, 8);
	glVertex3d(468, 8, 8);


	//right wall of the godfather
	glVertex3d(305, 8, 64);
	glVertex3d(305, -8, 64);
	glVertex3d(305, -8, -40);
	glVertex3d(305, 8, -40);

	//godfather door      width is 15
	glVertex3d(305, 8, -40);
	glVertex3d(305, 4, -40);
	glVertex3d(305, 4, -55);
	glVertex3d(305, 8, -55);




	//wall between godfather and stairs
	glVertex3d(305, 8, -55);
	glVertex3d(305, -8, -55);
	glVertex3d(305, -8, -125);
	glVertex3d(305, 8, -125);

	//wall behind stairs
	glVertex3d(305, 8, -125);
	glVertex3d(305, -8, -125);
	glVertex3d(285, -8, -125);
	glVertex3d(285, 8, -125);

	glVertex3d(285, 8, -125);
	glVertex3d(285, -8, -125);
	glVertex3d(285, -8, -90);
	glVertex3d(285, 8, -90);

	//main door of IT Department
	glVertex3d(285, 8, -90);
	glVertex3d(285, -8, -90);
	glVertex3d(280, -8, -90);
	glVertex3d(280, 8, -90);
	//width is 15
	glVertex3d(280, 8, -90);
	glVertex3d(280, 4, -90);
	glVertex3d(260, 4, -90);
	glVertex3d(260, 8, -90);

	glVertex3d(260, 8, -90);
	glVertex3d(260, -8, -90);
	glVertex3d(255, -8, -90);
	glVertex3d(255, 8, -90);

	glVertex3d(255, 8, -90);
	glVertex3d(255, -8, -90);
	glVertex3d(255, -8, -40);
	glVertex3d(255, 8, -40);


	glEnd();
	glPopMatrix();


	//locker in main hall
	glPushMatrix();
	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < 3; j++)
		{
			glCallList(7);
			glTranslated(0, 4.5, 0);
		}
		glTranslated(0, -13.5, 4.5);
	}
	glPopMatrix();


	glPushMatrix();
	//glColor3f(0.60, 0.40, 0.12);
	glColor3ub(139, 69, 19);
	glTranslated(300, -8, 10);
	glScaled(1, 0.7, 2);
	glBegin(GL_QUADS);
	glVertex3d(0, 0, -20);
	glVertex3d(0, 20, -20);
	glVertex3d(0, 20, 19);
	glVertex3d(0, 0, 19);
	glVertex3d(2, 0, -20);
	glVertex3d(2, 20, -20);
	glVertex3d(2, 20, 19);
	glVertex3d(2, 0, 19);


	glVertex3d(0, 0, -20);
	glVertex3d(2, 0, -20);
	glVertex3d(2, 20, -20);
	glVertex3d(0, 20, -20);

	glVertex3d(0, 20, -20);
	glVertex3d(2, 20, -20);
	glVertex3d(2, 20, 19);
	glVertex3d(0, 20, -20);


	glVertex3d(0, 0, 19);
	glVertex3d(2, 0, 19);
	glVertex3d(2, 20, 19);
	glVertex3d(0, 20, 19);

	glEnd();
	glPopMatrix();


	//locker in front of ice-13

	glPushMatrix();

	glTranslated(360, 0, 370);
	glRotated(90, 0, 1, 0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 3; j++)
		{
			glCallList(7);
			glTranslated(0, 4.5, 0);
		}
		glTranslated(0, -13.5, 4.5);
	}
	glPopMatrix();

	glPushMatrix(); glColor3ub(139, 69, 19);
	glTranslated(350, -8, 70);
	glScaled(1, 0.7, 2.1);
	glRotated(90, 0, 1, 0);
	glBegin(GL_QUADS);
	glVertex3d(0, 0, -20);
	glVertex3d(0, 20, -20);
	glVertex3d(0, 20, 21);
	glVertex3d(0, 0, 21);
	glVertex3d(2, 0, -20);
	glVertex3d(2, 20, -20);
	glVertex3d(2, 20, 21);
	glVertex3d(2, 0, 21);


	glVertex3d(0, 0, -20);
	glVertex3d(2, 0, -20);
	glVertex3d(2, 20, -20);
	glVertex3d(0, 20, -20);

	glVertex3d(0, 20, -20);
	glVertex3d(2, 20, -20);
	glVertex3d(2, 20, 21);
	glVertex3d(0, 20, -20);


	glVertex3d(0, 0, 21);
	glVertex3d(2, 0, 21);
	glVertex3d(2, 20, 21);
	glVertex3d(0, 20, 21);

	glEnd();
	glPopMatrix();


	///////////////////////////////////////////////////////////////////////////////////////////////////////
	/*
	the left side of the corridor
	ice-06       ice-08     ice-10     ice-12
	i copied the right side and didnt change the comments
	just translated and rotated it.

	*/

	glTranslated(263, 0, -35);
	glRotated(180, 0, 1, 0);
	glPushMatrix();
	glColor3ub(239, 211, 211);

	glBegin(GL_QUADS);

	//the wall right to ice-12 door
	glVertex3d(8, 8, 5);
	glVertex3d(24, 8, 5);
	glVertex3d(24, -8, 5);
	glVertex3d(8, -8, 5);

	//the top wall of ice-12 door
	glVertex3d(24, 8, 5);
	glVertex3d(32, 8, 5);
	glVertex3d(32, 4, 5);
	glVertex3d(24, 4, 5);

	//the wall left to ice-12 door and right to ice-10 door
	glVertex3d(32, 8, 5);
	glVertex3d(90, 8, 5);
	glVertex3d(90, -8, 5);
	glVertex3d(32, -8, 5);

	//the top wall of ice-10 door
	glVertex3d(90, 8, 5);
	glVertex3d(98, 8, 5);
	glVertex3d(98, 4, 5);
	glVertex3d(90, 4, 5);

	//the wall left to ice-10 door and right to ice-8 door
	glVertex3d(98, 8, 5);
	glVertex3d(146, 8, 5);
	glVertex3d(146, -8, 5);
	glVertex3d(98, -8, 5);

	//the top wall of ice-8 door
	glVertex3d(146, 8, 5);
	glVertex3d(154, 8, 5);
	glVertex3d(154, 4, 5);
	glVertex3d(146, 4, 5);

	//the wall left to ice-8 door and right to ice-6 door
	glVertex3d(154, 8, 5);
	glVertex3d(202, 8, 5);
	glVertex3d(202, -8, 5);
	glVertex3d(154, -8, 5);

	//the top wall of ice-6 door
	glVertex3d(202, 8, 5);
	glVertex3d(210, 8, 5);
	glVertex3d(210, 4, 5);
	glVertex3d(202, 4, 5);

	//the wall left to ice-6 door until the end of the corridor
	glVertex3d(210, 8, 5);
	glVertex3d(258, 8, 5);
	glVertex3d(258, -8, 5);
	glVertex3d(210, -8, 5);

	//the back wall of ice-6
	glVertex3d(258, 8, 5);
	glVertex3d(258, -8, 5);
	glVertex3d(258, -8, 55);
	glVertex3d(258, 8, 55);





	/*

	1------4-------6------12
	-      -       -      -
	-      5-------7      -
	-      -       -      -
	-      -       -      -
	-      -       -      -
	-      8-------10     -
	-      -       -      -
	2------3-------9------11


	 We draw each window using this method:

	 draw from 1-->2-->3-->4 (the wall left to the window)
	 then  4-->5-->7-->6     (the wall top to the window)
	 then  8-->3-->9-->10     (the wall under the window)
	 then  6-->9-->11-->12    (the wall right to the window)

	from 1-->4  12cm
	from 4-->6  8cm
	from 6-->12  4cm if there is a window next to it  (OR)  12 cm if it is the last window
	because it will continue to the board wall
	*/


	// ICE-6

	// first window in ice-6
	glVertex3d(258, 8, 55);
	glVertex3d(258, -8, 55);
	glVertex3d(246, -8, 55);
	glVertex3d(246, 8, 55);

	glVertex3d(246, 8, 55);
	glVertex3d(246, 4, 55);
	glVertex3d(238, 4, 55);
	glVertex3d(238, 8, 55);

	glVertex3d(246, -4, 55);
	glVertex3d(246, -8, 55);
	glVertex3d(238, -8, 55);
	glVertex3d(238, -4, 55);

	glVertex3d(238, 8, 55);
	glVertex3d(238, -8, 55);
	glVertex3d(234, -8, 55);
	glVertex3d(234, 8, 55);
	//end

	// second window in ice-6
	glVertex3d(234, 8, 55);
	glVertex3d(234, 4, 55);
	glVertex3d(226, 4, 55);
	glVertex3d(226, 8, 55);

	glVertex3d(234, -4, 55);
	glVertex3d(234, -8, 55);
	glVertex3d(226, -8, 55);
	glVertex3d(226, -4, 55);

	glVertex3d(226, 8, 55);
	glVertex3d(226, -8, 55);
	glVertex3d(222, -8, 55);
	glVertex3d(222, 8, 55);
	//end

	//third window in ice-6
	glVertex3d(222, 8, 55);
	glVertex3d(222, 4, 55);
	glVertex3d(214, 4, 55);
	glVertex3d(214, 8, 55);

	glVertex3d(222, -4, 55);
	glVertex3d(222, -8, 55);
	glVertex3d(214, -8, 55);
	glVertex3d(214, -4, 55);


	glVertex3d(214, 8, 55);
	glVertex3d(214, -8, 55);
	glVertex3d(210, -8, 55);
	glVertex3d(210, 8, 55);

	//end

	// the wall between the board wall and the nearest window
	glVertex3d(210, 8, 55);
	glVertex3d(210, -8, 55);
	glVertex3d(202, -8, 55);
	glVertex3d(202, 8, 55);


	//board wall in ice-6
	glVertex3d(202, 8, 55);
	glVertex3d(202, -8, 55);
	glVertex3d(200, -8, 5);
	glVertex3d(200, 8, 5);
	//we connect between 202 and 200 rather than 202 to leave 2cm between the board wall and the right wall of the door

	//END OF ICE-6

	//ICE-8

	// first window in ice-8
	glVertex3d(202, 8, 55);
	glVertex3d(202, -8, 55);
	glVertex3d(190, -8, 55);
	glVertex3d(190, 8, 55);

	glVertex3d(190, 8, 55);
	glVertex3d(190, 4, 55);
	glVertex3d(182, 4, 55);
	glVertex3d(182, 8, 55);

	glVertex3d(190, -4, 55);
	glVertex3d(190, -8, 55);
	glVertex3d(182, -8, 55);
	glVertex3d(182, -4, 55);

	glVertex3d(182, 8, 55);
	glVertex3d(182, -8, 55);
	glVertex3d(178, -8, 55);
	glVertex3d(178, 8, 55);
	//end

	// second window in ice-8
	glVertex3d(178, 8, 55);
	glVertex3d(178, 4, 55);
	glVertex3d(170, 4, 55);
	glVertex3d(170, 8, 55);

	glVertex3d(178, -4, 55);
	glVertex3d(178, -8, 55);
	glVertex3d(170, -8, 55);
	glVertex3d(170, -4, 55);

	glVertex3d(170, 8, 55);
	glVertex3d(170, -8, 55);
	glVertex3d(166, -8, 55);
	glVertex3d(166, 8, 55);

	//third window in ice-8
	glVertex3d(166, 8, 55);
	glVertex3d(166, 4, 55);
	glVertex3d(158, 4, 55);
	glVertex3d(158, 8, 55);

	glVertex3d(166, -4, 55);
	glVertex3d(166, -8, 55);
	glVertex3d(158, -8, 55);
	glVertex3d(158, -4, 55);

	glVertex3d(158, 8, 55);
	glVertex3d(158, -8, 55);
	glVertex3d(146, -8, 55);
	glVertex3d(146, 8, 55);

	//board wall in ice-8
	glVertex3d(146, 8, 55);
	glVertex3d(146, -8, 55);
	glVertex3d(144, -8, 5);
	glVertex3d(144, 8, 5);

	//END OF ICE-8

	//ICE-10
	//first window
	glVertex3d(146, 8, 55);
	glVertex3d(146, -8, 55);
	glVertex3d(134, -8, 55);
	glVertex3d(134, 8, 55);

	glVertex3d(134, 8, 55);
	glVertex3d(134, 4, 55);
	glVertex3d(126, 4, 55);
	glVertex3d(126, 8, 55);

	glVertex3d(134, -4, 55);
	glVertex3d(134, -8, 55);
	glVertex3d(126, -8, 55);
	glVertex3d(126, -4, 55);

	glVertex3d(126, 8, 55);
	glVertex3d(126, -8, 55);
	glVertex3d(122, -8, 55);
	glVertex3d(122, 8, 55);

	//second window in ice-10
	glVertex3d(122, 8, 55);
	glVertex3d(122, 4, 55);
	glVertex3d(114, 4, 55);
	glVertex3d(114, 8, 55);

	glVertex3d(122, -4, 55);
	glVertex3d(122, -8, 55);
	glVertex3d(114, -8, 55);
	glVertex3d(114, -4, 55);

	glVertex3d(114, 8, 55);
	glVertex3d(114, -8, 55);
	glVertex3d(110, -8, 55);
	glVertex3d(110, 8, 55);

	//third window in ice-10
	glVertex3d(110, 8, 55);
	glVertex3d(110, 4, 55);
	glVertex3d(102, 4, 55);
	glVertex3d(102, 8, 55);

	glVertex3d(110, -4, 55);
	glVertex3d(110, -8, 55);
	glVertex3d(102, -8, 55);
	glVertex3d(102, -4, 55);

	glVertex3d(102, 8, 55);
	glVertex3d(102, -8, 55);
	glVertex3d(90, -8, 55);
	glVertex3d(90, 8, 55);

	//board wall in ice-10
	glVertex3d(90, 8, 55);
	glVertex3d(90, -8, 55);
	glVertex3d(88, -8, 5);
	glVertex3d(88, 8, 5);

	//ICE-12
	//first window
	glVertex3d(90, 8, 55);
	glVertex3d(90, -8, 55);
	glVertex3d(78, -8, 55);
	glVertex3d(78, 8, 55);

	glVertex3d(78, 8, 55);
	glVertex3d(78, 4, 55);
	glVertex3d(70, 4, 55);
	glVertex3d(70, 8, 55);

	glVertex3d(78, -4, 55);
	glVertex3d(78, -8, 55);
	glVertex3d(70, -8, 55);
	glVertex3d(70, -4, 55);

	glVertex3d(70, 8, 55);
	glVertex3d(70, -8, 55);
	glVertex3d(66, -8, 55);
	glVertex3d(66, 8, 55);


	//second window
	glVertex3d(66, 8, 55);
	glVertex3d(66, 4, 55);
	glVertex3d(58, 4, 55);
	glVertex3d(58, 8, 55);

	glVertex3d(66, -4, 55);
	glVertex3d(66, -8, 55);
	glVertex3d(58, -8, 55);
	glVertex3d(58, -4, 55);

	glVertex3d(58, 8, 55);
	glVertex3d(58, -8, 55);
	glVertex3d(54, -8, 55);
	glVertex3d(54, 8, 55);

	//third window 
	glVertex3d(54, 8, 55);
	glVertex3d(54, 4, 55);
	glVertex3d(46, 4, 55);
	glVertex3d(46, 8, 55);

	glVertex3d(54, -4, 55);
	glVertex3d(54, -8, 55);
	glVertex3d(46, -8, 55);
	glVertex3d(46, -4, 55);

	glVertex3d(46, 8, 55);
	glVertex3d(46, -8, 55);
	glVertex3d(24, -8, 55);
	glVertex3d(24, 8, 55);

	//board wall
	glVertex3d(24, 8, 55);
	glVertex3d(24, -8, 55);
	glVertex3d(22, -8, 5);
	glVertex3d(22, 8, 5);

	// end of ice-12

	glEnd();
	glPopMatrix();



	//////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	//\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ SECOND FLOOR ////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////

	// Right side of the corridor
	// rooms are DSL  LC  Arduino  CL-10

			//OBJECTS RIGHT
	{
		glEnable(GL_LIGHT0);
		glPushMatrix();
		glTranslatef(215, 27.5, 40);
		glRotatef(15, 0, 1, 0);
		//the fan
		{

			glPushMatrix();
			glTranslatef(-10.5, 0, 0);
			glRotatef(SPIN, 1, 0, 0);
			glColor3ub(255, 255, 255);
			glRotatef(90, 1, 0, 0);
			glScalef(0, 1, 1);
			gluCylinder(a, 0.05, 0.6, 2, 200, 200);

			for (int i = 0; i < 5; i += 1) {
				glRotatef(72, 1, 0, 0);
				glScalef(0, 1, 1);
				gluCylinder(a, 0.05, 0.6, 2, 200, 200);
			}
			glPopMatrix();



			glPushMatrix();
			glTranslatef(-10.5, 0, 0);
			glRotatef(90, 1, 0, 0);
			glColor3ub(0, 0, 0);
			glScalef(0.4, 1, 1);
			glutWireSphere(2.4, 10, 10);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-10.5, 0, 0);
			glRotatef(90, 1, 0, 0);
			glColor3ub(0, 0, 0);
			gluSphere(a, 0.22, 200, 200);
			glPopMatrix();


			glPushMatrix();
			glTranslatef(-10.5, -2.3, 0);
			glRotatef(90, 1, 0, 0);
			glColor3ub(0, 0, 0);
			glScalef(0.4, 1, 1);
			gluCylinder(a, 0.49, 0.43, 2, 200, 200);
			glPopMatrix();

			glPushMatrix();
			glTranslatef(-10.5, -4, 0);
			glRotatef(90, 0, 1, 0);
			glColor3ub(0, 0, 0);
			glScalef(1, 0.4, 1);
			gluSphere(a, 1, 200, 200);
			glPopMatrix();

		}
		glPopMatrix();
		{
			glPushMatrix();

			//FIRST CLASS
			{
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();

				}
				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();

				}
				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

			}
			glPopMatrix();
			//-------------------//
			glPushMatrix();
			glTranslatef(+60, 0, 0);
			//	SECOND CLASS
			{
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
				glTranslatef(+18, 0, -10);
				for (int i = 0; i < 3; i++)
				{
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
				glTranslatef(+18, 0, -10);
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
				glTranslatef(+18, 0, -10);
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
				glTranslatef(+18, 0, -10);
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
			}
			glPopMatrix();
			//-------------------//
			glPushMatrix();
			//third class
			glTranslatef(+110, 0, 0);
			{
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
				glTranslatef(+18, 0, -10);
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
				glTranslatef(+18, 0, -10);
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
				glTranslatef(+18, 0, -10);
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
				glTranslatef(+18, 0, -10);
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
			}
			glPopMatrix();
			//-------------------//
			glPushMatrix();
			//forth class
			glTranslatef(+162, 0, 0);
			{
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);

					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
				glTranslatef(+18, 0, -10);
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
				glTranslatef(+18, 0, -10);
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
				glTranslatef(+18, 0, -10);
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
				glTranslatef(+18, 0, -10);
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
			}
			glPopMatrix();

			//cooler
			{
				glPushMatrix();
				glTranslated(260, -1, 24);
				glPushMatrix();
				glRotatef(180, 0, 1, 0);
				glPushMatrix();
				glScaled(0.9, 0.7, 0.8);
				glCallList(15);
				glPopMatrix();
				glPopMatrix();
				glPopMatrix();
			}

			//board and trash first class
			{
				//board placment
				glPushMatrix();
				glTranslated(24, 0, 30);
				glScaled(1, 2, 2);
				glCallList(10);
				glPopMatrix();
				// trash
				glPushMatrix();
				glTranslatef(35, -2, 7);
				glCallList(14);
				glPopMatrix();

				//board and trash sec class

				//board placment
				glPushMatrix();
				glTranslated(90, 0, 30);
				glScaled(1, 2, 2);
				glCallList(10);
				glPopMatrix();
				// trash
				glPushMatrix();
				glTranslatef(100, -2, 7);
				glCallList(14);
				glPopMatrix();

				//board and trash third class

				//board placment
				glPushMatrix();
				glTranslated(146, 0, 30);
				glScaled(1, 2, 2);
				glCallList(10);
				glPopMatrix();
				// trash
				glPushMatrix();
				glTranslatef(158, -2, 7);
				glCallList(14);
				glPopMatrix();

				//board and trash forth class

				//board placment
				glPushMatrix();
				glTranslated(202, 0, 30);
				glScaled(1, 2, 2);
				glCallList(10);
				glPopMatrix();
				// trash
				glPushMatrix();
				glTranslatef(213, -2, 7);
				glCallList(14);
				glPopMatrix();
			}
			//pc tables
			{
				//-------------------//
				glPushMatrix();
				glTranslatef(-272, -2.5, 0);
				glPushMatrix();
				glCallList(8);
				glPopMatrix();
				glPopMatrix();
				//-------------------//

				//-------------------//
				glPushMatrix();
				glTranslatef(-205, -2.5, 0);
				glCallList(8);
				glPopMatrix();
				//-------------------//

				//-------------------//
				glPushMatrix();
				glTranslatef(-150, -2.5, 0);
				glCallList(8);
				glPopMatrix();
				//-------------------//

				//-------------------//
				glPushMatrix();
				glTranslatef(-95, -2.5, 0);
				glCallList(8);
				glPopMatrix();
				//-------------------//

			}
			//door placment FIRST CLASS
			{
				glPushMatrix();
				glRotated(-90, 0, 1, 0);
				glTranslated(+5, 0, -29.5);
				glPushMatrix();
				glTranslated(0, 4, -2.5);
				glRotated(c, 0, 1, 0);
				glTranslated(-0, -4, +2.5);
				glCallList(16);
				glPopMatrix();
				glCallList(17);
				glPopMatrix();
			}
			//door placment SEC CLASS
			{
				glPushMatrix();
				glRotated(-90, 0, 1, 0);
				glTranslated(+5, 0, -95.5);
				glPushMatrix();
				glTranslated(0, 4, -2.5);
				glRotated(c, 0, 1, 0);
				glTranslated(-0, -4, +2.5);
				glCallList(16);
				glPopMatrix();
				glCallList(17);
				glPopMatrix();
			}
			//door placment THIRD CLASS
			{
				glPushMatrix();
				glRotated(-90, 0, 1, 0);
				glTranslated(+5, 0, -151.5);
				glPushMatrix();
				glTranslated(0, 4, -2.5);
				glRotated(c, 0, 1, 0);
				glTranslated(-0, -4, +2.5);
				glCallList(16);
				glPopMatrix();
				glCallList(17);
				glPopMatrix();
			}
			//door placment FORTH CLASS
			{
				glPushMatrix();
				glRotated(-90, 0, 1, 0);
				glTranslated(+5, 0, -207.5);
				glPushMatrix();
				glTranslated(0, 4, -2.5);
				glRotated(c, 0, 1, 0);
				glTranslated(-0, -4, +2.5);
				glCallList(16);
				glPopMatrix();
				glCallList(17);
				glPopMatrix();
			}
		}
		//PRACTICAL CHAIR FIRST..sec..third..forth CLASS
		{
			glPushMatrix();
			glTranslated(32, -4.7, 45);
			glRotated(-15, 0, 1, 0);
			glScaled(0.18, 0.18, 0.18);
			glCallList(13);
			glPopMatrix();
			//PRACTICAL CHAIR SEC CLASS
			glPushMatrix();
			glTranslated(98, -4.7, 45);
			glRotated(-15, 0, 1, 0);
			glScaled(0.18, 0.18, 0.18);
			glCallList(13);
			glPopMatrix();
			//PRACTICAL CHAIR THIRD CLASS
			glPushMatrix();
			glTranslated(154, -4.7, 45);
			glRotated(-15, 0, 1, 0);
			glScaled(0.18, 0.18, 0.18);
			glCallList(13);
			glPopMatrix();
			//PRACTICAL CHAIR THIRD CLASS
			glPushMatrix();
			glTranslated(210, -4.7, 45);
			glRotated(-15, 0, 1, 0);
			glScaled(0.18, 0.18, 0.18);
			glCallList(13);
			glPopMatrix();
		}
		//doors of 2
		{
			glPushMatrix();
			glRotated(-90, 0, 1, 0);
			glTranslated(+5, 31, -29.5);
			glPushMatrix();
			glTranslated(0, 4, -2.5);
			glRotated(c, 0, 1, 0);
			glScaled(1, 0.75, 1);
			glTranslated(-0, -4, +2.5);
			glCallList(16);
			glPopMatrix();
			glTranslated(0, 1, 0);
			glScaled(1, 0.75, 1);
			glCallList(17);
			glPopMatrix();
			////////////////////////////
			glPushMatrix();
			glRotated(-90, 0, 1, 0);
			glTranslated(+5, 31, -95.5);
			glPushMatrix();
			glTranslated(0, 4, -2.5);
			glRotated(c, 0, 1, 0);
			glScaled(1, 0.75, 1);
			glTranslated(-0, -4, +2.5);
			glCallList(16);
			glPopMatrix();
			glTranslated(0, 1, 0);
			glScaled(1, 0.75, 1);
			glCallList(17);
			glPopMatrix();
			//////////////////////////
			glPushMatrix();
			glRotated(-90, 0, 1, 0);
			glTranslated(+5, 31, -151.5);
			glPushMatrix();
			glTranslated(0, 4, -2.5);
			glRotated(c, 0, 1, 0);
			glScaled(1, 0.75, 1);
			glTranslated(-0, -4, +2.5);
			glCallList(16);
			glPopMatrix();
			glTranslated(0, 1, 0);
			glScaled(1, 0.75, 1);
			glCallList(17);
			glPopMatrix();
			/////////////////////////
			glPushMatrix();
			glRotated(-90, 0, 1, 0);
			glTranslated(+5, 31, -207.5);
			glPushMatrix();
			glTranslated(0, 4, -2.5);
			glRotated(c, 0, 1, 0);
			glScaled(1, 0.75, 1);
			glTranslated(-0, -4, +2.5);
			glCallList(16);
			glPopMatrix();
			glTranslated(0, 1, 0);
			glScaled(1, 0.75, 1);
			glCallList(17);
			glPopMatrix();
			/////////////////////////
			glPushMatrix();
			glRotated(-90, 0, 1, 0);
			glTranslated(35, 31, 63.6);
			glPushMatrix();
			glTranslated(0, 4, -2.5);
			glRotated(c, 0, 1, 0);
			glScaled(1, 0.75, 1);
			glTranslated(-0, -4, +2.5);
			glCallList(16);
			glPopMatrix();
			glTranslated(0, 1, 0);
			glScaled(1, 0.75, 1);
			glCallList(17);
			glPopMatrix();
		}
		//PRACTICAL CHAIR FIRST..sec..third..forth CLASS..secound floor
		{
			glPushMatrix();
			glTranslated(32, 25.5, 45);
			glRotated(-15, 0, 1, 0);
			glScaled(0.18, 0.18, 0.18);
			glCallList(13);
			glPopMatrix();
			//PRACTICAL CHAIR SEC CLASS
			glPushMatrix();
			glTranslated(98, 25.5, 45);
			glRotated(-15, 0, 1, 0);
			glScaled(0.18, 0.18, 0.18);
			glCallList(13);
			glPopMatrix();
			//PRACTICAL CHAIR THIRD CLASS
			glPushMatrix();
			glTranslated(154, 25.5, 45);
			glRotated(-15, 0, 1, 0);
			glScaled(0.18, 0.18, 0.18);
			glCallList(13);
			glPopMatrix();
			//PRACTICAL CHAIR THIRD CLASS
			glPushMatrix();
			glTranslated(210, 25.5, 45);
			glRotated(-15, 0, 1, 0);
			glScaled(0.18, 0.18, 0.18);
			glCallList(13);
			glPopMatrix();
		}
		//pc tables..secound floor
		{
			//-------------------//
			glPushMatrix();
			glTranslatef(-272, 27.5, 0);
			glPushMatrix();
			glCallList(8);
			glPopMatrix();
			glPopMatrix();
			//-------------------//

			//-------------------//
			glPushMatrix();
			glTranslatef(-205, 27.5, 0);
			glCallList(8);
			glPopMatrix();
			//-------------------//

			//-------------------//
			glPushMatrix();
			glTranslatef(-150, 27.5, 0);
			glCallList(8);
			glPopMatrix();
			//-------------------//

			//-------------------//
			glPushMatrix();
			glTranslatef(-95, 27.5, 0);
			glCallList(8);
			glPopMatrix();
			//-------------------//

		}
		//tables for students practical fir
		{
			//right
			glPushMatrix();
			{
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				///////////////////////////	
				glPushMatrix();
				glTranslated(6, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 2, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 3, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 4, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 5, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
			}
			glPopMatrix();
			//between
			glPushMatrix();
			glRotated(90, 0, 1, 0);
			glTranslated(-28, 0, +23);
			glPushMatrix();
			glTranslated(-60, 0, 12);
			{
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				///////////////////////////	
				glPushMatrix();
				glTranslated(6, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 2, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 3, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
			}
			glPopMatrix();
			glPopMatrix();
			//left
			glPushMatrix();
			glRotated(180, 0, 1, 0);
			glTranslated(-70, 0, -70);
			glPushMatrix();
			glTranslated(-60, 0, 12);
			{
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				///////////////////////////	
				glPushMatrix();
				glTranslated(6, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 2, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 3, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 4, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 5, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
			}
			glPopMatrix();
			glPopMatrix();
		}
		//tables for students practical sec
		glPushMatrix();
		glTranslated(56, 0, 0);
		{
			//right
			glPushMatrix();
			{
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				///////////////////////////	
				glPushMatrix();
				glTranslated(6, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 2, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 3, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 4, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 5, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
			}
			glPopMatrix();
			//between
			glPushMatrix();
			glRotated(90, 0, 1, 0);
			glTranslated(-28, 0, +23);
			glPushMatrix();
			glTranslated(-60, 0, 12);
			{
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				///////////////////////////	
				glPushMatrix();
				glTranslated(6, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 2, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 3, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
			}
			glPopMatrix();
			glPopMatrix();
			//left
			glPushMatrix();
			glRotated(180, 0, 1, 0);
			glTranslated(-70, 0, -70);
			glPushMatrix();
			glTranslated(-60, 0, 12);
			{
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				///////////////////////////	
				glPushMatrix();
				glTranslated(6, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 2, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 3, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 4, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 5, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
			}
			glPopMatrix();
			glPopMatrix();

		}
		glPopMatrix();
		glPushMatrix();
		glTranslated(56 * 2, 0, 0);
		{
			//right
			glPushMatrix();
			{
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				///////////////////////////	
				glPushMatrix();
				glTranslated(6, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 2, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 3, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 4, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 5, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
			}
			glPopMatrix();
			//between
			glPushMatrix();
			glRotated(90, 0, 1, 0);
			glTranslated(-28, 0, +23);
			glPushMatrix();
			glTranslated(-60, 0, 12);
			{
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				///////////////////////////	
				glPushMatrix();
				glTranslated(6, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 2, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 3, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
			}
			glPopMatrix();
			glPopMatrix();
			//left
			glPushMatrix();
			glRotated(180, 0, 1, 0);
			glTranslated(-70, 0, -70);
			glPushMatrix();
			glTranslated(-60, 0, 12);
			{
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				///////////////////////////	
				glPushMatrix();
				glTranslated(6, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 2, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 3, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 4, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 5, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
			}
			glPopMatrix();
			glPopMatrix();

		}
		glPopMatrix();
		glPushMatrix();
		glTranslated(56 * 3, 0, 0);
		{
			//right
			glPushMatrix();
			{
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				///////////////////////////	
				glPushMatrix();
				glTranslated(6, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 2, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 3, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 4, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 5, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
			}
			glPopMatrix();
			//between
			glPushMatrix();
			glRotated(90, 0, 1, 0);
			glTranslated(-28, 0, +23);
			glPushMatrix();
			glTranslated(-60, 0, 12);
			{
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				///////////////////////////	
				glPushMatrix();
				glTranslated(6, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 2, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 3, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
			}
			glPopMatrix();
			glPopMatrix();
			//left
			glPushMatrix();
			glRotated(180, 0, 1, 0);
			glTranslated(-70, 0, -70);
			glPushMatrix();
			glTranslated(-60, 0, 12);
			{
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				///////////////////////////	
				glPushMatrix();
				glTranslated(6, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 2, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 3, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 4, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
				glPushMatrix();
				glTranslated(6 * 5, 0, 0);
				glPushMatrix();
				glTranslatef(-252, 27.5, 0);
				glCallList(100);
				glPopMatrix();
				/////////-----------////////
				glPushMatrix();
				glTranslated(50, 25.5, 45);
				glScaled(0.16, 0.16, 0.16);
				glCallList(13);
				glPopMatrix();
				glPopMatrix();
				///////////////////////////
			}
			glPopMatrix();
			glPopMatrix();

		}
		glPopMatrix();

		//board and trash first class
		{
			//board placment
			glPushMatrix();
			glTranslated(24, 31, 30);
			glScaled(1, 2, 2);
			glCallList(10);
			glPopMatrix();
			// trash
			glPushMatrix();
			glTranslatef(35, 29, 7);
			glCallList(14);
			glPopMatrix();

			//board and trash sec class

			//board placment
			glPushMatrix();
			glTranslated(90, 31, 30);
			glScaled(1, 2, 2);
			glCallList(10);
			glPopMatrix();
			// trash
			glPushMatrix();
			glTranslatef(100, 29, 7);
			glCallList(14);
			glPopMatrix();

			//board and trash third class

			//board placment
			glPushMatrix();
			glTranslated(146, 31, 30);
			glScaled(1, 2, 2);
			glCallList(10);
			glPopMatrix();
			// trash
			glPushMatrix();
			glTranslatef(158, 29, 7);
			glCallList(14);
			glPopMatrix();

			//board and trash forth class

			//board placment
			glPushMatrix();
			glTranslated(202, 31, 30);
			glScaled(1, 2, 2);
			glCallList(10);
			glPopMatrix();
			// trash
			glPushMatrix();
			glTranslatef(213, 29, 7);
			glCallList(14);
			glPopMatrix();
		}
		glDisable(GL_LIGHT0);
	}

	//OBJECTS Left
	{
		glEnable(GL_LIGHT0);
		glPushMatrix();
		glTranslated(263, 0, -35);
		glRotated(180, 0, 1, 0);
		{
			glPushMatrix();
			//FIRST CLASS
			{
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();

				}
				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();

				}
				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

			}
			glPopMatrix();
			//-------------------//
			glPushMatrix();
			glTranslatef(+60, 0, 0);
			//	SECOND CLASS
			{
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
				glTranslatef(+18, 0, -10);
				for (int i = 0; i < 3; i++)
				{
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
				glTranslatef(+18, 0, -10);
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
				glTranslatef(+18, 0, -10);
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
				glTranslatef(+18, 0, -10);
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
			}
			glPopMatrix();
			//-------------------//
			glPushMatrix();
			//third class
			glTranslatef(+110, 0, 0);
			{
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
				glTranslatef(+18, 0, -10);
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
				glTranslatef(+18, 0, -10);
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
				glTranslatef(+18, 0, -10);
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
				glTranslatef(+18, 0, -10);
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
			}
			glPopMatrix();
			//-------------------//
			glPushMatrix();
			//forth class
			glTranslatef(+160, 0, 0);
			{
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);

					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
				glTranslatef(+18, 0, -10);
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
				glTranslatef(+18, 0, -10);
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
				glTranslatef(+18, 0, -10);
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
				glTranslatef(+18, 0, -10);
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}
			}
			glPopMatrix();
			//board and trash first class
			{
				//board placment
				glPushMatrix();
				glTranslated(24, 0, 30);
				glScaled(1, 2, 2);
				glCallList(10);
				glPopMatrix();
				// trash
				glPushMatrix();
				glTranslatef(35, -2, 7);
				glCallList(14);
				glPopMatrix();

				//board and trash sec class

				//board placment
				glPushMatrix();
				glTranslated(90, 0, 30);
				glScaled(1, 2, 2);
				glCallList(10);
				glPopMatrix();
				// trash
				glPushMatrix();
				glTranslatef(100, -2, 7);
				glCallList(14);
				glPopMatrix();

				//board and trash third class

				//board placment
				glPushMatrix();
				glTranslated(146, 0, 30);
				glScaled(1, 2, 2);
				glCallList(10);
				glPopMatrix();
				// trash
				glPushMatrix();
				glTranslatef(158, -2, 7);
				glCallList(14);
				glPopMatrix();

				//board and trash forth class

				//board placment
				glPushMatrix();
				glTranslated(202, 0, 30);
				glScaled(1, 2, 2);
				glCallList(10);
				glPopMatrix();
				// trash
				glPushMatrix();
				glTranslatef(213, -2, 7);
				glCallList(14);
				glPopMatrix();
			}
			//pc tables
			{
				//-------------------//
				glPushMatrix();
				glTranslatef(-272, -2.5, 0);
				glCallList(8);
				glPopMatrix();
				//-------------------//

				//-------------------//
				glPushMatrix();
				glTranslatef(-205, -2.5, 0);
				glCallList(8);
				glPopMatrix();
				//-------------------//

				//-------------------//
				glPushMatrix();
				glTranslatef(-150, -2.5, 0);
				glCallList(8);
				glPopMatrix();
				//-------------------//

				//-------------------//
				glPushMatrix();
				glTranslatef(-95, -2.5, 0);
				glCallList(8);
				glPopMatrix();
				//-------------------//

			}
			//door placment FIRST CLASS
			{
				glPushMatrix();
				glRotated(-90, 0, 1, 0);
				glTranslated(+5, 0, -29.5);
				glPushMatrix();
				glTranslated(0, 4, -2.5);
				glRotated(c, 0, 1, 0);
				glTranslated(-0, -4, +2.5);
				glCallList(16);
				glPopMatrix();
				glCallList(17);
				glPopMatrix();
			}
			//door placment SEC CLASS
			{
				glPushMatrix();
				glRotated(-90, 0, 1, 0);
				glTranslated(+5, 0, -95.5);
				glPushMatrix();
				glTranslated(0, 4, -2.5);
				glRotated(c, 0, 1, 0);
				glTranslated(-0, -4, +2.5);
				glCallList(16);
				glPopMatrix();
				glCallList(17);
				glPopMatrix();
			}
			//door placment THIRD CLASS
			{
				glPushMatrix();
				glRotated(-90, 0, 1, 0);
				glTranslated(+5, 0, -151.5);
				glPushMatrix();
				glTranslated(0, 4, -2.5);
				glRotated(c, 0, 1, 0);
				glTranslated(-0, -4, +2.5);
				glCallList(16);
				glPopMatrix();
				glCallList(17);
				glPopMatrix();
			}
			//door placment FORTH CLASS
			{
				glPushMatrix();
				glRotated(-90, 0, 1, 0);
				glTranslated(+5, 0, -207.5);
				glPushMatrix();
				glTranslated(0, 4, -2.5);
				glRotated(c, 0, 1, 0);
				glTranslated(-0, -4, +2.5);
				glCallList(16);
				glPopMatrix();
				glCallList(17);
				glPopMatrix();
			}
			//PRACTICAL CHAIR FIRST..sec..third..forth CLASS
			{
				glPushMatrix();
				glTranslated(32, -4.7, 45);
				glRotated(-15, 0, 1, 0);
				glScaled(0.18, 0.18, 0.18);
				glCallList(13);
				glPopMatrix();
				//PRACTICAL CHAIR SEC CLASS
				glPushMatrix();
				glTranslated(98, -4.7, 45);
				glRotated(-15, 0, 1, 0);
				glScaled(0.18, 0.18, 0.18);
				glCallList(13);
				glPopMatrix();
				//PRACTICAL CHAIR THIRD CLASS
				glPushMatrix();
				glTranslated(154, -4.7, 45);
				glRotated(-15, 0, 1, 0);
				glScaled(0.18, 0.18, 0.18);
				glCallList(13);
				glPopMatrix();
				//PRACTICAL CHAIR THIRD CLASS
				glPushMatrix();
				glTranslated(210, -4.7, 45);
				glRotated(-15, 0, 1, 0);
				glScaled(0.18, 0.18, 0.18);
				glCallList(13);
				glPopMatrix();
			}
			//doors of 2
			{
				glPushMatrix();
				glRotated(-90, 0, 1, 0);
				glTranslated(+5, 31, -29.5);
				glPushMatrix();
				glTranslated(0, 4, -2.5);
				glRotated(c, 0, 1, 0);
				glScaled(1, 0.75, 1);
				glTranslated(-0, -4, +2.5);
				glCallList(16);
				glPopMatrix();
				glTranslated(0, 1, 0);
				glScaled(1, 0.75, 1);
				glCallList(17);
				glPopMatrix();
				////////////////////////////
				glPushMatrix();
				glRotated(-90, 0, 1, 0);
				glTranslated(+5, 31, -95.5);
				glPushMatrix();
				glTranslated(0, 4, -2.5);
				glRotated(c, 0, 1, 0);
				glScaled(1, 0.75, 1);
				glTranslated(-0, -4, +2.5);
				glCallList(16);
				glPopMatrix();
				glTranslated(0, 1, 0);
				glScaled(1, 0.75, 1);
				glCallList(17);
				glPopMatrix();
				//////////////////////////
				glPushMatrix();
				glRotated(-90, 0, 1, 0);
				glTranslated(+5, 31, -151.5);
				glPushMatrix();
				glTranslated(0, 4, -2.5);
				glRotated(c, 0, 1, 0);
				glScaled(1, 0.75, 1);
				glTranslated(-0, -4, +2.5);
				glCallList(16);
				glPopMatrix();
				glTranslated(0, 1, 0);
				glScaled(1, 0.75, 1);
				glCallList(17);
				glPopMatrix();
				/////////////////////////
				glPushMatrix();
				glRotated(-90, 0, 1, 0);
				glTranslated(+5, 31, -207.5);
				glPushMatrix();
				glTranslated(0, 4, -2.5);
				glRotated(c, 0, 1, 0);
				glScaled(1, 0.75, 1);
				glTranslated(-0, -4, +2.5);
				glCallList(16);
				glPopMatrix();
				glTranslated(0, 1, 0);
				glScaled(1, 0.75, 1);
				glCallList(17);
				glPopMatrix();
				/////////////////////////
			}
			//PRACTICAL CHAIR FIRST..sec..third..forth CLASS..secound floor
			{
				glPushMatrix();
				glTranslated(32, 25.5, 45);
				glRotated(-15, 0, 1, 0);
				glScaled(0.18, 0.18, 0.18);
				glCallList(13);
				glPopMatrix();
				//PRACTICAL CHAIR SEC CLASS
				glPushMatrix();
				glTranslated(98, 25.5, 45);
				glRotated(-15, 0, 1, 0);
				glScaled(0.18, 0.18, 0.18);
				glCallList(13);
				glPopMatrix();
				//PRACTICAL CHAIR THIRD CLASS
				glPushMatrix();
				glTranslated(154, 25.5, 45);
				glRotated(-15, 0, 1, 0);
				glScaled(0.18, 0.18, 0.18);
				glCallList(13);
				glPopMatrix();
				//PRACTICAL CHAIR THIRD CLASS
				glPushMatrix();
				glTranslated(210, 25.5, 45);
				glRotated(-15, 0, 1, 0);
				glScaled(0.18, 0.18, 0.18);
				glCallList(13);
				glPopMatrix();
			}
			//pc tables..secound floor
			{
				//-------------------//
				glPushMatrix();
				glTranslatef(-272, 27.5, 0);
				glPushMatrix();
				glCallList(8);
				glPopMatrix();
				glPopMatrix();
				//-------------------//

				//-------------------//
				glPushMatrix();
				glTranslatef(-205, 27.5, 0);
				glCallList(8);
				glPopMatrix();
				//-------------------//

				//-------------------//
				glPushMatrix();
				glTranslatef(-150, 27.5, 0);
				glCallList(8);
				glPopMatrix();
				//-------------------//

				//-------------------//
				glPushMatrix();
				glTranslatef(-95, 27.5, 0);
				glCallList(8);
				glPopMatrix();
				//-------------------//

			}
			//tables for students practical fir
			{
				//right
				glPushMatrix();
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 4, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 5, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				//between
				glPushMatrix();
				glRotated(90, 0, 1, 0);
				glTranslated(-28, 0, +23);
				glPushMatrix();
				glTranslated(-60, 0, 12);
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				glPopMatrix();
				//left
				glPushMatrix();
				glRotated(180, 0, 1, 0);
				glTranslated(-70, 0, -70);
				glPushMatrix();
				glTranslated(-60, 0, 12);
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 4, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 5, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				glPopMatrix();
			}
			glPushMatrix();
			glTranslated(275, 0, 90);
			{
				//right
				glPushMatrix();
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 4, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 5, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				//between
				glPushMatrix();
				glRotated(90, 0, 1, 0);
				glTranslated(-28, 0, +23);
				glPushMatrix();
				glTranslated(-60, 0, 12);
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				glPopMatrix();
				//left
				glPushMatrix();
				glRotated(180, 0, 1, 0);
				glTranslated(-70, 0, -70);
				glPushMatrix();
				glTranslated(-60, 0, 12);
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 4, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 5, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				glPopMatrix();

			}
			glPopMatrix();
			glPushMatrix();
			glTranslated(328, 0, 90);
			{
				//right
				glPushMatrix();
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 4, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 5, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				//between
				glPushMatrix();
				glRotated(90, 0, 1, 0);
				glTranslated(-28, 0, +23);
				glPushMatrix();
				glTranslated(-60, 0, 12);
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				glPopMatrix();
				//left
				glPushMatrix();
				glRotated(180, 0, 1, 0);
				glTranslated(-70, 0, -70);
				glPushMatrix();
				glTranslated(-60, 0, 12);
				{
					glPushMatrix();
					glTranslated(-20, 0, 00);
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 4., 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 5, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPopMatrix();
				}
				glPopMatrix();
				glPopMatrix();

			}
			glPopMatrix();
			glPushMatrix();
			glTranslated(388, 0, 92);
			{
				//right
				glPushMatrix();
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 4, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 5, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				//between
				glPushMatrix();
				glRotated(90, 0, 1, 0);
				glTranslated(-28, 0, +23);
				glPushMatrix();
				glTranslated(-60, 0, 12);
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				glPopMatrix();
				//left
				glPushMatrix();
				glRotated(180, 0, 1, 0);
				glTranslated(-70, 0, -70);
				glPushMatrix();
				glTranslated(-60, 0, 12);
				{
					glPushMatrix();
					glTranslated(-20, 0, 00);
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 4., 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 5, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPopMatrix();
				}
				glPopMatrix();
				glPopMatrix();

			}
			glPopMatrix();
			//tables for students practical sec..third..forth
			glPushMatrix();
			glTranslated(56, 0, 0);
			{
				//right
				glPushMatrix();
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 4, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 5, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				//between
				glPushMatrix();
				glRotated(90, 0, 1, 0);
				glTranslated(-28, 0, +23);
				glPushMatrix();
				glTranslated(-60, 0, 12);
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				glPopMatrix();
				//left
				glPushMatrix();
				glRotated(180, 0, 1, 0);
				glTranslated(-70, 0, -70);
				glPushMatrix();
				glTranslated(-60, 0, 12);
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 4, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 5, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				glPopMatrix();

			}
			glPopMatrix();
			//////////////////////////////////
			glPushMatrix();
			glTranslated(56 * 2, 0, 0);
			{
				//right
				glPushMatrix();
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 4, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 5, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				//between
				glPushMatrix();
				glRotated(90, 0, 1, 0);
				glTranslated(-28, 0, +23);
				glPushMatrix();
				glTranslated(-60, 0, 12);
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				glPopMatrix();
				//left
				glPushMatrix();
				glRotated(180, 0, 1, 0);
				glTranslated(-70, 0, -70);
				glPushMatrix();
				glTranslated(-60, 0, 12);
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 4, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 5, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				glPopMatrix();

			}
			glPopMatrix();
			//////////////////////////////////
			glPushMatrix();
			glTranslated(56 * 3, 0, 0);
			{
				//right
				glPushMatrix();
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 4, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 5, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				//between
				glPushMatrix();
				glRotated(90, 0, 1, 0);
				glTranslated(-28, 0, +23);
				glPushMatrix();
				glTranslated(-60, 0, 12);
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				glPopMatrix();
				//left
				glPushMatrix();
				glRotated(180, 0, 1, 0);
				glTranslated(-70, 0, -70);
				glPushMatrix();
				glTranslated(-60, 0, 12);
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 4, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 5, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				glPopMatrix();

			}
			glPopMatrix();
			/////////////////////////////////
		//tables for students practical sec..third..forth
			glPushMatrix();
			glTranslated(-80, 0, +90);
			{
				//right
				glPushMatrix();
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 4, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 5, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				//between
				glPushMatrix();
				glRotated(90, 0, 1, 0);
				glTranslated(-28, 0, +23);
				glPushMatrix();
				glTranslated(-60, 0, 12);
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				glPopMatrix();
				//left
				glPushMatrix();
				glRotated(180, 0, 1, 0);
				glTranslated(-70, 0, -70);
				glPushMatrix();
				glTranslated(-60, 0, 12);
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 4, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 5, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				glPopMatrix();

			}
			glPopMatrix();
			///////////////////////
			glPushMatrix();
			glTranslated(-138, 0, +90);
			{
				//right
				glPushMatrix();
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 4, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 5, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				//between
				glPushMatrix();
				glRotated(90, 0, 1, 0);
				glTranslated(-28, 0, +23);
				glPushMatrix();
				glTranslated(-60, 0, 12);
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				glPopMatrix();
				//left
				glPushMatrix();
				glRotated(180, 0, 1, 0);
				glTranslated(-70, 0, -70);
				glPushMatrix();
				glTranslated(-60, 0, 12);
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 4, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 5, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				glPopMatrix();

			}
			glPopMatrix();
			//////////////////////
			glPushMatrix();
			glTranslated(-194, 0, +90);
			{
				//right
				glPushMatrix();
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 4, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 5, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				//between
				glPushMatrix();
				glRotated(90, 0, 1, 0);
				glTranslated(-28, 0, +23);
				glPushMatrix();
				glTranslated(-60, 0, 12);
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				glPopMatrix();
				//left
				glPushMatrix();
				glRotated(180, 0, 1, 0);
				glTranslated(-70, 0, -70);
				glPushMatrix();
				glTranslated(-60, 0, 12);
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 4, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 5, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				glPopMatrix();

			}
			glPopMatrix();
			//////////////////////
			glPushMatrix();
			glTranslated(-250, 0, +90);
			{
				//right
				glPushMatrix();
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 4, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 5, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				//between
				glPushMatrix();
				glRotated(90, 0, 1, 0);
				glTranslated(-28, 0, +23);
				glPushMatrix();
				glTranslated(-60, 0, 12);
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				glPopMatrix();
				//left
				glPushMatrix();
				glRotated(180, 0, 1, 0);
				glTranslated(-70, 0, -70);
				glPushMatrix();
				glTranslated(-60, 0, 12);
				{
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					///////////////////////////	
					glPushMatrix();
					glTranslated(6, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 2, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 3, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 4, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
					glPushMatrix();
					glTranslated(6 * 5, 0, 0);
					glPushMatrix();
					glTranslatef(-252, 27.5, 0);
					glCallList(100);
					glPopMatrix();
					/////////-----------////////
					glPushMatrix();
					glTranslated(50, 25.5, 45);
					glScaled(0.16, 0.16, 0.16);
					glCallList(13);
					glPopMatrix();
					glPopMatrix();
					///////////////////////////
				}
				glPopMatrix();
				glPopMatrix();

			}
			glPopMatrix();
			//////////////////////
			//board and trash first class
			{
				//board placment
				glPushMatrix();
				glTranslated(24, 31, 30);
				glScaled(1, 2, 2);
				glCallList(10);
				glPopMatrix();
				// trash
				glPushMatrix();
				glTranslatef(35, 29, 7);
				glCallList(14);
				glPopMatrix();

				//board and trash sec class

				//board placment
				glPushMatrix();
				glTranslated(90, 31, 30);
				glScaled(1, 2, 2);
				glCallList(10);
				glPopMatrix();
				// trash
				glPushMatrix();
				glTranslatef(100, 29, 7);
				glCallList(14);
				glPopMatrix();

				//board and trash third class

				//board placment
				glPushMatrix();
				glTranslated(146, 31, 30);
				glScaled(1, 2, 2);
				glCallList(10);
				glPopMatrix();
				// trash
				glPushMatrix();
				glTranslatef(158, 29, 7);
				glCallList(14);
				glPopMatrix();

				//board and trash forth class

				//board placment
				glPushMatrix();
				glTranslated(202, 31, 30);
				glScaled(1, 2, 2);
				glCallList(10);
				glPopMatrix();
				// trash
				glPushMatrix();
				glTranslatef(213, 29, 7);
				glCallList(14);
				glPopMatrix();
			}
		}
		glPopMatrix();
		glDisable(GL_LIGHT0);
	}
	//cl-04
	{
		glEnable(GL_LIGHT0);
		glPushMatrix();
		glTranslated(335, 0, -122);
		glRotated(180, 0, 1, 0);
		{
			glPushMatrix();
			//FIRST CLASS
			{
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();

				}
				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();

				}
				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

			}
			glPopMatrix();

			//board and trash first class
			{
				//board placment
				glPushMatrix();
				glTranslated(24, 0, 30);
				glScaled(1, 2, 2);
				glCallList(10);
				glPopMatrix();
				// trash
				glPushMatrix();
				glTranslatef(35, -2, 7);
				glCallList(14);
				glPopMatrix();

				//board placment
				glPushMatrix();
				glTranslated(24, 30.5, 30);
				glScaled(1, 2, 2);
				glCallList(10);
				glPopMatrix();
				// trash
				glPushMatrix();
				glTranslatef(35, 28.5, 7);
				glCallList(14);
				glPopMatrix();
			}
			//pc tables
			{
				//-------------------//
				glPushMatrix();
				glTranslatef(-272, -2.5, 0);
				glCallList(8);
				glPopMatrix();
				glPushMatrix();
				glTranslatef(-272, 28.5, 0);
				glCallList(8);
				glPopMatrix();
				//-------------------//
				glPushMatrix();
				glTranslatef(85, -2.5, 3);
				glCallList(8);
				glPopMatrix();
			}
			//door placment Cl-04 CLASS
			{
				glPushMatrix();
				glRotated(-90, 0, 1, 0);
				glTranslated(+5, 0, -29.5);
				glPushMatrix();
				glTranslated(0, 4, -2.5);
				glRotated(c, 0, 1, 0);
				glTranslated(-0, -4, +2.5);
				glCallList(16);
				glPopMatrix();
				glCallList(17);
				glPopMatrix();
			}
			/////////////////////////
			glPushMatrix();
			glRotated(-90, 0, 1, 0);
			glTranslated(+5, 31, -29.5);
			glPushMatrix();
			glTranslated(0, 4, -2.5);
			glRotated(c, 0, 1, 0);
			glScaled(1, 0.75, 1);
			glTranslated(-0, -4, +2.5);
			glCallList(16);
			glPopMatrix();
			glTranslated(0, 1, 0);
			glScaled(1, 0.75, 1);
			glCallList(17);
			glPopMatrix();
			//PRACTICAL CHAIR FIRST..sec..third..forth CLASS
			{
				glPushMatrix();
				glTranslated(32, -4.7, 45);
				glRotated(-15, 0, 1, 0);
				glScaled(0.18, 0.18, 0.18);
				glCallList(13);
				glPopMatrix();
			}
		}
		glPopMatrix();
	}
	//cl-03
	{
		glPushMatrix();
		glTranslated(391, 0, -122);
		glRotated(180, 0, 1, 0);
		{
			glPushMatrix();
			//FIRST CLASS
			{
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();

				}
				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();

				}
				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

			}
			glPopMatrix();

			//board and trash first class
			{
				//board placment
				glPushMatrix();
				glTranslated(24, 0, 30);
				glScaled(1, 2, 2);
				glCallList(10);
				glPopMatrix();
				// trash
				glPushMatrix();
				glTranslatef(35, -2, 7);
				glCallList(14);
				glPopMatrix();				//board placment
				glPushMatrix();
				glTranslated(24, 30.5, 30);
				glScaled(1, 2, 2);
				glCallList(10);
				glPopMatrix();
				// trash
				glPushMatrix();
				glTranslatef(35, 28.5, 7);
				glCallList(14);
				glPopMatrix();
			}
			//pc tables
			{
				//-------------------//
				glPushMatrix();
				glTranslatef(-272, -2.5, 0);
				glCallList(8);
				glPopMatrix();				glPushMatrix();
				glTranslatef(-272, 28.5, 0);
				glCallList(8);
				glPopMatrix();
				//-------------------//

			}
			//door placment cl-03 CLASS
			{
				glPushMatrix();
				glRotated(-90, 0, 1, 0);
				glTranslated(+5, 0, -29.5);
				glPushMatrix();
				glTranslated(0, 4, -2.5);
				glRotated(c, 0, 1, 0);
				glTranslated(-0, -4, +2.5);
				glCallList(16);
				glPopMatrix();
				glCallList(17);
				glPopMatrix();
			}
			/////////////////////////
			glPushMatrix();
			glRotated(-90, 0, 1, 0);
			glTranslated(+5, 31, -29.5);
			glPushMatrix();
			glTranslated(0, 4, -2.5);
			glRotated(c, 0, 1, 0);
			glScaled(1, 0.75, 1);
			glTranslated(-0, -4, +2.5);
			glCallList(16);
			glPopMatrix();
			glTranslated(0, 1, 0);
			glScaled(1, 0.75, 1);
			glCallList(17);
			glPopMatrix();
			//PRACTICAL CHAIR FIRST..sec..third..forth CLASS
			{
				glPushMatrix();
				glTranslated(32, -4.7, 45);
				glRotated(-15, 0, 1, 0);
				glScaled(0.18, 0.18, 0.18);
				glCallList(13);
				glPopMatrix();
			}
		}
		glPopMatrix();
	}
	//cl-02
	{
		glPushMatrix();
		glTranslated(447, 0, -122);
		glRotated(180, 0, 1, 0);
		{
			glPushMatrix();
			//FIRST CLASS
			{
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();

				}
				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();

				}
				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

			}
			glPopMatrix();

			//board and trash first class
			{
				//board placment
				glPushMatrix();
				glTranslated(24, 0, 30);
				glScaled(1, 2, 2);
				glCallList(10);
				glPopMatrix();
				// trash
				glPushMatrix();
				glTranslatef(35, -2, 7);
				glCallList(14);
				glPopMatrix();
				//board placment
				glPushMatrix();
				glTranslated(24, 30.5, 30);
				glScaled(1, 2, 2);
				glCallList(10);
				glPopMatrix();
				// trash
				glPushMatrix();
				glTranslatef(35, 28.5, 7);
				glCallList(14);
				glPopMatrix();
			}
			//pc tables
			{
				//-------------------//
				glPushMatrix();
				glTranslatef(-272, -2.5, 0);
				glCallList(8);
				glPopMatrix();				glPushMatrix();
				glTranslatef(-272, 28.5, 0);
				glCallList(8);
				glPopMatrix();
				//-------------------//

			}
			//door placment cl-02 CLASS
			{
				glPushMatrix();
				glRotated(-90, 0, 1, 0);
				glTranslated(+5, 0, -29.5);
				glPushMatrix();
				glTranslated(0, 4, -2.5);
				glRotated(c, 0, 1, 0);
				glTranslated(-0, -4, +2.5);
				glCallList(16);
				glPopMatrix();
				glCallList(17);
				glPopMatrix();
			}
			/////////////////////////
			glPushMatrix();
			glRotated(-90, 0, 1, 0);
			glTranslated(+5, 31, -29.5);
			glPushMatrix();
			glTranslated(0, 4, -2.5);
			glRotated(c, 0, 1, 0);
			glScaled(1, 0.75, 1);
			glTranslated(-0, -4, +2.5);
			glCallList(16);
			glPopMatrix();
			glTranslated(0, 1, 0);
			glScaled(1, 0.75, 1);
			glCallList(17);
			glPopMatrix();
			//PRACTICAL CHAIR FIRST..sec..third..forth CLASS
			{
				glPushMatrix();
				glTranslated(32, -4.7, 45);
				glRotated(-15, 0, 1, 0);
				glScaled(0.18, 0.18, 0.18);
				glCallList(13);
				glPopMatrix();
			}
		}
		glPopMatrix();
	}
	//cl-01
	{
		glPushMatrix();
		glTranslated(513, 0, -122);
		glRotated(180, 0, 1, 0);
		{
			glPushMatrix();
			//FIRST CLASS
			{
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();

				}
				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();

				}
				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

			}
			glPopMatrix();

			//board and trash first class
			{
				//board placment
				glPushMatrix();
				glTranslated(24, 0, 30);
				glScaled(1, 2, 2);
				glCallList(10);
				glPopMatrix();
				// trash
				glPushMatrix();
				glTranslatef(35, -2, 7);
				glCallList(14);
				glPopMatrix();				//board placment
				glPushMatrix();
				glTranslated(24, 30.5, 30);
				glScaled(1, 2, 2);
				glCallList(10);
				glPopMatrix();
				// trash
				glPushMatrix();
				glTranslatef(35, 28.5, 7);
				glCallList(14);
				glPopMatrix();
			}
			//pc tables
			{
				//-------------------//
				glPushMatrix();
				glTranslatef(-272, -2.5, 0);
				glCallList(8);
				glPopMatrix();				glPushMatrix();
				glTranslatef(-272, 28.5, 0);
				glCallList(8);
				glPopMatrix();
				//-------------------//

			}
			//door placment cl-01 CLASS
			{
				glPushMatrix();
				glRotated(-90, 0, 1, 0);
				glTranslated(+5, 0, -29.5);
				glPushMatrix();
				glTranslated(0, 4, -2.5);
				glRotated(c, 0, 1, 0);
				glTranslated(-0, -4, +2.5);
				glCallList(16);
				glPopMatrix();
				glCallList(17);
				glPopMatrix();
			}
			/////////////////////////
			glPushMatrix();
			glRotated(-90, 0, 1, 0);
			glTranslated(+5, 31, -29.5);
			glPushMatrix();
			glTranslated(0, 4, -2.5);
			glRotated(c, 0, 1, 0);
			glScaled(1, 0.75, 1);
			glTranslated(-0, -4, +2.5);
			glCallList(16);
			glPopMatrix();
			glTranslated(0, 1, 0);
			glScaled(1, 0.75, 1);
			glCallList(17);
			glPopMatrix();
			//PRACTICAL CHAIR FIRST..sec..third..forth CLASS
			{
				glPushMatrix();
				glTranslated(32, -4.7, 45);
				glRotated(-15, 0, 1, 0);
				glScaled(0.18, 0.18, 0.18);
				glCallList(13);
				glPopMatrix();
			}
		}
		glPopMatrix();

		glDisable(GL_LIGHT0);
	}
	//cl-017
	{

		glEnable(GL_LIGHT0);
		glPushMatrix();
		glTranslated(248, 0, 50);
		{
			glPushMatrix();
			//FIRST CLASS
			{
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();

				}
				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();

				}
				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

			}
			glPopMatrix();

			//board and trash first class
			{
				//board placment
				glPushMatrix();
				glTranslated(24, 0, 30);
				glScaled(1, 2, 2);
				glCallList(10);
				glPopMatrix();
				// trash
				glPushMatrix();
				glTranslatef(35, -2, 7);
				glCallList(14);
				glPopMatrix();
			}
			//pc tables
			{
				//-------------------//
				glPushMatrix();
				glTranslatef(-272, -2.5, 0);
				glCallList(8);
				glPopMatrix();
				//-------------------//

			}
			//door placment cl-17 CLASS
			{
				glPushMatrix();
				glRotated(-90, 0, 1, 0);
				glTranslated(+5, 0, -29.5);
				glPushMatrix();
				glTranslated(0, 4, -2.5);
				glRotated(c, 0, 1, 0);
				glTranslated(-0, -4, +2.5);
				glCallList(16);
				glPopMatrix();
				glCallList(17);
				glPopMatrix();
				///////////////////////////////
				glPushMatrix();
				glRotated(-90, 0, 1, 0);
				glTranslated(+5, 0, -95.5);
				glPushMatrix();
				glTranslated(0, 4, -2.5);
				glRotated(c, 0, 1, 0);
				glTranslated(-0, -4, +2.5);
				glCallList(16);
				glPopMatrix();
				glCallList(17);
				glPopMatrix();
				//////////////////////////////
				glPushMatrix();
				glRotated(-90, 0, 1, 0);
				glTranslated(+5, 0, -151.5);
				glPushMatrix();
				glTranslated(0, 4, -2.5);
				glRotated(c, 0, 1, 0);
				glTranslated(-0, -4, +2.5);
				glCallList(16);
				glPopMatrix();
				glCallList(17);
				glPopMatrix();
				//////////////////////////////
				glPushMatrix();
				glRotated(-90, 0, 1, 0);
				glTranslated(+5, 0, -207.5);
				glPushMatrix();
				glTranslated(0, 4, -2.5);
				glRotated(c, 0, 1, 0);
				glTranslated(-0, -4, +2.5);
				glCallList(16);
				glPopMatrix();
				glCallList(17);
				glPopMatrix();
			}
			/////////////////////////
			glPushMatrix();
			glRotated(-90, 0, 1, 0);
			glTranslated(+5, 31, -29.5);
			glPushMatrix();
			glTranslated(0, 4, -2.5);
			glRotated(c, 0, 1, 0);
			glScaled(1, 0.75, 1);
			glTranslated(-0, -4, +2.5);
			glCallList(16);
			glPopMatrix();
			glTranslated(0, 1, 0);
			glScaled(1, 0.75, 1);
			glCallList(17);
			glPopMatrix();
			///////////////////////////////
			glPushMatrix();
			glRotated(-90, 0, 1, 0);
			glTranslated(+5, 31, -95.5);
			glPushMatrix();
			glTranslated(0, 4, -2.5);
			glRotated(c, 0, 1, 0);
			glScaled(1, 0.75, 1);
			glTranslated(-0, -4, +2.5);
			glCallList(16);
			glPopMatrix();
			glTranslated(0, 1, 0);
			glScaled(1, 0.75, 1);
			glCallList(17);
			glPopMatrix();
			//////////////////////////////
			glPushMatrix();
			glRotated(-90, 0, 1, 0);
			glTranslated(+5, 31, -151.5);
			glPushMatrix();
			glTranslated(0, 4, -2.5);
			glRotated(c, 0, 1, 0);
			glScaled(1, 0.75, 1);
			glTranslated(-0, -4, +2.5);
			glCallList(16);
			glPopMatrix();
			glTranslated(0, 1, 0);
			glScaled(1, 0.75, 1);
			glCallList(17);
			glPopMatrix();
			//////////////////////////////
			glPushMatrix();
			glRotated(-90, 0, 1, 0);
			glTranslated(+5, 31, -207.5);
			glPushMatrix();
			glTranslated(0, 4, -2.5);
			glRotated(c, 0, 1, 0);
			glScaled(1, 0.75, 1);
			glTranslated(-0, -4, +2.5);
			glCallList(16);
			glPopMatrix();
			glTranslated(0, 1, 0);
			glScaled(1, 0.75, 1);
			glCallList(17);
			glPopMatrix();
			//PRACTICAL CHAIR FIRST..sec..third..forth CLASS
			{
				glPushMatrix();
				glTranslated(32, -4.7, 45);
				glRotated(-15, 0, 1, 0);
				glScaled(0.18, 0.18, 0.18);
				glCallList(13);
				glPopMatrix();
			}
		}
		glPopMatrix();

		glDisable(GL_LIGHT0);
	}
	//cl-013
	{

		glEnable(GL_LIGHT0);
		glPushMatrix();
		glTranslated(-21.5, 0, -125);
		glRotated(180, 0, 1, 0);
		{
			glPushMatrix();
			//FIRST CLASS
			{
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();

				}
				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();

				}
				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

			}
			glPopMatrix();

			//board and trash first class
			{
				//board placment
				glPushMatrix();
				glTranslated(24, 0, 30);
				glScaled(1, 2, 2);
				glCallList(10);
				glPopMatrix();
				// trash
				glPushMatrix();
				glTranslatef(35, -2, 7);
				glCallList(14);
				glPopMatrix();				glPushMatrix();
				glTranslated(24, 30.5, 30);
				glScaled(1, 2, 2);
				glCallList(10);
				glPopMatrix();
				// trash
				glPushMatrix();
				glTranslatef(35, 28.5, 7);
				glCallList(14);
				glPopMatrix();
			}
			//pc tables
			{
				//-------------------//
				glPushMatrix();
				glTranslatef(-272, 28.5, 0);
				glCallList(8);
				glPopMatrix();
				//-------------------//

			}
			//door placment cl-13 CLASS
			{
				glPushMatrix();
				glRotated(-90, 0, 1, 0);
				glTranslated(+5, 0, -29);
				glPushMatrix();
				glTranslated(0, 4, -2.5);
				glRotated(c, 0, 1, 0);
				glTranslated(-0, -4, +2.5);
				glCallList(16);
				glPopMatrix();
				glCallList(17);
				glPopMatrix();
			}
			/////////////////////////
			glPushMatrix();
			glRotated(-90, 0, 1, 0);
			glTranslated(+5, 31, -29);
			glPushMatrix();
			glTranslated(0, 4, -2.5);
			glRotated(c, 0, 1, 0);
			glScaled(1, 0.75, 1);
			glTranslated(-0, -4, +2.5);
			glCallList(16);
			glPopMatrix();
			glTranslated(0, 1, 0);
			glScaled(1, 0.75, 1);
			glCallList(17);
			glPopMatrix();
			//PRACTICAL CHAIR FIRST..sec..third..forth CLASS
			{
				glPushMatrix();
				glTranslated(32, -4.7, 45);
				glRotated(-15, 0, 1, 0);
				glScaled(0.18, 0.18, 0.18);
				glCallList(13);
				glPopMatrix();
			}
		}
		glPopMatrix();
	}
	//cl-014
	{
		glPushMatrix();
		glTranslated(-78.5, 0, -125);
		glRotated(180, 0, 1, 0);
		{
			glPushMatrix();
			//FIRST CLASS
			{
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();

				}
				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();

				}
				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

			}
			glPopMatrix();

			//board and trash first class
			{
				//board placment
				glPushMatrix();
				glTranslated(24, 0, 30);
				glScaled(1, 2, 2);
				glCallList(10);
				glPopMatrix();
				// trash
				glPushMatrix();
				glTranslatef(45, -2, 7);
				glCallList(14);
				glPopMatrix();				//board placment
				glPushMatrix();
				glTranslated(24, 30.5, 30);
				glScaled(1, 2, 2);
				glCallList(10);
				glPopMatrix();
				// trash
				glPushMatrix();
				glTranslatef(45, 28.5, 7);
				glCallList(14);
				glPopMatrix();
			}
			//pc tables
			{
				//-------------------//
				glPushMatrix();
				glTranslatef(-272, -2.5, 0);
				glCallList(8);
				glPopMatrix();				glPushMatrix();
				glTranslatef(-272, 28.5, 0);
				glCallList(8);
				glPopMatrix();
				//-------------------//

			}
			//door placment FIRST CLASS
			{
				glPushMatrix();
				glRotated(-90, 0, 1, 0);
				glTranslated(+5, 0, -38);
				glPushMatrix();
				glTranslated(0, 4, -2.5);
				glRotated(c, 0, 1, 0);
				glTranslated(-0, -4, +2.5);
				glCallList(16);
				glPopMatrix();
				glCallList(17);
				glPopMatrix();
			}
			//PRACTICAL CHAIR FIRST..sec..third..forth CLASS
			{
				glPushMatrix();
				glTranslated(32, -4.7, 45);
				glRotated(-15, 0, 1, 0);
				glScaled(0.18, 0.18, 0.18);
				glCallList(13);
				glPopMatrix();
			}
			/////////////////////////
			glPushMatrix();
			glRotated(-90, 0, 1, 0);
			glTranslated(+5, 31, -38);
			glPushMatrix();
			glTranslated(0, 4, -2.5);
			glRotated(c, 0, 1, 0);
			glScaled(1, 0.75, 1);
			glTranslated(-0, -4, +2.5);
			glCallList(16);
			glPopMatrix();
			glTranslated(0, 1, 0);
			glScaled(1, 0.75, 1);
			glCallList(17);
			glPopMatrix();
		}
		glPopMatrix();
	}
	//cl-015
	{
		glPushMatrix();
		glTranslated(-133.5, 0, -125);
		glRotated(180, 0, 1, 0);
		{
			glPushMatrix();
			//FIRST CLASS
			{
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();

				}
				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();

				}
				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

			}
			glPopMatrix();

			//board and trash first class
			{
				//board placment
				glPushMatrix();
				glTranslated(24, 0, 30);
				glScaled(1, 2, 2);
				glCallList(10);
				glPopMatrix();
				// trash
				glPushMatrix();
				glTranslatef(35, -2, 7);
				glCallList(14);
				glPopMatrix();				glPushMatrix();
				glTranslated(24, 30.5, 30);
				glScaled(1, 2, 2);
				glCallList(10);
				glPopMatrix();
				// trash
				glPushMatrix();
				glTranslatef(35, 28.5, 7);
				glCallList(14);
				glPopMatrix();
			}
			//pc tables
			{
				//-------------------//
				glPushMatrix();
				glTranslatef(-272, -2.5, 0);
				glCallList(8);
				glPopMatrix();
				//-------------------//

			}
			//door placment FIRST CLASS
			{
				glPushMatrix();
				glRotated(-90, 0, 1, 0);
				glTranslated(+5, 0, -49);
				glPushMatrix();
				glTranslated(0, 4, -2.5);
				glRotated(c, 0, 1, 0);
				glTranslated(-0, -4, +2.5);
				glCallList(16);
				glPopMatrix();
				glCallList(17);
				glPopMatrix();
			}
			/////////door 2////////////////
			glPushMatrix();
			glRotated(-90, 0, 1, 0);
			glTranslated(+5, 31, -49);
			glPushMatrix();
			glTranslated(0, 4, -2.5);
			glRotated(c, 0, 1, 0);
			glScaled(1, 0.75, 1);
			glTranslated(-0, -4, +2.5);
			glCallList(16);
			glPopMatrix();
			glTranslated(0, 1, 0);
			glScaled(1, 0.75, 1);
			glCallList(17);
			glPopMatrix();
			//PRACTICAL CHAIR FIRST..sec..third..forth CLASS
			{
				glPushMatrix();
				glTranslated(32, -4.7, 45);
				glRotated(-15, 0, 1, 0);
				glScaled(0.18, 0.18, 0.18);
				glCallList(13);
				glPopMatrix();
			}
		}
		glPopMatrix();
	}
	//cl-016
	{
		glPushMatrix();
		glTranslated(-200, 0, -122.5);
		glRotated(-90, 0, 1, 0);
		{
			glPushMatrix();
			//FIRST CLASS
			{
				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();

				}
				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();

				}
				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

				glTranslatef(+18, 0, -10);

				for (int i = 0; i < 3; i++) {
					glTranslatef(-6, 0, 0);
					glCallList(1);
					glPushMatrix();
					glTranslated(78, -3.1, 50);

					glTranslated(0, 0, -2.1);
					glRotatef(open, 1, 0, 0);
					glTranslated(0, 0, +2);
					glCallList(9);
					glPopMatrix();
				}

			}
			glPopMatrix();

			//board and trash first class
			{
				//board placment
				glPushMatrix();
				glTranslated(24, 0, 30);
				glScaled(1, 2, 2);
				glCallList(10);
				glPopMatrix();
				// trash
				glPushMatrix();
				glTranslatef(35, -2, 7);
				glCallList(14);
				glPopMatrix();
			}
			//pc tables
			{
				//-------------------//
				glPushMatrix();
				glTranslatef(-272, -2.5, 0);
				glCallList(8);
				glPopMatrix();
				//-------------------//

			}
			//door placment FIRST CLASS
			{
				glPushMatrix();
				glTranslated(+23.5, 0, 11.5);
				glPushMatrix();
				glTranslated(0, 4, -2.5);
				glRotated(c, 0, 1, 0);
				glTranslated(-0, -4, +2.5);
				glCallList(16);
				glPopMatrix();
				glCallList(17);
				glPopMatrix();
			}
			/////////////////////////
			glPushMatrix();
			glTranslated(+23.5, 31, 11.5);
			glPushMatrix();
			glTranslated(0, 4, -2.5);
			glRotated(0, 0, 1, 0);
			glScaled(1, 0.75, 1);
			glTranslated(-0, -4, +2.5);
			glCallList(16);
			glPopMatrix();
			glTranslated(0, 1, 0);
			glScaled(1, 0.75, 1);
			glCallList(17);
			glPopMatrix();
			//PRACTICAL CHAIR FIRST..sec..third..forth CLASS
			{
				glPushMatrix();
				glTranslated(32, -4.7, 45);
				glRotated(-15, 0, 1, 0);
				glScaled(0.18, 0.18, 0.18);
				glCallList(13);
				glPopMatrix();
			}
		}
		glPopMatrix();

		glDisable(GL_LIGHT0);
	}
	{

		glEnable(GL_LIGHT0);
		glPushMatrix();
		glTranslatef(-30, 0, -41);

		//godfather tabels
		{
			{
				glPushMatrix();
				glTranslated(-370, 2, 95);
				for (int i = 0; i < 6; i++) {
					glTranslated(-15, 0, 0);

					glCallList(2);
				}

				glPopMatrix();
			}
			{
				glPushMatrix();
				glTranslated(-370, 2, 70);
				for (int i = 0; i < 7; i++) {
					glTranslated(-15, 0, 0);

					glCallList(2);
				}
				glPopMatrix();
			} {
				glPushMatrix();
				glTranslated(-380, 2, 50);
				for (int i = 0; i < 8; i++) {
					glTranslated(-15, 0, 0);
					glColor3ub(i * 10, i * 15, i * 20);
					glCallList(2);
				}
				glPopMatrix();
			}
			{
				glPushMatrix();
				glTranslated(-450, 2, 25);
				for (int i = 0; i < 4; i++) {
					glTranslated(-15, 0, 0);
					glColor3ub(i * 10, i * 15, i * 20);
					glCallList(2);
				}
				glPopMatrix();
			}
			{
				glPushMatrix();
				glTranslated(-489, 2, 4);
				for (int i = 0; i < 2; i++) {
					glTranslated(-15, 0, 0);
					glColor3ub(i * 10, i * 15, i * 20);
					glCallList(2);
				}
				glPopMatrix();
			}
			{
				glPushMatrix();
				glTranslated(-520, 2, -40);
				for (int i = 0; i < 2; i++) {
					glTranslated(-3, 0, 0);
					glColor3ub(i * 10, i * 15, i * 20);
					glCallList(2);
				}
				glPopMatrix();
			}
			{
				glPushMatrix();
				glTranslated(-490, 2, -30);
				for (int i = 0; i < 2; i++) {
					glTranslated(-10, 0, 0);
					glColor3ub(i * 10, i * 15, i * 20);
					glCallList(2);
				}
				glPopMatrix();
			}










		};
		{
			glPushMatrix();
			glTranslated(-450, 2, 10);
			for (int i = 0; i < 3; i++) {
				glTranslated(0, 0, -15);
				glCallList(3);
			}
			glPopMatrix();
		}
		{
			glPushMatrix();
			glTranslated(-447, 2, -42);
			for (int i = 0; i < 2; i++) {
				glTranslated(-15, 0, 0);
				glCallList(4);
			}
			glPopMatrix();
		}
		{
			glPushMatrix();
			glTranslated(-485, 2, -47);
			for (int i = 0; i < 1; i++) {

				glCallList(3);
			}
			glPopMatrix();
		}
		//FIRE
		{
			glPushMatrix();
			glTranslated(-110, 0, 40);
			for (int i = 0; i < 1; i++) {

				glCallList(5);
			}
			glPopMatrix();


		}
		{
			glPushMatrix();
			glTranslated(-390, 0, 30);
			for (int i = 0; i < 2; i++) {
				glTranslated(-30, 0, 0);

				glCallList(6);
			}
			glPopMatrix();


		}
		glPopMatrix();

		glDisable(GL_LIGHT0);
	}
	// doctor room1

	glEnable(GL_LIGHT0);
	glPushMatrix();
	glTranslated(385, -5, 90);
	glScaled(0.14, 0.16, 0.14);
	glCallList(20);
	glPopMatrix();

	glPushMatrix();
	glTranslated(342, -5, 90);
	glPushMatrix();
	glRotated(180, 0, 1, 0);
	glScaled(0.14, 0.16, 0.14);
	glCallList(20);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslated(333, 4, 90);
	glPushMatrix();
	glRotated(90, 0, 1, 0);
	glScaled(0.5, 0.8, 0.5);
	glCallList(21);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslated(394, 4, 88);
	glPushMatrix();
	glRotated(-90, 0, 1, 0);
	glScaled(0.5, 0.8, 0.5);
	glCallList(21);
	glPopMatrix();
	glPopMatrix();

	glPushMatrix();
	glTranslated(345, -1, 97);
	glScaled(2, 2, 2);
	glCallList(22);
	glPopMatrix();

	glDisable(GL_LIGHT0);
	{
		// doctor room2

		glEnable(GL_LIGHT0);
		glPushMatrix();
		glTranslated(60, 0, 0);
		{
			glPushMatrix();
			glTranslated(385, -5, 90);
			glScaled(0.14, 0.16, 0.14);
			glCallList(20);
			glPopMatrix();

			glPushMatrix();
			glTranslated(342, -5, 90);
			glPushMatrix();
			glRotated(180, 0, 1, 0);
			glScaled(0.14, 0.16, 0.14);
			glCallList(20);
			glPopMatrix();
			glPopMatrix();

			glPushMatrix();
			glTranslated(333, 4, 90);
			glPushMatrix();
			glRotated(90, 0, 1, 0);
			glScaled(0.5, 0.8, 0.5);
			glCallList(21);
			glPopMatrix();
			glPopMatrix();

			glPushMatrix();
			glTranslated(394, 4, 88);
			glPushMatrix();
			glRotated(-90, 0, 1, 0);
			glScaled(0.5, 0.8, 0.5);
			glCallList(21);
			glPopMatrix();
			glPopMatrix();
			glPushMatrix();
			glTranslated(345, -1, 97);
			glScaled(2, 2, 2);
			glCallList(22);
			glPopMatrix();

		}
		glPopMatrix();


		glDisable(GL_LIGHT0);
	}
	{

		glEnable(GL_LIGHT0);
		//doctor room3
		glPushMatrix();
		glTranslated(112, 0, 0);
		{
			glPushMatrix();
			glTranslated(385, -5, 90);
			glScaled(0.14, 0.16, 0.14);
			glCallList(20);
			glPopMatrix();

			glPushMatrix();
			glTranslated(342, -5, 90);
			glPushMatrix();
			glRotated(180, 0, 1, 0);
			glScaled(0.14, 0.16, 0.14);
			glCallList(20);
			glPopMatrix();
			glPopMatrix();

			glPushMatrix();
			glTranslated(333, 4, 90);
			glPushMatrix();
			glRotated(90, 0, 1, 0);
			glScaled(0.5, 0.8, 0.5);
			glCallList(21);
			glPopMatrix();
			glPopMatrix();

			glPushMatrix();
			glTranslated(394, 4, 88);
			glPushMatrix();
			glRotated(-90, 0, 1, 0);
			glScaled(0.5, 0.8, 0.5);
			glCallList(21);
			glPopMatrix();
			glPopMatrix();

			glPushMatrix();
			glTranslated(345, -1, 97);
			glScaled(2, 2, 2);
			glCallList(22);
			glPopMatrix();
		}
		glPopMatrix();

		glPushMatrix();
		glTranslated(495, -5, 68);


		glScaled(0.14, 0.16, 0.14);
		glCallList(20);
		glPopMatrix();

		glPushMatrix();
		glTranslated(503, 4, 66);
		glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glScaled(0.5, 0.8, 0.5);
		glCallList(21);
		glPopMatrix();
		glPopMatrix();





		glDisable(GL_LIGHT0);
	}
	{
		// doctor room2

		glEnable(GL_LIGHT0);
		glPushMatrix();
		glTranslated(60, 31, 0);
		{
			glPushMatrix();
			glTranslated(385, -5, 90);
			glScaled(0.14, 0.16, 0.14);
			glCallList(20);
			glPopMatrix();

			glPushMatrix();
			glTranslated(342, -5, 90);
			glPushMatrix();
			glRotated(180, 0, 1, 0);
			glScaled(0.14, 0.16, 0.14);
			glCallList(20);
			glPopMatrix();
			glPopMatrix();

			glPushMatrix();
			glTranslated(333, 4, 90);
			glPushMatrix();
			glRotated(90, 0, 1, 0);
			glScaled(0.5, 0.8, 0.5);
			glCallList(21);
			glPopMatrix();
			glPopMatrix();

			glPushMatrix();
			glTranslated(394, 4, 88);
			glPushMatrix();
			glRotated(-90, 0, 1, 0);
			glScaled(0.5, 0.8, 0.5);
			glCallList(21);
			glPopMatrix();
			glPopMatrix();
			glPushMatrix();
			glTranslated(345, -1, 97);
			glScaled(2, 2, 2);
			glCallList(22);
			glPopMatrix();

		}
		glPopMatrix();


		glDisable(GL_LIGHT0);
	}
	{

		glEnable(GL_LIGHT0);
		//doctor room3
		glPushMatrix();
		glTranslated(112, 31, 0);
		{
			glPushMatrix();
			glTranslated(385, -5, 90);
			glScaled(0.14, 0.16, 0.14);
			glCallList(20);
			glPopMatrix();

			glPushMatrix();
			glTranslated(342, -5, 90);
			glPushMatrix();
			glRotated(180, 0, 1, 0);
			glScaled(0.14, 0.16, 0.14);
			glCallList(20);
			glPopMatrix();
			glPopMatrix();

			glPushMatrix();
			glTranslated(333, 4, 90);
			glPushMatrix();
			glRotated(90, 0, 1, 0);
			glScaled(0.5, 0.8, 0.5);
			glCallList(21);
			glPopMatrix();
			glPopMatrix();

			glPushMatrix();
			glTranslated(394, 4, 88);
			glPushMatrix();
			glRotated(-90, 0, 1, 0);
			glScaled(0.5, 0.8, 0.5);
			glCallList(21);
			glPopMatrix();
			glPopMatrix();

			glPushMatrix();
			glTranslated(345, -1, 97);
			glScaled(2, 2, 2);
			glCallList(22);
			glPopMatrix();
		}
		glPopMatrix();

		glPushMatrix();
		glTranslated(495, 25.2, 68);


		glScaled(0.14, 0.16, 0.14);
		glCallList(20);
		glPopMatrix();

		glPushMatrix();
		glTranslated(503, 34.8, 66);
		glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glScaled(0.5, 0.8, 0.5);
		glCallList(21);
		glPopMatrix();
		glPopMatrix();





		glDisable(GL_LIGHT0);
	}
	{

		glEnable(GL_LIGHT0);
		// mm room
		glPushMatrix();
		glTranslated(0, 31, 0);
		{
			glPushMatrix();
			glTranslated(385, -5, 90);
			glScaled(0.14, 0.16, 0.14);
			glCallList(20);
			glPopMatrix();

			glPushMatrix();
			glTranslated(342, -5, 90);
			glPushMatrix();
			glRotated(180, 0, 1, 0);
			glScaled(0.14, 0.16, 0.14);
			glCallList(20);
			glPopMatrix();
			glPopMatrix();

			glPushMatrix();
			glTranslated(333, 4, 90);
			glPushMatrix();
			glRotated(90, 0, 1, 0);
			glScaled(0.5, 0.8, 0.5);
			glCallList(21);
			glPopMatrix();
			glPopMatrix();

			glPushMatrix();
			glTranslated(394, 4, 88);
			glPushMatrix();
			glRotated(-90, 0, 1, 0);
			glScaled(0.5, 0.8, 0.5);
			glCallList(21);
			glPopMatrix();
			glPopMatrix();
			glPushMatrix();
			glTranslated(345, -1, 97);
			glScaled(2, 2, 2);
			glCallList(22);
			glPopMatrix();

			glPushMatrix();
			glTranslated(384, -1.8, 73);
			glCallList(26);
			glPopMatrix();




		}
		glPopMatrix();
		glPushMatrix();
		glTranslated(390, 25.2, 68);


		glScaled(0.14, 0.16, 0.14);
		glCallList(20);
		glPopMatrix();

		glPushMatrix();
		glTranslated(398, 34.8, 66);
		glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glScaled(0.5, 0.8, 0.5);
		glCallList(21);
		glPopMatrix();
		glPopMatrix();

		glDisable(GL_LIGHT0);

	}
	{

		glEnable(GL_LIGHT0);
		//doctors room 2 floor
		glPushMatrix();
		glTranslated(-505, 31, 0);
		{
			glPushMatrix();
			glTranslated(385, -5, 90);
			glScaled(0.14, 0.16, 0.14);
			glCallList(20);
			glPopMatrix();

			glPushMatrix();
			glTranslated(342, -5, 90);
			glPushMatrix();
			glRotated(180, 0, 1, 0);
			glScaled(0.14, 0.16, 0.14);
			glCallList(20);
			glPopMatrix();
			glPopMatrix();

			glPushMatrix();
			glTranslated(333, 4, 90);
			glPushMatrix();
			glRotated(90, 0, 1, 0);
			glScaled(0.5, 0.8, 0.5);
			glCallList(21);
			glPopMatrix();
			glPopMatrix();

			glPushMatrix();
			glTranslated(394, 4, 88);
			glPushMatrix();
			glRotated(-90, 0, 1, 0);
			glScaled(0.5, 0.8, 0.5);
			glCallList(21);
			glPopMatrix();
			glPopMatrix();
			glPushMatrix();
			glTranslated(345, -1, 97);
			glScaled(2, 2, 2);
			glCallList(22);
			glPopMatrix();

		}
		glPopMatrix();


		glDisable(GL_LIGHT0);
	}
	{

		glEnable(GL_LIGHT0);
		//doctors room 2 floor
		glPushMatrix();
		glTranslated(-515, 31, -50);
		{
			glPushMatrix();
			glTranslated(385, -5, 90);
			glScaled(0.14, 0.16, 0.14);
			glCallList(20);
			glPopMatrix();

			glPushMatrix();
			glTranslated(345, -5, 90);
			glPushMatrix();
			glRotated(180, 0, 1, 0);
			glScaled(0.14, 0.16, 0.14);
			glCallList(20);
			glPopMatrix();
			glPopMatrix();

			glPushMatrix();
			glTranslated(335, 4, 90);
			glPushMatrix();
			glRotated(90, 0, 1, 0);
			glScaled(0.5, 0.8, 0.5);
			glCallList(21);
			glPopMatrix();
			glPopMatrix();

			glPushMatrix();
			glTranslated(395, 4, 88);
			glPushMatrix();
			glRotated(-90, 0, 1, 0);
			glScaled(0.5, 0.8, 0.5);
			glCallList(21);
			glPopMatrix();
			glPopMatrix();
			glPushMatrix();
			glTranslated(345, -1, 97);
			glScaled(2, 2, 2);
			glCallList(22);
			glPopMatrix();

		}
		glPopMatrix();


		glDisable(GL_LIGHT0);
	}

	{

		glEnable(GL_LIGHT0);
		//fayez room
		glPushMatrix();
		glTranslated(220, 31, 380);
		glPushMatrix();
		glRotated(90, 0, 1, 0);
		glScaled(1, 2, 1.2);
		glCallList(23);
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glTranslated(275, 26, 77);
		glPushMatrix();
		glRotated(180, 0, 1, 0);
		glScaled(0.14, 0.16, 0.14);
		glCallList(20);
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glTranslated(-296, 31, -20);
		glScaled(2, 2, 2);
		glCallList(25);
		glPopMatrix();

		glPushMatrix();
		glTranslated(300, 25, 79);
		glPushMatrix();
		glRotated(180, 0, 1, 0);
		glScaled(0.12, 0.12, 0.12);
		glCallList(20);
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glTranslated(304, 25, 75);
		glPushMatrix();
		glRotated(90, 0, 1, 0);
		glScaled(0.12, 0.12, 0.12);
		glCallList(20);
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glTranslated(308, 25, 75);
		glPushMatrix();
		glRotated(90, 0, 1, 0);
		glScaled(0.12, 0.12, 0.12);
		glCallList(20);
		glPopMatrix();
		glPopMatrix();
		glPushMatrix();
		glTranslated(312, 25, 75);
		glPushMatrix();
		glRotated(90, 0, 1, 0);
		glScaled(0.12, 0.12, 0.12);
		glCallList(20);
		glPopMatrix();
		glPopMatrix();
		glPushMatrix();
		glTranslated(319, 25, 78);
		glPushMatrix();
		//glRotated(180, 0, 1, 0);
		glScaled(0.12, 0.12, 0.12);
		glCallList(20);
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glTranslated(312, 25, 86);
		glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glScaled(0.12, 0.12, 0.12);
		glCallList(20);
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glTranslated(308, 25, 86);
		glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glScaled(0.12, 0.12, 0.12);
		glCallList(20);
		glPopMatrix();
		glPopMatrix();


		glPushMatrix();
		glTranslated(304, 25, 86);
		glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glScaled(0.12, 0.12, 0.12);
		glCallList(20);
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glTranslated(284, 25, 81);
		glPushMatrix();
		glRotated(-90, 0, 1, 0);
		glScaled(0.12, 0.12, 0.12);
		glCallList(24);
		glPopMatrix();
		glPopMatrix();

		glPushMatrix();
		glTranslated(284, 25, 73);
		glPushMatrix();
		glRotated(90, 0, 1, 0);
		glScaled(0.12, 0.12, 0.12);
		glCallList(24);
		glPopMatrix();
		glPopMatrix();

	}


	glPushMatrix();
	glTranslated(330, 30, 85);
	glScaled(2, 2, 2);
	glCallList(22);
	glPopMatrix();
	{
		glPushMatrix();
		glTranslated(260, 29, 24);
		glPushMatrix();
		glRotatef(180, 0, 1, 0);
		glPushMatrix();
		glScaled(0.9, 0.7, 0.8);
		glCallList(15);
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();
	}
	{
		glPushMatrix();
		glTranslated(-40, 29, -10);
		glPushMatrix();
		glRotatef(180, 0, 1, 0);
		glPushMatrix();
		glScaled(0.9, 0.7, 0.8);
		glCallList(15);
		glPopMatrix();
		glPopMatrix();
		glPopMatrix();

		glDisable(GL_LIGHT0);
	}
	//FIRE
	{
		glPushMatrix();
		glTranslated(-140, 31, 1.2);
		for (int i = 0; i < 1; i++) {

			glCallList(5);
		}
		glPopMatrix();


	}



	glFlush();
};

void animation(int) {
	glutPostRedisplay();
	glutTimerFunc(16, animation, 0);
	//k++;



}
void timer(int) {
	glutTimerFunc(16, timer, 0);
	SPIN += 20;
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE); // Use single display buffer.
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("EMPTY WINDOW");
	InitGL();
	glutReshapeFunc(ReSizeGLScene);
	glutDisplayFunc(DrawGLScene);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutSpecialFunc(special);
	animation(0);
	timer(0);
	glutMainLoop();

	return 0;
}





//to be added afterwards

//pc table practical
/*
{
	//right wall
	glPushMatrix();
	glColor3ub(139, 69, 19);
	glTranslated(300.3, -2, 50);
	glRotated(90, 0, 0, 1);
	glScaled(1, 0.1, 1);
	glutSolidCube(3);
	glPopMatrix();

	//left wall

	glPushMatrix();
	glColor3ub(139, 69, 19);
	glTranslated(304.3, -2, 50);
	glRotated(90, 0, 0, 1);
	glScaled(1, 0.1, 1);
	glutSolidCube(3);
	glPopMatrix();

	//stand

	glPushMatrix();
	glColor3ub(139, 69, 19);
	glTranslated(302.3, -2, 50);
	glRotated(90, 0, 1, 0);
	glScaled(1, 0.1, 1.3);
	glutSolidCube(3);
	glPopMatrix();

	//seperater

	glPushMatrix();
	glColor3ub(139, 69, 19);
	glTranslated(301.8, -2.78, 50);
	glRotated(90, 0, 0, 1);
	glScaled(0.47, 0.05, 1.3);
	glutSolidCube(3);
	glPopMatrix();

	//pc case

	glPushMatrix();
	glColor3ub(0, 0, 0);
	glTranslated(301.1, -2.9, 50);
	glRotated(90, 0, 0, 1);
	glScaled(0.45, 0.3, 1);
	glutSolidCube(3);
	glPopMatrix();

	//monitor
{

	glPushMatrix();
	glColor3ub(0, 0, 0);
	glTranslated(303, -1, 50);
	glRotatef(15,0,1,0);
	glRotated(90, 0, 0, 1);
	glScaled(0.4, 0.44, 0.1);
	glutSolidCube(3);
	glPopMatrix();

	//screen light

	glPushMatrix();
	glColor3ub(255, 255, 0);
	glTranslated(302.95, -1, 49.8);
	glRotatef(15, 0, 1, 0);
	glRotated(90, 0, 0, 1);
	glScaled(0.45, 0.5, 0);
	glutSolidCube(2);
	glPopMatrix();

	//screen holder


		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(302.98, -1, 50);
		glRotatef(15, 0, 1, 0);
		glRotated(90, 1, 0, 0);
		glScaled(0.1, 0.1, 1);
		gluCylinder(a, 1, 1, 1, 4, 4);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(105, 105, 105);
		glTranslated(303, -1.8, 50);
		glRotatef(15, 0, 1, 0);
		glRotated(90, 0, 1, 0);
		glScaled(0.1, 0.15, 0.5);
		glutSolidSphere(1, 30, 30);
		glPopMatrix();

};
	//keyboard and mouse

	{

		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslated(303.4, -1.8, 49.4);
		glRotated(90, 0, 1, 0);
		glRotatef(-15, 0, 1, 0);
		glScaled(0.2,0.01, 0.4);
		glutSolidCube(3);
		glPopMatrix();

		glPushMatrix();
		glColor3ub(0, 0, 0);
		glTranslated(302.4, -1.8, 49.2);
		glRotated(90, 0, 1, 0);
		glRotatef(-15, 0, 1, 0);
		glScaled(1.3, 0.6, 0.8);
		glutSolidSphere(0.25, 10, 10);
		glPopMatrix();
	}
}

*/
//kholer water
/*
{
	glPushMatrix();
	glColor3ub(222, 184, 135);
	glTranslated(100, -5.3, 0);
	glScaled(1, 2.5, 1);
	glutSolidCube(3);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(176, 194, 222);
	glRotated(-90, 1, 0, 0);
	glTranslated(100, 0, -2);
	//glScaled(4, 1, 1);
	gluCylinder(a, 1.5, 1.5, 4.2, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(112, 128, 144);
	glTranslated(99, -3.3, 0);
	glScaled(1.4, 0.3, 1);
	glutSolidSphere(1.4, 20, 20);
	glPopMatrix();


	glPushMatrix();
	glColor3ub(112, 128, 144);
	glTranslated(99, -4.5, 0);
	glScaled(1.2, 0.3, 1);
	glutSolidSphere(1.4, 20, 20);
	glPopMatrix();


	glPushMatrix();
	glColor3ub(70, 130, 180);
	glTranslated(100, 2.2, 0);
	glScaled(1, 0.1, 1);
	glutSolidSphere(2, 20, 20);
	glPopMatrix();
}
*/
//the fan
/*
{
GLUquadricObj * a = gluNewQuadric();

  glPushMatrix();
  glTranslatef(-10.5, 0, 0);
  glRotatef(spin, 1, 0, 0);
  glColor3ub(255, 255, 255);
  glRotatef(90, 1, 0, 0);
  glScalef(0, 1, 1);
  gluCylinder(a, 0.05, 0.6, 2, 200, 200);

  for (int i = 0; i < 5; i += 1) {
	glRotatef(72, 1, 0, 0);
	glScalef(0, 1, 1);
	gluCylinder(a, 0.05, 0.6, 2, 200, 200);
  }
  glPopMatrix();



  glPushMatrix();
  glTranslatef(-10.5, 0, 0);
  glRotatef(90, 1, 0, 0);
  glColor3ub(0, 0, 0);
  glScalef(0.4, 1, 1);
  glutWireSphere(2.4, 10, 10);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-10.5, 0, 0);
  glRotatef(90, 1, 0, 0);
  glColor3ub(0, 0, 0);
  gluSphere(a, 0.22, 200, 200);
  glPopMatrix();


  glPushMatrix();
  glTranslatef(-10.5, -2.3, 0);
  glRotatef(90, 1, 0, 0);
  glColor3ub(0, 0, 0);
  glScalef(0.4, 1, 1);
  gluCylinder(a, 0.49, 0.43, 2, 200, 200);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-10.5, -4,a 0);
  glRotatef(90, 0, 1, 0);
  glColor3ub(0, 0, 0);
  glScalef(1, 0.4, 1);
  gluSphere(a, 1, 200, 200);
  glPopMatrix();

  }
  */