#include "mcdu_elements.h"

Element::Element()
{
    text = "DEFAULT ELEMENT";
    row = 0;
    offset = 0;
    color = 0;
}

Element::Element(std::string text_, int row_, int offset_, int color_)
{
    text = text_;
    row = row_;
    offset = offset_;
    color = color_;
}

Element::~Element()
{

}

//For rendering to a display. Sets reference vars to those of the specific element
void Element::getElement(std::string &text_, int &row_, int &offset_, int &color_)
{
    text_ = text;
    row_ = row;
    offset_ = offset;
    color_ = color;
}