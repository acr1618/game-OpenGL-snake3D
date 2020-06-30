
#include <iostream>
#include <stdlib.h>
#include <time.h>

#define GLEW_STATIC
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "glm/glm.hpp"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "windows.h" 
#include "Shader.hh"
#include "newCamera.h"
#include "Mundo.h"
#include "newCobra.h"
#include <stdlib.h>

//#define GLEW_STATIC

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);

// settings
const unsigned int SCR_WIDTH = 1024;  //largura da janela de visualização
const unsigned int SCR_HEIGHT = 768;  //altura da janela de visualização

newCamera cam;

//center mouse
float lastX = SCR_WIDTH / 2, lastY = SCR_HEIGHT / 2;
bool firstMouse = true;

float yaw = -55.3, pitch = -26.35;

int main()
{	
	// glfw: initialize and configure
	glfwInit();
	glfwWindowHint(GLFW_SAMPLES, 16);  // anti-aliasing factor
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);  //resizable window = false
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy;
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // use modern openGL

	// Open a window and create its OpenGL context
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Snake", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		std::cin.get();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  //deal with window resize

	//mouse
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(window, mouse_callback);

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Initialize GLEW
	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to initialize GLEW\n";
		std::cin.get();
		glfwTerminate();
		return -1;
	}

	Mundo world;          
	world.createMundo();  //importa as imagens do mundo

	newCobra movCobra;
	movCobra.createCobra();  //importa as imagem do cobra


	glEnable(GL_DEPTH_TEST);
	while (!glfwWindowShouldClose(window)) {
		processInput(window);

		//background Color
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// chama o metodo da classe cobra para desenhar e por argumento é passado o movimento que foi feito no teclado pelo utilizador
		movCobra.cobra(cam.moveSnake);
		movCobra.Draw(0, SCR_WIDTH, SCR_HEIGHT, cam.cameraPos, cam.cameraFront, cam.cameraUp);
		movCobra.cobra(cam.moveSnake2);
		movCobra.Draw(1,SCR_WIDTH, SCR_HEIGHT, cam.cameraPos, cam.cameraFront, cam.cameraUp);
		movCobra.cobra(cam.moveSnake3);
		movCobra.Draw(1,SCR_WIDTH, SCR_HEIGHT, cam.cameraPos, cam.cameraFront, cam.cameraUp);

		world.Draw(SCR_WIDTH, SCR_HEIGHT, cam.cameraPos, cam.cameraFront, cam.cameraUp);  // cria/desenha o mundo com as transformações 

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	world.clear();  //Limpa os objetos da classe q está na calsse mundo
	
	glfwTerminate();
	return 0;
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	cam.zoom(window);  // usa a camera do teclado para dar zoom

}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	cam.cam(lastX, lastY, ypos, xpos, yaw, pitch);  // usa a rato/mouse para ver em varios angulos
}
