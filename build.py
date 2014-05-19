#!/usr/bin/env python

"""
This file serves as a very simple build script for 2d3.
"""

import os, fnmatch

# Third party libraries to link against
LIBRARIES = [
    "allegro",
    "allegro_main",
    "allegro_font",
    "allegro_ttf",
    "allegro_image",
    "allegro_primitives",
    "chipmunk"
]

# Includes
INCLUDES = [
    "./src/include/"
]

FILE_IGNORES = [
    "rtest.cpp"
]

def find_c_files():
    result = []
    for (path, folders, files) in os.walk("."):
        for fname in files:
            if any(map(lambda i: fnmatch.fnmatch(fname, i), FILE_IGNORES)):
                continue
            if fname.endswith(".cpp") or fname.endswith(".c"):
                result.append(os.path.join(path, fname))
    return result

def build():
    for f in find_c_files():
        print "Building object for %s" % f
        os.system(build_command(["ENABLE_DEBUG"]) + " %s" % f)

    print "Building library..."
    os.system("ar rvs lib2d3.a *.o")

    print "Cleaning up..."
    os.system("rm *.o")

def build_command(flags, debug=True):
    print "Attempting build..."
    base = "g++ -c "
    base += " ".join(["-I%s" % i for i in INCLUDES])
    base += " "
    base += " ".join(["-l%s" % i for i in LIBRARIES])
    base += " "
    base += " ".join(["-D%s" % i for i in flags])
    return base

if __name__ == "__main__":
    build()
