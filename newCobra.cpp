#include "newCobra.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Shader.hh"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

newCobra::newCobra() { //construtor

}

newCobra::~newCobra() { //desconstrutor
	clear();
}


void newCobra::createCobra() { //chama outra função das imagens
	Imgs();
}

void newCobra::Imgs() {       //importa as imagens
	cabecaCobra.setTexture("cabeca.jpg");
	corpoCobra.setTexture("pele.jpg");
}


void newCobra::Draw(int i, unsigned int width, unsigned int height, glm::vec3 cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp) {    //desenha a arvore cabeça


	if (i == 0) {
		cabecaCobra.bind(); //textura da cabeça

		caCobra = glm::mat4(1.0f);
		caCobra = glm::rotate(caCobra, glm::radians(90.0f), glm::vec3(0.0, 1.0, 0.0)); //posição inicial da cabeça
		caCobra = glm::scale(caCobra, glm::vec3(0.3f, 0.15f, 0.3f)); //faz a escala
		caCobra = glm::translate(caCobra, moveCobra); //movimenta a cabeça
		caCobra = glm::scale(caCobra, glm::vec3(1.0f, 0.95f, 0.8f)); //faz uma nova escala

		cabecaCobra.setModel(caCobra);  //passa o model para o vertex.vs
		cabecaCobra.draw(width, height, cameraPos, cameraFront, cameraUp);  // desenha a cabeça
			cabecaCobra.closeBind(); 
	}
	else {

		corpoCobra.bind();
		coCobra = glm::mat4(1.0f);
		coCobra = glm::rotate(coCobra, glm::radians(90.0f), glm::vec3(0.0, 1.0, 0.0)); //posição inicial do corpo
		coCobra = glm::scale(coCobra, glm::vec3(0.3f, 0.15f, 0.3f));//faz a escala
		coCobra = glm::translate(coCobra, moveCobra); //movimenta o corpo

		corpoCobra.setModel(coCobra); //passa o model para o vertex.vs
		corpoCobra.draw(width, height, cameraPos, cameraFront, cameraUp); // desenha o corpo
		corpoCobra.closeBind();
	}

}


void newCobra::cobra(glm::vec3 move) { //movimento da cobra
	moveCobra = move;
}


void newCobra::clear() { //Limpa os objetos da classe cubo
	cabecaCobra.clear();
	corpoCobra.clear();
	
}
