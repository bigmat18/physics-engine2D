#include <Application.hpp>

int main(void) {
    Application app;
    app.Initialize();
    app.Run();
    app.Shutdown();

    return 0;
}