#include "Mundo.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Shader.hh"


Mundo::Mundo() {   //construtor
}


Mundo::~Mundo() {   //desconstrutor
	clear();
}


void Mundo::createMundo() {

	 type.cenario();
	 option = type.RandomBetween();   //gera uma posicão diferente do pikachu, cada vez que o tabuleiro é inicalizado.
	 option2 = type.RandomBetween();
	 option3 = type.RandomBetween();
	 option4 = type.RandomBetween();  


	 tabuleiro.createTabuleiro();  //cria os objetos no mundo.
	 arvore.createArvore();
	 food.createFood();
	 sun.createSun();
	 moon.createMoon();
	 nuvem.createCloud();

}


void Mundo::Draw(unsigned int width, unsigned int height, glm::vec3 cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp) { //desenha os objetos no mundo.

	tabuleiro.Draw(width, height, cameraPos, cameraFront, cameraUp);
	arvore.Draw(width, height, cameraPos, cameraFront, cameraUp);
	food.Draw(option, option2, option3, option4, width, height, cameraPos, cameraFront, cameraUp);
	sun.Draw(width, height, cameraPos, cameraFront, cameraUp);
	moon.Draw(width, height, cameraPos, cameraFront, cameraUp);
	nuvem.Draw(width, height, cameraPos, cameraFront, cameraUp);
}

void  Mundo::clear() { //Limpa os objetos do mundo.
	
	arvore.clear();
	nuvem.clear();
	food.clear();
	sun.clear();
	tabuleiro.clear();
	moon.clear();
}

