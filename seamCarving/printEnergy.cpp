#include "picture.h"
#include "SeamCarver.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: ./printEnergy infile.bmp" << endl;
        return 1;
    }

    // open the file and construct a Picture object
    Picture pic(argv[1]);
    printf( "%d-by-%d image\n", pic.width(), pic.height() );

    SeamCarver sc(pic);

    printf("Priniting energy calculated for each pixel.\n");

    for (int row = 0; row < sc.height(); row++) {
        for (int col = 0; col < sc.width(); col++) {
            printf( "%9.2f ", sc.energy(col, row) );
        }
        printf("\n");
    }

    return 0;
}
