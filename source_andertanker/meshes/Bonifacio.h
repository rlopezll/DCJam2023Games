#ifndef _BONIFACIO_MESH_
#define _BONIFACIO_MESH_

#include <types.h>
#include "dcRender.h"

static SDC_VertexTexturedNormal Bonifacio_Vertices[] = {
    { 8, 19, -5, 0, 0, -4095, -68, 0, 12, 7 },
    { 0, -50, -1, 0, 0, -4057, -558, 0, 11, 2 },
    { -8, 19, -5, 0, 0, -4095, -68, 0, 10, 7 },
    { 0, -24, -2, 0, 0, -4096, 0, 0, 3, 15 },
    { 34, -31, -2, 0, 0, -4096, 0, 0, 6, 15 },
    { -34, -31, -2, 0, 0, -4095, 0, 0, 0, 15 },
    { 0, -50, -1, 0, 4093, 0, -135, 0, 13, 3 },
    { 8, 19, -5, 0, 4093, 0, -135, 0, 13, 3 },
    { 8, 19, 3, 0, 4093, 0, -135, 0, 13, 3 },
    { -34, -31, -2, 0, -4020, 0, 784, 0, 8, 3 },
    { -41, -69, -2, 0, -4020, 0, 784, 0, 9, 3 },
    { -41, -69, 0, 0, -4020, 0, 784, 0, 9, 3 },
    { -34, -31, 0, 0, -4020, 0, 784, 0, 8, 3 },
    { 0, -24, -2, 0, -892, 0, 3997, 0, 7, 3 },
    { -34, -31, -2, 0, -892, 0, 3997, 0, 8, 3 },
    { -34, -31, 0, 0, -892, 0, 3997, 0, 8, 3 },
    { 0, -24, 0, 0, -892, 0, 3997, 0, 7, 3 },
    { 34, -31, -2, 0, 892, 0, 3997, 0, 13, 3 },
    { 0, -24, -2, 0, 892, 0, 3997, 0, 14, 3 },
    { 0, -24, 0, 0, 892, 0, 3997, 0, 14, 3 },
    { 34, -31, 0, 0, 892, 0, 3997, 0, 13, 3 },
    { 41, -69, -2, 0, 4020, 0, 784, 0, 12, 3 },
    { 34, -31, -2, 0, 4020, 0, 784, 0, 13, 3 },
    { 34, -31, 0, 0, 4020, 0, 784, 0, 13, 3 },
    { 41, -69, 0, 0, 4020, 0, 784, 0, 12, 3 },
    { 30, -102, -2, 0, 3893, 0, -1270, 0, 11, 3 },
    { 41, -69, -2, 0, 3893, 0, -1270, 0, 12, 3 },
    { 41, -69, 0, 0, 3893, 0, -1270, 0, 12, 3 },
    { 30, -102, 0, 0, 3893, 0, -1270, 0, 11, 3 },
    { 0, -113, -2, 0, 1327, 0, -3874, 0, 11, 3 },
    { 30, -102, -2, 0, 1327, 0, -3874, 0, 11, 3 },
    { 30, -102, 0, 0, 1327, 0, -3874, 0, 11, 3 },
    { 0, -113, 0, 0, 1327, 0, -3874, 0, 11, 3 },
    { -30, -102, -2, 0, -1327, 0, -3874, 0, 10, 3 },
    { 0, -113, -2, 0, -1327, 0, -3874, 0, 11, 3 },
    { 0, -113, 0, 0, -1327, 0, -3874, 0, 11, 3 },
    { -30, -102, 0, 0, -1327, 0, -3874, 0, 10, 3 },
    { -41, -69, -2, 0, -3893, 0, -1270, 0, 9, 3 },
    { -30, -102, -2, 0, -3893, 0, -1270, 0, 10, 3 },
    { -30, -102, 0, 0, -3893, 0, -1270, 0, 10, 3 },
    { -41, -69, 0, 0, -3893, 0, -1270, 0, 9, 3 },
    { -8, 19, -5, 0, -4093, 0, -135, 0, 12, 3 },
    { 0, -50, -1, 0, -4093, 0, -135, 0, 11, 3 },
    { -8, 19, 3, 0, -4093, 0, -135, 0, 12, 3 },
    { -8, 19, 3, 0, 0, 4095, -68, 0, 10, 7 },
    { 0, -50, -1, 0, 0, 4095, -68, 0, 11, 2 },
    { 8, 19, 3, 0, 0, 4095, -68, 0, 12, 7 },
    { 34, -31, 0, 0, 0, 4096, 0, 0, 14, 1 },
    { 0, -24, 0, 0, 0, 4096, 0, 0, 11, 2 },
    { -34, -31, 0, 0, 0, 4096, 0, 0, 7, 1 },
    { 0, -113, 0, 0, 0, 4096, 0, 0, 11, 15 },
    { -34, -31, 0, 0, 0, 4096, 0, 0, 8, 8 },
    { -30, -102, 0, 0, 0, 4096, 0, 0, 8, 15 },
    { -63, -47, -7, 0, 0, -4095, 0, 0, 9, 11 },
    { -56, -57, -7, 0, 0, -4096, 0, 0, 9, 10 },
    { -74, -65, -7, 0, 0, -4096, 0, 0, 8, 10 },
    { -67, -73, -7, 0, 0, -4095, 0, 0, 9, 10 },
    { 0, -74, -7, 0, 0, -4096, 0, 0, 11, 10 },
    { 0, -58, -7, 0, 0, -4096, 0, 0, 10, 10 },
    { 19, -79, -7, 0, 0, -4096, 0, 0, 11, 10 },
    { -19, -79, -7, 0, 0, -4095, 0, 0, 10, 10 },
    { 0, -58, -7, 0, 0, -4096, 0, 0, 10, 10 },
    { -19, -79, -7, 0, 0, -4096, 0, 0, 10, 10 },
    { -28, -52, -7, 0, 0, -4095, 0, 0, 10, 10 },
    { -44, -56, -7, 0, 0, -4096, 0, 0, 10, 10 },
    { 28, -52, -7, 0, 0, -4095, 0, 0, 12, 10 },
    { 44, -56, -7, 0, 0, -4095, 0, 0, 12, 10 },
    { 19, -79, -7, 0, 0, -4096, 0, 0, 11, 10 },
    { 44, -56, -7, 0, 0, -4096, 0, 0, 12, 10 },
    { 42, -38, -7, 0, 0, -4095, 0, 0, 12, 11 },
    { -42, -38, -7, 0, 0, -4095, 0, 0, 9, 11 },
    { 63, -47, -7, 0, 0, -4096, 0, 0, 13, 11 },
    { 56, -57, -7, 0, 0, -4096, 0, 0, 13, 10 },
    { 74, -65, -7, 0, 0, -4096, 0, 0, 13, 10 },
    { 67, -73, -7, 0, 0, -4095, 0, 0, 13, 10 },
    { -64, -85, -7, 0, 0, -4095, 0, 0, 9, 9 },
    { 64, -85, -7, 0, 0, -4096, 0, 0, 13, 9 },
    { -67, -73, -5, 0, 0, 4095, 0, 0, 9, 10 },
    { -56, -57, -5, 0, 0, 4096, 0, 0, 9, 10 },
    { -74, -65, -5, 0, 0, 4096, 0, 0, 8, 10 },
    { -63, -47, -5, 0, 0, 4095, 0, 0, 9, 11 },
    { 0, -58, -5, 0, 0, 4096, 0, 0, 11, 10 },
    { 0, -74, -5, 0, 0, 4096, 0, 0, 11, 10 },
    { 19, -79, -5, 0, 0, 4096, 0, 0, 11, 10 },
    { 0, -58, -5, 0, 0, 4096, 0, 0, 11, 10 },
    { -19, -79, -5, 0, 0, 4095, 0, 0, 10, 10 },
    { -19, -79, -5, 0, 0, 4096, 0, 0, 10, 10 },
    { -28, -52, -5, 0, 0, 4096, 0, 0, 10, 10 },
    { -44, -56, -5, 0, 0, 4096, 0, 0, 9, 10 },
    { 19, -79, -5, 0, 0, 4096, 0, 0, 11, 10 },
    { 28, -52, -5, 0, 0, 4095, 0, 0, 12, 10 },
    { 44, -56, -7, 0, 0, 4095, 0, 0, 12, 10 },
    { 44, -56, -5, 0, 0, 4096, 0, 0, 12, 10 },
    { 42, -38, -5, 0, 0, 4095, 0, 0, 12, 11 },
    { -42, -38, -5, 0, 0, 4095, 0, 0, 9, 11 },
    { 63, -47, -5, 0, 0, 4096, 0, 0, 13, 11 },
    { 56, -57, -5, 0, 0, 4096, 0, 0, 13, 10 },
    { 74, -65, -5, 0, 0, 4096, 0, 0, 13, 10 },
    { 67, -73, -5, 0, 0, 4095, 0, 0, 13, 10 },
    { -64, -85, -5, 0, 0, 4095, 0, 0, 9, 9 },
    { 64, -85, -5, 0, 0, 4096, 0, 0, 13, 9 },
    { -24, -92, -7, 0, 0, -4096, 0, 0, 3, 5 },
    { -6, -99, -7, 0, 0, -4096, 0, 0, 5, 4 },
    { -36, -106, -7, 0, 0, -4096, 0, 0, 1, 3 },
    { 31, -94, -7, 0, 0, -4096, 0, 0, 2, 2 },
    { 5, -110, -7, 0, 0, -4096, 0, 0, 5, 4 },
    { 12, -93, -7, 0, 0, -4096, 0, 0, 4, 2 },
    { -26, -123, -5, 0, 0, 4096, 0, 0, 11, 12 },
    { -8, -118, -5, 0, 0, 4096, 0, 0, 11, 14 },
    { -36, -106, -5, 0, 0, 4096, 0, 0, 12, 12 },
    { 19, -123, -5, 0, 0, 4096, 0, 0, 11, 13 },
    { 36, -113, -5, 0, 0, 4096, 0, 0, 11, 14 },
    { 5, -111, -5, 0, 0, 4096, 0, 0, 11, 12 },
    { 19, -109, -9, 0, 0, -4096, 0, 0, 9, 9 },
    { 16, -103, -9, 0, 0, -4096, 0, 0, 9, 9 },
    { 22, -103, -9, 0, 0, -4096, 0, 0, 10, 9 },
    { -19, -109, -9, 0, 0, -4096, 0, 0, 9, 9 },
    { -22, -103, -9, 0, 0, -4096, 0, 0, 9, 9 },
    { -16, -103, -9, 0, 0, -4096, 0, 0, 10, 9 },
    { 30, -102, 0, 0, 0, 4096, 0, 0, 13, 15 },
    { 41, -69, 0, 0, 0, 4096, 0, 0, 14, 12 },
    { 34, -31, 0, 0, 0, 4096, 0, 0, 14, 8 },
    { -41, -69, 0, 0, 0, 4096, 0, 0, 7, 12 },
    { 30, -102, -2, 0, 0, -4096, 0, 0, 6, 9 },
    { -30, -102, -2, 0, 0, -4096, 0, 0, 1, 9 },
    { -41, -69, -2, 0, 0, -4096, 0, 0, 0, 12 },
    { 41, -69, -2, 0, 0, -4096, 0, 0, 7, 12 },
    { 0, -113, -2, 0, 0, -4096, 0, 0, 3, 8 },
    { -8, -118, -7, 0, 0, -4096, 0, 0, 5, 2 },
    { -26, -123, -7, 0, 0, -4096, 0, 0, 3, 2 },
    { 36, -113, -7, 0, 0, -4096, 0, 0, 2, 4 },
    { 19, -123, -7, 0, 0, -4096, 0, 0, 4, 6 },
    { 31, -94, -5, 0, 0, 4096, 0, 0, 13, 14 },
    { 12, -93, -5, 0, 0, 4096, 0, 0, 13, 12 },
    { -6, -99, -5, 0, 0, 4096, 0, 0, 12, 14 },
    { -24, -92, -5, 0, 0, 4096, 0, 0, 13, 12 }
};
static u_short Bonifacio_Indices[] = {
    0, 2, 1, 3, 5, 4, 6, 8, 7, 9, 11, 10, 9, 12, 11, 13, 15, 14, 13, 16, 15, 17, 19, 18, 17, 20, 19, 21, 23, 22, 21, 24, 23, 
    25, 27, 26, 25, 28, 27, 29, 31, 30, 29, 32, 31, 33, 35, 34, 33, 36, 35, 37, 39, 38, 37, 40, 39, 41, 43, 42, 44, 46, 45, 47, 49, 
    48, 50, 52, 51, 53, 55, 54, 55, 56, 54, 57, 59, 58, 57, 61, 60, 62, 61, 63, 63, 64, 62, 65, 67, 66, 65, 58, 67, 68, 69, 65, 64, 
    63, 70, 68, 72, 71, 71, 69, 68, 64, 70, 53, 53, 54, 64, 71, 72, 73, 73, 72, 74, 56, 55, 75, 73, 74, 76, 77, 79, 78, 78, 79, 80, 
    81, 83, 82, 84, 82, 85, 86, 88, 87, 87, 84, 86, 81, 90, 89, 89, 90, 91, 91, 90, 92, 90, 93, 92, 88, 94, 87, 95, 96, 92, 92, 93, 
    95, 80, 94, 88, 88, 78, 80, 97, 98, 96, 96, 95, 97, 77, 99, 79, 97, 100, 98, 101, 103, 102, 104, 106, 105, 107, 109, 108, 110, 112, 111, 113, 
    115, 114, 116, 118, 117, 119, 121, 120, 51, 52, 122, 50, 121, 119, 50, 51, 121, 123, 125, 124, 123, 126, 125, 123, 124, 127, 125, 126, 4, 4, 5, 125, 
    128, 103, 129, 102, 103, 128, 130, 105, 131, 104, 105, 130, 111, 112, 132, 132, 112, 133, 108, 109, 134, 134, 109, 135
};
static SDC_Mesh3D Bonifacio_Mesh = {Bonifacio_Vertices, Bonifacio_Indices, NULL, 249, 136, POLIGON_VERTEX_TEXTURED_NORMAL};
#endif