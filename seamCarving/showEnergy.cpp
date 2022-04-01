#include "picture.h"
#include "SCUtility.h"
#include "SeamCarver.h"
#include <iostream>
#include <stdio.h>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cout << "Usage: ./showEnergy infile.bmp [outfile.bmp]" << endl;
        return 1;
    }

    Picture pic(argv[1]);
    printf( "%d-by-%d image\n", pic.width(), pic.height() );
    pic.show(true);
    SeamCarver sc(pic);

    printf("Displaying energy calculated for each pixel.\n");
    showEnergy(sc);

    if (argc > 2)
        saveEnergy(sc, argv[2]);

    return 0;
}
