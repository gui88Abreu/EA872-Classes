/*
Nome: Guilherme de Brito Abreu
RA: 173691
*/

#include "oo_model.hpp"

Corpo::Corpo(float massa, float velocidade, float posicao) {
  this->massa = massa;
  this->velocidade = velocidade;
  this->posicao = posicao;
}

void Corpo::update(float nova_velocidade, float nova_posicao) {
  this->velocidade = nova_velocidade;
  this->posicao = nova_posicao;
}

float Corpo::get_massa() {
  return this->massa;
}

float Corpo::get_velocidade() {
  return this->velocidade;
}

float Corpo::get_posicao() {
  return this->posicao;
}

ListaDeCorpos::ListaDeCorpos() {
  this->corpos = new std::vector<Corpo *>(0);
}

void ListaDeCorpos::add_corpo(Corpo *c) {
  (this->corpos)->push_back(c);
  std::cout << "Agora tenho: " << this->corpos->size() << " elementos" << std::endl;
}

std::vector<Corpo*> *ListaDeCorpos::get_corpos() {
  return (this->corpos);
}

Fisica::Fisica(ListaDeCorpos *ldc) {
  this->lista = ldc;
  this->k = 5; //constante da mola
  this->b = 1; //constante de amortecimento
}

void Fisica::update(float deltaT) {
  // Atualiza parametros dos corpos!
  std::vector<Corpo *> *c = this->lista->get_corpos();
  deltaT = deltaT/1000.0;
  
  for (int i = 0; i < (*c).size(); i++) {
    float acel = ((-1)*this->k*(*c)[i]->get_posicao() - this->b*(*c)[i]->get_velocidade())/(*c)[i]->get_massa();
    float new_vel = (*c)[i]->get_velocidade() + acel*deltaT;
    float new_pos = (*c)[i]->get_posicao() + deltaT *(*c)[i]->get_velocidade() + (acel*deltaT*deltaT/2.0);
    (*c)[i]->update(new_vel, new_pos);
  }
}