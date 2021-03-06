#pragma once
#include <vector>
#include "matrix.h"

enum class form_graph: uint8_t {
  L_GRAPH,
  M_GRAPH,
};

enum class type_graph: uint8_t {
  ORIENTED,
  NO_ORIENTED,
};

template <class _Ty>
class base_graph {
public:
  virtual form_graph form() = 0;
  virtual void inc() = 0;
  virtual void add(_Ty _left, _Ty _right) = 0;
  virtual size_t size() = 0;

protected:
  virtual ~base_graph() {};
};

template <class _Ty>
class L_graph;

template <class _Ty>
class M_graph;

template <class _Ty>
class L_graph: public base_graph<_Ty> {
  friend M_graph<_Ty>;
private:
  _STD vector<_STD vector<_Ty>> _data;
public:
  L_graph() {}
  L_graph(size_t num) {
    _data.resize(num);
  }

  L_graph(const M_graph<_Ty>& _other) {
    for(size_t i = 0; i < _other._data.size(); ++i) {
      for(size_t j = 0; j < _other._data.size(); ++j) {
        if(_other._data[i][j]) {
          _data[i].emplace_back(j);
        }
      }
    }
  }

  form_graph form() {
    return form_graph::L_GRAPH;
  }

  void inc() {
    size_t _size = _data.size() + 1;
    _data.resize(_size);
  }

  void add(_Ty _left, _Ty _right) {
    _data[_left].emplace_back(_right);
  }

  size_t size(){
    return _data.size();
  }
};

template <class _Ty>
class M_graph: public base_graph<_Ty> {
  friend L_graph<_Ty>;
private:
  matrix<bool> _data;

public:
  M_graph(size_t num) : _data(num) {}
  M_graph(const L_graph<_Ty>& _other) : _data(_other._data.size()){
    for(size_t i = 0; i < _other._data.size(); ++i) {
      for(auto& _node: _other._data[i]) {
          _data[i][_node] = true;
      }
    }
  }

  form_graph form() {
    return form_graph::M_GRAPH;
  }

  void inc() {
    _data.resize(_data.size() + 1);
  }

  void add(_Ty _left, _Ty _right) {
    _data[_left][_right] = true;
  }

  size_t size() {
    return _data.size();
  }

  _NODISCARD decltype(auto) operator[](const size_t _Pos) noexcept {
    return _data[_Pos];
  }
};