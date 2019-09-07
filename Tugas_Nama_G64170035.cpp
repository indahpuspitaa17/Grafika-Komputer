#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <windows.h>

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GL_TRUE);
}

    void setup_viewport(GLFWwindow* window)
    {
        // setting viewports size, projection etc
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);

        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, 800, 800, 0, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }

    void display()
    {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f); //warna background
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
    }

//Background
    void bg()
    {
        glBegin(GL_POLYGON);
            glColor3ub(251,251,251);
            glVertex2f(0,0);
            glVertex2f(0,800);
            glVertex2f(800,800);
            glVertex2f(800,0);
        glEnd();
    }

//Huruf I
    void I()
    {
         glBegin(GL_POLYGON);
          glColor3ub(0,91,91);
          glVertex2f(116.21,183.72);
          glVertex2f(116.21,200.97);
          glVertex2f(163.07,200.97);
          glVertex2f(163.07,183.72);
          glEnd();

          glBegin(GL_POLYGON);
          glColor3ub(0,91,91);
          glVertex2f(131.75,200.97);
          glVertex2f(147.29,200.97);
          glVertex2f(147.29,304.79);
          glVertex2f(131.75,304.79);
          glEnd();

          glBegin(GL_POLYGON);
          glColor3ub(0,91,91);
          glVertex2f(116.21,304.21);
          glVertex2f(116.21,322.06);
          glVertex2f(163.07,322.06);
          glVertex2f(163.07,304.79);
          glEnd();
    }

//Huruf N
    void N()
    {
        glBegin(GL_QUADS);
        glColor3ub(0,91,91);
        glVertex2f(198.48,184.3);
        glVertex2f(214.03,184.3);
        glVertex2f(214.03,322.64);
        glVertex2f(198.48,322.64);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,91,91);
        glVertex2f(214.03,236.35);
        glVertex2f(276.4,288.12);
        glVertex2f(276.4,270.87);
        glVertex2f(214.03,218.82);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,91,91);
        glVertex2f(276.4,184.3);
        glVertex2f(291.95,184.3);
        glVertex2f(291.95,322.64);
        glVertex2f(276.4,322.64);
        glEnd();

    }

//Huruf D
    void D()
    {
        glBegin(GL_POLYGON);
        glColor3ub(0,91,91);
        glVertex2f(328.36,183.72);
        glVertex2f(390.75,183.72);
        glVertex2f(390.75,200.97);
        glVertex2f(328.36,200.97);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,91,91);
        glVertex2f(328.36,200.97);
        glVertex2f(343.9,200.97);
        glVertex2f(343.9,322.06);
        glVertex2f(328.36,322.06);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,91,91);
        glVertex2f(343.9,322.06);
        glVertex2f(390.75,322.06);
        glVertex2f(390.75,304.79);
        glVertex2f(343.9,304.79);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,91,91);
        glVertex2f(390.75,304.79);
        glVertex2f(406.29,304.79);
        glVertex2f(406.29,200.97);
        glVertex2f(390.75,200.97);
        glEnd();
    }
//Huruf A
    void A()
    {
        glBegin(GL_POLYGON);
        glColor3ub(0,91,91);
        glVertex2f(509.88,199.51);
        glVertex2f(463.03,199.51);
        glVertex2f(463.03,182.26);
        glVertex2f(509.88,182.26);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,91,91);
        glVertex2f(509.88,199.51);
        glVertex2f(525.43,199.51);
        glVertex2f(525.43,320.6);
        glVertex2f(509.88,320.6);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,91,91);
        glVertex2f(509.88,286.08);
        glVertex2f(509.88,268.56);
        glVertex2f(463.03,268.56);
        glVertex2f(463.03,286.08);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(0,91,91);
        glVertex2f(463.03,320.6);
        glVertex2f(447.49,320.6);
        glVertex2f(447.49,199.51);
        glVertex2f(463.03,199.51);
        glEnd();
    }
//Huruf H
    void H()
    {
        glBegin(GL_POLYGON);
            glColor3ub(0,91,91);
            glVertex2f(565.48,182.26);
            glVertex2f(581.02,182.26);
            glVertex2f(581.02,320.6);
            glVertex2f(565.48,320.6);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(0,91,91);
            glVertex2f(581.02,251.3);
            glVertex2f(581.02,268.56);
            glVertex2f(627.87,268.56);
            glVertex2f(627.87,251.3);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(0,91,91);
            glVertex2f(627.87,182.26);
            glVertex2f(643.41,182.26);
            glVertex2f(643.41,320.6);
            glVertex2f(627.87,320.6);
        glEnd();
    }

//Huruf G
    void G()
    {
        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(183.17,352.92);
            glVertex2f(190.67,352.92);
            glVertex2f(190.67,399.08);
            glVertex2f(183.17,399.08);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(190.67,399.08);
            glVertex2f(190.67,406.75);
            glVertex2f(213.25,406.75);
            glVertex2f(213.25,399.08);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(190.67,399.08);
            glVertex2f(190.67,406.75);
            glVertex2f(213.25,406.75);
            glVertex2f(213.25,399.08);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(213.25,399.08);
            glVertex2f(220.74,399.08);
            glVertex2f(220.74,375.94);
            glVertex2f(213.25,375.94);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(205.76,375.94);
            glVertex2f(205.76,383.62);
            glVertex2f(220.74,383.62);
            glVertex2f(220.74,375.94);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(213.25,352.92);
            glVertex2f(213.25,345.24);
            glVertex2f(190.67,345.24);
            glVertex2f(190.67,352.92);
        glEnd();
    }
//Huruf 6
    void Enam()
    {
        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(258.95,352);
            glVertex2f(258.95,343.77);
            glVertex2f(235.6,343.77);
            glVertex2f(235.6,352);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(235.6,352);
            glVertex2f(227.85,352);
            glVertex2f(227.85,401.52);
            glVertex2f(235.6,401.52);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(235.6,401.52);
            glVertex2f(235.6,409.76);
            glVertex2f(258.95,409.76);
            glVertex2f(258.95,401.52);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(258.95,401.52);
            glVertex2f(266.7,401.52);
            glVertex2f(266.7,385.05);
            glVertex2f(258.95,385.05);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(258.95,385.05);
            glVertex2f(258.95,376.82);
            glVertex2f(227.85,376.82);
            glVertex2f(227.85,385.05);
        glEnd();

    }
//Huruf 4
    void Empat()
    {
        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(303.69,416.79);
            glVertex2f(295.93,416.79);
            glVertex2f(295.93,343.77);
            glVertex2f(303.69,343.77);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(272.68,380.35);
            glVertex2f(280.43,380.35);
            glVertex2f(295.93,361.99);
            glVertex2f(295.93,352.87);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(272.68,380.35);
            glVertex2f(272.68,389.46);
            glVertex2f(311.44,389.46);
            glVertex2f(311.44,380.35);
        glEnd();
    }
//Huruf 1
    void Satu()
    {
        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(329.13,372.16);
            glVertex2f(337.57,363.1);
            glVertex2f(337.57,354.17);
            glVertex2f(320.81,372.16);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(337.57,345.24);
            glVertex2f(345.89,345.24);
            glVertex2f(345.89,407.86);
            glVertex2f(337.57,407.86);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(329.13,407.86);
            glVertex2f(329.13,416.79);
            glVertex2f(354.2,416.79);
            glVertex2f(354.2,407.86);
        glEnd();
    }

//Huruf 7
    void Tujuh()
    {
        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(359.15,342.59);
            glVertex2f(359.15,351.83);
            glVertex2f(398.08,351.83);
            glVertex2f(398.08,342.59);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(398.08,351.83);
            glVertex2f(378.54,370.45);
            glVertex2f(368.84,370.45);
            glVertex2f(388.24,351.83);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(368.84,370.45);
            glVertex2f(378.54,370.45);
            glVertex2f(378.54,416.67);
            glVertex2f(368.84,416.67);
        glEnd();
    }

//Huruf 0
    void Nol()
    {
        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(406.21,350.99);
            glVertex2f(413.96,350.99);
            glVertex2f(413.96,407.41);
            glVertex2f(406.21,407.41);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(413.96,407.41);
            glVertex2f(413.96,416.79);
            glVertex2f(437.21,416.79);
            glVertex2f(437.21,407.41);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(437.21,407.41);
            glVertex2f(444.97,407.41);
            glVertex2f(444.97,350.99);
            glVertex2f(437.21,350.99);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(437.21,350.99);
            glVertex2f(437.21,341.61);
            glVertex2f(413.96,341.61);
            glVertex2f(413.96,350.99);
        glEnd();
    }

//Huruf 0
    void Nol2()
    {
        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(452.1,349.84);
            glVertex2f(459.85,349.84);
            glVertex2f(459.85,406.26);
            glVertex2f(452.1,406.26);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(459.85,406.26);
            glVertex2f(459.85,415.64);
            glVertex2f(483.1,415.64);
            glVertex2f(483.1,406.26);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(483.1,406.26);
            glVertex2f(490.85,406.26);
            glVertex2f(490.85,349.84);
            glVertex2f(483.1,349.84);
        glEnd();

         glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(483.1,349.84);
            glVertex2f(483.1,340.46);
            glVertex2f(459.85,340.46);
            glVertex2f(459.85,349.84);
        glEnd();
    }

//Huruf 3
    void Tiga()
    {
        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(504.13,359.51);
            glVertex2f(510.66,359.51);
            glVertex2f(510.66,349.98);
            glVertex2f(504.13,349.98);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(510.66,349.98);
            glVertex2f(510.66,340.46);
            glVertex2f(530.26,340.46);
            glVertex2f(530.26,349.98);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(530.26,349.98);
            glVertex2f(536.89,349.98);
            glVertex2f(536.89,369.17);
            glVertex2f(530.26,369.17);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(530.26,369.17);
            glVertex2f(523.73,369.17);
            glVertex2f(523.73,388.22);
            glVertex2f(530.26,388.22);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(530.26,388.22);
            glVertex2f(536.89,388.22);
            glVertex2f(536.89,407.26);
            glVertex2f(530.26,407.26);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(530.26,407.26);
            glVertex2f(530.26,416.79);
            glVertex2f(510.66,416.79);
            glVertex2f(510.66,407.26);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(510.66,407.26);
            glVertex2f(510.66,397.75);
            glVertex2f(504.13,397.75);
            glVertex2f(504.13,407.26);
        glEnd();

    }
//Huruf 5
    void Lima()
    {
        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(584.39,350.16);
            glVertex2f(584.39,340.52);
            glVertex2f(550.47,340.52);
            glVertex2f(550.47,350.16);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(550.47,350.16);
            glVertex2f(558.95,350.16);
            glVertex2f(558.95,369.6);
            glVertex2f(550.47,369.6);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(550.47,369.6);
            glVertex2f(558.95,379.25);
            glVertex2f(575.91,379.25);
            glVertex2f(575.91,369.6);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(575.91,379.25);
            glVertex2f(584.39,379.25);
            glVertex2f(584.39,408.17);
            glVertex2f(575.91,408.17);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(575.91,408.17);
            glVertex2f(575.91,417.82);
            glVertex2f(558.95,417.82);
            glVertex2f(558.95,408.17);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(254,51,10);
            glVertex2f(558.95,408.17);
            glVertex2f(558.95,398.53);
            glVertex2f(550.47,398.53);
            glVertex2f(550.47,408.17);
        glEnd();

    }

//Segitiga Pojok Kiri Atas
    void SegitigaAtas()
    {
        //Kolom 1
        glBegin(GL_POLYGON);
            glColor3ub(148,224,16);
            glVertex2f(0.01,0);
            glVertex2f(57.95,0.1);
            glVertex2f(0.01,33.54);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(12,89,105);
            glVertex2f(0.01,33.55);
            glVertex2f(57.95,0.08);
            glVertex2f(57.95,67);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(78,207,221);
            glVertex2f(0.01,33.54);
            glVertex2f(57.95,66.99);
            glVertex2f(0.005,100.45);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(83,183,199);
            glVertex2f(57.94,133.9);
            glVertex2f(0.01,100.45);
            glVertex2f(57.95,67);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(125,200,9);
            glVertex2f(0.01,167.35);
            glVertex2f(57.94,133.9);
            glVertex2f(0.01,100.45);
        glEnd();

        //Kolom 2
        glBegin(GL_POLYGON);
            glColor3ub(125,200,9);
            glVertex2f(57.95,0.1);
            glVertex2f(115.89,33.54);
            glVertex2f(115.9,0);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(149,220,188);
            glVertex2f(57.95,0.1);
            glVertex2f(115.89,33.54);
            glVertex2f(57.95,66.99);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(212,244,81);
            glVertex2f(115.89,33.54);
            glVertex2f(57.95,66.99);
            glVertex2f(115.88,100.45);
        glEnd();

        //Kolom 3
        glBegin(GL_POLYGON);
            glColor3ub(149,220,188);
            glVertex2f(115.89,33.54);
            glVertex2f(115.9,0);
            glVertex2f(173.84,0.09);
        glEnd();

        //Kolom 4
        glBegin(GL_POLYGON);
            glColor3ub(83,183,199);
            glVertex2f(173.84,0.09);
            glVertex2f(231.78,33.54);
            glVertex2f(231.78,0);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(212,244,81);
            glVertex2f(173.84,0.09);
            glVertex2f(231.78,33.54);
            glVertex2f(173.84,66.99);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(149,220,188);
            glVertex2f(173.84,66.99);
            glVertex2f(173.84,133.9);
            glVertex2f(231.78,100.44);
        glEnd();

        //Kolom 5
        glBegin(GL_POLYGON);
            glColor3ub(229,248,246);
            glVertex2f(231.78,0);
            glVertex2f(289.724,0.079);
            glVertex2f(231.78,33.54);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(125,200,9);
            glVertex2f(289.724,0.079);
            glVertex2f(231.78,33.54);
            glVertex2f(289.72,67);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(203,244,130);
            glVertex2f(231.78,33.54);
            glVertex2f(289.72,67);
            glVertex2f(231.78,100.44);
        glEnd();

        //Kolom 6
        glBegin(GL_POLYGON);
            glColor3ub(212,244,81);
            glVertex2f(347.67,0);
            glVertex2f(347.67,33.54);
            glVertex2f(289.72,0.08);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(143,201,192);
            glVertex2f(347.67,33.54);
            glVertex2f(289.72,0.08);
            glVertex2f(289.724,66.992);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(217,249,245);
            glVertex2f(347.669,100.444);
            glVertex2f(347.669,33.542);
            glVertex2f(289.72,66.998);
        glEnd();

        //Kolom 7
        glBegin(GL_POLYGON);
            glColor3ub(125,200,9);
            glVertex2f(347.67,0);
            glVertex2f(405.6,0.09);
            glVertex2f(347.669,33.542);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(101,142,28);
            glVertex2f(405.6,67);
            glVertex2f(405.6,0.09);
            glVertex2f(347.669,33.542);
        glEnd();

        glBegin(GL_POLYGON);
            glColor3ub(149,220,188);
            glVertex2f(347.669,100.444);
            glVertex2f(347.669,33.542);
            glVertex2f(405.6,67);
        glEnd();

        //Kolom 8
        glBegin(GL_POLYGON);
            glColor3ub(83,183,199);
            glVertex2f(405.6,0.08);
            glVertex2f(463.56,33.54);
            glVertex2f(463.551,0);
        glEnd();

        //Kolom 9
        glBegin(GL_POLYGON);
            glColor3ub(236,255,125);
            glVertex2f(463.56,33.54);
            glVertex2f(463.551,0);
            glVertex2f(521.35,0);
        glEnd();

    }

//Segitiga Tengah
    void SegitigaKananBawah()
    {
    //Kolom 1
        //1
        glBegin(GL_POLYGON);
            glColor3ub(12,89,105);
            glVertex2f(742.05,398.45);
            glVertex2f(800,431.9);
            glVertex2f(742.05,465.37);
        glEnd();
        //2
        glBegin(GL_POLYGON);
            glColor3ub(83,183,199);
            glVertex2f(800,498.82);
            glVertex2f(800,431.9);
            glVertex2f(742.05,465.37);
        glEnd();
        //3
        glBegin(GL_POLYGON);
            glColor3ub(68,202,139);
            glVertex2f(800,498.82);
            glVertex2f(742.05,532.28);
            glVertex2f(742.05,465.37);
        glEnd();

        //5
        glBegin(GL_POLYGON);
            glColor3ub(27,147,0);
            glVertex2f(800,565.74);
            glVertex2f(742.05,599.19);
            glVertex2f(742.05,532.28);
        glEnd();
        //6
        glBegin(GL_POLYGON);
            glColor3ub(83,183,199);
            glVertex2f(800,632.65);
            glVertex2f(800,565.74);
            glVertex2f(742.05,599.19);
        glEnd();
        //7
        glBegin(GL_POLYGON);
            glColor3ub(7,112,29);
            glVertex2f(800,632.65);
            glVertex2f(800,699.55);
            glVertex2f(742.05,666.1);
        glEnd();
        //8
        glBegin(GL_POLYGON);
            glColor3ub(83,183,199);
            glVertex2f(800,699.55);
            glVertex2f(742.05,666.1);
            glVertex2f(742.05,733);
        glEnd();
        //9
        glBegin(GL_POLYGON);
            glColor3ub(83,183,199);
            glVertex2f(742.05,666.1);
            glVertex2f(742.05,733);
            glVertex2f(800,699.55);
        glEnd();
        //9
        glBegin(GL_POLYGON);
            glColor3ub(78,207,221);
            glVertex2f(800,699.55);
            glVertex2f(800,766.45);
            glVertex2f(742.05,733);
        glEnd();
        //10
        glBegin(GL_POLYGON);
            glColor3ub(12,89,105);
            glVertex2f(800,766.45);
            glVertex2f(741.88,800);
            glVertex2f(742.05,733);
        glEnd();
        //11
        glBegin(GL_POLYGON);
            glColor3ub(148,224,16);
            glVertex2f(799.99,766.45);
            glVertex2f(741.88,800);
            glVertex2f(800,800);
        glEnd();

  /*  //Kolom 2
    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();
    }
    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();
    }
    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();


    //Kolom 3
    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();
    }
    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();


    //Kolom 4
    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();


    //Kolom 6
    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();
    }
    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();
    }

    //Kolom 7
    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();
    }
    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();
    }
    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();


    //Kolom 8
    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();


    //Kolom 9
    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

    //
        glBegin(GL_POLYGON);
            glColor3ub();
            glVertex2f();
            glVertex2f();
            glVertex2f();
        glEnd();

*/
    //Kolom 10
    //1
        glBegin(GL_POLYGON);
            glColor3ub(109,204,164);
            glVertex2f(220.55,632.64);
            glVertex2f(278.5,666.1);
            glVertex2f(220.55,699.55);
        glEnd();

    //2
        glBegin(GL_POLYGON);
            glColor3ub(196,224,30);
            glVertex2f(278.5,666.1);
            glVertex2f(220.55,699.55);
            glVertex2f(278.55,733.01);
        glEnd();

    //3
        glBegin(GL_POLYGON);
            glColor3ub(212,244,81);
            glVertex2f(220.55,699.55);
            glVertex2f(278.55,733.01);
            glVertex2f(220.55,766.46);
        glEnd();

    //4
        glBegin(GL_POLYGON);
            glColor3ub(229,248,246);
            glVertex2f(278.55,733.01);
            glVertex2f(220.55,766.46);
            glVertex2f(278.5,800);
        glEnd();

    //Kolom 11
    //1
        glBegin(GL_POLYGON);
            glColor3ub(109,204,164);
            glVertex2f(162.62,733.01);
            glVertex2f(220.55,766.46);
            glVertex2f(220.55,699.55);
        glEnd();

    //2
        glBegin(GL_POLYGON);
            glColor3ub(149,220,188);
            glVertex2f(162.62,733.01);
            glVertex2f(162.45,800);
            glVertex2f(220.55,766.46);
        glEnd();

    //3
        glBegin(GL_POLYGON);
            glColor3ub(125,200,9);
            glVertex2f(162.45,800);
            glVertex2f(220.55,800);
            glVertex2f(220.55,766.46);
        glEnd();


    //Kolom 12
    //
        glBegin(GL_POLYGON);
            glColor3ub(212,244,81);
            glVertex2f(104.66,800);
            glVertex2f(104.67,766.45);
            glVertex2f(162.45,800);
        glEnd();


    //Kolom 13
    //1
        glBegin(GL_POLYGON);
            glColor3ub(109,204,164);
            glVertex2f(46.73,800);
            glVertex2f(104.66,800);
            glVertex2f(104.67,766.45);
        glEnd();
    }


int main(void) {
     // Anti Aliasing
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glEnable(GL_POINT_SMOOTH);

        //Window
        GLFWwindow* window;
        glfwSetErrorCallback(error_callback);

        if (!glfwInit())exit(EXIT_FAILURE);
        window = glfwCreateWindow(800, 800, "Indah Puspita - G64170035", NULL, NULL);

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
            int width, height;
            glfwGetFramebufferSize(window, &width, &height);
            glViewport(0, 0, width, height);

          //fungsi untuk menampilkan objek
        bg();
         I();
         N();
         D();
         A();
         H();

         G();
         Enam();
         Empat();
         Satu();
         Tujuh();
         Nol();
         Nol2();
         Tiga();
         Lima();

         SegitigaAtas();
         SegitigaKananBawah();

        glfwSwapBuffers(window);
        glfwPollEvents();
        }

    //Fungsi Exit
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
 }
