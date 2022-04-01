#include "picture.h"
#include "SCUtility.h"
#include "SeamCarver.h"
#include <iostream>
#include <stdio.h>
using namespace std;

void saveVerticalSeam(SeamCarver& sc, char* filename) {
    Picture ep = toEnergyPicture(sc);
    vector<int> verticalSeam = sc.findVerticalSeam();
    Picture epOverlay = seamOverlay(ep, false, verticalSeam);
    epOverlay.show(true);
    epOverlay.save(filename);
}

void showVerticalSeam(SeamCarver& sc) {
    Picture ep = toEnergyPicture(sc);
    vector<int> verticalSeam = sc.findVerticalSeam();
    Picture epOverlay = seamOverlay(ep, false, verticalSeam);
    epOverlay.show(true);
}

void saveHorizontalSeam(SeamCarver& sc, char* filename) {
    Picture ep = toEnergyPicture(sc);
    vector<int> horizontalSeam = sc.findHorizontalSeam();
    Picture epOverlay = seamOverlay(ep, true, horizontalSeam);
    epOverlay.show(true);
    epOverlay.save(filename);
}

void showHorizontalSeam(SeamCarver& sc) {
    Picture ep = toEnergyPicture(sc);
    vector<int> horizontalSeam = sc.findHorizontalSeam();
    Picture epOverlay = seamOverlay(ep, true, horizontalSeam);
    epOverlay.show(true);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: ./showSeams infile.bmp [outfile.bmp]" << endl;
        return 1;
    }

    Picture pic(argv[1]);
    printf( "%d-by-%d image\n", pic.width(), pic.height() );
    pic.show(true);
    SeamCarver sc(pic);

    printf("Displaying vertical seam calculated.\n");
    if (argc > 2)
        saveVerticalSeam(sc, argv[2]);
    else
        showVerticalSeam(sc);

    printf("Displaying horizontal seam calculated.\n");
    if (argc > 2)
        saveHorizontalSeam(sc, argv[2]);
    else
        showHorizontalSeam(sc);

    return 0;
}
