#include <windows.h>//windows系统
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <math.h>//实现算法过程中用到数学函数
void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	//指定清空颜色（背景色）为白色
		glMatrixMode(GL_PROJECTION);//Set projection parameters
	gluOrtho2D(0.0, 400.0, 0.0, 400.0);
	//指定二维坐标系中被显示的区域
}
void setPixel(GLint x,
	GLint y)//画点函数
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}
inline int round(const float a)
{
	return int(a + 0.5);//取整操作
}
void lineDDA(int x0, int y0, int xEnd, int yEnd) {
	int dx = xEnd - x0,
		dy = yEnd - y0,
		steps,
		k;
	float xIncrement, yIncrement, x = x0, y = y0;

	if (fabs(dx) > fabs(dy))//斜率的绝对值小于1
		steps = fabs(dx);
	else//斜率的绝对值大于等于1
		steps = fabs(dy);
	xIncrement = float(dx) / float(steps);//下一个点距离上一个点x与y各自的增量
		yIncrement = float(dy) / float(steps);
	setPixel(round(x), round(y));
	for (k = 0; k < steps; k++) {//通过循环将直线通过一个一个的点画出
			x += xIncrement;
		y += yIncrement;
		setPixel(round(x), round(y));
	}
}
void displayDDA(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//清空显示窗口
		glColor3f(0.0, 0.0, 1.0);
	//指定前景色（当前绘制颜色）为蓝色
		lineDDA(200, 300, 300, 200);//直线算法函数调用，参数为（x0, y0）,(xEnd, yEnd)
		glFlush();
	//使绘制立即反映到屏幕上
}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	//初始GLUT.
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//设定显示模式
		glutInitWindowPosition(100, 100);
	//设定窗口位置
		glutInitWindowSize(400, 400);
	//设定窗口大小
		glutCreateWindow("An Example OpenGL Program"); //用前面指定参数创建窗口，并定义窗口名称
		init();
	//进行一些初始化工作
		glutDisplayFunc(displayDDA);
	//指定绘制的回调函数
		glutMainLoop();
	//进入无穷循环，等待事件处理
		return 0;
}
