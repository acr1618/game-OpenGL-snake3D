#include "newCircle.h"
#include <GL/glew.h>
#include "stb_image.h"
#include <iostream>
#include "glm/gtc/matrix_transform.hpp"

//Construtor
newCircle::newCircle() : myShader("vertex.vs", "fragment.fs") {
	createCircle();
}

newCircle::~newCircle() {
	clear();
}

//Methds
float newCircle::toRadians(float degrees) {
	return (degrees * 2.0f * 3.14159f) / 360.0f;
}

void newCircle::createCircle() {

	model = glm::mat4(1.0f);
	view = glm::mat4(1.0f);
	projection = glm::mat4(1.0f);

	int radius = 1;
	int sectorCount = 36;
	int stackCount = 18;
	float PI = 3.1415;
	std::vector<float> vertices;
	std::vector<float> normals;
	std::vector<float> texCoords;
	float x, y, z, xy;								// posição do vértice
	float nx, ny, nz, lengthInv = 1.0f / radius;    // vértice normal
	float s, t;										// coordenadas do vértice
	float sectorStep = 2 * PI / sectorCount;
	float stackStep = PI / stackCount;
	float sectorAngle, stackAngle;
	for (int i = 0; i <= stackCount; ++i)
	{
		stackAngle = PI / 2 - i * stackStep;        // iniciando de pi / 2 a -pi / 2
		xy = radius * cosf(stackAngle);             // r * cos(u)
		z = radius * sinf(stackAngle);              // r * sin(u)

		// adiciona (setorCount + 1) vértices por pilha
		// o primeiro e o último vértices têm a mesma posição e o normal, mas diferentes cordas tex
		for (int j = 0; j <= sectorCount; ++j)
		{
			sectorAngle = j * sectorStep;           // começando de 0 a 2pi

			// posição do vértice (x, y, z)
			x = xy * cosf(sectorAngle);             // r * cos(u) * cos(v)
			y = xy * sinf(sectorAngle);             // r * cos(u) * sin(v)
			vertices.push_back(x);
			vertices.push_back(y);
			vertices.push_back(z);

			// vértice normalizado normal (nx, ny, nz)
			nx = x * lengthInv;
			ny = y * lengthInv;
			nz = z * lengthInv;
			normals.push_back(nx);
			normals.push_back(ny);
			normals.push_back(nz);

			// vértice tex coord (s, t) varia entre [0, 1]
			s = (float)j / sectorCount;
			t = (float)i / stackCount;
			texCoords.push_back(s);
			texCoords.push_back(t);
		}
	}
	// gera lista de índice CCW de triângulos de esfera

	int k1, k2;
	for (int i = 0; i < stackCount; ++i)
	{
		k1 = i * (sectorCount + 1);     // início da pilha atual
		k2 = k1 + sectorCount + 1;     // início da próxima pilha

		for (int j = 0; j < sectorCount; ++j, ++k1, ++k2)
		{
			// 2 triângulos por setor, excluindo a primeira e a última pilhas
			// k1 => k2 => k1 + 1
			if (i != 0)
			{
				indices.push_back(k1);
				indices.push_back(k2);
				indices.push_back(k1 + 1);
			}

			// k1+1 => k2 => k2+1
			if (i != (stackCount - 1))
			{
				indices.push_back(k1 + 1);
				indices.push_back(k2);
				indices.push_back(k2 + 1);
			}
		}
	}

	glGenVertexArrays(1, &cubeVAO);
	glGenBuffers(1, &cubeVBO);
	glGenBuffers(1, &cubeEBO);

	glBindVertexArray(cubeVAO);

	float* pvertarray = &vertices[0];
	glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, cubeEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), &indices[0], GL_STATIC_DRAW);

	glGenBuffers(1, &cubeVBO2);
	glBindBuffer(GL_ARRAY_BUFFER, cubeVBO2);

	glBufferData(GL_ARRAY_BUFFER, sizeof(texCoords[0]) * texCoords.size(), &texCoords[0], GL_STATIC_DRAW);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void newCircle::setTexture(const char* path) {
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

void newCircle::bind() {

	newCircle::bindTexture();
	newCircle::bindVertex();
}

void newCircle::bindTexture() {
	// vincular texturas nas unidades de textura correspondentes
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
}

void newCircle::bindVertex() {
	glBindVertexArray(cubeVAO);
}

void newCircle::closeBind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void newCircle::setModel(glm::mat4 modelObj) { // Recebe o mat4 dos objetos
	model = modelObj;
}

void newCircle::draw(unsigned int width, unsigned int height, glm::vec3 cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp) {
	myShader.use(); // usa o shader
	view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	projection = glm::perspective(glm::radians(45.0f), (float)width / (float)height, 0.1f, 100.0f);
	myShader.setMat4("model", model); // passa o model para o shader
	myShader.setMat4("view", view); // passa o view para o shader
	myShader.setMat4("projection", projection); // passa o projection para o shader
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);  // desenha o circulo
}

void newCircle::clear() {  // limpa o VAO, VBO, VBO2, EBO e a textura 
	glDeleteVertexArrays(1, &cubeVAO);
	glDeleteBuffers(1, &cubeVBO);
	glDeleteBuffers(1, &cubeVBO2);
	glDeleteBuffers(1, &cubeEBO);
	glDeleteTextures(1, &texture);
}


