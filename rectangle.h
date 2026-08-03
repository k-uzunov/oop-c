#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "point.h"
#include <stdlib.h>

/* ************************************************************************* *
 * This structure describes a rectangle. It uses array of four Point ob-     *
 * jects to describe the shape. The point at index 0 must always be the top  *
 * left corner of the rectangle, the rest of the points are going in clock-  *
 * wise direction.                                                           *
 * ************************************************************************* */
/* ************************************************************************* *
 * The `__points` is hidden by convention. Between using opaque structure    *
 * and wrapper functions for the methods and exposing the structure layout   *
 * and hiding members by convention I chose hiding by convention with        *
 * double underscore (inspired by Python) to save some work on writing ad-   *
 * ditional functions, also to avoid mistakes, forgotten wrappers, wrap-     *
 * pers pointing to deleted methods etc.                                     *
 * ************************************************************************* */

typedef struct Rectangle{
    Point** __points;
    int (*set_points)(struct Rectangle*, Point*, Point*, Point*, Point*);
    int (*set_point)(struct Rectangle*, char, Point*);
    Point** (*get_points)(const struct Rectangle* );
    Point* (*get_point)(const struct Rectangle*, char);
    Point* (*get_center)(const struct Rectangle*);
    int (*get_width)(const struct Rectangle*);
    int (*get_height)(const struct Rectangle*);
    int (*get_area)(const struct Rectangle*);
    int (*get_circ)(const struct Rectangle*);
    void (*rotate)(struct Rectangle*);
    void (*destroy)(struct Rectangle*);
}  Rectangle;

Rectangle* rect_create(void);

#endif
