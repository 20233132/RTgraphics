#pragma once
#include "Shrine.h"
class upgShrine : public Shrine
{
private:
	
	AIMesh* upgrade = nullptr;
public:
	upgShrine();
	~upgShrine();
	
	void initUpg(vec3 position);
	AIMesh* getUpgrade();
	void rend(GLint matrix);
};

