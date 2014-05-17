// ***************************************************************************
// map.cpp: the program
// Author: Jeff Roberts <jeffroberts1@gmail.com>
// ***************************************************************************


// ***************************************************************************
// Include section

// system
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include "resource.h"
#include <map>
#include <string>

using namespace std;

// ***************************************************************************
// Definitions section


class ImageResource : public Resource {
    private:
    public:
};


// ***************************************************************************
// Global Variable section


// ***************************************************************************
// Prototypes section


// ***************************************************************************
// Extern section


int main(int argc, char **argv) {
    int handle;
    ImageResource *rsrc;
    ResourceManager<ImageResource> imageManager;

    // Create a new managed resource
    handle = imageManager.addResource(new ImageResource());
    printf("handle is %d\n", handle);

    // Check it out
    rsrc = imageManager.getResource(handle);
    printf("rsrc ptr is %p\n", rsrc);
    printf("rsrc handle is %d\n", rsrc->getHandle());

    // Check on the manager
    printf("imageManager size is %d\n", imageManager.getCount());
    imageManager.releaseAll();
    printf("imageManager size is %d\n", imageManager.getCount());

    return 0;
}
