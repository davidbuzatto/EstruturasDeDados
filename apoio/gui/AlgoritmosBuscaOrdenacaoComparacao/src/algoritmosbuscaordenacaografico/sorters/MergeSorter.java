/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package algoritmosbuscaordenacaografico.sorters;

/**
 *
 * @author David Buzatto
 */
public class MergeSorter extends Sorter {

    @Override
    public void sortIt( int[] array ) {

        clear();
        addArray( array, null, null );
        
        mergeSortR( array, 0, array.length - 1 );

    }
    
    /*
    * Algoritmo de intercalação do método de ordenação mergeSort.
    */
    private void intercalar( int[] elementos, int inicio, int meio, int fim ) {

        int i;
        int[] temp = new int[ inicio + fim + 1 ];

        int inicioParte1 = inicio;
        int inicioParte2 = meio + 1;
        int posLivre = inicio;

        // intercalando...
        while ( inicioParte1 <= meio && inicioParte2 <= fim ) {

            if ( elementos[inicioParte1] <= elementos[inicioParte2] ) {
                temp[posLivre++] = elementos[inicioParte1++];
            } else {
                temp[posLivre++] = elementos[inicioParte2++];
            }

        }

        // se ainda existem números no primeiro array
        // que não foram intercaladas...
        for ( i = inicioParte1; i <= meio; i++ ) {
            temp[posLivre++] = elementos[i];
        }

        // se ainda existem números no segundo array
        // que não foram intercaladas...
        for ( i = inicioParte2; i <= fim; i++ ) {
            temp[posLivre++] = elementos[i];
        }

        // retorna os valores do array temporário para o array original
        for ( i = inicio; i <= fim; i++ ) {
            elementos[i] = temp[i];
        }

    }

    /*
    * Função recursiva do mergeSort.
    */
    private void mergeSortR( int[] elementos, int inicio, int fim ) {

        int meio;

        if ( inicio < fim ) {

            meio = ( inicio + fim ) / 2;
            
            addArray( elementos, 
                    new Comparacao( inicio, Comparacao.Tipo.INDICE ),
                    new Comparacao( meio, Comparacao.Tipo.INDICE ) );
            
            mergeSortR( elementos, inicio, meio );
            
            addArray( elementos, 
                    new Comparacao( meio+1, Comparacao.Tipo.INDICE ),
                    new Comparacao( fim, Comparacao.Tipo.INDICE ) );
            
            mergeSortR( elementos, meio + 1, fim );
            
            intercalar( elementos, inicio, meio, fim );
            
            addArray( elementos, null, null );

        }

    }


    /*@Override
    public void sortIt( Comparable[] array ) {

        cleanEngine();
        Element[] elementos = preprocessArray( array );

        int bound = elementos.length-1;
        while ( true ) {
            int t = 0;
            for ( int j = 0; j < bound; j++ ) {
                if ( elementos[j].compareTo( elementos[j+1]) > 0 ) {
                    Element temp = elementos[j];
                    elementos[j] = elementos[j+1];
                    elementos[j+1] = temp;
                    addArray( elementos );
                    t = j;
                }
            }
            if ( t == 0 )
                break;
            bound = t;
        }

    }*/

}
