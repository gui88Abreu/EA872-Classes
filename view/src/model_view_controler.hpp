/*
Nome: Guilherme de Brito Abreu
RA: 173691
*/

#ifndef OO_MODEL_HPP
#define OO_MODEL_HPP

#include <iostream>
#include <vector>
#include <ncurses.h>

class Corpo {
  private:
  float massa;
  float velocidade;
  float posicao;

  public:
  Corpo(float massa, float velocidade, float posicao);
  void update(float nova_velocidade, float nova_posicao);
  float get_massa();
  float get_velocidade();
  float get_posicao();
};

class ListaDeCorpos {
 private:
    std::vector<Corpo*> *corpos;

  public:
    ListaDeCorpos();
    void hard_copy(ListaDeCorpos *ldc);
    void add_corpo(Corpo *c);
    std::vector<Corpo*> *get_corpos();
};

class Fisica {
  private:
    ListaDeCorpos *lista;
    float k;
    float b;
  public:
    Fisica(ListaDeCorpos *ldc);
    void add_corpo(Corpo *c);
    void update(float deltaT);
};

class Tela {
  private:
    ListaDeCorpos *lista, *lista_anterior;
    int maxI, maxJ;
    float maxX, maxY;

  public:
    Tela(ListaDeCorpos *ldc, int maxI, int maxJ, float maxX, float maxY);
    ~Tela();
    void stop();
    void init();
    void update();
};
#endif
