#include "Questions.hpp"
#include "Window.hpp"

void Window::Button_Click(){
    question.Make_New();
    label.set_text( question.Get_String() );
}

Window::Window():
    m_VBox(Gtk::Orientation::VERTICAL, 10),
    question(150),
    label( question.Get_String() ){
    set_title("Quiz");
    set_default_size(200, 150);
    set_child(m_VBox);
    m_VBox.set_margin(10);

    m_VBox.append(label);

    Gtk::Button* button = Gtk::make_managed<Gtk::Button>("Next Question");
    m_VBox.append(*button);
    button->signal_clicked().connect( sigc::mem_fun(*this, &Window::Button_Click) );
}
