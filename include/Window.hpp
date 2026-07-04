#ifndef Window_hpp
#define Window_hpp

#include <gtkmm.h>
#include "Questions.hpp"

class Window : public Gtk::Window{
public:
    Window();

protected:
    short score = 0;
    Question question;

    // Child widgets:
    Gtk::Box hbox, vbox;
    Gtk::Label question_label, score_label;
    Gtk::Entry entry;

    void Button_Click();
};

#endif // Window_hpp
