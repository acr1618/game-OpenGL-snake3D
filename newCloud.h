#ifndef CLOUD
#define CLOUD 

#include "glm/glm.hpp"
#include "newCube.h"

class newCloud
{
private:

	newCube nuvem; //declara o obejto da classe Cubo

	glm::mat4 nuv;  //declara o mat4 para fazer as transformações e passar para o model
	float count = 5.0f; // variavel para fazer a rotate da nuvem
	
public:

	newCloud();  //construtor
	~newCloud();  //desconstrutor
	
	void createCloud();   //chama outra função da imagem da nuvem

	void Imgs();  //importa a imagem da nuvem

	void Draw(unsigned int width, unsigned int height, glm::vec3 cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp);  //desenha a nuvem
	
	void clear(); //Limpa o objeto da classe cubo, da nuvem

};

#endif


