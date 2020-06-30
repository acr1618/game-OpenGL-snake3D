#ifndef SUN 
#define SUN 

#include "glm/glm.hpp"
#include "newCircle.h"

class newSun
{
private:

	glm::mat4 soll;  //declara o mat4 para fazer as transformações e passar para o model
	float count = 5.0f;  // variavel para fazer a rotate do sol
	newCircle sun; //declara o obejto da classe Circulo

public:

	newSun();  //construtor
	~newSun();  //desconstrutor

	void createSun(); //chama outra função da imagem do sol

	void Imgs(); //importa a imagem do sol

	void Draw(unsigned int width, unsigned int height, glm::vec3 cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp); //desenha o sol

	void clear();  //Limpa o objeto da classe Circulo, do sun

};

#endif


