#include <GL/glut.h>      // (or others, depending on the system in use)

void init (void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);  // ָ�������ɫ������ɫ��Ϊ��ɫ
    gluOrtho2D (0.0, 400.0, 0.0, 300.0);   //ָ����ά����ϵ�б���ʾ������
}

void display (void)
{
    glClear (GL_COLOR_BUFFER_BIT);  // �����ʾ����
    glColor3f (0.0, 0.0, 1.0);      // ָ��ǰ��ɫ����ǰ������ɫ��Ϊ��ɫ
    glBegin (GL_LINES);
        glVertex2i (180, 15);       // ָ������
        glVertex2i (10, 145);
    glEnd ( );
    glFlush ( );     // ʹ����������ӳ����Ļ��
}

void main (int argc, char** argv)
{
    glutInit (&argc, argv);                         // ��ʼ GLUT.
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);   //�趨��ʾģʽ
    glutInitWindowPosition (50, 100);   // �趨����λ��
    glutInitWindowSize (400, 300);      // �趨���ڴ�С
    glutCreateWindow ("An Example OpenGL Program"); // ��ǰ��ָ�������������ڣ������崰������
    init ( );                            // ����һЩ��ʼ������
    glutDisplayFunc (display);       // ָ�����ƵĻص�����
    glutMainLoop ( );          // ��������ѭ�����ȴ��¼�����
}
