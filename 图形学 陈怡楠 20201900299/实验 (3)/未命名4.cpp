#include <stdlib.h>
#include <math.h>

void init (void)
{
    glClearColor(1.0, 1.0,1.0, 0.0);  // 指定清空颜色（背景色）为白色
    glMatrixMode(GL_PROJECTION);//Set projection parameters
    gluOrtho2D (0.0, 400.0, 0.0, 400.0);   //指定二维坐标系中被显示的区域
}

void setPixel(GLint x,  GLint y)
 {
     glBegin(GL_POINTS);
     glVertex2i(x, y);
     glEnd();
}

inline int round(const float a)
{
    return int(a+0.5);
}

/*  Bresenham line-drawing procedure for |m| < 1.0.  */
void lineBres (int x0, int y0, int xEnd, int yEnd){
      int dx = fabs (xEnd - x0),  dy = fabs(yEnd - y0);
      int p = 2 * dy - dx;
      int twoDy = 2 * dy,  twoDyMinusDx = 2 * (dy - dx);
      int x, y;

      /* Determine which endpoint to use as start position.  */
      if (x0 > xEnd) {
         x = xEnd;
         y = yEnd;
         xEnd = x0;
      }
      else {
         x = x0;
         y = y0;
      }
      setPixel (x, y);

      while (x < xEnd) {
         x++;
         if (p < 0)
            p += twoDy;
         else {
            y++;
            p += twoDyMinusDx;
         }
         setPixel (x, y);
      }
  }


 void displayBres(void)
 {
    glClear (GL_COLOR_BUFFER_BIT);  // 清空显示窗口
    glColor3f (0.0,0.0,1.0);      // 指定前景色（当前绘制颜色）为蓝色
    lineBres(150,150,300,300);
    glFlush ( );     // 使绘制立即反映到屏幕上
 }

int main (int argc, char** argv)
{
    glutInit (&argc, argv);                         // 初始 GLUT.
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   //设定显示模式
    glutInitWindowPosition (100, 100);   // 设定窗口位置
    glutInitWindowSize (400, 400);      // 设定窗口大小
    glutCreateWindow ("An Example OpenGL Program"); // 用前面指定参数创建窗口，并定义窗口名称

    init ( );                            // 进行一些初始化工作
    glutDisplayFunc (displayBres);       // 指定绘制的回调函数
    glutMainLoop ( );          // 进入无穷循环，等待事件处理
    return 0;
}
