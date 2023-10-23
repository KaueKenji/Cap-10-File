#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#define ex1

#ifdef ex1

int main() { // principais do main  
  setlocale(LC_ALL, "Portuguese ");
  int cont;

  // entrada      
  FILE *p;
  // abre file escrita
  if ((p = fopen("arq.txt", "w")) == NULL) {
    printf("erro na abertura do arquivo \n");
    exit(0); /*encerra o programa e volta ao sistema operacional*/
  }

  char aa;

  // para o usuário escolher sair   
  do {
    // inicio projeto       
    system("cls");

    // alimentação
    do {
      printf("\nDigite um caracter: ");
      scanf("%c", &aa);
      getchar();
      putc(aa, p);

    } while (aa != '0');
    // fechar file escrita
    fclose(p);

    // abre file leitura
    if ((p = fopen("arq.txt", "r")) == NULL) {
      printf("erro na abertura do arquivo \n");
      exit(0); /*encerra o programa e volta ao sistema operacional*/
    }
    // função
    // saída
    do {
      aa = getc(p);
      printf("\nCaracter Digitado: %c", aa);

    } while (aa != '0');

    // fecha file leitura
    fclose(p);

    // perguntar se o usuário quer finalizar  
    printf("\n \nDeseja finalizar? (1-Sim / 2-Não)");
    scanf("%d", &cont);
    // evitar bugs de Enter
    getchar();
    if (cont == 1)
      break;

  } while (1 == 1);
}
#endif

#ifdef ex2
typedef struct contatos {

  char nome[50];
  int tele;
  int dia;
  int mes;

} ctt;
// strings 
int strcmp( char *str1, char *str2) {

  int diferente = 0;

  for (int i = 0; (str1[i] != '\0' || str2[i] != '\0'); i++) {

    if (str1[i] != str2[i]) {

      diferente = 1;

      // fim if
    }


    // fim for
  }

  return (diferente);
  // fim função
}
void Inserir(FILE *p, ctt *c) {
  // abre file escrita
  if ((p = fopen("contatos.txt", "w")) == NULL) {
    printf("erro na abertura do arquivo \n");
    exit(0); /*encerra o programa e volta ao sistema operacional*/
  }

  // registrar
  for (int i = 0; i < 4; i++) {
  
    printf("\nDigite o Nome do contato: ");
    scanf("%s",c->nome);
    printf("\nDigite o Telefone do contato: ");
    scanf("%d", &c->tele);
    printf("\nDigite o Dia do Aniversário do contato: ");
    scanf("%d", &c->dia);
    printf("\nDigite o Mês do Aniversário do contato: ");
    scanf("%d", &c->mes);

   
   
    fwrite(c, sizeof(*c), 1, p);
    // fim for
  }
   
  // fecha file escrita
  fclose(p);
  // fim pro
}
void Listar(FILE *file, ctt *c){
   
  // abre file leitura
     
  if ((file = fopen("contatos.txt", "r")) == NULL) {
      printf("erro na abertura do arquivo \n");
      exit(0); /*encerra o programa e volta ao sistema operacional*/
    }

    //ler e listar
    int i = 0;
    while ( fread(c, sizeof(*c), 1, file) != 0) {
    
       if(*c->nome != 0){
      printf("\n ____________________________ ");
      printf("\n| %d° \n| Nome: %s\n| Telefone: %d\n| Aniversário: %d/%d", i+1,  c->nome, c->tele, c->dia, c->mes);
       printf("\n|____________________________|");

         i++;
         //fim if
       }
    // fim while
  }
 
  
    // fecha file leitura
    fclose(file);
  //fim proc
}
void Pesquisar( FILE *file, ctt *c){
     
    // abre file leitura
     
  if ((file = fopen("contatos.txt", "r")) == NULL) {
      printf("erro na abertura do arquivo \n");
      exit(0); /*encerra o programa e volta ao sistema operacional*/
    }

  //perguntar
  char pesq[50];
  char *p = &pesq[0];

  printf("\nDigite o nome para pesquisa: ");
  scanf("%s", p);
  
  
    //fazer pesquisa
 
   while(fread(c, sizeof(*c), 1, file) != 0)
  {
    
    if(strcmp(c->nome, pesq) == 0){
     
      printf("\n ____________________________ ");
      printf("\n| Nome: %s\n| Telefone: %d\n| Aniversário: %d/%d",   c->nome, c->tele, c->dia, c->mes);
       printf("\n|____________________________|");

      //fim if
    }
    //fim while
    
  }
  
 
  
  fclose(file);
  //fim proc
}
void Letra(FILE *file, ctt *c){
   
  // abre file leitura
     
  if ((file = fopen("contatos.txt", "r")) == NULL) {
      printf("erro na abertura do arquivo \n");
      exit(0); /*encerra o programa e volta ao sistema operacional*/
    }

    //ler e listar
    int i = 0;
    char cha;
  getchar();
  printf("Digite uma letra: \n");
  scanf("%c", &cha);
  
  
  while ( fread(c, sizeof(*c), 1, file) != 0) {
    
       if(*c->nome != 0 && c->nome[0] == cha ){
      printf("\n ____________________________ ");
      printf("\n| Nome: %s\n| Telefone: %d\n| Aniversário: %d/%d",  c->nome, c->tele, c->dia, c->mes);
       printf("\n|____________________________|");

         i++;
         //fim if
       }
    // fim while
  }
 
  
    // fecha file leitura
    fclose(file);
  //fim proc
}
void Niver(FILE *file, ctt *c){
   
  // abre file leitura
     
  if ((file = fopen("contatos.txt", "r")) == NULL) {
      printf("erro na abertura do arquivo \n");
      exit(0); /*encerra o programa e volta ao sistema operacional*/
    }

    //ler e listar
    
    int mes;
  
  printf("Digite o mês: \n");
  scanf("%d", &mes);
  
  
  while ( fread(c, sizeof(*c), 1, file) != 0) {
    
       if(*c->nome != 0 && c->mes == mes ){
      printf("\n ____________________________ ");
      printf("\n| Nome: %s\n| Telefone: %d\n| Aniversário: %d/%d",  c->nome, c->tele, c->dia, c->mes);
       printf("\n|____________________________|");

         
         //fim if
       }
    // fim while
  }
 
  
    // fecha file leitura
    fclose(file);
  //fim proc
}
void Alterar( FILE *file, ctt *c){
     
    // abre file leitura
     
  if ((file = fopen("contatos.txt", "r+")) == NULL) {
      printf("erro na abertura do arquivo \n");
      exit(0); /*encerra o programa e volta ao sistema operacional*/
    }

  //perguntar
  char pesq[50];
  char *p = &pesq[0];
  int a =0;
  printf("\nDigite o nome para pesquisa: ");
  scanf("%s", p);
  
  
    //fazer pesquisa
   for(int i = 0;fread(c, sizeof(*c), 1, file) != 0; i++)
  {
    
    if(strcmp(c->nome, pesq) == 0){
       
    printf("\nDigite o Nome do contato: ");
     scanf("%s",c->nome);
    printf("\nDigite o Telefone do contato: ");
    scanf("%d", &c->tele);
    printf("\nDigite o Dia do Aniversário do contato: ");
    scanf("%d", &c->dia);
    printf("\nDigite o Mês do Aniversário do contato: ");
    scanf("%d", &c->mes);


      a = i * sizeof(*c);
        fseek(file,a, SEEK_SET);
     fwrite(c, sizeof(*c), 1, file);
      
      //fim if
    }
    //fim for
    
  }
  
  fclose(file);
  //fim proc
}
void Excluir( FILE *file, ctt *c){
     
    // abre file leitura
     
  if ((file = fopen("contatos.txt", "r+")) == NULL) {
      printf("erro na abertura do arquivo \n");
      exit(0); /*encerra o programa e volta ao sistema operacional*/
    }

  //perguntar
  char pesq[50];
  char *p = &pesq[0];
  int a =0;
  printf("\nDigite o nome para pesquisa: ");
  scanf("%s", p);
  
  
    //fazer pesquisa
   for(int i = 0;fread(c, sizeof(*c), 1, file) != 0; i++)
  {
    
    if(strcmp(c->nome, pesq) == 0){
        
      *c->nome = 0;
       c->dia = 0;
      c->mes = 0;
       c->tele = 0;
      
      a = i * sizeof(*c);
        fseek(file,a, SEEK_SET);
     fwrite(c, sizeof(*c), 1, file);
      
      //fim if
    }
    //fim for
    
  }
  
  fclose(file);
  //fim proc
}

int main() { // principais do main  
  setlocale(LC_ALL, "Portuguese ");
 

  // entrada      
  FILE *p;
 ctt cada[4];
  ctt *pctt = &cada[0];
  int op;
  
    // inicio projeto       
    system("cls");

    // menu
    do {
      printf("\n\nO que deseja fazer?\n1 - inserir contato\n2 - listar todos os "
             "contatos\n3 - pesquisar um contato pelo nome\n4 - listar os "
             "contatos cujo nome inicia com uma letra digitada\n5 - imprimir "
             "os aniversariantes do mês.\n6 - altera contato\n7 - exclui "
             "contato\n8 - saida\n");
      scanf("%d", &op);

      // função
      switch (op) {

      case (1): {
        Inserir(p, pctt);
        break;
      }
      case (2): {
        Listar(p, pctt);
        break;
      }
      case (3): {
        Pesquisar(p, pctt);
        break;
      }
      case (4): {
        Letra(p, pctt);
        break;
      }
      case (5): {
        Niver(p, pctt);
        break;
      }
      case (6): {
        Alterar(p, pctt);
        break;
      }
      case (7): {
        Excluir(p, pctt);
        break;
      }
      case (8): {

        break;
      }
        // fim switch
      }

    } while (op != 8);

   
}
#endif

#ifdef ex3
typedef struct contatos {

  char nome[50];
  char email[50];
  int tele;
  

} ctt;
// strings 
int strcmp( char *str1, char *str2) {

  int diferente = 0;

  for (int i = 0; (str1[i] != '\0' || str2[i] != '\0'); i++) {

    if (str1[i] != str2[i]) {

      diferente = 1;

      // fim if
    }


    // fim for
  }

  return (diferente);
  // fim função
}
void Inserir(FILE *p, ctt *c) {
  // abre file acrescentar
  if ((p = fopen("contatos3.txt", "a")) == NULL) {
    printf("erro na abertura do arquivo \n");
    exit(0); /*encerra o programa e volta ao sistema operacional*/
  }

  
    printf("\nDigite o Nome: ");
    scanf("%s", c->nome);
    printf("\nDigite o Email: ");
    scanf("%s", c->email);
    printf("\nDigite o Celular: ");
    scanf("%d", &c->tele);
    

    // gravar
    
    fwrite(c, sizeof(*c), 1, p);
  
    
    
 

  // fecha file escrita
  fclose(p);
  // fim pro
}
void Listar(FILE *file, ctt *c){
   
  // abre file leitura
     
  if ((file = fopen("contatos3.txt", "r")) == NULL) {
      printf("erro na abertura do arquivo \n");
      exit(0); /*encerra o programa e volta ao sistema operacional*/
    }

    //ler e listar
    int i = 0;
    while ( fread(c, sizeof(*c), 1, file) != 0) {
    
       if(*c->nome != 0){
      printf("\n ____________________________ ");
      printf("\n| %d° \n| Nome: %s\nEmail: %s\n|Celular: %d", i+1,  c->nome, c->email, c->tele);
       printf("\n|____________________________|");

         i++;
         //fim if
       }
    // fim while
  }
 
  
    // fecha file leitura
    fclose(file);
  //fim proc
}
void Pesquisar( FILE *file, ctt *c){
     
    // abre file leitura
     
  if ((file = fopen("contatos3.txt", "r")) == NULL) {
      printf("erro na abertura do arquivo \n");
      exit(0); /*encerra o programa e volta ao sistema operacional*/
    }

  //perguntar
  char pesq[50];
  char *p = &pesq[0];

  printf("\nDigite o nome para pesquisa: ");
  scanf("%s", p);
  
  
    //fazer pesquisa
 
   while(fread(c, sizeof(*c), 1, file) != 0)
  {
    
    if(strcmp(c->nome, pesq) == 0){
     
     printf("\n ____________________________ ");
      printf("\n| Nome: %s\nEmail: %s\n|Celular: %d",  c->nome, c->email, c->tele);
       printf("\n|____________________________|");

      //fim if
    }
    //fim while
    
  }
  
 
  
  fclose(file);
  //fim proc
}
void Alterar( FILE *file, ctt *c){
     
    // abre file leitura
     
  if ((file = fopen("contatos3.txt", "r+")) == NULL) {
      printf("erro na abertura do arquivo \n");
      exit(0); /*encerra o programa e volta ao sistema operacional*/
    }

  //perguntar
  char pesq[50];
  char *p = &pesq[0];
  int a =0;
  printf("\nDigite o nome para pesquisa: ");
  scanf("%s", p);
  
  
    //fazer pesquisa
   for(int i = 0;fread(c, sizeof(*c), 1, file) != 0; i++)
  {
    
    if(strcmp(c->nome, pesq) == 0){
        
       printf("\nDigite o Nome: ");
    scanf("%s", c->nome);
    printf("\nDigite o Email: ");
    scanf("%s", c->email);
    printf("\nDigite o Celular: ");
    scanf("%d", &c->tele);

      a = i * sizeof(*c);
        fseek(file,a, SEEK_SET);
     fwrite(c, sizeof(*c), 1, file);
      
      //fim if
    }
    //fim for
    
  }
  
  fclose(file);
  //fim proc
}
void Excluir( FILE *file, ctt *c){
     
    // abre file leitura
     
  if ((file = fopen("contatos3.txt", "r+")) == NULL) {
      printf("erro na abertura do arquivo \n");
      exit(0); /*encerra o programa e volta ao sistema operacional*/
    }

  //perguntar
  char pesq[50];
  char *p = &pesq[0];
  int a =0;
  printf("\nDigite o nome para pesquisa: ");
  scanf("%s", p);
  
  
    //fazer pesquisa
   for(int i = 0;fread(c, sizeof(*c), 1, file) != 0; i++)
  {
    
    if(strcmp(c->nome, pesq) == 0){
        
      *c->nome = 0;
       *c->email = 0;
       c->tele = 06;
      
      a = i * sizeof(*c);
        fseek(file,a, SEEK_SET);
     fwrite(c, sizeof(*c), 1, file);
      
      //fim if
    }
    //fim for
    
  }
  
  fclose(file);
  //fim proc
}
int main() { // principais do main  
  setlocale(LC_ALL, "Portuguese ");
  

  // entrada      
  FILE *p;
 ctt cada;
  ctt *pctt = &cada;
  int op;
  
    
    // menu
    do {
      // inicio projeto       
    system("cls");

      printf("\n\nO que deseja fazer?\n1 - Incluir registros\n2 - Listar todos os registros\n3 - Pesquisar registro pelo nome\n4 - Altera registro\n5 - Exclui registro\n6 - Saida\n");
      scanf("%d", &op);

      // função
      switch (op) {

      case (1): {
        Inserir(p, pctt);
        break;
      }
      case (2): {
       Listar(p, pctt);
        break;
      }
      case (3): {
       Pesquisar(p, pctt);
        break;
      }
      case (4): {
        Alterar(p, pctt);
        break;
      }
      case (5): {
        Excluir(p, pctt);
        break;
      }
      case (6): {

        break;
      }
        // fim switch
      }

    } while (op != 6);

   
}
#endif

#ifdef ex4
typedef struct produtos {

  float cod;
  char nome[50];
  int qtd;
  

} prod;
// strings 
int strcmp( char *str1, char *str2) {

  int diferente = 0;

  for (int i = 0; (str1[i] != '\0' || str2[i] != '\0'); i++) {

    if (str1[i] != str2[i]) {

      diferente = 1;

      // fim if
    }


    // fim for
  }

  return (diferente);
  // fim função
}
void Inserir(FILE *p, prod *c) {
  // abre file acrescentar
  if ((p = fopen("produtos.txt", "a")) == NULL) {
    printf("erro na abertura do arquivo \n");
    exit(0); /*encerra o programa e volta ao sistema operacional*/
  }

    printf("\nDigite o Código do produto: ");
    scanf("%f", &c->cod);
    printf("\nDigite o Nome do produto: ");
    scanf("%s", c->nome);
    printf("\nDigite a Quantidade do produto: ");
    scanf("%d", &c->qtd);
    

    // gravar
    
    fwrite(c, sizeof(*c), 1, p);
  
    
    
 

  // fecha file escrita
  fclose(p);
  // fim pro
}
void Listar(FILE *file, prod *c){
   
  // abre file leitura
     
  if ((file = fopen("produtos.txt", "r")) == NULL) {
      printf("erro na abertura do arquivo \n");
      exit(0); /*encerra o programa e volta ao sistema operacional*/
    }

    //ler e listar
    int i = 0;
    while ( fread(c, sizeof(*c), 1, file) != 0) {
    
       if(*c->nome != 0){
      printf("\n ____________________________ ");
      printf("\n| %d° \n| Código: %f\n| Nome: %s\n|Quantidade: %d", i+1,c->cod, c->nome, c->qtd);
       printf("\n|____________________________|");

         i++;
         //fim if
       }
    // fim while
  }
 
  
    // fecha file leitura
    fclose(file);
  //fim proc
}
void NaoTem(FILE *file, prod *c){
   //variave
  int entrou = 0;
  // abre file leitura
     
  if ((file = fopen("produtos.txt", "r")) == NULL) {
      printf("erro na abertura do arquivo \n");
      exit(0); /*encerra o programa e volta ao sistema operacional*/
    }

    //ler e listar
    int i = 0;
    while ( fread(c, sizeof(*c), 1, file) != 0) {
    
       if(c->qtd == 0){
      printf("\n ____________________________ ");
      printf("\n| %d° \n| Código: %f\n| Nome: %s\n|Quantidade: %d", i+1,c->cod, c->nome, c->qtd);
       printf("\n|____________________________|");
        entrou++;
         i++;
         //fim if
       }
    // fim while
  }
    if(entrou == 0){
      printf("\nTodos os produtos estão disponíveis!");
    }
 
  
    // fecha file leitura
    fclose(file);
  //fim proc
}
void Pesquisar( FILE *file, prod *c){
     
 
  if ((file = fopen("produtos.txt", "r")) == NULL) {
      printf("erro na abertura do arquivo \n");
      exit(0); /*encerra o programa e volta ao sistema operacional*/
    }

  //perguntar
  char pesq[50];
  char *p = &pesq[0];

  printf("\nDigite o nome para pesquisa: ");
  scanf("%s", p);
  
  
    //fazer pesquisa
 
   while(fread(c, sizeof(*c), 1, file) != 0)
  {
    
    if(strcmp(c->nome, pesq) == 0){
     
     printf("\n ____________________________ ");
       printf("\n| Código: %f\n| Nome: %s\n|Quantidade: %d", c->cod, c->nome, c->qtd);
       printf("\n|____________________________|");

      //fim if
    }
    //fim while
    
  }
  
 
  
  fclose(file);
  //fim proc
}
void AlterarQtd( FILE *file, prod *c){
     
    // abre file leitura
     
  if ((file = fopen("produtos.txt", "r+")) == NULL) {
      printf("erro na abertura do arquivo \n");
      exit(0); /*encerra o programa e volta ao sistema operacional*/
    }

  //perguntar
  char pesq[50];
  char *p = &pesq[0];
  int a =0, es;
  printf("\nDigite o nome para pesquisa: ");
  scanf("%s", p);
  
  
    //fazer pesquisa
   for(int i = 0;fread(c, sizeof(*c), 1, file) != 0; i++)
  {
    
    if(strcmp(c->nome, pesq) == 0){
        
    
    printf("\nDigite a Entrada(números positivos) ou Saída('-' Números negativos) do produto: ");
    scanf("%d", &es);

      c->qtd = c->qtd + es;
      if (c->qtd < 0){
        //nao existir prod negativo
         c->qtd = 0;
      }
      a = i * sizeof(*c);
        fseek(file,a, SEEK_SET);
     fwrite(c, sizeof(*c), 1, file);
      
      //fim if
    }
    //fim for
    
  }
  
  fclose(file);
  //fim proc
}
void Alterar( FILE *file, prod *c){
     
    // abre file leitura
     
  if ((file = fopen("produtos.txt", "r+")) == NULL) {
      printf("erro na abertura do arquivo \n");
      exit(0); /*encerra o programa e volta ao sistema operacional*/
    }

  //perguntar
  char pesq[50];
  char *p = &pesq[0];
  int a =0;
  printf("\nDigite o nome para pesquisa: ");
  scanf("%s", p);
  
  
    //fazer pesquisa
   for(int i = 0;fread(c, sizeof(*c), 1, file) != 0; i++)
  {
    
    if(strcmp(c->nome, pesq) == 0){
        
     printf("\nDigite o Código do produto: ");
    scanf("%f", &c->cod);
    printf("\nDigite o Nome do produto: ");
    scanf("%s", c->nome);

      a = i * sizeof(*c);
        fseek(file,a, SEEK_SET);
     fwrite(c, sizeof(*c), 1, file);
      
      //fim if
    }
    //fim for
    
  }
  
  fclose(file);
  //fim proc
}
void Excluir( FILE *file, prod *c){
     
    // abre file leitura
     
  if ((file = fopen("produtos.txt", "r+")) == NULL) {
      printf("erro na abertura do arquivo \n");
      exit(0); /*encerra o programa e volta ao sistema operacional*/
    }

  //perguntar
  char pesq[50];
  char *p = &pesq[0];
  int a =0;
  printf("\nDigite o nome para pesquisa: ");
  scanf("%s", p);
  
  
    //fazer pesquisa
   for(int i = 0;fread(c, sizeof(*c), 1, file) != 0; i++)
  {
    
    if(strcmp(c->nome, pesq) == 0){
        
      *c->nome = 0;
       c->cod = 0;
       c->qtd = -1;
      
      a = i * sizeof(*c);
        fseek(file,a, SEEK_SET);
     fwrite(c, sizeof(*c), 1, file);
      
      //fim if
    }
    //fim for
    
  }
  
  fclose(file);
  //fim proc
}
int main() { // principais do main  
  setlocale(LC_ALL, "Portuguese ");
  

  // entrada      
  FILE *p;
 prod cada;
  prod *pprod = &cada;
  int op;
  
    

    // menu
    do {
      // inicio projeto       
    system("cls");
      printf("\n\nO que deseja fazer?\n1 - Incluir produtos\n2 - Listar todos os produtos\n3 - Pesquisar produto pelo nome\n4 - Listar produtos não Disponíveis\n5 - Altera a quantidade do produto\n6 - Altera produto\n7 - Exclui produto\n8 - Saida\n");
      scanf("%d", &op);

      // função
      switch (op) {

      case (1): {
        Inserir(p, pprod);
        break;
      }
      case (2): {
       Listar(p, pprod);
        break;
      }
      case (3): {
       Pesquisar(p, pprod);
        break;
      }
      case (4): {
       NaoTem(p, pprod);
        break;
      }
      case (5): {
        AlterarQtd(p, pprod);
        break;
      }
      case (6): {
        Alterar(p, pprod);
        break;
      }
      case (7): {
        Excluir(p, pprod);
        break;
      }
      case (8): {

        break;
      }
        // fim switch
      }

    } while (op != 8);

   
}
#endif
