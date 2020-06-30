#include "newComida.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Shader.hh"


newComida::newComida() {  //construtor

}

newComida::~newComida() {  //desconstrutor
	clear();
}


void newComida::createFood() { //chama outra função da imagem
	Imgs();
}

void newComida::Imgs() {  //importa a imagem
	food.setTexture("pika.jpg");
}

void newComida::Draw(float option, float option2, float option3, float option4, unsigned int width, unsigned int height, glm::vec3 cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp){    //desenha a comida da cobra

	glm::vec3 pikas[] = { //posição no tabuleiro das comidas

		glm::vec3(option,  0.55f,  3.5f),
		glm::vec3(option2,  0.55f,  0.5f),
		glm::vec3(option3, 0.55f,   5.5f),
		glm::vec3(option4,  0.55f,  4.7f),
		glm::vec3(4.5f,  0.55f,  3.9f),
		glm::vec3(0.6f,  0.55f,  2.0f),
		glm::vec3(4.0f,  0.55f,  1.1f),

	};


	food.bind(); //textura das nuvens
	for (int x = 0; x < 7; x++) {

		pika = glm::mat4(1.0f);
		pika = glm::translate(pika, pikas[x]); 
		pika = glm::scale(pika, glm::vec3(0.05f, 0.05f, 0.05f));         //faz a escala das comidas
		food.setModel(pika);                                          //passa o model para o vertex.vs
		food.draw(width, height, cameraPos, cameraFront, cameraUp);  // desenha as esferas das comidas

	}
	food.closeBind();

}


void newComida::clear() { //Limpa o objeto da classe cubo, da comida
	food.clear();

}
