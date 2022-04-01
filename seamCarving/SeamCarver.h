#ifndef SEAMCARVER_H
#define SEAMCARVER_H
#include "picture.h"
#include <vector>
using namespace std;

class SeamCarver {
   public:
       SeamCarver(Picture& picture);                       // create a seam carver object based on the given picture
       ~SeamCarver();                                       // destructor
       Picture picture();                                 // current picture
       int width();                                         // width of current picture
       int height();                                        // height of current picture
       double energy(int x, int y);                         // energy of pixel at column x and row y
       vector<int> findHorizontalSeam();                    // sequence of indices for horizontal seam
       vector<int> findVerticalSeam();                      // sequence of indices for vertical seam
       void removeHorizontalSeam(const vector<int>& seam);  // remove horizontal seam from current picture
       void removeVerticalSeam(const vector<int>& seam);    // remove vertical seam from current picture
  private:
    Picture Pic;
    int Width;
    int Height;
    Color newcolor;
    
    struct Node{
      unsigned char R,G,B;
      double energy;
      Node* parent;
    };
    vector <vector<Node*> > Vec;
  };

#endif
