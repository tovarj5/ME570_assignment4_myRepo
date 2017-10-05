///-------------------------------------------
// Author: Jacob Tovar
// Date: 9/28/17
// Assignment: 3 - Linked-Lists with Pointers
//--------------------------------------------
#include <string>
#include <iostream>
#include <QString>

#ifndef SHAPE_H
#define SHAPE_H


class Shape
{
public:
    Shape(int id);

    int get_id();

    //All of the get / set functions are the same and take in the parameters and assign them.
    //Get takes in null parameters by reference and fills them.
    void set_translation(double tx,double ty, double tz);
    void get_translation(double &tx,double &ty, double &tz);

    void set_rotation(double rx,double ry, double rz);
    void get_rotation(double &rx,double &ry, double &rz);

    void set_scale(double sx,double sy, double sz);
    void get_scale(double &sx,double &sy, double&sz);

    void set_color(double r,double g, double b);
    void get_color(double &r,double &g, double &b);

    virtual QString print()=0;

protected:
    //All shapes have the following things in common: An id. A color.
    //A set of translations in the x, y and z directions. A set of rotations about the x axis, y axis and z axis.
    //A set of scale factors in the x, y and z directions.
    int mid{0};
    std::string shape_color{NULL};
    double mtx{0},mty{0},mtz{0};
    double mrx{0},mry{0},mrz{0};
    double msx{0},msy{0},msz{0};
    double mred{0},mgreen{0},mblue{0};


};

#endif // SHAPE_H
