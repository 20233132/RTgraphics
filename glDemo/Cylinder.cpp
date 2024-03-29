
#include "Cylinder.h"
#include "TextureLoader.h"
#include "shader_setup.h"

using namespace std;
using namespace glm;


Cylinder::Cylinder(std::string filename, GLuint meshIndex) : AIMesh(filename, meshIndex) {

	// Load textures

	wave2Texture = loadTexture("Assets\\shrine\\white.png", FIF_PNG);

	// Load shader
	shader = setupShaders(string("Assets\\cylinder\\cylinder.vert"), string("Assets\\cylinder\\cylinder.frag"));

	// Get uniform locations
	shader_mvpMatrix = glGetUniformLocation(shader, "mvpMatrix");

	shader_wave2Texture = glGetUniformLocation(shader, "wave2Texture");


	// Set uniform values that will not change (ie. texture sampler values)
	glUseProgram(shader);
	
	glUniform1i(shader_wave2Texture, 2);
	glUseProgram(0); // restore default
}

// Override pre and post render to use wave textures unique to cylinder

void Cylinder::preRender() {

	AIMesh::preRender(); // will not bind texture since inherited texture = 0

	// Now bind wave textures
	

	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, wave2Texture);

	// restore default
	glActiveTexture(GL_TEXTURE0);

}

void Cylinder::render(mat4 transform) {

	// Handle cylinder effects internally so setup shader here
	transform = transform * glm::scale(identity<mat4>(), vec3(0.05f,0.05f,0.05f));
	glUseProgram(shader);
	glUniformMatrix4fv(shader_mvpMatrix, 1, GL_FALSE, (GLfloat*)&transform);
	//glUniform1f(shader_wave1Phase, cosf(glm::radians<float>(wavePhase)));
	//glUniform1f(shader_wave2Phase, sinf(glm::radians<float>(wavePhase)));

	AIMesh::render();
}

void Cylinder::postRender() {

	AIMesh::postRender();
}


void Cylinder::update() {

	
}

