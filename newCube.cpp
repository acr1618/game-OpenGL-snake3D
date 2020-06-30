#include "newCube.h"
#include <GL/glew.h>
#include "stb_image.h"
#include <iostream>
#include "glm/gtc/matrix_transform.hpp"



newCube::newCube() : myShader("vertex.vs", "fragment.fs") { // construtor
	createCube();
}

newCube::~newCube() { // desconstrutor
	clear();
}

void newCube::createCube() {

	model = glm::mat4(1.0f);
	view = glm::mat4(1.0f);
	projection = glm::mat4(1.0f);

	float vertices[] = {
			-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
			0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
			0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			0.5f,  0.5f, -0.5f,  1.0f, 1.0f, /*tras*/
			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
			0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
			0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
			-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,  /*centro*/
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

			-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
			-0.5f,  0.5f, -0.5f,  -1.0f, 0.0f,
			-0.5f, -0.5f, -0.5f,  -1.0f, -1.0f,  /*esquerdo*/
			-0.5f, -0.5f, -0.5f,  -1.0f, -1.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,
			-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,

			0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
			0.5f,  0.5f, -0.5f,  -1.0f, 0.0f,
			0.5f, -0.5f, -0.5f,  -1.0f, -1.0f,  /*direito*/
			0.5f, -0.5f, -0.5f,  -1.0f, -1.0f,
			0.5f, -0.5f,  0.5f,  0.0f, -1.0f,
			0.5f,  0.5f,  0.5f,  0.0f, 0.0f,

			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
			0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
			0.5f, -0.5f,  0.5f,  1.0f, 0.0f,  /*baixo*/
			0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
			-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
			0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
			0.5f,  0.5f,  0.5f,  1.0f, 0.0f,  /*cima*/
			0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
			-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
			-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// atributo posição
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// atributo de coordenação da textura
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void newCube::setTexture(const char* path) {  // coloca a textura no cubo
	int width, height, nrChannels;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	// define os parâmetros de quebra de textura
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// define parâmetros de filtragem de textura
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// carrega imagem, cria textura e gera mipmaps
	stbi_set_flip_vertically_on_load(true); // diga ao stb_image.h para inverter as texturas carregadas no eixo y.
	unsigned char* data = stbi_load(path, &width, &height, &nrChannels, 0);
	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else {
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
}

void newCube::bind() {
	newCube::bindTexture();
	newCube::bindVertex();
}

void newCube::bindTexture() { // vincular texturas nas unidades de textura correspondentes
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
}

void newCube::closeBind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void newCube::bindVertex() {
	glBindVertexArray(VAO);
}

void newCube::clear() {   // limpa o VAO e a textura 
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteTextures(1, &texture);
}

void newCube::setModel(glm::mat4 modelObj) { // Recebe o mat4 dos objetos
	model = modelObj;
}

void newCube::draw(unsigned int width, unsigned int height, glm::vec3 cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp) {

	myShader.use(); // usa o shader

	view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);  
	projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);
	
	myShader.setMat4("model", model); // passa o model para o shader
	myShader.setMat4("view", view);  // passa o view para o shader
	myShader.setMat4("projection", projection); // passa a projection para o shader
	glDrawArrays(GL_TRIANGLES, 0, 36); // desenha o cubo
}

