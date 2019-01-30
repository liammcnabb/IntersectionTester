#include "canvas.h"

Canvas::Canvas( QWidget* parent ) : QOpenGLWidget( parent )
{
    IntersectTester::setTolerance( 1.0f );
}

void Canvas::initializeGL()
{

    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    glEnable( GL_BLEND ); // Required Blending for alpha blending
    glEnable( GL_ALPHA ); // Lets you add alpha values
    //    glEnable( GL_LINE_STIPPLE ); // Enables Dotted Line for use
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
    glClearColor(1,1,1,1);
    //    connect( &timer, SIGNAL( timeout() ), this, SLOT( update() ) );
    //    timer.start( 1000 );
    QWidget::setMouseTracking(true);
    setMouse(Point(-100,100));

}



void Canvas::paintGL()
{
    prepareDraw();

    drawGridlines(100, 0.95f);
    drawGridlines(20, 0.8f);
    drawGridlines(2,0.6f);


    if( movingState() == POINT && staticState() == POINT )
    {
        Point set(0,0);
        pointPointTest(mouse(), set);
    }
    else if( movingState() == POINT && staticState() == LINE )
    {
        LineSegment line(Point(-50,-40),Point(80,10));
        pointLineTest(mouse(), line);
    }
    else if( movingState() == POINT && staticState() == CIRCLE )
    {
        Circle circle(Point(30,30),20);
        pointCircleTest(mouse(), circle);
    }
    else if( movingState() == POINT && staticState() == TRIANGLE )
    {
        Triangle t(Point(-10,-10), Point(-30,-10), Point(-20,10));
        pointTriangleTest(mouse(), t);
    }
    else if( movingState() == POINT && staticState() == SQUARE )
    {
        AABB box(-20,20,-20,20);
        pointSquareTest(mouse(), box);
    }
    else if ( movingState() == LINE && staticState() == POINT )
    {
        Point set(0,0);
        LineSegment line(Point( mouse().getX()-24, mouse().getY()-18 ),
                         Point( mouse().getX()+24, mouse().getY()+18 ) );
        pointLineTest(set, line);
    }
    else if ( movingState() == LINE && staticState() == LINE)
    {
        LineSegment line(Point( mouse().getX()-24, mouse().getY()-18 ),
                         Point( mouse().getX()+24, mouse().getY()+18 ) );
        LineSegment line2(Point(-50,-40),Point(80,10));
        lineLineTest(line, line2);
    }
    else if ( movingState() == LINE && staticState() == CIRCLE)
    {
        LineSegment line(Point( mouse().getX()-24, mouse().getY()-18 ),
                         Point( mouse().getX()+24, mouse().getY()+18 ) );
        Circle circle(Point(30,30),20);
        lineCircleTest(line, circle);
    }
    else if ( movingState() == LINE && staticState() == TRIANGLE)
    {
        LineSegment line(Point( mouse().getX()-24, mouse().getY()-18 ),
                         Point( mouse().getX()+24, mouse().getY()+18 ) );
        Triangle t(Point(-10,-10), Point(-30,-10), Point(-20,10));
        lineTriangleTest(line, t);
    }
    else if ( movingState() == LINE && staticState() == SQUARE)
    {
        LineSegment line(Point( mouse().getX()-24, mouse().getY()-18 ),
                         Point( mouse().getX()+24, mouse().getY()+18 ) );
        AABB box(-20,20,-20,20);
        lineSquareTest(line, box);
    }
    else if ( movingState() == CIRCLE && staticState() == POINT)
    {
        Circle cir(mouse(), 10 );
        Point set(0,0);
        pointCircleTest(set, cir);
    }
    else if ( movingState() == CIRCLE && staticState() == LINE)
    {
        LineSegment line(Point(-50,-40),Point(80,10));
        Circle cir(mouse(), 10 );
        lineCircleTest(line, cir);
    }
    else if ( movingState() == CIRCLE && staticState() == CIRCLE)
    {
        Circle circle(Point(30,30),20);
        Circle cir(mouse(), 10 );
        circleCircleTest(circle, cir);
    }
    else if ( movingState() == CIRCLE && staticState() == TRIANGLE)
    {
        Triangle t(Point(-10,-10), Point(-30,-10), Point(-20,10));
        Circle cir(mouse(), 10 );
        circleTriangleTest(cir, t);
    }
    else if ( movingState() == CIRCLE && staticState() == SQUARE)
    {
        AABB box(-20,20,-20,20);
        Circle cir(mouse(), 10 );
        circleSquareTest(cir, box);
    }
    else if ( movingState() == TRIANGLE && staticState() == POINT)
    {
        Triangle t(Point(mouse().getX()-11,mouse().getY()-11),
                   Point(mouse().getX()+11,mouse().getY()-11),
                   Point(mouse().getX(),mouse().getY()+11));
        Point set(0,0);
        pointTriangleTest(set, t);
    }
    else if ( movingState() == TRIANGLE && staticState() == LINE)
    {
        LineSegment line(Point(-50,-40),Point(80,10));
        Triangle t(Point(mouse().getX()-11,mouse().getY()-11),
                   Point(mouse().getX()+11,mouse().getY()-11),
                   Point(mouse().getX(),mouse().getY()+11));
        lineTriangleTest(line, t);
    }
    else if ( movingState() == TRIANGLE && staticState() == CIRCLE)
    {
        Circle circle(Point(30,30),20);
        Triangle t(Point(mouse().getX()-11,mouse().getY()-11),
                   Point(mouse().getX()+11,mouse().getY()-11),
                   Point(mouse().getX(),mouse().getY()+11));
        circleTriangleTest(circle, t);
    }
    else if ( movingState() == TRIANGLE && staticState() == TRIANGLE)
    {
        Triangle t(Point(-10,-10), Point(-30,-10), Point(-20,10));
        Triangle t2(Point(mouse().getX()-11,mouse().getY()-11),
                   Point(mouse().getX()+11,mouse().getY()-11),
                   Point(mouse().getX(),mouse().getY()+11));
        triangleTriangleTest(t, t2);
    }
    else if ( movingState() == TRIANGLE && staticState() == SQUARE)
    {
        AABB box(-20,20,-20,20);
        Triangle t(Point(mouse().getX()-11,mouse().getY()-11),
                   Point(mouse().getX()+11,mouse().getY()-11),
                   Point(mouse().getX(),mouse().getY()+11));
        triangleSquareTest(t, box);
    }
    else if ( movingState() == SQUARE && staticState() == POINT)
    {
        AABB box(mouse().getX()-20,mouse().getX()+20,mouse().getY()-10,mouse().getY()+10);
        Point set(0,0);
        pointSquareTest(set, box);
    }
    else if ( movingState() == SQUARE && staticState() == LINE)
    {
        LineSegment line(Point(-50,-40),Point(80,10));
        AABB box(mouse().getX()-20,mouse().getX()+20,mouse().getY()-10,mouse().getY()+10);
        lineSquareTest(line, box);
    }
    else if ( movingState() == SQUARE && staticState() == CIRCLE)
    {
        Circle circle(Point(30,30),20);
        AABB box(mouse().getX()-20,mouse().getX()+20,mouse().getY()-10,mouse().getY()+10);
        circleSquareTest(circle, box);
    }
    else if ( movingState() == SQUARE && staticState() == TRIANGLE)
    {
        Triangle t(Point(-10,-10), Point(-30,-10), Point(-20,10));
        AABB box(mouse().getX()-20,mouse().getX()+20,mouse().getY()-10,mouse().getY()+10);
        triangleSquareTest(t, box);
    }
    else if ( movingState() == SQUARE && staticState() == SQUARE)
    {
        AABB a(-20,20,-20,20);
        AABB b(mouse().getX()-20,mouse().getX()+20,mouse().getY()-10,mouse().getY()+10);
        squareSquareTest(a, b);
    }
}

void Canvas::pointPointTest(Point mv, Point st)
{
    drawPoint(mv,Qt::red);
    QColor c = Qt::black;
    if(IntersectTester::isIntersecting(mv, st))
    {
        c = Qt::green;
        drawPoint(mv,c);
    }
    drawPoint(st,c);
}

void Canvas::pointLineTest(Point p, LineSegment ls)
{
    drawPoint(p,Qt::red);
    QColor c = Qt::black;
    if(IntersectTester::isIntersecting(p, ls))
    {
        c = Qt::green;
        drawPoint(p,c);
    }
    drawPoint(IntersectTester::closestPoint(ls,p), Qt::black);
    drawLine(ls,c);
}

void Canvas::pointCircleTest(Point p, Circle cir)
{
    drawPoint(p,Qt::red);
    QColor c = Qt::black;
    if(IntersectTester::isIntersecting(p, cir))
    {
        c = Qt::green;
        drawPoint(p,c);
    }
    drawCircle(cir,c);
}

void Canvas::pointTriangleTest(Point p, Triangle t)
{
    drawPoint(p,Qt::red);
    QColor c = Qt::black;
    if(IntersectTester::isIntersecting(p, t))
    {
        c = Qt::green;
        drawPoint(p,c);
    }
    drawTriangle(t,c);
}

void Canvas::pointSquareTest(Point p, AABB b)
{
    drawPoint(p,Qt::red);
    QColor c = Qt::black;
    if(IntersectTester::isIntersecting(p, b))
    {
        c = Qt::green;
        drawPoint(p,c);
    }
    drawSquare(b,c);
}

void Canvas::lineLineTest(LineSegment a, LineSegment b)
{
    QColor c = Qt::black;
    if(IntersectTester::isIntersecting(a, b))
        c = Qt::green;

    drawLine(a,c);
    drawLine(b,c);
}

void Canvas::lineCircleTest(LineSegment ls, Circle cir)
{
    QColor c = Qt::black;
    if(IntersectTester::isIntersecting(ls, cir))
        c = Qt::green;

    drawPoint(IntersectTester::closestPoint( ls, cir.getCenter() ),Qt::black);
    drawLine(ls,c);
    drawCircle(cir,c);
}

void Canvas::lineTriangleTest(LineSegment ls, Triangle t)
{
    QColor c = Qt::black;
    if(IntersectTester::isIntersecting(ls, t))
        c = Qt::green;

    drawLine(ls,c);
    drawTriangle(t,c);
}

void Canvas::lineSquareTest(LineSegment ls, AABB sq)
{
    QColor c = Qt::black;
    if(IntersectTester::isIntersecting(ls, sq))
        c = Qt::green;

    drawLine(ls,c);
    drawSquare(sq,c);
}

void Canvas::circleCircleTest(Circle a, Circle b)
{
    QColor c = Qt::black;
    if(IntersectTester::isIntersecting(a, b))
        c = Qt::green;

    drawCircle(a,c);
    drawCircle(b,c);
}

void Canvas::circleTriangleTest(Circle cir, Triangle t)
{
    QColor c = Qt::black;
    if(IntersectTester::isIntersecting(cir, t))
        c = Qt::green;

    drawCircle(cir,c);
    drawTriangle(t,c);
}

void Canvas::circleSquareTest(Circle cir, AABB sq)
{
    Point A(sq.minimums[AABB::XDIM], sq.minimums[AABB::YDIM]);
    Point B(sq.minimums[AABB::XDIM], sq.maximums[AABB::YDIM]);
    Point C(sq.maximums[AABB::XDIM], sq.maximums[AABB::YDIM]);
    Point D(sq.maximums[AABB::XDIM], sq.minimums[AABB::YDIM]);

    QColor c = Qt::black;
    if(IntersectTester::isIntersecting(cir, sq))
        c = Qt::green;

    drawPoint(IntersectTester::closestPoint( LineSegment(A,B), cir.getCenter() ),Qt::black);
    drawPoint(IntersectTester::closestPoint( LineSegment(B,C), cir.getCenter() ),Qt::black);
    drawPoint(IntersectTester::closestPoint( LineSegment(D,C), cir.getCenter() ),Qt::black);
    drawPoint(IntersectTester::closestPoint( LineSegment(A,D), cir.getCenter() ),Qt::black);
    drawCircle(cir,c);
    drawSquare(sq,c);
}

void Canvas::triangleTriangleTest(Triangle a, Triangle b)
{
    QColor c = Qt::black;
    if(IntersectTester::isIntersecting(a, b))
        c = Qt::green;

    drawTriangle(a,c);
    drawTriangle(b,c);
}

void Canvas::triangleSquareTest(Triangle t, AABB sq)
{
    QColor c = Qt::black;
    if(IntersectTester::isIntersecting(t, sq))
        c = Qt::green;

    drawTriangle(t,c);
    drawSquare(sq,c);
}

void Canvas::squareSquareTest(AABB a, AABB b)
{
    QColor c = Qt::black;
    if(IntersectTester::isIntersecting(a, b))
        c = Qt::green;

    drawSquare(a,c);
    drawSquare(b,c);
}

void Canvas::drawPoint( Point p, QColor color )
{
    glColor3f(color.redF(),color.greenF(),color.blueF());
    glBegin(GL_POINTS);
    glVertex2f(p.getX(),p.getY());
    glEnd();
}

void Canvas::drawLine( LineSegment line, QColor color )
{
    glColor3f(color.redF(),color.greenF(),color.blueF());
    glBegin(GL_LINES);
    glVertex2f(line.getStart().getX(), line.getStart().getY());
    glVertex2f(line.getEnd().getX(), line.getEnd().getY());
    glEnd();
}

void Canvas::drawCircle( Circle circle, QColor color )
{
    glColor3f(color.redF(),color.greenF(),color.blueF());
    glBegin(GL_LINE_LOOP);
    for ( float angle = 0; angle <= (2*M_PI); angle += 0.01 )
    {
        float x = circle.getCenter().getX() + sin( angle ) *
                    circle.getRadius();

        float y = circle.getCenter().getY() + cos( angle ) *
                    circle.getRadius();

        glVertex2f( x, y );
    }
    glEnd();

    glColor4f(color.redF(),color.greenF(),color.blueF(), 0.2f);
    glBegin( GL_TRIANGLE_FAN );
    glVertex2f( circle.getCenter().getX(), circle.getCenter().getY() );
    for ( float angle = 0; angle <= (2*M_PI); angle += 0.01 )
    {
        float x = circle.getCenter().getX() + sin( angle ) *
                    circle.getRadius();

        float y = circle.getCenter().getY() + cos( angle ) *
                    circle.getRadius();

        glVertex2f( x, y );
    }
    float x = circle.getCenter().getX() + sin( 0 ) *
                circle.getRadius();

    float y = circle.getCenter().getY() + cos( 0 ) *
                circle.getRadius() ;

    glVertex2f( x, y );
    glEnd();
}

void Canvas::drawTriangle(Triangle t, QColor color)
{
    glColor3f(color.redF(),color.greenF(),color.blueF());
    glBegin(GL_LINE_LOOP);
    glVertex2f(t.getVertexOne().getX(), t.getVertexOne().getY());
    glVertex2f(t.getVertexTwo().getX(), t.getVertexTwo().getY());
    glVertex2f(t.getVertexThree().getX(), t.getVertexThree().getY());
    glEnd();

    glColor4f(color.redF(),color.greenF(),color.blueF(),0.2);
    glBegin(GL_POLYGON);
    glVertex2f(t.getVertexOne().getX(), t.getVertexOne().getY());
    glVertex2f(t.getVertexTwo().getX(), t.getVertexTwo().getY());
    glVertex2f(t.getVertexThree().getX(), t.getVertexThree().getY());
    glEnd();
}

void Canvas::drawSquare(AABB sq, QColor color)
{
    glColor3f(color.redF(),color.greenF(),color.blueF());
    glBegin(GL_LINE_LOOP);
    glVertex2f(sq.minimums[AABB::XDIM],sq.minimums[AABB::YDIM]);
    glVertex2f(sq.minimums[AABB::XDIM],sq.maximums[AABB::YDIM]);
    glVertex2f(sq.maximums[AABB::XDIM],sq.maximums[AABB::YDIM]);
    glVertex2f(sq.maximums[AABB::XDIM],sq.minimums[AABB::YDIM]);
    glEnd();

    glColor4f(color.redF(),color.greenF(),color.blueF(), 0.2);
    glBegin(GL_QUADS);
    glVertex2f(sq.minimums[AABB::XDIM],sq.minimums[AABB::YDIM]);
    glVertex2f(sq.minimums[AABB::XDIM],sq.maximums[AABB::YDIM]);
    glVertex2f(sq.maximums[AABB::XDIM],sq.maximums[AABB::YDIM]);
    glVertex2f(sq.maximums[AABB::XDIM],sq.minimums[AABB::YDIM]);
    glEnd();
}

void Canvas::drawGridlines(int granularity, float shade)
{
    int gap = ( TOP - BOTTOM ) / granularity;
    glColor3f(shade,shade,shade);
    glBegin(GL_LINES);
    for ( int i = 0; i < granularity; ++i )
    {
        int x = LEFT + (gap*i);
        glVertex2f(x,BOTTOM);
        glVertex2f(x,TOP);

        int y = BOTTOM + (gap*i);
        glVertex2f(LEFT,y);
        glVertex2f(RIGHT,y);

    }
    glEnd();
}

void Canvas::prepareDraw()
{
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glClearColor( 1,
                  1,
                  1, 1.0 );
    glOrtho(LEFT,RIGHT,BOTTOM,TOP,1,0);
    glClear( GL_COLOR_BUFFER_BIT );
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    glLoadIdentity();
    glPointSize( 3 );
}


float Canvas::convertedX( float windowX )
{
    float newX;
    newX = LEFT +
            ( ( windowX / this->width() ) *
              ( RIGHT - LEFT ) );
    return newX;
}

float Canvas::convertedY( float windowY )
{
    float newY,reverseY;
    reverseY = -( windowY - 1 - this->height() );

    newY = BOTTOM +
            ( ( reverseY / this->height() ) *
              ( TOP - BOTTOM ) ) ;
    return newY;
}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    setMouse(Point( int(convertedX( float( event->x() ) ) ),
                     int(convertedY( float( event->y() ) ) ) ) );
    update();
}

Point Canvas::mouse() const
{
    return m_mouse;
}

void Canvas::setMouse(const Point &mouse)
{
    m_mouse = mouse;
}

int Canvas::movingState() const
{
    return m_movingState;
}

void Canvas::setMovingState(int movingState)
{
    m_movingState = movingState;
}

int Canvas::staticState() const
{
    return m_staticState;
}

void Canvas::setStaticState(int staticState)
{
    m_staticState = staticState;
}
