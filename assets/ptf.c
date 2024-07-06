/*
    James William Fletcher (github.com/mrbid)
        June 2024

    Converts ASCII PLY (.ply) file to C OpenGL buffers.
    
    This is specifically made for:
    esAux6.h: https://gist.github.com/mrbid/8563c765116f2dce3d4461adea15fdd1
    esAux7.h: ...
    
    - Auto detects if index buffer is GLubyte, GLushort or GLuint.
    - This is not particularly fast. Not intended for large files.
    - This version only exports PLY files with: index, vertex, color & normal
    - This works with the latest Blender (4.x) PLY exporter, which no longer
      starts the index array at 0,1,2.
    - Color buffer is now saved as GLubyte

    Compile: cc ptf4.c -lm -Ofast -o ptf
    
    Usage: ./ptf4 filename_noextension
        (loads filenames from the '../ply/' directory)
        (saves to the '../high/' directory)
    
    Example: ./ptf4 porygon
        (loads '../ply/porygon.ply' and outputs '../high/porygon.h' into the cwd)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_BUFF 1161326592 //387108864 //24194304 //6048576 //1048576

int main(int argc, char** argv)
{
    // start time
    time_t st = time(0);

    // ensure an input file is specified
    if(argc < 2)
    {
        printf("Please specify an input file.\n");
        return 0;
    }

    // take the input file name and strip any supplied extension
    char name[32] = {0};
    strcat(name, argv[1]);
    char* p = strstr(name, ".");
    if(p != NULL){*p = 0x00;}

    // generate the read file path (reads .ply files from a local `ply/` directory)
    char readfile[32] = {0};
    strcat(readfile, "ply/");
    strcat(readfile, name);
    strcat(readfile, ".ply");

    // pre-init our buffers
    char* vertex_array = calloc(1, MAX_BUFF);
    char* index_array = calloc(1, MAX_BUFF);
    char* normal_array = calloc(1, MAX_BUFF);
    char* color_array = calloc(1, MAX_BUFF);
    if(vertex_array == NULL || index_array == NULL || normal_array == NULL || color_array == NULL)
    {
        printf("Failed to allocate memory.\n");
        return 0;
    } 

    // open our ASCII PLY file for reading
    unsigned int numvert=0, numind=0, maxind=0;
    unsigned int mode = 0;
    printf("Open: %s\n", readfile);
    FILE* f = fopen(readfile, "r");
    while(f == NULL)
    {
        f = fopen(readfile, "r");
        sleep(1);
    }

    // do the conversion
    float pxl=99999.f, pyl=99999.f, pzl=99999.f;
    float pxh=-99999.f, pyh=-99999.f, pzh=-99999.f;
    char line[256];
    char add[256];
    while(fgets(line, 256, f) != NULL)
    {
        //printf("%s\n",line);
        if(strcmp(line, "end_header\n") == 0)
        {
            mode = 1;
            continue;
        }

        // load vertex, normal, color
        if(mode == 1)
        {
            float vx,vy,vz,nx,ny,nz;
            unsigned int r,g,b;
            if(sscanf(line, "%f %f %f %f %f %f %u %u %u", &vx, &vy, &vz, &nx, &ny, &nz, &r, &g, &b) == 9)
            {
                if(vx < pxl){pxl=vx;}
                else if(vx > pxh){pxh=vx;}

                if(vy < pyl){pyl=vy;}
                else if(vy > pyh){pyh=vy;}

                if(vz < pzl){pzl=vz;}
                else if(vz > pzh){pzh=vz;}

                sprintf(add, "%g,%g,%g,", vx, vy, vz);
                strcat(vertex_array, add);
                numvert++;

                sprintf(add, "%g,%g,%g,", nx, ny, nz);
                strcat(normal_array, add);

                sprintf(add, "%u,%u,%u,", r, g, b);
                strcat(color_array, add);
            }
            else
            {
                mode = 2;
            }
        }

        // load index
        if(mode == 2)
        {
            unsigned int n,x,y,z;
            if(sscanf(line, "%u %u %u %u", &n, &x, &y, &z) == 4)
            {
                char add[256];
                sprintf(add, "%u,%u,%u,", x, y, z);
                strcat(index_array, add);
                if(x > maxind){maxind = x;}
                if(y > maxind){maxind = y;}
                if(z > maxind){maxind = z;}
                numind += 3;
            }
        }
    }

    // compute model meta data (position & radius)
    const float pdx = pxh-pxl;
    const float pdy = pyh-pyl;
    const float pdz = pzh-pzl;
    const float px = pxl + (pdx/2.f);
    const float py = pyl + (pdy/2.f);
    const float pz = pzl + (pdz/2.f);
    float radius = pdx;
    if(pdy > radius){radius = pdy;}
    if(pdz > radius){radius = pdz;}
    radius /= 2.f;
    
    // close PLY file
    fclose(f);
    
    // remove trailing comma's
    vertex_array[strlen(vertex_array)-1] = 0x00;
    normal_array[strlen(normal_array)-1] = 0x00;
    index_array[strlen(index_array)-1] = 0x00;
    color_array[strlen(color_array)-1] = 0x00;

    // output the resultant file
    char outfile[256];
    sprintf(outfile, "high/%s.h", name);
    f = fopen(outfile, "w");
    while(f == NULL)
    {
        f = fopen(outfile, "w");
        sleep(1);
    }

    fprintf(f, "\n#ifndef %s_H\n#define %s_H\n\nGLfloat %s_vertices[] = {%s};\n", name, name, name, vertex_array);
    fprintf(f, "GLfloat %s_normals[] = {%s};\n", name, normal_array);
    fprintf(f, "GLubyte %s_colors[] = {%s};\n", name, color_array);
    
    if(maxind <= 255)
    {
        fprintf(f, "const GLubyte %s_indices[] = {%s};\nconst GLsizeiptr %s_numind = %u;\nconst GLsizeiptr %s_numvert = %u;\n\n", name, index_array, name, numind, name, numvert);
        printf("Output: %s.h (UBYTE)\n", name);
    }
    else if(maxind <= 65535)
    {
        fprintf(f, "const GLushort %s_indices[] = {%s};\nconst GLsizeiptr %s_numind = %u;\nconst GLsizeiptr %s_numvert = %u;\n\n", name, index_array, name, numind, name, numvert);
        printf("Output: %s.h (USHORT)\n", name);
    }
    else
    {
        fprintf(f, "const GLuint %s_indices[] = {%s};\nconst GLsizeiptr %s_numind = %u;\nconst GLsizeiptr %s_numvert = %u;\n\n", name, index_array, name, numind, name, numvert);
        printf("Output: %s.h (UINT)\n", name);
    }

    // fprintf(f, "const vec %s_wpos = (vec){%gf, %gf, %gf};\n", name, px, py, pz);
    // fprintf(f, "const float %s_wrad = %gf;\n\n", name, radius);

    fprintf(f, "void register_%s()\n", name);
    fprintf(f, "{\n");
    fprintf(f, "    esBind(GL_ARRAY_BUFFER, &esModelArray[esModelArray_index].vid, %s_vertices, sizeof(%s_vertices), GL_STATIC_DRAW);\n", name, name);
    fprintf(f, "    esBind(GL_ARRAY_BUFFER, &esModelArray[esModelArray_index].nid, %s_normals, sizeof(%s_normals), GL_STATIC_DRAW);\n", name, name);
    fprintf(f, "    esBind(GL_ARRAY_BUFFER, &esModelArray[esModelArray_index].cid, %s_colors, sizeof(%s_colors), GL_STATIC_DRAW);\n", name, name);
    fprintf(f, "    esBind(GL_ELEMENT_ARRAY_BUFFER, &esModelArray[esModelArray_index].iid, %s_indices, sizeof(%s_indices), GL_STATIC_DRAW);\n", name, name);
    
    if(maxind <= 255)       {fprintf(f, "    esModelArray[esModelArray_index].itp = GL_UNSIGNED_BYTE;\n");}
    else if(maxind <= 65535){fprintf(f, "    esModelArray[esModelArray_index].itp = GL_UNSIGNED_SHORT;\n");}
    else                    {fprintf(f, "    esModelArray[esModelArray_index].itp = GL_UNSIGNED_INT;\n");}
    
    fprintf(f, "    esModelArray[esModelArray_index].ni = %s_numind;\n", name);
    fprintf(f, "    esModelArray[esModelArray_index].nv = %s_numvert;\n", name);
    fprintf(f, "    esModelArray[esModelArray_index].pos = (vec){%g, %g, %g};\n", px, py, pz);
    fprintf(f, "    esModelArray[esModelArray_index].rad = %g;\n", radius);
    fprintf(f, "    esModelArray[esModelArray_index].rsq = %g;\n", radius*radius);

    fprintf(f, "    esModelArray[esModelArray_index].vertices = %s_vertices;\n", name);
    fprintf(f, "    esModelArray[esModelArray_index].normals = %s_normals;\n", name);
    fprintf(f, "    esModelArray[esModelArray_index].colors = %s_colors;\n", name);
    fprintf(f, "    esModelArray_index++;\n");
    fprintf(f, "}\n\n");

    fprintf(f, "#endif\n");

    fclose(f);
    const float mins = ((float)(time(0)-st))/60.f;
    if(mins > 0.001f){printf("Time Taken: %.2f mins\n", mins);}
    return 0;
}
