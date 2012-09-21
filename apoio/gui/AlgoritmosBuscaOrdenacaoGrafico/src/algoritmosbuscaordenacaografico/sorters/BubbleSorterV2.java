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
    public void sortIt( Comparable[] array ) {

        cleanEngine();
        Element[] elementos = preprocessArray( array );
        
        addArray( elementos );
        
        for ( int i = 0; i < elementos.length; i++ ) {
            for ( int j = 0; j < elementos.length - 1 - i; j++ ) {
                
                if ( elementos[j].compareTo( elementos[j+1] ) > 0 ) {
                    Element temp = elementos[j];
                    elementos[j] = elementos[j+1];
                    elementos[j+1] = temp;
                }
                
                addArray( elementos );
                
            }
        }

    }

}
