#include "box.h"
//#include <iostream>
Box::Box(int id) : Shape(id)
{

}
void Box::get_size(double &height, double &width, double &depth)
{
height = mheight;
width = mwidth;
depth = mdepth;
}

void Box::set_size(double height, double width, double depth)
{
mheight = height;
mwidth = width;
mdepth = depth;
}

//This function should print, to std::cout,
//all of the Shape and Box data : shape type, id, translations, rotations, scales, color, height, width and depth.
QString Box::print()
{
    QString test;
    test.number(mtx);

    QString output{""};
    output.append("Box ID: ").append(mid).append("\n");
    output.append("Translations: ").number(mtx).append(" ").number(mty).append(" ").number(mtz).append("\n");
//    output.append("Rotations: ").append(mrx).append(" ").append(mry).append(" ").append(mrz).append("\n");
//    output.append("Scales: ").append(msx).append(" ").append(msy).append(" ").append(msz).append("\n");
//    output.append("Color: Red: ").append(mred).append(" Green: ").append(mgreeen).append(" Blue: ").append(mblue);
//    output.append("Height: ").append(mheight).append(" Width: ").append(mwidth).append(" Depth: ").append(mdepth).append("\n");


return output;
//std::cout << "Box ID: " << mid << std::endl;
//std::cout << "Translations: " << mtx << " " << mty << " " << mtz << std::endl;
//std::cout << "Rotations: " << mrx << " " << mry << " " << mrz << std::endl;
//std::cout << "Scales: " << msx << " " << msy << " " << msz << std::endl;
//std::cout << "Color: Red: " << mred << " Green: " << mgreen << " Blue: " << mblue  << std::endl;
//std::cout << "Height, Width, Depth " << mheight << " " << mwidth << " " << mdepth << std::endl <<std::endl;

}

