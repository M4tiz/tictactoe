#include "logger.h"
#include "version.h"
#include "game_runner.h"
#include "iostream"
#include "gui/gui_game_handler.h"
#include <gtkmm-3.0/gtkmm/application.h>

int main(int argc, char *argv[]) {
    auto app = Gtk::Application::create(argc, argv, "org.gtkmm.matizaurus");
    GuiGameHandler handler;
    // try {
    //     ConsoleGameRunner(std::cin, std::cout).start();
    // } catch (const std::exception& ex) {
    //     ex.what();
    // }

    return app -> run(handler);
}
