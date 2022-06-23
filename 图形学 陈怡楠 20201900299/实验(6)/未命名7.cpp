#include<GL/glut.h>
#include <math.h>
#include<iostream>
using namespace std;
GLfloat square[4][2];//定义一个正方形的顶点坐标数组
//平移（用键盘的上下左右键控制）
void Translate(GLfloat Tx, GLfloat Ty)
{
	for (int i = 0; i < 4; i++) {
		square[i][0] += Tx;              //相加就是平移
		square[i][1] += Ty;
	}
}
//比例/缩放（用键盘的a/A键控制x的缩放,d/D键控制y的缩放）
void Scale(GLfloat Sx, GLfloat Sy)
{
	for (int i = 0; i < 4; i++) {
		square[i][0] *= Sx;
		square[i][1] *= Sy;
	}
}
//旋转（用键盘的r/R键控制逆时针和正时针旋转）
void Rotate(GLfloat degree)
{
	for (int i = 0; i < 4; i++) {
		int tmpX = square[i][0], tmpY = square[i][1];
		square[i][0] = tmpX * cos(degree) - tmpY * sin(degree);
		square[i][1] = tmpX * sin(degree) + tmpY * cos(degree);
	}
}
//对称（x键关于x轴对称，y键关于y轴对称）
void Symmetry(int flag)
{
	for (int i = 0; i < 4; i++) {
		if (flag) {//等于1关于x轴对称
			square[i][1] *= -1;
		}
		else {//等于0关于y轴对称
			square[i][0] *= -1;
		}
	}
}
//用户自定义初始化
void myinit()
{
	//初始化正方形顶点数组
	square[0][0] = 50;		//100 左上
	square[0][1] = 100;      
	square[1][0] = 150.0;        
	square[1][1] = 100.0;   //右上
	square[2][0] = 100.0;   
	square[2][1] = 0;    //-100
	square[3][0] = 0;//0 
	square[3][1] = 0;//0

}
//窗口大小变化的回调函数
void reshape(GLsizei w, GLsizei h)
{
	glViewport(0, 0, w, h);//设置视口大小比例始终与窗口一致

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500, 500, -500, 500);
}

void display()
{
	//设置背景颜色为白色并清除颜色缓冲
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	//画坐标系
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	//画x轴
	glVertex2f(400.0, 0.0);
	glVertex2f(-400.0, 0.0);
	//画y轴
	glVertex2f(0.0, 400.0);
	glVertex2f(0.0, -400.0);
	glEnd();
	glColor3f(0.0, 1.0, 0.0);
	glPointSize(4.0);
	glBegin(GL_POINTS);
	//画x、y轴上的坐标
	for (GLfloat i = -400.0; i <= 400.0; i += 100.0) {
		glVertex2f(i, 0.0);
		glVertex2f(0.0, i);
	}
	glEnd();

	//画正方形
	glColor4f(1.0, 0.0, 0.0, 0.1);
	glLineWidth(2.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_POLYGON);
	glVertex2f(square[0][0], square[0][1]);
	glVertex2f(square[1][0], square[1][1]);
	glVertex2f(square[2][0], square[2][1]);
	glVertex2f(square[3][0], square[3][1]);
	glEnd();

	//交换前后缓冲区
	glutSwapBuffers();
}
//键盘上特殊按键的回调函数
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
//键盘普通按键的回调函数
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
//主函数
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	//初始化OPENGL显示方式
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	//设定OPENGL窗口位置和大小
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	//打开窗口
	glutCreateWindow("多边形的平移、比例（缩放）、旋转、对称变换");
	cout << "输入A和D进行放大 输入a和d进行缩小" << endl;
	cout << "输入上下左右进行平移操作" << endl;
	cout << "输入r和R键控制逆时针和正时针旋转" << endl;
	cout << "x键关于x轴对称，y键关于y轴对称" << endl;
	//调用初始化函数
	myinit();
	//设定窗口大小变化的回调函数
	glutReshapeFunc(reshape);
	//设定键盘控制的回调函数
	glutSpecialFunc(processSpecialKeys);
	glutKeyboardFunc(processNormalKeys);

	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
