#include <Application.hpp>
#include <Vector2D.hpp>
#include <iostream>

int main(void) {
    // Application app;
    // app.Initialize();
    // app.Run();
    // app.Shutdown();

    Vector2D a(3, 4);
    Vector2D b(4, 5);
    a += 2.0f;
    a += b;
    std::cout << std::string(a);

    a.Normalize();
    std::cout << std::string(a);

    return 0;
}