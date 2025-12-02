#include "Screen.h"
#include <iostream>
#include <string>


Screen::Screen(Settings& settings) :
    m_width(settings.GetWidth()), m_height(settings.GetHeight()), 
    m_zPosition(settings.GetScreenPosition()), m_meshZPosition(settings.GetMeshPosition()),
    m_background(settings.GetScreenBackground()), m_meshProjection(settings.GetScreenMeshProjection()),
    m_pixels(m_width* m_height, '.'), m_oozBuffer(m_width* m_height, 0.f)
{
    m_pixels = std::vector<char>(m_width * m_height, '.');
}

void Screen::Display()
{
    std::cout << "\033[?25l";
    std::cout << "\033[2J";
    std::cout << "\033[H";

    for (int h = 0; h < m_height; h++)
    {
        for (int w = 0; w < m_width; w++)
        {
            std::cout << m_pixels[m_width * h + w];
        }
        std::cout << ".\n";
    }

    std::cout << "\033[?25h";

}

void Screen::Draw(Mesh& mesh)
{
    std::fill(m_pixels.begin(), m_pixels.end(), m_background);
    std::fill(m_oozBuffer.begin(), m_oozBuffer.end(), 0.f);

    for (Mesh::Vertex vertice : mesh.m_vertices)
    {
        _ProjectInCenterScreenSpace(vertice);
        _ProjectInTopLeftScreenSpace(vertice);
        int u = std::round(vertice.x);
        int v = std::round(vertice.y);
        float ooz = 1.0f / vertice.z;
        if (_IsVertexInScreen(u, v) && ooz > m_oozBuffer[v * m_width + u])
        {
            m_oozBuffer[v * m_width + u] = ooz;
            m_pixels[v * m_width + u] = m_meshProjection;
        }
    }
}

void Screen::_ProjectInCenterScreenSpace(Mesh::Vertex& vertex)
{
    vertex.z += m_meshZPosition;
    vertex.x = m_zPosition * vertex.x / vertex.z;
    vertex.y = m_zPosition * vertex.y / vertex.z / 2.f;
}

void Screen::_ProjectInTopLeftScreenSpace(Mesh::Vertex& vertex)
{
    vertex.x += m_width / 2;
    vertex.y += m_height / 2;
}

bool Screen::_IsVertexInScreen(int u, int v)
{
    return u >= 0 && u < m_width && v >= 0 && v < m_height;
}