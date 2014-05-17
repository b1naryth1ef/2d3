#!/usr/bin/env python

"""
This file serves as a very simple build script for 2d3.
"""

import os, fnmatch

LIBRARIES = [
    "allegro",
    "allegro_main",
    "allegro_font",
    "allegro_ttf",
    "allegro_image",
    "allegro_primitives",
    "chipmunk"
]

INCLUDES = [
    "./src/include/"
]

FILE_IGNORES = [
    "rtest.cpp"
]

FLAGS = [
    "ENABLE_DEBUG"
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

def build(libs, fs, incl,flags, output, debug=True):
    print "Attempting build..."
    base = "g++"
    base += (" -g " if debug else " ")
    base += " ".join(fs)
    base += " -o %s " % output
    base += " ".join(["-I%s" % i for i in incl])
    base += " "
    base += " ".join(["-l%s" % i for i in libs])
    base += " "
    base += " ".join(["-D%s" % i for i in flags])
    if os.system(base) == 0:
        print "Build Finished!"
    else:
        print "Build Failed!"

if __name__ == "__main__":
    build(LIBRARIES, find_c_files(), INCLUDES, FLAGS, "game")