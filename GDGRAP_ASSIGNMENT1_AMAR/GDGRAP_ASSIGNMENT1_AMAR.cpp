//Rameses P. Amar GDGRAP
//

#include <iostream>
#include<cmath>
#include<vector>

#include <GLFW/glfw3.h>
#define PI 3.14



int main(void)
{
    GLFWwindow* window;

    float x = .92f, y = .38f;

    float rad = (45 * PI) / 180;

    float Xvert[8];
    float Yvert[8];

    Xvert[0] = x;
    Yvert[0] = y;


    for (int i = 0;i < 8;i++)
    {

        float a, b, z, v;
        std::cout << Xvert[i] << ", " << Yvert[i] + .1f << "\n";
        a = (Xvert[i] * cos(rad)) - (Yvert[i] * sin(rad));
        b = (Xvert[i] * sin(rad)) + (Yvert[i] * cos(rad));

        //round off:
        z = std::floorf(a * 100) / 100.0f;
        v = std::floorf(b * 100) / 100.0f;

        Xvert[i + 1] = z;
        Yvert[i + 1] = v;
    }





    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Rameses P. Amar:    THE OCTAGON", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_POLYGON);





        for (int i = 0;i < 8;i++)
        {

            glVertex2f(Xvert[i], Yvert[i] + .1f);
        }

        glEnd();
        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();


    }



    glfwTerminate();
    return 0;
}