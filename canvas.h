#ifndef CANVAS_H
#define CANVAS_H

#include <QOpenGLWidget>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <QMouseEvent>
#include <IntersectTester/AABB.h>
#include <IntersectTester/IntersectTester.h>

class Canvas : public QOpenGLWidget
{
public:
    //EXTENTS
    int TOP = 100;
    int BOTTOM = -100;
    int LEFT = -100;
    int RIGHT = 100;

    //PRIMITIVES
    int POINT = 0;
    int LINE = 1;
    int CIRCLE = 2;
    int TRIANGLE = 3;
    int SQUARE = 4;

    Canvas(QWidget *parent);
    void initializeGL();
    void paintGL();
    Point mouse() const;
    void setMouse(const Point &mouse);

    int staticState() const;
    void setStaticState(int staticState);

    int movingState() const;
    void setMovingState(int movingState);

private:
    Point m_mouse;
    int m_staticState = 4;
    int m_movingState = 0;
    void prepareDraw();
    void drawGridlines(int granularity, float shade);
    void mouseMoveEvent(QMouseEvent *event);
    float convertedX(float windowX);
    float convertedY(float windowY);
    void drawSquare(float left, float right, float bottom, float top, QColor color);
    void drawPoint(Point p, QColor color);
    void drawLine(LineSegment line, QColor color);
    void drawCircle(Circle circle, QColor color);
    void drawTriangle(Triangle t, QColor color);
};

#endif // CANVAS_H
