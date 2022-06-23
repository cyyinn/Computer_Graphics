#include <GL/glut.h>
#define pointNum 3  //���������С

//һ����Ľṹ��
struct wcPt2D {
	GLfloat x, y;
};
wcPt2D point[pointNum];//��������
GLint tx=20,ty=20;//ƽ�ƾ���
void translate2D (wcPt2D * verts, GLint nVerts, GLfloat tx, GLfloat ty)
{ //�Զ���εĶ��㼯һ��һ������ƽ��
	GLint k;
	for (k = 0; k < nVerts; k++) {
		verts [k].x = verts [k].x + tx;
		verts [k].y = verts [k].y + ty;
	}
}

void init (void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);  
    glMatrixMode (GL_PROJECTION);  
    gluOrtho2D (0.0, 640.0, 0.0, 480.0);
	point[0].x=10; point[0].y=10;//Ϊ����εĶ���ָ����ʼֵ
	point[1].x=100; point[1].y=10;
	point[2].x=10; point[2].y=100;
}

void myDraw (void)
{
	glClear (GL_COLOR_BUFFER_BIT); 
	glColor3f (1.0, 0.0, 0.0);
	
	glBegin (GL_POLYGON);//��point�еĶ�������������
	for (int k = 0; k < pointNum; k++)
		glVertex2f (point[k].x, point[k].y);
	glEnd ( );
	
	glFlush ( );
}
void myMouse(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)//������ƽ�ƶ�ÿ������tx,ty
		translate2D (point, pointNum, tx, ty);
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)//����Ҽ�ƽ�ƶ�ÿ������-tx,-ty����
		translate2D (point, pointNum, -tx, -ty);
	
	glutPostRedisplay(); //��ƽ�ƺ�Ķ��㼯���µ��û��ƺ������л���
}
void main (int argc, char** argv)
{
    glutInit (&argc, argv);                        
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  
    glutInitWindowPosition (0, 0);  
    glutInitWindowSize (640, 480);      
    glutCreateWindow ("��άƽ�Ʊ任,������ҽ�����ƽ��"); 
    
    init();                  
    glutDisplayFunc (myDraw);
    glutMouseFunc( myMouse);
    glutMainLoop ( );  
}
