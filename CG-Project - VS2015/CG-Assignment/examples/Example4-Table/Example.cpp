
#include <GL/glut.h>
// #include <GL/glaux.h>

void init() {
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glEnable(GL_DEPTH_TEST);

	glClearColor(0.3,0.4,0.8,0.1);
	//projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90,1,1,100);
	gluLookAt(0,0,-20,0,0,-50,0,1,0);

	//light source
	GLfloat light_position[]={0,50,0,1};
	GLfloat ambient[]={0.2,0.2,0.2,1};
	GLfloat diffuse[]={0.8,0.8,0.8,1};
	GLfloat specular[]={1,0.6,0.6,1};
	glLightfv(GL_LIGHT1,GL_POSITION,light_position);
	glLightfv(GL_LIGHT1,GL_AMBIENT,ambient);
	glLightfv(GL_LIGHT1,GL_DIFFUSE,diffuse);
	glLightfv(GL_LIGHT1,GL_SPECULAR,specular);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);

	glShadeModel(GL_SMOOTH); //shading
}


/****************** draw a table ********************/
void Table() {
	//material property
	GLfloat tb_ambient[]={0.05,0.05,0.05,1};
	GLfloat tb_diffuse[]={0.8,0.8,0.8,1};
	GLfloat tb_specular[]={0.6,0.6,0.6,1};

	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,tb_ambient);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,tb_diffuse);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,tb_specular);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/******** 4 legs of the table *********/
	GLUquadricObj *ob=gluNewQuadric();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(0,-20,-45);
	glRotatef(-90,1,0,0);
	gluCylinder(ob,0.5,0.5,10,20,20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1,-20,-53);
	glRotatef(-90,1,0,0);
	gluCylinder(ob,0.5,0.5,10,20,20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8,-20,-53);
	glRotatef(-90,1,0,0);
	gluCylinder(ob,0.5,0.5,10,20,20);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8,-20,-45);
	glRotatef(-90,1,0,0);
	gluCylinder(ob,0.5,0.5,10,20,20);
	glPopMatrix();
	/********** surface of the table *********/
	glPushMatrix();
	glTranslatef(4,-9.5,-49);
	glScalef(1, 0.1, 1);
	glutSolidCube(10);
	glPopMatrix();
	glFlush();
}


void main (int argc, char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	//window
	glutInitWindowSize(800,600);
	glutInitWindowPosition(150,100);
	glutCreateWindow("Example");

	glutDisplayFunc(Table);  // display callback
	init(); // set OpenGL state
	glutMainLoop(); // enter event loop
}

