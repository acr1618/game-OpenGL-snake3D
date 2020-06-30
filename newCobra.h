#ifndef COBRA
#define COBRA

#include "glm/glm.hpp"
#include "newCube.h"

class newCobra
{
private:
	newCube cabecaCobra;   //declara os obejtos da classe Cubo
	newCube corpoCobra;


	glm::mat4 caCobra; //declara os mat4 para fazer as transforma��es e passar para o model
	glm::mat4 coCobra;

	glm::vec3 moveCobra = glm::vec3(0.0f, 1.0f, 0.0f);


public:
	
	newCobra(); //construtor
	~newCobra();  //desconstrutor

	void createCobra(); //chama outra fun��o da imagens
	
	void Imgs();  //importa a imagem da cabe�a e corpo da cobra

	void Draw(int i, unsigned int width, unsigned int height, glm::vec3 cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp); //desenha a cabe�a da cobra
	
	void clear(); //Limpa os objetos da classe cubo

	void cobra(glm::vec3 move); //movimento da cobra

};

#endif


