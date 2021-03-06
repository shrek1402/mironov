#pragma once

#include "simple_graph.h"

//формирование реберно-связного неориентированного графа
class random {
 public:
   // 
   struct create {
     // Рандомный граф без весов
     template<class _Ty1, class _Ty2>
     static void random(simple_graph<_Ty1, _Ty2>& _graph) {
       auto n_node = rand() % 30;

       for(size_t i = 0; i < n_node; ++i) {
         _graph.InsertV();
       }

       for(size_t i = 0; i < n_node; ++i) {
         _graph.InsertE(_graph._data.node[i], _graph._data.node[rand() % n_node]);
         _graph.InsertE(_graph._data.node[i], _graph._data.node[rand() % n_node]);
       }
     }

     // Рандомный граф с рандомными весами
     template<class _Ty1, class _Ty2>
     static void random_and_w(simple_graph<_Ty1, _Ty2>& _graph) {
       auto n_node = rand() % 30;

       for(size_t i = 0; i < n_node; ++i) {
         _graph.InsertV();
       }

       for(size_t i = 0; i < n_node; ++i) {
         _graph.InsertE(_graph._data.node[i], _graph._data.node[rand() % n_node]);
         _graph._data.edge.back().SetW(1. / rand());
         _graph.InsertE(_graph._data.node[i], _graph._data.node[rand() % n_node]);
         _graph._data.edge.back().SetW(1. / rand());
       }
     }
   };
};

template<class _Ty1, class _Ty2>
class frsng {
private:
  simple_graph<_Ty1, _Ty2> _graph;

 public:
  frsng(const simple_graph<_Ty1, _Ty2>& _sgraph) : _graph(_sgraph){
    Restart();
  }
  
  frsng(const frsng& _other): _graph(_other._graph){}
  
  ~frsng(){}

  void Set(simple_graph<_Ty1, _Ty2>& _sgraph) { _graph = _sgraph; }

  void Restart(){
    for(size_t i = 0; i < 20; ++i) {
      _graph.InsertV();
    }

    for(size_t i = 0; i < _graph.V() - 1; ++i) {
      _graph.InsertE(_graph._data.node[i], _graph._data.node[i + 1]);
    }

    for(size_t i = 0; i < _graph.V() - 2; ++i) {
      _graph.InsertE(_graph._data.node[i], _graph._data.node[i + 2]);
    }
  }

  decltype(auto) Result(){
    return _graph;
  }
};