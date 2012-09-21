/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package arvorebinariabuscagrafico.arvorebinaria;

/**
 *
 * @author David
 */
public class No {
    
    private static int idGen = 0;
    public int id;
    public int ordemVisita;
    public int grau;
    
    public No() {
        id = idGen++;
    }
    
    // membros públicos de propósito... não faça isso em casa :D
    public int valor;
    public No esquerda;
    public No direita;

    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final No other = (No) obj;
        if (this.id != other.id) {
            return false;
        }
        return true;
    }

    @Override
    public int hashCode() {
        int hash = 3;
        hash = 47 * hash + this.id;
        return hash;
    }

    @Override
    public String toString() {
        return "No{" + "id=" + id + ", valor=" + valor + ", esquerda=" + esquerda + ", direita=" + direita + '}';
    }
    
}
