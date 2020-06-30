#include "newMoon.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Shader.hh"

newMoon::newMoon() { //construtor

}

newMoon::~newMoon() { //desconstrutor
	clear();
}

void newMoon::createMoon() { //chama outra função da imagem
	Imgs();
}

void newMoon::Imgs() {
	moon.setTexture("lua.jpg"); //importa a imagem
}


void newMoon::Draw(unsigned int width, unsigned int height, glm::vec3 cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp) {   //desenha a lua


	glm::vec3 luaa[] = {   //posição das luas

	  glm::vec3(1.0f,  2.25f,  0.0f),
	  glm::vec3(1.0f,  2.25f,  0.0f),
	  glm::vec3(1.0f,  2.25f,  0.0f),
	  glm::vec3(1.0f,  2.25f,  0.0f)
	};

	moon.bind();  //textura das luas
	count = count + 0.5f;
	for (int i = 0; i < 4; i++) {


		lua = glm::mat4(1.0f);
		lua = glm::translate(lua, luaa[i]);
		lua = glm::scale(lua, glm::vec3(0.25f, 0.2f, 0.25f));   //faz a escala das luas
		lua = glm::rotate(lua, glm::radians(count), glm::vec3(0.0, 5.0, 0.0));  //rotação em torno do sol
		if (i == 0) {
			lua = glm::translate(lua, glm::vec3(2.0f, 0.0f, -3.0f)); //movimento de mudar de posição da lua[0]

		}
		if (i == 1) {
			lua = glm::translate(lua, glm::vec3(-2.0f, 0.0f, 3.0f)); //movimento de mudar de posição da lua[1]
		}
		if (i == 2) {
			lua = glm::translate(lua, glm::vec3(3.0f, 0.0f, 2.0f)); //movimento de mudar de posição da lua[2]

		}
		if (i == 3) {
			lua = glm::translate(lua, glm::vec3(-3.0f, 0.0f, -2.0f)); //movimento de mudar de posição da lua[3]

		}

		moon.setModel(lua); //passa o model para o vertex.vs
		moon.draw(width, height, cameraPos, cameraFront, cameraUp);  // desenha o circulo das luas
	}

	moon.closeBind();

}


void newMoon::clear() { //Limpa o objeto da classe Circulo, da moon
	moon.clear();
}

