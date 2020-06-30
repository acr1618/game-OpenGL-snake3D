#ifndef MOON 
#define MOON 

#include "glm/glm.hpp"
#include "newCircle.h"

class newMoon
{
private:
		newCircle moon; //declara o obejto da classe Circulo

		glm::mat4 lua; //declara o mat4 para fazer as transformações e passar para o model
		float count = 5.0f;  // variavel para fazer a rotate da lua

public:

		newMoon(); //construtor
		~newMoon(); //desconstrutor

		void createMoon();  //chama outra função da imagem da lua

		void Imgs(); //importa a imagem da lua

		void Draw(unsigned int width, unsigned int height, glm::vec3 cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp);  //desenha a lua

		void clear(); //Limpa o objeto da classe Circulo, da moon

};
#endif
