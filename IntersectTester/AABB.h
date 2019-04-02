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

#ifndef AABB_H
#define AABB_H

#include <vector>
#include <string>
#include <math.h>
#include <iostream>


class AABB
{
public:
    /**
     * @brief AABB Default constructor
     */
    AABB(); //Base Constructor
    /**
     * @brief AABB 2D Constructor
     * @param minX minimum x coordinate
     * @param maxX maximum x coordinate
     * @param minY minimum y coordinate
     * @param maxY maximum y coordinate
     */
    AABB( float minX, float maxX, float minY, float maxY );
    /**
     * @brief AABB 3D Constructor
     * @param minX minimum x coordinate
     * @param maxX maximum x coordinate
     * @param minY minimum y coordinate
     * @param maxY maximum y coordinate
     * @param minZ minimum z coordinate
     * @param maxZ maximum z coordinate
     */
    AABB( float minX, float maxX, float minY, float maxY,
             float minZ, float maxZ );
    /**
     * @brief AABB copy constructor
     * @param other other AABB to copy data from
     */
    AABB( const AABB& other ); //Copy Constructor
    /**
     * @brief operator= assignment operator
     * @param other other AABB to assign data from
     * @return this AABB
     */
    AABB& operator=( const AABB& other ); //Copy Assignment

    /**
     * @brief overwrite alternative assigment method
     * @param other AABB to assign from
     * @see ABBB::operator=
     */
    void overwrite( const AABB& other );
    /**
     * @brief AABB::equals
     * @param comparitor comparison AABB to check for variable equality
     * @return false if any items are not the same value.
     */
    bool equals( AABB comparitor ) const;
    /**
     * @brief AABB::intersects
     * @param comparitor comparison AABB to check for overlap
     * @return false if does not overlap on any of the axes
     */
    bool intersects( AABB comparitor ) const;
    /**
     * @brief AABB::unify
     * @param a
     * @param b
     * @return
     */
    static AABB unify( AABB* a, AABB* b );
    /**
     * @brief length calculates the distance between the min and max values of
     * the dimension
     * @param dimension the dimension to test: XDIM, YDIM, ZDIM.
     * @return the distance between the min and max values of the dimension
     */
    float length( int dimension );
    std::vector<float> minimums;
    std::vector<float> maximums;
    std::string toString();

    static const int XDIM = 0;
    static const int YDIM = 1;
    static const int ZDIM = 2;
    static const int TOTAL_SIZE = 3;

private:
    /**
     * @brief AABB::initialize initialize AABB
     */
    void initialize();
    /**
     * @brief AABB::toString
     * @return  string representation of object
     */
    void dimensionsDefaultSize();
};

#endif // AABB_H
