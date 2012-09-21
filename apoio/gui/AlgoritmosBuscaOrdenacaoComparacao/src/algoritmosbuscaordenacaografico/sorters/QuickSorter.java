/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package algoritmosbuscaordenacaografico.sorters;

/**
 *
 * @author David Buzatto
 */
public class QuickSorter extends Sorter {

    @Override
    public void sortIt( int[] array ) {

        clear();
        addArray( array, null, null );

        quickSortR( array, 0, array.length - 1 );

    }
    
    /*
    * Algoritmo de particionamento.
    */
    private int particionar( int[] array, int inicio, int fim ) {

        int i = inicio - 1;
        int j = fim + 1;
        int pivo = array[ ( inicio + fim ) / 2 ]; // elemento do meio

        while ( i < j ) {
            
            addArray( array, 
                    new Comparacao( i, Comparacao.Tipo.INDICE ),
                    new Comparacao( j, Comparacao.Tipo.INDICE ) );
            
            do {
                addArray( array, 
                        new Comparacao( pivo, Comparacao.Tipo.VALOR ),
                        new Comparacao( j, Comparacao.Tipo.INDICE ) );
                j--;
            } while ( array[j] > pivo );

            do {
                addArray( array, 
                        new Comparacao( pivo, Comparacao.Tipo.VALOR ),
                        new Comparacao( i, Comparacao.Tipo.INDICE ) );
                i++;
            } while ( array[i] < pivo );
            
            addArray( array, 
                    new Comparacao( i, Comparacao.Tipo.INDICE ),
                    new Comparacao( j, Comparacao.Tipo.INDICE ) );
            
            if ( i < j ) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
            
            addArray( array, null, null );

        }

        return j;

    }

    /*
    * Função recursiva do quickSort.
    */
    private void quickSortR( int[] array, int inicio, int fim ) {

        int meio;

        if ( inicio < fim ) {
            meio = particionar( array, inicio, fim );
            quickSortR( array, inicio, meio );
            quickSortR( array, meio + 1, fim );
        }

    }

}
