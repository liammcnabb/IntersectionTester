#ifndef INTERSECTTESTER_H
#define INTERSECTTESTER_H

#include <limits>
#include <QDebug>
#include "AABB.h"
//#include "IntersectTester.cpp"


class Point {
public:
        float x, y, z;
        Point() 
        {
            this->x = 0;
            this->y = 0;
            this->z = 0;
        }
        Point( float x, float y )
        {
            this->x = x;
            this->y = y;
            this->z = 0;
        }
        Point( float x, float y, float z)
        {
            this->x = x;
            this->y = y;
            this->z = z;
        }
         Point& operator= (const Point& other)
         {
             x = other.getX();
             y = other.getY();
             z = other.getZ();
             return *this;
         }
        float getX() const { return x; }
        float getY() const { return y; }
        float getZ() const { return z; }
        void setX( float newX ) { x = newX; }
        void setY( float newY ) { y = newY; }
        void setZ( float newZ ) { z = newZ; }
};

class LineSegment {
public:
        Point start;
        Point end;
        LineSegment(Point x, Point y)
        {
             start = Point(x.getX(), x.getY(), x.getZ());
             end = Point(y.getX(), y.getY(), y.getZ());
        }
        Point getStart() const { return start; } 
        Point getEnd() const { return end; } 
};


class Triangle {
public:
        Point v1, v2 ,v3;
        Triangle(Point x, Point y, Point z)
        {
             v1 = Point(x.getX(), x.getY(), x.getZ());
             v2 = Point(y.getX(), y.getY(), y.getZ());
             v3 = Point(z.getX(), z.getY(), z.getZ());
        }
        Point getVertexOne() const { return v1; } 
        Point getVertexTwo() const { return v2; } 
        Point getVertexThree() const { return v3; } 
};

class Circle {
public:
    Point center;
    float radius;
    Circle(Point center, float radius)
    {
        this->center = center;
        this->radius = radius;
    }
    Point getCenter() const { return center; }
    float getRadius() const { return radius; }
};



class IntersectTester
{

public:
    IntersectTester();

    static bool isIntersecting(Point a, Point b);
   /**
    * @brief IntersectTester::isIntersecting calls isPointOnLineSegment
    * @refer IntersectTester::isPointOnLineSegment
    * @param p coordinate set to test
    * @param ls lineSegment
    * @return if point is on line segment (ls), return
    * true, otherwise return false.
    */
    inline static bool isIntersecting(Point p, LineSegment ls) 
    { return isPointOnLineSegment( p, ls ); }

    inline static bool isIntersecting(Point p, Circle c)
    { return isPointOnCircle( p,c ); }

    inline static bool isIntersecting(Point p, Triangle t)
    { return isPointOnTriangle( p,t ); }

    inline static bool isIntersecting(Point p, AABB a)
    { return isPointOnAABB( p, a ); }

    inline static bool isIntersecting(LineSegment a, LineSegment b) 
    { return areLineSegmentsIntersecting( a, b ); }

    inline static bool isIntersecting(LineSegment a, Circle c)
    { return areLineSegmentAndCircleIntersecting( a, c ); }

    inline static bool isIntersecting(LineSegment ls, Triangle t)
    { return doesLineSegmentIntersectTriangle( ls, t ); }

    inline static bool isIntersecting(LineSegment ls, AABB a)
    { return doesLineSegmentIntersectAABB( ls, a ); }

    inline static bool isIntersecting(Circle a, Circle b)
    { return doCirclesIntersect(a,b); }

    inline static bool isIntersecting(Circle c, Triangle t)
    { return doesCircleIntersectTriangle(c,t); }

    inline static bool isIntersecting(Circle c, AABB a)
    { return doCircleandAABBIntersect(c, a); }

    inline static bool isIntersecting(Triangle a, Triangle b)
    { return doTrianglesIntersect(a,b); }

    inline static bool isIntersecting(Triangle t, AABB a)
    { return doTriangleAndAABBIntersect(t,a); }

    inline static bool isIntersecting(AABB a, AABB b) 
    { return areBoxesIntersecting( a, b ); }
    



    static float distanceBetweenPoints(Point a, Point b);
    static float crossProduct(Point a, Point b, Point c);
    static float dotProduct(Point a, Point b);
    static float dotProduct(Point a, Point b, Point c);
    static int direction(Point a, Point b, Point c);
private:
    /**
    * @brief IntersectTester::isPointOnLineSegment used to check
    * whether a coordinate point (p) intersects with a line (ls).
    * @param p coordinate set to test
    * @param ls lineSegment
    * @return if point is on the line (ls), return
    * true, otherwise return false.
    */
    static bool isPointOnLineSegment(Point p, LineSegment ls);
    /**
     * @brief isPointOnCircle Tested by checking the distance
     * between the point, and the center of the circle, if the
     * distance is less than or equal to the radius, the point is
     * within the circle.
     * @param p Point
     * @param c Circle
     * @return if point is in the circle, return true,
     * otherwise return false
     */
    static bool isPointOnCircle(Point p, Circle c);
    /**
     * @brief isPointOnTriangle
     * @param p
     * @param t
     * @return
     */
    static bool isPointOnTriangle(Point p, Triangle t);
    /**
     * @brief isPointOnAABB We test the null hypothesis.
     * If the X axis, or the Y axis fall outside of the axes
     * range of the bounding box, the we know this is false.
     * Otherwise it is true.
     * @param p Point
     * @param a AABB
     * @return if point is within AABB, return true,
     * otherwise return false.
     */
    static bool isPointOnAABB(Point p, AABB a);
    /**
     * @brief areLineSegmentsIntersecting
     * @param a
     * @param b
     * @return
     */
    static bool areLineSegmentsIntersecting(LineSegment a, LineSegment b);
    /**
     * @brief areLineSegmentAndCircleIntersecting
     * @param a
     * @param c
     * @return
     */
    static bool areLineSegmentAndCircleIntersecting( LineSegment a, Circle c );
    /**
     * @brief doesLineSegmentIntersectTriangle
     * @param a
     * @param t
     * @return
     */
    static bool doesLineSegmentIntersectTriangle( LineSegment a, Triangle t);
    /**
     * @brief doesLineSegmentIntersectAABB
     * @param ls
     * @param a
     * @return
     */
    static bool doesLineSegmentIntersectAABB(LineSegment ls, AABB a );
    /**
     * @brief doCirclesIntersect
     * @param a
     * @param b
     * @return
     */
    static bool doCirclesIntersect(Circle a, Circle b);
    /**
     * @brief doesCircleIntersectTriangle
     * @param c
     * @param t
     * @return
     */
    static bool doesCircleIntersectTriangle(Circle c, Triangle t);
    /**
     * @brief doCircleandAABBIntersect
     * @param c
     * @param a
     * @return
     */
    static bool doCircleandAABBIntersect(Circle c, AABB a);
    /**
     * @brief doTrianglesIntersect
     * @param a
     * @param b
     * @return
     */
    static bool doTrianglesIntersect(Triangle a, Triangle b);
    /**
     * @brief doTriangleAndAABBIntersect
     * @param t
     * @param a
     * @return
     */
    static bool doTriangleAndAABBIntersect(Triangle t, AABB a);
    /**
     * @brief areBoxesIntersecting the axis-aligned box test is similar to the point test.
     * We use the null hypothesis. If the X dimension extents of AABB 2 do not fall into
     * the extents of AABB 1, then we know that it is not possible for the boxes to
     * intersect. We can make the same assumption for the Y axis. If both the X and Y axes
     * of AABB 2 can be found in AABB 1, then we know that they intersect.
     * @param a AABB 1
     * @param b AABB 2
     * @return
     */
    static bool areBoxesIntersecting(AABB a, AABB b);



};


#endif // INTERSECTTESTER_H
