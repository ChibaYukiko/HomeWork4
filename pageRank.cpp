#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <vector>

using namespace std;

#define SIZE 20


class Vertex {
public:
  std::string name;  // このVertex
  double score;  // 点数
  std::vector<Vertex> neighbors;  // 矢印の先の隣接Vertexたち
  double kari_score;  // もっと必要な情報があればここに入れる
};

std::ifstream ifs("small_data.txt"); // file open

Vertex vertex[SIZE];

void shokika(int ver_num){

  string str;
  
  for(int i = 0; i < ver_num; i++){ // give each vertex 100scores
    getline(ifs, str);
    vertex[i].name = str;
    vertex[i].score = 100.0;
    vertex[i].kari_score = 0;  
  }
  
}

int search_vertex(string str,int edge_num){

  int num = 0;
  
  while(num < edge_num){
    if(vertex[num].name == str){
      break;
    }else{
      num++;
    }
  }

  return num;
  
}


void insert_neighbor(int edge_num){

  string str;

   for(int j = 0; j < edge_num; j++){
    string vertex1, vertex2;

    getline(ifs,str,' ');
    vertex1 = str;
    //std::cout << vertex1 << std::endl;

    getline(ifs,str);
    vertex2 = str;
    //std::cout << vertex2 << std::endl;


    int ver = 0, edge = 0 ;

    ver = search_vertex(vertex1, edge_num);

    edge = search_vertex(vertex2, edge_num);
    
    vertex[ver].neighbors.push_back(vertex[edge]);

    std::cout << vertex[ver].name << "->" << vertex[ver].neighbors.front().name << std::endl;

   }

}

void pageRank(int ver_num){

  for(int i = 0; i < ver_num ; i++){

    int n = vertex[i].neighbors.size();
    std::cout << vertex[i].score << std::endl;
    double div_score = vertex[i].score / n;

    for(int j = 0; j < n ; j++){
      vertex[i].neighbors[j].kari_score += div_score;
      std::cout << vertex[j].name << " : " << vertex[j].kari_score << std::endl;
    }
    
  }

  for(int k = 0; k < ver_num; k++){
    vertex[k].score = vertex[k].kari_score;
    vertex[k].kari_score = 0.0;
    //std::cout << vertex[k].name << " : " << vertex[k].score << std::endl;
  }
  
}
 
int main(){

  string str;
  int ver_num = 0, edge_num = 0;


  if (ifs.fail()){
    std::cerr << "失敗" << std::endl;
    return -1;
  }
  
  getline(ifs, str); // vertex count
  ver_num = atoi(str.c_str());
  std::cout << ver_num << std::endl;

  shokika(ver_num);


  getline(ifs, str); //node count
  edge_num = atoi(str.c_str());

  insert_neighbor(edge_num);


  for(int i = 0; i < 3; i++){
    std::cout << i << std::endl;
    pageRank(ver_num);
   
  }
  return 0;
}
