#include "picture.h"
#include "SeamCarver.h"
#include <iostream>
#include <stdio.h>
using namespace std;

const bool HORIZONTAL = true;
const bool VERTICAL = false;

void printSeam(SeamCarver& carver, const vector<int>& seam, bool direction) {
    double totalSeamEnergy = 0.0;

    for (int row = 0; row < carver.height(); row++) {
        for (int col = 0; col < carver.width(); col++) {
            double energy = carver.energy(col, row);
            string marker = " ";
            if ((direction == HORIZONTAL && row == seam[col]) ||
                (direction == VERTICAL   && col == seam[row])) {
                marker = "*";
                totalSeamEnergy += energy;
            }
            printf("%7.2f%s ", energy, marker.c_str());
        }
        printf("\n");
    }

    printf("Total energy = %f\n", totalSeamEnergy);
    printf("\n");
    printf("\n");
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: ./printSeams infile.bmp" << endl;
        return 1;
    }

    Picture pic(argv[1]);
    printf("%s (%d-by-%d image)\n", argv[1], pic.width(), pic.height());
    printf("\n");
    printf("The table gives the dual-gradient energies of each pixel.\n");
    printf("The asterisks denote a minimum energy vertical or horizontal seam.\n");
    printf("\n");

    SeamCarver carver(pic);

    printf("Vertical seam: { ");
    vector<int> verticalSeam = carver.findVerticalSeam();
    for (int x : verticalSeam)
        printf("%d ", x);
    printf("}\n");
    printSeam(carver, verticalSeam, VERTICAL);

    printf("Horizontal seam: { ");
    vector<int> horizontalSeam = carver.findHorizontalSeam();
    carver.picture();
    for (int y : horizontalSeam)
        printf("%d ", y);
    printf("}\n");
    printSeam(carver, horizontalSeam, HORIZONTAL);

    return 0;
}
