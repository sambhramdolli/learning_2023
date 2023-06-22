#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

void calculateVolumeAndSurfaceArea(struct Box* box) {
    double volume = box->length * box->width * box->height;
    double surfaceArea = 2 * (box->length * box->width + box->width * box->height + box->height * box->length);
    
    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surfaceArea);
}

int main() {
    struct Box myBox;
    struct Box* boxPtr = &myBox;
    
    (*boxPtr).length = 5.0;
    (*boxPtr).width = 3.0;
    (*boxPtr).height = 2.0;
    
    calculateVolumeAndSurfaceArea(boxPtr);
    
    boxPtr->length = 10.0;
    boxPtr->width = 7.0;
    boxPtr->height = 4.0;
    
    calculateVolumeAndSurfaceArea(boxPtr);
    
    return 0;
}
