#ifndef SCUTILITY_H
#define SCUTILITY_H

#include "picture.h"
#include "SeamCarver.h"

// displays grayscale values as energy (converts to picture, calls show)
void showEnergy(SeamCarver& sc);

// saves grayscale energy image (converts to picture, calls save)
void saveEnergy(SeamCarver& sc, char* filename);

// convert SeamCarver picture to W-by-H energy matrix
double** toEnergyMatrix(SeamCarver& sc);

// returns picture of energy matrix associated with SeamCarver picture
Picture toEnergyPicture(SeamCarver& sc);

/* converts a double matrix of values into a normalized picture; values are
normalized by the maximum grayscale value */
Picture doubleToPicture(double** grayValues, int width, int height);

/* this funciton is useful for debugging seams; it overlays red pixels over the
calculated seam */
Picture seamOverlay(Picture& picture, bool isHorizontal, const vector<int>& seam);

#endif
