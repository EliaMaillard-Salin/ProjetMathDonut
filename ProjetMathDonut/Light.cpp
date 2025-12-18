#include "Light.h"

#include "Settings.h"
#include <cmath>


Light::Light(): lx(0.0f), ly(0.0f), lz(0.0f), m_normalizedLight()
{}

Light::Light(Settings const& setting) : lx(0.0f), ly(0.0f), lz(0.0f), m_normalizedLight()
{
	lx = setting.GetLightX();
	ly = setting.GetLightY();
	lz = setting.GetLightZ();
	float normDir = std::sqrt(lx * lx + ly * ly + lz * lz);
	if (normDir != 0.0f)
	{
		m_normalizedLight.x = lx;
		m_normalizedLight.y = ly;
		m_normalizedLight.z = lz;

		m_normalizedLight.nx = lx / normDir;
		m_normalizedLight.ny = ly / normDir;
		m_normalizedLight.nz = lz / normDir;
	}
}

Mesh::Vertex Light::GetNormalizedLight() const
{
	return m_normalizedLight;
}
