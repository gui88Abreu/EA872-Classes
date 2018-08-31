Para incluir a interação modelo-teclado no programa anterior, foi acrescentada uma força externa no modelo físico, de modo que a cada interação
com as teclas 's' ou 'w' o método 'choque' da classe 'Fisica' altere esse valor de nulo para não-nulo.  A força externa é anulada a cada update 
feito no modelo.

Para testar utilize: make run
OBS 1: o comando já faz a compilação dos arquivos
OBS 2: é necessário teclar mais de uma vez as teclas w e s para produzir um efeito perceptível no sistema