#include "widgets.hpp"
#include "graphics.hpp"
using namespace genv;

Widget::Widget(int x, int y, int sx, int sy) : _x(x), _y(y), _size_x(sx), _size_y(sy)
{
}

bool Widget::is_selected(int mouse_x, int mouse_y)
{
    g=(mouse_y-(_y+_size_x))/_size_y;
    t=(mouse_x-(_x+_size_x))/_size_x;

       return mouse_x>_x+t*_size_x+_size_x && mouse_x < _x+t*_size_x+2*_size_x && mouse_y >_y+g*_size_y+_size_y && mouse_y < _y+g*_size_y+2*_size_y;
}






