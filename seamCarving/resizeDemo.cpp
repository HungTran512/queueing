#include "picture.h"
#include "SCUtility.h"
#include "SeamCarver.h"
#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cmath>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cout << "Usage: ./showSeams infile.bmp [num columns to remove] [num rows to remove] [outfile.bmp]" << endl;
        return 1;
    }

    Picture pic(argv[1]);
    int removeColumns = atoi(argv[2]);
    int removeRows = atoi(argv[3]);

    printf( "%d-by-%d image\n", pic.width(), pic.height() );
    SeamCarver sc(pic);
    clock_t start;
    double duration;
    start = clock();
    for (int i = 0; i < removeRows; i++) {
            vector<int> horizontalSeam = sc.findHorizontalSeam();
            sc.removeHorizontalSeam(horizontalSeam);
    }

    for (int i = 0; i < removeColumns; i++) {
        vector<int> verticalSeam = sc.findVerticalSeam();
        sc.removeVerticalSeam(verticalSeam);
    }
    duration = (clock() - start ) / (double) CLOCKS_PER_SEC;
    cout << "It takes " << duration << " seconds to reduce " << removeColumns << " columns" << endl;

    printf("new image size is %d columns by %d rows\n", sc.width(), sc.height());

    pic.show(true);
    Picture p = sc.picture();
    p.show(true);

    if (argc > 4)
        p.save(argv[4]);

    return 0;
}
