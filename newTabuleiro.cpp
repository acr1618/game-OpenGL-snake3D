#include "newTabuleiro.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Shader.hh"

newTabuleiro::newTabuleiro() { //construtor

}

newTabuleiro::~newTabuleiro() { //desconstrutor
	clear();
}

void newTabuleiro::createTabuleiro() { //chama outra função da imagem
	Imgs();
}

void newTabuleiro::Imgs() { //importa a imagem
	tabuleiro.setTexture("grid.jpg");
}


void newTabuleiro::Draw(unsigned int width, unsigned int height, glm::vec3 cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp) { //desenha o tabuleiro
	

	glm::vec3 tabulPosition[] = {  //posição no tabuleirono mundo

			glm::vec3(0.0f,  0.0f,  0.0f),
			glm::vec3(0.0f,  0.0f,  1.0f),
			glm::vec3(0.0f,  0.0f,  2.0f),
			glm::vec3(0.0f,  0.0f,  3.0f),
			glm::vec3(0.0f,  0.0f,  4.0f),
			glm::vec3(0.0f,  0.0f,  5.0f),
			glm::vec3(0.0f,  0.0f,  6.0f),

			glm::vec3(1.0f,  0.0f, 0.0f),
			glm::vec3(1.0f,  0.0f, 1.0f),
			glm::vec3(1.0f,  0.0f, 2.0f),
			glm::vec3(1.0f,  0.0f, 3.0f),
			glm::vec3(1.0f,  0.0f, 4.0f),
			glm::vec3(1.0f,  0.0f, 5.0f),
			glm::vec3(1.0f,  0.0f, 6.0f),

			glm::vec3(2.0f,  0.0f, 0.0f),
			glm::vec3(2.0f,  0.0f, 1.0f),
			glm::vec3(2.0f,  0.0f, 2.0f),
			glm::vec3(2.0f,  0.0f, 3.0f),
			glm::vec3(2.0f,  0.0f, 4.0f),
			glm::vec3(2.0f,  0.0f, 5.0f),
			glm::vec3(2.0f,  0.0f, 6.0f),

			glm::vec3(3.0f,  0.0f, 0.0f),
			glm::vec3(3.0f,  0.0f, 1.0f),
			glm::vec3(3.0f,  0.0f, 2.0f),
			glm::vec3(3.0f,  0.0f, 3.0f),
			glm::vec3(3.0f,  0.0f, 4.0f),
			glm::vec3(3.0f,  0.0f, 5.0f),
			glm::vec3(3.0f,  0.0f, 6.0f),

			glm::vec3(4.0f,  0.0f, 0.0f),
			glm::vec3(4.0f,  0.0f, 1.0f),
			glm::vec3(4.0f,  0.0f, 2.0f),
			glm::vec3(4.0f,  0.0f, 3.0f),
			glm::vec3(4.0f,  0.0f, 4.0f),
			glm::vec3(4.0f,  0.0f, 5.0f),
			glm::vec3(4.0f,  0.0f, 6.0f),

			glm::vec3(5.0f,  0.0f, 0.0f),
			glm::vec3(5.0f,  0.0f, 1.0f),
			glm::vec3(5.0f,  0.0f, 2.0f),
			glm::vec3(5.0f,  0.0f, 3.0f),
			glm::vec3(5.0f,  0.0f, 4.0f),
			glm::vec3(5.0f,  0.0f, 5.0f),
			glm::vec3(5.0f,  0.0f, 6.0f),
	};

	tabuleiro.bind();  //textura das nuvens
	
	for (int x = 0; x < 42; x++) {
		tabul = glm::mat4(1.0f);
		tabul = glm::translate(tabul, tabulPosition[x]);  //coloca cada cubo no mundo na sua posição
		tabuleiro.setModel(tabul);                                          //passa o model para o vertex.vs
		tabuleiro.draw(width, height, cameraPos, cameraFront, cameraUp);    // desenha os cubos do tabuleiro
	}

	tabuleiro.closeBind();

}


void newTabuleiro::clear() { //Limpa o objeto da classe cubo, do tabuleiro
	tabuleiro.clear();
}
