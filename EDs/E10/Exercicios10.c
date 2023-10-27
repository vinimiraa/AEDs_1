/*
 * -------------------------- Documentacao
 * Pontificia Universidade Catolica de Minas Gerais
 * Curso de Ciencia da Computacao
 * Algoritmos e Estruturas de Dados I
 *
 * Exercicios10 - v0.0. - 26 / 10 / 2023
 * Author: Vinicius Miranda de Araujo
 *
 * Para compilar em terminal (janela de comandos):
 *      Linux : gcc -o Exercicios10 Exercicios10.c
 *      Windows: gcc -o Exercicios10 Exercicios10.c
 *
 * Para executar em terminal (janela de comandos):
 *      Linux : ./Exercicios10
 *      Windows: Exercicios10
 *
 */

// -------------------------- lista de dependencias

#include "libshow.h"

// -------------------------- tratamento de erro

// -------------------------- definicao de constantes

// -------------------------- definicao de variaveis globais

// -------------------------- definicao de prototipos

void menuOpcoes();
void exercicio1011();
void exercicio1012();
void exercicio1013();
void exercicio1014();
void exercicio1015();
void exercicio1016();
void exercicio1017();
void exercicio1018();
void exercicio1019();
void exercicio1020();
void exercicio10E1();
void exercicio10E2();

// -------------------------- definicao do metodo principal

int main(void)
{
    int opcao = 0;

    do
    {
        clear();

        // mostrar identificacao do autor e programa
        id("Programa: Exercicios10 - v0.0");

        // mostrar menu de opcoes
        menuOpcoes();

        // ler opcao do teclado
        opcao = readint("Opcao = ");

        // executar a opcao escolhida
        switch (opcao)
        {
        case 0:
            pause("Aperte ENTER para terminar!");
            break;
        case 1:
            exercicio1011();
            break;
        case 2:
            exercicio1012();
            break;
        case 3:
            exercicio1013();
            break;
        case 4:
            exercicio1014();
            break;
        case 5:
            exercicio1015();
            break;
        case 6:
            exercicio1016();
            break;
        case 7:
            exercicio1017();
            break;
        case 8:
            exercicio1018();
            break;
        case 9:
            exercicio1019();
            break;
        case 10:
            exercicio1020();
            break;
        case 11:
            exercicio10E1();
            break;
        case 12:
            exercicio10E2();
            break;
        default:
            pause("ERRO: opcao invalida");
            break;
        } // fim switch

    } while (opcao != 0);

    return (0);
}

// -------------------------- definicao de metodos

/**
 * Menu de opcoes
 */
void menuOpcoes()
{
    printf("\n");
    printf("%s\n\n", "Escolha alguma das opcoes a seguir:");
    printf("%s\n", "  0 - Encerrar programa");
    printf("%s\n", "  1 - Exercicio 1011");
    printf("%s\n", "  2 - Exercicio 1012");
    printf("%s\n", "  3 - Exercicio 1013");
    printf("%s\n", "  4 - Exercicio 1014");
    printf("%s\n", "  5 - Exercicio 1015");
    printf("%s\n", "  6 - Exercicio 1016");
    printf("%s\n", "  7 - Exercicio 1017");
    printf("%s\n", "  8 - Exercicio 1018");
    printf("%s\n", "  9 - Exercicio 1019");
    printf("%s\n", " 10 - Exercicio 1020");
    printf("%s\n", " 11 - Exercicio 10E1");
    printf("%s\n", " 12 - Exercicio 10E2");
    printf("\n");
} // fim menuOpcoes()

typedef struct s_intArray
{
    int  length;
    int* data  ;
    int  ix    ;
} intArray;

int RandomIntGenerate( int a, int b )
{
    int x = 0;
    while( x < a || b < x )
    {
        x = rand() % 100;
    } // end while
    return( x );
} // end RandomIntGenerate ( )

void printIntArray( intArray array )
{
    
    if ( array.data )
    {
        for ( array.ix = 0; array.ix < array.length; array.ix = array.ix + 1 )
        {
            print( "%2d: %d\n", array.ix, array.data[array.ix] );
        } // end for
    } // end if
} // end printIntArray ( )

void fprintIntArray( string fileName, intArray array )
{
    FILE *arquivo = fopen( fileName, "wt" );
    
    fprint( arquivo, "%d\n", array.length );
    
    if ( array.data )
    {
        for ( array.ix = 0; array.ix < array.length; array.ix = array.ix + 1 )
        {
            fprint( arquivo, "%d\n", array.data[array.ix] );
        } // end for
    } // end if

    fclose( arquivo );
} // end fprintIntArray ( )

/**
 * Metodo01.
 */
void exercicio1011()
{
    // identificacao
    id("Exercicio 1011:");

    // programa
    int a = 0, b = 0; // intervalos
    int x = 0;        // valor a ser gerado
    intArray array;   // arranjo
    
    a            = readint( "Digite o limite inicial do intervalo: " );
    b            = readint( "Digite o limite final do intervalo  : " );
    array.length = readint( "Digite a quantidade de valores: "       );

    if( a > b )
    { 
        print( "\n%s\n", "ERRO: Valor inicial maior que o valor final." );
    }
    else
    {
        array.data = (int*) malloc ( array.length * sizeof(int) );

        for( array.ix = 0; array.ix < array.length; array.ix = array.ix + 1 )
        {
            x = RandomIntGenerate( a, b );
            array.data[array.ix] = x;

        } // end for

        fprintIntArray( "DADOS.TXT", array );

        print( "\n%s\n", "Dados gravados no arquivo \"DADOS.TXT\". " );
    } // end if

    if( array.data )
    {
        free(array.data);
        array.data = NULL;
    } // end if

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio1011

intArray readArrayFromFile( string fileName )
{

    FILE *arquivo = fopen( fileName, "rt" );
    static intArray array;

    if (arquivo)
    {
        fscan( arquivo, "%d", &array.length ); fgetc( arquivo );

        if (array.length <= 0)
        {
            print( "\n%s\n", "ERRO: Tamanho invalido." );
            array.length = 0; 
        }
        else
        {
            array.data = (int*) malloc ( array.length * sizeof(int) );
            
            if ( array.data )
            {
                array.ix = 0; // posicao 0
                while (!feof(arquivo) && array.ix < array.length)
                {
                    fscan(arquivo, "%d", &(array.data[array.ix]));
                    fgetc( arquivo );
                    array.ix = array.ix + 1;
                } // end while
            } // end if
        } // end if
    } // end if
    
    fclose( arquivo );
    
    return (array);
} // end readArrayFromFile ( )

bool searchIntArray( int value, intArray array )
{
    bool resultado = false;
    
    array.ix = 0;
    while ( array.ix < array.length && !resultado )
    {
        if( value == array.data[array.ix] ) 
        {
            resultado = true;
        } // end if
        array.ix = array.ix + 1;
    } // end while

    return ( resultado );
} // end searchIntArray ( )

/**
 * Metodo02.
 */
void exercicio1012()
{
    // identificacao
    id("Exercicio 1012:");

    // programa
    intArray array; // arranjo
    int x = 0;

    array = readArrayFromFile("DADOS.TXT");
    
    x = readint ( "Digite o valor a ser procurado: " );

    if ( searchIntArray( x, array ) )
    {
        print( "\n%s\n", "O valor esta no arranjo" );
    }
    else
    {
        print( "\n%s\n", "O valor nao esta no arranjo" );
    } // end if

    if( array.data )
    {
        free( array.data );
        array.data = NULL;
    } // end if

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio1012

bool intArrayCompare( intArray array1, intArray array2 )
{
    bool resultado = true;
    
    if( array1.length <= 0 || array2.length <= 0 )
    {
        print( "\n%s\n", "ERRO: Tamanho Invalido." );
    }
    else
    {
        if( array1.length == array2.length )
        {
            array1.ix = 0;
            while ( array1.ix < array1.length /*&& !resultado*/ )
            {
                if( array1.data[array1.ix] != array2.data[array1.ix] )
                {
                    resultado = false;
                } // end if
                array1.ix = array1.ix + 1;
            } // end while
        } // end if
    } // end if

    return ( resultado );
} // end intArrayCompare ( )

/**
 * Metodo03.
 */
void exercicio1013()
{
    // identificacao
    id("Exercicio 1013:");

    // programa
    intArray arranjo1;
    intArray arranjo2;

    arranjo1 = readArrayFromFile( "DADOS1.TXT" );
    arranjo2 = readArrayFromFile( "DADOS2.TXT" );
    
    print( "%s\n", "Arranjo 1:" );
    printIntArray(arranjo1);
    print("\n%s\n", "Arranjo 2:" );
    printIntArray(arranjo2);

    if( intArrayCompare(arranjo1,arranjo2) )
    {
        print( "\n%s\n", "Os arranjos sao iguais." );
    }
    else
    {    
        print( "\n%s\n", "Os arranjos sao diferentes." );
    } // end if

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio1013

intArray intArrayAdd( intArray array1, int k, intArray array2 )
{
    static intArray soma;
    
    if( array1.length <= 0 || array2.length <= 0 )
    {
        print( "\n%s\n", "ERRO: Tamanho Invalido." );
    }
    else
    {
        if( array1.length == array2.length )
        {
            soma.data = (int*) malloc ( array1.length * sizeof(int) );
            soma.length = array1.length;
            
            if ( soma.data )
            {
                for( soma.ix = 0; soma.ix < soma.length; soma.ix = soma.ix + 1 )
                {
                    soma.data[soma.ix] = array1.data[soma.ix] + array2.data[soma.ix] * k;
                } // end for
            } // end for
        } // end if
    } // end if

    return ( soma );
} // end intArrayAdd ( )

/**
 * Metodo04.
 */
void exercicio1014()
{
    // identificacao
    id("Exercicio 1014:");

    // programa
    intArray arranjo1;
    intArray arranjo2;
    intArray soma;

    arranjo1 = readArrayFromFile( "DADOS1.TXT" );
    arranjo2 = readArrayFromFile( "DADOS2.TXT" );
    
    soma = intArrayAdd( arranjo1, 1, arranjo2 );

    print( "%s\n", "Soma do arranjo gravado em \"DADOS1.TXT\" com o arranjo gravado em \"DADOS2.TXT\": " );
    printIntArray( soma );

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio1014

bool isArrayDecrescent( intArray array )
{
    bool resultado = true;

    if( array.data )
    {
        array.ix = 1;
        while ( array.ix < array.length /*&& !resultado*/ )
        {
            if( array.data[array.ix-1] <= array.data[array.ix] )
            {
                resultado = false;
            } // end if
            // printf( "%d %d %d %d\n", array.ix, array.data[array.ix-1], array.data[array.ix], resultado ); 
            array.ix = array.ix + 1;
        } // end while
    } // end if

    return ( resultado );
} // end isArrayDecrescent ( )

/**
 * Metodo05.
 */
void exercicio1015()
{
    // identificacao
    id("Exercicio 1015:");

    // programa
    intArray arranjo;

    arranjo = readArrayFromFile( "DADOS1.TXT" );
    
    print( "%s\n", "Arranjo:" );
    printIntArray ( arranjo );
    
    if( isArrayDecrescent( arranjo ) )
    {
        print( "\n%s\n", "O arranjo e decrescente." );
    }
    else
    {
        print( "\n%s\n", "O arranjo nao e decrescente." );
    } // end if

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio1015

typedef struct s_intMatrix
{
    int row;
    int col;
    int** data;
    int ix,iy;
} intMatrix;

void printIntMatrix( intMatrix* matrix )
{
    if (matrix != NULL && matrix->data != NULL)
    {
        for (matrix->ix = 0; matrix->ix < matrix->row; matrix->ix = matrix->ix + 1)
        {
            for (matrix->iy = 0; matrix->iy < matrix->col; matrix->iy = matrix->iy + 1)
            {
                printf("%3d\t", matrix->data[matrix->ix][matrix->iy]);
            } // end for
            printf("\n");
        } // end for
    } // end if
} // end printIntArray ( )

intMatrix* intMatrix_new( int rows, int cols )
{
    intMatrix *matrix = (intMatrix*) malloc ( 1 * sizeof(intMatrix) );
    
    if( matrix != NULL )
    {
        matrix->row = 0;
        matrix->col = 0;
        matrix->data = NULL;
        
        if ( rows > 0 && cols > 0 )
        {
            matrix->row = rows;
            matrix->col = cols;
            matrix->data = malloc( rows * sizeof(int*) );
            
            if ( matrix->data )
            {
                for (matrix->ix = 0; matrix->ix < matrix->row; matrix->ix = matrix->ix + 1)
                {
                    matrix->data[matrix->ix] = (int*) malloc( cols * sizeof(int) );
                } // end for
            } // end if
        } // end if
        matrix->ix = 0;
        matrix->iy = 0;
    } // end if
    return ( matrix );
} // end intMatrix_new

intMatrix* readMatrixFromFile( string filename )
{
    intMatrix* matrix = NULL;
    int rows = 0;
    int cols = 0;
    FILE *arquivo = fopen( filename, "rt" );
    
    if ( arquivo == NULL )
    {
        print( "\n%s\n", "ERRO: Nao foi possivel abrir o aquivo." );
    }
    else
    {
        fscanf(arquivo, "%d", &rows); fgetc( arquivo );
        fscanf(arquivo, "%d", &cols); fgetc( arquivo );

        if (rows <= 0 || cols <= 0)
        {
            print( "\n%s\n", "ERRO: Tamanho invalido." );
        }
        else
        {

            matrix = intMatrix_new( rows, cols );

            if (matrix != NULL && matrix->data == NULL)
            {
                matrix->row = 0;
                matrix->col = 0;
                matrix->ix = 0;
                matrix->iy = 0;
            }
            else
            {
                if (matrix != NULL)
                {
                    matrix->ix = 0;
                    while ( !feof( arquivo ) && matrix->ix < matrix->row )
                    {
                        matrix->iy = 0;
                        while ( !feof( arquivo ) && matrix->iy < matrix->col )
                        {
                            fscanf( arquivo, "%d", &(matrix->data[matrix->ix][matrix->iy]) );
                            fgetc( arquivo );
                            matrix->iy = matrix->iy + 1;
                        } // end while
                        matrix->ix = matrix->ix + 1;
                    } // end while
                    matrix->ix = 0;
                    matrix->iy = 0;
                } // end if
            } // end if
        } // end if
    } // end if
    fclose ( arquivo );
    
    return (matrix);
} // end readMatrixFromFile ( ) 

intMatrix* matrixTranspose( intMatrix* matrix ) 
{
    intMatrix* aux = NULL;
    int rows = 0;
    int cols = 0;
    
    // printIntMatrix( matrix );
    
    if( matrix != NULL && matrix->data != NULL )
    {
        rows = matrix->col;
        cols = matrix->row;
        
        // printf("%d %d\n" , rows, cols );
        aux = intMatrix_new( rows, cols );
        
        if( aux != NULL && aux->data != NULL )
        {
            aux->ix = 0;
            while( aux->ix < aux->row )
            {
                aux->iy = 0;
                while( aux->iy < aux->col )
                {
                    // printf( "%d %d %d\n", matrix->ix, matrix->iy, matrix->data[matrix->iy][matrix->ix] );
                    // aux->data[aux->ix][aux->iy] = matrix->data[matrix->iy][matrix->ix]; // antes
                    aux->data[aux->ix][aux->iy] = matrix->data[aux->iy][aux->ix];          // agora
                    aux->iy = aux->iy + 1;
                } // end while
                aux->ix = aux->ix + 1;
            } // end while
        } // end if
    } // end if
    
    return ( aux ) ;
} // end matrixTranspose ( )

/**
 * Metodo06.
 */
void exercicio1016()
{
    // identificacao
    id("Exercicio 1016:");

    // programa
    intMatrix* matrix1 = NULL;
    intMatrix* transposed = NULL;
    
    matrix1 = readMatrixFromFile( "DADOS3.TXT" );
    
    if ( matrix1 != NULL )
    {
        transposed = matrixTranspose( matrix1 );

        print( "%s\n", "Matriz:" );
        printIntMatrix( matrix1 );
        
        print( "\n%s\n", "Matriz Transposta:" );
        printIntMatrix( transposed );
    }

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio1016

/**
 * Metodo07.
 */
void exercicio1017()
{
    // identificacao
    id("Exercicio 1017:");

    // programa

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio1017

/**
 * Metodo08.
 */
void exercicio1018()
{
    // identificacao
    id("Exercicio 1018:");

    // programa

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio1018

/**
 * Metodo10.
 */
void exercicio1019()
{
    // identificacao
    id("Exercicio 1019:");

    // programa

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio1019

/**
 * Metodo10.
 */
void exercicio1020()
{
    // identificacao
    id("Exercicio 1020:");

    // programa

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio1020

/**
 * Metodo11.
 */
void exercicio10E1()
{
    // identificacao
    id("Exercicio 10E1:");

    // programa

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio10E1

/**
 * Metodo12.
 */
void exercicio10E2()
{
    // identificacao
    id("Exercicio 10E2:");

    // programa

    // encerrar
    pause("Aperte ENTER para continuar!");
} // fim exercicio10E2