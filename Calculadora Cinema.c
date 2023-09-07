#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Funções
void menu();
void verificacao_escolha();
void calculadora();
//Variáveis Globais
float preco_ingresso = 30.50;
float desconto =  0.0;
float valor_total = 0.0;
int escolha;

//Função principal
int main() {
  setlocale(LC_ALL, "Portuguese"); //Define a linguagem padrão para PT-BR, permitindo acentos, ç, sinais gráficos e etc; melhorando o "design" do executável
  menu();
  return 0;
}

//Função menu
void menu(){
  //Limpa a tela - Windows
  system("cls");
  
  //Menu de opções de filmes em exibição no cinema
  printf("\t\tFilmes em Cartaz:\n\n");
  printf("1. Missão Impossível: Acerto de Contas\n");
  printf("2. Barbie\n");
  printf("3. Besouro Azul\n");
  printf("4. Oppenheimer\n");
  
  printf("\nDigite o número do filme escolhido: ");
  scanf("%d", &escolha); //Posso substituir por um getch(); depois
  
  verificacao_escolha();
}

//Função para verificar se tem erro na escolha do filme
void verificacao_escolha(){
  if(escolha == 1 || escolha == 2 || escolha == 3 || escolha == 4){
    calculadora();
  }
  else{
    printf("\n");
    system("cls");//Limpa a tela - Windows
    printf("Opção Inválida! ");
    system("pause");
    getchar();
    menu();
  }
}

//Função para calcular o valor dos ingressos
void calculadora (){
  int idade;
  int quantidade_ingressos;

  //Aqui captamos o número de ingressos que o usuário deseja
  printf("Digite a quantidade de ingressos: ");
  scanf("%d", &quantidade_ingressos);

  //Aqui captamos a idade de cada espectador utilizando um loop
  for(int contador = 0; contador < quantidade_ingressos; contador++){
    printf("Digite a idade do espectador %d: ", contador+1);
    scanf("%d", &idade);

    if(idade < 10 || idade > 65){
      desconto -= preco_ingresso /2;
    }
    //adicionar no for uma verificação de erro no input do usuário
  }

  valor_total=(preco_ingresso*quantidade_ingressos)+desconto;
  
  system("cls");//Limpa a tela - Windows
  printf("\nFilme escolhido: ");
  
  switch(escolha){
    case 1:
      printf("Missão Impossível: Acerto de Contas\n");
      break;
    case 2:
      printf("Barbie\n");
      break;
    case 3:
      printf("Besouro Azul\n");
      break;
    case 4:
      printf("Oppenheimer\n");
      break;
  }
  
  printf("Valor total: R$ %.2f\n", valor_total);
  printf("Desconto: R$ %.2f\n", desconto);
  printf("Quantidade de Ingressos: %d\n", quantidade_ingressos);
}
