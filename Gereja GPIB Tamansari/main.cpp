#include <windows.h>
#include <GL/glut.h>
#include <math.h>
bool buka=true,bukaatap=true,bukabalkon=true,bukasisiatas=true;
float a =1.0,gerak=0,x,y;
int is_depth;
float xrot = 0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;
bool mousedown =false;

void initGL() {
   glClearColor((float)77/255.0f,(float)72/255.0f,(float)63/255.0f,1);
   glClearDepth(1.0f);
   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LEQUAL);
   glShadeModel(GL_SMOOTH);
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
   glEnable(GL_BLEND);
glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
is_depth=1;
}

void idle(){
	if (!mousedown){
	xrot+=0.3f;
	yrot+=0.4f;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON&& state == GLUT_DOWN){
	mousedown=true;
	xdiff=x-yrot;
	ydiff=-y+xrot;
	}
	else{
	mousedown = false;
	}
	glutPostRedisplay();
}
void mousemotion(int x, int y){
		if (mousedown){
		yrot=x-xdiff;
		xrot=y+ydiff;

		glutPostRedisplay();
		}
	}

void circle(float r, float x, float y) {

	float i = 0.0f;

        glBegin(GL_TRIANGLE_FAN);

        glVertex3f(x, 0.0015f,y); // Center
        for(i = 0.0f; i <= 360; i++)
                glVertex3f(r*cos(3.14 * i / 180.0) + x,0.0015f, r*sin(3.14 * i / 180.0) + y);

        glEnd();
}
void circleup(float r, float x, float y,float z) {

	float i = 0.0f;

        glBegin(GL_TRIANGLE_FAN);

        glVertex3f(x, y,1.0015f+z); // Center
        for(i = 0.0f; i <= 361; i++)
                glVertex3f(r*cos(3.14 * i / 180.0) + x, r*sin(3.14 * i / 180.0) + y,1.0015f+z);

        glEnd();
}
void halfcircleup(float r, float x, float y,float z) {

	float i = 0.0f;

        glBegin(GL_TRIANGLE_FAN);

        glVertex3f(x, y,1.0015f+z); // Center
        for(i = 0.0f; i <= 180; i++)
                glVertex3f(r*cos(3.14 * i / 180.0) + x, r*sin(3.14 * i / 180.0) + y,1.0015f+z);

        glEnd();
}

void halfcirclesamping(float r, float x, float y,float z) {

	float i = 0.0f;

        glBegin(GL_TRIANGLE_FAN);

        glVertex3f(1.0015f+x, y,z); // Center
        for(i = 0.0f; i <= 180; i++)
                glVertex3f(1.0015f+x, r*sin(3.14 * i / 180.0) + y,r*cos(3.14 * i / 180.0) + z);

        glEnd();
}
void cylinder( float r1, float r2,float t,float x, float y,float z){
	//gluCylinder(quadric, bottomRadius, topRadius, height, slices, rings)
GLUquadric *quadric = gluNewQuadric();
    gluQuadricTexture(quadric, true);
    glPushMatrix();                        //save first position
        //Draw the cylinder
        glTranslatef(x, y, z);      //Move to cylinder center
        glPushMatrix();                       //save cylinder center
            glRotatef(90, 1.0f, 0.0f, 0.f);  //cylinder rotation
            //Cylinder render (fill or line)
			gluQuadricDrawStyle(quadric, GLU_FILL);
            gluCylinder(quadric, r1, r2, t, 20, 20);
        glPopMatrix();
}
void kotak(float x, float y, float z, float px, float py, float pz){
   glBegin(GL_POLYGON);//kanan
   glVertex3f(x+px,y,z);
   glVertex3f(x+px,y+py,z);
   glVertex3f(x+px,y+py,z+pz);
   glVertex3f(x+px,y,z+pz);
   glEnd();
    glBegin(GL_POLYGON);//kiri
   glVertex3f(x,y,z);
   glVertex3f(x,y+py,z);
   glVertex3f(x,y+py,z+pz);
   glVertex3f(x,y,z+pz);
   glEnd();
   glBegin(GL_POLYGON);//depan
   glVertex3f(x+px,y,z+pz);
   glVertex3f(x+px,y+py,z+pz);
   glVertex3f(x,y+py,z+pz);
   glVertex3f(x,y,z+pz);
   glEnd();
    glBegin(GL_POLYGON);//belakang
  glVertex3f(x+px,y,z);
   glVertex3f(x+px,y+py,z);
   glVertex3f(x,y+py,z);
   glVertex3f(x,y,z);
   glEnd();
  glBegin(GL_POLYGON);//atas
   glVertex3f(x,y+py,z);
   glVertex3f(x+px,y+py,z);
   glVertex3f(x+px,y+py,z+pz);
   glVertex3f(x,y+py,z+pz);
   glEnd();
    glBegin(GL_POLYGON);//bawah
    glVertex3f(x,y,z);
   glVertex3f(x+px,y,z);
   glVertex3f(x+px,y,z+pz);
   glVertex3f(x,y,z+pz);
   glEnd();
}
void kotakbalkon(float x, float y, float z, float px, float py, float pz){
  glColor4f((float)177/255.0f,(float)182/255.0f,(float)205/255.0f,1);
	glBegin(GL_POLYGON);//kanan
   glVertex3f(x+px,y,z);
   glVertex3f(x+px,y+py,z);
   glVertex3f(x+px,y+py,z+pz);
   glVertex3f(x+px,y,z+pz);
   glEnd();
    glBegin(GL_POLYGON);//kiri
   glVertex3f(x,y,z);
   glVertex3f(x,y+py,z);
   glVertex3f(x,y+py,z+pz);
   glVertex3f(x,y,z+pz);
   glEnd();
   glBegin(GL_POLYGON);//depan
   glVertex3f(x+px,y,z+pz);
   glVertex3f(x+px,y+py,z+pz);
   glVertex3f(x,y+py,z+pz);
   glVertex3f(x,y,z+pz);
   glEnd();
    glBegin(GL_POLYGON);//belakang
  glVertex3f(x+px,y,z);
   glVertex3f(x+px,y+py,z);
   glVertex3f(x,y+py,z);
   glVertex3f(x,y,z);
   glEnd();
    glBegin(GL_POLYGON);//bawah
    glVertex3f(x,y,z);
   glVertex3f(x+px,y,z);
   glVertex3f(x+px,y,z+pz);
   glVertex3f(x,y,z+pz);
   glEnd();
   glColor4f((float)218/255.0f,(float)150/255.0f,(float)62/255.0f,1);
  glBegin(GL_POLYGON);//atas
   glVertex3f(x,y+py,z);
   glVertex3f(x+px,y+py,z);
   glVertex3f(x+px,y+py,z+pz);
   glVertex3f(x,y+py,z+pz);
   glEnd();

}

void kotaksugoiline(float x, float y, float z, float px, float py, float pz){
	glLineWidth(3);
	glBegin(GL_LINE_STRIP);//kanan
   glVertex3f(x+px,y,z);
   glVertex3f(x+px,y+py,z);
   glVertex3f(x+px,y+py,z+pz);
   glVertex3f(x+px,y,z+pz);
   glEnd();
    glBegin(GL_LINE_STRIP);//kiri
   glVertex3f(x,y,z);
   glVertex3f(x,y+py,z);
   glVertex3f(x,y+py,z+pz);
   glVertex3f(x,y,z+pz);
   glEnd();
   if(buka){
   glBegin(GL_LINE_STRIP);//depan
   glVertex3f(x+px,y,z+pz);
   glVertex3f(x+px,y+py,z+pz);
   glVertex3f(x,y+py,z+pz);
   glVertex3f(x,y,z+pz);
   glEnd();
   glBegin(GL_LINE_STRIP);//atas
   glVertex3f(x,y+py,z);
   glVertex3f(x+px,y+py,z);
   glVertex3f(x+px,y+py,z+pz);
   glVertex3f(x,y+py,z+pz);
   glEnd();}
   glBegin(GL_LINE_STRIP);//belakang
   glVertex3f(x+px,y,z);
   glVertex3f(x+px,y+py,z);
   glVertex3f(x,y+py,z);
   glVertex3f(x,y,z);
   glEnd();
    glBegin(GL_LINE_STRIP);//bawah
    glVertex3f(x,y,z);
   glVertex3f(x+px,y,z);
   glVertex3f(x+px,y,z+pz);
   glVertex3f(x,y,z+pz);
   glEnd();
   glLineWidth(1);
}
void kotaktangga(float x, float y, float z, float px, float py, float pz){
  glColor4f((float)228/255.0f,(float)228/255.0f,(float)230/255.0f,1);
	glBegin(GL_POLYGON);//kanan
   glVertex3f(x+px,y,z);
   glVertex3f(x+px,y+py,z);
   glVertex3f(x+px,y+py,z+pz);
   glVertex3f(x+px,y,z+pz);
   glEnd();
    glBegin(GL_POLYGON);//kiri
   glVertex3f(x,y,z);
   glVertex3f(x,y+py,z);
   glVertex3f(x,y+py,z+pz);
   glVertex3f(x,y,z+pz);
   glEnd();
   glBegin(GL_POLYGON);//depan
   glVertex3f(x+px,y,z+pz);
   glVertex3f(x+px,y+py,z+pz);
   glVertex3f(x,y+py,z+pz);
   glVertex3f(x,y,z+pz);
   glEnd();
    glBegin(GL_POLYGON);//belakang
  glVertex3f(x+px,y,z);
   glVertex3f(x+px,y+py,z);
   glVertex3f(x,y+py,z);
   glVertex3f(x,y,z);
   glEnd();
   glColor4f((float)251/255.0f,(float)250/255.0f,(float)255/255.0f,1);
  glBegin(GL_POLYGON);//atas
   glVertex3f(x,y+py,z);
   glVertex3f(x+px,y+py,z);
   glVertex3f(x+px,y+py,z+pz);
   glVertex3f(x,y+py,z+pz);
   glEnd();
    glBegin(GL_POLYGON);//bawah
    glVertex3f(x,y,z);
   glVertex3f(x+px,y,z);
   glVertex3f(x+px,y,z+pz);
   glVertex3f(x,y,z+pz);
   glEnd();
}
void kotakmiringdepan(float x, float y, float z, float px, float py, float pz,float ppy){
   glBegin(GL_POLYGON);//kanan
   glVertex3f(x+px,y+ppy,z);
   glVertex3f(x+px,y+py+ppy,z);
   glVertex3f(x+px,y+py,z+pz);
   glVertex3f(x+px,y,z+pz);
   glEnd();
    glBegin(GL_POLYGON);//kiri
   glVertex3f(x,y+ppy,z);
   glVertex3f(x,y+py+ppy,z);
   glVertex3f(x,y+py,z+pz);
   glVertex3f(x,y,z+pz);
   glEnd();
   glBegin(GL_POLYGON);//depan
   glVertex3f(x+px,y,z+pz);
   glVertex3f(x+px,y+py,z+pz);
   glVertex3f(x,y+py,z+pz);
   glVertex3f(x,y,z+pz);
   glEnd();
    glBegin(GL_POLYGON);//belakang
  glVertex3f(x+px,y+ppy,z);
   glVertex3f(x+px,y+py+ppy,z);
   glVertex3f(x,y+py+ppy,z);
   glVertex3f(x,y+ppy,z);
   glEnd();

    glBegin(GL_POLYGON);//bawah
    glVertex3f(x,y+ppy,z);
   glVertex3f(x+px,y+ppy,z);
   glVertex3f(x+px,y,z+pz);
   glVertex3f(x,y,z+pz);
   glEnd();
   glColor4f((float)228/255.0f,(float)242/255.0f,(float)235/255.0f,1);
   glBegin(GL_POLYGON);//atas
   glVertex3f(x,y+py+ppy,z);
   glVertex3f(x+px,y+py+ppy,z);
   glVertex3f(x+px,y+py,z+pz);
   glVertex3f(x,y+py,z+pz);
   glEnd();
}

void kotakmiringdepanbalkon(float x, float y, float z, float px, float py, float pz,float ppy){
   glBegin(GL_POLYGON);//kanan
   glVertex3f(x+px,y+ppy,z);
   glVertex3f(x+px,y+py+ppy,z);
   glVertex3f(x+px,y+py,z+pz);
   glVertex3f(x+px,y,z+pz);
   glEnd();
    glBegin(GL_POLYGON);//kiri
   glVertex3f(x,y+ppy,z);
   glVertex3f(x,y+py+ppy,z);
   glVertex3f(x,y+py,z+pz);
   glVertex3f(x,y,z+pz);
   glEnd();
   glBegin(GL_POLYGON);//depan
   glVertex3f(x+px,y,z+pz);
   glVertex3f(x+px,y+py,z+pz);
   glVertex3f(x,y+py,z+pz);
   glVertex3f(x,y,z+pz);
   glEnd();
    glBegin(GL_POLYGON);//belakang
  glVertex3f(x+px,y+ppy,z);
   glVertex3f(x+px,y+py+ppy,z);
   glVertex3f(x,y+py+ppy,z);
   glVertex3f(x,y+ppy,z);
   glEnd();

    glBegin(GL_POLYGON);//bawah
    glVertex3f(x,y+ppy,z);
   glVertex3f(x+px,y+ppy,z);
   glVertex3f(x+px,y,z+pz);
   glVertex3f(x,y,z+pz);
   glEnd();
   glBegin(GL_POLYGON);//atas
   glVertex3f(x,y+py+ppy,z);
   glVertex3f(x+px,y+py+ppy,z);
   glVertex3f(x+px,y+py,z+pz);
   glVertex3f(x,y+py,z+pz);
   glEnd();
}
void kotakmiringbelakang(float x, float y, float z, float px, float py, float pz,float ppy){
   glBegin(GL_POLYGON);//kanan
   glVertex3f(x+px,y,z);
   glVertex3f(x+px,y+py,z);
   glVertex3f(x+px,y+py+ppy,z+pz);
   glVertex3f(x+px,y+ppy,z+pz);
   glEnd();
    glBegin(GL_POLYGON);//kiri
   glVertex3f(x,y,z);
   glVertex3f(x,y+py,z);
   glVertex3f(x,y+py+ppy,z+pz);
   glVertex3f(x,y+ppy,z+pz);
   glEnd();
   glBegin(GL_POLYGON);//depan
   glVertex3f(x+px,y+ppy,z+pz);
   glVertex3f(x+px,y+py+ppy,z+pz);
   glVertex3f(x,y+py+ppy,z+pz);
   glVertex3f(x,y+ppy,z+pz);
   glEnd();
    glBegin(GL_POLYGON);//belakang
  glVertex3f(x+px,y,z);
   glVertex3f(x+px,y+py,z);
   glVertex3f(x,y+py,z);
   glVertex3f(x,y,z);
   glEnd();

    glBegin(GL_POLYGON);//bawah
    glVertex3f(x,y,z);
   glVertex3f(x+px,y,z);
   glVertex3f(x+px,y+ppy,z+pz);
   glVertex3f(x,y+ppy,z+pz);
   glEnd();

   glBegin(GL_POLYGON);//atas
   glVertex3f(x,y+py,z);
   glVertex3f(x+px,y+py,z);
   glVertex3f(x+px,y+py+ppy,z+pz);
   glVertex3f(x,y+py+ppy,z+pz);
   glEnd();
}
void kotakmiringkiri(float x, float y, float z, float px, float py, float pz,float ppy){
  glColor4f((float)177/255.0f,(float)182/255.0f,(float)205/255.0f,1);
	glBegin(GL_POLYGON);//kanan
   glVertex3f(x+px,y+ppy,z);
   glVertex3f(x+px,y+py+ppy,z);
   glVertex3f(x+px,y+py+ppy,z+pz);
   glVertex3f(x+px,y+ppy,z+pz);
   glEnd();
    glBegin(GL_POLYGON);//kiri
   glVertex3f(x,y,z);
   glVertex3f(x,y+py,z);
   glVertex3f(x,y+py,z+pz);
   glVertex3f(x,y,z+pz);
   glEnd();
   glBegin(GL_POLYGON);//depan
   glVertex3f(x+px,y+ppy,z+pz);
   glVertex3f(x+px,y+py+ppy,z+pz);
   glVertex3f(x,y+py,z+pz);
   glVertex3f(x,y,z+pz);
   glEnd();
   glBegin(GL_POLYGON);//belakang
   glVertex3f(x+px,y+ppy,z);
   glVertex3f(x+px,y+py+ppy,z);
   glVertex3f(x,y+py,z);
   glVertex3f(x,y,z);
   glEnd();
   glBegin(GL_POLYGON);//bawah
   glVertex3f(x,y,z);
   glVertex3f(x+px,y+ppy,z);
   glVertex3f(x+px,y+ppy,z+pz);
   glVertex3f(x,y,z+pz);
   glEnd();
  glColor4f((float)218/255.0f,(float)150/255.0f,(float)62/255.0f,1);
  glBegin(GL_POLYGON);//atas
   glVertex3f(x,y+py,z);
   glVertex3f(x+px,y+py+ppy,z);
   glVertex3f(x+px,y+py+ppy,z+pz);
   glVertex3f(x,y+py,z+pz);
   glEnd();

}
void kotakmiringkanan(float x, float y, float z, float px, float py, float pz,float ppy){
   glColor4f((float)177/255.0f,(float)182/255.0f,(float)205/255.0f,1);
	glBegin(GL_POLYGON);//kanan
   glVertex3f(x+px,y,z);
   glVertex3f(x+px,y+py,z);
   glVertex3f(x+px,y+py,z+pz);
   glVertex3f(x+px,y,z+pz);
   glEnd();
    glBegin(GL_POLYGON);//kiri
   glVertex3f(x,y+ppy,z);
   glVertex3f(x,y+py+ppy,z);
   glVertex3f(x,y+py+ppy,z+pz);
   glVertex3f(x,y+ppy,z+pz);
   glEnd();
   glBegin(GL_POLYGON);//depan
   glVertex3f(x+px,y,z+pz);
   glVertex3f(x+px,y+py,z+pz);
   glVertex3f(x,y+py+ppy,z+pz);
   glVertex3f(x,y+ppy,z+pz);
   glEnd();
    glBegin(GL_POLYGON);//belakang
  glVertex3f(x+px,y,z);
   glVertex3f(x+px,y+py,z);
   glVertex3f(x,y+py+ppy,z);
   glVertex3f(x,y+ppy,z);
   glEnd();
    glBegin(GL_POLYGON);//bawah
    glVertex3f(x,y+ppy,z);
   glVertex3f(x+px,y,z);
   glVertex3f(x+px,y,z+pz);
   glVertex3f(x,y+ppy,z+pz);
   glEnd();
   glColor4f((float)218/255.0f,(float)150/255.0f,(float)62/255.0f,1);
  glBegin(GL_POLYGON);//atas
   glVertex3f(x,y+py+ppy,z);
   glVertex3f(x+px,y+py,z);
   glVertex3f(x+px,y+py,z+pz);
   glVertex3f(x,y+py+ppy,z+pz);
   glEnd();

}
void kotaksugoi(float x, float y, float z, float px, float py, float pz){
   glBegin(GL_POLYGON);//kanan
   glVertex3f(x+px,y,z);
   glVertex3f(x+px,y+py,z);
   glVertex3f(x+px,y+py,z+pz);
   glVertex3f(x+px,y,z+pz);
   glEnd();
    glBegin(GL_POLYGON);//kiri
   glVertex3f(x,y,z);
   glVertex3f(x,y+py,z);
   glVertex3f(x,y+py,z+pz);
   glVertex3f(x,y,z+pz);
   glEnd();
   if(buka){
   glBegin(GL_POLYGON);//depan
   glVertex3f(x+px,y,z+pz);
   glVertex3f(x+px,y+py,z+pz);
   glVertex3f(x,y+py,z+pz);
   glVertex3f(x,y,z+pz);
   glEnd();
    glBegin(GL_POLYGON);//atas
   glVertex3f(x,y+py,z);
   glVertex3f(x+px,y+py,z);
   glVertex3f(x+px,y+py,z+pz);
   glVertex3f(x,y+py,z+pz);
   glEnd();}

    glBegin(GL_POLYGON);//belakang
  glVertex3f(x+px,y,z);
   glVertex3f(x+px,y+py,z);
   glVertex3f(x,y+py,z);
   glVertex3f(x,y,z);
   glEnd();

   glColor3f(1,1,1);
    glBegin(GL_POLYGON);//bawah
    glVertex3f(x,y,z);
   glVertex3f(x+px,y,z);
   glVertex3f(x+px,y,z+pz);
   glVertex3f(x,y,z+pz);
   glEnd();
}


void trapesium(float bx,float by, float bz,float ax,float ay, float az,float a, float b){
	//depan
	glBegin(GL_POLYGON);
	glVertex3f(bx,by,bz);
	glVertex3f(bx+b,by,bz);
	glVertex3f(ax+a,ay,az);
	glVertex3f(ax,ay,az);
	glEnd();
	//kanan
	glBegin(GL_POLYGON);
	glVertex3f(bx+b,by,bz);
	glVertex3f(bx+b,by,bz-b);
	glVertex3f(ax+a,ay,az-a);
	glVertex3f(ax+a,ay,az);
	glEnd();
	//kiri
	glBegin(GL_POLYGON);
	glVertex3f(bx,by,bz);
	glVertex3f(bx,by,bz-b);
	glVertex3f(ax,ay,az-a);
	glVertex3f(ax,ay,az);
	glEnd();
	//belakang
	glBegin(GL_POLYGON);
	glVertex3f(bx,by,bz-b);
	glVertex3f(bx+b,by,bz-b);
	glVertex3f(ax+a,ay,az-a);
	glVertex3f(ax,ay,az-a);
	glEnd();
	//atas
	glBegin(GL_POLYGON);
	glVertex3f(ax,ay,az);
	glVertex3f(ax+a,ay,az);
	glVertex3f(ax+a,ay,az-a);
	glVertex3f(ax,ay,az-a);
	glEnd();
}

void baloksegitiga(float x, float y, float z, float px, float py, float pz)
{

   glBegin(GL_POLYGON);//kanan
   glVertex3f(x+px,y,z);
   glVertex3f(x+px,y+py,z+pz);
   glVertex3f(x+px,y,z+pz);
   glEnd();
    glBegin(GL_POLYGON);//kiri
   glVertex3f(x,y,z);
   glVertex3f(x,y+py,z+pz);
   glVertex3f(x,y,z+pz);
   glEnd();
   glBegin(GL_POLYGON);//depan
   glVertex3f(x+px,y,z+pz);
   glVertex3f(x+px,y+py,z+pz);
   glVertex3f(x,y+py,z+pz);
   glVertex3f(x,y,z+pz);
   glEnd();
    glBegin(GL_POLYGON);//belakang
  glVertex3f(x+px,y,z);
   glVertex3f(x+px,y+py,z+pz);
   glVertex3f(x,y+py,z+pz);
   glVertex3f(x,y,z);
   glEnd();
    glBegin(GL_POLYGON);//bawah
    glVertex3f(x,y,z);
   glVertex3f(x+px,y,z);
   glVertex3f(x+px,y,z+pz);
   glVertex3f(x,y,z+pz);
   glEnd();
}

void tanah(int x, int z){
	glColor3f(0.6,0.6,0.6);
	glBegin(GL_POLYGON);
	glVertex3f(-3-x,0,2+z);
	glVertex3f(2+x,0,2+z);
	glVertex3f(2+x,0,-3-z);
	glVertex3f(-3-x,0,-3-z);
	glEnd();
}
void hiasantower(){

	glColor4f((float)234/255.0f,(float)245/255.0f,(float)239/255.0f,1);
	 glBegin(GL_POLYGON);
	glVertex3f(-0.235,1.475,1.10001);
	glVertex3f(-0.235,1.215,1.10001);
	glVertex3f(-0.145,1.215,1.10001);
	glVertex3f(-0.145,1.475,1.10001);
	glEnd();
	for (float i=0;i<6*0.04;i=i+0.04){
		glColor4f((float)234/255.0f,(float)245/255.0f,(float)239/255.0f,1);
	kotakmiringdepan(-0.23,1.42-i,1.1,0.08,0.01,0.06,0.04);
	}
	glColor3f(0,0,0);
    glBegin(GL_POLYGON);
	glVertex3f(-0.23,1.47,1.100015);
	glVertex3f(-0.23,1.22,1.100015);
	glVertex3f(-0.15,1.22,1.100015);
	glVertex3f(-0.15,1.47,1.100015);
	glEnd();

	/*glColor4f((float)234/255.0f,(float)245/255.0f,(float)239/255.0f,1);
	halfcircleup(0.04,-0.14,1.47,0.1);
	glColor4f((float)228/255.0f,(float)238/255.0f,(float)233/255.0f,1);
	halfcircleup(0.03,-0.14,1.47,0.10001);
	glColor4f((float)234/255.0f,(float)245/255.0f,(float)239/255.0f,1);
	halfcircleup(0.02,-0.14,1.47,0.100015);
	glColor3f(0,0,0);
	circleup(-0.045,-0.135,1.475,0.10002);
	circleup(-0.045,-0.14,1.48,0.10002);
	circleup(-0.045,-0.145,1.475,0.10002);
*/

}
void kumpulan_hiasan_tower(){
glPushMatrix();
glTranslatef(0,-0.05,-0.1);
hiasantower();
glTranslatef(-0.1,0,0);
hiasantower();
glPopMatrix();
}
void salibA(){
	glColor4f((float)250/255.0f,(float)250/255.0f,(float)250/255.0f,1);
	kotak(-0.28,1.13,1.06,0.08,0.27,0.05);
	kotak(-0.34,1.3,1.06,0.2,0.05,0.05);

	glColor4f((float)168/255.0f,(float)67/255.0f,(float)47/255.0f,1);
	kotak(-0.27,1.14,1.11,0.06,0.25,0.01);
	kotak(-0.33,1.31,1.11,0.18,0.03,0.01);

}
void tower(){
//kepala
	glColor4f((float)168/255.0f,(float)171/255.0f,(float)181/255.0f,1);
	kotak(-0.4,0.9,0.7,0.3,0.7,0.3);
//topi
	glColor4f((float)255/255.0f,(float)255/255.0f,(float)204/255.0f,1);
	glBegin(GL_POLYGON);
	glVertex3f(-0.53,1.6,1.13);
	glVertex3f(0.03,1.6,1.13);
	glVertex3f(0.03,1.6,0.57);
	glVertex3f(-0.53,1.6,0.57);
	glEnd();
	glColor4f((float)129/255.0f,(float)119/255.0f,(float)98/255.0f,1);
	//void trapesium(float bx,float by, float bz,float ax,float ay, float az,float a, float b)
	glPushMatrix();
	glTranslatef(0,0,-0.1);
	trapesium(-0.55,1.6,1.25,-0.40,1.7,1.1,0.3,0.6);
	trapesium(-0.40,1.7,1.1,-0.275,2,0.975,0.05,0.3);
	cylinder(0.003,0.01,0.5,-0.25,2.5,0.95);
	glPopMatrix();
	salibA();
	kumpulan_hiasan_tower();

}
void lekukan_depan(){
	//sisi kanan

	glColor3f(1,1,1);
	glBegin(GL_POLYGON);//depan
	glVertex3f(-0.82,0.8,1.12);
	glVertex3f(-0.82,0.81,1.12);
	glVertex3f(-0.65,0.81,1.12);
	glVertex3f(-0.65,0.8,1.12);
	glEnd();

	glBegin(GL_POLYGON);//belakang
	glVertex3f(-0.82,0.8,1);
	glVertex3f(-0.82,0.81,1);
	glVertex3f(-0.65,0.81,1);
	glVertex3f(-0.65,0.8,1);
	glEnd();

	glBegin(GL_POLYGON);//kiri
	glVertex3f(-0.82,0.8,1.12);
	glVertex3f(-0.82,0.81,1);
	glVertex3f(-0.82,0.81,1);
	glVertex3f(-0.82,0.8,1.12);
	glEnd();

	glBegin(GL_POLYGON);//bawah
	glVertex3f(-0.82,0.8,1);
	glVertex3f(-0.82,0.8,1.12);
	glVertex3f(-0.65,0.8,1.12);
	glVertex3f(-0.65,0.8,1);
	glEnd();
	glColor4f((float)243/255.0f,(float)142/255.0f,(float)99/255.0f,1);
	glBegin(GL_POLYGON);//atas
	glVertex3f(-0.82,0.81,1);
	glVertex3f(-0.82,0.81,1.12);
	glVertex3f(-0.65,0.81,1.12);
	glVertex3f(-0.65,0.81,1);
	glEnd();

	//sisi kiri
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);//depan
	glVertex3f(0.32,0.8,1.12);
	glVertex3f(0.32,0.81,1.12);
	glVertex3f(0.15,0.81,1.12);
	glVertex3f(0.15,0.8,1.12);
	glEnd();

	glBegin(GL_POLYGON);//belakang
	glVertex3f(0.32,0.8,1);
	glVertex3f(0.32,0.81,1);
	glVertex3f(0.15,0.81,1);
	glVertex3f(0.15,0.8,1);
	glEnd();

	glBegin(GL_POLYGON);//kanan
	glVertex3f(0.32,0.8,1.12);
	glVertex3f(0.32,0.81,1);
	glVertex3f(0.32,0.81,1);
	glVertex3f(0.32,0.8,1.12);
	glEnd();

	glBegin(GL_POLYGON);//bawah
	glVertex3f(0.32,0.8,1);
	glVertex3f(0.32,0.8,1.12);
	glVertex3f(0.15,0.8,1.12);
	glVertex3f(0.15,0.8,1);
	glEnd();
	glColor4f((float)243/255.0f,(float)142/255.0f,(float)99/255.0f,1);
	glBegin(GL_POLYGON);//atas
	glVertex3f(0.32,0.81,1);
	glVertex3f(0.32,0.81,1.12);
	glVertex3f(0.15,0.81,1.12);
	glVertex3f(0.15,0.81,1);
	glEnd();

	//sisi kiri samping
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);//depan
	glVertex3f(-0.06,1.05,1.12);
	glVertex3f(-0.05,1.05,1.12);
	glVertex3f(0.15,0.81,1.12);
	glVertex3f(0.15,0.8,1.12);
	glEnd();

	glBegin(GL_POLYGON);//belakang
	glVertex3f(-0.06,1.05,1);
	glVertex3f(-0.05,1.05,1);
	glVertex3f(0.15,0.81,1);
	glVertex3f(0.15,0.8,1);
	glEnd();

	glBegin(GL_POLYGON);//kanan
	glVertex3f(0.15,0.8,1.12);
	glVertex3f(0.15,0.81,1);
	glVertex3f(0.15,0.81,1);
	glVertex3f(0.15,0.8,1.12);
	glEnd();

	glBegin(GL_POLYGON);//bawah
	glVertex3f(-0.06,1.05,1);
	glVertex3f(-0.06,1.05,1.12);
	glVertex3f(0.15,0.8,1.12);
	glVertex3f(0.15,0.8,1);
	glEnd();
	glColor4f((float)243/255.0f,(float)142/255.0f,(float)99/255.0f,1);
	glBegin(GL_POLYGON);//atas
	glVertex3f(-0.05,1.05,1);
	glVertex3f(-0.05,1.05,1.12);
	glVertex3f(0.15,0.81,1.12);
	glVertex3f(0.15,0.81,1);
	glEnd();

	//sisi kanan samping
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);//depan
	glVertex3f(-0.65,0.8,1.12);
	glVertex3f(-0.65,0.81,1.12);
	glVertex3f(-0.35,1.05,1.12);
	glVertex3f(-0.35,1.04,1.12);
	glEnd();

	glBegin(GL_POLYGON);//belakang
	glVertex3f(-0.65,0.8,1);
	glVertex3f(-0.65,0.81,1);
	glVertex3f(-0.35,1.05,1);
	glVertex3f(-0.35,1.04,1);
	glEnd();

	glBegin(GL_POLYGON);//kanan
	glVertex3f(-0.35,1.04,1.12);
	glVertex3f(-0.35,1.05,1);
	glVertex3f(-0.35,1.05,1);
	glVertex3f(-0.35,1.04,1.12);
	glEnd();

	glBegin(GL_POLYGON);//bawah
	glVertex3f(-0.65,0.8,1);
	glVertex3f(-0.65,0.8,1.12);
	glVertex3f(-0.35,1.05,1.12);
	glVertex3f(-0.35,1.04,1);
	glEnd();
	glColor4f((float)243/255.0f,(float)142/255.0f,(float)99/255.0f,1);
	glBegin(GL_POLYGON);//atas
	glVertex3f(-0.65,0.81,1);
	glVertex3f(-0.65,0.81,1.12);
	glVertex3f(-0.35,1.05,1.12);
	glVertex3f(-0.35,1.05,1);
	glEnd();

	//sisi tengah atas
	glColor3f(1,1,1);
	kotak(-0.40,1.05,1,0.3,0.05,0.1);

	//sisi tengah
	glColor4f((float)151/255.0f,(float)156/255.0f,(float)182/255.0f,1);
	glBegin(GL_POLYGON);//atas
	glVertex3f(-0.70,0.8,1.11);
	glVertex3f(-0.40,1.04,1.11);
	glVertex3f(-0.11,1.05,1.11);
	glVertex3f(0.20,0.8,1.11);
	glEnd();

}

void jendela_deket_entrance(){
	glColor4f((float)151/255.0f,(float)156/255.0f,(float)182/255.0f,1);
	glBegin(GL_POLYGON);
	glVertex3f(-0.9,0.25,0.5001);
	glVertex3f(-0.9,0.65,0.5001);
	glVertex3f(-1.15,0.65,0.5001);
	glVertex3f(-1.15,0.25,0.5001);
	glEnd();
	glColor4f((float)207/255.0f,(float)210/255.0f,(float)222/255.0f,1);
	glBegin(GL_POLYGON);
	glVertex3f(-0.92,0.27,0.50015);
	glVertex3f(-0.92,0.63,0.50015);
	glVertex3f(-1.13,0.63,0.50015);
	glVertex3f(-1.13,0.27,0.50015);
	glEnd();
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex3f(-0.94,0.29,0.5002);
	glVertex3f(-0.94,0.61,0.5002);
	glVertex3f(-1.11,0.61,0.5002);
	glVertex3f(-1.11,0.29,0.5002);
	glEnd();

	glColor4f((float)151/255.0f,(float)156/255.0f,(float)182/255.0f,1);
	halfcircleup(0.12,-1.025,0.65,-0.5);
	glColor4f((float)207/255.0f,(float)210/255.0f,(float)222/255.0f,1);
	halfcircleup(0.1,-1.025,0.65,-0.499);
	glColor4f((float)151/255.0f,(float)156/255.0f,(float)182/255.0f,1);
	halfcircleup(0.08,-1.025,0.65,-0.4985);
	glColor4f((float)207/255.0f,(float)210/255.0f,(float)222/255.0f,1);
	halfcircleup(0.07,-1.025,0.65,-0.498);
	glColor3f(0,0,0);
	circleup(0.015,-1.015,0.67,-0.4975);
	circleup(0.015,-1.025,0.69,-0.4975);
	circleup(0.015,-1.035,0.67,-0.4975);
	glColor4f((float)207/255.0f,(float)210/255.0f,(float)222/255.0f,1);
	float tambah=0.03;
	for (int i=0;i<11;i++){
		kotakmiringdepan(-1.11,0.61-tambah,0.50025,0.17,0.01,0.02,0.01);
	tambah+=0.03;
	}
}


void balkon(){
	glColor4f((float)151/255.0f,(float)156/255.0f,(float)182/255.0f,1);
	kotak(-0.65,0.4,1,0.1,0.05,0.2);
	glColor4f((float)177/255.0f,(float)182/255.0f,(float)205/255.0f,1);
	kotak(-0.64,0.38,1,0.08,0.05,0.15);
	kotak(-0.625,0.37,1,0.05,0.05,0.13);
	glPushMatrix();
	glTranslatef(0.7,0,0);
	glColor4f((float)151/255.0f,(float)156/255.0f,(float)182/255.0f,1);
	kotak(-0.65,0.4,1,0.1,0.05,0.2);
	glColor4f((float)177/255.0f,(float)182/255.0f,(float)205/255.0f,1);
	kotak(-0.64,0.38,1,0.08,0.05,0.15);
	kotak(-0.625,0.37,1,0.05,0.05,0.13);
	glPopMatrix();
	kotakbalkon(-0.6,0.45,1,0.05,0.05,0.2);

	kotakmiringkiri(-0.55,0.45,1,0.1,0.05,0.2,0.1);
	kotakmiringkiri(-0.45,0.55,1,0.1,0.05,0.2,0.05);
	kotakmiringkiri(-0.35,0.6,1,0.05,0.05,0.2,0.025);
	kotakmiringkiri(-0.3,0.625,1,0.05,0.05,0.2,0);

	kotakmiringkanan(-0.25,0.6,1,0.1,0.05,0.2,0.025);
	kotakmiringkanan(-0.15,0.55,1,0.1,0.05,0.2,0.05);
	kotakmiringkanan(-0.05,0.45,1,0.1,0.05,0.2,0.1);

	kotakbalkon(0.05,0.45,1,0.05,0.05,0.2);

}
void entrance(){
//tempat masuk gedung utama
	glColor4f((float)255/255.0f,(float)255/255.0f,(float)153/255.0f,1);
	kotak(-0.75,0,0.5,1,0.8,0.5);//main block
	glColor4f((float)240/255.0f,(float)185/255.0f,(float)89/255.0f,1);
	kotak(-0.7451,0,1,0.995,0.01,0.3);//alas depan

	glColor4f((float)151/255.0f,(float)156/255.0f,(float)182/255.0f,1);
	kotak(-0.8,0.7,0.5,0.05,0.1,0.6);//strip balok kanan
	kotak(-0.75,0,1,0.1,0.8,0.1);//strip pilar depan kanan
	kotak(0.25,0.7,0.5,0.05,0.1,0.6);//strip balok kiri
	kotak(0.15,0,1,0.1,0.8,0.1);//strip pilar depan kiri
	balkon();
	glColor4f((float)151/255.0f,(float)156/255.0f,(float)182/255.0f,1);
	halfcircleup(0.2,-0.26,0.42,0);
	glColor4f((float)50/255.0f,(float)36/255.0f,(float)97/255.0f,1);
	halfcircleup(0.18,-0.26,0.43,0.001);
	glColor4f((float)151/255.0f,(float)156/255.0f,(float)182/255.0f,1);
	kotak(-0.35,0.42,1.002,0.01,0.172,0.001);
	kotak(-0.18,0.42,1.002,0.01,0.172,0.001);
	//pintu
	glPushMatrix();
	glTranslatef(0.05,0,0);
	glColor4f((float)125/255.0f,(float)96/255.0f,(float)70/255.0f,1);
	glBegin(GL_POLYGON);
	glVertex3f(-0.51,0,1.001);
	glVertex3f(-0.51,0.42,1.001);
	glVertex3f(-0.31,0.42,1.001);
	glVertex3f(-0.31,0,1.001);
	glEnd();
	glColor4f((float)168/255.0f,(float)120/255.0f,(float)78/255.0f,1);
	glBegin(GL_POLYGON);
	glVertex3f(-0.46,0.05,1.0015);
	glVertex3f(-0.46,0.37,1.0015);
	glVertex3f(-0.36,0.37,1.0015);
	glVertex3f(-0.36,0.05,1.0015);
	glEnd();
	glPushMatrix();
	glTranslatef(0.2,0,0);
	glColor4f((float)125/255.0f,(float)96/255.0f,(float)70/255.0f,1);
	glBegin(GL_POLYGON);
	glVertex3f(-0.51,0,1.001);
	glVertex3f(-0.51,0.42,1.001);
	glVertex3f(-0.31,0.42,1.001);
	glVertex3f(-0.31,0,1.001);
	glEnd();
	glColor4f((float)168/255.0f,(float)120/255.0f,(float)78/255.0f,1);
	glBegin(GL_POLYGON);
	glVertex3f(-0.46,0.05,1.0015);
	glVertex3f(-0.46,0.37,1.0015);
	glVertex3f(-0.36,0.37,1.0015);
	glVertex3f(-0.36,0.05,1.0015);
	glEnd();
	glPopMatrix();
	glPopMatrix();

	//something front lekukan depan
	lekukan_depan();

	glPushMatrix();
	glTranslatef(0,-0.1,0);
	tower();
	glPopMatrix();

}
void kursi_panjang(){
	glColor4f((float)171/255.0f,(float)94/255.0f,(float)35/255.0f,1);
	kotak(-1,0.08,-0.5,0.13,0.04,0.25);//dudukan
	//kaki
	glColor4f((float)149/255.0f,(float)89/255.0f,(float)42/255.0f,1);
	kotak(-1,0,-0.5,0.03,0.08,0.03);//kiri belakang
	kotak(-0.9,0,-0.5,0.03,0.08,0.03);//kanan belakang
	kotak(-1,0,-0.28,0.03,0.08,0.03);//kiri depan
	kotak(-0.9,0,-0.28,0.03,0.08,0.03);//kanan depan
	//penyangga
	glColor4f((float)183/255.0f,(float)118/255.0f,(float)68/255.0f,1);
	kotak(-0.875,0.1,-0.265,0.01,0.07,0.02);//depan
	kotak(-0.875,0.1,-0.385,0.01,0.07,0.02);//tengah
	kotak(-0.875,0.1,-0.505,0.01,0.07,0.02);//belakang
	//senderan
	glColor4f((float)171/255.0f,(float)94/255.0f,(float)35/255.0f,1);
	kotak(-0.885,0.15,-0.505,0.015,0.06,0.26);
}
void kumpulankursiA(){
	float kebelakang=0;
	float kesamping=0;
	for (int i=0;i<3;i++){
		for (int j=0;j<10;j++){
	glPushMatrix();
	glTranslatef(0+kebelakang,0,-0.35+kesamping);
    kursi_panjang();
    glPopMatrix();
	kebelakang+=0.2;
		}

		kesamping+=0.4;
		kebelakang=0;
	}
}
void podiumA(){
	glColor4f((float)134/255.0f,(float)69/255.0f,(float)20/255.0f,1);
	kotak(-1.5,0,-0.45,0.3,0.05,0.3);
	glBegin(GL_POLYGON);//bagian depan
	glVertex3f(-1.2,0.05,-0.15);
	glVertex3f(-1.2,0.4,-0.15);
	glVertex3f(-1.2,0.4,-0.45);
	glVertex3f(-1.2,0.05,-0.45);
	glEnd();

	glBegin(GL_POLYGON);//samping kanan
	glVertex3f(-1.5,0.05,-0.15);
	glVertex3f(-1.5,0.3,-0.15);
	glVertex3f(-1.2,0.4,-0.15);
	glVertex3f(-1.2,0.05,-0.15);
	glEnd();

	glBegin(GL_POLYGON);//samping kiri
	glVertex3f(-1.5,0.05,-0.45);
	glVertex3f(-1.5,0.3,-0.45);
	glVertex3f(-1.2,0.4,-0.45);
	glVertex3f(-1.2,0.05,-0.45);
	glEnd();
	//salib
	glColor4f((float)92/255.0f,(float)52/255.0f,(float)21/255.0f,1);
	kotak(-1.199,0.18,-0.315,0.02,0.12,0.03);
	kotak(-1.199,0.245,-0.35,0.02,0.025,0.1);

}
void balkonatapA(){
	//glColor4f((float)23/255.0f,(float)235/255.0f,(float)246/255.0f,1);
	float geser=0,atas=0;
	baloksegitiga(-1.7,1,-1,2.7,0.05,0.1);
   kotakmiringbelakang(-1.7,1,-0.9,2.7,0.05,0.13,0.05);
   kotakmiringbelakang(-1.7,1.05,-0.77,2.7,0.05,0.13,0.05);
   kotakmiringbelakang(-1.7,1.1,-0.64,2.7,0.05,0.13,0.05);
   kotakmiringbelakang(-1.7,1.15,-0.51,2.7,0.05,0.13,0.04);
   kotakmiringbelakang(-1.7,1.19,-0.38,2.7,0.05,0.13,0.03);

    kotakmiringdepanbalkon(-1.7,1.19,-0.25,2.7,0.05,0.13,0.03);
	kotakmiringdepanbalkon(-1.7,1.15,-0.12,2.7,0.05,0.13,0.04);
   kotakmiringdepanbalkon(-1.7,1.1,0.01,2.7,0.05,0.13,0.05);
   kotakmiringdepanbalkon(-1.7,1.05,0.14,2.7,0.05,0.13,0.05);
   kotakmiringdepanbalkon(-1.7,1,0.27,2.7,0.05,0.13,0.05);
	baloksegitiga(-1.7,1,0.5,2.7,0.05,-0.1);
}
void gedungA(){
	glColor4f((float)236/255.0f,(float)235/255.0f,(float)246/255.0f,1);
	kotaksugoi(-1.7,0.001,-1,2.7,1,1.5);
	if(bukabalkon){
	balkonatapA();
	}
	glColor4f(1,1,1,1);
	kotaksugoiline(-1.7,0.001,-1,2.7,1,1.5);
	if(buka){
	jendela_deket_entrance();
	glPushMatrix();
	glTranslatef(-0.3,0,0);
	jendela_deket_entrance();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.5,0,0);
	jendela_deket_entrance();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(1.8,0,0);
	jendela_deket_entrance();
	glPopMatrix();
	}
	if(bukasisiatas){
	//atap
	glBegin(GL_POLYGON);//sisi kiri
	glVertex3f(-1.7,1.001,-1);
	glVertex3f(-1.7,1.501,-0.25);
	glVertex3f(-1.7,1.001,0.5);
	glEnd();

	glBegin(GL_POLYGON);//sisi kanan
	glVertex3f(1,1.001,-1);
	glVertex3f(1,1.501,-0.25);
	glVertex3f(1,1.001,0.5);
	glEnd();}
	if(bukaatap){
	glColor4f((float)215/255.0f,(float)101/255.0f,(float)52/255.0f,1);
	glBegin(GL_POLYGON);//genteng depan
	glVertex3f(-1.7,1.001,0.5);
	glVertex3f(1,1.001,0.5);
	glVertex3f(1,1.501,-0.25);
	glVertex3f(-1.7,1.501,-0.25);
	glEnd();

	glBegin(GL_POLYGON); //genteng belakang
	glVertex3f(-1.7,1.001,-1);
	glVertex3f(1,1.001,-1);
	glVertex3f(1,1.501,-0.25);
	glVertex3f(-1.7,1.501,-0.25);
	glEnd();}
	kumpulankursiA();
	podiumA();

}

void coba(){
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    gluLookAt(0.5,2,5,0,0,0,0,1,0);
	glRotatef(xrot,1,0,0);
	glRotatef(yrot,0,1,0);
	tanah(1,1);
	//ruangan utama
	gedungA();
	if(buka){
	entrance();
	}
}
void display() {
  glPushMatrix();
  glScalef(0.2,0.2,0.2);
  coba();
  glPopMatrix();
  glFlush();
  glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)
}

void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1, 100.0f);
}

void keyboard(unsigned char pencetan, int uh, int ah) {
   switch (pencetan) {

		case 'a':
			glTranslatef(-0.05f, 0.0, 0.0);
			break;
		case 'A':
			glTranslatef(-0.1, 0.0, 0.0);
			break;
			//geser ke kanan
		case 'd':
			glTranslatef(0.05f, 0.0, 0.0);
			break;
		case 'D':
			glTranslatef(0.1, 0.0, 0.0);
			break;
			 //gerak ke atas
		case 'w':
			glTranslatef(0.0, 0.05f, 0);
			break;
		case 'W':
			glTranslatef(0.0, 0.1, 0);
			break;
			 //gerak ke bawah
		case 's':
			glTranslatef(0.0, -0.05f, 0);
			break;
		case 'S':
			glTranslatef(0.0, -0.1, 0);
			break;
			 //gerak ke depan
		case 'z':
			glTranslatef(0.0, 0, 0.05f);
			break;
		case 'Z':
			glTranslatef(0.0, 0, 0.1);
			break;
			 //gerak ke belakang
		case 'c':
			glTranslatef(0.0, .0, -0.05f);
			break;
		case 'C':
			glTranslatef(0.0, .0, -0.1);
			break;
			 //rotate ke kiri
		case 'k':
			glRotatef(1.0, 0.0, -5.0, 0.0);
			break;
		case 'K':
			glRotatef(2.0, 0.0, -5.0, 0.0);
			break;
			//rotate ke kanan
		case ';':
			glRotatef(1.0, 0.0, 5.0, 0.0);
			break;
		case ':':
			glRotatef(2.0, 0.0, 5.0, 0.0);
			break;
			//rotate ke samping kanan
		case 'p':
			glRotatef(1.0, 0.0, 0.0, -5.0);
			break;
		case 'P':
			glRotatef(2.0, 0.0, 0.0, -5.0);
			break;
			//rotate ke samping kiri
		case 'i':
			glRotatef(1.0, 0.0, 0.0, 5.0);
			break;
		case 'I':
			glRotatef(2.0, 0.0, 0.0, 5.0);
			break;
			//rotate ke atas
		case 'o':
			glRotatef(1.0, -5.0, 0.0, 0.0);
			break;
		case 'O':
			glRotatef(2.0, -5.0, 0.0, 0.0);
			break;
			//rotate ke bawah
		case 'l':
			glRotatef(1.0, 5.0, 0.0, 0.0);
			break;
		case 'L':
			glRotatef(2.0, 5.0, 0.0, 0.0);
			break;
		case '1': // munculin dan ilangin bagian depan dan sisi kanan
			if(buka){
				buka=false;}
			else {
			buka=true;
			}
			break;
		case '2': // munculin dan ilangin atap
			if(bukaatap){
				bukaatap=false;}
			else {
			bukaatap=true;
			}
			break;
		case '3': // munculin dan ilangin balkon
			if(bukabalkon){
				bukabalkon=false;}
			else {
			bukabalkon=true;
			}
			break;
		case '4': // munculin dan ilangin sisi atas gedung A
			if(bukasisiatas){
				bukasisiatas=false;}
			else {
			bukasisiatas=true;
			}
			break;

   }
   display();
}


int main(int argc, char** argv) {
   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(1080, 810);   // Set the window's initial width & height
   glutInitWindowPosition(250, 50); // Position the window's initial top-left corner
   glutCreateWindow("GPIB Tamansari 672017207,672017089,672017079");          // Create window with the given title
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   glutKeyboardFunc(keyboard);
   glutMouseFunc(mouse);
	glutMotionFunc(mousemotion);
	//glutIdleFunc(idle);
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}
