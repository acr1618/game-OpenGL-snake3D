#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "windows.h" 
#include "Shader.hh"
#include "newCube.h"

class newCamera
{
public:

	float x = -16.8, y = 3.859, z = 8.75, z2 = 9.65001, x2 = -16.8, z3 = 10.65001, x3 = -16.8;  //variaveis usadas no movimento da cobra

	//posição inicial da camera

	glm::vec3 cameraPos = glm::vec3(-1.21507f, 4.04806f, 9.40119f);
	glm::vec3 cameraFront = glm::vec3(0.510131f, -0.443853f, -0.736723f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	//movimento da cobra

	glm::vec3 moveSnake = glm::vec3(x, y, z);
	glm::vec3 moveSnake2 = glm::vec3(x2, y, z2);
	glm::vec3 moveSnake3 = glm::vec3(x3, y, z3);

	newCamera();

	void cam(float lastX, float lastY, double ypos, double xpos, float yaw, float pitch); // moviemnto do rato

	void zoom(GLFWwindow *window); // moviemnto do teclado

};

