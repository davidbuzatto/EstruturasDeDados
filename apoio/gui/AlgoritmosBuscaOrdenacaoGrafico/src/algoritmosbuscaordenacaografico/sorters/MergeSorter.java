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
    public void sortIt( Comparable[] array ) {

        cleanEngine();
        Element[] elementos = preprocessArray( array );

        addArray( elementos );
        
        mergeSortR( elementos, 0, elementos.length - 1 );
        

    }
    
    /*
    * Algoritmo de intercalação do método de ordenação mergeSort.
    */
    private void intercalar( Element[] elementos, int inicio, int meio, int fim ) {

        int i;
        Element[] temp = new Element[ inicio + fim + 1 ];

        int inicioParte1 = inicio;
        int inicioParte2 = meio + 1;
        int posLivre = inicio;

        // intercalando...
        while ( inicioParte1 <= meio && inicioParte2 <= fim ) {

            if ( elementos[inicioParte1].compareTo( elementos[inicioParte2] ) <= 0 ) {
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
    private void mergeSortR( Element[] elementos, int inicio, int fim ) {

        int meio;

        if ( inicio < fim ) {

            meio = ( inicio + fim ) / 2;
            mergeSortR( elementos, inicio, meio );
            addArray( elementos );
            mergeSortR( elementos, meio + 1, fim );
            addArray( elementos );
            intercalar( elementos, inicio, meio, fim );
            addArray( elementos );

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
