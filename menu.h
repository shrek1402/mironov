#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "frsng.h"

class menu {};

template <class _Tygraph>
class main_menu {
 private:
   _Tygraph _graph;
  _STD vector<_STD string> _puncts;
 typename _Tygraph::nodes_container::iterator _it_node;
 typename _Tygraph::edges_container::iterator _it_edge;

 public:
  main_menu(_Tygraph _gr): _graph(_gr) {
    _puncts = {"Выход. ",  // Выход всегда на первом месте
               "Вывод дерева в консоль. ",
               "Опрос размера дерева. ",
               "Очистка дерева. ",
               "Проверка дерева на пустоту. ",
               "Установка итератора точки на первый элемент. ",
               "Установка итератора точки на последний элемент. ",
               "Установка итератора ребра на первый элемент. ",
               "Установка итератора ребра на последний элемент. ",
               "Итератор точки ++. ",
               "Итератор точки --. ",
               "Итератор ребра ++. ",
               "Итератор ребра --. ",
               "Проверка равенства итераторов. ",
               "Проверка неравенства итераторов. ",
               "Тестирование для случайного случая. ",
               "Запись по ключу (точка). ",
               "Чтение по ключу (точка). ",
               "Запись по итератору (точка). ",
               "Чтение по итератору (точка). "};
  }

  void run() {
    uint64_t tmp = 9999;

    while (tmp != 0) {
      main_menu::print();
      tmp = scan_comand();
      if(tmp < _puncts.size()){ 
        start_command(tmp);
        print_command_ok();
      } else {
        print_command_not_ok();
      }

      system("pause");
      system("cls");
    }
  }

 private:
   void print_command_ok() {
     _STD cout << _STD endl << "Задача выполнена! " << _STD endl;
   }

   void print_command_not_ok() {
     _STD cout << _STD endl << "Задача не выполнена! " << _STD endl;
   }

  void start_command(const uint64_t& num) {
    switch (num) {
      case 0:
        _STD cout << "Всего доброго! :(\n";
        exit(0);

      case 1:
        _graph.print();
        break;

      case 2:
        _STD cout << _graph._data.node.size() << _STD endl;
        break;

      case 3:
        _graph._data.node.clear();
        _graph._data.edge.clear();
        break;

      case 4:
        _STD cout << _graph._data.node.empty() << _STD endl;
        break;

      case 5:
        _it_node = _graph._data.node.begin();
        break;

      case 6:
        _it_node = _graph._data.node.end();

      case 7:
        _it_edge = _graph._data.edge.begin();
        break;

      case 8:
        _it_edge = _graph._data.edge.end();

      case 9:
        _it_node++;
        break;

      case 10:
        _it_node--;
        break;

      case 11:
        _it_edge++;
        break;

      case 12:
        _it_edge--;
        break;

      case 13:
        break;

      case 14:
        break;

      case 15:
      {
        random::create::random(_graph);
        frsng<_Tygraph::nodes_container::value_type, _Tygraph::edges_container::value_type> _frsng(_graph);
        break;
      }
      
      case 16:
      {
        size_t key;
        size_t new_data;
        _STD cout << "\nВведите ключ: ";
        _STD cin >> key;
        for (auto& val: _graph._data.node){
          if(val.Index() == key) {
            _STD cout << "Записываемое значение: ";
            _STD cin >> new_data;
            val.SetData(new_data);
            break;
          }
        }
      }
      break;

      case 17:
      {
        size_t key;
        _STD cout << "\nВведите ключ: ";
        _STD cin >> key;
        for(auto& val : _graph._data.node) {
          if(val.Index() == key) {
            _STD cout << val.GetData();
            break;
          }
        }
      }
      break;

      case 18:
      {
        size_t new_data;
        _STD cout << "Записываемое значение: ";
        _STD cin >> new_data;
        _it_node->SetData(new_data);
      }
      break;

      case 19:
      {
        _STD cout << _it_node->GetData();
      }
        
      default:
        break;
    }
  }

  void print_punct(uint64_t num, const _STD string& str) {
    _STD cout << num << ".\t" << str << _STD endl;
  }

  uint64_t scan_comand() {
    uint64_t tmp;
    _STD cout << _STD endl << _STD endl << "Введите команду: ";
    _STD cin >> tmp;
    return tmp;
  }

  void print() {
    for (size_t i = 0; i < _puncts.size(); ++i) {
      print_punct(i, _puncts[i]);
    }
  }
};