#ifndef TABULEIRO
#define TABULEIRO

#include "glm/glm.hpp"
#include "newCube.h"

class newTabuleiro
{
private:
	newCube tabuleiro; //declara o obejto da classe Cubo
	glm::mat4 tabul; //declara o mat4 para fazer as transformações e passar para o model

public:


	newTabuleiro(); //construtor
	~newTabuleiro(); //desconstrutor

	void createTabuleiro(); //chama outra função da imagem do tabuleiro
	
	void Imgs(); //importa a imagem do tabuleiro

	void Draw(unsigned int width, unsigned int height, glm::vec3 cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp); //desenha o tabuleiro

	void clear(); //Limpa o objeto da classe cubo, do tabuleiro
};

#endif
