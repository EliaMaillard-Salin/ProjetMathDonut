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
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    Settings settings = Settings(argc, argv);
    Screen screen = Screen(settings.GetWidth(), settings.GetHeight());
    //Screen screen = Screen(100, 100);

    Mesh mesh = Mesh(settings.GetRadius());

    //while (true)
    //{
        screen.Draw(mesh);
        //mesh.Debug();
//    }

    return 0;
}
