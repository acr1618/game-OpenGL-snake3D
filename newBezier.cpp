#include "newBezier.h"
#include <iostream>
#define GLEW_STATIC
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

#include "Shader.hh"


// Construtor
newBezier::newBezier() : myShader("C:/Users/LENOIVO/source/repos/ConsoleApplication1/ConsoleApplication1/ver.vs", "C:/Users/LENOIVO/source/repos/ConsoleApplication1/ConsoleApplication1/frag.fs") {
	createBezier();
}

newBezier::~newBezier() {
	clear();
}

void newBezier::createBezier() {

	int nSegs = 100;
	float delta = 1.0 / nSegs;
	glm::vec4 p0 = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	glm::vec4 p1 = glm::vec4(1.5f, 0.0f, 0.0f, 1.0f);
	glm::vec4 p2 = glm::vec4(0.0f, 0.5f, 0.0f, 1.0f);
	glm::vec4 p3 = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
	for (int i = 0; i < nSegs + 1; i++) {		glm::vec4 novoPonto = toBezier(delta, i, p0, p1, p2, p3);		vertices2.push_back(novoPonto.x);		vertices2.push_back(novoPonto.y);		vertices2.push_back(novoPonto.z);	}

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2[0]) * vertices2.size(), &vertices2[0], GL_STATIC_DRAW);

	// position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

glm::vec4 toBezier(float delta, int i, glm::vec4 P0, glm::vec4 P1, glm::vec4 P2, glm::vec4 P3)
{
	float t = delta * float(i);	float t_menos = (1 - t);	float t_menos_quadrado = t_menos * t_menos;	float t_menos_cubo = t_menos * t_menos_quadrado;	glm::vec4 Point = t_menos_cubo * P0 + 3.0f*t_menos_quadrado*P1*t + 3.0f*t_menos*t*t*P2 + t * t*t*P3;	return Point;

}
void newBezier::bind() {
	newBezier::bindVertex();
}


void newBezier::closeBind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void newBezier::bindVertex() {
	glBindVertexArray(VAO);
}

void newBezier::clear() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}


void newBezier::draw(unsigned int width, unsigned int height, glm::vec3 cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp) {
	myShader.use();

	glm::mat4 linha;
	linha = glm::mat4(1.0f);
	linha = glm::translate(linha, glm::vec3(0.0f, 2.25f, 0.0f));

	view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);
	myShader.setMat4("model", linha);
	myShader.setMat4("view", view);
	myShader.setMat4("projection", projection);
	//glDrawArrays(GL_LINE_STRIP, 0, 3);
	glDrawArrays(GL_LINE_STRIP, 0, vertices2.size() / 3);
}


