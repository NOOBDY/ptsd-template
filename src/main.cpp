#include "App.hpp"

#include "Core/Context.hpp"

int main(int, char**) {
    auto ctx = Core::Context::GetInstance();
    App app;

    while (!ctx->GetExit()) {
        ctx->Update();
        switch (app.GetCurrentState()) {
            case App::State::START:
                app.Start();
                break;

            case App::State::UPDATE:
                app.Update();
                break;

            case App::State::END:
                app.End();
                ctx->SetExit(true);
                break;
        }
    }
    return 0;
}
