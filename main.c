#include "point.h"
#include "rectangle.h"
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

    printf("-------------------------------------------------------------\n\n");

    Point* rect_p_a = point_create();
    Point* rect_p_b = point_create();
    Point* rect_p_c = point_create();
    Point* rect_p_d = point_create();

    point_set_x(rect_p_a, 10);
    point_set_y(rect_p_a, 15);

    point_set_x(rect_p_b, 10);
    point_set_y(rect_p_b, 0);

    point_set_x(rect_p_c, 0);
    point_set_y(rect_p_c, 0);

    point_set_x(rect_p_d, 0);
    point_set_y(rect_p_d, 15);

    Rectangle* rect = rect_create();
    rect->set_points(rect, rect_p_a, rect_p_b, rect_p_c, rect_p_d);

    Point** rect_points = rect->get_points(rect);

    printf("Points of the rectangle are:\n");
    for (int i = 0; i < 4; i++) {
        int px = point_get_x(rect_points[i]);
        int py = point_get_y(rect_points[i]);
        printf("%d, %d\n", px, py);
    }
    printf("The rectangle is %d wide.\n", rect->get_width(rect));
    printf("The rectangle is %d tall.\n", rect->get_height(rect));
    printf("The rectangle area is %d\n", rect->get_area(rect));
    printf("The rectangle circumference is %d\n", rect->get_circ(rect));
    printf("Rotating the rectangle...\n");
    rect->rotate(rect);

    rect_points = NULL;
    rect_points = rect->get_points(rect);
    printf("Points of the rectangle are:\n");
    for (int i = 0; i < 4; i++) {
        int px = point_get_x(rect_points[i]);
        int py = point_get_y(rect_points[i]);
        printf("%d, %d\n", px, py);
    }

    rect->destroy(rect);
}
