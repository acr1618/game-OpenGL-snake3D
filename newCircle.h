#ifndef CIRCLE
#define CIRCLE
#include<vector>
#include "Shader.hh"
#include "glm/glm.hpp"

#pragma once
class newCircle
{
private:
	unsigned int cubeVAO, cubeVBO, cubeEBO; //declara o VBO e VAO
	unsigned int cubeVBO2; 
	unsigned int texture;  //declara a textura
	std::vector<int> indices;  //declara o vector de indices

	Shader myShader;  //declara o Shader

	//mat4 q serão usados para passar para o shader
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;


public:

	newCircle();  //construtor
	~newCircle(); //desconstrutor

	void setTexture(const char* path); //recebe o caminho da textura
	void setModel(glm::mat4 modelObj);  //recebe model por paramentro
	void bind();
	void draw(unsigned int width, unsigned int height, glm::vec3 cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp); //desenha o circulo
	void clear();  // limpa o VAO e a textura 
	void closeBind();

private:
	void createCircle(); //cria a esfera
	void bindTexture();
	void bindVertex();
	float toRadians(float degrees);
};

#endif
