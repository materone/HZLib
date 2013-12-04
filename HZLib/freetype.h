//
//  freetype.h
//  HZLib
//
//  Created by tony on 13-12-4.
//  Copyright (c) 2013年 tony. All rights reserved.
//
#include <stdio.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#ifndef HZLib_freetype_h
#define HZLib_freetype_h

int extractHZFone();
int ttfFont(int argc, char **argv);

#endif
