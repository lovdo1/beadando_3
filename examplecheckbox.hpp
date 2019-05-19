#ifndef EXAMPLECHECKBOX_HPP_INCLUDED
#define EXAMPLECHECKBOX_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <cmath>

class ExampleCheckBox : public Widget {
protected:
    bool _checked, che, akar, katt, kattint;
    int a=0;
    int q,w,e,r;

    const double pi = 3.1415926;
public:
    ExampleCheckBox(int x, int y, int sx, int sy);
    virtual void rajzol() ;
    virtual void handle(genv::event ev);
    virtual bool is_checked() ;
};


#endif // EXAMPLECHECKBOX_HPP_INCLUDED
