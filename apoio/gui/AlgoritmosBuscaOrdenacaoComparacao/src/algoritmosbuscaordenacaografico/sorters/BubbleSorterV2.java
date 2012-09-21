/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package algoritmosbuscaordenacaografico.sorters;

/**
 *
 * @author David Buzatto
 */
public class BubbleSorterV2 extends Sorter {

    @Override
    public void sortIt( int[] array ) {

        clear();
        addArray( array, null, null );
        
        for ( int i = 0; i < array.length; i++ ) {
            for ( int j = 0; j < array.length - 1 - i; j++ ) {
                
                addArray( array, 
                        new Comparacao( j, Comparacao.Tipo.INDICE ), 
                        new Comparacao( j+1, Comparacao.Tipo.INDICE ) );
                
                if ( array[j] > array[j+1] ) {
                    int temp = array[j];
                    array[j] = array[j+1];
                    array[j+1] = temp;
                }
                
                addArray( array, null, null );
                
            }
        }

    }

}
