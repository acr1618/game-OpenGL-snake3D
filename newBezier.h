#ifndef BEZIER
#define BEZIER

#include "Shader.hh"
#include "glm/glm.hpp"
#include <vector>

class newBezier
{
private:
	unsigned int VBO, VAO;
	unsigned int texture;
	Shader myShader;

public:
	newBezier();
	~newBezier();

	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 projection;

	std::vector<float> vertices2;

	void bind();
	void draw(unsigned int width, unsigned int height, glm::vec3 cameraPos, glm::vec3 cameraFront, glm::vec3 cameraUp);
	glm::vec4 toBezier(float delta, int i, glm::vec4 P0, glm::vec4 P1, glm::vec4 P2, glm::vec4 P3);
	void clear();
	void closeBind();
	void createBezier();

private:
	void bindVertex();
	

};
#endif
