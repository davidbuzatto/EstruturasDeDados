/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package sorters;

/**
 *
 * @author David Buzatto
 */
public class ShellSorter extends Sorter {

    @Override
    public void sortIt( Comparable[] array ) {

        cleanEngine();
        Element[] elementos = preprocessArray( array );

        int[] t = new int[]{ 5, 3, 1 };
        for ( int h : t ) {
            for ( int j = h; j < elementos.length; j++ ) {
                int i = j - h;
                Element r = elementos[j];
                boolean flag = false;
                while ( i > -1 ) {
                    if ( r.compareTo( elementos[i] ) < 0 ) {
                        System.out.println( "aa" );
                        flag = true;
                        Element tmp = elementos[i];
                        elementos[i] = elementos[i+h];
                        elementos[i+h] = tmp;
                        i -= h;
                        addArray( elementos );
                    } else {
                        break;
                    }
                }
                elementos[i+h] = r;
            }
        }

    }
}
