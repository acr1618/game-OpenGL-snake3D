#include "NewArvore.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Shader.hh"


newArvore::newArvore() {  //construtor

}

newArvore::~newArvore() {  //desconstrutor
	clear();
}

void newArvore::createArvore() { //chama outra função das imagens
	Imgs();
}

void newArvore::Imgs() {          //importa as imagens
	folha.setTexture("arv.jpg");

	tronco.setTexture("tron.jpg");
}

void newArvore::Draw(unsigned int width, unsigned int height, glm::vec3 cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp) {  //desenha a arvore


	folha.bind();			//textura das folhas
	folh = glm::mat4(1.0f);

	glm::vec3 folhas[] = {	//posição no tabuleiro das folhas

		glm::vec3(-0.1f,  1.25f, 0.3f),
		glm::vec3(-0.2f,  1.25f,  5.0f),
		glm::vec3(5.0f,  1.25f,  -0.2f),
		glm::vec3(2.0f,  1.25f,  3.0f),
		glm::vec3(4.8f,  1.25f,  6.2f),
		glm::vec3(5.3f,  1.25f,  3.5f),
		glm::vec3(2.5f,  1.25f,  -0.2f),

	};


	for (int x = 0; x < 7; x++) {
		folh = glm::mat4(1.0f);
		folh = glm::translate(folh, folhas[x]);
		folh = glm::scale(folh, glm::vec3(0.6f, 0.4f, 0.6f));  //faz a escala das folhas da arvore
		folha.setModel(folh);								   //passa o model para o vertex.vs
		folha.draw(width, height, cameraPos, cameraFront, cameraUp);  // desenha o cubo das folhas
	}
	folha.closeBind();

	tronco.bind();					//passa a textura dos troncos
	tronc = glm::mat4(1.0f);		

	glm::vec3 troncos[] = {//posição no tabuleiro dos troncos

	glm::vec3(-0.1f,  0.82f, 0.3f),
	glm::vec3(-0.2f,  0.82f,  5.0f),
	glm::vec3(5.0f,  0.82f,  -0.2f),
	glm::vec3(2.0f,  0.82f,  3.0f),
	glm::vec3(4.8f,  0.82f,  6.2f),
	glm::vec3(5.3f,  0.82f,  3.5f),
    glm::vec3(2.5f,  0.82f,  -0.2f),

	};

	for (int x = 0; x < 7; x++) {
		tronc = glm::mat4(1.0f);
		tronc = glm::translate(tronc, troncos[x]); 
		tronc = glm::scale(tronc, glm::vec3(0.2f, 0.638f, 0.2f));      //faz a escala dos troncos da arvore
		tronco.setModel(tronc);								           //passa o model para o vertex.vs
		tronco.draw(width, height, cameraPos, cameraFront, cameraUp);  // desenha o cubo dos troncos
	}
	tronco.closeBind();

}


void newArvore::clear() { //Limpa os objetos da classe cubo, das folhas e dos troncos
	folha.clear();
	tronco.clear();
}
