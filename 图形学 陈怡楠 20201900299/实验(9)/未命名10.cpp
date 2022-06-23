#include <GL/glut.h>
#define pointNum 3  //顶点数组大小

//一个点的结构体
struct wcPt2D {
	GLfloat x, y;
};
wcPt2D point[pointNum];//顶点数组
GLint tx=20,ty=20;//平移距离
void translate2D (wcPt2D * verts, GLint nVerts, GLfloat tx, GLfloat ty)
{ //对多边形的顶点集一个一个进行平移
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
	point[0].x=10; point[0].y=10;//为多边形的顶点指定初始值
	point[1].x=100; point[1].y=10;
	point[2].x=10; point[2].y=100;
}

void myDraw (void)
{
	glClear (GL_COLOR_BUFFER_BIT); 
	glColor3f (1.0, 0.0, 0.0);
	
	glBegin (GL_POLYGON);//用point中的顶点绘制填充多边形
	for (int k = 0; k < pointNum; k++)
		glVertex2f (point[k].x, point[k].y);
	glEnd ( );
	
	glFlush ( );
}
void myMouse(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)//点击左键平移对每个顶点tx,ty
		translate2D (point, pointNum, tx, ty);
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)//点击右键平移对每个顶点-tx,-ty距离
		translate2D (point, pointNum, -tx, -ty);
	
	glutPostRedisplay(); //用平移后的顶点集重新调用绘制函数进行绘制
}
void main (int argc, char** argv)
{
    glutInit (&argc, argv);                        
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  
    glutInitWindowPosition (0, 0);  
    glutInitWindowSize (640, 480);      
    glutCreateWindow ("二维平移变换,鼠标左右健控制平移"); 
    
    init();                  
    glutDisplayFunc (myDraw);
    glutMouseFunc( myMouse);
    glutMainLoop ( );  
}
