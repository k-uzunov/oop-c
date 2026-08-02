#ifndef POINT_H
#define POINT_H

/* Define opaque structure */
typedef struct Point Point;

/* ************************************************************************** */
/* * Methods of the "class" Point. Some of them require the Point object to * */
/* * be passed as an argument in order to access the object's properties,   * */
/* * similar to Python's 'self'.                                            * */
/* ************************************************************************** */

/* Creates a pointer to structure Point and allocates memory */
Point* point_create(void);
/* Frees memory of a point */
void point_destroy(Point* point);
/* Gets a point's x coordinate */
int point_get_x(Point* point);
/* Gets a point's y coordinate */
int point_get_y(Point* point);
/* Sets a point's x coordinate */
void point_set_x(Point* point, int x);
/* Sets a point's y coordinate */
void point_set_y(Point* point, int y);
/* Moves a point */
void point_move(Point* point, int dx, int dy);

#endif // POINT_H
