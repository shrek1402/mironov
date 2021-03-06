#include <iostream>
#include "simple_graph.h"
#include "node.h"
#include "edge.h"
#include "menu.h"

int main()
{
  setlocale(LC_ALL, "Russian");
  simple_graph<node<size_t>, edge<size_t>> a;
  main_menu<simple_graph<node<size_t>, edge<size_t>>> my_menu(a);
  my_menu.run();

  return 0;
}
