#include "Shrine.h"

Shrine::Shrine(vec3 position)
{
	shrinePos = position;
	pillarPos[0] = position + vec3(1.5f, 0.0f, 0.0f);
	pillarPos[1] = position + vec3(1.5f, 0.0f, 2.5f);
	pillarPos[2] = position + vec3(1.5f, 0.0f, -2.5f);
	pillarPos[3] = position + vec3(-1.5f, 0.0f, 0.0f);
	pillarPos[4] = position + vec3(-1.5f, 0.0f, 2.5f);
	pillarPos[5] = position + vec3(-1.5f, 0.0f, -2.5f);
	
}
Shrine::~Shrine()
{
	AIMesh* pillarMesh = nullptr;
	AIMesh* roofMesh = nullptr;
}
void Shrine::init()
{
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
