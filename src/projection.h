
#include "vector.h"

point3 model_to_world_space();

point3 world_to_camera_space();

//
// NOTE: orthogonal projection (x,y,0) of vertices in screen space (after perspective distortion)
// results in perspective projection on the canvas.
//
point3 camera_to_screen_space(point3 p_camera, float nearClippingPlane)
{
    float perspective_divisor = nearClippingPlane / -p_camera.z();
    return point3(
        p_camera.x() / perspective_divisor,
        p_camera.y() / perspective_divisor,
        p_camera.z());
}

point3 screen_to_ndc_space(point3 p_screen, point3 canvas_lb, point3 canvas_rt)
{
    return point3(
        2 * p_screen.x() / (canvas_rt.x() - canvas_lb.x()) - (canvas_rt.x() - canvas_lb.x()) / (canvas_rt.x() - canvas_lb.x()),
        2 * p_screen.y() / (canvas_rt.y() - canvas_lb.y()) - (canvas_rt.y() + canvas_lb.y()) / (canvas_rt.y() + canvas_lb.y()),
        p_screen.z()); // camera.z
}

point3 ndc_to_raster_space(point3 p_ndc, float image_width, float image_height)
{
    return point3(
        (p_ndc.x() + 1) / 2 * image_width,
        (p_ndc.y() + 1) / 2 * image_height,
        -p_ndc.z()); // -camera.z
}