#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <vector>
#include <stdexcept>

using namespace std;

#define SIZE 26 // 頂点の数


class Vertex {
public:
  string name;  // このVertex
  double score;  // 点数
  vector<Vertex*> neighbors;  // 矢印の先の隣接Vertexたち
  double kari_score;  // 与えられた点数を代入する
};

std::ifstream ifs("medium_data.txt"); // file open

Vertex vertex[SIZE];

void shokika(int ver_num){ // 初期化

  string str;
  
  for(int i = 0; i < ver_num; i++){ // give each vertex 100scores
    getline(ifs, str);
    vertex[i].name = str;
    vertex[i].score = 100.0;
    vertex[i].kari_score = 0.0;
  }
  
}

int search_vertex(string str,int edge_num){ //頂点を探す->そのindexを返す

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


void insert_neighbor(int edge_num){ //　neighbors の代入

  string str;

   for(int j = 0; j < edge_num; j++){
    string vertex1, vertex2;

    getline(ifs,str,' ');
    vertex1 = str;

    getline(ifs,str);
    vertex2 = str;

    int ver = 0, edge = 0 ; // if A -> C then ver: A's index edge: C's index

    ver = search_vertex(vertex1, edge_num);

    edge = search_vertex(vertex2, edge_num);
    
    vertex[ver].neighbors.insert(vertex[ver].neighbors.begin(), &vertex[edge]);

   }

}

void pageRank(int ver_num){ // 点数配分の計算

  for(int i = 0; i < ver_num ; i++){

    int n = vertex[i].neighbors.size(); // お隣の頂点の数
    double div_score = vertex[i].score / n; //自分の今の持ち点をつながっている矢印の数で割った点数

    for(int j = 0; j < n ; j++){
      vertex[i].neighbors[j]->kari_score += div_score; // お隣さんに点数を与える
    }
    
  }

  for(int k = 0; k < ver_num; k++){ //与えられた点数を自分の点数として代入してkari_scoreはリセット
    vertex[k].score = vertex[k].kari_score;
    vertex[k].kari_score = 0.0;
    std::cout << vertex[k].name << " : " << vertex[k].score << std::endl;
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
  //std::cout << ver_num << std::endl;

  shokika(ver_num);


  getline(ifs, str); //node count
  edge_num = atoi(str.c_str());

  insert_neighbor(edge_num);


  for(int i = 1; i < 4; i++){ //pageRank を実行
    std::cout << "for文 " << i << " 回目"<< std::endl;
    pageRank(ver_num);
   
  }

  double max_score = vertex[0].score;
  string max_name = vertex[0].name;

  for(int j = 1; j < ver_num ; j++){ // 最高点を探す
    if(max_score < vertex[j].score){
      max_score = vertex[j].score;
      max_name = vertex[j].name;
    }
  }

  std::cout << "Max score is " << max_name << " : " << max_score << std::endl;
  
  return 0;
}
