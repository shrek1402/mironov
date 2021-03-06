#pragma once
#include <type_traits>

// CLASS TEMPLATE _Compressed_pair
struct _zero_then_variadic_args_t {
  explicit _zero_then_variadic_args_t() = default;
}; // tag type for value-initializing first, constructing second from remaining args

struct _one_then_variadic_args_t {
  explicit _one_then_variadic_args_t() = default;
}; // tag type for constructing first from one arg, constructing second from remaining args

template <class _Ty1, class _Ty2, bool = _STD is_empty<_Ty1>::value && !_STD is_final<_Ty1>::value>
class _compressed_pair final: private _Ty1 { // store a pair of values, deriving from empty first
public:
  _Ty2 _Myval2;

  using _Mybase = _Ty1; // for visualization

  template <class... _Other2>
  constexpr explicit _compressed_pair(_zero_then_variadic_args_t, _Other2&&... _Val2)
    : _Ty1(), _Myval2(_STD forward<_Other2>(_Val2)...) {}

  template <class _Other1, class... _Other2>
  constexpr _compressed_pair(_one_then_variadic_args_t, _Other1&& _Val1, _Other2&&... _Val2)
    : _Ty1(_STD forward<_Other1>(_Val1)), _Myval2(_STD forward<_Other2>(_Val2)...) {}

  constexpr _Ty1& _Get_first() noexcept {
    return *this;
  }

  constexpr const _Ty1& _Get_first() const noexcept {
    return *this;
  }
};

template <class _Ty1, class _Ty2>
class _compressed_pair<_Ty1, _Ty2, false> final { // store a pair of values, not deriving from first
public:
  _Ty1 _Myval1;
  _Ty2 _Myval2;

  template <class... _Other2>
  constexpr explicit _compressed_pair(_zero_then_variadic_args_t, _Other2&&... _Val2)
    : _Myval1(), _Myval2(_STD forward<_Other2>(_Val2)...) {}

  template <class _Other1, class... _Other2>
  constexpr _compressed_pair(_one_then_variadic_args_t, _Other1&& _Val1, _Other2&&... _Val2) 
    : _Myval1(_STD forward<_Other1>(_Val1)), _Myval2(_STD forward<_Other2>(_Val2)...) {}

  constexpr _Ty1& _Get_first() noexcept {
    return _Myval1;
  }

  constexpr const _Ty1& _Get_first() const noexcept {
    return _Myval1;
  }
};