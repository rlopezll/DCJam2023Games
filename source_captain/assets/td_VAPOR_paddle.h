#ifndef _TD_VAPOR_PADDLE_MESH_
#define _TD_VAPOR_PADDLE_MESH_

#include <types.h>
#include "dcRender.h"

static SDC_VertexTextured td_VAPOR_paddle_Vertices[] = {
    { 63, -59, -51, 0, 85, 30 },
    { 63, -63, -46, 0, 85, 30 },
    { 63, -82, -64, 0, 85, 30 },
    { -62, -63, -46, 0, 85, 30 },
    { -62, -59, -51, 0, 85, 30 },
    { -62, -82, -64, 0, 85, 30 },
    { -62, -5, -77, 0, 84, 29 },
    { -62, 1, -77, 0, 84, 29 },
    { -62, -1, -103, 0, 83, 29 },
    { 63, 1, -77, 0, 83, 28 },
    { 63, -5, -77, 0, 83, 28 },
    { 63, -1, -103, 0, 83, 28 },
    { 63, -77, 12, 0, 85, 30 },
    { 63, -75, 18, 0, 85, 30 },
    { 63, -101, 21, 0, 85, 30 },
    { -62, -75, 18, 0, 83, 29 },
    { -62, -77, 12, 0, 83, 29 },
    { -62, -101, 21, 0, 83, 29 },
    { 63, -37, 66, 0, 83, 29 },
    { 63, -32, 69, 0, 83, 29 },
    { 63, -46, 91, 0, 83, 29 },
    { -62, -32, 69, 0, 85, 30 },
    { -62, -37, 66, 0, 85, 30 },
    { -62, -46, 91, 0, 85, 30 },
    { 63, 28, 69, 0, 83, 29 },
    { 63, 33, 66, 0, 83, 29 },
    { 63, 42, 91, 0, 83, 29 },
    { -62, 33, 66, 0, 83, 29 },
    { -62, 28, 69, 0, 83, 29 },
    { -62, 42, 91, 0, 84, 29 },
    { 63, 71, 18, 0, 84, 30 },
    { 63, 73, 12, 0, 84, 30 },
    { 63, 97, 21, 0, 84, 30 },
    { -62, 73, 12, 0, 83, 29 },
    { -62, 71, 18, 0, 83, 29 },
    { -62, 97, 21, 0, 83, 29 },
    { 63, 59, -46, 0, 85, 30 },
    { 63, 55, -51, 0, 85, 30 },
    { 63, 78, -64, 0, 85, 30 },
    { -62, 55, -51, 0, 83, 29 },
    { -62, 59, -46, 0, 83, 29 },
    { -62, 78, -64, 0, 83, 29 },
    { 63, -82, -64, 0, 43, 33 },
    { -62, -59, -51, 0, 57, 30 },
    { 63, -59, -51, 0, 43, 30 },
    { -62, -82, -64, 0, 57, 33 },
    { 63, -82, -64, 0, 57, 25 },
    { -62, -63, -46, 0, 70, 27 },
    { -62, -82, -64, 0, 70, 25 },
    { 63, -63, -46, 0, 57, 27 },
    { -62, -1, -103, 0, 57, 39 },
    { 63, -1, -103, 0, 43, 39 },
    { 63, -5, -77, 0, 43, 42 },
    { -62, -5, -77, 0, 57, 42 },
    { 63, 1, -77, 0, 29, 39 },
    { -62, -1, -103, 0, 43, 42 },
    { -62, 1, -77, 0, 43, 39 },
    { 63, -1, -103, 0, 29, 42 },
    { 63, -77, 12, 0, 43, 22 },
    { -62, -101, 21, 0, 56, 25 },
    { -62, -77, 12, 0, 56, 22 },
    { 63, -101, 21, 0, 43, 25 },
    { 63, -75, 18, 0, 82, 28 },
    { -62, -75, 18, 0, 82, 28 },
    { -62, -101, 21, 0, 82, 27 },
    { 63, -101, 21, 0, 82, 27 },
    { 63, -37, 66, 0, 57, 27 },
    { -62, -46, 91, 0, 70, 30 },
    { -62, -37, 66, 0, 70, 27 },
    { 63, -46, 91, 0, 57, 30 },
    { -62, -46, 91, 0, 29, 36 },
    { 63, -46, 91, 0, 43, 36 },
    { 63, -32, 69, 0, 43, 33 },
    { -62, -32, 69, 0, 29, 33 },
    { 63, 28, 69, 0, 29, 36 },
    { -62, 42, 91, 0, 43, 39 },
    { -62, 28, 69, 0, 43, 36 },
    { 63, 42, 91, 0, 29, 39 },
    { -62, 42, 91, 0, 57, 25 },
    { 63, 42, 91, 0, 43, 25 },
    { 63, 33, 66, 0, 43, 27 },
    { -62, 33, 66, 0, 57, 27 },
    { 63, 97, 21, 0, 43, 36 },
    { -62, 97, 21, 0, 57, 36 },
    { -62, 71, 18, 0, 57, 33 },
    { 63, 71, 18, 0, 43, 33 },
    { 63, 73, 12, 0, 43, 39 },
    { -62, 73, 12, 0, 57, 39 },
    { -62, 59, -46, 0, 70, 30 },
    { 63, 59, -46, 0, 57, 30 },
    { 63, 78, -64, 0, 57, 33 },
    { -62, 78, -64, 0, 70, 33 },
    { 63, 78, -64, 0, 43, 27 },
    { -62, 55, -51, 0, 57, 30 },
    { -62, 78, -64, 0, 57, 27 },
    { 63, 55, -51, 0, 43, 30 },
    { -62, -63, -46, 0, 70, 23 },
    { 63, -63, -46, 0, 57, 23 },
    { 63, -59, -51, 0, 57, 24 },
    { -62, -59, -51, 0, 70, 24 },
    { 63, 1, -77, 0, 57, 21 },
    { -62, 1, -77, 0, 70, 21 },
    { -62, -5, -77, 0, 70, 20 },
    { 63, -5, -77, 0, 57, 20 },
    { -62, -75, 18, 0, 70, 22 },
    { 63, -75, 18, 0, 57, 22 },
    { 63, -77, 12, 0, 57, 22 },
    { -62, -77, 12, 0, 70, 22 },
    { -62, -32, 69, 0, 70, 23 },
    { 63, -32, 69, 0, 57, 23 },
    { 63, -37, 66, 0, 57, 23 },
    { -62, -37, 66, 0, 70, 23 },
    { -62, 33, 66, 0, 70, 20 },
    { 63, 33, 66, 0, 57, 20 },
    { 63, 28, 69, 0, 57, 20 },
    { -62, 28, 69, 0, 70, 20 },
    { 63, 73, 12, 0, 57, 21 },
    { -62, 71, 18, 0, 70, 22 },
    { -62, 73, 12, 0, 70, 21 },
    { 63, 71, 18, 0, 57, 22 },
    { 63, 55, -51, 0, 57, 22 },
    { -62, 59, -46, 0, 70, 23 },
    { -62, 55, -51, 0, 70, 22 },
    { 63, 59, -46, 0, 57, 23 },
    { -65, 69, -58, 0, 83, 28 },
    { -60, -1, -96, 0, 83, 28 },
    { -65, -1, -92, 0, 83, 28 },
    { -60, 73, -60, 0, 83, 28 },
    { -65, -72, -58, 0, 85, 27 },
    { -65, -1, -92, 0, 86, 27 },
    { -60, -1, -96, 0, 86, 27 },
    { -60, -75, -60, 0, 85, 27 },
    { -65, -72, -58, 0, 85, 27 },
    { -60, -94, 19, 0, 86, 27 },
    { -65, -90, 18, 0, 86, 27 },
    { -60, -75, -60, 0, 85, 27 },
    { -65, -40, 80, 0, 83, 27 },
    { -65, -90, 18, 0, 83, 27 },
    { -60, -94, 19, 0, 83, 27 },
    { -60, -42, 84, 0, 83, 27 },
    { -60, 40, 84, 0, 82, 27 },
    { -65, -40, 80, 0, 82, 27 },
    { -60, -42, 84, 0, 82, 27 },
    { -65, 38, 80, 0, 82, 27 },
    { -65, 38, 80, 0, 82, 27 },
    { -60, 91, 19, 0, 82, 27 },
    { -65, 87, 18, 0, 82, 27 },
    { -60, 40, 84, 0, 82, 27 },
    { -65, 69, -58, 0, 85, 27 },
    { -65, 87, 18, 0, 85, 27 },
    { -60, 91, 19, 0, 85, 27 },
    { -60, 73, -60, 0, 85, 27 },
    { 65, 69, -58, 0, 82, 27 },
    { 61, -1, -96, 0, 82, 27 },
    { 61, 73, -60, 0, 82, 27 },
    { 65, -1, -92, 0, 82, 27 },
    { 61, 91, 19, 0, 83, 27 },
    { 65, 69, -58, 0, 84, 27 },
    { 61, 73, -60, 0, 84, 27 },
    { 65, 87, 18, 0, 83, 27 },
    { 65, 87, 18, 0, 84, 28 },
    { 61, 40, 84, 0, 83, 29 },
    { 65, 38, 80, 0, 83, 29 },
    { 61, 91, 19, 0, 84, 28 },
    { 65, -40, 80, 0, 84, 29 },
    { 65, 38, 80, 0, 84, 29 },
    { 61, 40, 84, 0, 84, 29 },
    { 61, -42, 84, 0, 84, 29 },
    { 65, -90, 18, 0, 83, 29 },
    { 61, -42, 84, 0, 83, 28 },
    { 61, -94, 19, 0, 83, 29 },
    { 65, -40, 80, 0, 83, 28 },
    { 65, -72, -58, 0, 85, 28 },
    { 61, -94, 19, 0, 85, 29 },
    { 61, -75, -60, 0, 85, 28 },
    { 65, -90, 18, 0, 85, 29 },
    { 61, -1, -96, 0, 82, 27 },
    { 65, -72, -58, 0, 82, 27 },
    { 61, -75, -60, 0, 82, 27 },
    { 65, -1, -92, 0, 82, 27 },
    { -65, 69, -58, 0, 82, 28 },
    { -65, -1, -92, 0, 82, 28 },
    { -65, 2, -86, 0, 82, 28 },
    { -65, 62, -57, 0, 82, 28 },
    { -65, -1, -92, 0, 85, 27 },
    { -65, 0, 0, 0, 85, 27 },
    { -65, 4, -8, 0, 85, 27 },
    { -65, 2, -86, 0, 85, 27 },
    { -65, 69, -58, 0, 84, 28 },
    { -65, 4, -8, 0, 83, 29 },
    { -65, 0, 0, 0, 83, 29 },
    { -65, 62, -57, 0, 83, 28 },
    { -65, 87, 18, 0, 82, 27 },
    { -65, 69, -58, 0, 82, 27 },
    { -65, 67, -51, 0, 82, 27 },
    { -65, 82, 13, 0, 82, 27 },
    { -65, 69, -58, 0, 84, 28 },
    { -65, 9, -2, 0, 83, 29 },
    { -65, 67, -51, 0, 84, 28 },
    { -65, 87, 18, 0, 82, 27 },
    { -65, 9, -2, 0, 82, 27 },
    { -65, 0, 0, 0, 82, 27 },
    { -65, 82, 13, 0, 82, 27 },
    { -65, 87, 18, 0, 83, 29 },
    { -65, 39, 73, 0, 83, 29 },
    { -65, 38, 80, 0, 83, 29 },
    { -65, 80, 21, 0, 83, 29 },
    { -65, 87, 18, 0, 85, 27 },
    { -65, 0, 0, 0, 85, 27 },
    { -65, 7, 5, 0, 85, 27 },
    { -65, 80, 21, 0, 85, 27 },
    { -65, 38, 80, 0, 83, 27 },
    { -65, 7, 5, 0, 83, 27 },
    { -65, 0, 0, 0, 83, 27 },
    { -65, 39, 73, 0, 83, 27 },
    { -65, 38, 80, 0, 84, 27 },
    { -65, -34, 76, 0, 83, 27 },
    { -65, -40, 80, 0, 83, 27 },
    { -65, 31, 76, 0, 84, 27 },
    { -65, 38, 80, 0, 83, 27 },
    { -65, 0, 0, 0, 83, 27 },
    { -65, 0, 8, 0, 83, 27 },
    { -65, 31, 76, 0, 83, 27 },
    { -65, -40, 80, 0, 82, 28 },
    { -65, 0, 8, 0, 82, 28 },
    { -65, 0, 0, 0, 82, 28 },
    { -65, -34, 76, 0, 82, 28 },
    { -65, -40, 80, 0, 82, 27 },
    { -65, -82, 21, 0, 82, 27 },
    { -65, -90, 18, 0, 82, 27 },
    { -65, -41, 73, 0, 82, 27 },
    { -65, -40, 80, 0, 82, 28 },
    { -65, 0, 0, 0, 82, 28 },
    { -65, -6, 5, 0, 82, 28 },
    { -65, -41, 73, 0, 82, 28 },
    { -65, -90, 18, 0, 85, 27 },
    { -65, -6, 5, 0, 85, 27 },
    { -65, 0, 0, 0, 85, 27 },
    { -65, -82, 21, 0, 85, 27 },
    { -65, -90, 18, 0, 84, 28 },
    { -65, -70, -51, 0, 83, 28 },
    { -65, -72, -58, 0, 83, 28 },
    { -65, -84, 13, 0, 84, 28 },
    { -65, 0, 0, 0, 85, 27 },
    { -65, -8, -2, 0, 85, 27 },
    { -65, -84, 13, 0, 85, 27 },
    { -65, -72, -58, 0, 83, 29 },
    { -65, -8, -2, 0, 83, 29 },
    { -65, 0, 0, 0, 83, 29 },
    { -65, -70, -51, 0, 83, 29 },
    { -65, -1, -92, 0, 83, 27 },
    { -65, -72, -58, 0, 83, 27 },
    { -65, -65, -57, 0, 83, 27 },
    { -65, -5, -86, 0, 83, 27 },
    { -65, -3, -8, 0, 83, 29 },
    { -65, -65, -57, 0, 83, 29 },
    { -65, -72, -58, 0, 83, 29 },
    { -65, -3, -8, 0, 85, 27 },
    { -65, -1, -92, 0, 85, 27 },
    { -65, -5, -86, 0, 85, 27 },
    { 65, -1, -92, 0, 83, 29 },
    { 65, 69, -58, 0, 83, 28 },
    { 66, 62, -57, 0, 83, 28 },
    { 66, 2, -86, 0, 83, 29 },
    { 65, 0, 0, 0, 83, 29 },
    { 66, 62, -57, 0, 84, 29 },
    { 65, 69, -58, 0, 84, 28 },
    { 66, 2, -9, 0, 83, 29 },
    { 65, -1, -92, 0, 84, 27 },
    { 66, 2, -9, 0, 83, 27 },
    { 65, 0, 0, 0, 83, 27 },
    { 66, 2, -86, 0, 84, 27 },
    { 65, 69, -58, 0, 82, 27 },
    { 65, 87, 18, 0, 82, 27 },
    { 66, 82, 13, 0, 82, 27 },
    { 66, 67, -51, 0, 82, 27 },
    { 65, 0, 0, 0, 82, 27 },
    { 66, 82, 13, 0, 82, 27 },
    { 65, 87, 18, 0, 82, 27 },
    { 66, 7, -3, 0, 82, 27 },
    { 65, 69, -58, 0, 84, 28 },
    { 66, 7, -3, 0, 83, 29 },
    { 66, 67, -51, 0, 84, 28 },
    { 65, 87, 18, 0, 82, 27 },
    { 65, 38, 80, 0, 82, 27 },
    { 66, 38, 73, 0, 82, 27 },
    { 66, 80, 21, 0, 82, 27 },
    { 65, 38, 80, 0, 82, 28 },
    { 65, 0, 0, 0, 82, 28 },
    { 66, 5, 4, 0, 82, 28 },
    { 66, 38, 73, 0, 82, 28 },
    { 65, 87, 18, 0, 84, 29 },
    { 66, 5, 4, 0, 84, 30 },
    { 65, 0, 0, 0, 84, 30 },
    { 66, 80, 21, 0, 84, 29 },
    { 65, 38, 80, 0, 83, 29 },
    { 65, -40, 80, 0, 83, 30 },
    { 66, -34, 76, 0, 83, 30 },
    { 66, 31, 76, 0, 83, 29 },
    { 65, -40, 80, 0, 83, 27 },
    { 65, 0, 0, 0, 83, 27 },
    { 66, -1, 7, 0, 83, 27 },
    { 66, -34, 76, 0, 83, 27 },
    { 65, 0, 0, 0, 82, 28 },
    { 65, 38, 80, 0, 82, 28 },
    { 66, 31, 76, 0, 82, 28 },
    { 66, -1, 7, 0, 82, 28 },
    { 65, -90, 18, 0, 84, 27 },
    { 66, -41, 73, 0, 83, 27 },
    { 65, -40, 80, 0, 83, 27 },
    { 66, -83, 21, 0, 84, 27 },
    { 65, -90, 18, 0, 84, 28 },
    { 65, 0, 0, 0, 84, 27 },
    { 66, -8, 4, 0, 84, 27 },
    { 66, -83, 21, 0, 84, 27 },
    { 65, 0, 0, 0, 83, 27 },
    { 66, -41, 73, 0, 83, 28 },
    { 66, -8, 4, 0, 83, 27 },
    { 65, -72, -58, 0, 83, 27 },
    { 66, -84, 13, 0, 83, 27 },
    { 65, -90, 18, 0, 83, 27 },
    { 66, -70, -51, 0, 83, 27 },
    { 65, -72, -58, 0, 83, 29 },
    { 65, 0, 0, 0, 83, 29 },
    { 66, -10, -3, 0, 83, 29 },
    { 66, -70, -51, 0, 83, 29 },
    { 65, -90, 18, 0, 84, 28 },
    { 66, -10, -3, 0, 84, 27 },
    { 65, 0, 0, 0, 84, 27 },
    { 66, -84, 13, 0, 84, 28 },
    { 65, -1, -92, 0, 84, 29 },
    { 66, -65, -57, 0, 83, 29 },
    { 65, -72, -58, 0, 83, 29 },
    { 66, -5, -86, 0, 84, 29 },
    { 65, -1, -92, 0, 82, 27 },
    { 65, 0, 0, 0, 82, 27 },
    { 66, -5, -9, 0, 82, 27 },
    { 66, -5, -86, 0, 82, 27 },
    { 66, -5, -9, 0, 83, 29 },
    { 65, -72, -58, 0, 83, 29 },
    { 66, -65, -57, 0, 83, 29 },
    { 65, 0, 0, 0, 83, 29 },
    { -100, -5, -3, 0, 84, 27 },
    { 100, 1, 6, 0, 83, 27 },
    { -100, -1, 6, 0, 84, 27 },
    { 100, -6, -3, 0, 83, 27 },
    { -100, 6, -3, 0, 84, 28 },
    { 100, -6, -3, 0, 83, 28 },
    { -100, -5, -3, 0, 84, 28 },
    { 100, 5, -3, 0, 83, 28 },
    { 100, 1, 6, 0, 83, 28 },
    { -100, -1, 6, 0, 84, 28 }
};
static u_short td_VAPOR_paddle_Indices[] = {
    0, 2, 1, 3, 5, 4, 6, 8, 7, 9, 11, 10, 12, 14, 13, 15, 17, 16, 18, 20, 19, 21, 23, 22, 24, 26, 25, 27, 29, 28, 30, 32, 31, 
    33, 35, 34, 36, 38, 37, 39, 41, 40, 42, 44, 43, 43, 45, 42, 46, 48, 47, 47, 49, 46, 50, 52, 51, 50, 53, 52, 54, 56, 55, 55, 57, 
    54, 58, 60, 59, 59, 61, 58, 62, 64, 63, 62, 65, 64, 66, 68, 67, 67, 69, 66, 70, 72, 71, 70, 73, 72, 74, 76, 75, 75, 77, 74, 78, 
    80, 79, 78, 81, 80, 82, 84, 83, 82, 85, 84, 83, 86, 82, 83, 87, 86, 88, 90, 89, 88, 91, 90, 92, 94, 93, 93, 95, 92, 96, 98, 97, 
    96, 99, 98, 100, 102, 101, 100, 103, 102, 104, 106, 105, 104, 107, 106, 108, 110, 109, 108, 111, 110, 112, 114, 113, 112, 115, 114, 116, 118, 117, 117, 119, 
    116, 120, 122, 121, 121, 123, 120, 124, 126, 125, 125, 127, 124, 128, 130, 129, 130, 128, 131, 132, 134, 133, 133, 135, 132, 136, 138, 137, 138, 136, 139, 140, 
    142, 141, 141, 143, 140, 144, 146, 145, 145, 147, 144, 148, 150, 149, 150, 148, 151, 152, 154, 153, 153, 155, 152, 156, 158, 157, 157, 159, 156, 160, 162, 161, 
    161, 163, 160, 164, 166, 165, 166, 164, 167, 168, 170, 169, 169, 171, 168, 172, 174, 173, 173, 175, 172, 176, 178, 177, 177, 179, 176, 180, 182, 181, 180, 183, 
    182, 184, 186, 185, 184, 187, 186, 188, 190, 189, 189, 191, 188, 192, 194, 193, 192, 195, 194, 196, 197, 190, 196, 198, 197, 199, 201, 200, 200, 202, 199, 203, 
    205, 204, 204, 206, 203, 207, 209, 208, 207, 210, 209, 211, 213, 212, 212, 214, 211, 215, 217, 216, 216, 218, 215, 219, 221, 220, 219, 222, 221, 223, 225, 224, 
    224, 226, 223, 227, 229, 228, 228, 230, 227, 231, 233, 232, 231, 234, 233, 235, 237, 236, 236, 238, 235, 239, 241, 240, 240, 242, 239, 235, 244, 243, 235, 245, 
    244, 246, 248, 247, 247, 249, 246, 250, 252, 251, 250, 253, 252, 254, 256, 255, 256, 254, 248, 257, 259, 258, 185, 257, 258, 260, 262, 261, 260, 263, 262, 264, 
    266, 265, 265, 267, 264, 268, 270, 269, 269, 271, 268, 272, 274, 273, 272, 275, 274, 276, 278, 277, 277, 279, 276, 264, 281, 280, 281, 282, 280, 283, 285, 284, 
    283, 286, 285, 287, 289, 288, 287, 290, 289, 291, 293, 292, 292, 294, 291, 295, 297, 296, 295, 298, 297, 299, 301, 300, 299, 302, 301, 303, 305, 304, 303, 306, 
    305, 307, 309, 308, 308, 310, 307, 311, 313, 312, 311, 314, 313, 315, 316, 299, 315, 317, 316, 318, 320, 319, 319, 321, 318, 322, 324, 323, 322, 325, 324, 326, 
    328, 327, 327, 329, 326, 330, 332, 331, 331, 333, 330, 334, 336, 335, 334, 337, 336, 338, 340, 339, 341, 338, 339, 342, 344, 343, 343, 345, 342, 346, 348, 347, 
    347, 349, 346, 346, 349, 350, 350, 351, 346
};
static SDC_Mesh3D td_VAPOR_paddle_Mesh = {td_VAPOR_paddle_Vertices, td_VAPOR_paddle_Indices, NULL, 522, 352, POLIGON_VERTEX_TEXTURED};
#endif