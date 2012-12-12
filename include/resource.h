// ***************************************************************************
// resource.h: resource&management class/template
// Author: Jeff Roberts <jeffroberts1@gmail.com>
// ***************************************************************************
#ifndef RESOURCE_H_
#define RESOURCE_H_

// ***************************************************************************
// Include section
#include <map>
#include <cstring>

// ***************************************************************************
// Definitions section
class Resource {
    private:
        int handle;

    public:
        char *filename; // must be exposed for interation.. better way?

        Resource() {
            handle = 0;
            filename = NULL;
        }

        int getHandle() { return handle; }
        char *getFilename() { return filename; }

        void setHandle(int h) { handle = h; }
};

template <class T> class ResourceManager {
  private:
    std::map<int, T *> resources;
    int handleAt;

  public:
    ResourceManager() {
        handleAt = 1;
    }

    int getCount() { return resources.size(); }

    int addResource(T *rsrc) {
        rsrc->setHandle(handleAt);
        resources[handleAt] = rsrc;
        handleAt += 1;
        return rsrc->getHandle();
    }

    T *getResource(int handle) { return resources[handle]; }

    T *getResource(char *filename) {
        char *name;
        typename std::map<int, T*>::iterator i;

        for (i = resources.begin() ; i != resources.end(); ++i) {
            name = i->second->filename;
            if (!name) continue;
            if (!std::strcmp(name, filename)) return i->second;
        }
        return NULL;
    }

    void releaseAll() {
        resources.clear();
        handleAt = 1;
    }
};

// ***************************************************************************
// Global Variable section


// ***************************************************************************
// Prototypes section


// ***************************************************************************
// Extern section


#endif
