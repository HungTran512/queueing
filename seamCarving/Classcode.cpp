#include "picture.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
  Picture pic (argv[1]);
  for (int row =0; row < pic.height(); row++){
    for (int col = 0 ; col < pic.width(); col ++){
      Color color = pic.get(row,col);
      Color newcolor;
      double luminace = 0.299*color.red + 0.587*color.green +
      0.114*color.blue; // fot gray scale

      // newcolor.red = int (luminace);
      // newcolor.green = int (luminace);
      // newcolor.blue = int (luminace);
      newcolor.red = color.green;
      newcolor.green = color.blue;
      newcolor.blue = color.red;

      pic.set(row,col,newcolor);
    }
  }
  pic.save(argv[2]);
  return 0;
}
