/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package algoritmosbuscaordenacaografico.sorters;

/**
 *
 * @author David Buzatto
 */
public class Element implements Comparable {

    private Integer key;
    private Comparable value;

    public Element( Integer key, Comparable value ) {
        this.key = key;
        this.value = value;
    }

    public Integer getKey() {
        return key;
    }

    public Comparable getValue() {
        return value;
    }

    public int compareTo( Object o ) {
        Element n = ( Element ) o;
        return getValue().compareTo( n.getValue() );
    }

}
