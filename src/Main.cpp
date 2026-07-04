#include "Window.hpp"

int main(int argc, char *argv[]){
    using Application = Glib::RefPtr<Gtk::Application>;
    Application app = Gtk::Application::create("org.gtkmm.examples.base");

    // Shows the window and returns when it is closed.
    return app->make_window_and_run<Window>(argc, argv);
    
    return 0;
}
