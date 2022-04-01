#include <iostream>
#include "SCUtility.h"
using namespace std;

void showEnergy(SeamCarver& sc) {
    double** energies = toEnergyMatrix(sc);
    doubleToPicture( energies, sc.width(), sc.height() ).show(true);

    // clean up memory
    for (int w = 0; w < sc.width(); w++) {
        delete[] energies[w];
    }
    delete[] energies;
}

void saveEnergy(SeamCarver& sc, char* filename) {
    double** energies = toEnergyMatrix(sc);
    doubleToPicture( energies, sc.width(), sc.height() ).save(filename);

    // clean up memory
    for (int w = 0; w < sc.width(); w++) {
        delete[] energies[w];
    }
    delete[] energies;
}

double** toEnergyMatrix(SeamCarver& sc) {
    double** a = new double*[sc.width()];
    for (int col = 0; col < sc.width(); col++) {
        a[col] = new double[sc.height()];
        for (int row = 0; row < sc.height(); row++) {
            a[col][row] = sc.energy(col, row);
        }
    }
    return a;
}

Picture toEnergyPicture(SeamCarver& sc) {
    double** energies = toEnergyMatrix(sc);
    Picture pic = doubleToPicture( energies, sc.width(), sc.height() );

    // clean up memory
    for (int w = 0; w < sc.width(); w++) {
        delete[] energies[w];
    }
    delete[] energies;

    return pic;
}

Picture doubleToPicture(double** grayValues, int width, int height) {
    Picture picture(height, width);

    double maxVal = 0;
    for (int col = 0; col < width; col++) {
        for (int row = 0; row < height; row++) {
            if (grayValues[col][row] > maxVal) {
                maxVal = grayValues[col][row];
            }
        }
    }

    if (maxVal == 0)
        return picture;  // return black picture

    for (int col = 0; col < width; col++) {
        for (int row = 0; row < height; row++) {
            double normalizedGrayValue = (grayValues[col][row] / maxVal) * 255;
            Color gray(normalizedGrayValue, normalizedGrayValue, normalizedGrayValue);
            picture.set(row, col, gray);
        }
    }

    return picture;
}

Picture seamOverlay(Picture& picture, bool isHorizontal, const vector<int>& seam) {
    Picture overlaid(picture);

    // if horizontal seam, set one pixel in every column
    if (isHorizontal) {
        for (int col = 0; col < picture.width(); col++) {
            overlaid.set(seam.at(col), col, Color(255, 0, 0));
        }
    }
    // if vertical seam, set one pixel in each row
    else {
        for (int row = 0; row < picture.height(); row++) {
            overlaid.set(row, seam.at(row), Color(255, 0, 0));
        }
    }

    return overlaid;
}
