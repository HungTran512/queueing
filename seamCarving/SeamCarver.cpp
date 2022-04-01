#include "SeamCarver.h"
#include "picture.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

//constructor
SeamCarver::SeamCarver(Picture& picture):Pic(picture){
  Width = picture.width();
  Height = picture.height();
  Vec.resize(Height);
  for (int i = 0; i < Height; i++){
    Vec[i].resize(Width);
    for (int j = 0; j < Width; j++){
      Color color = Pic.get(i,j);
      Node* node = new Node;
      node->R = color.red;
      node->G = color.green;
      node->B = color.blue;
      node->energy = -1;
      node->parent = nullptr;
      Vec[i][j] = node;
    }
  }
}
//destrcutor
SeamCarver::~SeamCarver(){
  for (int i = 0; i < Height; i++){
    for (int j = 0; j < Width; j++){
      delete Vec[i][j];
    }
  }
}

Picture SeamCarver::picture(){
  return Pic;
}

int SeamCarver::width(){
  return Width;
}

int SeamCarver::height(){
  return Height;
}

// compute energy
double SeamCarver::energy(int x, int y){
  Color color_left;
  Color color_right;
  if (x == 0){
     color_left = Pic.get(y,Width-1);
     color_right = Pic.get(y,x+1);
}
  else if (x == Width - 1){
     color_left = Pic.get(y,x-1);
     color_right = Pic.get(y,0);
  }
  else {
     color_left = Pic.get(y,x-1);
     color_right = Pic.get(y,x+1);
  }
  int redx = color_left.red - color_right.red;
  int greenx = color_left.green - color_right.green;
  int bluex = color_left.blue - color_right.blue;

  int energyx = (redx*redx) + (greenx*greenx) + (bluex*bluex);

  Color color_up;
  Color color_low;
  if(y == 0){
     color_up = Pic.get(Height-1,x);
     color_low = Pic.get(y+1,x );
  }
  else if(y == Height-1){
     color_up = Pic.get(y-1,x);
     color_low = Pic.get(0,x);
  }
  else {
     color_up = Pic.get(y-1,x);
     color_low = Pic.get(y+1,x);
  }

  int redy = color_up.red - color_low .red;
  int greeny = color_up.green - color_low .green;
  int bluey = color_up.blue - color_low.blue;

  int energyy = (redy*redy) + (greeny*greeny) + (bluey*bluey);

  double energy = sqrt(energyx + energyy);
  return energy;
}

vector <int> SeamCarver::findHorizontalSeam(){
  //tranposing picture
  Picture temp_pic(Width,Height);
  for(int i = 0; i < Height; i++){
    for(int j = 0; j < Width; j++){
      Color color = Pic.get(i,j);
      temp_pic.set(j,i,color);
    }
  }

  SeamCarver test(temp_pic);

  vector<int> HorizontalSeam = test.findVerticalSeam();

  return HorizontalSeam;
}

vector<int> SeamCarver::findVerticalSeam(){
  vector<int> VerticalSeam;
  // special case for first row
  for (int j = 0; j < Width; j++){
    Vec[0][j]->energy = energy(j,0);
  }

  for (int i = 1; i < Height; i++){
    for (int j = 0; j < Width; j++){
      if(j > 0 && j < (Width-1)){
        auto parent = min(min(Vec[i-1][j-1]->energy,Vec[i-1][j]->energy),Vec[i-1][j+1]->energy);
        if(parent == Vec[i-1][j-1]->energy){
          Vec[i][j]->parent = Vec[i-1][j-1];
        }
        else if (parent == Vec[i-1][j]->energy){
          Vec[i][j]->parent = Vec[i-1][j];
        }
        else{
          Vec[i][j]->parent = Vec[i-1][j+1];
        }
        //actually find parent
        Vec[i][j]->energy = Vec[i][j]->parent->energy + energy(j,i);
      }
      else if (j == 0){
        auto parent = min(Vec[i-1][j+1]->energy,Vec[i-1][j]->energy);
        if(parent == Vec[i-1][j+1]->energy){
          Vec[i][j]->parent = Vec[i-1][j+1];
        }
        else {
          Vec[i][j]->parent = Vec[i-1][j];
        }
        Vec[i][j]->energy = Vec[i][j]->parent->energy + energy(j,i);
      }
      else{
        auto parent = min(Vec[i-1][j]->energy,Vec[i-1][j-1]->energy);
        if(parent == Vec[i-1][j]->energy){
          Vec[i][j]->parent = Vec[i-1][j];
          Vec[i][j]->energy = Vec[i][j]->parent->energy + energy(j,i);
        }
        else {
          Vec[i][j]->parent = Vec[i-1][j-1];
        }
        Vec[i][j]->energy = Vec[i][j]->parent->energy + energy(j,i);
       }
    }
  }
  for (int j = 0; j < Width; j++){
    Vec[0][j]->energy = energy(j,0);
  }
  //loop through the last row, find the element with the lowest energy count and track back.
  auto min = Vec[Height-1][0]->energy;
  int index = 0;
  for (int j = 0; j < Width; j++){
    if(min > Vec[Height-1][j]->energy){
      min = Vec[Height-1][j]->energy;
      index = j;
    }
  }
  VerticalSeam.push_back(index);

    Node* curr = new Node;
    curr->energy = Vec[Height-1][index]->energy;
    curr->parent = Vec[Height-1][index]->parent;
    int id = Height - 1;
  while(curr->parent){
    if(index > 0 && index < (Width - 1)){
      if(Vec[id-1][index-1]->energy == curr->parent->energy){
        VerticalSeam.push_back(index-1);
        index--;
      }
      else if(Vec[id-1][index]->energy == curr->parent->energy){
        VerticalSeam.push_back(index);
      }
      else{
          VerticalSeam.push_back(index+1);
          index++;
      }
    }
    else if(index == 0){
      if(Vec[id-1][index]->energy == curr->parent->energy){
        VerticalSeam.push_back(index);
      }
      else{
        VerticalSeam.push_back(index + 1);
        index++;
      }
    }
    else {
      if(Vec[id-1][index-1]->energy == curr->parent->energy){
        VerticalSeam.push_back(index-1);
        index--;
    }
    else{
      VerticalSeam.push_back(index);
    }
  }
  curr = curr->parent;
  id --;
}

reverse(VerticalSeam.begin(), VerticalSeam.end());
return VerticalSeam;
}

void SeamCarver::removeHorizontalSeam(const vector<int>& seam){
  Picture _pic(Height-1,Width);
  for(int i = 0; i < Height;i++){
    for(int j = 0; j < Width;j++){
      if(i > seam[j]){
        Color color = Pic.get(i,j);
        _pic.set(i-1,j,color);
      }
      else if(i < seam[j]){
        Color color = Pic.get(i,j);
        _pic.set(i,j,color);
      }
    }
  }
  Height--;
  Pic = _pic;
}

void SeamCarver::removeVerticalSeam(const vector<int>& seam){
  Picture _pic(Height,Width-1);
  for(int i = 0; i < Height;i++){
    for(int j = 0; j < Width;j++){
      if(j > seam[i]){
        Color color = Pic.get(i,j);
        _pic.set(i,j-1,color);
      }
      else if(j < seam[i]){
        Color color = Pic.get(i,j);
        _pic.set(i,j,color);
      }
    }
  }
  Width--;
  Pic = _pic;
}
