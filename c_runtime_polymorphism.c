#include <stdio.h>

// Define the base structure
typedef struct {
    void (*print)(void);
} Shape;

// Define the derived structures
typedef struct {
    Shape base;
    int width;
    int height;
} Rectangle;

typedef struct {
    Shape base;
    int radius;
} Circle;

// Define the print functions for each derived structure
void printRectangle(Rectangle* rect) {
    printf("Rectangle: width = %d, height = %d\n", rect->width, rect->height);
}

void printCircle(Circle* circle) {
    printf("Circle: radius = %d\n", circle->radius);
}

int main() {
    // Create instances of the derived structures
    Rectangle rect = { .base.print = (void (*)(void))printRectangle, .width = 5, .height = 3 };
    Circle circle = { .base.print = (void (*)(void))printCircle, .radius = 2 };

    // Call the print function for each instance
    rect.base.print();
    circle.base.print();

    return 0;
}
