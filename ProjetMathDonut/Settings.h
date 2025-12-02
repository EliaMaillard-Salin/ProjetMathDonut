#pragma once

#include "Mesh.h"

class Settings
{
	int m_width;
	int m_height;
	char m_screenBackground;
	float m_zScreenPosition;
	char m_screenMeshProjection;
	int m_meshResolution;
	float m_zMeshPosition;

public:
	Mesh currentMesh;

	Settings();
	
	bool HandleSettings(int argC, char** argV);
	
	void GenerateCircle(float radius);
	void GenerateHalfCircle(float radius);
	void GenerateSquare(float size);
	void GenerateRectangle(float width, float height);
	char GetScreenBackground() const { return m_screenBackground; }
	float GetScreenPosition() const { return m_zScreenPosition; }
	char GetScreenMeshProjection() const { return m_screenMeshProjection; }
	int GetMeshResolution() const { return m_meshResolution; }
	float GetMeshPosition() const { return m_zMeshPosition; }
	int GetHeight();
	int GetWidth();

};

