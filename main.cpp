#include <windows.h> // For Windows-specific
#include <GL/glut.h> // GLUT, includes glu.h and gl.h
#include<math.h>>

# define PI           3.14159265358979323846
///.....................................................SAMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
// Rocket position variable
float rocketY = 0.0f;       // Initially at original position
int moveUp = 0;             // Flag for moving up
int moveDown = 0;           // Flag for moving down
float targetY = 0.0f;       // Target Y position
//fuletank position variables
float tankY = 0.0f;       // Initially at original position
int tmoveUp = 0;             // Flag for moving up
int tmoveDown = 0;           // Flag for moving down
float tanktargetY = 0.0f;       // Target Y position

//background position variables
float bgY = 0.0f;       // Initially at original position
int bgmoveUp = 0;             // Flag for moving up
int bgmoveDown = 0;           // Flag for moving down
float bgtargetY = 0.0f;       // Target Y position
//platform and scenary variables
float pY = 0.0f;       // Initially at original position
int pmoveUp = 0;             // Flag for moving up
int pgmoveDown = 0;           // Flag for moving down
float ptargetY = 0.0f;       // Target Y position

void init()
{
    // Set up 2D orthographic viewing region
    glMatrixMode(GL_PROJECTION);      // Switch to the projection matrix
    glLoadIdentity();                 // Reset projection matrix
    gluOrtho2D(-400.0,400.0, -300.0, 300.0); // Set the 2D clipping area
}
// rocket timer
void timer(int value)
{
    if (moveUp)
    {
        if (rocketY < targetY)
            rocketY += 2.0f;
        else
            moveUp = 0;
        bgmoveUp =1;
    }
    else if (moveDown)
    {
        if (rocketY > targetY)
            rocketY -= 2.0f;
        else
            moveDown = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); // slow
}

// fuel tank timer ..................................................
void timer2(int value)
{
    if (tmoveUp && tankY < tanktargetY)
    {
        tankY += 2.0f;
    }
    else if (tmoveDown && tankY > tanktargetY)
    {
        tankY -= 4.0f;
    }
    else
    {
        tmoveUp = 0;
        tmoveDown = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(16, timer2, 0);
}
// bg timer ......................................................
void timerbg(int value)
{
    if (bgmoveUp)
    {
        bgtargetY = -900;
        if (bgY > bgtargetY)
            bgY -= 2.0f;
        else
            bgmoveDown = 0;
    }
    else
    {
        bgmoveUp = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(16, timerbg, 0);
}

// -------------------- Special Key Function -------------------- for rocket
void specialKeys(int key, int x, int y)
{
    // UP key -> Rocket + Tank go up (if tank still attached)
    if (key == GLUT_KEY_UP && !moveUp && rocketY == 0.0f)
    {
        targetY = 100.0f;
        moveUp = 1;
        moveDown = 0;

        // Move the tank up only if not detached
        if (!tmoveDown)
        {
            tanktargetY = 100.0f;
            tmoveUp = 1;
            tmoveDown = 0;
        }
    }
    // DOWN key -> Rocket comes back down (tank stays detached if already dropped)
    else if (key == GLUT_KEY_DOWN && !moveDown && rocketY > 0.0f)
    {
        targetY = 0.0f;    // Bring rocket to original position
        moveDown = 1;
        moveUp = 0;

        // Move tank down only if still attached
        if (!tmoveDown)
        {
            tanktargetY = 0.0f;
            tmoveDown = 1;
            tmoveUp = 0;
        }
    }
}


//.................................................................for tank detach
void handleKeypress(unsigned char key, int x, int y)
{
    if ((key == 'D' || key == 'd') && !tmoveDown && tankY > -250.0f )
    {
        tanktargetY = -250.0f;   // Detach tank, make it fall
        tmoveDown = 1;
        tmoveUp = 0;
    }
}
///................................................................................................SAMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
///for clouddddddddddddddddddd
GLfloat position = 0.0f;
GLfloat speed = 0.8f;

void update(int value)
{
    if(position <-300.0f)
        position = 300.0f;
    position -= speed;

    glutPostRedisplay();
    glutTimerFunc(100, update, 0);
}

///for carrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
GLfloat position2 = 0.0f;
GLfloat speed2 = 5.0f;

void update2(int value2)
{
    if(position2 <-400.0f)
        position2 = 400.0f;
    position2 -= speed2;

    glutPostRedisplay();
    glutTimerFunc(100, update2, 0);
}
///car done

///for planeeeeeeeeeeeee

GLfloat positionX = -400.0f;
GLfloat positionY = -300.0f;
GLfloat speed3 = 3;

void update3(int value3)
{
    positionX += speed3;
    positionY += speed3;

    if (positionX > 400 || positionY > 300)
    {
        positionX = -400.0f;
        positionY = -300.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(100, update3, 0);
}
///plane done

///for display change
GLfloat position1 = 0.0f;
GLfloat speed1 = 0.1f;

void update1(int value1)
{

    if(position1 <-1.0)
        position1 = 1.0f;

    position1 -= speed1;

    glutPostRedisplay();


    glutTimerFunc(100, update1, 0);
}


///2nd display//////////////////////////////////////////////////////////////////////////////////////////////////////////////


///1st display////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void display_Earth()
{
    glClearColor(0.196f, 0.607f, 0.659f, 1.0f);   // Set background color
    glClear(GL_COLOR_BUFFER_BIT);  // Clear background

    //glLoadIdentity();

    ///BGSky...............sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
    glPushMatrix();
    glTranslatef(0.0f, bgY, 0.0f);

    // Cyan
    float startR = 0.196f;
    float startG = 0.607f;
    float startB = 0.659f;

    // Black
    float endR = 0.0f;
    float endG = 0.0f;
    float endB = 0.0f;


    const int numQuads = 100;

    float stepR = (endR - startR) / numQuads;
    float stepG = (endG - startG) / numQuads;
    float stepB = (endB - startB) / numQuads;


    const int quadHeight = 20;

    // 60 quads
    for (int i = 0; i < numQuads; ++i)
    {

        int currentY = -300 + (i * quadHeight);


        float r = startR + (i * stepR);
        float g = startG + (i * stepG);
        float b = startB + (i * stepB);

        glColor3f(r, g, b);

        glBegin(GL_QUADS);


        glVertex2i(-400, currentY);             // Bottom-left
        glVertex2i(-400, currentY + quadHeight);  // Top-left
        glVertex2i(400, currentY + quadHeight);   // Top-right
        glVertex2i(400, currentY);             // Bottom-right

        glEnd();
    }
    /// STARS .......................................................
    glPointSize(2.0f);
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_POINTS);
    static bool starsInitialized = false;
    static int starX[100];
    static int starY[100];

    if (!starsInitialized)
    {
        for (int i = 0; i < 100; i++)
        {
            starX[i] = -400 + (rand() % 801);   // X: -400 to 400
            starY[i] = 600 + (rand() % 1201);   // Y: 600 to 1800
        }
        starsInitialized = true;
    }

    glPointSize(2.0f);
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_POINTS);
    for (int i = 0; i < 100; i++)
    {
        glVertex2i(starX[i], starY[i]);
    }
    glEnd();
    /// END STARS ...................................................



    glPopMatrix();
    ///BGSKY END.....................................................................................

    ///rocket..................................................................................rrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr
    glPushMatrix();
    glTranslatef(0.0f, rocketY, 0.0f);

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
    glVertex2i(5, -168);
    glVertex2i(-10, -168);
    glVertex2i(-2.6, -149);
    glEnd();
    glColor3f(1.0f, 01.0f, 01.0f);
    glBegin(GL_QUADS);
    glVertex2i(5, -168);
    glVertex2i(-10, -168);
    glVertex2i(-10, -215);
    glVertex2i(5, -215);
    glEnd();
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2i(2.5, -180);
    glVertex2i(-7.9, -180);
    glVertex2i(-7.9, -174);
    glVertex2i(2.5, -174);
    glEnd();
    glColor3f(01.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2i(-18, -215);
    glVertex2i(-10, -215);
    glVertex2i(-10, -197);
    glVertex2i(-22, -209);
    glVertex2i(-22, -222);
    glVertex2i(-18, -222);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2i(12, -215);
    glVertex2i(12, -222);
    glVertex2i(16, -222);
    glVertex2i(16, -209);
    glVertex2i(5, -197);
    glVertex2i(5, -215);
    glEnd();

    //bottom gray part
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2i(-9, -220);
    glVertex2i(4, -220);
    glVertex2i(1, -215);
    glVertex2i(-6, -215);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(-6, -220);
    glVertex2i(1, -220);
    glVertex2i(1, -222);
    glVertex2i(-6, -222);
    glEnd();
    // fire
    glColor3f(0.7f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2i(1, -222);
    glVertex2i(-6, -222);
    glVertex2i(-9, -228);
    glVertex2i(-2.5, -236);
    glVertex2i(4, -228);
    glEnd();
    glColor3f(1.0f, 0.84f, 0.0f); //light ylo
    glBegin(GL_QUADS);
    glVertex2i(-2.5, -222);
    glVertex2i(-6, -228);
    glVertex2i(-2.5, -231);
    glVertex2i(1, -228);
    glEnd();



    //bottom red line
    glColor3f(01.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2i(-1, -197);
    glVertex2i(-4, -197);
    glVertex2i(-4, -222);
    glVertex2i(-1, -222);
    glEnd();
    //rocket end
    glPopMatrix();

    //.................................................................................................
    //fule tank ................................................tttttttttttttttttttttttttttttttttttttttttttttttttttttttttt
    glPushMatrix();
    ///fuletank............................................................................ttttttttttttttttttttttttttttttttttttttt

    glTranslatef(0.0f, tankY, 0.0f);
    glColor3f(0.7f, 0.7f, 0.7f);
    glBegin(GL_POLYGON);
    glVertex2i(-10, -226);
    glVertex2i(-6, -221);
    glVertex2i(1, -221);
    glVertex2i(5, -226);
    glVertex2i(5, -262);
    glVertex2i(-10, -262);
    glEnd();
    //fire
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2i(5, -262);
    glVertex2i(-10, -262);
    glVertex2i(-10, -280);
    glVertex2i(-2.5, -290);
    glVertex2i(5, -280);
    glEnd();

    glColor3f(1.0f, 0.84f, 0.0f);  // Deep Yellow
    glBegin(GL_POLYGON);
    glVertex2i(1, -262);
    glVertex2i(-6, -262);
    glVertex2i(-6, -275);
    glVertex2i(-2.5, -286);
    glVertex2i(1, -275);
    glEnd();
    //dark line
    glColor3f(0.5f, 0.5f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2i(5, -238);
    glVertex2i(-10, -238);
    glVertex2i(-10, -236);
    glVertex2i(5, -236);
    glEnd();


    glPopMatrix();
    // tank end ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;



    ///platform................................................................ppppppppppppppppppppppppppppppppppppppppppppppppppp
    glPushMatrix();
    glTranslatef(0.0f, bgY, 0.0f);


    ///PLaneeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee

    // glColor3ub(22,52,93);
    //glBegin(GL_QUADS);
    //glVertex2i(-390,200 );
    //glVertex2i(-330, 200);
    //glVertex2i(-330, 230);
    //glVertex2i(-390, 230);
    //glEnd();

    //glColor3ub(22,52,93);
    //glBegin(GL_TRIANGLES);
    //  glVertex2i(-330, 230);
    //        glVertex2i(-300, 210);
    //glVertex2i(-330, 200);
    //glEnd();

    //glColor3ub(22,52,93);
    //glBegin(GL_POLYGON);
    //glVertex2i(-390,200 );
    //glVertex2i(-330, 240);
    //glVertex2i(-300, 220);
    //glVertex2i(-370, 180);
    //glEnd();

    //glColor3ub(22,52,93);
    //glBegin(GL_POLYGON);
    //glVertex2i(-390,200 );
    //glVertex2i(-330, 240);
    //glVertex2i(-300, 220);
    //glVertex2i(-370, 180);
    //glEnd();

    //glBegin(GL_POLYGON);
    //glColor3f(1.0f, 1.0f, 1.0f);
    //glVertex2f(-100.0f, -10.0f);
    //glVertex2f( 120.0f, -10.0f);
    //glVertex2f( 140.0f,  0.0f);
    //glVertex2f( 120.0f,  10.0f);
    //glVertex2f(-100.0f,  10.0f);
    //glEnd();
    //  glBegin(GL_TRIANGLES);
    //glColor3f(0.0f, 0.0f, 0.5f);
    //glVertex2f(0.0f, 10.0f);
    //glVertex2f(-40.0f, 60.0f);
    //glVertex2f(40.0f, 10.0f);
    //glEnd();

    //glBegin(GL_TRIANGLES);
    //glColor3f(0.0f, 0.0f, 0.5f);
    //glVertex2f(-100.0f, 10.0f);
    //glVertex2f(-130.0f, 40.0f);
    //glVertex2f(-90.0f, 10.0f);
    //glEnd();

    glPushMatrix();
    glTranslatef(positionX, positionY, 0.0f);
    glRotatef(15.0f, 0.0f, 0.0f, 1.0f);
    glBegin(GL_POLYGON);
    glColor3ub(160,208,236);
    glVertex2i(-100, -10);
    glVertex2i( 20, -10);
    glVertex2i( 20,  10);
    glVertex2i(-100,  10);
    glEnd();
    glBegin(GL_TRIANGLES);  //face
    glColor3ub(47,144,212);
    glVertex2i( 20, -10);
    glVertex2i( 50,  0);
    glVertex2i( 20,  10);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0,58,101);
    glVertex2i(-10, 10);
    glVertex2i(-60, 60);
    glVertex2i(-30, 10);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(0,58,101);
    glVertex2i(-100, 10);
    glVertex2i(-130, 40);
    glVertex2i(-90, 10);
    glEnd();

    glBegin(GL_POLYGON); //windows
    glColor3ub(160,208,236);
    glVertex2i(-100, 0);
    glVertex2i( 120, 0);
    glVertex2i( 120, 0);
    glVertex2i(-100, 0);
    glEnd();


    GLfloat X13 = -102;
    GLfloat Y13 = 0;
    GLfloat radius13 = 5;
    int triangleAmount13 = 100;
    GLfloat twicePi13 = 2.0f * PI;

    glColor3ub(255,90,0); //sky bluw
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(X13, Y13);
    for (int i = 0; i <= triangleAmount13; i++)
    {
        glVertex2f(
            X13 + (radius13 * cos(i * twicePi13 / triangleAmount13)),
            Y13 + (radius13 * sin(i * twicePi13 / triangleAmount13))
        );
    }
    glEnd();
    glPopMatrix();


    glPopMatrix();

    glPopMatrix();



///planeeeeeeeeeee done



    ///roadddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex2i(-400, -300);
    glVertex2i(-400, -272);
    glVertex2i(400, -272);
    glVertex2i(400, -300);
    glEnd();

    glColor3ub(232,227,211);
    glBegin(GL_QUADS);
    glVertex2i(-380, -283);
    glVertex2i(-380, -287);
    glVertex2i(-360, -287);
    glVertex2i(-360, -283);
    glEnd();

    glColor3ub(232,227,211);
    glBegin(GL_QUADS);
    glVertex2i(-340, -283);
    glVertex2i(-340, -287);
    glVertex2i(-320, -287);
    glVertex2i(-320, -283);
    glEnd();

    glColor3ub(232,227,211);
    glBegin(GL_QUADS);
    glVertex2i(-300, -283);
    glVertex2i(-300, -287);
    glVertex2i(-280, -287);
    glVertex2i(-280, -283);
    glEnd();

    glColor3ub(232,227,211);
    glBegin(GL_QUADS);
    glVertex2i(-260, -283);
    glVertex2i(-260, -287);
    glVertex2i(-240, -287);
    glVertex2i(-240, -283);
    glEnd();

    glColor3ub(232,227,211);
    glBegin(GL_QUADS);
    glVertex2i(-220, -283);
    glVertex2i(-220, -287);
    glVertex2i(-200, -287);
    glVertex2i(-200, -283);
    glEnd();

    glColor3ub(232,227,211);
    glBegin(GL_QUADS);
    glVertex2i(-180, -283);
    glVertex2i(-180, -287);
    glVertex2i(-160, -287);
    glVertex2i(-160, -283);
    glEnd();

    glColor3ub(232,227,211);
    glBegin(GL_QUADS);
    glVertex2i(-140, -283);
    glVertex2i(-140, -287);
    glVertex2i(-120, -287);
    glVertex2i(-120, -283);
    glEnd();

    glColor3ub(232,227,211);
    glBegin(GL_QUADS);
    glVertex2i(-100, -283);
    glVertex2i(-100, -287);
    glVertex2i(-80, -287);
    glVertex2i(-80, -283);
    glEnd();
    glColor3ub(232,227,211);
    glBegin(GL_QUADS);
    glVertex2i(-60, -283);
    glVertex2i(-60, -287);
    glVertex2i(-40, -287);
    glVertex2i(-40, -283);
    glEnd();
    glColor3ub(232,227,211);
    glBegin(GL_QUADS);
    glVertex2i(-20, -283);
    glVertex2i(-20, -287);
    glVertex2i(-0, -287);
    glVertex2i(-0, -283);
    glEnd();

    glColor3ub(232,227,211);
    glBegin(GL_QUADS);
    glVertex2i(20, -283);
    glVertex2i(20, -287);
    glVertex2i(40, -287);
    glVertex2i(40, -283);
    glEnd();

    glColor3ub(232,227,211);
    glBegin(GL_QUADS);
    glVertex2i(60, -283);
    glVertex2i(60, -287);
    glVertex2i(80, -287);
    glVertex2i(80, -283);
    glEnd();
    glColor3ub(232,227,211);
    glBegin(GL_QUADS);
    glVertex2i(100, -283);
    glVertex2i(100, -287);
    glVertex2i(120, -287);
    glVertex2i(120, -283);
    glEnd();
    glColor3ub(232,227,211);
    glBegin(GL_QUADS);
    glVertex2i(140, -283);
    glVertex2i(140, -287);
    glVertex2i(160, -287);
    glVertex2i(160, -283);
    glEnd();
    glColor3ub(232,227,211);
    glBegin(GL_QUADS);
    glVertex2i(180, -283);
    glVertex2i(180, -287);
    glVertex2i(200, -287);
    glVertex2i(200, -283);
    glEnd();

    glColor3ub(232,227,211);
    glBegin(GL_QUADS);
    glVertex2i(220, -283);
    glVertex2i(220, -287);
    glVertex2i(240, -287);
    glVertex2i(240, -283);
    glEnd();
    glColor3ub(232,227,211);
    glBegin(GL_QUADS);
    glVertex2i(260, -283);
    glVertex2i(260, -287);
    glVertex2i(280, -287);
    glVertex2i(280, -283);
    glEnd();
    glColor3ub(232,227,211);
    glBegin(GL_QUADS);
    glVertex2i(300, -283);
    glVertex2i(300, -287);
    glVertex2i(320, -287);
    glVertex2i(320, -283);
    glEnd();

    glColor3ub(232,227,211);
    glBegin(GL_QUADS);
    glVertex2i(340, -283);
    glVertex2i(340, -287);
    glVertex2i(360, -287);
    glVertex2i(360, -283);
    glEnd();

    glColor3ub(232,227,211);
    glBegin(GL_QUADS);
    glVertex2i(380, -283);
    glVertex2i(380, -287);
    glVertex2i(400, -287);
    glVertex2i(400, -283);
    glEnd();

///walking road
    glColor3f(0.5f, 0.5f, 0.5f); //grey
    glBegin(GL_QUADS);
    glVertex2i(-400, -272);
    glVertex2i(-400, -267);
    glVertex2i(400, -267);
    glVertex2i(400, -272);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2i(-25, -264);
    glVertex2i(45, -264);
    glVertex2i(45, -272);
    glVertex2i(-25, -272);
    glEnd();
    //pillar
    glBegin(GL_QUADS);
    glVertex2i(41, -202);
    glVertex2i(21, -202);
    glVertex2i(21, -272);
    glVertex2i(41, -272);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(39, -198);
    glVertex2i(23, -198);
    glVertex2i(23, -272);
    glVertex2i(23, -272);
    glEnd();
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex2i(36, -176);
    glVertex2i(27, -176);
    glVertex2i(27, -272);
    glVertex2i(36, -272);
    glEnd();
    ///attach bar from platform to rocket
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex2i(2, -242);
    glVertex2i(2, -251);
    glVertex2i(42, -251);
    glVertex2i(42, -242);
    glEnd();
    glBegin(GL_QUADS);
    glVertex2i(2, -188);
    glVertex2i(2, -192);
    glVertex2i(35, -192);
    glVertex2i(35, -188);
    glEnd();


    ///diptooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo
    //left scenary by dipta

    // Electrical Line 3
    glBegin(GL_QUADS);
    glColor3ub(75, 88, 92);
    glVertex2i(-332, -262);
    glVertex2i(-332, -267);
    glVertex2i(-344, -267);
    glVertex2i(-344, -262);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(75, 88, 92);
    glVertex2i(-335, -135);
    glVertex2i(-340, -135);
    glVertex2i(-340, -262);
    glVertex2i(-335, -262);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(75, 88, 92);
    glVertex2i(-316, -142);
    glVertex2i(-360, -142);
    glVertex2i(-360, -145);
    glVertex2i(-316, -145);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(75, 88, 92);
    glVertex2i(-352, -136);
    glVertex2i(-357, -136);
    glVertex2i(-357, -142);
    glVertex2i(-352, -142);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(75, 88, 92);
    glVertex2i(-325, -136);
    glVertex2i(-320, -136);
    glVertex2i(-320, -142);
    glVertex2i(-325, -142);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2i(-348, -166);
    glVertex2i(-348, -186);
    glVertex2i(-340, -186);
    glVertex2i(-340, -166);
    glEnd();


    // Electrical Line 4
    glBegin(GL_QUADS);
    glColor3ub(75, 88, 92);
    glVertex2i(-147, -262);
    glVertex2i(-147, -267);
    glVertex2i(-159, -267);
    glVertex2i(-159, -262);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(75, 88, 92);
    glVertex2i(-150, -135);
    glVertex2i(-155, -135);
    glVertex2i(-155, -262);
    glVertex2i(-150, -262);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(75, 88, 92);
    glVertex2i(-131, -142);
    glVertex2i(-175, -142);
    glVertex2i(-175, -145);
    glVertex2i(-131, -145);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(75, 88, 92);
    glVertex2i(-167, -136);
    glVertex2i(-172, -136);
    glVertex2i(-172, -142);
    glVertex2i(-167, -142);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(75, 88, 92);
    glVertex2i(-140, -136);
    glVertex2i(-135, -136);
    glVertex2i(-135, -142);
    glVertex2i(-140, -142);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2i(-163, -166);
    glVertex2i(-163, -186);
    glVertex2i(-155, -186);
    glVertex2i(-155, -166);
    glEnd();


    // Tree 1 (translated x -10)
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.17, 0.0);
    glVertex2i(-279, -267);
    glVertex2i(-279, -257);
    glVertex2i(-268, -257);
    glVertex2i(-268, -267);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.003, 0.34, 0.02);
    glVertex2i(-300, -257);
    glVertex2i(-247, -257);
    glVertex2i(-273.5, -238);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.01, 0.38, 0.03);
    glVertex2i(-298, -252);
    glVertex2i(-249, -252);
    glVertex2i(-273.5, -234);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.03, 0.42, 0.04);
    glVertex2i(-296, -247);
    glVertex2i(-251, -247);
    glVertex2i(-273.5, -230);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.05, 0.46, 0.05);
    glVertex2i(-294, -242);
    glVertex2i(-253, -242);
    glVertex2i(-273.5, -226);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.08, 0.50, 0.06);
    glVertex2i(-292, -238);
    glVertex2i(-255, -238);
    glVertex2i(-273.5, -222);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.10, 0.54, 0.07);
    glVertex2i(-290, -234);
    glVertex2i(-257, -234);
    glVertex2i(-273.5, -218);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.58, 0.08);
    glVertex2i(-288, -230);
    glVertex2i(-259, -230);
    glVertex2i(-273.5, -214);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.14, 0.62, 0.09);
    glVertex2i(-286, -226);
    glVertex2i(-261, -226);
    glVertex2i(-273.5, -210);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.16, 0.66, 0.10);
    glVertex2i(-284, -222);
    glVertex2i(-263, -222);
    glVertex2i(-273.5, -206);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.68, 0.11);
    glVertex2i(-282, -218);
    glVertex2i(-265, -218);
    glVertex2i(-273.5, -202);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.19, 0.69, 0.12);
    glVertex2i(-280, -214);
    glVertex2i(-267, -214);
    glVertex2i(-273.5, -198);
    glEnd();



    // Tree 2 (translated x +56)
    glBegin(GL_QUADS);
    glColor3f(0.4, 0.17, 0.0);
    glVertex2i(-213, -267);
    glVertex2i(-213, -257);
    glVertex2i(-202, -257);
    glVertex2i(-202, -267);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.003, 0.34, 0.02);
    glVertex2i(-234, -257);
    glVertex2i(-181, -257);
    glVertex2i(-207.5, -238);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.01, 0.38, 0.03);
    glVertex2i(-232, -252);
    glVertex2i(-183, -252);
    glVertex2i(-207.5, -234);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.03, 0.42, 0.04);
    glVertex2i(-230, -247);
    glVertex2i(-185, -247);
    glVertex2i(-207.5, -230);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.05, 0.46, 0.05);
    glVertex2i(-228, -242);
    glVertex2i(-187, -242);
    glVertex2i(-207.5, -226);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.08, 0.50, 0.06);
    glVertex2i(-226, -238);
    glVertex2i(-189, -238);
    glVertex2i(-207.5, -222);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.10, 0.54, 0.07);
    glVertex2i(-224, -234);
    glVertex2i(-191, -234);
    glVertex2i(-207.5, -218);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.12, 0.58, 0.08);
    glVertex2i(-222, -230);
    glVertex2i(-193, -230);
    glVertex2i(-207.5, -214);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.14, 0.62, 0.09);
    glVertex2i(-220, -226);
    glVertex2i(-195, -226);
    glVertex2i(-207.5, -210);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.16, 0.66, 0.10);
    glVertex2i(-218, -222);
    glVertex2i(-197, -222);
    glVertex2i(-207.5, -206);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.18, 0.68, 0.11);
    glVertex2i(-216, -218);
    glVertex2i(-199, -218);
    glVertex2i(-207.5, -202);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.19, 0.69, 0.12);
    glVertex2i(-214, -214);
    glVertex2i(-201, -214);
    glVertex2i(-207.5, -198);
    glEnd();
///diptooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo

    ///Right scenaryy    fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff


    ///2nd building........................................................................................................................

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);

    glVertex2i(60, -267); //W1
    glVertex2i(180, -267); //z1
    glVertex2i(180, -272); //A2
    glVertex2i(60, -272); //B2
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(45, 53, 66);
    glVertex2i(60, -100); //W1
    glVertex2i(180, -100); //z1
    glVertex2i(180, -267); //A2
    glVertex2i(60, -267); //B2
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(158, 145, 137);
    glVertex2i(60, -100); //W1
    glVertex2i(100, -100); //z1 ///////////140-60/3==26.5
    glVertex2i(100, -267); //A2
    glVertex2i(60, -267); //B2
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(158, 145, 137);
    glVertex2i(140, -100); //W1
    glVertex2i(180, -100); //z1
    glVertex2i(180, -267); //A2
    glVertex2i(140, -267); //B2
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(232,227,211);
    glVertex2i(111, -225); //W1
    glVertex2i(130, -225); //z1
    glVertex2i(130, -267); //A2
    glVertex2i(111, -267); //B2
    glEnd();

    glBegin(GL_QUADS); /// roof top
    glColor3ub(232,227,211);
    glVertex2i(60, -75); //W1
    glVertex2i(105, -75); //z1
    glVertex2i(105, -100); //A2
    glVertex2i(60, -100); //B2
    glEnd();

    ///windows
    //glLoadIdentity();
    //glTranslatef(+0,0,0);
    glBegin(GL_QUADS);
    glColor3ub(232,227,211);
    glVertex2i(68, -230); //W1
    glVertex2i(92, -230); //z1
    glVertex2i(92, -220); //A2
    glVertex2i(68, -220); //B2
    glEnd();

    //glLoadIdentity();
    //glTranslatef(+50,0,0);
    glBegin(GL_QUADS);
    glColor3ub(232,227,211);
    glVertex2i(68, -250); //W1
    glVertex2i(92, -250); //z1
    glVertex2i(92, -240); //A2
    glVertex2i(68, -240); //B2
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(232,227,211);
    glVertex2i(68, -210); //W1
    glVertex2i(92, -210); //z1
    glVertex2i(92, -200); //A2
    glVertex2i(68, -200); //B2
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(232,227,211);
    glVertex2i(68, -190); //W1
    glVertex2i(92, -190); //z1
    glVertex2i(92, -180); //A2
    glVertex2i(68, -180); //B2
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(232,227,211);
    glVertex2i(68, -170); //W1
    glVertex2i(92, -170); //z1
    glVertex2i(92, -160); //A2
    glVertex2i(68, -160); //B2
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(232,227,211);
    glVertex2i(68, -150); //W1
    glVertex2i(92, -150); //z1
    glVertex2i(92, -140); //A2
    glVertex2i(68, -140); //B2
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(232,227,211);
    glVertex2i(68, -130); //W1
    glVertex2i(92, -130); //z1
    glVertex2i(92, -120); //A2
    glVertex2i(68, -120); //B2
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(232,227,211);
    glVertex2i(68, -230); //W1
    glVertex2i(92, -230); //z1
    glVertex2i(92, -220); //A2
    glVertex2i(68, -220); //B2
    glEnd();

///winodow right
    //glLoadIdentity();
    //glTranslatef(+50,0,0);

    glBegin(GL_QUADS);
    glColor3ub(232,227,211);
    glVertex2i(148, -230); //W1
    glVertex2i(172, -230); //z1
    glVertex2i(172, -220); //A2
    glVertex2i(148, -220); //B2
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(232,227,211);
    glVertex2i(148, -250); //W1
    glVertex2i(172, -250); //z1
    glVertex2i(172, -240); //A2
    glVertex2i(148, -240); //B2
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(232,227,211);
    glVertex2i(148, -210); //W1
    glVertex2i(172, -210); //z1
    glVertex2i(172, -200); //A2
    glVertex2i(148, -200); //B2
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(232,227,211);
    glVertex2i(148, -190); //W1
    glVertex2i(172, -190); //z1
    glVertex2i(172, -180); //A2
    glVertex2i(148, -180); //B2
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(232,227,211);
    glVertex2i(148, -170); //W1
    glVertex2i(172, -170); //z1
    glVertex2i(172, -160); //A2
    glVertex2i(148, -160); //B2
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(232,227,211);
    glVertex2i(148, -150); //W1
    glVertex2i(172, -150); //z1
    glVertex2i(172, -140); //A2
    glVertex2i(148, -140); //B2
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(232,227,211);
    glVertex2i(148, -130); //W1
    glVertex2i(172, -130); //z1
    glVertex2i(172, -120); //A2
    glVertex2i(148, -120); //B2
    glEnd();



    ///Electric  line 111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
    glBegin(GL_QUADS);
    glColor3ub(75, 88, 92);
    glVertex2i(147, -272); //C
    glVertex2i(147, -267);//D
    glVertex2i(160, -267);//E
    glVertex2i(160, -272); //F
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(75, 88, 92);
    glVertex2i(151, -135); //G
    glVertex2i(156, -135);//H
    glVertex2i(156, -267);//I
    glVertex2i(151, -267);//J
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(75, 88, 92);
    glVertex2i(131, -142); //K
    glVertex2i(175, -142); //L
    glVertex2i(175, -145); //M
    glVertex2i(131, -145); //N
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(75, 88, 92);
    glVertex2i(168, -136); //O
    glVertex2i(172, -136); //P
    glVertex2i(172, -142); //Q
    glVertex2i(168, -142); //R
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(75, 88, 92);
    glVertex2i(140, -136); //S
    glVertex2i(135, -136); //T
    glVertex2i(135, -142); //U
    glVertex2i(140, -142); //V
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(75, 38, 21);
    glVertex2i(147, -166); //W
    glVertex2i(147, -186); //Z
    glVertex2i(152, -186); //A1
    glVertex2i(152, -166); //B1
    glEnd();

    //Electric  line 2
    glBegin(GL_QUADS);
    glColor3ub(75, 88, 92);
    glVertex2i(332, -272); //C1
    glVertex2i(332, -267);//D1
    glVertex2i(344, -267);//E1
    glVertex2i(344, -272); //F 1
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(75, 88, 92);
    glVertex2i(335, -135); //G1
    glVertex2i(340, -135);//H1
    glVertex2i(340, -267);//I1
    glVertex2i(335, -267);//J1
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(75, 88, 92);
    glVertex2i(316, -142); //K1
    glVertex2i(360, -142); //L1
    glVertex2i(360, -145); //M1
    glVertex2i(316, -145); //N1
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(75, 88, 92);
    glVertex2i(352, -136); //O1
    glVertex2i(357, -136); //P1
    glVertex2i(357, -142); //Q1
    glVertex2i(352, -142); //R1
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(75, 88, 92);
    glVertex2i(325, -136); //S1
    glVertex2i(320, -136); //T1
    glVertex2i(320, -142); //W1
    glVertex2i(325, -142); //Z1
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(75, 38, 21);
    glVertex2i(330, -166); //
    glVertex2i(330, -186); //
    glVertex2i(335, -186); //
    glVertex2i(335, -166); //
    glEnd();

    //House
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);

    glVertex2i(215, -220); //W1
    glVertex2i(288, -220); //z1
    glVertex2i(288, -225); //A2
    glVertex2i(215, -225); //B2
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 0.5f); //grey
    glVertex2i(218.5, -272); //C2
    glVertex2i(285.5, -272); //D2
    glVertex2i(285.5, -225); //E2
    glVertex2i(218.5, -225); //F2
    glEnd();

    //in lab 8th sept

    glBegin(GL_QUADS);
    glColor3ub(0,0,0); //grey
    glVertex2i(218.5, -267); //
    glVertex2i(285.5, -267); //
    glVertex2i(285.5, -260); //
    glVertex2i(218.5, -260); //
    glEnd();

//door
    glBegin(GL_QUADS);
    glColor3ub(196,194,205); //grey
    glVertex2i(244, -267); //
    glVertex2i(262, -267); //
    glVertex2i(262, -240); //
    glVertex2i(244, -240); //
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(56, 29, 16); //grey
    glVertex2i(252, -267); //
    glVertex2i(254, -267); //
    glVertex2i(254, -240); //
    glVertex2i(252, -240); //
    glEnd();

//window right
    glBegin(GL_QUADS);
    glColor3ub(250, 220, 155); //grey
    glVertex2i(268, -248); //
    glVertex2i(278, -248); //
    glVertex2i(278, -240); //
    glVertex2i(268, -240); //
    glEnd();

    //window left
    glBegin(GL_QUADS);
    glColor3ub(250, 220, 155); //grey
    glVertex2i(238, -248); //
    glVertex2i(228, -248); //
    glVertex2i(228, -240); //
    glVertex2i(238, -240); //
    glEnd();


//flag stand
    glBegin(GL_QUADS);
    glColor3ub(56, 29, 16); //grey
    glVertex2i(270, -215); //W1
    glVertex2i(280, -215); //z1
    glVertex2i(280, -220); //A2
    glVertex2i(270, -220); //B2
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(56, 29, 16); //grey
    glVertex2i(274, -215); //W1
    glVertex2i(276, -215); //z1
    glVertex2i(276, -190); //A2
    glVertex2i(274, -190); //B2
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 106, 78); //grey
    glVertex2i(276, -200); //W1
    glVertex2i(290, -200); //z1
    glVertex2i(290, -190); //A2
    glVertex2i(276, -190); //B2
    glEnd();

    GLfloat X1 = 283;
    GLfloat Y2 = -195;
    GLfloat radius2 = 3;
    int triangleAmount2 = 100;
    GLfloat twicePi2 = 2.0f * PI;
    glColor3ub(244, 42, 65); //red
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(X1, Y2);
    for (int i = 0; i <= triangleAmount2; i++)
    {
        glVertex2f(
            X1 + (radius2 * cos(i * twicePi2 / triangleAmount2)),
            Y2 + (radius2 * sin(i * twicePi2 / triangleAmount2))
        );
    }
    glEnd();

//Treeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee

    glBegin(GL_QUADS);
    glColor3ub(56, 29, 16); //grey
    glVertex2i(180, -272); //G3
    glVertex2i(186, -272); //H3
    glVertex2i(186, -263); //I3
    glVertex2i(180, -263); //J3
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(42,126,25);
    glVertex2i(165,-263);

    glVertex2i(200,-263);
    glVertex2i(182,-240);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(42,126,25);
    glVertex2i(168,-250);

    glVertex2i(197,-250);
    glVertex2i(182,-220);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(42,126,25);
    glVertex2i(172,-235);

    glVertex2i(194,-235);
    glVertex2i(182,-205);
    glEnd();


    //sunnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn

    GLfloat X = 320;
    GLfloat Y = 220;
    GLfloat radius = 25;
    int triangleAmount = 100;
    GLfloat twicePi = 2.0f * PI;

    glColor3ub(255, 255, 0); //yellow
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(X, Y);
    for (int i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            X + (radius * cos(i * twicePi / triangleAmount)),
            Y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //cloudddddddddddddddddddddddddddddddddddddddddddddddddd
    glPushMatrix();
    glTranslatef(position,0.0f, 0.0f);

    GLfloat X3 = 200;
    GLfloat Y3 = 100;
    GLfloat radius3 = 20;
    int triangleAmount3 = 100;
    GLfloat twicePi3 = 2.0f * PI;

    glColor3ub(135, 206, 235); //sky bluw
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(X3, Y3);
    for (int i = 0; i <= triangleAmount3; i++)
    {
        glVertex2f(
            X3 + (radius3 * cos(i * twicePi3 / triangleAmount3)),
            Y3 + (radius3 * sin(i * twicePi3 / triangleAmount3))
        );
    }
    glEnd();

    GLfloat X4 = 220;
    GLfloat Y4 = 90;
    GLfloat radius4 = 20;
    int triangleAmount4 = 100;
    GLfloat twicePi4 = 2.0f * PI;

    glColor3ub(135, 206, 235); //sky bluw
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(X4, Y4);
    for (int i = 0; i <= triangleAmount4; i++)
    {
        glVertex2f(
            X4 + (radius4 * cos(i * twicePi4 / triangleAmount4)),
            Y4 + (radius4 * sin(i * twicePi4 / triangleAmount4))
        );
    }
    glEnd();

    GLfloat X5 = 190;
    GLfloat Y5 = 85;
    GLfloat radius5 = 20;
    int triangleAmount5 = 100;
    GLfloat twicePi5 = 2.0f * PI;

    glColor3ub(135, 206, 235); //sky bluw
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(X5, Y5);
    for (int i = 0; i <= triangleAmount5; i++)
    {
        glVertex2f(
            X5 + (radius5 * cos(i * twicePi5 / triangleAmount5)),
            Y5 + (radius5 * sin(i * twicePi5 / triangleAmount5))
        );
    }
    glEnd();

    //cloud 2222222222

    GLfloat X6 = 100;
    GLfloat Y6 = 130;
    GLfloat radius6 = 20;
    int triangleAmount6 = 100;
    GLfloat twicePi6 = 2.0f * PI;

    glColor3ub(135, 206, 235); //sky bluw
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(X6, Y6);
    for (int i = 0; i <= triangleAmount6; i++)
    {
        glVertex2f(
            X6 + (radius6 * cos(i * twicePi6 / triangleAmount6)),
            Y6 + (radius6 * sin(i * twicePi6 / triangleAmount6))
        );
    }
    glEnd();

    GLfloat X7 = 120;
    GLfloat Y7 = 120;
    GLfloat radius7 = 20;
    int triangleAmount7 = 100;
    GLfloat twicePi7 = 2.0f * PI;

    glColor3ub(135, 206, 235); //sky bluw
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(X7, Y7);
    for (int i = 0; i <= triangleAmount7; i++)
    {
        glVertex2f(
            X7 + (radius7 * cos(i * twicePi7 / triangleAmount7)),
            Y7 + (radius7 * sin(i * twicePi7 / triangleAmount7))
        );
    }
    glEnd();

    GLfloat X8 = 90;
    GLfloat Y8 = 115;
    GLfloat radius8 = 20;
    int triangleAmount8 = 100;
    GLfloat twicePi8 = 2.0f * PI;

    glColor3ub(135, 206, 235); //sky bluw
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(X8, Y8);
    for (int i = 0; i <= triangleAmount8; i++)
    {
        glVertex2f(
            X8 + (radius8 * cos(i * twicePi8 / triangleAmount8)),
            Y8 + (radius8 * sin(i * twicePi8 / triangleAmount8))
        );
    }
    glEnd();

    glPopMatrix();
    //cloud end

    ///carrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr

    glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);

    glColor3ub(22,52,93);
    glBegin(GL_QUADS);
    glVertex2i(338, -285);
    glVertex2i(338, -270);
    glVertex2i(360, -270);
    glVertex2i(360, -285);
    glEnd();

    glColor3ub(246,254,255);
    glBegin(GL_TRIANGLES);
    glVertex2i(340, -270);
    glVertex2i(354, -260);
    glVertex2i(360, -270);
    glEnd();

    glColor3ub(30,79,111);
    glBegin(GL_QUADS);
    glVertex2i(352, -285);
    glVertex2i(352, -255);
    glVertex2i(390, -255);
    glVertex2i(390, -285);
    glEnd();

    ///wheelof carrrrr

    GLfloat X9 = 352;
    GLfloat Y9 = -284;
    GLfloat radius9 = 7;
    int triangleAmount9 = 100;
    GLfloat twicePi9 = 2.0f * PI;

    glColor3ub(0,0,0); //sky bluw
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(X9, Y9);
    for (int i = 0; i <= triangleAmount9; i++)
    {
        glVertex2f(
            X9 + (radius9 * cos(i * twicePi9 / triangleAmount9)),
            Y9 + (radius9 * sin(i * twicePi9 / triangleAmount9))
        );
    }
    glEnd();

    GLfloat X10 = 352;
    GLfloat Y10= -284;
    GLfloat radius10= 5;
    int triangleAmount10 = 100;
    GLfloat twicePi10 = 2.0f * PI;

    glColor3ub(223, 221, 217); //sky bluw
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(X10, Y10);
    for (int i = 0; i <= triangleAmount10; i++)
    {
        glVertex2f(
            X10 + (radius10 * cos(i * twicePi10 / triangleAmount10)),
            Y10 + (radius10 * sin(i * twicePi10 / triangleAmount10))
        );
    }
    glEnd();



    GLfloat X11 = 382;
    GLfloat Y11 = -284;
    GLfloat radius11 = 7;
    int triangleAmount11 = 100;
    GLfloat twicePi11 = 2.0f * PI;

    glColor3ub(0,0,0); //sky bluw
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(X11, Y11);
    for (int i = 0; i <= triangleAmount11; i++)
    {
        glVertex2f(
            X11 + (radius11 * cos(i * twicePi11 / triangleAmount11)),
            Y11 + (radius11 * sin(i * twicePi11 / triangleAmount11))
        );
    }
    glEnd();

    GLfloat X12 = 382;
    GLfloat Y12 = -284;
    GLfloat radius12 = 5;
    int triangleAmount12 = 100;
    GLfloat twicePi12 = 2.0f * PI;

    glColor3ub(223, 221, 217); //sky bluw
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(X12, Y12);
    for (int i = 0; i <= triangleAmount12; i++)
    {
        glVertex2f(
            X12 + (radius12 * cos(i * twicePi12 / triangleAmount12)),
            Y12 + (radius12 * sin(i * twicePi12 / triangleAmount12))
        );
    }
    glEnd();
    glPopMatrix();


    glPopMatrix();

    glFlush(); // Render now
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1240, 780);          // Set the window's initial width & height
    glutInitWindowPosition(80, 50);        // Set the window's initial position
    glutCreateWindow("ROKETY"); // Create a window with the given title
    init();

    //    glutDisplayFunc(display_ufo);                                 // Call your initialization function
    glutDisplayFunc(display_Earth);              // Register display callback handler
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(handleKeypress);

    glutTimerFunc(0, timer, 0);
    glutTimerFunc(0, timer2, 0);
    glutTimerFunc(0, timerbg, 0);
    glutTimerFunc(100, update, 0);
    glutTimerFunc(100, update1, 0);
    glutTimerFunc(100, update2, 0);
    glutTimerFunc(100, update3, 0);

    glutMainLoop();                        // Enter the event-processing loop
    return 0;
}
