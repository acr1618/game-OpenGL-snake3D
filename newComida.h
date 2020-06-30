#ifndef COMIDA 
#define COMIDA 

#include "glm/glm.hpp"
#include "newCircle.h"

class newComida
{
private:

	newCircle food; //declara o obejto da classe Cubo
	glm::mat4 pika; //declara o mat4 para fazer as transformações e passar para o model
	
public:

	newComida();   //construtor
	~newComida(); //desconstrutor

	void createFood(); //chama outra função da imagem do pikachu

	int cenario();

	float RandomBetween();

	void Imgs(); //importa a imagem do pikachu

	void Draw(float option, float option2, float option3, float option4, unsigned int width, unsigned int height, glm::vec3 cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp); //desenha o pikachu

	void clear(); //Limpa o objeto da classe cubo, do pikachu
};

#endif


