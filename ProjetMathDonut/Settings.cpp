#include "Settings.h"

#include <iostream>

#include <Windows.h>

Settings::Settings() : m_width(0), m_height(0), currentMesh(Mesh::DefaultMesh()),resolution(15)
{}

bool Settings::HandleSettings(int argC, char** argV)
{
    for (int i = 1; i + 1 < argC; i++)
    {
        if (std::string(argV[i]) == "-w")
        {
            m_width = std::atoi(argV[i + 1]);
            ++i;
        }
        if (std::string(argV[i]) == "-h")
        {
            m_height = std::atoi(argV[i + 1]);
            ++i;
        }
        if (std::string(argV[i]) == "-res")
        {
            resolution = std::atoi(argV[i + 1]);
            ++i;
        }

        if (std::string(argV[i]) == "--C")
        {
            if (i + 2 >= argC)
                continue;
            if (std::string(argV[i + 1]) == "-r")
            {
                GenerateCircle(std::atof(argV[i + 2]));
                i += 2;
            }
        }

        if (std::string(argV[i]) == "--HC")
        {
            if (i + 2 >= argC)
                continue;
            if (std::string(argV[i + 1]) == "-r")
            {
                GenerateHalfCircle(std::atof(argV[i + 2]));
                i += 2;
            }
        }

        if (std::string(argV[i]) == "--R")
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

        if (std::string(argV[i]) == "--S")
        {
            if (i + 2 >= argC)
                continue;
            if (std::string(argV[i + 1]) == "-s")
            {
                GenerateSquare(std::atof(argV[i + 2]));
                i += 2;
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
    currentMesh = Mesh::CreateCircle(radius,resolution);
}

void Settings::GenerateHalfCircle(float radius)
{
    currentMesh = Mesh::CreateHalfCircle(radius,resolution);
}

void Settings::GenerateSquare(float size)
{
    currentMesh = Mesh::CreateSquare(size, resolution);
}

void Settings::GenerateRectangle(float width, float height)
{
    currentMesh = Mesh::CreateRectangle(width,height, resolution);
}

int Settings::GetHeight()
{
	return m_height;
}

int Settings::GetWidth()
{
	return m_width;
}
