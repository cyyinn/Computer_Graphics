#include <GL/glut.h>
void init (void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);  
    glMatrixMode (GL_PROJECTION);  
    gluOrtho2D (-5.0, 5.0, -5.0, 5.0); //������ʾ�ķ�Χ��X:-5.0~5.0, Y:-5.0~5.0
    glMatrixMode (GL_MODELVIEW);
}
void drawSquare(void) //����������ԭ�㣬�߳�Ϊ2��������
{
	glBegin (GL_POLYGON); //����ָ����Ҫ����ʱ�뷽��
	   glVertex2f (-1.0f,-1.0f);//���µ�
	   glVertex2f (1.0f,-1.0f);//���µ�
	   glVertex2f (1.0f, 1.0f);//���ϵ�
	   glVertex2f (-1.0f,1.0f);//���ϵ�
	glEnd ( );
}

void myDraw1 (void)
{
	glClear (GL_COLOR_BUFFER_BIT); //���
	glLoadIdentity();        //����ǰ������Ϊ��λ����
	
	glColor3f (1.0, 0.0, 0.0); 
	drawSquare();       //��ԭ�㴦���Ʊ߳�Ϊ2��ɫ������

	glTranslatef(2.0,3.0,0.0);  //�����ƶ�2��λ�������ƶ�3��λ
	glScalef(1.0,1.5,1.0); //X��Z���򱣳ֲ��䣬Y����Ŵ�Ϊԭ����1.5��
	glColor3f (0.0, 1.0, 0.0);  
	drawSquare();              //���Ʊ߳�Ϊ2��ɫ������
    
	glLoadIdentity();        //����ǰ������Ϊ��λ����
	glTranslatef(-2.0,-3.0,0.0);  //�����ƶ�2��λ�������ƶ�3��λ
	glScalef(0.5,1.5,1.0); //Z���򱣳ֲ��䣬X������СΪԭ����0.5����Y����Ŵ�Ϊԭ����1.5��
	glColor3f (0.0, 0.0, 1.0);
	drawSquare();              //���Ʊ߳�Ϊ2��ɫ������

	glFlush ( );
}

void myDraw2 (void)
{
	glClear (GL_COLOR_BUFFER_BIT); //���
	glLoadIdentity();        //����ǰ������Ϊ��λ����
	
	glColor3f (1.0, 0.0, 0.0); 
	drawSquare();       //��ԭ�㴦���Ʊ߳�Ϊ2��ɫ������
    
	glPushMatrix();   //�ѵ�ǰ����ѹ���ջ
	glTranslatef(2.0,3.0,0.0);  //�����ƶ�2��λ�������ƶ�3��λ
	glScalef(1.0,1.5,1.0); //X��Z���򱣳ֲ��䣬Y����Ŵ�Ϊԭ����1.5��
	glColor3f (0.0, 1.0, 0.0);  
	drawSquare();              //���Ʊ߳�Ϊ2��ɫ������
    glPopMatrix();   //�Ӷ�ջջ������һ������Ϊ��ǰ����
	
	glTranslatef(-2.0,-3.0,0.0);  //�����ƶ�2��λ�������ƶ�3��λ
	glScalef(0.5,1.5,1.0); //Z���򱣳ֲ��䣬X������СΪԭ����0.5����Y����Ŵ�Ϊԭ����1.5��
	glColor3f (0.0, 0.0, 1.0);
	drawSquare();              //���Ʊ߳�Ϊ2��ɫ������

	glFlush ( );
}

void main (int argc, char** argv)
{
    glutInit (&argc, argv);                        
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  
    glutInitWindowPosition (0, 0);  
    glutInitWindowSize (600, 600);      
    glutCreateWindow ("Scale����ʾ��"); 
    
    init();                  
    glutDisplayFunc (myDraw1);
    glutMainLoop ( );  
}
