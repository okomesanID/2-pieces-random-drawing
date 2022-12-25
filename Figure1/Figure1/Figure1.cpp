#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<GL/glut.h>
#define QP 8
#define AP 5
#define BP 3


void drawCircle(double x, double y, double radius)
{
	int i;	double PI = 3.14159;	int CIRCLE_REC = 60;

	glBegin(GL_POLYGON);
	for (i = 0; i < CIRCLE_REC; i++)
		glVertex2f(x + radius*cos((2.*PI*i) / CIRCLE_REC),
		y + radius*sin((2.*PI*i) / CIRCLE_REC));
	glEnd();
}

//�}�`�̍��W�ԍ�
void render_string(float x, float y, const char* string)
{
	float z = -1.0f;
	glRasterPos3f(x, y, z);
	char*p = (char*)string;
	while (*p != '\0')glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *p++);
}

void display()
{
	int dummy, i = 0, j = 0, n = 0;
	double x[4], y[4];//���
	double Qx[QP], Qy[QP];	//�V���G�b�g���W
	double ax[AP], ay[AP];	//�܊p�`���W
	double bx[BP], by[BP];  //�O�p�`���W
	char str[256];	//���W�ԍ�

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	//���
	x[0] = -5; y[0] = 0;
	x[1] = 5; y[1] = 0;
	x[2] = 0; y[2] = -5;
	x[3] = 0; y[3] = 5;

	//���V���G�b�g���W
	Qx[0] = 0.0; Qy[0] = 0.0;
	Qx[1] = 1.0; Qy[1] = 0.0;
	Qx[2] = 2.0; Qy[2] = 1.1;
	Qx[3] = 2.0; Qy[3] = 2.0;
	Qx[4] = 1.5; Qy[4] = 2.0;
	Qx[5] = 1.5; Qy[5] = 3.1;
	Qx[6] = 0.5; Qy[6] = 2.0;
	Qx[7] = 0.0; Qy[7] = 2.0;


	//�܊p�`-pieace1
	ax[0] = 0.0; ay[0] = 0.0;
	ax[1] = 1.0; ay[1] = 0.0;
	ax[2] = 2.0; ay[2] = 1.1;
	ax[3] = 2.0; ay[3] = 2.0;
	ax[4] = 0.0; ay[4] = 2.0;

	//�O�p�`-pieace2
	bx[0] = 1.0; by[0] = 0.0;
	bx[1] = 2.0; by[1] = 0.0;
	bx[2] = 2.0; by[2] = 1.1;

	//���V���G�b�g�`��	�����ԕς���Ȃ�
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.8, 1.0);
	for (i = 0; i < QP; i++)
		glVertex2f(Qx[i], Qy[i]);
	glEnd();

	//���	�����ԕς���Ȃ�
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	for (i = 0; i < 4; i++)
		glVertex2f(x[i], y[i]);
	glEnd();

	//���x���̔ԍ��\��
	glColor3f(0.0, 0.0, 0.0);
	for (i = 0; i < QP; i++){
		sprintf_s(str, "%d", i);
		render_string(Qx[i], Qy[i], str);
	}

	////pieace1(�܊p�`)
	//glBegin(GL_LINE_LOOP);
	//glColor3f(0.0, 0.0, 0.0);
	//for (i = 0; i < AP; i++)
	//	glVertex2f(ax[i], ay[i]);
	//glEnd();

	////pieace2(�O�p�`)
	//glBegin(GL_LINE_LOOP);
	//glColor3f(0.0, 0.0, 0.0);
	//for (i = 0; i < BP; i++)
	//	glVertex2f(bx[i], by[i]);
	//glEnd();

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);

	glutInitWindowSize(400, 400);  // �E�B���h�E�T�C�Y��400x400�h�b�g
	glutInitWindowPosition(600, 300);  // �E�B���h�E�T�C�Y�̕\���ʒu�̎w��
	glutCreateWindow("simple");
	glOrtho(-5.0, 5.0, -5.0, 5.0, -1.0, 1.0);

	printf("�J�n���܂��B�����L�[�������Ă��������B");  getchar();

	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}