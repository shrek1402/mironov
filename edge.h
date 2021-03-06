#pragma once

// АТД «Дескриптор ребра графа»
template <class _Ty>
class edge {
public:
  using value_type = _Ty;
  using pointer = _Ty*;
  using const_pointer = const pointer;
  using reference = _Ty&;
  using const_reference = const _Ty&;
  using size_type = size_t;
  using difference_type = size_t;

private:
  using tname = _STD string;
  using tweight = double;
  using tnode = node<_Ty>;

public:
  bool operator ==(edge _other) {
    return node1.Index() == _other.node1.Index() &&
           node2.Index() == _other.node2.Index();
  }

public:
  edge(const tnode& _v1, const tnode& _v2) : node1(_v1), node2(_v2), weight(), data() {}
  edge(const tnode& _v1, const tnode& _v2, tweight _w) : node1(_v1), node2(_v2), weight(_w), data() {}
  edge(const tnode& _v1, const tnode& _v2, tweight _w, const _Ty& _data) : node1(_v1), node2(_v2), weight(_w), data(_data) {}
  ~edge(){}

  const tnode& v1() const {
    return node1;
  }
  const tnode& v2() const {
    return node2;
  }
  tnode& v1() {
    return node1;
  }
  tnode& v2() {
    return node2;
  }

  const tweight& GetW() const {
    return weight;
  }
  tweight& GetW() {
    return weight;
  }

  edge& SetW(tweight _w) {
    weight = _w;
    return *this;
  }

  const _Ty& GetData() const {
    return data;
  }

  const edge& SetData(const _Ty& _data) const {
    data = _data;
    return *this;
  }
  edge& SetData(const _Ty& _data) {
    data = _data;
    return *this;
  }

private:
  union {
    struct {
      tnode node1;
      tnode node2;
    };
    tnode vnode[2];
  };

  tweight weight;
  _Ty data;
};