#ifndef _PATH_P2_MESH_
#define _PATH_P2_MESH_

#include <types.h>
#include "dcRender.h"

static SDC_VertexTexturedNormal Path_P2_Vertices[] = {
    { 398, 20, -430, 0, 0, 4096, 0, 0, 0, 17 },
    { 279, 20, -400, 0, 0, 4096, 0, 0, 63, 33 },
    { 398, 20, -400, 0, 0, 4096, 0, 0, 0, 33 },
    { 279, 20, -430, 0, 0, 4096, 0, 0, 63, 17 },
    { 398, 0, -339, 0, 0, 0, 4096, 0, 19, 59 },
    { 545, 0, -339, 0, 0, 0, 4096, 0, 20, 59 },
    { 398, 20, -339, 0, 0, 0, 4096, 0, 19, 62 },
    { 545, 20, -339, 0, 0, 0, 4096, 0, 20, 62 },
    { 545, 20, -460, 0, 0, 0, -4096, 0, 20, 59 },
    { 398, 0, -460, 0, 0, 0, -4096, 0, 19, 62 },
    { 398, 20, -460, 0, 0, 0, -4096, 0, 19, 59 },
    { 545, 0, -460, 0, 0, 0, -4096, 0, 20, 62 },
    { 157, 20, -430, 0, 0, 4096, 0, 0, 0, 17 },
    { 145, 20, -384, 0, 0, 4096, 0, 0, 10, 33 },
    { 170, 20, -400, 0, 0, 4096, 0, 0, 0, 33 },
    { 121, 20, -408, 0, 0, 4096, 0, 0, 10, 17 },
    { 194, 0, -339, 0, 1098, 0, 3946, 0, 17, 59 },
    { 194, 20, -339, 0, 1098, 0, 3946, 0, 17, 62 },
    { 191, 20, -338, 0, 2896, 0, 2896, 0, 17, 62 },
    { 191, 0, -338, 0, 2896, 0, 2896, 0, 17, 59 },
    { 145, 20, -460, 0, -1098, 0, -3946, 0, 17, 59 },
    { 98, 0, -431, 0, -2896, 0, -2896, 0, 17, 62 },
    { 98, 20, -431, 0, -2896, 0, -2896, 0, 17, 59 },
    { 145, 0, -460, 0, -1098, 0, -3946, 0, 17, 62 },
    { 100, 20, -271, 0, 0, 4096, 0, 0, 63, 17 },
    { 129, 20, -330, 0, 0, 4096, 0, 0, 27, 33 },
    { 100, 20, -330, 0, 0, 4096, 0, 0, 27, 17 },
    { 130, 20, -271, 0, 0, 4096, 0, 0, 63, 33 },
    { 189, 0, -271, 0, 4096, 0, 0, 0, 16, 59 },
    { 189, 0, -330, 0, 4096, 0, 0, 0, 17, 59 },
    { 189, 20, -271, 0, 4096, 0, 0, 0, 16, 62 },
    { 189, 20, -330, 0, 4096, 0, 0, 0, 17, 62 },
    { 70, 20, -330, 0, -4096, 0, 0, 0, 17, 59 },
    { 70, 0, -271, 0, -4096, 0, 0, 0, 16, 62 },
    { 70, 20, -271, 0, -4096, 0, 0, 0, 16, 59 },
    { 70, 0, -330, 0, -4096, 0, 0, 0, 17, 62 },
    { 130, 20, -240, 0, 0, 4096, 0, 0, 4, 33 },
    { 100, 20, -227, 0, 0, 4096, 0, 0, 4, 17 },
    { 145, 20, -215, 0, 0, 4096, 0, 0, 13, 33 },
    { 121, 20, -191, 0, 0, 4095, 0, 0, 13, 17 },
    { 189, 0, -264, 0, 3946, 0, -1097, 0, 16, 59 },
    { 189, 20, -264, 0, 3946, 0, -1097, 0, 16, 62 },
    { 191, 20, -261, 0, 2896, 0, -2896, 0, 16, 62 },
    { 191, 0, -261, 0, 2896, 0, -2896, 0, 16, 59 },
    { 70, 20, -215, 0, -3946, 0, 1098, 0, 16, 59 },
    { 98, 0, -168, 0, -2896, 0, 2896, 0, 16, 62 },
    { 98, 20, -168, 0, -2896, 0, 2896, 0, 16, 59 },
    { 70, 0, -215, 0, -3946, 0, 1098, 0, 16, 62 },
    { 300, 20, -200, 0, 0, 4096, 0, 0, 63, 33 },
    { 170, 20, -200, 0, 0, 4096, 0, 0, 22, 33 },
    { 287, 20, -169, 0, 0, 4096, 0, 0, 63, 17 },
    { 157, 20, -169, 0, 0, 4096, 0, 0, 22, 17 },
    { 324, 20, -260, 0, 1098, 0, -3946, 0, 14, 62 },
    { 194, 0, -260, 0, 1098, 0, -3946, 0, 15, 59 },
    { 194, 20, -260, 0, 1098, 0, -3946, 0, 15, 62 },
    { 324, 0, -260, 0, 1098, 0, -3946, 0, 14, 59 },
    { 145, 20, -139, 0, -1098, 0, 3946, 0, 15, 59 },
    { 275, 0, -139, 0, -1098, 0, 3946, 0, 15, 62 },
    { 275, 20, -139, 0, -1098, 0, 3946, 0, 15, 59 },
    { 145, 0, -139, 0, -1098, 0, 3946, 0, 15, 62 },
    { 300, 20, -200, 0, 0, 4096, 0, 0, 0, 33 },
    { 287, 20, -169, 0, 0, 4096, 0, 0, 0, 17 },
    { 301, 20, -161, 0, 0, 4096, 0, 0, 10, 17 },
    { 324, 20, -184, 0, 0, 4096, 0, 0, 10, 33 },
    { 371, 0, -231, 0, 2896, 0, -2896, 0, 14, 59 },
    { 371, 20, -231, 0, 2896, 0, -2896, 0, 14, 62 },
    { 278, 0, -138, 0, -2896, 0, 2896, 0, 14, 62 },
    { 278, 20, -138, 0, -2896, 0, 2896, 0, 14, 59 },
    { 310, 20, -128, 0, 0, 4096, 0, 0, 26, 17 },
    { 309, 20, -62, 0, 0, 4096, 0, 0, 63, 17 },
    { 340, 20, -62, 0, 0, 4096, 0, 0, 63, 33 },
    { 340, 20, -128, 0, 0, 4096, 0, 0, 26, 33 },
    { 400, 0, -62, 0, 4096, 0, 0, 0, 13, 59 },
    { 399, 0, -128, 0, 4096, 0, 0, 0, 14, 59 },
    { 400, 20, -62, 0, 4096, 0, 0, 0, 13, 62 },
    { 399, 20, -128, 0, 4096, 0, 0, 0, 14, 62 },
    { 280, 20, -128, 0, -4096, 0, 0, 0, 14, 59 },
    { 279, 0, -62, 0, -4096, 0, 0, 0, 13, 62 },
    { 279, 20, -62, 0, -4096, 0, 0, 0, 13, 59 },
    { 280, 0, -128, 0, -4096, 0, 0, 0, 14, 62 },
    { 301, 20, -29, 0, 0, 4096, 0, 0, 19, 17 },
    { 324, 20, -6, 0, 0, 4096, 0, 0, 19, 33 },
    { 340, 20, -31, 0, 0, 4096, 0, 0, 6, 33 },
    { 309, 20, -43, 0, 0, 4096, 0, 0, 6, 17 },
    { 371, 0, 40, 0, 2896, 0, 2896, 0, 13, 59 },
    { 400, 0, -6, 0, 3946, 0, 1098, 0, 13, 59 },
    { 371, 20, 40, 0, 2896, 0, 2896, 0, 13, 62 },
    { 400, 20, -6, 0, 3946, 0, 1098, 0, 13, 62 },
    { 279, 20, -55, 0, -3946, 0, -1098, 0, 13, 59 },
    { 278, 0, -52, 0, -2896, 0, -2896, 0, 13, 62 },
    { 278, 20, -52, 0, -2896, 0, -2896, 0, 13, 59 },
    { 279, 0, -55, 0, -3946, 0, -1098, 0, 13, 62 },
    { -5, 20, -20, 0, 0, 4096, 0, 0, 0, 17 },
    { -141, 20, 8, 0, 0, 4096, 0, 0, 63, 33 },
    { -5, 20, 8, 0, 0, 4096, 0, 0, 0, 33 },
    { -141, 20, -20, 0, 0, 4096, 0, 0, 63, 17 },
    { -5, 0, 68, 0, 0, 0, 4096, 0, 11, 59 },
    { 129, 0, 68, 0, 0, 0, 4096, 0, 11, 59 },
    { -5, 20, 68, 0, 0, 0, 4096, 0, 11, 62 },
    { 129, 20, 68, 0, 0, 0, 4096, 0, 11, 62 },
    { -5, 20, -50, 0, 0, 0, -4096, 0, 11, 59 },
    { 129, 0, -50, 0, 0, 0, -4096, 0, 12, 62 },
    { -5, 0, -50, 0, 0, 0, -4096, 0, 11, 62 },
    { 129, 20, -50, 0, 0, 0, -4096, 0, 12, 59 },
    { -322, 20, -20, 0, 0, 4096, 0, 0, 27, 17 },
    { -334, 20, 24, 0, 0, 4096, 0, 0, 38, 33 },
    { -310, 20, 8, 0, 0, 4096, 0, 0, 27, 33 },
    { -358, 20, 0, 0, 0, 4096, 0, 0, 38, 17 },
    { -285, 0, 68, 0, 1097, 0, 3946, 0, 9, 59 },
    { -285, 20, 68, 0, 1097, 0, 3946, 0, 9, 62 },
    { -288, 20, 70, 0, 2896, 0, 2896, 0, 8, 62 },
    { -288, 0, 70, 0, 2896, 0, 2896, 0, 8, 59 },
    { -334, 20, -50, 0, -1098, 0, -3946, 0, 9, 59 },
    { -381, 0, -22, 0, -2896, 0, -2896, 0, 8, 62 },
    { -381, 20, -22, 0, -2896, 0, -2896, 0, 8, 59 },
    { -334, 0, -50, 0, -1098, 0, -3946, 0, 9, 62 },
    { -380, 20, 194, 0, 0, 4096, 0, 0, 0, 17 },
    { -380, 20, 306, 0, 0, 4096, 0, 0, 63, 17 },
    { -349, 20, 306, 0, 0, 4096, 0, 0, 63, 33 },
    { -349, 20, 194, 0, 0, 4096, 0, 0, 0, 33 },
    { -289, 0, 194, 0, 4096, 0, 0, 0, 7, 59 },
    { -289, 0, 82, 0, 4096, 0, 0, 0, 8, 59 },
    { -289, 20, 194, 0, 4096, 0, 0, 0, 7, 62 },
    { -289, 20, 82, 0, 4096, 0, 0, 0, 8, 62 },
    { -410, 20, 82, 0, -4096, 0, 0, 0, 8, 59 },
    { -410, 0, 194, 0, -4096, 0, 0, 0, 7, 62 },
    { -410, 20, 194, 0, -4096, 0, 0, 0, 7, 59 },
    { -410, 0, 82, 0, -4096, 0, 0, 0, 8, 62 },
    { -388, 20, 341, 0, 0, 4096, 0, 0, 26, 17 },
    { -365, 20, 364, 0, 0, 4096, 0, 0, 26, 33 },
    { -349, 20, 340, 0, 0, 4096, 0, 0, 14, 33 },
    { -380, 20, 327, 0, 0, 4096, 0, 0, 14, 17 },
    { -318, 0, 411, 0, 2896, 0, 2896, 0, 6, 59 },
    { -289, 0, 364, 0, 3946, 0, 1098, 0, 6, 59 },
    { -318, 20, 411, 0, 2896, 0, 2896, 0, 6, 62 },
    { -289, 20, 364, 0, 3946, 0, 1098, 0, 6, 62 },
    { -410, 20, 315, 0, -3946, 0, -1098, 0, 6, 59 },
    { -411, 0, 318, 0, -2896, 0, -2896, 0, 6, 62 },
    { -411, 20, 318, 0, -2896, 0, -2896, 0, 6, 59 },
    { -410, 0, 315, 0, -3946, 0, -1098, 0, 6, 62 },
    { -676, 20, 409, 0, 0, 4096, 0, 0, 63, 48 },
    { -531, 20, 410, 0, 0, 4096, 0, 0, 31, 48 },
    { -531, 20, 380, 0, 0, 4096, 0, 0, 31, 33 },
    { -676, 20, 379, 0, 0, 4096, 0, 0, 63, 33 },
    { -820, 20, 439, 0, 0, 0, 4096, 0, 3, 62 },
    { -676, 0, 440, 0, 0, 0, 4096, 0, 4, 59 },
    { -676, 20, 440, 0, 0, 0, 4096, 0, 4, 62 },
    { -820, 0, 439, 0, 0, 0, 4096, 0, 3, 59 },
    { -676, 0, 319, 0, 0, 0, -4096, 0, 4, 62 },
    { -820, 0, 319, 0, 0, 0, -4096, 0, 3, 62 },
    { -676, 20, 319, 0, 0, 0, -4096, 0, 4, 59 },
    { -820, 20, 319, 0, 0, 0, -4096, 0, 3, 59 },
    { 100, 20, -372, 0, 0, 4096, 0, 0, 21, 17 },
    { 129, 20, -359, 0, 0, 4096, 0, 0, 21, 33 },
    { 189, 20, -335, 0, 3946, 0, 1097, 0, 17, 62 },
    { 189, 0, -335, 0, 3946, 0, 1097, 0, 17, 59 },
    { 70, 0, -384, 0, -3946, 0, -1098, 0, 17, 62 },
    { 70, 20, -384, 0, -3946, 0, -1098, 0, 17, 59 },
    { 340, 20, -160, 0, 0, 4096, 0, 0, 20, 33 },
    { 310, 20, -147, 0, 0, 4096, 0, 0, 20, 17 },
    { 399, 0, -184, 0, 3946, 0, -1098, 0, 14, 59 },
    { 399, 20, -184, 0, 3946, 0, -1098, 0, 14, 62 },
    { 280, 0, -135, 0, -3946, 0, 1097, 0, 14, 62 },
    { 280, 20, -135, 0, -3946, 0, 1097, 0, 14, 59 },
    { 300, 20, 8, 0, 0, 4096, 0, 0, 31, 33 },
    { 287, 20, -20, 0, 0, 4096, 0, 0, 31, 17 },
    { 324, 0, 68, 0, 1098, 0, 3946, 0, 13, 59 },
    { 324, 20, 68, 0, 1098, 0, 3946, 0, 13, 62 },
    { 275, 0, -50, 0, -1097, 0, -3946, 0, 13, 62 },
    { 275, 20, -50, 0, -1097, 0, -3946, 0, 13, 59 },
    { -380, 20, 36, 0, 0, 4096, 0, 0, 49, 17 },
    { -350, 20, 48, 0, 0, 4096, 0, 0, 49, 33 },
    { -289, 20, 73, 0, 3946, 0, 1098, 0, 8, 62 },
    { -289, 0, 73, 0, 3946, 0, 1098, 0, 8, 59 },
    { -410, 20, 24, 0, -3946, 0, -1098, 0, 8, 59 },
    { -410, 0, 24, 0, -3946, 0, -1098, 0, 8, 62 },
    { -389, 20, 380, 0, 0, 4096, 0, 0, 38, 33 },
    { -402, 20, 350, 0, 0, 4096, 0, 0, 38, 17 },
    { -365, 0, 440, 0, 1098, 0, 3946, 0, 6, 59 },
    { -365, 20, 440, 0, 1098, 0, 3946, 0, 6, 62 },
    { -414, 0, 319, 0, -1097, 0, -3946, 0, 6, 62 },
    { -414, 20, 319, 0, -1097, 0, -3946, 0, 6, 59 },
    { 207, 20, -400, 0, 0, 4096, 0, 0, 30, 33 },
    { 207, 20, -430, 0, 0, 4096, 0, 0, 30, 17 },
    { 170, 20, -400, 0, 0, 4096, 0, 0, 63, 33 },
    { 157, 20, -430, 0, 0, 4096, 0, 0, 63, 17 },
    { 864, 20, -370, 0, 0, 4096, 0, 0, 63, 48 },
    { 1000, 20, -369, 0, 0, 4096, 0, 0, 0, 48 },
    { 1000, 20, -399, 0, 0, 4096, 0, 0, 0, 33 },
    { 864, 20, -400, 0, 0, 4096, 0, 0, 63, 33 },
    { 207, 20, -339, 0, 0, 0, 4096, 0, 18, 62 },
    { 207, 0, -339, 0, 0, 0, 4096, 0, 18, 59 },
    { 728, 20, -339, 0, 0, 0, 4096, 0, 21, 62 },
    { 864, 0, -339, 0, 0, 0, 4096, 0, 22, 59 },
    { 864, 20, -339, 0, 0, 0, 4096, 0, 22, 62 },
    { 728, 0, -339, 0, 0, 0, 4096, 0, 21, 59 },
    { 207, 20, -460, 0, 0, 0, -4096, 0, 18, 59 },
    { 207, 0, -460, 0, 0, 0, -4096, 0, 18, 62 },
    { 864, 0, -460, 0, 0, 0, -4096, 0, 22, 62 },
    { 728, 0, -460, 0, 0, 0, -4096, 0, 21, 62 },
    { 864, 20, -460, 0, 0, 0, -4096, 0, 22, 59 },
    { 728, 20, -460, 0, 0, 0, -4096, 0, 21, 59 },
    { 100, 20, -271, 0, 0, 4096, 0, 0, 0, 17 },
    { 130, 20, -271, 0, 0, 4096, 0, 0, 0, 33 },
    { 159, 20, -330, 0, 0, 4096, 0, 0, 27, 48 },
    { 159, 20, -347, 0, 0, 4096, 0, 0, 21, 48 },
    { 340, 20, -62, 0, 0, 4096, 0, 0, 0, 33 },
    { 309, 20, -62, 0, 0, 4096, 0, 0, 0, 17 },
    { 369, 20, -128, 0, 0, 4096, 0, 0, 26, 48 },
    { 369, 20, -172, 0, 0, 4096, 0, 0, 20, 48 },
    { -276, 20, 8, 0, 0, 4096, 0, 0, 0, 33 },
    { -276, 20, -20, 0, 0, 4096, 0, 0, 0, 17 },
    { 264, 20, 38, 0, 0, 4096, 0, 0, 63, 48 },
    { 312, 20, 38, 0, 0, 4096, 0, 0, 31, 48 },
    { 264, 20, 8, 0, 0, 4096, 0, 0, 63, 33 },
    { -276, 0, 68, 0, 0, 0, 4096, 0, 9, 59 },
    { -276, 20, 68, 0, 0, 0, 4096, 0, 9, 62 },
    { 264, 20, 68, 0, 0, 0, 4096, 0, 12, 62 },
    { 264, 0, 68, 0, 0, 0, 4096, 0, 12, 59 },
    { -276, 20, -50, 0, 0, 0, -4096, 0, 9, 59 },
    { -276, 0, -50, 0, 0, 0, -4096, 0, 9, 62 },
    { 264, 0, -50, 0, 0, 0, -4096, 0, 12, 62 },
    { 264, 20, -50, 0, 0, 0, -4096, 0, 12, 59 },
    { -349, 20, 306, 0, 0, 4096, 0, 0, 0, 33 },
    { -380, 20, 306, 0, 0, 4096, 0, 0, 0, 17 },
    { -350, 20, 82, 0, 0, 4096, 0, 0, 63, 33 },
    { -319, 20, 82, 0, 0, 4096, 0, 0, 63, 48 },
    { -319, 20, 61, 0, 0, 4096, 0, 0, 49, 48 },
    { -289, 0, 306, 0, 4096, 0, 0, 0, 6, 59 },
    { -289, 20, 306, 0, 4096, 0, 0, 0, 6, 62 },
    { -410, 20, 306, 0, -4096, 0, 0, 0, 6, 59 },
    { -410, 0, 306, 0, -4096, 0, 0, 0, 6, 62 },
    { -450, 20, 410, 0, 0, 4096, 0, 0, 63, 48 },
    { -377, 20, 410, 0, 0, 4096, 0, 0, 38, 48 },
    { -450, 20, 380, 0, 0, 4096, 0, 0, 63, 33 },
    { -450, 20, 440, 0, 0, 0, 4096, 0, 5, 62 },
    { -450, 0, 440, 0, 0, 0, 4096, 0, 5, 59 },
    { -450, 0, 319, 0, 0, 0, -4096, 0, 5, 62 },
    { -450, 20, 319, 0, 0, 0, -4096, 0, 5, 59 },
    { 398, 20, -369, 0, 0, 4096, 0, 0, 0, 48 },
    { 279, 20, -369, 0, 0, 4096, 0, 0, 63, 48 },
    { 398, 20, -339, 0, 0, 4095, 0, 0, 0, 63 },
    { 279, 20, -339, 0, 0, 4096, 0, 0, 63, 63 },
    { 398, 20, -430, 0, 0, 4096, 0, 0, 63, 17 },
    { 545, 20, -460, 0, 0, 4096, 0, 0, 0, 0 },
    { 398, 20, -460, 0, 0, 4096, 0, 0, 63, 0 },
    { 545, 20, -430, 0, 0, 4096, 0, 0, 0, 17 },
    { 182, 20, -369, 0, 0, 4096, 0, 0, 0, 48 },
    { 191, 20, -338, 0, 0, 4096, 0, 0, 10, 63 },
    { 194, 20, -339, 0, 0, 4095, 0, 0, 0, 63 },
    { 168, 20, -361, 0, 0, 4096, 0, 0, 10, 48 },
    { 145, 20, -460, 0, 0, 4096, 0, 0, 0, 0 },
    { 98, 20, -431, 0, 0, 4096, 0, 0, 10, 0 },
    { 159, 20, -271, 0, 0, 4096, 0, 0, 63, 48 },
    { 189, 20, -330, 0, 0, 4096, 0, 0, 27, 63 },
    { 189, 20, -271, 0, 0, 4096, 0, 0, 63, 63 },
    { 70, 20, -330, 0, 0, 4096, 0, 0, 27, 0 },
    { 70, 20, -271, 0, 0, 4095, 0, 0, 63, 0 },
    { 189, 20, -264, 0, 0, 4096, 0, 0, 4, 63 },
    { 159, 20, -252, 0, 0, 4096, 0, 0, 4, 48 },
    { 191, 20, -261, 0, 0, 4096, 0, 0, 13, 63 },
    { 168, 20, -238, 0, 0, 4096, 0, 0, 13, 48 },
    { 70, 20, -215, 0, 0, 4096, 0, 0, 4, 0 },
    { 98, 20, -168, 0, 0, 4096, 0, 0, 13, 0 },
    { 324, 20, -260, 0, 0, 4096, 0, 0, 63, 63 },
    { 194, 20, -260, 0, 0, 4096, 0, 0, 22, 63 },
    { 312, 20, -230, 0, 0, 4096, 0, 0, 63, 48 },
    { 182, 20, -230, 0, 0, 4096, 0, 0, 22, 48 },
    { 275, 20, -139, 0, 0, 4096, 0, 0, 63, 0 },
    { 145, 20, -139, 0, 0, 4096, 0, 0, 22, 0 },
    { 324, 20, -260, 0, 0, 4096, 0, 0, 0, 63 },
    { 312, 20, -230, 0, 0, 4096, 0, 0, 0, 48 },
    { 348, 20, -208, 0, 0, 4096, 0, 0, 10, 48 },
    { 371, 20, -231, 0, 0, 4096, 0, 0, 10, 63 },
    { 278, 20, -138, 0, 0, 4095, 0, 0, 10, 0 },
    { 275, 20, -139, 0, 0, 4096, 0, 0, 0, 0 },
    { 370, 20, -62, 0, 0, 4096, 0, 0, 63, 48 },
    { 399, 20, -128, 0, 0, 4096, 0, 0, 26, 63 },
    { 400, 20, -62, 0, 0, 4096, 0, 0, 63, 63 },
    { 280, 20, -128, 0, 0, 4096, 0, 0, 26, 0 },
    { 279, 20, -62, 0, 0, 4096, 0, 0, 63, 0 },
    { 370, 20, -18, 0, 0, 4096, 0, 0, 6, 48 },
    { 348, 20, 17, 0, 0, 4096, 0, 0, 19, 48 },
    { 400, 20, -6, 0, 0, 4096, 0, 0, 6, 63 },
    { 371, 20, 40, 0, 0, 4096, 0, 0, 19, 63 },
    { 278, 20, -52, 0, 0, 4096, 0, 0, 19, 0 },
    { 279, 20, -55, 0, 0, 4096, 0, 0, 6, 0 },
    { -5, 20, 38, 0, 0, 4096, 0, 0, 0, 48 },
    { -141, 20, 38, 0, 0, 4096, 0, 0, 63, 48 },
    { -5, 20, 68, 0, 0, 4096, 0, 0, 0, 63 },
    { -141, 20, 68, 0, 0, 4096, 0, 0, 63, 63 },
    { -5, 20, -20, 0, 0, 4096, 0, 0, 63, 17 },
    { 129, 20, -50, 0, 0, 4096, 0, 0, 0, 0 },
    { -5, 20, -50, 0, 0, 4096, 0, 0, 63, 0 },
    { 129, 20, -20, 0, 0, 4096, 0, 0, 0, 17 },
    { -297, 20, 38, 0, 0, 4096, 0, 0, 27, 48 },
    { -288, 20, 70, 0, 0, 4096, 0, 0, 38, 63 },
    { -285, 20, 68, 0, 0, 4095, 0, 0, 27, 63 },
    { -311, 20, 47, 0, 0, 4096, 0, 0, 38, 48 },
    { -334, 20, -50, 0, 0, 4096, 0, 0, 27, 0 },
    { -381, 20, -22, 0, 0, 4096, 0, 0, 38, 0 },
    { -319, 20, 306, 0, 0, 4096, 0, 0, 63, 48 },
    { -289, 20, 194, 0, 0, 4095, 0, 0, 0, 63 },
    { -319, 20, 194, 0, 0, 4096, 0, 0, 0, 48 },
    { -289, 20, 306, 0, 0, 4096, 0, 0, 63, 63 },
    { -410, 20, 194, 0, 0, 4096, 0, 0, 63, 0 },
    { -380, 20, 82, 0, 0, 4096, 0, 0, 0, 17 },
    { -410, 20, 82, 0, 0, 4096, 0, 0, 0, 0 },
    { -380, 20, 194, 0, 0, 4096, 0, 0, 63, 17 },
    { -319, 20, 352, 0, 0, 4096, 0, 0, 14, 48 },
    { -341, 20, 388, 0, 0, 4096, 0, 0, 26, 48 },
    { -289, 20, 364, 0, 0, 4096, 0, 0, 14, 63 },
    { -318, 20, 411, 0, 0, 4096, 0, 0, 26, 63 },
    { -411, 20, 318, 0, 0, 4096, 0, 0, 26, 0 },
    { -410, 20, 315, 0, 0, 4096, 0, 0, 14, 0 },
    { -676, 20, 349, 0, 0, 4096, 0, 0, 63, 17 },
    { -532, 20, 350, 0, 0, 4096, 0, 0, 31, 17 },
    { -532, 20, 319, 0, 0, 4096, 0, 0, 31, 0 },
    { -676, 20, 319, 0, 0, 4095, 0, 0, 63, 0 },
    { -820, 20, 439, 0, 0, 4096, 0, 0, 63, 63 },
    { -676, 20, 440, 0, 0, 4096, 0, 0, 0, 63 },
    { -676, 20, 409, 0, 0, 4096, 0, 0, 0, 48 },
    { -820, 20, 409, 0, 0, 4096, 0, 0, 63, 48 },
    { 189, 20, -335, 0, 0, 4096, 0, 0, 21, 63 },
    { 70, 20, -384, 0, 0, 4096, 0, 0, 21, 0 },
    { 399, 20, -184, 0, 0, 4096, 0, 0, 20, 63 },
    { 280, 20, -135, 0, 0, 4096, 0, 0, 20, 0 },
    { 324, 20, 68, 0, 0, 4096, 0, 0, 31, 63 },
    { 275, 20, -50, 0, 0, 4096, 0, 0, 31, 0 },
    { -289, 20, 73, 0, 0, 4096, 0, 0, 49, 63 },
    { -410, 20, 24, 0, 0, 4096, 0, 0, 49, 0 },
    { -365, 20, 440, 0, 0, 4096, 0, 0, 38, 63 },
    { -414, 20, 319, 0, 0, 4096, 0, 0, 38, 0 },
    { 207, 20, -339, 0, 0, 4096, 0, 0, 30, 63 },
    { 207, 20, -369, 0, 0, 4096, 0, 0, 30, 48 },
    { 194, 20, -339, 0, 0, 4095, 0, 0, 63, 63 },
    { 182, 20, -369, 0, 0, 4096, 0, 0, 63, 48 },
    { 207, 20, -460, 0, 0, 4096, 0, 0, 30, 0 },
    { 145, 20, -460, 0, 0, 4096, 0, 0, 63, 0 },
    { 864, 20, -430, 0, 0, 4096, 0, 0, 63, 17 },
    { 1000, 20, -429, 0, 0, 4096, 0, 0, 0, 17 },
    { 1000, 20, -459, 0, 0, 4096, 0, 0, 0, 0 },
    { 864, 20, -460, 0, 0, 4096, 0, 0, 63, 0 },
    { 864, 20, -370, 0, 0, 4096, 0, 0, 0, 48 },
    { 728, 20, -339, 0, 0, 4095, 0, 0, 63, 63 },
    { 864, 20, -339, 0, 0, 4096, 0, 0, 0, 63 },
    { 728, 20, -370, 0, 0, 4096, 0, 0, 63, 48 },
    { 189, 20, -271, 0, 0, 4096, 0, 0, 0, 63 },
    { 159, 20, -271, 0, 0, 4096, 0, 0, 0, 48 },
    { 70, 20, -271, 0, 0, 4095, 0, 0, 0, 0 },
    { 400, 20, -62, 0, 0, 4096, 0, 0, 0, 63 },
    { 370, 20, -62, 0, 0, 4096, 0, 0, 0, 48 },
    { 279, 20, -62, 0, 0, 4096, 0, 0, 0, 0 },
    { -276, 20, 68, 0, 0, 4096, 0, 0, 0, 63 },
    { -276, 20, 38, 0, 0, 4096, 0, 0, 0, 48 },
    { -276, 20, -50, 0, 0, 4096, 0, 0, 0, 0 },
    { 264, 20, -20, 0, 0, 4096, 0, 0, 63, 17 },
    { 264, 20, -50, 0, 0, 4096, 0, 0, 63, 0 },
    { 264, 20, 68, 0, 0, 4095, 0, 0, 63, 63 },
    { -289, 20, 306, 0, 0, 4096, 0, 0, 0, 63 },
    { -319, 20, 306, 0, 0, 4096, 0, 0, 0, 48 },
    { -410, 20, 306, 0, 0, 4096, 0, 0, 0, 0 },
    { -410, 20, 82, 0, 0, 4096, 0, 0, 63, 0 },
    { -380, 20, 82, 0, 0, 4096, 0, 0, 63, 17 },
    { -289, 20, 82, 0, 0, 4096, 0, 0, 63, 63 },
    { -450, 20, 350, 0, 0, 4096, 0, 0, 63, 17 },
    { -450, 20, 319, 0, 0, 4096, 0, 0, 63, 0 },
    { -450, 20, 440, 0, 0, 4096, 0, 0, 63, 63 },
    { 728, 20, -430, 0, 0, 4096, 0, 0, 0, 17 },
    { 545, 20, -400, 0, 0, 4096, 0, 0, 63, 33 },
    { 728, 20, -400, 0, 0, 4096, 0, 0, 0, 33 },
    { 545, 20, -430, 0, 0, 4096, 0, 0, 63, 17 },
    { 398, 20, -400, 0, 0, 4096, 0, 0, 63, 33 },
    { 545, 20, -400, 0, 0, 4096, 0, 0, 0, 33 },
    { 279, 20, -400, 0, 0, 4096, 0, 0, 0, 33 },
    { 279, 20, -430, 0, 0, 4096, 0, 0, 0, 17 },
    { 279, 0, -339, 0, 0, 0, 4096, 0, 18, 59 },
    { 279, 20, -339, 0, 0, 0, 4096, 0, 18, 62 },
    { 279, 20, -460, 0, 0, 0, -4096, 0, 18, 59 },
    { 279, 0, -460, 0, 0, 0, -4096, 0, 18, 62 },
    { 728, 20, -370, 0, 0, 4096, 0, 0, 0, 48 },
    { 545, 20, -369, 0, 0, 4096, 0, 0, 63, 48 },
    { 728, 20, -339, 0, 0, 4095, 0, 0, 0, 63 },
    { 545, 20, -339, 0, 0, 4096, 0, 0, 63, 63 },
    { 545, 20, -339, 0, 0, 4096, 0, 0, 0, 63 },
    { 398, 20, -369, 0, 0, 4096, 0, 0, 63, 48 },
    { 398, 20, -339, 0, 0, 4095, 0, 0, 63, 63 },
    { 545, 20, -369, 0, 0, 4096, 0, 0, 0, 48 },
    { 279, 20, -339, 0, 0, 4096, 0, 0, 0, 63 },
    { 279, 20, -369, 0, 0, 4096, 0, 0, 0, 48 },
    { 279, 20, -460, 0, 0, 4096, 0, 0, 0, 0 },
    { 398, 20, -460, 0, 0, 4096, 0, 0, 0, 0 },
    { 279, 20, -460, 0, 0, 4096, 0, 0, 63, 0 },
    { 728, 20, -460, 0, 0, 4096, 0, 0, 0, 0 },
    { 545, 20, -460, 0, 0, 4096, 0, 0, 63, 0 },
    { -1000, 20, 409, 0, 0, 4095, 0, 0, 63, 17 },
    { -820, 20, 409, 0, 0, 4096, 0, 0, 0, 17 },
    { -820, 20, 379, 0, 0, 4096, 0, 0, 0, 33 },
    { -1000, 20, 379, 0, 0, 4096, 0, 0, 63, 33 },
    { -676, 20, 379, 0, 0, 4096, 0, 0, 0, 33 },
    { -820, 20, 379, 0, 0, 4096, 0, 0, 63, 33 },
    { -450, 20, 380, 0, 0, 4096, 0, 0, 0, 33 },
    { -450, 20, 410, 0, 0, 4096, 0, 0, 0, 48 },
    { -531, 20, 440, 0, 0, 0, 4096, 0, 5, 62 },
    { -531, 0, 440, 0, 0, 0, 4096, 0, 5, 59 },
    { -1000, 0, 439, 0, 0, 0, 4096, 0, 2, 59 },
    { -1000, 20, 439, 0, 0, 0, 4096, 0, 2, 62 },
    { -532, 0, 319, 0, 0, 0, -4096, 0, 5, 62 },
    { -532, 20, 319, 0, 0, 0, -4096, 0, 5, 59 },
    { -1000, 0, 319, 0, 0, 0, -4096, 0, 2, 62 },
    { -1000, 20, 319, 0, 0, 0, -4096, 0, 2, 59 },
    { -1000, 20, 349, 0, 0, 4095, 0, 0, 63, 48 },
    { -820, 20, 349, 0, 0, 4096, 0, 0, 0, 48 },
    { -820, 20, 319, 0, 0, 4096, 0, 0, 0, 63 },
    { -1000, 20, 319, 0, 0, 4096, 0, 0, 63, 63 },
    { -820, 20, 349, 0, 0, 4096, 0, 0, 63, 17 },
    { -676, 20, 349, 0, 0, 4096, 0, 0, 0, 17 },
    { -676, 20, 319, 0, 0, 4095, 0, 0, 0, 0 },
    { -820, 20, 319, 0, 0, 4096, 0, 0, 63, 0 },
    { -450, 20, 319, 0, 0, 4096, 0, 0, 0, 0 },
    { -450, 20, 350, 0, 0, 4096, 0, 0, 0, 17 },
    { -531, 20, 440, 0, 0, 4096, 0, 0, 31, 63 },
    { -450, 20, 440, 0, 0, 4096, 0, 0, 0, 63 },
    { -676, 20, 440, 0, 0, 4096, 0, 0, 63, 63 },
    { -1000, 20, 439, 0, 0, 4095, 0, 0, 63, 0 },
    { -820, 20, 439, 0, 0, 4096, 0, 0, 0, 0 },
    { 728, 20, -400, 0, 0, 4096, 0, 0, 63, 33 },
    { 864, 20, -400, 0, 0, 4096, 0, 0, 0, 33 },
    { 1000, 0, -339, 0, 0, 0, 4096, 0, 23, 59 },
    { 1000, 20, -339, 0, 0, 0, 4096, 0, 23, 62 },
    { 1000, 0, -459, 0, 0, 0, -4096, 0, 23, 62 },
    { 1000, 20, -459, 0, 0, 0, -4096, 0, 23, 59 },
    { 728, 20, -430, 0, 0, 4096, 0, 0, 63, 17 },
    { 864, 20, -460, 0, 0, 4096, 0, 0, 0, 0 },
    { 728, 20, -460, 0, 0, 4096, 0, 0, 63, 0 },
    { 864, 20, -430, 0, 0, 4096, 0, 0, 0, 17 },
    { 864, 20, -339, 0, 0, 4096, 0, 0, 63, 63 },
    { 1000, 20, -339, 0, 0, 4096, 0, 0, 0, 63 },
    { 264, 20, -20, 0, 0, 4096, 0, 0, 0, 17 },
    { 129, 20, 8, 0, 0, 4096, 0, 0, 63, 33 },
    { 264, 20, 8, 0, 0, 4096, 0, 0, 0, 33 },
    { 129, 20, -20, 0, 0, 4096, 0, 0, 63, 17 },
    { -5, 20, 8, 0, 0, 4096, 0, 0, 63, 33 },
    { 129, 20, 8, 0, 0, 4096, 0, 0, 0, 33 },
    { -276, 20, 8, 0, 0, 4096, 0, 0, 63, 33 },
    { -141, 20, -20, 0, 0, 4096, 0, 0, 0, 17 },
    { -276, 20, -20, 0, 0, 4096, 0, 0, 63, 17 },
    { -141, 20, 8, 0, 0, 4096, 0, 0, 0, 33 },
    { -141, 0, 68, 0, 0, 0, 4096, 0, 10, 59 },
    { -141, 20, 68, 0, 0, 0, 4096, 0, 10, 62 },
    { -141, 20, -50, 0, 0, 0, -4096, 0, 10, 59 },
    { -141, 0, -50, 0, 0, 0, -4096, 0, 10, 62 },
    { 264, 20, 38, 0, 0, 4096, 0, 0, 0, 48 },
    { 129, 20, 38, 0, 0, 4096, 0, 0, 63, 48 },
    { 264, 20, 68, 0, 0, 4095, 0, 0, 0, 63 },
    { 129, 20, 68, 0, 0, 4096, 0, 0, 63, 63 },
    { 129, 20, 38, 0, 0, 4096, 0, 0, 0, 48 },
    { -5, 20, 38, 0, 0, 4096, 0, 0, 63, 48 },
    { 129, 20, 68, 0, 0, 4096, 0, 0, 0, 63 },
    { -5, 20, 68, 0, 0, 4096, 0, 0, 63, 63 },
    { -141, 20, 68, 0, 0, 4096, 0, 0, 0, 63 },
    { -276, 20, 38, 0, 0, 4096, 0, 0, 63, 48 },
    { -276, 20, 68, 0, 0, 4096, 0, 0, 63, 63 },
    { -141, 20, 38, 0, 0, 4096, 0, 0, 0, 48 },
    { -141, 20, -50, 0, 0, 4096, 0, 0, 0, 0 },
    { -276, 20, -50, 0, 0, 4096, 0, 0, 63, 0 },
    { -5, 20, -50, 0, 0, 4096, 0, 0, 0, 0 },
    { -141, 20, -50, 0, 0, 4096, 0, 0, 63, 0 },
    { 264, 20, -50, 0, 0, 4096, 0, 0, 0, 0 },
    { 129, 20, -50, 0, 0, 4096, 0, 0, 63, 0 },
    { -349, 20, 194, 0, 0, 4096, 0, 0, 63, 33 },
    { -350, 20, 82, 0, 0, 4096, 0, 0, 0, 33 },
    { -289, 20, 194, 0, 0, 4095, 0, 0, 63, 63 },
    { -289, 20, 82, 0, 0, 4096, 0, 0, 0, 63 },
    { -319, 20, 194, 0, 0, 4096, 0, 0, 63, 48 },
    { -319, 20, 82, 0, 0, 4096, 0, 0, 0, 48 },
    { -410, 20, 306, 0, 0, 4096, 0, 0, 63, 0 },
    { -410, 20, 194, 0, 0, 4096, 0, 0, 0, 0 }
};
static u_short Path_P2_Indices[] = {
    0, 2, 1, 1, 3, 0, 4, 6, 5, 7, 5, 6, 8, 10, 9, 9, 11, 8, 12, 14, 13, 13, 15, 12, 16, 18, 17, 18, 16, 19, 20, 22, 21, 
    21, 23, 20, 24, 26, 25, 25, 27, 24, 28, 30, 29, 31, 29, 30, 32, 34, 33, 33, 35, 32, 36, 38, 37, 38, 39, 37, 40, 42, 41, 42, 40, 
    43, 44, 46, 45, 45, 47, 44, 48, 50, 49, 51, 49, 50, 52, 54, 53, 53, 55, 52, 56, 58, 57, 57, 59, 56, 60, 62, 61, 60, 63, 62, 64, 
    65, 55, 52, 55, 65, 58, 67, 66, 66, 57, 58, 68, 70, 69, 70, 68, 71, 72, 74, 73, 75, 73, 74, 76, 78, 77, 77, 79, 76, 80, 82, 81, 
    80, 83, 82, 84, 86, 85, 87, 85, 86, 88, 90, 89, 89, 91, 88, 92, 94, 93, 93, 95, 92, 96, 98, 97, 99, 97, 98, 100, 102, 101, 101, 103, 
    100, 104, 106, 105, 105, 107, 104, 108, 110, 109, 110, 108, 111, 112, 114, 113, 113, 115, 112, 116, 118, 117, 118, 116, 119, 120, 122, 121, 123, 121, 122, 124, 
    126, 125, 125, 127, 124, 128, 130, 129, 128, 131, 130, 132, 134, 133, 135, 133, 134, 136, 138, 137, 137, 139, 136, 140, 142, 141, 140, 143, 142, 144, 146, 145, 
    145, 147, 144, 148, 150, 149, 151, 149, 150, 15, 13, 152, 152, 13, 153, 19, 154, 18, 154, 19, 155, 22, 157, 156, 156, 21, 22, 38, 51, 39, 38, 49, 
    51, 43, 54, 42, 54, 43, 53, 46, 56, 59, 59, 45, 46, 62, 63, 158, 158, 159, 62, 160, 161, 64, 65, 64, 161, 67, 163, 162, 162, 66, 67, 80, 
    81, 164, 164, 165, 80, 166, 167, 84, 86, 84, 167, 90, 169, 168, 168, 89, 90, 107, 105, 170, 170, 105, 171, 111, 172, 110, 172, 111, 173, 174, 175, 113, 
    113, 114, 174, 128, 129, 176, 176, 177, 128, 178, 179, 132, 134, 132, 179, 138, 181, 180, 180, 137, 138, 182, 184, 183, 184, 185, 183, 186, 188, 187, 186, 189, 
    188, 190, 191, 17, 17, 191, 16, 192, 194, 193, 193, 195, 192, 196, 20, 23, 23, 197, 196, 198, 200, 199, 201, 199, 200, 37, 202, 36, 36, 202, 203, 25, 
    205, 204, 25, 153, 205, 28, 41, 30, 41, 28, 40, 31, 154, 155, 155, 29, 31, 34, 44, 47, 47, 33, 34, 156, 157, 35, 32, 35, 157, 82, 83, 206, 
    83, 207, 206, 208, 71, 158, 208, 158, 209, 85, 87, 72, 74, 72, 87, 75, 161, 160, 160, 73, 75, 78, 88, 91, 91, 77, 78, 79, 163, 76, 163, 79, 
    162, 210, 106, 211, 106, 104, 211, 212, 164, 213, 212, 214, 164, 215, 109, 216, 109, 215, 108, 217, 167, 166, 166, 218, 217, 219, 112, 115, 115, 220, 219, 221, 
    169, 222, 169, 221, 168, 130, 131, 223, 131, 224, 223, 225, 227, 226, 225, 171, 227, 133, 135, 228, 229, 228, 135, 123, 172, 173, 173, 121, 123, 230, 136, 139, 
    139, 231, 230, 175, 174, 127, 124, 127, 174, 232, 176, 233, 232, 234, 176, 235, 179, 178, 178, 236, 235, 180, 181, 237, 238, 237, 181, 239, 241, 240, 242, 240, 
    241, 2, 239, 1, 240, 1, 239, 243, 245, 244, 244, 246, 243, 247, 249, 248, 248, 250, 247, 14, 247, 250, 250, 13, 14, 12, 15, 251, 251, 15, 252, 253, 
    204, 254, 254, 255, 253, 27, 25, 204, 204, 253, 27, 24, 257, 256, 256, 26, 24, 258, 260, 259, 260, 261, 259, 259, 261, 36, 261, 38, 36, 39, 262, 37, 
    262, 39, 263, 264, 266, 265, 267, 265, 266, 266, 48, 267, 49, 267, 48, 268, 269, 51, 51, 50, 268, 270, 272, 271, 270, 273, 272, 271, 63, 60, 271, 272, 
    63, 274, 275, 61, 61, 62, 274, 276, 208, 277, 277, 278, 276, 70, 71, 208, 208, 276, 70, 69, 280, 279, 279, 68, 69, 281, 283, 282, 282, 283, 284, 82, 
    281, 81, 81, 281, 282, 83, 80, 285, 285, 286, 83, 287, 289, 288, 290, 288, 289, 94, 287, 93, 288, 93, 287, 291, 293, 292, 292, 294, 291, 295, 297, 296, 
    296, 298, 295, 106, 295, 298, 298, 105, 106, 104, 107, 299, 299, 107, 300, 301, 303, 302, 302, 304, 301, 118, 119, 303, 303, 301, 118, 305, 307, 306, 306, 308, 
    305, 309, 311, 310, 310, 311, 312, 130, 309, 129, 129, 309, 310, 131, 128, 313, 313, 314, 131, 315, 317, 316, 315, 318, 317, 143, 316, 142, 143, 315, 316, 319, 
    321, 320, 319, 322, 321, 248, 205, 250, 205, 248, 323, 13, 250, 153, 153, 250, 205, 324, 252, 15, 15, 152, 324, 260, 267, 261, 260, 265, 267, 261, 49, 38, 
    261, 267, 49, 263, 39, 269, 39, 51, 269, 272, 273, 325, 325, 209, 272, 209, 158, 63, 63, 272, 209, 62, 159, 274, 159, 326, 274, 282, 284, 327, 327, 213, 
    282, 81, 282, 213, 213, 164, 81, 328, 285, 165, 80, 165, 285, 296, 227, 298, 227, 296, 329, 105, 298, 171, 171, 298, 227, 330, 300, 107, 107, 170, 330, 310, 
    312, 331, 331, 233, 310, 129, 310, 233, 233, 176, 129, 332, 313, 177, 128, 177, 313, 333, 335, 334, 335, 336, 334, 334, 336, 182, 336, 184, 182, 185, 337, 183, 
    337, 185, 338, 339, 341, 340, 339, 342, 341, 189, 340, 188, 189, 339, 340, 343, 345, 344, 344, 346, 343, 347, 258, 348, 259, 348, 258, 36, 203, 259, 259, 203, 
    348, 37, 262, 349, 349, 202, 37, 256, 324, 152, 256, 152, 26, 26, 152, 153, 26, 153, 25, 204, 323, 254, 204, 205, 323, 283, 281, 350, 281, 351, 350, 281, 
    82, 351, 82, 206, 351, 286, 207, 83, 286, 352, 207, 68, 279, 326, 326, 159, 68, 71, 68, 159, 159, 158, 71, 208, 209, 277, 277, 209, 325, 353, 297, 354, 
    297, 295, 354, 210, 354, 295, 295, 106, 210, 104, 355, 211, 355, 104, 299, 165, 356, 328, 356, 357, 328, 214, 356, 165, 165, 164, 214, 327, 358, 213, 358, 212, 
    213, 311, 309, 359, 309, 360, 359, 309, 130, 360, 130, 223, 360, 314, 224, 131, 314, 361, 224, 362, 330, 170, 362, 170, 363, 363, 170, 171, 363, 171, 225, 329, 
    364, 226, 226, 227, 329, 365, 332, 177, 365, 366, 332, 234, 177, 176, 234, 365, 177, 367, 233, 331, 367, 232, 233, 368, 370, 369, 369, 371, 368, 246, 373, 372, 
    372, 243, 246, 374, 182, 183, 183, 375, 374, 191, 190, 376, 377, 376, 190, 376, 377, 4, 6, 4, 377, 7, 192, 195, 195, 5, 7, 378, 196, 197, 197, 379, 
    378, 10, 378, 379, 379, 9, 10, 199, 201, 11, 8, 11, 201, 380, 382, 381, 383, 381, 382, 384, 386, 385, 385, 387, 384, 388, 333, 334, 334, 389, 388, 370, 
    380, 369, 381, 369, 380, 387, 385, 372, 372, 373, 387, 389, 334, 182, 182, 374, 389, 183, 337, 390, 390, 375, 183, 3, 392, 391, 391, 0, 3, 393, 368, 371, 
    371, 394, 393, 395, 397, 396, 395, 398, 397, 322, 399, 321, 322, 400, 399, 401, 402, 141, 141, 142, 401, 403, 235, 236, 236, 404, 403, 146, 403, 404, 404, 145, 
    146, 405, 406, 147, 144, 147, 406, 237, 238, 407, 408, 407, 238, 407, 408, 148, 150, 148, 408, 151, 410, 409, 409, 149, 151, 411, 413, 412, 411, 414, 413, 415, 
    417, 416, 415, 418, 417, 419, 420, 316, 316, 317, 419, 398, 412, 397, 398, 411, 412, 400, 416, 399, 400, 415, 416, 420, 401, 142, 142, 316, 420, 402, 422, 421, 
    421, 141, 402, 423, 141, 421, 423, 140, 141, 424, 395, 396, 396, 425, 424, 343, 346, 426, 426, 427, 343, 194, 429, 428, 428, 193, 194, 430, 431, 198, 200, 198, 
    431, 432, 434, 433, 433, 435, 432, 427, 426, 432, 432, 435, 427, 187, 437, 436, 436, 186, 187, 438, 440, 439, 439, 441, 438, 294, 443, 442, 442, 291, 294, 444, 
    446, 445, 445, 447, 444, 215, 216, 448, 449, 448, 216, 448, 449, 96, 98, 96, 449, 99, 217, 218, 218, 97, 99, 450, 219, 220, 220, 451, 450, 100, 450, 451, 
    451, 102, 100, 221, 222, 101, 103, 101, 222, 452, 454, 453, 455, 453, 454, 456, 458, 457, 459, 457, 458, 460, 462, 461, 461, 463, 460, 440, 452, 439, 453, 439, 
    452, 457, 443, 456, 457, 442, 443, 461, 444, 447, 447, 463, 461, 446, 465, 464, 464, 445, 446, 95, 467, 466, 466, 92, 95, 468, 438, 441, 441, 469, 468, 470, 
    308, 471, 308, 306, 471, 228, 229, 120, 122, 120, 229, 126, 230, 231, 231, 125, 126, 472, 474, 473, 474, 475, 473, 474, 470, 475, 470, 471, 475, 117, 476, 116, 
    476, 477, 116
};
static SDC_Mesh3D Path_P2_Mesh = {Path_P2_Vertices, Path_P2_Indices, NULL, 1476, 478, POLIGON_VERTEX_TEXTURED_NORMAL};
#endif