#pragma once
#include "core.h"
#include "AIMesh.h"

using namespace std;
using namespace glm;

class Shrine
{
protected:
	vec3 shrinePos = vec3(0.0f, 0.0f, 0.0f);
	vec3 shrineScale = vec3(0.05, 0.05f, 0.05f);
	
	AIMesh* pillarMesh = nullptr;
	AIMesh* roofMesh = nullptr;
	
public:
	vec3 pillarPos[6];

	Shrine();
	~Shrine();
	void init(vec3 position);
	AIMesh* getPillar();
	AIMesh* getRoof();
	vec3 getPos();
	vec3 getScale();
	void rend(GLint matrix);
};

