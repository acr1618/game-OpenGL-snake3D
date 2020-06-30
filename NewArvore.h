#ifndef ARVORE
#define ARVORE

#include "glm/glm.hpp"
#include "newCube.h"

class newArvore
{
private:

	newCube folha;  //declara os obejtos da classe Cubo
	newCube tronco;

	glm::mat4 folh;  //declara os mat4 para fazer as transformações e passar para o model
	glm::mat4 tronc;


public:

	newArvore(); //construtor
	~newArvore(); //desconstrutor
	
	void createArvore();   //chama outra função da imagem
    void Imgs();          //importa a imagem da arvore
    void Draw(unsigned int width, unsigned int height, glm::vec3 cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp); //desenha a arvore
    void clear();  //Limpa os objetos da classe cubo, das folhas e dos troncos

};

#endif
