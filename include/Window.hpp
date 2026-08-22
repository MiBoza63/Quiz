#ifndef Window_hpp
#define Window_hpp

#include <gtkmm.h>
#include "Questions.hpp"

class Window : public Gtk::Window{
public:
    Window();

protected:
    short score;
    Question question;

    // Child widgets:
    Gtk::Box hbox, vbox;
    Gtk::Label question_label, score_label;
    Gtk::Entry entry;

    void Button_Click();
    ~Window();
};

#endif // Window_hpp
