#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <SOIL.H>
#include <OpenGL/gl.h>

static const char OPT_TGA = 't';
static const char OPT_BMP = 'b';
static const char OPT_DDS = 'd';

static int flag_mipmaps;
static int flag_invert_y;

static int verbose_flag;

static struct option long_options[] = {
    {"verbose", no_argument, &verbose_flag, 1},
    {"mipmaps", no_argument, &flag_mipmaps, 1},
    {"invert-y", no_argument, &flag_invert_y, 1},
    {"tga", required_argument, 0, OPT_TGA},
    {"bmp", required_argument, 0, OPT_BMP},
    {"dds", required_argument, 0, OPT_DDS},
    {0, 0, 0, 0}
};

/**
*/
int main(int argc, char** argv)
{
    int opt;
    int i;

    // Validate the source image
    printf("Source: %s\n", argv[1]);
    GLuint src = SOIL_load_OGL_texture(
            argv[1],
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            (flag_mipmaps ? SOIL_FLAG_MIPMAPS : 0) |
            (flag_invert_y ? SOIL_FLAG_INVERT_Y : 0)
            );

    while ((opt = getopt_long_only(argc, argv, "", long_options, &i)) != -1)
    {
        switch (opt)
        {
            case OPT_TGA:
                printf("Creating TGA %s...\n", optarg); 
                break;

            case OPT_BMP:
                printf("Creating BMP %s...\n", optarg); 
                break;

            case OPT_DDS:
                printf("Creating DDS %s...\n", optarg);
                break;
        }
    }

    exit(0); 
}
