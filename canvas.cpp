#include "canvas.h"

Canvas::Canvas( QWidget* parent ) : QOpenGLWidget( parent )
{}

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


    if(staticState() == POINT && movingState() == POINT)
    {
        drawPoint(mouse(),Qt::red);
        QColor c = Qt::black;
        if(IntersectTester::isIntersecting(mouse(), Point(0,0)))
        {
            c = Qt::green;
            drawPoint(mouse(),c);
        }
        drawPoint(Point(0,0),c);
    }
    if(staticState() == LINE && movingState() == POINT)
    {
        drawPoint(mouse(),Qt::red);
        LineSegment line(Point(-50,-40),Point(80,10));
        QColor c = Qt::black;
        if(IntersectTester::isIntersecting(mouse(), line))
        {
            c = Qt::green;
            drawPoint(mouse(),c);
        }
        drawLine(line,c);
    }
    if(staticState() == CIRCLE && movingState() == POINT)
    {
        drawPoint(mouse(),Qt::red);
        Circle circle(Point(30,30),20);
        QColor c = Qt::black;
        if(IntersectTester::isIntersecting(mouse(), circle))
        {
            c = Qt::green;
            drawPoint(mouse(),c);
        }
        drawCircle(circle,c);
    }
    if(staticState() == TRIANGLE && movingState() == POINT)
    {
        drawPoint(mouse(),Qt::red);
        Triangle t(Point(-10,-10), Point(-30,-10), Point(-20,10));
        QColor c = Qt::black;
        if(IntersectTester::isIntersecting(mouse(), t))
        {
            c = Qt::green;
            drawPoint(mouse(),c);
        }
        drawTriangle(t,c);
    }
    else if(staticState() == SQUARE && movingState() == POINT)
    {
        drawPoint(mouse(),Qt::red);
        QColor c = Qt::black;
        if(IntersectTester::isIntersecting(mouse(), AABB(-20,20,-20,20)))
        {
            c = Qt::green;
            drawPoint(mouse(),c);
        }
        drawSquare(-20,20,-20,20,c);
    }
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

void Canvas::drawSquare(float left, float right, float bottom, float top, QColor color)
{
    glColor3f(color.redF(),color.greenF(),color.blueF());
    glBegin(GL_LINE_LOOP);
    glVertex2f(-20,-20);
    glVertex2f(-20,20);
    glVertex2f(20,20);
    glVertex2f(20,-20);
    glEnd();

    glColor4f(color.redF(),color.greenF(),color.blueF(), 0.2);
    glBegin(GL_QUADS);
    glVertex2f(-20,-20);
    glVertex2f(-20,20);
    glVertex2f(20,20);
    glVertex2f(20,-20);
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
