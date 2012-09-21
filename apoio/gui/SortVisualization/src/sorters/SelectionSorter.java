/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package sorters;

/**
 *
 * @author David Buzatto
 */
public class SelectionSorter extends Sorter {

    @Override
    public void sortIt( Comparable[] array ) {

        cleanEngine();
        Element[] elementos = preprocessArray( array );

        for ( int j = elementos.length - 1; j >= 0; j-- ) {
            int m = maxPos( elementos, j );
            Element temp = elementos[m];
            elementos[m] = elementos[j];
            elementos[j] = temp;
            addArray( elementos );
        }

    }

    private int maxPos( Element[] elementos, int ate ) {

        int c = 0;
        Element maximo = elementos[0];

        for ( int i = 0; i <= ate; i++ ) {
            if ( maximo.compareTo( elementos[i] ) < 0 ) {
                maximo = elementos[i];
                c = i;
            }
        }

        return c;
    }

}
