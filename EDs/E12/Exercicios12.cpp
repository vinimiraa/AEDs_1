/*
 * -------------------------- Documentacao
 * Pontificia Universidade Catolica de Minas Gerais
 * Curso de Ciencia da Computacao
 * Algoritmos e Estruturas de Dados I
 *
 * Exercicios12 - v0.0. - 06 / 11 / 2023
 * Author: Vinicius Miranda de Araujo
 *
 * Para compilar em terminal (janela de comandos):
 *      Linux : gcc -o Exercicios12 Exercicios12.cpp
 *      Windows: gcc -o Exercicios12 Exercicios12.cpp
 *
 * Para executar em terminal (janela de comandos):
 *      Linux : ./Exercicios12
 *      Windows: Exercicios12
 *
 */

// -------------------------- lista de dependencias

#include "libshow.hpp"
#include "mymatrix.hpp"

// -------------------------- tratamento de erro

// -------------------------- definicao de constantes

// -------------------------- definicao de variaveis globais

// -------------------------- definicao de metodos

/**
 * Menu de opcoes
 */
void menuOpcoes()
{
    std::cout << std::endl;
    std::cout << "Escolha alguma das opcoes a seguir:" << std::endl;
    std::cout << "  0 - Encerrar programa " << std::endl;
    std::cout << "  1 - Exercicio 1211    " << std::endl;
    std::cout << "  2 - Exercicio 1212    " << std::endl;
    std::cout << "  3 - Exercicio 1213    " << std::endl;
    std::cout << "  4 - Exercicio 1214    " << std::endl;
    std::cout << "  5 - Exercicio 1215    " << std::endl;
    std::cout << "  6 - Exercicio 1216    " << std::endl;
    std::cout << "  7 - Exercicio 1217    " << std::endl;
    std::cout << "  8 - Exercicio 1218    " << std::endl;
    std::cout << "  9 - Exercicio 1219    " << std::endl;
    std::cout << " 10 - Exercicio 1220    " << std::endl;
    std::cout << " 11 - Exercicio 12E1    " << std::endl;
    std::cout << " 12 - Exercicio 12E2    " << std::endl;
    std::cout << std::endl;
} // fim menuOpcoes()

/**
 *  Metodo01.
 */
void exercicio1211( void )
{
    // identificacao
    id( "Exercicio 1211:" );

    // programa
    int row = 0, col = 0;            // linhas e colunas
    int inferior = 0, superior = 0;  // intervalos
    string filename = "DADOS.TXT";   // nome do arquivo

    inferior = readint( "Digite o valor inicial do intervalo: " );
    superior = readint( "Digite o valor final do intervalo  : " );
    row      = readint( "Digite a quantidade de linhas : " );
    col      = readint( "Digite a quantidade de colunas: " );

    if( inferior > superior || row <= 0 || col <= 0 )
    {
        cout << endl << "ERRO: Tamanho do Intervalo ou Linhas e Colunas Invalido." << endl;
    }
    else
    {
        Matrix<int> matriz( row, col, 0);
        matriz.randomIntGenerate( inferior, superior );
        matriz.fprint_b( filename );
        matriz.print( );
        cout << "Matriz gravada em " << filename << endl;
    }

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1211 (  )

/**
 *  Metodo02.
 */
void exercicio1212( void )
{
    // identificacao
    id( "Exercicio 1212:" );

    // programa
    Matrix<int> matriz1;
    Matrix<int> matriz2;
    string filename = "DADOS.TXT";
    int k = 0;

    k = readint( "Digite a constante: " );

    matriz1.fread( filename );

    matriz2 = matriz1.scalar( k );
    
    matriz2.print( );

    matriz1.free();
    matriz2.free();

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1212 (  )

/**
 *  Metodo03.
 */
void exercicio1213( void )
{
    // identificacao
    id( "Exercicio 1213:" );

    // programa

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1213 (  )

/**
 *  Metodo04.
 */
void exercicio1214( void )
{
    // identificacao
    id( "Exercicio 1214:" );

    // programa

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1214 (  )

/**
 *  Metodo05.
 */
void exercicio1215( void )
{
    // identificacao
    id( "Exercicio 1215:" );

    // programa

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1215 (  )

/**
 *  Metodo06.
 */
void exercicio1216( void )
{
    // identificacao
    id( "Exercicio 1216:" );

    // programa

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1216 (  )

/**
 *  Metodo07.
 */
void exercicio1217( void )
{
    // identificacao
    id( "Exercicio 1217:" );

    // programa

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1217 (  )

/**
 *  Metodo08.
 */
void exercicio1218( void )
{
    // identificacao
    id( "Exercicio 1218:" );

    // programa

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1218 (  )

/**
 *  Metodo12.
 */
void exercicio1219( void )
{
    // identificacao
    id( "Exercicio 1219:" );

    // programa

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1219 (  )

/**
 *  Metodo10.
 */
void exercicio1220( void )
{
    // identificacao
    id( "Exercicio 1220:" );

    // programa

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio1220 (  )

/**
 *  Metodo11.
 */
void exercicio12E1( void )
{
    // identificacao
    id( "Exercicio 12E1:" );

    // programa

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio12E1 (  )

/**
 *  Metodo12.
 */
void exercicio12E2( void )
{
    // identificacao
    id( "Exercicio 12E2:" );

    // programa

    // encerrar
    pause( "Aperte ENTER para continuar!" );
} // fim exercicio12E2 (  )

// -------------------------- definicao do metodo principal

int main( void )
{
    int opcao = 0;

    do
    {
        // limpar a saida de dados
        clearscreen(  );

        // mostrar identificacao do autor e programa
        id( "Programa: Exercicios12 - v0.0" );

        // mostrar menu de opcoes
        menuOpcoes(  );

        // ler opcao do teclado
        opcao = readint("Opcao = ");

        // executar a opcao escolhida
        switch ( opcao )
        {
        case 0:
            pause("Aperte ENTER para terminar!");
            break;
        case 1:
            exercicio1211(  );
            break;
        case 2:
            exercicio1212(  );
            break;
        case 3:
            exercicio1213(  );
            break;
        case 4:
            exercicio1214(  );
            break;
        case 5:
            exercicio1215(  );
            break;
        case 6:
            exercicio1216(  );
            break;
        case 7:
            exercicio1217(  );
            break;
        case 8:
            exercicio1218(  );
            break;
        case 9:
            exercicio1219(  );
            break;
        case 10:
            exercicio1220(  );
            break;
        case 11:
            exercicio12E1(  );
            break;
        case 12:
            exercicio12E2(  );
            break;
        default:
            pause( "ERRO: opcao invalida" );
            break;
        } // fim switch

    } while ( opcao != 0 );

    return ( 0 );
}
