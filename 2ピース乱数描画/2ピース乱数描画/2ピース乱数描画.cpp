#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<GL/glut.h>
#define NP 8

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
	int dummy, i = 0;
	double r = 0.2;
	double x[4], y[4];//���
	double Qx[NP], Qy[NP];	//�V���G�b�g���W
	double ax[NP], ay[NP];	//a���W
	double bx[NP], by[NP];  //b���W
	double ran[3];          //�����p
	char str[256];

	glClearColor(1.0, 1.0, 1.0, 1.0);

	//���
	x[0] = -5; y[0] = 0;
	x[1] = 5; y[1] = 0;
	x[2] = 0; y[2] = -5;
	x[3] = 0; y[3] = 5;

	//���V���G�b�g���W
	Qx[0] = 1.0; Qy[0] = 0.0;
	Qx[1] = 2.0; Qy[1] = 1.1;
	Qx[2] = 2.0; Qy[2] = 2.0;
	Qx[3] = 1.5; Qy[3] = 2.0;
	Qx[4] = 1.5; Qy[4] = 3.1;
	Qx[5] = 0.5; Qy[5] = 2.0;
	Qx[6] = 0.0; Qy[6] = 2.0;
	Qx[7] = 0.0; Qy[7] = 0.0;

	//�܊p�`-pieace1
	ax[0] = -1.0; ay[0] = -1.0;
	ax[1] = 0.0; ay[1] = -1.0;
	ax[2] = 1.0; ay[2] = 0.1;
	ax[3] = 1.0; ay[3] = 1.0;
	ax[4] = -1.0; ay[4] = 1.0;

	//�O�p�`-pieace2
	bx[0] = 0.0; by[0] = -1.0;
	bx[1] = 1.0; by[1] = -1.0;
	bx[2] = 1.0; by[2] = 0.1;


	//�ȉ��A�j���[�V�����̕`��
	for (;;){
		double time1 = (double)clock() / CLOCKS_PER_SEC;
		for (;;){
			double time2 = (double)clock() / CLOCKS_PER_SEC;
			if (time2 - time1 > 0.1) break;
		}

		glClear(GL_COLOR_BUFFER_BIT);



		//���V���G�b�g�`��
		glBegin(GL_POLYGON);
		glColor3f(1.0, 0.8, 1.0);
		for (i = 0; i<NP; i++)
			glVertex2f(Qx[i], Qy[i]);
		glEnd();

		//���
		glBegin(GL_LINES);
		glColor3f(1.0, 0.0, 0.0);
		for (i = 0; i<4; i++)
			glVertex2f(x[i], y[i]);
		glEnd();

		//���W����
		srand((unsigned int)time(NULL));
		dummy = rand();
		dummy = rand();
		ran[0] = (double)(rand() % 10001 - 5000) / 10000;
		ran[1] = (double)(rand() % 10001 - 5000) / 10000;
		ran[2] = (double)(rand() % 10001 - 5000) / 10000;
		ran[3] = (double)(rand() % 10001 - 5000) / 10000;

		//���x���̔ԍ��\��
		glColor3f(0.8, 0.0, 1.0);
		for (i = 0; i < NP; i++){
			sprintf_s(str, "%d", i + 1);
			render_string(Qx[i], Qy[i], str);
		}

		//pieace1
		glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.0);
		for (i = 0; i < 5; i++)
			glVertex2f(ax[i], ay[i]);
		glEnd();

		//pieace2
		glBegin(GL_LINE_LOOP);
		glColor3f(0.0, 0.0, 0.0);
		for (i = 0; i < 3; i++)
			glVertex2f(bx[i], by[i]);
		glEnd();

		glFlush();

		//���W�̍X�V
		ax[0] -= ran[0]; ax[1] -= ran[0]; ax[2] -= ran[0]; ax[3] -= ran[0]; ax[4] -= ran[0];
		ay[0] -= ran[1]; ay[1] -= ran[1]; ay[2] -= ran[1]; ay[3] -= ran[1]; ay[4] -= ran[1];
		bx[0] -= ran[2]; bx[1] -= ran[2]; bx[2] -= ran[2];
		by[0] -= ran[3]; by[1] -= ran[3]; by[2] -= ran[3];

		printf("%lf\n", ax[0]);
	}
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
