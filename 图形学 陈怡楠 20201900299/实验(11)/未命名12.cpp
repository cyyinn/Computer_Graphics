#include <GL/glut.h>
void init (void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);  
    glMatrixMode (GL_PROJECTION);  
    gluOrtho2D (-5.0, 5.0, -5.0, 5.0); //设置显示的范围是X:-5.0~5.0, Y:-5.0~5.0
    glMatrixMode (GL_MODELVIEW);
}
void drawSquare(void) //绘制中心在原点，边长为2的正方形
{
	glBegin (GL_POLYGON); //顶点指定需要按逆时针方向
	   glVertex2f (-1.0f,-1.0f);//左下点
	   glVertex2f (1.0f,-1.0f);//右下点
	   glVertex2f (1.0f, 1.0f);//右上点
	   glVertex2f (-1.0f,1.0f);//左上点
	glEnd ( );
}
void myDraw1 (void)
{
	glClear (GL_COLOR_BUFFER_BIT); //清空
	glLoadIdentity();        //将当前矩阵设为单位矩阵
	
	glColor3f (1.0, 0.0, 0.0); 
	drawSquare();       //在原点处绘制边长为2红色正方形

	glTranslatef(2.0,3.0,0.0);  //向右移动2单位，向上移动3单位
	glColor3f (0.0, 1.0, 0.0);  
	drawSquare();              //绘制边长为2绿色正方形

	glTranslatef(0.0,-3.0,0.0); //再向下移动3单位
	glColor3f (0.0, 0.0, 1.0);
	drawSquare();              //绘制边长为2蓝色正方形

	glFlush ( );
}

void myDraw2 (void)
{
	glClear (GL_COLOR_BUFFER_BIT); //清空
	glLoadIdentity();        //将当前矩阵设为单位矩阵
	
	glColor3f (1.0, 0.0, 0.0); 
	drawSquare();       //在原点处绘制边长为2红色正方形
    
	glPushMatrix();
	glTranslatef(2.0,3.0,0.0);  //向右移动2单位，向上移动3单位
	glColor3f (0.0, 1.0, 0.0);  
	drawSquare();              //绘制边长为2绿色正方形
    glPopMatrix();


	glTranslatef(2.0,0.0,0.0); //再向右移动2单位
	glColor3f (0.0, 0.0, 1.0);
	drawSquare();       //绘制边长为2蓝色正方形

	glFlush ( );
}

void main (int argc, char** argv)
{
    glutInit (&argc, argv);                        
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  
    glutInitWindowPosition (0, 0);  
    glutInitWindowSize (600, 600);      
    glutCreateWindow ("Translate函数示例"); 
    
    init();                  
    glutDisplayFunc (myDraw1);
    glutMainLoop ( );  
}
