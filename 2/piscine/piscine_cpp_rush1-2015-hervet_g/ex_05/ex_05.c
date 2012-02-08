
#include <stdio.h>
#include <assert.h>

#include "array.h"
#include "int.h"
#include "new.h"


int main()
{
    Object* array = new(Array, 10, Int, 0);
    Object* it = begin(array);
    Object* it_end = end(array);

    setitem(array, 0, 12);
    setitem(array, 1, 13);
    while (gt(it, it_end))
    {
        printf("%s\n", str(getval(it)));
        incr(it);
    }

    delete(it);
    delete(it_end);
    delete(array);
    return 0;
}

