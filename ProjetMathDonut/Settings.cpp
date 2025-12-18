#include "Settings.h"

#include <iostream>

#include <Windows.h>

Settings::Settings() : 
    m_width(100),m_height(20),
    m_screenBackground(' '), m_screenMeshProjection('X'),
    m_zScreenPosition(3.33f), m_zMeshPosition(5.f),
    m_meshResolution(32), currentMesh(Mesh::DefaultMesh())
{}

bool Settings::HandleSettings(int argC, char** argV)
{
    for (int i = 1; i + 1 < argC; i++)
    {
        std::string arg = std::string(argV[i]);
        if (arg == "-w")
        {
            m_width = std::atoi(argV[i + 1]);
            ++i;
        }
        else if (arg == "-h")
        {
            m_height = std::atoi(argV[i + 1]);
            ++i;
        }
        else if (arg == "-res")
        {
            m_meshResolution = std::atoi(argV[i + 1]);
            ++i;
        }
        else if (arg == "-b")
        {
            m_screenBackground = argV[i + 1][0];
            i++;
        }
        else if (arg == "-p")
        {
            m_screenMeshProjection = argV[i + 1][0];
            i++;
        }
        else if (arg == "-s")
        {
            m_zScreenPosition = std::atof(argV[i + 1]);
            i++;
        }
        else if (arg == "-m")
        {
            m_zMeshPosition = std::atof(argV[i + 1]);
            i++;
        }
        else if (arg == "-lx")
        {
            lightX = std::atof(argV[i + 1]);
            i++;
        }
        else if (arg == "-ly")
        {
            lightY = std::atof(argV[i + 1]);
            i++;
        }
        else if (arg == "-lz")
        {
            lightZ = std::atof(argV[i + 1]);
            i++;
        }

        // Handle MeshType
        else if (std::string(argV[i]) == "--C")
        {
            if (i + 2 >= argC)
                continue;
            if (std::string(argV[i + 1]) == "-r")
            {
                GenerateCircle(std::atof(argV[i + 2]));
                i += 2;
            }
        }

        else if (std::string(argV[i]) == "--HC")
        {
            if (i + 2 >= argC)
                continue;
            if (std::string(argV[i + 1]) == "-r")
            {
                GenerateHalfCircle(std::atof(argV[i + 2]));
                i += 2;
            }
        }

        else if (std::string(argV[i]) == "--R")
        {
            if (i + 2 >= argC)
                continue;
            int width = 0;
            int height = 0;
            if (std::string(argV[i + 1]) == "-rw")
            {
                width = std::atof(argV[i + 2]);
            }

            if (std::string(argV[i + 3]) == "-rh")
            {
                height = std::atof(argV[i + 4]);
            }

            if (width != 0 && height != 0)
            {
                GenerateRectangle(width, height);
                i += 4;
            }
        }

        else if (std::string(argV[i]) == "--S")
        {
            if (i + 2 >= argC)
                continue;
            if (std::string(argV[i + 1]) == "-s")
            {
                GenerateSquare(std::atof(argV[i + 2]));
                i += 2;
            }
        }

        else if (std::string(argV[i]) == "--T")
        {
            if (i + 2 >= argC)
                continue;
            int minorRadius = 0;
            int majorRadius = 0;

            if (std::string(argV[i + 1]) == "-MaR")
            {
                majorRadius = std::atof(argV[i + 2]);
            }

            if (std::string(argV[i + 3]) == "-MiR")
            {
                minorRadius = std::atof(argV[i + 4]);
            }

            if (minorRadius != 0 && majorRadius != 0)
            {
                currentMesh = Mesh::CreateTorus(majorRadius, minorRadius, m_meshResolution);
                i += 4;
            }
        }
    }

    if (m_width == 0 || m_height == 0)
    {
        std::cout << "Error with Width or Height Value \n";
        return false;
    }
    return true;
}

void Settings::GenerateCircle(float radius)
{
    currentMesh = Mesh::CreateCircle(radius,m_meshResolution);
}

void Settings::GenerateHalfCircle(float radius)
{
    currentMesh = Mesh::CreateHalfCircle(radius, m_meshResolution);
}

void Settings::GenerateSquare(float size)
{
    currentMesh = Mesh::CreateSquare(size, m_meshResolution);
}

void Settings::GenerateRectangle(float width, float height)
{
    currentMesh = Mesh::CreateRectangle(width,height, m_meshResolution);
}

int Settings::GetHeight()
{
	return m_height;
}

int Settings::GetWidth()
{
	return m_width;
}
