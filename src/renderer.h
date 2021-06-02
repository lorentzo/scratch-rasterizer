
#ifndef RENDERER_H
#define RENDERER_H

// Rasterizer headers.
#include "vector.h"

// Standard headers.
#include <vector>
#include <iostream> 

void render()
{

    // Ini frame buffer.
    const int frame_width = 512; 
    const int frame_height = 512; 
    std::vector<std::vector<color>> frame_buffer;
    for(int i = 0; i < frame_width; ++i)
    {
        std::vector<color> col;
        for(int j = 0; j < frame_height; ++j)
        {
            col.push_back(color(0.0, 0.0, 0.0));
            frame_buffer.push_back(col);
        }
    }

    // TODO: create algorithm/input which defines vertices in object space.
    // TODO: transform vertices to raster space.
    // Vertices in raster space.
    std::vector<vec3> vertices = 
    {
        vec3(100, 100, 0),
        vec3(200, 200, 0),
        vec3(300, 300, 0),
        vec3(400, 400, 0)
    };

    // Draw vertice.
    for (vec3 v : vertices)
    {
        frame_buffer[v.x()][v.y()] = color(0.9, 0.9, 0.9);
    }

    // Output image.
    std::cout << "P3\n" << frame_width << " " << frame_height << "\n255\n";
    for(int i = 0; i < frame_width; ++i)
    {
        for(int j = 0; j < frame_height; ++j)
        {
           std::cout << static_cast<int>(255 * frame_buffer[i][j].x()) << " "
                     << static_cast<int>(255 * frame_buffer[i][j].y()) << " "
                     << static_cast<int>(255 * frame_buffer[i][j].z()) << "\n";
        }
    }

}

#endif
