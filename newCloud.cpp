#include "newCloud.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Shader.hh"


newCloud::newCloud() { //construtor

}

newCloud::~newCloud() { //desconstrutor
	clear();
}

void newCloud::createCloud() { //chama outra função da imagem
	Imgs();
}

void newCloud::Imgs() {  //importa a imagem
	nuvem.setTexture("nuv.jpg");
}


void newCloud::Draw(unsigned int width, unsigned int height, glm::vec3 cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp) {   //desenha a nuvem

	glm::vec3 nuvens[] = {  //posição das nuvens

		glm::vec3(5.0f,  2.40f,  2.4f),
		glm::vec3(5.3f,  2.45f,  2.0f),
		glm::vec3(5.0f,  2.40f,  4.8f),
		glm::vec3(5.0f,  2.40f,  3.6f),
		glm::vec3(4.7f,  2.35f,  4.0f),
		glm::vec3(5.3f,  2.45f,  3.6f),
		glm::vec3(5.6f,  2.45f,  2.6f)

	};

	nuvem.bind();  //textura das nuvens

	count = count + 0.4f;
	for (int x = 0; x < 7; x++) {
		nuv = glm::mat4(1.0f);
		nuv = glm::translate(nuv, nuvens[x]);

		if (x == 0 || x == 2) {
			nuv = glm::scale(nuv, glm::vec3(0.3f, 0.4f, 0.8f));        //faz a escala das nuvens
			nuv = glm::rotate(nuv, glm::radians(count), glm::vec3(0.0, 0.0, 0.5));  //faz a rotação das nuvens
		}else{
			nuv = glm::scale(nuv, glm::vec3(0.3f, 0.4f, 1.6f));        //faz a escala das nuvens
			nuv = glm::rotate(nuv, glm::radians(count), glm::vec3(0.0, 0.0, 0.5)); //faz a rotação das nuvens
		}

		nuvem.setModel(nuv);  //passa o model para o vertex.vs
		nuvem.draw(width, height, cameraPos, cameraFront, cameraUp);  // desenha o cubo das nuvens
	};
	nuvem.closeBind();


}


void newCloud::clear() { //Limpa o objeto da classe cubo, da nuvem
	nuvem.clear();
}