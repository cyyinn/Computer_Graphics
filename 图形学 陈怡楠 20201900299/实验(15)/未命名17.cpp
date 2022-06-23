#include <stdlib.h>
#include <GL/glut.h>

float fTranslate;
float fRotate;
float fScale = 1.0f;	// set inital scale value to 1.0f

bool bPersp = false;
bool bAnim = false;
bool bWire = false;
bool light_flag = false;//环境光颜色
GLfloat color[] = { 1.0, 1.0, 1.0, 1.0 }; // 定义颜色   
int wHeight = 0;
int wWidth = 0;
//环境光
GLfloat light_x = 0.0f;
GLfloat light_y = 0.0f;
GLfloat light_z = 0.0f;
//聚光灯
GLfloat spot_x = 0.0f;
GLfloat spot_y = 0.0f;
GLfloat spot_z = 0.0f;
GLfloat Angle = 5.0f;//聚光灯角度
void Draw_Leg();

void Draw_Table() // This function draws a triangle with RGB colors
{
    //定义变量
    GLfloat specular[] = { 0.6f,0.6f,0.6f,1.0f };
    GLfloat color1[] = { 0.85f,0.65f,0.2f,1.0f };//金黄色
    GLfloat color2[] = { 1.0f,0.0f,0.0f };
    GLfloat color3[] = { 0.0f,1.0f,0.0f };
    GLfloat color4[] = { 1.0f,1.0f,0.0f };
    GLfloat color5[] = { 0.0f,1.0f,1.0f };
    GLfloat color6[] = { 0.0f,0.0f,1.0f };
    //茶壶
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);//设置镜面颜色
    glMateriali(GL_FRONT, GL_SHININESS, 50);//设置镜面指数
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color1);//材料的环境和散射颜色
    glTranslatef(0, 0, 4 + 1);
    glRotatef(90, 1, 0, 0);
    glutSolidTeapot(1);
    glPopMatrix();
    //桌面
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_SPECULAR, color2);//设置镜面颜色
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color2);//材料的环境和散射颜色
    glTranslatef(0, 0, 3.5);
    glScalef(5, 4, 1);
    glutSolidCube(1.0);
    glPopMatrix();
    //四条腿
    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_SPECULAR, color3);//设置镜面颜色
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color3);//材料的环境和散射颜色
    glTranslatef(1.5, 1, 1.5);
    Draw_Leg();
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_SPECULAR, color4);//设置镜面颜色
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color4);//材料的环境和散射颜色
    glTranslatef(-1.5, 1, 1.5);
    Draw_Leg();
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_SPECULAR, color5);//设置镜面颜色
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color5);//材料的环境和散射颜色
    glTranslatef(1.5, -1, 1.5);
    Draw_Leg();
    glPopMatrix();

    glPushMatrix();
    glMaterialfv(GL_FRONT, GL_SPECULAR, color6);//设置镜面颜色
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color6);//材料的环境和散射颜色
    glTranslatef(-1.5, -1, 1.5);
    Draw_Leg();
    glPopMatrix();

}

void Draw_Leg()
{
    glScalef(1, 1, 3);
    glutSolidCube(1.0);
}

void updateView(int width, int height)
{
    glViewport(0, 0, width, height);						// Reset The Current Viewport

    glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
    glLoadIdentity();									// Reset The Projection Matrix

    float whRatio = (GLfloat)width / (GLfloat)height;
    if (bPersp) {
        gluPerspective(45.0f, whRatio, 0.1f, 100.0f);
        //glFrustum(-3, 3, -3, 3, 3,100);
    }
    else {
        glOrtho(-3, 3, -3, 3, -100, 100);
    }

    glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
}

void reshape(int width, int height)
{
    if (height == 0)										// Prevent A Divide By Zero By
    {
        height = 1;										// Making Height Equal One
    }

    wHeight = height;
    wWidth = width;

    updateView(wHeight, wWidth);
}

void idle()
{
    glutPostRedisplay();
}

float eye[] = { 0, 0, 8 };
float center[] = { 0, 0, 0 };

void key(unsigned char k, int x, int y)
{
    switch (k)
    {
    case 27://ESC
    case 'q': {exit(0); break; }//quit
    case 'p': {bPersp = !bPersp; break; }//显示模式

    case ' ': {bAnim = !bAnim; break; }//旋转
    case 'o': {bWire = !bWire; break; }//线框

    case 'd': {//右
        eye[0] -= 0.2f;
        center[0] -= 0.2f;
        break;
    }
    case 'a': {//左
        eye[0] += 0.2f;
        center[0] += 0.2f;
        break;
    }
    case 'w': {//上
        eye[1] -= 0.2f;
        center[1] -= 0.2f;
        break;
    }
    case 's': {//下
        eye[1] += 0.2f;
        center[1] += 0.2f;
        break;
    }
    case 'z': {//前
        eye[2] -= 0.2f;
        center[2] -= 0.2f;
        break;
    }
    case 'c': {//后
        eye[2] += 0.2f;
        center[2] += 0.2f;
        break;
    }
    case 'j': {//环境光左
        light_x += 0.2f;
        break;
    }
    case 'l': {//环境光右
        light_x -= 0.2f;
        break;
    }
    case 'i': {//环境光上
        light_y += 0.2f;
        break;
    }
    case 'k': {//环境光下
        light_y -= 0.2f;
        break;
    }
    case 'n': {//环境光前
        light_z += 0.2f;
        break;
    }
    case ',': {//环境光后
        light_z -= 0.2f;
        break;
    }
    case 'u': {//环境光颜色切换
        light_flag = !light_flag;
        break;
    }
    case 'f': {//聚光灯左移
        spot_x -= 0.05f;
        break;
    }
    case 'h': {
        spot_x += 0.05f;
        break;
    }
    case 't': {
        spot_y -= 0.05f;
        break;
    }
    case 'g': {
        spot_y += 0.05f;
        break;
    }
    case 'v': {//聚光灯前移
        spot_z += 0.05f;
        break;
    }
    case 'b': {//聚光灯后移
        spot_z -= 0.05f;
        break;
    }
    case 'r': {//角度变大
        if (Angle <= 89.0f)
            Angle += 0.2f;
        break;
    }
    case 'y': {
        if (Angle >= 1.0f)
            Angle -= 0.2f;
        break;
    }
    }

    updateView(wHeight, wWidth);
}


void redraw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();									// Reset The Current Modelview Matrix

    gluLookAt(eye[0], eye[1], eye[2],
        center[0], center[1], center[2],
        0, 1, 0);				// 场景（0，0，0）的视点中心 (0,5,50)，Y轴向上

    if (bWire) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
    glEnable(GL_DEPTH_TEST);//开启深度测试
    glEnable(GL_LIGHTING);//开启光照模式

    GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };//定义环境光颜色：白色
    GLfloat light_pos[] = { 5.0 + light_x,5.0 + light_y,5.0 + light_z,1 };
    //定义聚光灯位置
    GLfloat spot_pos[] = { 0.0f,5.0f,0.0f,1.0f };
    //定义聚光灯照射方向
    GLfloat spot_angle[] = { 0.0f + spot_x,-1.0f + spot_y,0.0f + spot_z };
    //是否改变光照颜色
    if (light_flag)
        color[1] = color[3] = 0.0f;
    else
        color[1] = color[3] = 1.0f;


    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);//0号光源的位置
    glLightfv(GL_LIGHT0, GL_SMOOTH, white);//设置环境光颜色
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);                     //设置漫射光成分  
    glLightfv(GL_LIGHT0, GL_AMBIENT, color);   //设置第0号光源多次反射后的光照颜色（环境光颜色）
    glEnable(GL_LIGHT0);//开启0号光源

    glLightfv(GL_LIGHT1, GL_AMBIENT, color);    //设置环境光成分
    glLightfv(GL_LIGHT1, GL_SPECULAR, white);                 //设置镜面光成分
    glLightfv(GL_LIGHT1, GL_DIFFUSE, white);                     //设置漫射光成分

    glLightfv(GL_LIGHT1, GL_POSITION, spot_pos);
    glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, Angle);            //裁减角度
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, spot_angle);          //光源方向
    glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.);                    //聚集度
    glEnable(GL_LIGHT1);//开启1号光源

    //	glTranslatef(0.0f, 0.0f,-6.0f);			// Place the triangle at Center
    glRotatef(fRotate, 0, 1.0f, 0);			// Rotate around Y axis
    glRotatef(-90, 1, 0, 0);
    glScalef(0.2, 0.2, 0.2);
    Draw_Table();						// Draw triangle

    if (bAnim) fRotate += 0.5f;
    glutSwapBuffers();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(480, 480);
    int windowHandle = glutCreateWindow("Simple GLUT App");

    glutDisplayFunc(redraw);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glutMainLoop();
    return;
}
