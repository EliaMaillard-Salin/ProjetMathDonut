#include "Mesh.h"

#include <iostream>
#include <cmath>

#include "Light.h"

#define PI 3.14159


Mesh::Mesh(std::vector<Vertex> vertices) : m_vertices(vertices)
{}

Mesh::Mesh(int _resolution): m_vertices(std::vector<Vertex>(_resolution* _resolution)), m_resolution(_resolution)
{
}

Mesh& Mesh::CreateSector(float radius, float angle)
{
    m_vertices = std::vector<Mesh::Vertex>(m_resolution * m_resolution);
    for (int i = 0; i < m_resolution; i++)
    {
        float r = (radius * i) / (m_resolution - 1);
        for (int j = 0; j < m_resolution; j++)
        {
            float theta = (angle * j) / (m_resolution - 1);
            m_vertices[m_resolution * i + j].x = radius * std::cos(theta);
            m_vertices[m_resolution * i + j].y = radius * std::sin(theta);
            m_vertices[m_resolution * i + j].z = 0.f;
            m_vertices[m_resolution * i + j].nx = std::cos(theta);
            m_vertices[m_resolution * i + j].ny = std::sin(theta);
            m_vertices[m_resolution * i + j].nz = 0;
        }
    }
    return *this;
}

Mesh& Mesh::CreateRect(float width, float height)
{
    m_vertices.resize(m_resolution * m_resolution);
    for (int i = 0; i < m_resolution; i++)
    {
        for (int j = 0; j < m_resolution; j++)
        {
            m_vertices[m_resolution * i + j].x = (1.f * i / (m_resolution - 1) - 0.5f) * width;
            m_vertices[m_resolution * i + j].y = (1.f * j / (m_resolution - 1) - 0.5f) * height;
            m_vertices[m_resolution * i + j].z = 0.f;
        }
    }
    return *this;
}


Mesh Mesh::CreateCircle(float radius, int resolution)
{
    Mesh mesh = Mesh(resolution);
    return mesh.CreateSector(radius, 2 * PI);
}

Mesh Mesh::CreateHalfCircle(float radius, int resolution)
{
    Mesh mesh = Mesh(resolution);
    return mesh.CreateSector(radius, PI);
}

Mesh Mesh::CreateSquare(float size, int resolution)
{
    Mesh mesh = Mesh(resolution);
    return mesh.CreateRect(size,size);
}

Mesh Mesh::CreateRectangle(float width, float height, int resolution)
{
    Mesh mesh = Mesh(resolution);
    return mesh.CreateRect(width,height);
}

Mesh Mesh::CreateTorus(float majorRadius, float minorRadius, int resolution)
{
    Mesh mesh = Mesh(resolution);
    mesh.m_vertices.resize(resolution * resolution);

    for (int i = 0; i < resolution; i++)
    {
        float angleY = (2 * PI * i) / (resolution);
        for (int j = 0; j < resolution; j++)
        {
            float theta = (2*PI * j) / (resolution);
            mesh.m_vertices[resolution * i + j].x = majorRadius + minorRadius * std::cos(theta);
            mesh.m_vertices[resolution * i + j].y = minorRadius * std::sin(theta);
            mesh.m_vertices[resolution * i + j].Rotate(angleY, Axis::Y);
            mesh.m_vertices[resolution * i + j].nx = std::cos(theta);
            mesh.m_vertices[resolution * i + j].ny = std::sin(theta);
            mesh.m_vertices[resolution * i + j].nz = 0;
        }
    }

    return mesh;
}

std::vector<Mesh::Vertex> Mesh::GetVertices()
{
    return m_vertices;
}

Mesh Mesh::DefaultMesh()
{
    Mesh mesh = Mesh({{1.0f,-1.0f,0.0f}});
    return mesh;
}


void Mesh::Debug()
{
    std::cout << "Vertices : \n";

    for (int i = 0; i < m_vertices.size(); i++)
    {
        std::cout << "Coords : {X: " << std::round(m_vertices[i].x) << ";Y: " << std::round(m_vertices[i].y) << ";Z: " << std::round(m_vertices[i].z) << "}";
        std::cout << "\t Normals : {NX : " << m_vertices[i].nx << "; NY : "<< m_vertices[i].ny << "; NZ : " << m_vertices[i].nz << "}" << std::endl;
    }
}

void Mesh::Rotate(float angle, Axis axis)
{
    for (int i = 0; i < m_vertices.size(); i++)
    {
        m_vertices[i].Rotate(angle, axis);
    }
}

void Mesh::Vertex::Rotate(float angle, Axis axis)
{
    Vertex previous = *this;
    switch (axis)
    {
    case Axis::X:
    {
        y = previous.y * std::cos(angle) - previous.z * std::sin(angle);
        z = previous.y * std::sin(angle) + previous.z * std::cos(angle);
    }
    break;
    case Axis::Y:
    {
        x = previous.x * std::cos(angle) + previous.z * std::sin(angle);
        z = -previous.x * std::sin(angle) + previous.z * std::cos(angle);
    }
        break;
    case Axis::Z:
    {
        x = previous.x * std::cos(angle) - previous.y * std::sin(angle);
        y = previous.x * std::sin(angle) + previous.y * std::cos(angle);
    }
        break;
    default:
        break;
    }
}

float Mesh::Vertex::ComputeIllumination(Light const& light) const
{
    return nx * light.GetNormalizedLight().nx + ny * light.GetNormalizedLight().ny + nz * light.GetNormalizedLight().nz;
}
