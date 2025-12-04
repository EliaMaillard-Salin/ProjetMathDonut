#include "Screen.h"
#include <iostream>
#include <string>



Screen::Screen(Settings& settings) :
    m_width(settings.GetWidth()), m_height(settings.GetHeight()),
    m_centerX(m_width * 0.5f), m_centerY(m_height * 0.5f),
    m_zPosition(settings.GetScreenPosition()), m_meshZPosition(settings.GetMeshPosition()),
    m_background(settings.GetScreenBackground()), m_meshProjection(settings.GetScreenMeshProjection()),
    m_pixels(m_height, std::vector<char>(m_width, m_background)), m_oozBuffer(m_height, std::vector<float>(m_width, 0.0f))
{}

Screen::Screen(int width, int height, char meshProjection, char screenProjection) :
    m_width(width), m_height(height),
    m_centerX(m_width * 0.5f), m_centerY(m_height * 0.5f),
    m_zPosition(0.0f), m_meshZPosition(0.0f),
    m_background(screenProjection), m_meshProjection(meshProjection),
    m_pixels(m_height, std::vector<char>(m_width, m_background)), m_oozBuffer(m_height, std::vector<float>(m_width, 0.0f))
{}

void Screen::ResetScreen()
{
    for (int h = 0; h < m_height; h++)
    {
        std::fill(m_pixels[h].begin(), m_pixels[h].end(), m_background);
        std::fill(m_oozBuffer[h].begin(), m_oozBuffer[h].end(), -1.f);
    }

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
            std::cout << m_pixels[h][w];
        }
        std::cout << ".\n";
    }

    std::cout << "\033[?25h";

}

void Screen::Draw(Mesh& mesh)
{
    for (Mesh::Vertex vertice : mesh.m_vertices)
    {
        //_ProjectInCenterScreenSpace(&vertice);
        //_ProjectInTopLeftScreenSpace(&vertice);
        //int u = std::round(vertice.x);
        //int v = std::round(vertice.y);
        //float ooz = 1.0f / vertice.z;

        int u  = std::round(m_centerX + vertice.x + mesh.GetPosX());
        int v = std::round((m_centerY + vertice.y) * 0.5f + mesh.GetPosY());
        float z = vertice.z + mesh.GetPosZ();

        if (_IsVertexInScreen(u, v) && z > m_oozBuffer[v][u])
        {
            m_oozBuffer[v][u] = z;
            m_pixels[v][u] = m_meshProjection;
        }
    }
}

void Screen::_ProjectInCenterScreenSpace(Mesh::Vertex* vertex)
{
    vertex->z += m_meshZPosition;
    vertex->x = m_zPosition * vertex->x / vertex->z;
    vertex->y = m_zPosition * vertex->y / vertex->z / 2.f;
}

void Screen::_ProjectInTopLeftScreenSpace(Mesh::Vertex* vertex)
{
    vertex->x += m_width / 2;
    vertex->y += m_height / 2;
}

bool Screen::_IsVertexInScreen(int u, int v)
{
    return u >= 0 && u < m_width && v >= 0 && v < m_height;
}