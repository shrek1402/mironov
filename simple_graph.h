#pragma once
#include "container.h"
#include "LM_graph.h"
#ifndef _STD
#define _STD ::std::
#endif

#include <map>
#include <vector>

template<class _Tynode, class _Tyedge>
class simple_pair{
public:
 simple_pair(){}
 simple_pair(_Tynode n, _Tyedge e) : node(n), edge(e) {}
 _Tynode node;
 _Tyedge edge;
};

// АДТ простой граф
template <class _Tynode, class _Tyedge>
class simple_graph {
public:
  using nodes_container = container<_Tynode>;
  using edges_container = container<_Tyedge>;

private:
    using _Scary_val = typename simple_pair<container<_Tynode>, container<_Tyedge>>;

public:
  _Scary_val _data;

private:
  base_graph<size_t>* _graph;
  type_graph _type           = type_graph::NO_ORIENTED;


public:
  // создает пустой L - граф с нулевым числом вершин и ребер,
  simple_graph(): _graph(new L_graph<size_t>{0}) {}

  simple_graph(size_t _num, type_graph _type, form_graph _form) {
  }

  simple_graph(size_t _numv, size_t _nume, type_graph _type, form_graph _form) {}
  simple_graph(const simple_graph& _other): _data(_other._data), _type(_other._type){
    if(_other._graph->form() == form_graph::L_GRAPH) {
      auto a = dynamic_cast<L_graph<size_t>*>(_other._graph);
      _graph = new L_graph<size_t>(*a);
    } else if(_other._graph->form() == form_graph::M_GRAPH) {
      auto a = dynamic_cast<M_graph<size_t>*>(_other._graph);
      _graph = new M_graph<size_t>(*a);
    }
  }
  ~simple_graph(){}

  decltype(auto) V() const {
    return _data.node.size();
  }

  decltype(auto) E() const {
    return _data.edge.size();
  }

  type_graph Directed() {
    return _type;
  }

  form_graph Dense() {
    return _graph->form();
  }

  double K() {
    return 0. / 0.;
  }

  L_graph<size_t> ToListGraph() {
      L_graph<size_t> tmp(*dynamic_cast<L_graph<size_t>*>(_graph));
      return tmp;
  }

  M_graph<size_t> ToMatrixGraph() {
    if(_graph->form() == form_graph::L_GRAPH) {
      M_graph<size_t> tmp(*dynamic_cast<L_graph<size_t>*>(_graph));
      return tmp;
    }
  }

  decltype(auto) InsertV(){
    _data.node.emplace_back(_data.node.size());
    _graph->inc();
  }
  decltype(auto) DeleteV(_Tynode* n){
   _data.node.erase(n);
  }
  decltype(auto) InsertE(_Tynode n1, _Tynode n2){
  _data.edge.emplace_back(n1, n2);
  _graph->add(n1.Index(), n2.Index());
  }
  decltype(auto) GetE(_Tynode n1, _Tynode n2){
    return _data.edge.find({n1, n2});
  }
  decltype(auto) DeleteE(_Tynode n1, _Tynode n2){
    auto _it = GetE(n1, n2);
    if(_it != _data.edge.end()) {
      _data.erase(_it);
    }

    return _data.edge;
  }

  void print() {
    auto g = ToMatrixGraph();
    for(size_t i = 0; i < g.size(); i++) {
      for(size_t j = 0; j < g.size(); j++) {
        _STD cout << g[i][j] << " ";
      }
      _STD cout << _STD endl;
    }
  }
};


