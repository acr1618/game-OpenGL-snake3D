#include "newRandom.h"
#include "newTabuleiro.h"
#include "newCube.h"
#include "newCircle.h"
#include "newArvore.h"
#include "newComida.h"
#include "newSun.h"
#include "newCloud.h"
#include "newMoon.h"

class Mundo
{
private:

	float option;  //gera uma posicão diferente do pikachu, cada vez que o tabuleiro é inicalizado.
	float option2;
	float option3;
	float option4;

	newTabuleiro tabuleiro;	 //declara os obejtos de cada classe
	newArvore arvore;
	newComida food;
	newRandom type;
	newSun sun;
	newMoon moon;
	newCloud nuvem;

public:

	Mundo(); //construtor
	~Mundo(); //desconstrutor

	void createMundo(); //cria os objetos no mundo.

	void Draw(unsigned int width, unsigned int height, glm::vec3 cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp);	//desenha os objetos no mundo.

	void clear(); //Limpa os objetos do mundo.

};

