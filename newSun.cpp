#include "newSun.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Shader.hh"

newSun::newSun() { //construtor

}

newSun::~newSun() {  //desconstrutor
	clear();
}

void newSun::createSun() {  //chama outra função da imagem
	Imgs();
}

void newSun::Imgs() {   //importa a imagem
	sun.setTexture("sol.jpg");  
}


void newSun::Draw(unsigned int width, unsigned int height, glm::vec3 cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp) {  //desenha o sol

	glm::vec3 Sol[] = {  //posição dado sol

      glm::vec3(1.0f,  2.25f,  0.0f)

	};

	sun.bind();  //textura do sol
	count = count + 0.5f;

		soll = glm::mat4(1.0f);
		soll = glm::translate(soll, Sol[0]);
		soll = glm::scale(soll, glm::vec3(0.5f, 0.4f, 0.5f));  //faz a escala do sol
		soll = glm::rotate(soll, glm::radians(count), glm::vec3(0.0, 0.0, 1.0)); //rotação em torno do seu proprio eixo

		sun.setModel(soll);  //passa o model para o vertex.vs
		sun.draw(width, height, cameraPos, cameraFront, cameraUp);  // desenha o circulo do sol
	
	sun.closeBind();

}


void newSun::clear() { //Limpa o objeto da classe Circulo, do sun
	sun.clear();
}

