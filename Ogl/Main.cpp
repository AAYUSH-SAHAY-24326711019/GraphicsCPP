#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

using namespace std;
int main1() {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	int height_Window = 200;
	int width_Window = 600;
	GLFWwindow* window = glfwCreateWindow(width_Window, height_Window, "Message for window", NULL,NULL);
	if (window == NULL){
		cout << "failed to create the window";
		glfwTerminate();
		return -1;
	}
	else
		cout << "window made successfully";

	glfwMakeContextCurrent(window);
	gladLoadGL();

	glViewport(0,0,width_Window,height_Window);

	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwSwapBuffers(window);
	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

	}

	glfwDestroyWindow(window);
	glfwTerminate();


	return 0;
}