#ifndef M_CUBE
#define M_CUBE

#include "Shader.hh"
#include "glm/glm.hpp"

class newCube
{
private:
	unsigned int VBO, VAO; //declara o VBO e VAO
	unsigned int texture;  //declara a textura
	Shader myShader;  //declara o Shader

	//mat4 q serão usados para passar para o shader
	glm::mat4 model;  
	glm::mat4 view;
	glm::mat4 projection;

public:

	newCube(); //construtor
	~newCube(); //desconstrutor

	void setTexture(const char* path); //recebe o caminho da textura
	void setModel(glm::mat4 modelObj); //recebe model por paramentro

	void bind();
	void draw(unsigned int width, unsigned int height, glm::vec3 cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp); //desenha o cubo
	void clear();  // limpa o VAO e a textura 
	void closeBind();

private:

	void bindTexture();
	void bindVertex();
	void createCube();  //cria o cubo

};
#endif
