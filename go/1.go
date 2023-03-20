/*********************************
 * 1.go: Primeiro programa em Go *
 *********************************/
 package main  // Nome do pacote que está sendo criado, 
               // equivale ao nome do programa.
               
import "fmt"   // Importação de bibliotecas. Equivale ao "#include < >" em C++.

func main() {  // Função principal. A indentação neste formato é obrigatória e 
               // deve ser seguida.
   //Comandos 
   fmt.Print("Bem Vindos ao GO!\n", 123)
   fmt.Prinln("Bem Vindos ao GO!\n", 123)
   fmt.Prinln("Bem Vindos ao GO! %d\n", 123)

}
