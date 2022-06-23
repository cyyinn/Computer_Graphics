#include<GL/glut.h>
#include <math.h>
#include<iostream>
using namespace std;
GLfloat square[4][2];//����һ�������εĶ�����������
//ƽ�ƣ��ü��̵��������Ҽ����ƣ�
void Translate(GLfloat Tx, GLfloat Ty)
{
	for (int i = 0; i < 4; i++) {
		square[i][0] += Tx;              //��Ӿ���ƽ��
		square[i][1] += Ty;
	}
}
//����/���ţ��ü��̵�a/A������x������,d/D������y�����ţ�
void Scale(GLfloat Sx, GLfloat Sy)
{
	for (int i = 0; i < 4; i++) {
		square[i][0] *= Sx;
		square[i][1] *= Sy;
	}
}
//��ת���ü��̵�r/R��������ʱ�����ʱ����ת��
void Rotate(GLfloat degree)
{
	for (int i = 0; i < 4; i++) {
		int tmpX = square[i][0], tmpY = square[i][1];
		square[i][0] = tmpX * cos(degree) - tmpY * sin(degree);
		square[i][1] = tmpX * sin(degree) + tmpY * cos(degree);
	}
}
//�Գƣ�x������x��Գƣ�y������y��Գƣ�
void Symmetry(int flag)
{
	for (int i = 0; i < 4; i++) {
		if (flag) {//����1����x��Գ�
			square[i][1] *= -1;
		}
		else {//����0����y��Գ�
			square[i][0] *= -1;
		}
	}
}
//�û��Զ����ʼ��
void myinit()
{
	//��ʼ�������ζ�������
	square[0][0] = 50;		//100 ����
	square[0][1] = 100;      
	square[1][0] = 150.0;        
	square[1][1] = 100.0;   //����
	square[2][0] = 100.0;   
	square[2][1] = 0;    //-100
	square[3][0] = 0;//0 
	square[3][1] = 0;//0

}
//���ڴ�С�仯�Ļص�����
void reshape(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);//�����ӿڴ�С����ʼ���봰��һ��

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500, 500, -500, 500);
}

void display()
{
	//���ñ�����ɫΪ��ɫ�������ɫ����
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	//������ϵ
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	//��x��
	glVertex2f(400.0, 0.0);
	glVertex2f(-400.0, 0.0);
	//��y��
	glVertex2f(0.0, 400.0);
	glVertex2f(0.0, -400.0);
	glEnd();
	glColor3f(0.0, 1.0, 0.0);
	glPointSize(4.0);
	glBegin(GL_POINTS);
	//��x��y���ϵ�����
	for (GLfloat i = -400.0; i <= 400.0; i += 100.0) {
		glVertex2f(i, 0.0);
		glVertex2f(0.0, i);
	}
	glEnd();

	//��������
	glColor4f(1.0, 0.0, 0.0, 0.1);
	glLineWidth(2.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	glVertex2f(square[0][0], square[0][1]);
	glVertex2f(square[1][0], square[1][1]);
	glVertex2f(square[2][0], square[2][1]);
	glVertex2f(square[3][0], square[3][1]);
	glEnd();

	//����ǰ�󻺳���
	glutSwapBuffers();
}
//���������ⰴ���Ļص�����
void processSpecialKeys(int key, int x, int y)
{
	switch (key) {
	case GLUT_KEY_LEFT:
		Translate(-100.0, 0);
		break;
	case GLUT_KEY_RIGHT:
		Translate(100.0, 0.0);
		break;
	case GLUT_KEY_UP:
		Translate(0.0, 100.0);
		break;
	case GLUT_KEY_DOWN:
		Translate(0.0, -100.0);
		break;
	}
	glutPostRedisplay();
}
//������ͨ�����Ļص�����
void processNormalKeys(unsigned char key, int x, int y)
{
	switch (key) {
	case 97:	//"a"
		Scale(0.5, 1.0);
		break;
	case 65:	//"A"
		Scale(2.0, 1.0);
		break;
	case 100:	//"d"
		Scale(1.0, 0.5);
		break;
	case 68:	//"D"
		Scale(1.0, 2.0);
		break;
	case 114:	//"r"
		Rotate(15.0);
		break;
	case 82:	//"R"
		Rotate(-15.0);
		break;
	case 120:	//"x"
		Symmetry(1);
		break;
	case 121:	//"y"
		Symmetry(0);
		break;
	case 27:	//"esc"
		exit(0);
	}
	glutPostRedisplay();
}
//������
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	//��ʼ��OPENGL��ʾ��ʽ
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	//�趨OPENGL����λ�úʹ�С
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	//�򿪴���
	glutCreateWindow("����ε�ƽ�ơ����������ţ�����ת���ԳƱ任");
	cout << "����A��D���зŴ� ����a��d������С" << endl;
	cout << "�����������ҽ���ƽ�Ʋ���" << endl;
	cout << "����r��R��������ʱ�����ʱ����ת" << endl;
	cout << "x������x��Գƣ�y������y��Գ�" << endl;
	//���ó�ʼ������
	myinit();
	//�趨���ڴ�С�仯�Ļص�����
	glutReshapeFunc(reshape);
	//�趨���̿��ƵĻص�����
	glutSpecialFunc(processSpecialKeys);
	glutKeyboardFunc(processNormalKeys);

	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
