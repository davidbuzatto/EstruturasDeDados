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
    public void sortIt( Comparable[] array ) {

        cleanEngine();
        Element[] elementos = preprocessArray( array );
        
        addArray( elementos );

        quickSortR( elementos, 0, elementos.length - 1 );

    }
    
    /*
    * Algoritmo de particionamento.
    */
    private int particionar( Element[] elementos, int inicio, int fim ) {

        int i = inicio - 1;
        int j = fim + 1;
        Element pivo = elementos[ ( inicio + fim ) / 2 ]; // elemento do meio

        while ( i < j ) {

            do {
                j--;
            } while ( elementos[j].compareTo( pivo ) > 0 );

            do {
                i++;
            } while ( elementos[i].compareTo( pivo ) < 0 );

            if ( i < j ) {
                Element temp = elementos[i];
                elementos[i] = elementos[j];
                elementos[j] = temp;
                addArray( elementos );
            }

        }

        return j;

    }

    /*
    * Função recursiva do quickSort.
    */
    private void quickSortR( Element[] elementos, int inicio, int fim ) {

        int meio;

        if ( inicio < fim ) {
            meio = particionar( elementos, inicio, fim );
            quickSortR( elementos, inicio, meio );
            quickSortR( elementos, meio + 1, fim );
        }

    }
    
    /*@Override
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

    }*/

}
