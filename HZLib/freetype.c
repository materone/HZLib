//
//  freetype.c
//  HZLib
//
//  Created by tony on 13-12-4.
//  Copyright (c) 2013年 tony. All rights reserved.
//
#include "freetype.h"

int extractHZFone(){
    printf("Conv it");
    return 0;
}


int ttfFont(int argc, char **argv)
{
    FT_Library library;
    FT_Face face;
    int error;
    int i, j, k, counter;
    unsigned char temp;
    unsigned int glyph_index;
    int char_index;
    int font_size;
    
    if (argc != 4)
    {
        printf("Usage: test filename font_size unicode\n");
        return 0;
    }
    
    char_index =  (int)strtol(argv[3], (char **)NULL, 16);;//atoi(argv[3]);
    font_size = atoi(argv[2]);
    
    error = FT_Init_FreeType(&library);
    if (error)
    {
        printf("can not init free type library!\n");
        return 0;
    }
    
    error = FT_New_Face(library, argv[1], 0, &face);
    if (error)
    {
        printf("create new face falied!\n");
        return 0;
    }
    
    error = FT_Set_Pixel_Sizes(face, 0, font_size);
    if (error)
    {
        printf("set font size error!\n");
        return 0;
    }
    
    
    printf("file family name %s\n", face->family_name);
    
    printf("file style name %s\n", face->style_name);
    
    printf("number of char %ld\n", face->num_glyphs);
    
    printf("number of fixed bitmap %d\n", face->num_fixed_sizes);
    
    printf("Char size %ld\n", face->size);
    
    //convert from ucs to index
    glyph_index = FT_Get_Char_Index( face, char_index );
    //error = FT_Load_Glyph(face, char_index, FT_LOAD_DEFAULT);
    error = FT_Load_Glyph(face, glyph_index, FT_LOAD_DEFAULT);
    if (error)
    {
        printf("Load char error!\n");
        return 0;
    }
    
    if (face->glyph->format != FT_GLYPH_FORMAT_BITMAP)
    {
        error = FT_Render_Glyph(face->glyph, FT_RENDER_MODE_MONO);
        if (error)
        {
            printf("render char failed!\n");
            return 0;
        }
    }
    
    printf("rows %d, width %d\n", face->glyph->bitmap.rows, face->glyph->bitmap.width);
    
    printf("pitch %d\n", face->glyph->bitmap.pitch);
    
    printf("bit_map_left %d bit_map_top %d\n", face->glyph->bitmap_left,face->glyph->bitmap_top);
    
    printf("width %ld height %ld\n", face->glyph->metrics.width, face->glyph->metrics.height);
    
    printf("%ld %ld %ld\n", face->glyph->metrics.horiBearingX, face->glyph->metrics.horiBearingY,face->glyph->metrics.horiAdvance);
    
    
    for (j = 0; j < (font_size * 26) / 32 - face->glyph->bitmap_top; j++)
    {
        for (i = 0; i < font_size; i++)
        {
            printf(" ");//("_");
        }
        printf("\n");
    }
    
    for (; j < face->glyph->bitmap.rows + (font_size * 26) / 32 - face->glyph->bitmap_top; j++)
    {
        for (i = 1; i <= face->glyph->bitmap_left; i++)
        {
            printf(" ");//("_");
        }
        
        for (k = 0; k < face->glyph->bitmap.pitch; k++)
        {
            temp = face->glyph->bitmap.buffer[face->glyph->bitmap.pitch*(j + face->glyph->bitmap_top - (font_size * 26) / 32) + k];
            for (counter = 0; counter < 8; counter++)
            {
                if (temp & 0x80)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");//("_");
                }
                temp <<= 1;
                i++;
                if (i > font_size)
                {
                    break;
                }
            }
        }
        /*
         for (; i <= font_size; i++)
         {
         printf("|");
         }
         */
        printf("\n");
    }
    
    for (; j < font_size; j++)
    {
        for (i = 0; i < font_size; i++)
        {
            printf(" ");//(" ")
        }
        printf("\n");
    }
    
    return 0;
}

