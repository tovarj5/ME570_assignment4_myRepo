#ifndef XMLSHAPESREADER_H
#define XMLSHAPESREADER_H
#include <QIODevice>
#include <QXmlStreamReader>
#include <QString>
//#include "linkedlist.h"


class Shape;

class XmlShapesReader
{
public:
    //XmlShapesReader(LinkedList *linkedlist);
    XmlShapesReader(std::list<Shape*> *linkedlist);
    bool read(QIODevice *device);
    QString errorString() const;

protected:
    QXmlStreamReader mReader;
    //LinkedList* mLinkedList;
    std::list<Shape*> mLinkedList;
    struct Vector3
    {
        double mX{0};
        double mY{0};
        double mZ{0};
    };

    void read_shapes();
    void read_shape();
    void read_box(int id, Shape *&shape); //Reads in the height, width, and depth for a box. if empty property is 1
    void read_cone(int id, Shape *&shape); //Reads in the height, X & Y Radius for a cone. If empty, property is 0
    void read_ellipsoid(int id, Shape *&shape); //Reads in the X, Y, Z Radius for an ellipsoid. If empty, property is 0
    void read_id(int &id);//Reads id number from file. if empty, property is null.
    void read_color(Vector3 &color);
    void read_xyz(Vector3 &vec);
};

#endif // XMLSHAPESREADER_H
