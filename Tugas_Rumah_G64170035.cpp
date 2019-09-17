#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int i,j=0,status=0;
double m=0;
float xpos=0,ypos1=0,ypos2=60,ypos3=30,ypos4=90;


static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);

    if (key == GLFW_KEY_ENTER && action == GLFW_PRESS)
        status++;
}

    void setup_viewport(GLFWwindow* window)
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);

        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, 800, 800, 0, 1.f, -1.f);   //batas kiri, kanan, bottom, top, near, far
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }


    void display()  {
        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_POLYGON);
        glColor3ub(255/3,255/3,255/3);
        glVertex2d(0,0);
        glVertex2d(0,800);
        glVertex2d(800,800);
        glVertex2d(800,0);
        glEnd();
        glFlush();
    }

    void lingkaranforawan(float radius, float jumlah_titik, float x_tengah, float y_tengah);
    void awan(float x, float y);
    void jendela(double x);
    void pintu();
    void bingkaipintu(double x);
    void tanggadepan(double x);
    void tanggaatas(double x);
    void pagarluarkiri(double x);
    void pagarluarkanan(double x);
    void batangkiri(double x);
    void batangkiridepan(double x);
    void batangkanan(double x);
    void batangkanandepan(double x);
    void pagardalamkiri();
    void rumah();
    void dinding(double x);


int main(void)
{
    GLFWwindow* window;
    if (!glfwInit()) exit(EXIT_FAILURE);

    window = glfwCreateWindow(800, 800, "Tugas Rumah - G64170035", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window))
    {
        setup_viewport(window);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        display();


       // awan(500, -100);
       // awan(600, 0);
       // awan(700, -150);
        rumah();
        dinding(m);

        //pagardalamkanan
        for(i=0;i<6;i++) batangkanan(i);
        for(i=0;i<6;i++) batangkanandepan(i);
        pintu();
        pagardalamkiri();
        for(i=0;i<2;i++) jendela(i);
        for(i=0;i<3;i++) bingkaipintu(i);

        if ((status %2 == 0 )&& m<=255) m+=0.25;
        if ((status %2 !=0 )&& m>=0) m-=0.25;

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();

    exit(EXIT_SUCCESS);
}

void lingkaranforawan(float radius, float jumlah_titik, float x_tengah, float y_tengah){
        glBegin(GL_POLYGON);
        int i;
        for(i=0; i<=360; i++){
            //glColor3ub(242 + (0.8 * (255-i)), 242 + (1.4 * (255-i)), 242 + (0.5 * (255-i)));
            float sudut = i*(2*3.14/jumlah_titik);
            float x = x_tengah+radius*cos(sudut);
            float y = y_tengah+radius*sin(sudut);
            glVertex2f(x,y);
        }
        glEnd();
}

void awan(float x, float y){
        int i, j;
        glPushMatrix();
        glTranslatef((float)glfwGetTime() * 30,0,0);
        for(i=0, j=-10000; i<100; i++,j+=400){
            glColor3ub(209, 207, 231);
            lingkaranforawan(17, 70, 17.61 + x + j, 211.32 + y);
            lingkaranforawan(20, 70, 43.18 + x + j, 203.5 + y);
            lingkaranforawan(35, 70, 171.27 + x + j, 196.91 + y);
            lingkaranforawan(33, 70, 73.52 + x + j, 196.91 + y);
            lingkaranforawan(45, 70, 116.26 + x + j, 187.1 + y);
        }
        glPopMatrix();
}

void jendela(double x){
    //kaca
    glBegin(GL_POLYGON);
    glColor3ub(241,240,248);
    glVertex2d(256.726+(x*112.862) ,387.221+(x*64.934) );
    glVertex2d(280.465+(x*112.862) ,400.924+(x*64.934) );
    glVertex2d(280.465+(x*112.862) ,449.026+(x*64.934) );
    glVertex2d(256.726+(x*112.862) ,435.32+(x*64.934) );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(58,123,102);
    glVertex2d(253.776+(x*112.862) ,385.519+(x*64.934) );
    glVertex2d(253.776+(x*112.862) ,436.943+(x*64.934) );
    glVertex2d(256.726+(x*112.862) ,435.32+(x*64.934) );
    glVertex2d(256.726+(x*112.862) ,387.221+(x*64.934) );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(113,173,159);
    glVertex2d(253.899+(x*112.862) ,436.951+(x*64.934) );
    glVertex2d(280.465+(x*112.862) ,452.289+(x*64.934) );
    glVertex2d(280.465+(x*112.862) ,449.026+(x*64.934) );
    glVertex2d(256.726+(x*112.862) ,435.32+(x*64.934) );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(113,173,159);
    glVertex2d(256.726+(x*112.862) ,405.304+(x*64.934) );
    glVertex2d(255.251+(x*112.862) ,406.156+(x*64.934) );
    glVertex2d(280.465+(x*112.862) ,420.71+(x*64.934) );
    glVertex2d(280.389+(x*112.862) ,418.968+(x*64.934) );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(80,149,122);
    glVertex2d(255.251 +(x*112.862) ,406.156 +(x*64.934) );
    glVertex2d(280.465 +(x*112.862) ,420.711 +(x*64.934) );
    glVertex2d(280.465 +(x*112.862) ,423.362 +(x*64.934) );
    glVertex2d(255.251 +(x*112.862) ,408.88 +(x*64.934) );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(113,173,159);
    glVertex2d(250.457+(x*112.862) ,379.916+(x*64.934) );
    glVertex2d(254.883+(x*112.862) ,377.362+(x*64.934) );
    glVertex2d(288.209+(x*112.862) ,396.603+(x*64.934) );
    glVertex2d(283.784+(x*112.862) ,399.158+(x*64.934) );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(58,123,102);
    glVertex2d(283.784+(x*112.862) ,399.158+(x*64.934) );
    glVertex2d(288.209+(x*112.862) ,396.603+(x*64.934) );
    glVertex2d(288.209+(x*112.862) ,455.472+(x*64.934) );
    glVertex2d(283.784+(x*112.862) ,458.027+(x*64.934) );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(113,173,159);
    glVertex2d(250.457+(x*112.862) ,379.916+(x*64.934) );
    glVertex2d(253.776+(x*112.862) ,385.519+(x*64.934) );
    glVertex2d(280.465+(x*112.862) ,400.924+(x*64.934) );
    glVertex2d(283.784+(x*112.862) ,399.158+(x*64.934) );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(80,149,122);
    glVertex2d(280.465 +(x*112.862) ,400.924 +(x*64.934) );
    glVertex2d(283.784 +(x*112.862) ,399.158 +(x*64.934) );
    glVertex2d(283.784 +(x*112.862) ,458.027 +(x*64.934) );
    glVertex2d(280.465 +(x*112.862) ,452.289 +(x*64.934) );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(80,149,122);
    glVertex2d(280.465 +(x*112.862) ,452.289 +(x*64.934) );
    glVertex2d(283.784 +(x*112.862) ,458.027 +(x*64.934) );
    glVertex2d(250.457 +(x*112.862) ,438.864 +(x*64.934) );
    glVertex2d(253.899 +(x*112.862) ,436.951 +(x*64.934) );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(80,149,122);
    glVertex2d(253.899 +(x*112.862) ,436.951 +(x*64.934) );
    glVertex2d(250.457 +(x*112.862) ,438.864 +(x*64.934) );
    glVertex2d(250.457 +(x*112.862) ,379.771 +(x*64.934) );
    glVertex2d(253.776 +(x*112.862) ,385.519 +(x*64.934) );
    glEnd();
}

void pintu(){
    glBegin(GL_POLYGON);
    glColor3ub(58,123,102);
    glVertex2d(342.68 ,420.688 );
    glVertex2d(348.249 ,417.472 );
    glVertex2d(348.249 ,521.105 );
    glVertex2d(342.68 ,524.321 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(58,123,102);
    glVertex2d(303.789 ,403.012 );
    glVertex2d(303.789 ,501.841 );
    glVertex2d(307.612 ,499.737 );
    glVertex2d(307.612 ,405.217 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(237,223,171);
    glVertex2d(307.612 ,405.217 );
    glVertex2d(338.378 ,422.978 );
    glVertex2d(338.378 ,517.499 );
    glVertex2d(307.612 ,499.737 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(80,149,122);
    glVertex2d(299.488 ,499.486 );
    glVertex2d(303.789 ,501.841 );
    glVertex2d(303.789 ,403.012 );
    glVertex2d(299.488 ,395.562 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(80,149,122);
    glVertex2d(299.488 ,395.562 );
    glVertex2d(342.68 ,420.494 );
    glVertex2d(338.378 ,422.978 );
    glVertex2d(303.789 ,403.012 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(80,149,122);
    glVertex2d(338.378 ,422.978 );
    glVertex2d(342.68 ,420.494 );
    glVertex2d(342.68 ,524.321 );
    glVertex2d(338.378 ,517.499 );
    glEnd();
}

void bingkaipintu(double x){
    glBegin(GL_POLYGON);
    glColor3ub(58,123,102);
    glVertex2d(311.674 ,414.404+(x*27.743) );
    glVertex2d(311.674 ,435.58+(x*27.743) );
    glVertex2d(314.382 ,414.828+(x*27.743) );
    glVertex2d(314.382 ,435.233+(x*27.743) );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(80,149,122);
    glVertex2d(312.272 ,435.108+(x*27.743) );
    glVertex2d(311.674 ,435.58+(x*27.743) );
    glVertex2d(337.275 ,450.361+(x*27.743) );
    glVertex2d(337.275 ,449.543+(x*27.743) );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(80,149,122);
    glVertex2d(314.441 ,419.196+(x*27.743) );
    glVertex2d(315.039 ,418.723+(x*27.743) );
    glVertex2d(335.216 ,430.373+(x*27.743) );
    glVertex2d(334.508 ,430.782+(x*27.743) );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(58,123,102);
    glVertex2d(335.216 ,430.373+(x*27.743) );
    glVertex2d(332.508 ,430.782+(x*27.743) );
    glVertex2d(332.508 ,445.569+(x*27.743) );
    glVertex2d(335.216 ,445.221+(x*27.743) );
    glEnd();
}

void tanggadepan(double x){
    glBegin(GL_POLYGON);
    glColor3ub(159,97,72);
    glVertex2d(188.25+(x*8.71),594.82-(x*13.84));
    glVertex2d(188.233+(x*8.71),586.158-(x*13.84));
    glVertex2d(228.265+(x*8.71),609.387-(x*13.84));
    glVertex2d(228.285+(x*8.71),618.051-(x*13.84));
    glEnd();
}

void tanggaatas(double x){
    glBegin(GL_POLYGON);
    glColor3ub(176,127,94);
    glVertex2d(188.233+(x*8.71),586.158-(x*13.84));
    glVertex2d(197.202+(x*8.71),580.980-(x*13.84));
    glVertex2d(237.234+(x*8.71),604.209-(x*13.84));
    glVertex2d(228.265+(x*8.71),609.387-(x*13.84));
    glEnd();
}

void pagarluarkiri(double x){

    if(x<11) {
    glBegin(GL_POLYGON);
    glColor3ub(176,128,92);
    glVertex2d(112.074+(x*27.345),427.885-(x*15.792));
    glVertex2d(128.261+(x*27.345),418.54-(x*15.792));
    glVertex2d(124.864+(x*27.345),416.566-(x*15.792));
    glVertex2d(108.677+(x*27.345),425.911-(x*15.792));
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(111,81,70);
    glVertex2d(124.953+(x*27.345),447.22-(x*15.792));
    glVertex2d(128.35+(x*27.345),450.194-(x*15.792));
    glVertex2d(128.293+(x*27.345),429.802-(x*15.792));
    glVertex2d(124.896+(x*27.345),427.828-(x*15.792));
    glEnd();
    }

    glBegin(GL_POLYGON);
    glColor3ub(159,97,74);
    glVertex2d(100.863+(x*27.345),418.841-(x*15.792));
    glVertex2d(106.433+(x*27.345),410.048-(x*15.792));
    glVertex2d(112.03+(x*27.345),412.394-(x*15.792));
    glVertex2d(112.164+(x*27.345),459.539-(x*15.792));
    glVertex2d(100.997+(x*27.345),465.987-(x*15.792));
    glEnd();


    if (x<11) {
    glBegin(GL_POLYGON);
    glVertex2d(112.074+(x*27.345),427.885-(x*15.792));
    glVertex2d(112.106+(x*27.345),439.147-(x*15.792));
    glVertex2d(128.293+(x*27.345),429.802-(x*15.792));
    glVertex2d(128.261+(x*27.345),418.54-(x*15.792));
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(109,83,68);
    glVertex2d(124.864+(x*27.345),416.566-(x*15.792));
    glVertex2d(128.261+(x*27.345),418.54-(x*15.792));
    glVertex2d(128.217+(x*27.345),403.049-(x*15.792));
    glVertex2d(124.82+(x*27.345),401.075-(x*15.792));
    glEnd();
    }

    if(x<12){
    glBegin(GL_POLYGON);
    glColor3ub(176,128,92);
    glVertex2d(97.466+(x*27.345),416.867-(x*15.792));
    glVertex2d(100.863+(x*27.345),418.841-(x*15.792));
    glVertex2d(106.433+(x*27.345),410.048-(x*15.792));
    glVertex2d(103.036+(x*27.345),408.074-(x*15.792));
    glEnd();
    }
}

void pagarluarkanan(double x){


    glBegin(GL_POLYGON);
    glColor3ub(110,82,70);
    glVertex2d(671.739+20/2-(x*27.345),465.48-50-(x*15.792));
    glVertex2d(671.739+20/2-(x*27.345),476.742-50-(x*15.792));
    glVertex2d(687.894+20/2-(x*27.345),486.087-50-(x*15.792));
    glVertex2d(687.894+20/2-(x*27.345),474.825-50-(x*15.792));
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(156,99,70);
    glVertex2d(702.4+20/2-(x*27.345),460.953-(x*15.792));
    glVertex2d(699.003+20/2-(x*27.345),462.927-(x*15.792));
    glVertex2d(699.137+20/2-(x*27.345),415.782-(x*15.792));
    glVertex2d(702.4+20/2-(x*27.345),413.808-(x*15.792));
    glEnd();

    if (x<11) {
    glBegin(GL_POLYGON);
    glColor3ub(172,126,93);
    glVertex2d(687.926+20/2-(x*27.345),474.825-50-(x*15.792));
    glVertex2d(691.322+20/2-(x*27.345),472.851-50-(x*15.792));
    glVertex2d(675.136+20/2-(x*27.345),463.506-50-(x*15.792));
    glVertex2d(671.739+20/2-(x*27.345),465.48-50-(x*15.792));
    glEnd();
    }

    glBegin(GL_POLYGON);
    glColor3ub(176,127,94);
    glVertex2d(699.137+20/2-(x*27.345),465.782-50-(x*15.792));
    glVertex2d(702.534+20/2-(x*27.345),463.808-50-(x*15.792));
    glVertex2d(696.964+20/2-(x*27.345),455.014-50-(x*15.792));
    glVertex2d(693.567+20/2-(x*27.345),456.988-50-(x*15.792));
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(110,82,70);
    glVertex2d(699.137+20/2-(x*27.345),465.782-50-(x*15.792));
    glVertex2d(693.567+20/2-(x*27.345),456.988-50-(x*15.792));
    glVertex2d(687.969+20/2-(x*27.345),459.334-50-(x*15.792));
    glVertex2d(687.836+20/2-(x*27.345),506.479-50-(x*15.792));
    glVertex2d(699.003+20/2-(x*27.345),512.927-50-(x*15.792));
    glEnd();


}

void batangkiri(double x){


    glBegin(GL_POLYGON);
    glColor3ub(158,98,72);
    glVertex2d(222.511-(x*12.185),419.76+(x*7.03));
    glVertex2d(226.783-(x*12.185),422.243+(x*7.03));
    glVertex2d(226.881-(x*12.185),456.698+(x*7.03));
    glVertex2d(222.608-(x*12.185),454.214+(x*7.03));
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(110,82,70);
    glVertex2d(165.857+(x*12.185),457.418-(x*7.03));
    glVertex2d(165.857+(x*12.185),491.873-(x*7.03));
    glVertex2d(171.471+(x*12.185),488.689-(x*7.03));
    glVertex2d(171.373+(x*12.185),454.234-(x*7.03));
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(159,97,72);
    glVertex2d(232.277,412.723);
    glVertex2d(232.295,419.06);
    glVertex2d(165.857,457.418);
    glVertex2d(165.857,451.07);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(242,140,69);
    glVertex2d(232.277,412.723);
    glVertex2d(228.004,410.24);
    glVertex2d(161.585,448.587);
    glVertex2d(165.857,451.07);
    glEnd();

}

void batangkiridepan(double x){
    glBegin(GL_POLYGON);
    glColor3ub(159,97,74);
    glVertex2d(223.732-(x*12.189),495.765-(x*7.037));
    glVertex2d(223.732-(x*12.189),530.22-(x*7.037));
    glVertex2d(218.216-(x*12.189),527.036-(x*7.037));
    glVertex2d(218.216-(x*12.189),492.581-(x*7.037));
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(110,82,70);
    glVertex2d(167.078+(x*12.189),458.107+(x*7.037));
    glVertex2d(167.078+(x*12.189),492.562+(x*7.037));
    glVertex2d(162.806+(x*12.189),495.043+(x*7.037));
    glVertex2d(162.806+(x*12.189),460.59+(x*7.037));
    glEnd();
}

void batangkanan(double x){


    glBegin(GL_POLYGON);
    glColor3ub(159,98,72);
    glVertex2d(409.128-(x*12.185),528.158+(x*7.03));
    glVertex2d(404.855-(x*12.185),525.675+(x*7.03));
    glVertex2d(404.855-(x*12.185),560.13+(x*7.03));
    glVertex2d(409.128-(x*12.185),562.613+(x*7.03));
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(110,82,70);
    glVertex2d(348.3+(x*12.185),597.788-(x*7.03));
    glVertex2d(353.815+(x*12.185),594.604-(x*7.03));
    glVertex2d(353.815+(x*12.185),560.149-(x*7.03));
    glVertex2d(348.3+(x*12.185),563.333-(x*7.03));
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(110,82,70);
    glVertex2d(414.622,518.638);
    glVertex2d(414.622,524.976);
    glVertex2d(348.3,563.33);
    glVertex2d(348.3,556.986);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(242,140,69);
    glVertex2d(414.622,518.638);
    glVertex2d(410.349,516.155);
    glVertex2d(343.93,554.503);
    glVertex2d(348.202,556.986);
    glEnd();

}

void batangkanandepan(double x){
    glBegin(GL_POLYGON);
    glColor3ub(159,97,74);
    glVertex2d(277.687+(x*12.189),527.453+(x*7.037));
    glVertex2d(277.687+(x*12.189),561.908+(x*7.037));
    glVertex2d(283.101+(x*12.189),565.09+(x*7.037));
    glVertex2d(283.101+(x*12.189),530.635+(x*7.037));
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(110,82,70);
    glVertex2d(283.101+(x*12.189),565.09+(x*7.037));
    glVertex2d(283.101+(x*12.189),530.635+(x*7.037));
    glVertex2d(287.472+(x*12.189),528.152+(x*7.037));
    glVertex2d(287.374+(x*12.189),562.607+(x*7.037));
    glEnd();


}

void pagardalamkiri() {

    //pagardalamkiri

    for(i=0;i<6;i++) batangkiri(i);

    for(i=0;i<6;i++) batangkiridepan(i);

    glBegin(GL_POLYGON);
    glColor3ub(159,97,72);
    glVertex2d(223.732,495.765);
    glVertex2d(223.732,489.417);
    glVertex2d(157.294,451.07);
    glVertex2d(157.294,457.408);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(242,140,69);
    glVertex2d(223.732,489.417);
    glVertex2d(228.004,486.934);
    glVertex2d(161.585,448.587);
    glVertex2d(157.294,451.07);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(110,82,70);
    glVertex2d(223.732,489.417);
    glVertex2d(228.004,486.934);
    glVertex2d(227.906,527.737);
    glVertex2d(223.732,530.22);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(159,97,72);
    glVertex2d(277.687,527.453);
    glVertex2d(277.687,521.115);
    glVertex2d(344.125,559.462);
    glVertex2d(344.125,565.81);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(242,140,69);
    glVertex2d(277.705,521.115);
    glVertex2d(281.978,518.632);
    glVertex2d(348.397,556.979);
    glVertex2d(344.125,559.462);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(110,82,70);
    glVertex2d(344.125,559.462);
    glVertex2d(348.397,556.979);
    glVertex2d(344.125,600.265);
    glVertex2d(348.397,597.782);
    glEnd();
}

void rumah() {
    //tangga depan
    glBegin(GL_POLYGON);
    glColor3ub(159,97,74);
    glVertex2d(149.6,496.24);
    glVertex2d(150.02,531.92);
    glVertex2d(336.21,640.36);
    glVertex2d(336.21,604.69);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(110,82,70);
    glVertex2d(336.208,604.689);
    glVertex2d(336.208,640.364);
    glVertex2d(602.683,486.840);
    glVertex2d(602.683,451.168);
    glEnd();

    //tangga di samping
    glBegin(GL_POLYGON);
    glColor3ub(106,82,70);
    glVertex2d(228.26,609.38);
    glVertex2d(228.27,618.01);
    glVertex2d(237,613.02);
    glVertex2d(237,604.21);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(237,595.54);
    glVertex2d(237,613.02);
    glVertex2d(245.96,607.84);
    glVertex2d(245.71,590.37);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(245.85,581.71);
    glVertex2d(245.85,607.99);
    glVertex2d(254.67,602.81);
    glVertex2d(254.67,576.52);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(254.395,567.858);
    glVertex2d(254.414,602.952);
    glVertex2d(263.384,597.774);
    glVertex2d(263.364,562.680);
    glEnd();

    //tangga
    for(i=0;i<4;i++){
        tanggadepan(i);
        tanggaatas(i);
    }

    //alas
    glBegin(GL_POLYGON);
    glVertex2d(149.595,496.242);
    glVertex2d(336.208,604.689);
    glVertex2d(602.683,451.168);
    glVertex2d(416.071,342.721);
    glEnd();


    //alasdalam
    glBegin(GL_POLYGON);
    glColor3ub(249,238,205);
    glVertex2d(414.295,559.467);
    glVertex2d(227.946,451.133);
    glVertex2d(416.071,342.721);
    glVertex2d(602.583,451.168);
    glEnd();


    //pagarluarkanan
    for(i=0;i<12;i++) pagarluarkanan(i);


    //pagarluarkiri
    glBegin(GL_POLYGON);
    glColor3ub(109,83,68);
    glVertex2d(97.6,464.013);
    glVertex2d(100.997,465.987);
    glVertex2d(100.863,418.841);
    glVertex2d(97.446,416.867);
    glEnd();

    for(i=0;i<12;i++) pagarluarkiri(i);

    //tembok kiri
    glBegin(GL_POLYGON);
    glColor3ub(210,195,154);
    glVertex2d(234.395 ,346.895 );
    glVertex2d(234.394 ,455.268 );
    glVertex2d(415.515 ,350.932 );
    glVertex2d(415.515 ,242.326 );
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(210,195,154);
    glVertex2d(324.474,204.704);
    glVertex2d(258.626,334.971);
    glVertex2d(398.354,275.807);
    glEnd();


        //lukisan
    glBegin(GL_POLYGON);
    glColor3ub(176,127,94);
    glVertex2d(262.897,363.883);
    glVertex2d(264.286,364.69);
    glVertex2d(306.768,340.282);
    glVertex2d(305.379,339.474);
    glEnd();


    glBegin(GL_POLYGON); //background
    glColor3ub(143,210,218);
    glVertex2d(266.159,364.753);
    glVertex2d(266.222,387.89);
    glVertex2d(304.97,365.636);
    glVertex2d(304.908,343.499);
    glEnd();

    glBegin(GL_POLYGON); // gunung
    glColor3ub(77,150,121);
    glVertex2d(266.2,380.42);
    glVertex2d(274.594,364.69);
    glVertex2d(289.806,365.694);
    glVertex2d(295.729,357.834);
    glVertex2d(305.519,358.415);
    glVertex2d(303.58,364.829);
    glVertex2d(266.217,386.287);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(107,84,70);
    glVertex2d(262.897,363.883);
    glVertex2d(264.286,364.69);
    glVertex2d(264.361,391.107);
    glVertex2d(262.972,390.3);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(86,86,86);
    glVertex2d(264.833,387.082);
    glVertex2d(266.222,387.89);
    glVertex2d(304.97,365.636);
    glVertex2d(303.581,364.829);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(109,81,69);
    glVertex2d(304.97,365.636);
    glVertex2d(303.581,364.829);
    glVertex2d(303.581,342.69);
    glVertex2d(304.908,343.499);
    glEnd();


    glBegin(GL_POLYGON); // atas
    glColor3ub(161,96,74);
    glVertex2d(264.286,364.69);
    glVertex2d(266.159,365.753);
    glVertex2d(304.908,343.499);
    glVertex2d(306.768,340.282);
    glEnd();

    glBegin(GL_POLYGON); // kanan
    glColor3ub(155,99,72);
    glVertex2d(304.908,343.499);
    glVertex2d(306.768,340.282);
    glVertex2d(306.843,366.698);
    glVertex2d(304.97,365.636);
    glEnd();

    glBegin(GL_POLYGON); // bawah
    glColor3ub(155,99,72);
    glVertex2d(304.97,365.636);
    glVertex2d(306.843,366.698);
    glVertex2d(264.361,391.107);
    glVertex2d(266.222,387.89);
    glEnd();


    glBegin(GL_POLYGON); // kiri
    glColor3ub(155,99,72);
    glVertex2d(264.361,391.107);
    glVertex2d(266.222,387.89);
    glVertex2d(266.159,365.753);
    glVertex2d(264.286,364.69);
    glEnd();

        //kasurkiri
    glBegin(GL_POLYGON);
    glColor3ub(236,223,171);
    glVertex2d(266.386,441.646);
    glVertex2d(235.975,424.257);
    glVertex2d(294.565,389.562);
    glVertex2d(324.975,406.951);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(210,195,154);
    glVertex2d(324.975,406.951);
    glVertex2d(325.091,417.044);
    glVertex2d(265.593,452.114);
    glVertex2d(266.386,441.646);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(110,82,70);
    glVertex2d(325.438,417.663);
    glVertex2d(325.526,427.633);
    glVertex2d(265.018,463.314);
    glVertex2d(265.61,453.055);
    glEnd();

    //tembokkiriblkg
    glBegin(GL_POLYGON);
    glColor3ub(237,200,148);
    glVertex2d(334.299 ,321.081 );
    glVertex2d(335.853 ,320.262 );
    glVertex2d(384.815 ,348.776 );
    glVertex2d(383.407 ,349.679 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(211,173,108);
    glVertex2d(334.299 ,321.081 );
    glVertex2d(383.407 ,349.679 );
    glVertex2d(383.252 ,426.261 );
    glVertex2d(334.356 ,397.786 );
    glEnd();

    //temboksampingkiri
    glBegin(GL_POLYGON);
    glColor3ub(234,197,145);
    glVertex2d(396.087,386.122 );
    glVertex2d(394.59 ,385.27 );
    glVertex2d(283.307 ,449.783 );
    glVertex2d(284.715 ,450.686 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(183,144,87);
    glVertex2d(396.087 ,386.122 );
    glVertex2d(396.087 ,419.861 );
    glVertex2d(284.87 ,484.335 );
    glVertex2d(284.715 ,450.686 );
    glEnd();

    //mejaijokiri
    glBegin(GL_POLYGON);
    glColor3ub(58,123,102);
    glVertex2d(325.393 ,385.635 );
    glVertex2d(334.603 ,380.317 );
    glVertex2d(334.689 ,398.059 );
    glVertex2d(325.479 ,403.377 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(128,193,174);
    glVertex2d(324.776 ,385.276 );
    glVertex2d(342.099 ,395.342 );
    glVertex2d(351.309 ,390.025 );
    glVertex2d(333.986 ,379.959 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(128,193,174);
    glVertex2d(325.393 ,399.886 );
    glVertex2d(334.603 ,394.569 );
    glVertex2d(350.691 ,403.918 );
    glVertex2d(341.481 ,409.235 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(58,123,102);
    glVertex2d(342.099 ,395.342 );
    glVertex2d(351.309 ,390.025 );
    glVertex2d(351.396 ,407.767 );
    glVertex2d(342.186 ,413.085 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(80,149,122);
    glVertex2d(325.479 ,403.377 );
    glVertex2d(324.863 ,403.019 );
    glVertex2d(324.776 ,385.276 );
    glVertex2d(325.393 ,385.635 );
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(325.393 ,385.635 );
    glVertex2d(325.395 ,386.347 );
    glVertex2d(341.483 ,395.697 );
    glVertex2d(341.481 ,394.984 );
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(342.099 ,395.342 );
    glVertex2d(341.483 ,394.984 );
    glVertex2d(342.186 ,413.085 );
    glVertex2d(341.569 ,412.727 );
    glEnd();

    //pintukiri
    glBegin(GL_POLYGON);
    glColor3ub(80,149,122);
    glVertex2d(385.505 ,430.446 );
    glVertex2d(385.505 ,358.607 );
    glVertex2d(363.971 ,371.04 );
    glVertex2d(362.38 ,443.895 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(58,123,102);
    glVertex2d(355.315 ,443.76 );
    glVertex2d(360.612 ,446.939 );
    glVertex2d(360.612 ,368.861 );
    glVertex2d(355.315 ,365.802 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(113,173,159);
    glVertex2d(355.107 ,365.922 );
    glVertex2d(360.405 ,368.981 );
    glVertex2d(390.804 ,351.431 );
    glVertex2d(385.505 ,348.372 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(58,123,102);
    glVertex2d(387.238 ,431.326 );
    glVertex2d(385.505 ,430.446 );
    glVertex2d(385.505 ,358.607 );
    glVertex2d(387.238 ,357.607 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(80,149,122);
    glVertex2d(360.405 ,446.939 );
    glVertex2d(363.971 ,444.88 );
    glVertex2d(363.971 ,371.04 );
    glVertex2d(360.405 ,368.981 );
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(360.405 ,368.981 );
    glVertex2d(363.971 ,371.04 );
    glVertex2d(387.238 ,357.607 );
    glVertex2d(390.804 ,351.431 );
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(390.804 ,351.431 );
    glVertex2d(387.238 ,357.607 );
    glVertex2d(387.238 ,431.326 );
    glVertex2d(390.804 ,429.388 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(242,240,251);
    glVertex2d(382.107 ,364.686 );
    glVertex2d(382.107 ,403.129 );
    glVertex2d(365.527 ,412.701 );
    glVertex2d(365.527 ,374.259 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(113,173,159);
    glVertex2d(365.527 ,412.701 );
    glVertex2d(365.527 ,414.508 );
    glVertex2d(383.672 ,404.031 );
    glVertex2d(382.108 ,403.128 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(58,123,102);
    glVertex2d(382.107 ,364.686 );
    glVertex2d(383.672 ,363.783 );
    glVertex2d(383.672 ,404.031 );
    glVertex2d(382.107 ,403.129 );
    glEnd();

    //tembokdepan
    glBegin(GL_POLYGON);
    glColor3ub(237,223,171);
    glVertex2d(234.295,346.985);
    glVertex2d(227.946,342.76);
    glVertex2d(227.946,451.133);
    glVertex2d(234.295,455.268);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(237,223,171);
    glVertex2d(227.946,421.426);
    glVertex2d(227.946,451.133);
    glVertex2d(414.513,559.467);
    glVertex2d(414.513,525.817);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(249,238,205);
    glVertex2d(227.946,421.426);
    glVertex2d(236.265,420.607);
    glVertex2d(415.921,524.914);
    glVertex2d(414.513,525.817);
    glEnd();

    //tembok belakang
    glBegin(GL_POLYGON);
    glColor3ub(237,223,171);
    glVertex2d(415.515 ,242.326 );
    glVertex2d(415.515 ,350.932 );
    glVertex2d(596.23 ,455.268 );
    glVertex2d(596.636 ,346.895 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(210,195,154);
    glVertex2d(596.636 ,346.895 );
    glVertex2d(603.084 ,342.76 );
    glVertex2d(423.385 ,239.683 );
    glVertex2d(415.515 ,242.326 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(210,195,154);
    glVertex2d(596.636 ,346.895 );
    glVertex2d(603.084 ,342.76 );
    glVertex2d(602.678 ,451.133 );
    glVertex2d(596.23 ,455.268 );
    glEnd();

    //mesin cuci
    glBegin(GL_POLYGON);
    glColor3ub(244,236,212);
    glVertex2d(415.515 ,317.795 );
    glVertex2d(437.972 ,330.761 );
    glVertex2d(415.515 ,343.726 );
    glVertex2d(393.058 ,330.761 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(210,195,154);
    glVertex2d(437.972 ,330.761 );
    glVertex2d(438.046 ,363.944 );
    glVertex2d(415.588 ,376.909 );
    glVertex2d(415.515 ,343.726 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(237,223,171);
    glVertex2d(393.058 ,330.761 );
    glVertex2d(415.515 ,343.726 );
    glVertex2d(415.588 ,376.909 );
    glVertex2d(392.985 ,363.944 );
    glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(242,240,251);
                for (i=0; i <= 360; i++) {
              float rad = i*3.14159/180;
              glVertex2f(403.5+cos(rad)*(4.5+2),357+sin(rad)*(7+2));
           }
        glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(141,210,217);
                for (i=0; i <= 360; i++) {
              float rad = i*3.14159/180;
              glVertex2f(403.5+cos(rad)*4.5,357+sin(rad)*7);
           }
        glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(231,63,75);
                for (i=0; i <= 360; i++) {
              float rad = i*3.14159/180;
              glVertex2f(403.37+cos(rad)*1.25,341.8+sin(rad)*2.12);
           }
        glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(58,123,102);
                for (i=0; i <= 360; i++) {
              float rad = i*3.14159/180;
              glVertex2f(400.555+cos(rad)*1.25,339.8+sin(rad)*2.12);
           }
        glEnd();

    glBegin(GL_POLYGON);
        glColor3ub(111,109,109);
                for (i=0; i <= 360; i++) {
              float rad = i*3.14159/180;
              glVertex2f(396+cos(rad)*2,338+sin(rad)*3);
           }
        glEnd();


    //pintu belakang
    glBegin(GL_POLYGON);
    glColor3ub(80,149,122);
    glVertex2d(460.089 ,312.995 );
    glVertex2d(484.49 ,327.083 );
    glVertex2d(484.49 ,397.698 );
    glVertex2d(460.089 ,383.61 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(58,123,102);
    glVertex2d(491.426 ,321.04 );
    glVertex2d(486.225 ,324.042 );
    glVertex2d(486.225 ,400.686 );
    glVertex2d(491.426 ,397.566 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(80,149,122);
    glVertex2d(486.429 ,400.686 );
    glVertex2d(482.928 ,398.548 );
    glVertex2d(482.928 ,326.181 );
    glVertex2d(486.429 ,324.16 );
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(486.429 ,324.16 );
    glVertex2d(482.928 ,326.181 );
    glVertex2d(460.089 ,312.995 );
    glVertex2d(456.588 ,306.932 );
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(456.588 ,306.932 );
    glVertex2d(460.089 ,312.995 );
    glVertex2d(460.089 ,385.479 );
    glVertex2d(456.588 ,383.458 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(58,123,102);
    glVertex2d(460.089 ,312.995 );
    glVertex2d(461.789 ,313.976 );
    glVertex2d(461.789 ,384.497 );
    glVertex2d(460.089 ,385.479 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(242,240,251);
    glVertex2d(481.401 ,329.341 );
    glVertex2d(465.124 ,319.057 );
    glVertex2d(465.124 ,357.68 );
    glVertex2d(481.401 ,367.078 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(113,173,159);
    glVertex2d(463.589 ,358.567 );
    glVertex2d(465.124 ,357.68 );
    glVertex2d(481.401 ,367.078 );
    glVertex2d(481.401 ,368.851 );
    glEnd();

    //tembok belakang sebelah pintu belakang
    glBegin(GL_POLYGON);
    glColor3ub(234,197,143);
    glVertex2d(491.428 ,360.993 );
    glVertex2d(492.925 ,361.846 );
    glVertex2d(443.473 ,390.57 );
    glVertex2d(442.065 ,389.667 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(180,143,88);
    glVertex2d(492.925 ,361.846 );
    glVertex2d(492.925 ,395.584+2 );
    glVertex2d(443.473 ,424.219+2 );
    glVertex2d(443.473 ,390.57  );
    glEnd();

    //pintu kamar kanan
    glBegin(GL_POLYGON);
    glColor3ub(113,173,159);
    glVertex2d(440.364 ,355.175 );
    glVertex2d(445.565 ,358.178 );
    glVertex2d(415.725 ,375.406 );
    glVertex2d(410.524 ,372.404 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(58,123,102);
    glVertex2d(410.728 ,372.286 );
    glVertex2d(415.928 ,375.288 );
    glVertex2d(415.928 ,451.933 );
    glVertex2d(410.728 ,448.812 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(80,149,122);
    glVertex2d(415.725 ,451.933 );
    glVertex2d(419.225 ,449.912 );
    glVertex2d(419.225 ,377.427 );
    glVertex2d(415.725 ,375.406 );
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(415.725 ,375.406 );
    glVertex2d(419.225 ,377.427 );
    glVertex2d(442.065 ,364.241 );
    glVertex2d(445.565 ,358.178 );
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(445.565 ,358.178 );
    glVertex2d(442.065 ,364.241 );
    glVertex2d(442.065 ,436.725 );
    glVertex2d(445.565 ,434.704 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(80,149,122);
    glVertex2d(442.065 ,364.241 );
    glVertex2d(417.663 ,378.329 );
    glVertex2d(417.663 ,448.944 );
    glVertex2d(442.065 ,434.856 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(242,240,251);
    glVertex2d(438.565 ,370.303 );
    glVertex2d(420.753 ,380.587 );
    glVertex2d(420.753 ,420.097 );
    glVertex2d(438.565 ,409.813 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(58,123,102);
    glVertex2d(438.565 ,370.303 );
    glVertex2d(437.029 ,371.19 );
    glVertex2d(437.029 ,408.927 );
    glVertex2d(438.565 ,409.813 );
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(442.065 ,364.241 );
    glVertex2d(440.364 ,365.222 );
    glVertex2d(440.364 ,435.743 );
    glVertex2d(442.065 ,436.725 );
    glEnd();

    //kasur kanan
    glBegin(GL_POLYGON);
    glColor3ub(58,123,102);
    glVertex2d(515.224 ,372.307 );
    glVertex2d(516.706 ,371.457 );
    glVertex2d(566.734 ,400.341 );
    glVertex2d(568.212 ,402.9 );
    glVertex2d(568.15 ,439.598 );
    glVertex2d(566.662 ,440.445 );
    glVertex2d(516.634 ,411.561 );
    glVertex2d(515.161 ,409.005 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(80,149,122);
    glVertex2d(515.658 ,371.356 );
    glVertex2d(517.547 ,370.304 );
    glVertex2d(569.653 ,400.367 );
    glVertex2d(567.775 ,401.439 );
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(567.775 ,401.439 );
    glVertex2d(569.674 ,400.404 );
    glVertex2d(569.604 ,439.493 );
    glVertex2d(567.945 ,440.321 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(174,129,94);
    glVertex2d(513.951 ,400.331 );
    glVertex2d(516.901 ,400.329 );
    glVertex2d(566.929 ,429.212 );
    glVertex2d(566.939 ,430.924 );
    glVertex2d(508.35 ,465.619 );
    glVertex2d(505.394 ,465.619 );
    glVertex2d(455.366 ,436.736 );
    glVertex2d(455.361 ,435.027 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(80,149,122);
    glVertex2d(567.543 ,430.074 );
    glVertex2d(569.981  ,438.977  );
    glVertex2d(506.982 ,476.158 );
    glVertex2d(506.904 ,465.97 );
    glEnd();

    glBegin(GL_POLYGON); //kasurputih
    glColor3ub(234,197,143);
    glVertex2d(455.366 ,425.607 );
    glVertex2d(455.361 ,423.897 );
    glVertex2d(513.951 ,389.202 );
    glVertex2d(516.901 ,389.2 );
    glVertex2d(566.929 ,418.083 );
    glVertex2d(566.939 ,419.795 );
    glVertex2d(508.35 ,454.49 );
    glVertex2d(505.394 ,454.49 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(210,195,154);
    glVertex2d(567.543 ,418.945 );
    glVertex2d(567.525 ,429.152 );
    glVertex2d(566.922 ,429.983 );
    glVertex2d(506.83 ,465.029 );
    glVertex2d(506.904 ,454.841 );
    glEnd();

    glBegin(GL_POLYGON);//bantal1
    glColor3ub(80,149,122);
    glVertex2d(520.76 ,387.351 );
    glVertex2d(532.842 ,394.327 );
    glVertex2d(532.83 ,403.329 );
    glVertex2d(520.734 ,396.346 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(58,123,102);
    glVertex2d(520.76 ,387.351 );
    glVertex2d(522.58 ,386.26 );
    glVertex2d(535.25 ,393.729 );
    glVertex2d(532.889 ,394.408 );
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d(532.889 ,394.408 );
    glVertex2d(535.25 ,393.729 );
    glVertex2d(535.154 ,402.425 );
    glVertex2d(532.992 ,403.238 );
    glEnd();

    glBegin(GL_POLYGON);//bantal2
    glColor3ub(80,149,122);
    glVertex2d(520.76+20.408 ,387.351+11.722 );
    glVertex2d(532.842+20.408 ,394.327+11.722 );
    glVertex2d(532.83+20.408 ,403.329+11.722 );
    glVertex2d(520.734+20.408 ,396.346+11.722 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(58,123,102);
    glVertex2d(520.76+20.408 ,387.351+11.722 );
    glVertex2d(522.58+20.408 ,386.26+11.722 );
    glVertex2d(535.25+20.408 ,393.729+11.722 );
    glVertex2d(532.889+20.408 ,394.408+11.722 );
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d(532.889+20.408 ,394.408+11.722 );
    glVertex2d(535.25+20.408 ,393.729+11.722 );
    glVertex2d(535.154+20.408 ,402.425+11.722 );
    glVertex2d(532.992+20.408 ,403.238+11.722 );
    glEnd();

    //lukisan kanan atas
    glBegin(GL_POLYGON);
    glColor3ub(141,210,217);
    glVertex2d(526.898 ,340.412 );
    glVertex2d(567.513 ,363.744 );
    glVertex2d(567.444 ,388.02 );
    glVertex2d(526.829 ,364.689 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(80,149,122);
    glVertex2d(528.491 ,363.014 );
    glVertex2d(528.554 ,356.6 );
    glVertex2d(536.344 ,356.02 );
    glVertex2d(542.266 ,363.88 );
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d(565.856 ,384.473 );
    glVertex2d(565.873 ,378.431 );
    glVertex2d(557.478 ,362.876 );
    glVertex2d(542.266 ,363.88 );
    glVertex2d(528.491 ,363.014 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(80,149,122);
    glVertex2d(528.554 ,340.877 );
    glVertex2d(527.165 ,341.685 );
    glVertex2d(527.165 ,363.822 );
    glVertex2d(528.554 ,363.014 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(86,86,86);
    glVertex2d(528.554 ,363.014 );
    glVertex2d(527.165 ,363.822  );
    glVertex2d(565.851 ,386.075 );
    glVertex2d(567.24 ,385.268 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(174,129,94);
    glVertex2d(525.305 ,338.467 );
    glVertex2d(526.694 ,337.66 );
    glVertex2d(569.175 ,362.069 );
    glVertex2d(567.786 ,362.876 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(80,149,122);
    glVertex2d(567.786 ,362.876 );
    glVertex2d(569.175 ,362.069 );
    glVertex2d(569.101 ,388.485 );
    glVertex2d(567.711 ,389.293 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(58,123,102);
    glVertex2d(525.305 ,338.467 );
    glVertex2d(527.165 ,341.685 );
    glVertex2d(565.914 ,363.938 );
    glVertex2d(567.786 ,362.876 );
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(565.914 ,363.938 );
    glVertex2d(567.786 ,362.876 );
    glVertex2d(567.711 ,389.293 );
    glVertex2d(565.851 ,386.075 );
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(567.711 ,389.293 );
    glVertex2d(565.851 ,386.075 );
    glVertex2d(527.102 ,363.822 );
    glVertex2d(525.23 ,364.884 );
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2d(527.102 ,363.822 );
    glVertex2d(525.23 ,364.884 );
    glVertex2d(525.305 ,338.467 );
    glVertex2d(527.165 ,341.685 );
    glEnd();

    //tembok depan kasur kanan
    glBegin(GL_POLYGON);
    glColor3ub(249,238,205);
    glVertex2d(410.863 ,392.552 );
    glVertex2d(409.31 ,393.371 );
    glVertex2d(506.81 ,450.301 );
    glVertex2d(508.218 ,449.398 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(237,223,171);
    glVertex2d(409.31 ,393.371 );
    glVertex2d(409.366 ,449.757 );
    glVertex2d(506.654 ,506.564 );
    glVertex2d(506.81 ,450.301 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(249,238,205);
    glVertex2d(506.81 ,450.301 );
    glVertex2d(508.218 ,449.398 );
    glVertex2d(508.129 ,505.7 );
    glVertex2d(506.654 ,506.564 );
    glEnd();

    //kursi tamu
    glBegin(GL_POLYGON);
    glColor3ub(80,149,122);
    glVertex2d(420.249  ,480.75 );
    glVertex2d(420.696 ,481.377 );
    glVertex2d(446.411 ,495.97 );
    glVertex2d(446.166 ,498.585 );
    glVertex2d(420.696 ,484.012 );
    glVertex2d(420.249 ,483.384 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(58,123,102);
    glVertex2d(439.154 ,456.224 );
    glVertex2d(433.76 ,459.429 );
    glVertex2d(423.713  ,469.92 );
    glVertex2d(419.343 ,484.396 );
    glVertex2d(439.207 ,474.816 );
    glVertex2d(440.922 ,471.846 );
    glVertex2d(440.88 ,457.207 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(80,149,122);
    glVertex2d(439.154 ,456.224 );
    glVertex2d(435.356 ,454.016 );
    glVertex2d(429.962 ,457.221 );
    glVertex2d(420.476 ,466.794 );
    glVertex2d(415.545 ,482.188 );
    glVertex2d(419.343 ,484.396 );
    glVertex2d(424.274 ,469.001 );
    glVertex2d(433.76 ,459.429 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(237,223,171); // putih
    glVertex2d(436.118  ,455.738+2 );
    glVertex2d(439.842 ,453.51+2 );
    glVertex2d(468.976 ,468.976+2);
    glVertex2d(461.806 ,470.99+2 );
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d(461.806 ,470.99+2 );
    glVertex2d(468.976 ,468.976+2 );
    glVertex2d(465.721 ,486.474+2 );
    glVertex2d(461.755 ,488.845+2 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(210,195,154);
    glVertex2d(435.255 ,456.461+2 );
    glVertex2d(436.338 ,455.839+2 );
    glVertex2d(461.038 ,470.175+2 );
    glVertex2d(462.118 ,472.046+2 );
    glVertex2d(462.073 ,488.152+2 );
    glVertex2d(460.985 ,488.771+2 );
    glVertex2d(436.286 ,474.436+2 );
    glVertex2d(435.209 ,472.567+2 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(237,223,171);
    glVertex2d(434.63 ,467.643 );
    glVertex2d(436.787 ,467.641 );
    glVertex2d(461.487 ,481.976 );
    glVertex2d(461.494 ,483.228 );
    glVertex2d(447.568 ,491.32 );
    glVertex2d(445.408 ,491.32 );
    glVertex2d(420.708 ,476.985 );
    glVertex2d(420.705 ,475.735 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(210,195,154);
    glVertex2d(420.262 , 475.255 );
    glVertex2d(420.249 ,480.75 );
    glVertex2d(446.259 ,495.962 );
    glVertex2d(446.259 ,495.962 );
    glEnd();



    glBegin(GL_POLYGON); // bagian kanan
    glColor3ub(58,123,102);
    glVertex2d(439.154+29.082 ,456.224+16.833 );
    glVertex2d(433.76+29.082 ,459.429+16.833 );
    glVertex2d(423.713+29.082  ,469.92+16.833 );
    glVertex2d(419.343+29.082 ,484.396+16.833 );
    glVertex2d(439.207+29.082 ,474.816+16.833 );
    glVertex2d(440.922+29.082 ,471.846+16.833 );
    glVertex2d(440.88+29.082 ,457.207+16.833 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(80,149,122);
    glVertex2d(439.154+29.082 ,456.224+16.833 );
    glVertex2d(435.356+29.082 ,454.016+16.833 );
    glVertex2d(429.962+29.082 ,457.221+16.833 );
    glVertex2d(420.476+29.082 ,466.794+16.833 );
    glVertex2d(415.545+29.082 ,482.188+16.833 );
    glVertex2d(419.343+29.082 ,484.396+16.833 );
    glVertex2d(424.274+29.082 ,469.001+16.833 );
    glVertex2d(433.76+29.082 ,459.429+16.833 );
    glEnd();

    //meja tamu

    glBegin(GL_POLYGON);
    glColor3ub(80,149,122);
    glVertex2d(410.63  ,501.731 );
    glVertex2d(412.363 ,502.731 );
    glVertex2d(412.34  ,510.882);
    glVertex2d(410.606 ,509.881 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(58,123,102);
    glVertex2d(414.086  ,501.73 );
    glVertex2d(412.363  ,502.731 );
    glVertex2d(412.34   ,510.882);
    glVertex2d(414.063  ,509.881 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(80,149,122);
    glVertex2d(410.63+11.782  ,501.731-6.89 );
    glVertex2d(412.363+11.782 ,502.731-6.89 );
    glVertex2d(412.34+11.782  ,510.882-6.89);
    glVertex2d(410.606+11.782 ,509.881-6.89 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(58,123,102);
    glVertex2d(414.086+11.782 ,501.73-6.89 );
    glVertex2d(412.363+11.78  ,502.731-6.89 );
    glVertex2d(412.34+11.782  ,510.882-6.89);
    glVertex2d(414.063+11.782 ,509.881-6.89 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(113,173,159);
    glVertex2d(396.864 ,494.708 );
    glVertex2d(396.846 ,491.544 );
    glVertex2d(411.219 ,493.565 );
    glVertex2d(413.068 ,485.292 );
    glVertex2d(425.573 ,492.421 );
    glVertex2d(425.591 ,495.585 );
    glVertex2d(414.832 ,501.837 );
    glVertex2d(409.37 ,501.837 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(58,123,102);
    glVertex2d(396.864 ,494.708 );
    glVertex2d(396.86 ,496.357 );
    glVertex2d(409.365 ,503.486 );
    glVertex2d(414.828 , 503.486 );
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2d(412.396 ,502.485 );
    glVertex2d(412.329 ,504.138 );
    glVertex2d(426.62 ,496.136 );
    glVertex2d(426.713  ,494.014 );
    glVertex2d(426.103  ,495.215 );
    glEnd();

    //rooftopkiri
    glBegin(GL_POLYGON);
    glColor3ub(159,97,72);
    glVertex2d(248.916,368.455);
    glVertex2d(248.916,348.577);
    glVertex2d(212.479,327.456);
    glVertex2d(212.479,347.333);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(129,87,71);
    glVertex2d(248.916,348.577);
    glVertex2d(212.479,327.456);
    glVertex2d(311.007,163.892);
    glVertex2d(347.352,185.014);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(110,82,70);
    glVertex2d(248.916,368.455);
    glVertex2d(248.916,348.577);
    glVertex2d(325.563,221.185);
    glVertex2d(324.625,243.796);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(159,97,74);
    glVertex2d(325.563,221.185);
    glVertex2d(324.625,243.796);
    glVertex2d(501.836,343.442);
    glVertex2d(501.836,323.623);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(129,87,71);
    glVertex2d(325.563,221.185);
    glVertex2d(347.352,185.014);
    glVertex2d(523.625,287.452);
    glVertex2d(501.836,323.623);
    glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(109,81,69);
    glVertex2d(501.836,343.442);
    glVertex2d(501.836,323.623);
    glVertex2d(523.625,287.452);
    glVertex2d(524.24,306.932);
    glEnd();

    //rooftopbelakang

    glBegin(GL_POLYGON);
    glColor3ub(110,82,70);
    glVertex2d(523.625,287.452);
    glVertex2d(524.24,306.932);
    glVertex2d(622.847,356.775);
    glVertex2d(622.756,336.898);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(128,87,74);
    glVertex2d(311.007,163.892);
    glVertex2d(523.625,287.452);
    glVertex2d(622.756,336.898);
    glVertex2d(410.138,213.338);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(80,149,122);
    glVertex2d(293.157 ,392.096 );
    glVertex2d(298.892 ,388.784 );
    glVertex2d(326.819 ,392.439 );
    glVertex2d(321.084 ,395.749 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(113,173,159);
    glVertex2d(321.084 ,395.749 );
    glVertex2d(326.819 ,392.439 );
    glVertex2d(354.745 ,421.032 );
    glVertex2d(349.011 ,424.343 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(58,123,102);
    glVertex2d(293.157 ,392.096 );
    glVertex2d(321.084 ,395.749 );
    glVertex2d(349.011 ,424.343 );
    glEnd();
    j++;
}

void dinding(double x){
    //dinding depan
    glBegin(GL_POLYGON);
    glColor4ub(237,223,171,x);
    glVertex2d(227.946 ,342.76 );
    glVertex2d(228.352 ,451.133 );
    glVertex2d(414.737  ,559.431 );
    glVertex2d(415.928  ,440.422  );
    glEnd();

    //dinding samping
    glBegin(GL_POLYGON);
    glColor4ub(210,195,154,x);
    glVertex2d(524.938 ,305.501 );
    glVertex2d(600.153 ,345.577 );
    glVertex2d(447.944 ,424.407 );
    glEnd();

    glBegin(GL_POLYGON);
    glColor4ub(210,195,154,x);
    glVertex2d(414.737 ,559.431 );
    glVertex2d(415.928 ,440.422 );
    glVertex2d(601  ,344.5 );
    glVertex2d(602.678 ,451.133 );
    glEnd();

    //atap di depan
    glBegin(GL_POLYGON);
    glColor4ub(58,123,102,x);
    glVertex2d(212.479 ,327.456 );
    glVertex2d(212.479 ,347.333 );
    glVertex2d(421.376 ,465.436 );
    glVertex2d(420.323 ,444.606 );
    glEnd();

    //atap di atas
    glBegin(GL_POLYGON);
    glColor4ub(80,149,122,x);
    glVertex2d(212.479 ,327.456 );
    glVertex2d(311.007 ,163.892 );
    glVertex2d(523.625 ,287.452 );
    glVertex2d(420.333 ,444.61 );
    glEnd();

    //atap di samping
    glBegin(GL_POLYGON);
    glColor4ub(58,123,102,x);
    glVertex2d(420.323 ,444.606 );
    glVertex2d(421.376 ,465.436 );
    glVertex2d(528.376 ,300.192 );
    glVertex2d(523.716 ,287.498 );
    glEnd();
}
