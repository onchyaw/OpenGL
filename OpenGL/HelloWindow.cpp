#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    if (GLFWwindow* Window = glfwCreateWindow(1024, 512, "HelloWindow", nullptr, nullptr))
    {
        glfwMakeContextCurrent(Window);
        glfwSetFramebufferSizeCallback(Window, [](GLFWwindow* Window, int Width, int Height) { glViewport(0, 0, Width, Height); });

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            return -1;

        while (!glfwWindowShouldClose(Window))
        {
            if (glfwGetKey(Window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
                glfwSetWindowShouldClose(Window, true);

            glClearColor(1.f, 0.3f, 0.5f, 1.f);
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(Window);
            glfwPollEvents();
        }
    }
    
    glfwTerminate();
    return 0;
}