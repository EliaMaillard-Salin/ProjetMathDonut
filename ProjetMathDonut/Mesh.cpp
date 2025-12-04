#include "Mesh.h"

#include <iostream>
#include <cmath>

#define PI 3.14159


Mesh::Mesh(std::vector<Vertex> vertices) : m_vertices(vertices)
{}

Mesh::Mesh(int _resolution): m_vertices(std::vector<Vertex>(_resolution* _resolution)), m_resolution(_resolution)
{
}

std::vector<Mesh::Vertex>& Mesh::CreateSector(float radius, float angle)
{
    std::vector<Mesh::Vertex> resVertices = std::vector<Mesh::Vertex>(m_resolution * m_resolution);
    for (int i = 0; i < m_resolution; i++)
    {
        float r = (radius * i) / (m_resolution - 1);
        for (int j = 0; j < m_resolution; j++)
        {
            float theta = (angle * j) / (m_resolution - 1);
            resVertices[m_resolution * i + j].x = radius * std::cos(theta);
            resVertices[m_resolution * i + j].y = radius * std::sin(theta);
            resVertices[m_resolution * i + j].z = 0.f;
        }
    }
    return resVertices;
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
    mesh.m_vertices = mesh.CreateSector(radius, 2 * PI);
    return mesh;
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

Mesh Mesh::CreateDonut(float r1, float r2, int resolution)
{
    return Mesh::DefaultMesh();
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
        std::cout << "X : " << m_vertices[i].x << "; Y : "<< m_vertices[i].y << "; Z : " << m_vertices[i].z << std::endl;
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
