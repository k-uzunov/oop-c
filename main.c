#include "point.h"
#include <stdio.h>

int main(void) {
    Point* p1 = point_create();
    Point* p2 = point_create();

/* ************************************************************************** */
/* * Test if x is accessible                                                * */
/* * It should fail                                                         * */
/* ************************************************************************** */
    // p1->x = 3;                                                         * */

/* ************************************************************************** */
/* * main.c: In function ‘main’:                                            * */
/* *    main.c:10:7: error: invalid use of incomplete typedef ‘Point’       * */
/* *       10 |     p1->x = 3;                                              * */
/* *          |       ^~                                                    * */
/* ************************************************************************** */
    point_set_x(p1, 1);
    point_set_y(p1, 2);
    point_set_x(p2, 3);
    point_set_y(p2, 4);

    printf("Point 1 coordinates are: %d, %d\n", point_get_x(p1), point_get_y(p1));
    printf("Point 2 coordinates are: %d, %d\n", point_get_x(p2), point_get_y(p2));

    printf("Moving Point 1 ...\n");
    point_move(p1, 5, 6);

    printf("Point 1 coordinates are: %d, %d\n", point_get_x(p1), point_get_y(p1));
    printf("Point 2 coordinates are: %d, %d\n", point_get_x(p2), point_get_y(p2));

    point_destroy(p1);
    point_destroy(p2);
}
