/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package algoritmosbuscaordenacaografico.sorters;

/**
 *
 * @author David Buzatto
 */
public class BubbleSorterV3 extends Sorter {

    @Override
    public void sortIt( Comparable[] array ) {
        
        boolean trocou;
        
        cleanEngine();
        Element[] elementos = preprocessArray( array );
        
        addArray( elementos );
        
        for ( int i = 0; i < elementos.length; i++ ) {
            
            trocou = false;
            
            for ( int j = 0; j < elementos.length - 1 - i; j++ ) {
                
                if ( elementos[j].compareTo( elementos[j+1] ) > 0 ) {
                    Element temp = elementos[j];
                    elementos[j] = elementos[j+1];
                    elementos[j+1] = temp;
                    trocou = true;
                }
                
                addArray( elementos );
                
            }
            
            if ( !trocou ) {
                return;
            }
            
        }

    }

}
