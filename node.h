#pragma once

// АТД «Дескриптор вершины графа»
template <class _Ty>
class node {
public:
  using value_type = _Ty;
  using pointer = _Ty*;
  using const_pointer = const pointer;
  using reference = _Ty&;
  using const_reference = const _Ty&;
  using size_type = size_t;
  using difference_type = size_t;

private:
  using tname = char;
  using tindex = int64_t;

public:
  node(size_t _idx = -1) : name(), data(), index(_idx) {}
  node(const tname& _name, const _Ty& _data)
    : name(_name), data(_data), index() {}
  ~node(){}

  const tname& GetName() const {
    return name;
  }
  tname& GetName() {
    return name;
  }

  const _Ty& GetData() const {
    return data;
  }
  _Ty& GetData() {
    return data;
  }

  void SetName(const tname& _name) {
    name = _name;
  }

  void SetData(const _Ty& _data) {
    data = _data;
  }

  int64_t Index() {
    return index;
  }

private:
  tname name;
  int64_t index;
  _Ty data;
};