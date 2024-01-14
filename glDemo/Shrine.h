#pragma once
#include "core.h"
#include "AIMesh.h"

using namespace std;
using namespace glm;

class Shrine
{
private:
	vec3 shrinePos = vec3(0.0f, 0.0f, 0.0f);
	vec3 shrineScale = vec3(0.05f, 0.05f, 0.05f);
	
	AIMesh* pillarMesh = nullptr;
	AIMesh* roofMesh = nullptr;
	
public:
	vec3 pillarPos[6];

	Shrine(vec3 position);
	~Shrine();
	void init();
	AIMesh* getPillar();
	AIMesh* getRoof();
	vec3 getPos();
	vec3 getScale();
};

