#include <stdlib.h>
#include <math.h>

void init (void)
{
    glClearColor(1.0, 1.0,1.0, 0.0);  // ָ�������ɫ������ɫ��Ϊ��ɫ
    glMatrixMode(GL_PROJECTION);//Set projection parameters
    gluOrtho2D (0.0, 400.0, 0.0, 400.0);   //ָ����ά����ϵ�б���ʾ������
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
    glClear (GL_COLOR_BUFFER_BIT);  // �����ʾ����
    glColor3f (0.0,0.0,1.0);      // ָ��ǰ��ɫ����ǰ������ɫ��Ϊ��ɫ
    lineBres(150,150,300,300);
    glFlush ( );     // ʹ����������ӳ����Ļ��
 }

int main (int argc, char** argv)
{
    glutInit (&argc, argv);                         // ��ʼ GLUT.
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   //�趨��ʾģʽ
    glutInitWindowPosition (100, 100);   // �趨����λ��
    glutInitWindowSize (400, 400);      // �趨���ڴ�С
    glutCreateWindow ("An Example OpenGL Program"); // ��ǰ��ָ�������������ڣ������崰������

    init ( );                            // ����һЩ��ʼ������
    glutDisplayFunc (displayBres);       // ָ�����ƵĻص�����
    glutMainLoop ( );          // ��������ѭ�����ȴ��¼�����
    return 0;
}
