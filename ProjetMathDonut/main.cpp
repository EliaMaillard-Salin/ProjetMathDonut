#include <iostream>

#include "Settings.h"
#include "Screen.h"
#include "Mesh.h"

#include <Windows.h>

#define PI 3.14159

// Clear : [2J
// SetCursor 0,0 : [H
// Cursor Invisible : [?25l
// Cursor Visible : [?25h

// ANSI Command : https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797


int main(int argc, char** argv)
{

    Settings settings = Settings();
    if (settings.HandleSettings(argc, argv) == false)
        return 0;
    //Screen screen = Screen(settings);

    Screen screen = Screen(75, 25, 'X', ' ');
    Mesh donut = Mesh::CreateTorus(15, 5,70);
    donut.SetPosition(0.0f, 5.0f, 0.0f);
    //Mesh SecondCircle = Mesh::CreateCircle(10, 30);

    //FirstCircle.SetPosition(-12.5f, 0.0f, 0.0f);
    //SecondCircle.SetPosition(12.5f, 0.0f, 0.0f);

    //screen.Draw(SecondCircle);
    while (true)
    {
        screen.ResetScreen();
        screen.Draw(donut);
        screen.Display();

        donut.Rotate(0.08f, Axis::X);
        //donut.Rotate(0.02f, Axis::Y);
    }

    return 0;
}
