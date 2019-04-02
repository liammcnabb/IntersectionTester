/*!
 *
 *  Intersection Tester - v1.0.0
    Original Author: Liam McNabb
    Proceeding Author(s): N/A
    Copyright (c) 2019
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (IntersectionTester), to
    deal in the Software without restriction, including without limitation the
    rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
    sell copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

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
    /**
     * @brief TOP Top of the canvas
     */
    static const int TOP = 100;
    /**
     * @brief BOTTOM Bottom of the canvas
     */
    static const int BOTTOM = -100;
    /**
     * @brief LEFT Left of the canvas
     */
    static const int LEFT = -100;
    /**
     * @brief RIGHT Right on the canvas
     */
    static const int RIGHT = 100;

    //PRIMITIVES
    /**
     * @brief POINT set primitive to point
     */
    static const int POINT = 0;
    /**
     * @brief LINE set primitive to line segment
     */
    static const int LINE = 1;
    /**
     * @brief CIRCLE set primitive to circle
     */
    static const int CIRCLE = 2;
    /**
     * @brief TRIANGLE set primitive to triangle
     */
    static const int TRIANGLE = 3;
    /**
     * @brief SQUARE set primitive to square
     */
    static const int SQUARE = 4;

    /**
     * @brief Canvas Constructor
     * @param parent parent window
     */
    Canvas(QWidget *parent);
    /**
     * @brief initializeGL OpenGL initialization method
     */
    void initializeGL();
    /**
     * @brief paintGL method called on OpenGL window refresh
     */
    void paintGL();

    /**
     * @brief mouse getter method for mouse coordinates
     * @return mouse coordinates
     */
    Point mouse() const;
    /**
     * @brief setMouse setter method for mouse coordinates
     * @param mouse new mouse coordinates
     */
    void setMouse(const Point &mouse);

    /**
     * @brief staticState getter method for state of static primitive
     * @return state of static primitive
     */
    int staticState() const;
    /**
     * @brief setStaticState setter method for state of static primitive
     * @param staticState new state of static primitive
     */
    void setStaticState(int staticState);

    /**
     * @brief movingState getter method for state of moving primitive
     * @return state of moving primitive
     */
    int movingState() const;
    /**
     * @brief setMovingState setter method for state of moving primitive
     * @param movingState new state of moving primitive
     */
    void setMovingState(int movingState);

private:
    Point m_mouse;
    int m_staticState = 4;
    int m_movingState = 0;

    /**
     * @brief prepareDraw method to intialze canvas options per draw sequence
     */
    void prepareDraw();
    /**
     * @brief drawGridlines Used to draw grid lines across full canvas
     * @param granularity how many lifes drawn grid segments per dimension
     * @param shade the greyscale shade of the grid
     */
    void drawGridlines(int granularity, float shade);
    /**
     * @brief mouseMoveEvent qt method to catch mouse movement events
     * @param event the moust event
     */
    void mouseMoveEvent(QMouseEvent *event);
    /**
     * @brief convertedX converts display x coordinate to canvas x coordinate
     * @param windowX display x coordinate
     * @return canvas x coordinate
     */
    float convertedX(float windowX);
    /**
     * @brief convertedY converts display y coordinate to canvas y coordinate
     * @param windowY display y coordinate
     * @return canvas y coordinate
     */
    float convertedY(float windowY);
    /**
     * @brief drawSquare draw a square on the canvas
     * @param sq the square to draw
     * @param color the color of the square
     */
    void drawSquare(AABB sq, QColor color);
    /**
     * @brief drawPoint draw a point on the canvas
     * @param p point to draw
     * @param color the color of the point
     */
    void drawPoint(Point p, QColor color);
    /**
     * @brief drawLine draw a line on the canvas
     * @param line line to draw
     * @param color the color of the line
     */
    void drawLine(LineSegment line, QColor color);
    /**
     * @brief drawCircle draw a circle on the canvas
     * @param circle circle to draw
     * @param color the color of the circle
     */
    void drawCircle(Circle circle, QColor color);
    /**
     * @brief drawTriangle draw a triangle on the canvas
     * @param t triangle to draw
     * @param color the color of the triangle
     */
    void drawTriangle(Triangle t, QColor color);
    /**
     * @brief pointPointTest test to call when two points need to be tested
     * @param mv point 1
     * @param st point 2
     */
    void pointPointTest(Point mv, Point st);
    /**
     * @brief pointLineTest test to call when point and line segment need to be
     * tested
     * @param p point
     * @param ls line segment
     */
    void pointLineTest(Point p, LineSegment ls);
    /**
     * @brief pointCircleTest test to call when point and cirlce need to be
     * tested
     * @param p point
     * @param cir circle
     */
    void pointCircleTest(Point p, Circle cir);
    /**
     * @brief pointTriangleTest test to call when point and triangle need to be
     * tested
     * @param p point
     * @param t triangle
     */
    void pointTriangleTest(Point p, Triangle t);
    /**
     * @brief pointSquareTest test to call when point and square need to be
     * tested
     * @param p point
     * @param b square
     */
    void pointSquareTest(Point p, AABB b);
    /**
     * @brief lineLineTest test to call when two linesegment need to be tested
     * @param a line 1
     * @param b line 2
     */
    void lineLineTest(LineSegment a, LineSegment b);
    /**
     * @brief lineCircleTest test to call when linesegment and circle need to be
     * tested
     * @param ls linesegment
     * @param cir circle
     */
    void lineCircleTest(LineSegment ls, Circle cir);
    /**
     * @brief lineTriangleTest test to call when linesegment and triangle need
     * to be tested
     * @param ls linesegment
     * @param t triangle
     */
    void lineTriangleTest(LineSegment ls, Triangle t);
    /**
     * @brief lineSquareTest test to call when linesegment and triangle need to
     * be tested
     * @param ls linesegment
     * @param sq square
     */
    void lineSquareTest(LineSegment ls, AABB sq);
    /**
     * @brief circleCircleTest test to call when two circles need to be tested
     * @param a circle 1
     * @param b circle 2
     */
    void circleCircleTest(Circle a, Circle b);
    /**
     * @brief circleTriangleTest test to call when circle and triangle need to
     * be tested
     * @param cir circle
     * @param t triangle
     */
    void circleTriangleTest(Circle cir, Triangle t);
    /**
     * @brief circleSquareTest test to call when a circle and square need to
     * be tested
     * @param cir circle
     * @param sq square
     */
    void circleSquareTest(Circle cir, AABB sq);
    /**
     * @brief triangleTriangleTest test to call when two triangles need to be
     * tested
     * @param a triangle
     * @param b triangle
     */
    void triangleTriangleTest(Triangle a, Triangle b);
    /**
     * @brief triangleSquareTest test to call when triangle and circle need to
     * be tested
     * @param t triangle
     * @param sq square
     */
    void triangleSquareTest(Triangle t, AABB sq);
    /**
     * @brief squareSquareTest test to call when two squares need to be tested
     * @param a
     * @param b
     */
    void squareSquareTest(AABB a, AABB b);
};

#endif // CANVAS_H
