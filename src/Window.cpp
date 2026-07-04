#include <iostream>
#include "Questions.hpp"
#include "Window.hpp"

void Window::Button_Click(){
    question.Make_New();
    label.set_text( question.Get_String() );

    std::cout<<entry.get_text()<<'\n';
}

Window::Window():
    hbox(Gtk::Orientation::HORIZONTAL, 10),
    vbox(Gtk::Orientation::VERTICAL, 10),
    question(150),
    label( question.Get_String() ){

    set_title("Quiz");
    set_default_size(200, 100);
    set_child(vbox);
    vbox.set_margin(10);

    hbox.append(label);
    hbox.append(entry);
    vbox.append(hbox);

    Gtk::Button* button = Gtk::make_managed<Gtk::Button>("Next Question");
    vbox.append(*button);
    button->signal_clicked().connect( sigc::mem_fun(*this, &Window::Button_Click) );
}
