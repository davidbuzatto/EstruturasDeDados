/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package sorters;

/**
 *
 * @author David Buzatto
 */
public class QuickSorter extends Sorter {

    @Override
    public void sortIt( Comparable[] array ) {

        cleanEngine();
        Element[] elementos = preprocessArray( array );

        quickSort( elementos, 0, null );

    }

    private void quickSort( Element[] lst, int left, Integer right ) {

        if ( right == null ) {
            right = lst.length - 1;
        }

        int l = left;
        int r = right;

        if ( l <= r ) {
            Element mid = lst[(left+right)/2];
            while ( l <= r ) {
                while ( l <= right && lst[l].compareTo( mid ) < 0 ) {
                    l++;
                }
                while ( r > left && lst[r].compareTo( mid ) > 0 ) {
                    r--;
                }
                if ( l <= r ) {
                    Element temp = lst[l];
                    lst[l] = lst[r];
                    lst[r] = temp;
                    addArray( lst );
                    l++;
                    r--;
                }
            }
            if ( left < r ) {
                quickSort( lst, left, r );
            }
            if ( l < right ) {
                quickSort( lst, l, right );
            }
        }

    }

}
