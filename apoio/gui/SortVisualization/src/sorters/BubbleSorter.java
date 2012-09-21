/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package sorters;

/**
 *
 * @author David Buzatto
 */
public class BubbleSorter extends Sorter {

    @Override
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

    }

}
