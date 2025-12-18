#pragma once

#include "Mesh.h"

class Settings;

struct Light
{
private:
	Mesh::Vertex m_normalizedLight;
public:
	float lx;
	float ly;
	float lz;


	Light();
	Light(Settings const& setting);
	Mesh::Vertex GetNormalizedLight() const;
};

