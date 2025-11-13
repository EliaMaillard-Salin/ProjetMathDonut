#include "Settings.h"

#include <iostream>

#include <Windows.h>

Settings::Settings(int argC, char** argV) : m_width(0), m_height(0), currentMesh(Mesh::DefaultMesh())
{
    for (int i = 1; i + 1 < argC; i++)
    {
        if (std::string(argV[i]) == "-w")
            m_width = std::atoi(argV[i + 1]);
        if (std::string(argV[i]) == "-h")
            m_height = std::atoi(argV[i + 1]);

        if (std::string(argV[i]) == "-c")
        {
            if (i + 2 >= argC)
                continue;
            if (std::string(argV[i+1]) == "-r")
                GenerateCircle(std::atof(argV[i + 2]));
        }

        //if (std::string(argV[i]) == "-hc")
        //    radius = std::atof(argV[i + 1]);

        //if (std::string(argV[i]) == "-r")
        //    radius = std::atof(argV[i + 1]);

        //if (std::string(argV[i]) == "-s")
        //    radius = std::atof(argV[i + 1]);
    }

    if (m_width == 0 || m_height == 0)
        std::cout << "Error with Width or Height Value \n";

}

void Settings::GenerateCircle(float radius)
{
    currentMesh = Mesh::CreateCircle(radius);
}

void Settings::GenerateHalfCircle(float radius)
{
}

void Settings::GenerateSquare(float radius)
{
}

void Settings::GenerateRectangle(float radius)
{
}

int Settings::GetHeight()
{
	return m_height;
}

int Settings::GetWidth()
{
	return m_width;
}
