#include <stdlib.h>
#include "point.h"

struct Point {
    int x;
    int y;
};

struct Point* point_create(){
  struct Point* new_point = calloc(1, sizeof(struct Point));
  return new_point;
};

void point_destroy(Point *point){
    free(point);
};

int point_get_x(Point *point) {
    return point->x;
};

int point_get_y(Point *point){
    return point->y;
};

void point_set_x(Point *point, int x){
    point->x = x;
};

void point_set_y(Point *point, int y){
    point->y = y;
};

void point_move(Point *point, int dx, int dy){
    point->x = point->x + dx;
    point->y = point->y + dy;
}
