#include <iostream>

#include "Settings.h"
#include "Screen.h"
#include "Mesh.h"

#include <Windows.h>

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

    Screen screen = Screen(75, 25, 'X', '.');
    Mesh FirstCircle = Mesh::CreateCircle(10, 30);
    Mesh SecondCircle = Mesh::CreateCircle(10, 30);

    FirstCircle.SetPosition(-12.5f, 0.0f, 0.0f);
    SecondCircle.SetPosition(12.5f, 0.0f, 0.0f);

    screen.ResetScreen();
    screen.Draw(FirstCircle);
    screen.Draw(SecondCircle);
    screen.Display();
    while (true)
    {
    }

    return 0;
}
