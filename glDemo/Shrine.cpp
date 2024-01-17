#include "Shrine.h"
#include "AIMesh.h"

Shrine::Shrine()
{

	
}
Shrine::~Shrine()
{
	AIMesh* pillarMesh = nullptr;
	AIMesh* roofMesh = nullptr;
}
void Shrine::init(vec3 position)
{
	this->shrinePos = position;
	pillarPos[0] = position + vec3(1.5f, 0.0f, 0.0f);
	pillarPos[1] = position + vec3(1.5f, 0.0f, 2.5f);
	pillarPos[2] = position + vec3(1.5f, 0.0f, -2.5f);
	pillarPos[3] = position + vec3(-1.5f, 0.0f, 0.0f);
	pillarPos[4] = position + vec3(-1.5f, 0.0f, 2.5f);
	pillarPos[5] = position + vec3(-1.5f, 0.0f, -2.5f);

	pillarMesh = new AIMesh(string("Assets\\shrine\\column.obj"));
	roofMesh = new AIMesh(string("Assets\\shrine\\roof.obj"));
	pillarMesh->addTexture("Assets\\shrine\\Marble.png", FIF_PNG);
	roofMesh->addTexture("Assets\\shrine\\Marble.png", FIF_PNG);
}

AIMesh* Shrine::getPillar()
{
	return pillarMesh;
}
AIMesh* Shrine::getRoof()
{
	return roofMesh;
}
vec3 Shrine::getPos()
{
	return shrinePos;
}
vec3 Shrine::getScale()
{
	return shrineScale;
}
void Shrine::rend(GLint matrix)
{
	if (pillarMesh) {
		for (int i = 0; i < 6; i++)
		{

			mat4 modelTransform = glm::translate(identity<mat4>(), pillarPos[i]) * glm::scale(identity<mat4>(), shrineScale);

			glUniformMatrix4fv(matrix, 1, GL_FALSE, (GLfloat*)&modelTransform);

			pillarMesh->preRender();
			pillarMesh->render();
			pillarMesh->postRender();
		}
	}
	if (roofMesh)
	{

		mat4 modelTransform = glm::translate(identity<mat4>(), shrinePos) * glm::scale(identity<mat4>(), shrineScale);

		glUniformMatrix4fv(matrix, 1, GL_FALSE, (GLfloat*)&modelTransform);

		roofMesh->preRender();
		roofMesh->render();
		roofMesh->postRender();
	}
}
