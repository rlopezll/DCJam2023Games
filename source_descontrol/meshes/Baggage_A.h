#ifndef _BAGGAGE_A_MESH_
#define _BAGGAGE_A_MESH_

#include <types.h>
#include "dcRender.h"

static SDC_VertexNormal Baggage_A_Vertices[] = {
    { 59, 56, 39, 0, 0, 4096, 0, 0 },
    { -59, 56, -39, 0, 0, 4096, 0, 0 },
    { -59, 56, 39, 0, 0, 4096, 0, 0 },
    { 59, 56, -39, 0, 0, 4096, 0, 0 },
    { -62, 38, -50, 0, 0, 0, -4096, 0 },
    { 62, 38, -50, 0, 0, 0, -4096, 0 },
    { 62, 20, -50, 0, 0, 0, -4096, 0 },
    { -62, 20, -50, 0, 0, 0, -4096, 0 },
    { -69, 38, -42, 0, -4096, 0, 0, 0 },
    { -69, 20, 42, 0, -4095, 0, 0, 0 },
    { -69, 38, 42, 0, -4095, 0, 0, 0 },
    { -69, 20, -42, 0, -4096, 0, 0, 0 },
    { -62, 20, 50, 0, 0, 0, 4096, 0 },
    { 62, 38, 50, 0, 0, 0, 4096, 0 },
    { -62, 38, 50, 0, 0, 0, 4096, 0 },
    { 62, 20, 50, 0, 0, 0, 4096, 0 },
    { 69, 38, -42, 0, 4096, 0, 0, 0 },
    { 69, 38, 42, 0, 4096, 0, 0, 0 },
    { 69, 20, 42, 0, 4096, 0, 0, 0 },
    { 69, 20, -42, 0, 4096, 0, 0, 0 },
    { 62, 20, -50, 0, 2562, -2032, -2465, 0 },
    { 69, 20, -42, 0, 2562, -2032, -2465, 0 },
    { 59, 3, -39, 0, 2562, -2032, -2465, 0 },
    { -59, 3, -39, 0, -2562, -2032, -2465, 0 },
    { -69, 20, -42, 0, -2562, -2032, -2465, 0 },
    { -62, 20, -50, 0, -2562, -2032, -2465, 0 },
    { 69, 20, 42, 0, 2562, -2032, 2465, 0 },
    { 62, 20, 50, 0, 2562, -2032, 2465, 0 },
    { 59, 3, 39, 0, 2562, -2032, 2465, 0 },
    { -59, 3, 39, 0, -2562, -2032, 2465, 0 },
    { -62, 20, 50, 0, -2562, -2032, 2465, 0 },
    { -69, 20, 42, 0, -2562, -2032, 2465, 0 },
    { 59, 56, -39, 0, 2562, 2032, -2465, 0 },
    { 69, 38, -42, 0, 2562, 2032, -2465, 0 },
    { 62, 38, -50, 0, 2562, 2032, -2465, 0 },
    { -59, 56, -39, 0, -2562, 2032, -2465, 0 },
    { -62, 38, -50, 0, -2562, 2032, -2465, 0 },
    { -69, 38, -42, 0, -2562, 2032, -2465, 0 },
    { 59, 56, 39, 0, 2562, 2032, 2465, 0 },
    { 62, 38, 50, 0, 2562, 2032, 2465, 0 },
    { 69, 38, 42, 0, 2562, 2032, 2465, 0 },
    { -59, 56, 39, 0, -2562, 2032, 2465, 0 },
    { -69, 38, 42, 0, -2562, 2032, 2465, 0 },
    { -62, 38, 50, 0, -2562, 2032, 2465, 0 },
    { 69, 20, 42, 0, 3525, -2085, 0, 0 },
    { 59, 3, -39, 0, 3525, -2085, 0, 0 },
    { 69, 20, -42, 0, 3525, -2085, 0, 0 },
    { 59, 3, 39, 0, 3525, -2085, 0, 0 },
    { -62, 20, 50, 0, 0, -2236, 3431, 0 },
    { 59, 3, 39, 0, 0, -2236, 3431, 0 },
    { 62, 20, 50, 0, 0, -2236, 3431, 0 },
    { -59, 3, 39, 0, 0, -2236, 3431, 0 },
    { -69, 20, 42, 0, -3525, -2085, 0, 0 },
    { -59, 3, -39, 0, -3525, -2085, 0, 0 },
    { -59, 3, 39, 0, -3525, -2085, 0, 0 },
    { -69, 20, -42, 0, -3525, -2085, 0, 0 },
    { 62, 20, -50, 0, 0, -2236, -3431, 0 },
    { -59, 3, -39, 0, 0, -2236, -3431, 0 },
    { -62, 20, -50, 0, 0, -2236, -3431, 0 },
    { 59, 3, -39, 0, 0, -2236, -3431, 0 },
    { -59, 56, -39, 0, 0, 2236, -3431, 0 },
    { 59, 56, -39, 0, 0, 2236, -3431, 0 },
    { 62, 38, -50, 0, 0, 2236, -3431, 0 },
    { -62, 38, -50, 0, 0, 2236, -3431, 0 },
    { -59, 56, 39, 0, -3525, 2085, 0, 0 },
    { -59, 56, -39, 0, -3525, 2085, 0, 0 },
    { -69, 38, -42, 0, -3525, 2085, 0, 0 },
    { -69, 38, 42, 0, -3525, 2085, 0, 0 },
    { -62, 38, 50, 0, 0, 2236, 3431, 0 },
    { 62, 38, 50, 0, 0, 2236, 3431, 0 },
    { -59, 56, 39, 0, 0, 2236, 3431, 0 },
    { 59, 56, 39, 0, 0, 2236, 3431, 0 },
    { 69, 38, 42, 0, 3525, 2085, 0, 0 },
    { 69, 38, -42, 0, 3525, 2085, 0, 0 },
    { 59, 56, 39, 0, 3525, 2085, 0, 0 },
    { 59, 56, -39, 0, 3525, 2085, 0, 0 },
    { -62, 38, -50, 0, -2951, 0, -2840, 0 },
    { -69, 20, -42, 0, -2951, 0, -2840, 0 },
    { -69, 38, -42, 0, -2951, 0, -2840, 0 },
    { -62, 20, -50, 0, -2951, 0, -2840, 0 },
    { 69, 38, -42, 0, 2951, 0, -2840, 0 },
    { 69, 20, -42, 0, 2951, 0, -2840, 0 },
    { 62, 38, -50, 0, 2951, 0, -2840, 0 },
    { 62, 20, -50, 0, 2951, 0, -2840, 0 },
    { -69, 38, 42, 0, -2951, 0, 2840, 0 },
    { -62, 20, 50, 0, -2951, 0, 2840, 0 },
    { -62, 38, 50, 0, -2951, 0, 2840, 0 },
    { -69, 20, 42, 0, -2951, 0, 2840, 0 },
    { 62, 38, 50, 0, 2951, 0, 2840, 0 },
    { 62, 20, 50, 0, 2951, 0, 2840, 0 },
    { 69, 38, 42, 0, 2951, 0, 2840, 0 },
    { 69, 20, 42, 0, 2951, 0, 2840, 0 },
    { -24, 36, 61, 0, -267, 4065, 421, 0 },
    { -16, 37, 50, 0, -435, 4072, 34, 0 },
    { -25, 37, 50, 0, -435, 4072, 34, 0 },
    { -12, 39, 52, 0, -126, 4027, 736, 0 },
    { -12, 39, 52, 0, 1571, 0, -3782, 0 },
    { -12, 20, 52, 0, 1571, 0, -3782, 0 },
    { -16, 37, 50, 0, 1571, 0, -3782, 0 },
    { -16, 21, 50, 0, 1571, 0, -3782, 0 },
    { -25, 37, 50, 0, -4081, 0, 342, 0 },
    { -24, 22, 61, 0, -4081, 0, 342, 0 },
    { -24, 36, 61, 0, -4081, 0, 342, 0 },
    { -25, 21, 50, 0, -4081, 0, 342, 0 },
    { 19, 36, 61, 0, 267, 4065, 421, 0 },
    { 6, 39, 52, 0, 126, 4027, 736, 0 },
    { 6, 39, 52, 0, 0, 0, -4096, 0 },
    { 6, 20, 52, 0, 0, 0, -4096, 0 },
    { -12, 39, 52, 0, 0, 0, -4096, 0 },
    { -12, 20, 52, 0, 0, 0, -4096, 0 },
    { 19, 36, 61, 0, 0, 0, 4096, 0 },
    { -24, 36, 61, 0, 0, 0, 4096, 0 },
    { -24, 22, 61, 0, 0, 0, 4096, 0 },
    { 19, 22, 61, 0, 0, 0, 4096, 0 },
    { 11, 37, 50, 0, 435, 4072, 34, 0 },
    { 20, 37, 50, 0, 435, 4072, 34, 0 },
    { 11, 21, 50, 0, -1572, 0, -3782, 0 },
    { 6, 39, 52, 0, -1572, 0, -3782, 0 },
    { 11, 37, 50, 0, -1572, 0, -3782, 0 },
    { 6, 20, 52, 0, -1572, 0, -3782, 0 },
    { 20, 37, 50, 0, 4081, 0, 342, 0 },
    { 19, 36, 61, 0, 4081, 0, 342, 0 },
    { 19, 22, 61, 0, 4081, 0, 342, 0 },
    { 20, 21, 50, 0, 4081, 0, 342, 0 }
};
static u_short Baggage_A_Indices[] = {
    0, 2, 1, 1, 3, 0, 4, 6, 5, 4, 7, 6, 8, 10, 9, 9, 11, 8, 12, 14, 13, 13, 15, 12, 16, 18, 17, 16, 19, 18, 20, 22, 21, 
    23, 25, 24, 26, 28, 27, 29, 31, 30, 32, 34, 33, 35, 37, 36, 38, 40, 39, 41, 43, 42, 44, 46, 45, 45, 47, 44, 48, 50, 49, 49, 51, 
    48, 52, 54, 53, 53, 55, 52, 56, 58, 57, 57, 59, 56, 60, 62, 61, 60, 63, 62, 64, 66, 65, 64, 67, 66, 68, 70, 69, 71, 69, 70, 72, 
    74, 73, 75, 73, 74, 76, 78, 77, 77, 79, 76, 80, 82, 81, 82, 83, 81, 84, 86, 85, 85, 87, 84, 88, 90, 89, 90, 91, 89, 92, 94, 93, 
    93, 95, 92, 96, 98, 97, 98, 99, 97, 100, 102, 101, 101, 103, 100, 104, 92, 95, 95, 105, 104, 106, 108, 107, 108, 109, 107, 110, 112, 111, 110, 113, 
    112, 105, 114, 104, 104, 114, 115, 116, 118, 117, 117, 119, 116, 120, 122, 121, 120, 123, 122
};
static SDC_Mesh3D Baggage_A_Mesh = {Baggage_A_Vertices, Baggage_A_Indices, NULL, 180, 124, POLIGON_VERTEX_NORMAL};
#endif