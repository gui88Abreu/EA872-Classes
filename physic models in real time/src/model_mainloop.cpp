#include <iostream>
#include <thread>
#include <vector>
#include <stdint.h>
#include <chrono>

#include "oo_model.hpp"

uint64_t get_now_ms() {
  return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
}

int main ()
{
  Corpo *c = new Corpo(2, 0, 2);
  ListaDeCorpos *l = new ListaDeCorpos();
  l->add_corpo(c);

  Fisica *f = new Fisica(l);

  std::cout << "Iniciando simulacao\n";
  std::cout << "Simulando por 10 segundos\n";

  uint64_t t0;
  uint64_t t1;
  uint64_t deltaT;
  uint64_t T;

  int i = 0;

  T = get_now_ms();
  t1 = T;
  while (1) {
    // Atualiza timers
    t0 = t1;
    t1 = get_now_ms();
    deltaT = t1-t0;

    // Atualiza modelo
    f->update(deltaT);

    std::vector<Corpo *> *corpos = l->get_corpos();

    for (int j=0; j<corpos->size(); j++)
    {
      std::cout << i << " t=" << (t1-T)/1000. << " - x = ";
      std::cout << (*corpos)[j]->get_posicao() << " - Velocidade = ";
      std::cout << (*corpos)[j]->get_velocidade() << std::endl;
    }

    // Condicao de parada
    if ( (t1-T) > 10000 ) break;

    std::this_thread::sleep_for (std::chrono::milliseconds(100));
    i++;
  }
  std::cout << "The End\n";
  return 0;
}
