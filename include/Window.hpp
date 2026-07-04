#ifndef Window_hpp
#define Window_hpp

#include <gtkmm.h>
#include "Questions.hpp"

class Window : public Gtk::Window{
public:
    Window();

protected:
    Question question;

    // Child widgets:
    Gtk::Box hbox, vbox;
    Gtk::Label label;
    Gtk::Entry entry;

    void Button_Click();
};

#endif // Window_hpp
