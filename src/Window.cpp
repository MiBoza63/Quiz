#include "Questions.hpp"
#include "Window.hpp"
using std::stoi;
using std::to_string;

void Window::Button_Click(){
    ushort guess = stoi( entry.get_text() );
    if( question.Check(guess) )
        score++;
    else
        score *= 0.9;

    score_label.set_text("Score: " + to_string(score) );
    entry.set_text("");

    question.Make_New();
    question_label.set_text( question.Get_String() );
}

Window::Window():
    hbox(Gtk::Orientation::HORIZONTAL, 10),
    vbox(Gtk::Orientation::VERTICAL, 10),
    question(100),
    question_label( question.Get_String() ){

    set_title("Quiz");
    set_default_size(200, 120);
    set_child(vbox);
    vbox.set_margin(10);

    score = Read_Score();
    score_label.set_text("Score: " + to_string(score) );

    hbox.append(question_label);
    hbox.append(entry);
    vbox.append(hbox);
    vbox.append(score_label);

    Gtk::Button* button = Gtk::make_managed<Gtk::Button>("Check");
    vbox.append(*button);
    button->signal_clicked().connect( sigc::mem_fun(*this, &Window::Button_Click) );
}

Window::~Window(){
    Save_Score(score);
}
