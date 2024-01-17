#include "upgShrine.h"
upgShrine::upgShrine() : Shrine()
{
	
}
upgShrine::~upgShrine()
{
	AIMesh* upgrade = nullptr;
}

void upgShrine::initUpg(vec3 position)
{
	vec3 pos = position + vec3(0.0f,1.5f, 0.0f);
	init(pos);
	upgrade = new AIMesh(string("Assets\\shrine\\upgrade.obj"));
	
	upgrade->addTexture("Assets\\shrine\\stone.png", FIF_PNG);
}
AIMesh* upgShrine::getUpgrade()
{
	return upgrade;
}
void upgShrine::rend(GLint matrix)
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
	if (upgrade)
	{

		mat4 modelTransform = glm::translate(identity<mat4>(), (shrinePos- vec3(0.0f,0.5f,0.0f))) * glm::scale(identity<mat4>(), shrineScale);

		glUniformMatrix4fv(matrix, 1, GL_FALSE, (GLfloat*)&modelTransform);

		upgrade->preRender();
		upgrade->render();
		upgrade->postRender();
	}

}