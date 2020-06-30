#include "newCamera.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "windows.h" 
#include "Shader.hh"
#include "newCube.h"

newCamera::newCamera() { //construtor

}

void newCamera::cam(float lastX, float lastY, double ypos, double xpos, float yaw, float pitch) { //Angulo do rato

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	float sensitivity = 0.05;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(direction);
}


void newCamera::zoom(GLFWwindow *window) {  //Zoom do teclado e moviemnto da cobra

	const float cameraSpeed = 0.1f; // e a velocidade dos moveimentos

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		cameraPos += cameraSpeed * cameraFront;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		cameraPos -= cameraSpeed * cameraFront;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;

	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {  // move a cobra para baixo

		if (x > -19.20) {

			moveSnake = glm::vec3(x -= 0.10, y, z);
			moveSnake2 = glm::vec3(x2 = x + 1.0, y, z2 = z);
			moveSnake3 = glm::vec3(x3 = x + 2.0, y, z3 = z);

		}

	}

	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) { // move a cobra para direita


		if (z < 16.0) {

			moveSnake = glm::vec3(x, y, z += 0.10);
			moveSnake2 = glm::vec3(x2 = x, y, z2 = z - 0.9);
			moveSnake3 = glm::vec3(x3 = x, y, z3 = z - 1.8);

		}
	}

	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) { // move a cobra para cima
		if (x < -0.899971) {

			moveSnake = glm::vec3(x += 0.10, y, z);
			moveSnake2 = glm::vec3(x2 = x - 1.0, y, z2 = z);
			moveSnake3 = glm::vec3(x3 = x - 2.0, y, z3 = z);

		}
	}

	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) { // move a cobra para a esquerda

		if (z > 0.8 ) {

			moveSnake = glm::vec3(x, y, z -= 0.10);
			moveSnake2 = glm::vec3(x2 = x, y, z2 = z + 0.9);
			moveSnake3 = glm::vec3(x3 = x, y, z3 = z + 1.8);

		}
	}
	


}