#ifndef _BAGGAGE_E_MESH_
#define _BAGGAGE_E_MESH_

#include <types.h>
#include "dcRender.h"

static SDC_VertexNormal Baggage_E_Vertices[] = {
    { 71, 36, 14, 0, 3846, 127, 1401, 0 },
    { 55, 11, 35, 0, 1996, 68, 3575, 0 },
    { 72, 11, 14, 0, 3861, 127, 1360, 0 },
    { 54, 37, 35, 0, 1936, 66, 3608, 0 },
    { 72, 11, -14, 0, 3861, 127, -1360, 0 },
    { 71, 36, -14, 0, 3846, 127, -1401, 0 },
    { 55, 11, -35, 0, 1996, 68, -3575, 0 },
    { 54, 37, -35, 0, 1936, 66, -3608, 0 },
    { 26, 11, -39, 0, -247, -9, -4088, 0 },
    { 25, 36, -39, 0, -251, -9, -4088, 0 },
    { 7, 34, -34, 0, -1421, -50, -3840, 0 },
    { 7, 11, -34, 0, -1424, -50, -3840, 0 },
    { -15, 33, -22, 0, -1472, -51, -3821, 0 },
    { -14, 11, -22, 0, -1468, -51, -3823, 0 },
    { -37, 31, -17, 0, -545, -18, -4059, 0 },
    { -36, 11, -17, 0, -546, -19, -4059, 0 },
    { -72, 11, -16, 0, -1226, -45, -3907, 0 },
    { -73, 29, -16, 0, -1252, -46, -3899, 0 },
    { -85, 11, -7, 0, -3627, -134, -1897, 0 },
    { -85, 29, -7, 0, -3637, -135, -1877, 0 },
    { -85, 29, 7, 0, -3637, -135, 1877, 0 },
    { -85, 11, 7, 0, -3627, -134, 1897, 0 },
    { -73, 29, 16, 0, -1252, -46, 3899, 0 },
    { -72, 11, 16, 0, -1226, -45, 3907, 0 },
    { -37, 31, 17, 0, -545, -18, 4059, 0 },
    { -36, 11, 17, 0, -546, -19, 4059, 0 },
    { -14, 11, 22, 0, -1468, -51, 3823, 0 },
    { -15, 33, 22, 0, -1472, -51, 3821, 0 },
    { 7, 11, 34, 0, -1424, -50, 3840, 0 },
    { 7, 34, 34, 0, -1421, -50, 3840, 0 },
    { 26, 11, 39, 0, -247, -9, 4088, 0 },
    { 25, 36, 39, 0, -251, -9, 4088, 0 },
    { -36, 38, -9, 0, -270, 4087, 0, 0 },
    { -71, 36, 10, 0, -169, 4092, 0, 0 },
    { -36, 38, 9, 0, -270, 4087, 0, 0 },
    { -71, 36, -10, 0, -169, 4092, 0, 0 },
    { -13, 40, -16, 0, -332, 4082, 0, 0 },
    { -13, 40, 16, 0, -332, 4082, 0, 0 },
    { 8, 42, 27, 0, -335, 4082, 0, 0 },
    { 8, 42, -27, 0, -335, 4082, 0, 0 },
    { 26, 43, -32, 0, -266, 4087, 0, 0 },
    { 26, 43, 32, 0, -266, 4087, 0, 0 },
    { 52, 44, 29, 0, 1, 4095, 0, 0 },
    { 52, 44, -29, 0, 1, 4095, 0, 0 },
    { 65, 43, -12, 0, 492, 4066, 0, 0 },
    { 65, 43, 12, 0, 492, 4066, 0, 0 },
    { -79, 36, -4, 0, -166, 4092, 0, 0 },
    { -79, 36, 4, 0, -166, 4092, 0, 0 },
    { 71, 36, 14, 0, 2899, 2749, 898, 0 },
    { 71, 36, -14, 0, 2899, 2749, -898, 0 },
    { 65, 43, -12, 0, 2877, 2741, -989, 0 },
    { 65, 43, 12, 0, 2877, 2741, 989, 0 },
    { 52, 44, -29, 0, 1530, 2833, -2530, 0 },
    { 54, 37, -35, 0, 1368, 2846, -2608, 0 },
    { 25, 36, -39, 0, -396, 2824, -2940, 0 },
    { 26, 43, -32, 0, -369, 2823, -2944, 0 },
    { 7, 34, -34, 0, -1248, 2810, -2705, 0 },
    { 8, 42, -27, 0, -1246, 2810, -2706, 0 },
    { -15, 33, -22, 0, -1268, 2834, -2671, 0 },
    { -13, 40, -16, 0, -1271, 2833, -2670, 0 },
    { -37, 31, -17, 0, -549, 2876, -2863, 0 },
    { -36, 38, -9, 0, -553, 2876, -2862, 0 },
    { -71, 36, -10, 0, -990, 2853, -2766, 0 },
    { -73, 29, -16, 0, -979, 2853, -2769, 0 },
    { -79, 36, -4, 0, -2650, 2834, -1310, 0 },
    { -85, 29, -7, 0, -2641, 2835, -1328, 0 },
    { -85, 29, 7, 0, -2641, 2835, 1328, 0 },
    { -79, 36, 4, 0, -2650, 2834, 1310, 0 },
    { -73, 29, 16, 0, -979, 2854, 2769, 0 },
    { -71, 36, 10, 0, -990, 2853, 2766, 0 },
    { -37, 31, 17, 0, -549, 2876, 2863, 0 },
    { -36, 38, 9, 0, -553, 2876, 2862, 0 },
    { -15, 33, 22, 0, -1268, 2834, 2671, 0 },
    { -13, 40, 16, 0, -1271, 2833, 2670, 0 },
    { 8, 42, 27, 0, -1246, 2810, 2706, 0 },
    { 7, 34, 34, 0, -1248, 2810, 2705, 0 },
    { 25, 36, 39, 0, -396, 2824, 2940, 0 },
    { 26, 43, 32, 0, -369, 2823, 2944, 0 },
    { 52, 44, 29, 0, 1530, 2833, 2530, 0 },
    { 54, 37, 35, 0, 1368, 2846, 2608, 0 },
    { -48, 25, 16, 0, -170, 4092, -46, 0 },
    { -61, 25, 33, 0, -170, 4092, -46, 0 },
    { -47, 26, 29, 0, -131, 4089, 184, 0 },
    { -64, 25, 15, 0, -170, 4092, -46, 0 },
    { -47, 26, 29, 0, 4070, 0, -454, 0 },
    { -48, 15, 16, 0, 4070, 0, -454, 0 },
    { -48, 25, 16, 0, 4070, 0, -454, 0 },
    { -47, 14, 29, 0, 4070, 0, -454, 0 },
    { -61, 25, 33, 0, -4033, 0, 712, 0 },
    { -64, 25, 15, 0, -4033, 0, 712, 0 },
    { -64, 15, 15, 0, -4033, 0, 712, 0 },
    { -61, 15, 33, 0, -4033, 0, 712, 0 },
    { -5, 25, 54, 0, -99, 4077, 373, 0 },
    { -57, 25, 40, 0, -99, 4077, 373, 0 },
    { -9, 26, 39, 0, 25, 4089, 222, 0 },
    { -9, 14, 39, 0, 1060, 0, -3956, 0 },
    { -47, 26, 29, 0, 1060, 0, -3956, 0 },
    { -9, 26, 39, 0, 1060, 0, -3956, 0 },
    { -47, 14, 29, 0, 1060, 0, -3956, 0 },
    { -57, 25, 40, 0, -1060, 0, 3956, 0 },
    { -5, 15, 54, 0, -1060, 0, 3956, 0 },
    { -5, 25, 54, 0, -1060, 0, 3956, 0 },
    { -57, 15, 40, 0, -1060, 0, 3956, 0 },
    { 1, 25, 50, 0, 175, 4092, 41, 0 },
    { -1, 25, 28, 0, 175, 4092, 41, 0 },
    { 12, 25, 34, 0, 175, 4092, 41, 0 },
    { -1, 25, 28, 0, -3370, 0, -2328, 0 },
    { -9, 14, 39, 0, -3370, 0, -2328, 0 },
    { -9, 26, 39, 0, -3370, 0, -2328, 0 },
    { -1, 15, 28, 0, -3370, 0, -2328, 0 },
    { 12, 25, 34, 0, 3300, 0, 2425, 0 },
    { 1, 25, 50, 0, 3300, 0, 2425, 0 },
    { 1, 15, 50, 0, 3300, 0, 2425, 0 },
    { 12, 15, 34, 0, 3300, 0, 2425, 0 },
    { -61, 25, 33, 0, -309, 4080, 178, 0 },
    { -57, 25, 40, 0, -309, 4080, 178, 0 },
    { -47, 26, 29, 0, -309, 4080, 178, 0 },
    { -5, 25, 54, 0, 178, 4080, 309, 0 },
    { 1, 25, 50, 0, 178, 4080, 309, 0 },
    { -9, 26, 39, 0, 178, 4080, 309, 0 },
    { -57, 25, 40, 0, -3547, 0, 2048, 0 },
    { -61, 25, 33, 0, -3547, 0, 2048, 0 },
    { -61, 15, 33, 0, -3547, 0, 2048, 0 },
    { -57, 15, 40, 0, -3547, 0, 2048, 0 },
    { -5, 25, 54, 0, 2048, 0, 3547, 0 },
    { 1, 15, 50, 0, 2048, 0, 3547, 0 },
    { 1, 25, 50, 0, 2048, 0, 3547, 0 },
    { -5, 15, 54, 0, 2048, 0, 3547, 0 }
};
static u_short Baggage_E_Indices[] = {
    0, 2, 1, 1, 3, 0, 0, 5, 4, 4, 2, 0, 5, 7, 6, 6, 4, 5, 7, 9, 8, 8, 6, 7, 10, 8, 9, 10, 11, 8, 12, 11, 10, 
    12, 13, 11, 14, 13, 12, 14, 15, 13, 14, 17, 16, 16, 15, 14, 17, 19, 18, 18, 16, 17, 20, 18, 19, 20, 21, 18, 22, 21, 20, 22, 23, 
    21, 24, 23, 22, 24, 25, 23, 24, 27, 26, 26, 25, 24, 27, 29, 28, 28, 26, 27, 29, 31, 30, 30, 28, 29, 3, 30, 31, 3, 1, 30, 32, 
    34, 33, 33, 35, 32, 34, 32, 36, 36, 37, 34, 38, 37, 39, 37, 36, 39, 38, 39, 40, 40, 41, 38, 40, 42, 41, 42, 40, 43, 44, 45, 42, 
    43, 44, 42, 33, 47, 46, 46, 35, 33, 48, 50, 49, 48, 51, 50, 52, 49, 50, 49, 52, 53, 52, 55, 54, 54, 53, 52, 55, 57, 56, 56, 54, 
    55, 57, 59, 58, 58, 56, 57, 59, 61, 60, 60, 58, 59, 62, 60, 61, 60, 62, 63, 62, 64, 63, 63, 64, 65, 66, 65, 64, 64, 67, 66, 67, 
    69, 68, 68, 66, 67, 69, 71, 70, 70, 68, 69, 70, 73, 72, 70, 71, 73, 74, 72, 73, 72, 74, 75, 75, 77, 76, 75, 74, 77, 78, 76, 77, 
    76, 78, 79, 78, 51, 48, 48, 79, 78, 80, 82, 81, 81, 83, 80, 84, 86, 85, 85, 87, 84, 88, 90, 89, 88, 91, 90, 92, 93, 82, 82, 94, 
    92, 95, 97, 96, 96, 98, 95, 99, 101, 100, 100, 102, 99, 103, 94, 104, 104, 105, 103, 106, 108, 107, 107, 109, 106, 110, 112, 111, 110, 113, 112, 114, 
    116, 115, 117, 119, 118, 120, 122, 121, 120, 123, 122, 124, 126, 125, 125, 127, 124
};
static SDC_Mesh3D Baggage_E_Mesh = {Baggage_E_Vertices, Baggage_E_Indices, NULL, 306, 128, POLIGON_VERTEX_NORMAL};
#endif