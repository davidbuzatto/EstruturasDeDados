/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package sorters;

/**
 *
 * @author David Buzatto
 */
public class HeapSorter extends Sorter {

    @Override
    public void sortIt( Comparable[] array ) {

        cleanEngine();
        Element[] elementos = preprocessArray( array );

        heapSort( elementos );

    }

    private void heapSort(Element[] v) {
        buildMaxHeap(v);
        int n = v.length;

        for (int i = v.length - 1; i > 0; i--) {
            swap(v, i, 0);
            addArray( v );
            maxHeapify(v, 0, --n);
        }
    }

    private void buildMaxHeap(Element[] v) {
        for (int i = v.length / 2 - 1; i >= 0; i--)
            maxHeapify(v, i, v.length);
    }

    private void maxHeapify(Element[] v, int pos, int n) {
        int max = 2 * pos + 1, right = max + 1;
        if (max < n) {
            if (right < n && v[max].compareTo(v[right]) < 0)
                max = right;
            if (v[max].compareTo(v[pos]) > 0) {
                swap(v, max, pos);
                addArray( v );
                maxHeapify(v, max, n);
            }
        }
    }

    public void swap(Element[] v, int j, int aposJ) {
        Element aux;
        aux = v[j];
        v[j] = v[aposJ];
        v[aposJ] = aux;
    }

}
