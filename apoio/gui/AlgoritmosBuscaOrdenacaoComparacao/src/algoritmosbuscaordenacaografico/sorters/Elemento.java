/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package algoritmosbuscaordenacaografico.sorters;

import java.awt.Color;

/**
 *
 * @author David
 */
public class Elemento {
    
    public int valor;
    public boolean ativo;
    public boolean pivoOuEleito;
    
    public Elemento( int valor, boolean ativo, boolean pivoOuEleito ) {
        this.valor = valor;
        this.ativo = ativo;
        this.pivoOuEleito = pivoOuEleito;
    }
    
}
