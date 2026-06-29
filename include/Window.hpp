#ifndef Window_hpp
#define Window_hpp

#include <gtkmm.h>

class Window : public Gtk::Window{
public:
    Window();

protected:
    // Child widgets:
    Gtk::Box m_VBox;
};

#endif // Window_hpp
