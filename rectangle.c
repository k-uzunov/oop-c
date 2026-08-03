#include "rectangle.h"
#include "point.h"
#include <stdlib.h>

int rect_set_points(Rectangle* self, Point* a, Point* b, Point* c, Point* d);
int rect_set_point (Rectangle* self, char point_letter, Point* point);
Point** rect_get_points(const Rectangle* self);
Point* rect_get_point (const Rectangle* self, char point_letter);
int rect_get_width(const Rectangle* self);
int rect_get_height(const Rectangle* self);
Point* rect_get_center(const Rectangle* self);
int rect_get_area(const Rectangle* self);
int rect_get_circ(const Rectangle* self);
void rect_rotate(Rectangle* self);
void rect_destroy(Rectangle* self);


Rectangle* rect_create(void){
    struct Rectangle* new_rect = calloc(1, sizeof(struct Rectangle));
    new_rect->__points = calloc(4, sizeof(Point*));
    new_rect->set_points = &rect_set_points;
    new_rect->set_point = &rect_set_point;
    new_rect->get_points = &rect_get_points;
    new_rect->get_point = &rect_get_point;
    new_rect->get_center = &rect_get_center;
    new_rect->get_width = &rect_get_width;
    new_rect->get_height = &rect_get_height;
    new_rect->get_area = &rect_get_area;
    new_rect->get_circ = &rect_get_circ;
    new_rect->rotate = &rect_rotate;
    new_rect->destroy = &rect_destroy;
    return new_rect;
}

/* Initializes the rectangle. Accepts four points a, b, c, d. Point a must be the top left corner and the rest are assigned in a clockwise direction */
int rect_set_points(Rectangle* self, Point* a, Point* b, Point* c, Point* d){
    if (point_get_x(a) != point_get_x(b)) {
        return -1;
    }
    if (point_get_y(b) != point_get_y(c)) {
        return -2;
    }
    if (point_get_x(c) != point_get_x(d)) {
        return -3;
    }
    if (point_get_y(d) != point_get_y(a)) {
        return -4;
    }
    self->__points[0] = a;
    self->__points[1] = b;
    self->__points[2] = c;
    self->__points[3] = d;
    return 0;
}

/* Sets the value for a single point. */
int rect_set_point(Rectangle* self, char point_letter, Point* point){
    switch (point_letter) {
        case 'a':
            if (self->__points[1] != NULL && point_get_y(self->__points[1]) != point_get_y(point)) {
                return -1;
            }
            if (self->__points[3] != NULL && point_get_x(self->__points[3])!=point_get_x(point)) {
                return -2;
            }
            self->__points[0] = point;
            break;
        case 'b':
            if (self->__points[0]!=NULL && point_get_y(self->__points[1]) != point_get_y(point)) {
                return -3;
            }
            if (self->__points[2]!=NULL && point_get_x(self->__points[2])!= point_get_x(point)) {
                return -4;
            }
            self->__points[1] = point;
            break;
        case 'c':
            if (self->__points[1]!=NULL && point_get_x(self->__points[1]) != point_get_x(point)) {
                return -5;
            }
            if (self->__points[3]!=NULL && point_get_y(self->__points[3])!= point_get_y(point)) {
                return -6;
            }
            self->__points[2] = point;
            break;
        case 'd':
            if (self->__points[0]!=NULL && point_get_x(self->__points[0]) != point_get_x(point)) {
                return -7;
            }
            if (self->__points[2]!=NULL && point_get_y(self->__points[2])!= point_get_y(point)) {
                return -8;
            }
            self->__points[3] = point;
            break;
        default:
            return -9;
    }
    return 0;
}

/* Get all 4 points. Returns array of points */
Point** rect_get_points(const Rectangle* rect){
    return rect->__points;
}

/* Get specific point */
Point* rect_get_point(const Rectangle* self, char point_letter){
    switch (point_letter) {
        case 'a':
            return self->__points[0];
            break;
        case 'b':
            return self->__points[1];
            break;
        case 'c':
            return self->__points[2];
            break;
        case 'd':
            return self->__points[3];
            break;
        default:
            return NULL;
    }
}

/* Calculates rectangle width */
int rect_get_width(const Rectangle* self){
    return point_get_x(self->__points[0]) - point_get_x(self->__points[3]);
}

/* Calculates rectangle height */
int rect_get_height(const Rectangle* self){
    return point_get_y(self->__points[0]) - point_get_y(self->__points[1]);
}

/* Finds the center point of a rectangle. Since points are integers if two or
 * all sides are odd lengts the center will be off. */
Point* rect_get_center(const Rectangle* self){
    int width_center = self->get_width(self) / 2;
    int height_center = self->get_height(self) / 2;
    Point *center_point = point_create();
    point_set_x(center_point, width_center);
    point_set_y(center_point, height_center);

    return center_point;
}

/* Calculates rectangle area */
int rect_get_area(const Rectangle* self){
    return self->get_width(self) * self->get_height(self);
}

/* Calculates rectangle circumference */
int rect_get_circ(const Rectangle* self){
    return 2 * (self->get_width(self) + self->get_height(self));
}

/* Rotates rectangle */
void rect_rotate(Rectangle* self){
    Point* temp = point_create();
    point_set_x(temp, point_get_x(self->__points[3]));
    point_set_y(temp, point_get_y(self->__points[3]));

    point_set_x(self->__points[3], point_get_x(self->__points[0]));
    point_set_y(self->__points[3], point_get_y(self->__points[0]));

    point_set_x(self->__points[0], point_get_x(self->__points[1]));
    point_set_y(self->__points[0], point_get_y(self->__points[1]));

    point_set_x(self->__points[1], point_get_x(self->__points[2]));
    point_set_y(self->__points[1], point_get_y(self->__points[2]));

    point_set_x(self->__points[2], point_get_x(temp));
    point_set_y(self->__points[2], point_get_y(temp));
}

void rect_destroy(Rectangle* self){
    for (int i = 0; i < 4; i++) {
        point_destroy(self->__points[i]);
    }

    free(self->__points);
    free(self);
}
