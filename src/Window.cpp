#include "Window.hpp"
#include <iostream>

void Say_Hi(){
    std::cout<<"Hi.\n";
}

Window::Window():
    m_VBox(Gtk::Orientation::VERTICAL, 10){
    set_title("Quiz");
    set_default_size(200, 200);
    set_child(m_VBox);
    m_VBox.set_margin(10);

    Gtk::Button* button = Gtk::make_managed<Gtk::Button>("label");
    m_VBox.append(*button);
    button->signal_clicked().connect( sigc::ptr_fun(&Say_Hi) );
}
