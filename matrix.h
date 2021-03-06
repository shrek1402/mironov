#pragma once

template <class _Ty>
class matrix {
private:
  _STD vector<_STD vector<_Ty>> _mat;

public:
  matrix(size_t num) {
    _mat.resize(num);
    for(auto& _val : _mat) {
      _val.resize(num);
    }
  }

  size_t size() {
    return _mat.size();
  }

  void resize(size_t n) {
    _mat.resize(n);
    for(auto& val : _mat) {
      val.resize(n);
    }
  }

  _NODISCARD _STD vector<_Ty>& operator[](const size_t _Pos) noexcept {
    return _mat[_Pos];
  }
  _NODISCARD const _STD vector<_Ty>& operator[](const size_t _Pos) const noexcept {
    return _mat[_Pos];
  }
};