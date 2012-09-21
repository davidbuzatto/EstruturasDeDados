/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package algoritmosbuscaordenacaografico.sorters;

/**
 *
 * @author David
 */
public class Comparacao {
    
    public enum Tipo {
        INDICE,
        VALOR,
        PIVO_OU_ELEITO
    }
    
    public int valor;
    public Tipo tipo;
    
    public Comparacao( int valor, Tipo tipo ) {
        this.valor = valor;
        this.tipo = tipo;
    }
    
}
