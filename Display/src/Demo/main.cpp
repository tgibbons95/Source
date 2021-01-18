#include "Widgets/MainWindow.h"
#include "Widgets/GearWidget.h"



int main(int argc, char* argv[])
{
    ThomasUx::MainWindow window;

    static GLfloat red[4] = { 1.0f, 0.0f, 0.f, 1.f };
    ThomasUx::GearWidget gear1(1.f, 4.f, 1.f, 20, 0.7f, red);
    gear1.SetTranslate(-3.0, -2.0, 0.0);

    static GLfloat green[4] = { 0.f, 0.8f, 0.2f, 1.f };
    ThomasUx::GearWidget gear2(0.5f, 2.f, 2.f, 10, 0.7f, green);
    gear2.SetTranslate(3.1f, -2.f, 0.f);
    gear2.SetAngle(-2.f, -9.f);

    static GLfloat blue[4] = { 0.2f, 0.2f, 1.f, 1.f };
    ThomasUx::GearWidget gear3(1.3f, 2.f, 0.5f, 10, 0.7f, blue);
    gear3.SetTranslate(-2.f, 4.2f, 0.f);
    gear3.SetAngle(-2.f, -25.f);

    window.AddWidget(&gear1);
    window.AddWidget(&gear2);
    window.AddWidget(&gear3);
    window.Run();
}