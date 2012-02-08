
#include <stdio.h>
#include <stdlib.h>

#include "new.h"
#include "point.h"
#include "vertex.h"

#define ok_point 1
#define ok_vertex 1

int main()
{
    Object * point = new(Point, 42, -42);
    Object * vertex = new(Vertex, 0, 1, 2);
    char	const *str;

    str = str(point);
    printf("point = %s\n", str);
    free((void*)str);
    str = str(vertex);
    printf("vertex = %s\n", str);
    free((void*)str);

    str = str(point);
    printf("point = %s\n", str);
    free((void*)str);
    str = str(vertex);
    printf("vertex = %s\n", str);
    free((void*)str);

    str = str(point);
    printf("point = %s\n", str);
    free((void*)str);
    str = str(vertex);
    printf("vertex = %s\n", str);
    free((void*)str);

    delete(point);
    delete(vertex);

    point = new(Point, 0, 0);
    vertex = new(Vertex, 0, -1, -2);

    str = str(point);
    printf("point = %s\n", str);
    free((void*)str);
    str = str(vertex);
    printf("vertex = %s\n", str);
    free((void*)str);

    delete(point);
    delete(vertex);

    return 0;
}
