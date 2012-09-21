/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package arvorebinariabuscagrafico.arvorebinaria;

/**
 *
 * @author David
 */
public class ArvoreBinariaBusca {
    
    private No raiz;

    public No getRaiz() {
        return raiz;
    }

    public void setRaiz( No raiz ) {
        this.raiz = raiz;
    }
    
    public boolean estaVazia() {
        return raiz == null;
    }
    
    public void inserir( int valor ) {
        raiz = inserirNo( raiz, valor );
    }
    
    private No inserirNo( No no, int valor ) {

        if ( no == null ) {

            no = new No();
            no.valor = valor;
            no.esquerda = null;
            no.direita = null;

        } else if ( valor < no.valor ) {
            no.esquerda = inserirNo( no.esquerda, valor );
        } else {
            no.direita = inserirNo( no.direita, valor );
        }

        return no;

    }
    
    public boolean contem( int valor ) {
        return contemNo( raiz, valor, false );
    }
    
    private boolean contemNo( No no, int valor, boolean achou ) {

        if ( no != null && !achou ) {

            if ( valor == no.valor ) {
                achou = true;
            } else if ( valor < no.valor ) {
                achou = contemNo( no.esquerda, valor, achou );
            } else {
                achou = contemNo( no.direita, valor, achou );
            }

        }

        return achou;

    }
    
    public boolean remover( int valor ) {

        boolean achou = contemNo( raiz, valor, false );

        if ( achou ) {
            raiz = removerNo( raiz, valor );
        }

        return achou;

    }
    
    private No removerNo( No no, int valor ) {

        No temp;

        if ( valor == no.valor ) {

            // o nó não tem filhos
            if ( no.esquerda == no.direita ) {
                
                no = null;
                return null;
                
            // o nó a ser removido não tem filho à esquerda
            } else if ( no.esquerda == null ) {

                temp = no.direita;
                no = null;
                return temp;

            // o nó a ser removido não tem filho à direita
            } else if ( no.direita == null ) {

                temp = no.esquerda;
                no = null;
                return temp;

            // o nó a ser removido tem filhos em ambos os lados
            } else {

                No temp2 = no.direita;
                temp = no.direita;

                while ( temp.esquerda != null ) {
                    temp = temp.esquerda;
                }

                temp.esquerda = no.esquerda;
                no = null;
                return temp2;

            }

        } else if ( valor < no.valor ) {
            no.esquerda = removerNo( no.esquerda, valor );
        } else {
            no.direita = removerNo( no.direita, valor );
        }

        return no;

    }
    
    public void percorrer( TipoPercurso tipo ) {

        switch ( tipo ) {
            case EM_ORDEM:
                percorrerEmOrdem( raiz );
                break;
            case PRE_ORDEM:
                percorrerEmPreOrdem( raiz );
                break;
            case POS_ORDEM:
                percorrerEmPosOrdem( raiz );
                break;
            case EM_ORDEM_INV:
                percorrerEmOrdemInversa( raiz );
                break;
            case PRE_ORDEM_INV:
                percorrerEmPreOrdemInversa( raiz );
                break;
            case POS_ORDEM_INV:
                percorrerEmPosOrdemInversa( raiz );
                break;
        }

        System.out.println();

    }

    private void percorrerEmPreOrdem( No no ) {

        if ( no != null ) {

            System.out.printf( "%d ", no.valor );
            percorrerEmPreOrdem( no.esquerda );
            percorrerEmPreOrdem( no.direita );

        }

    }

    private void percorrerEmOrdem( No no ) {

        if ( no != null ) {

            percorrerEmOrdem( no.esquerda );
            System.out.printf( "%d ", no.valor );
            percorrerEmOrdem( no.direita );

        }

    }

    private void percorrerEmPosOrdem( No no ) {

        if ( no != null ) {

            percorrerEmPosOrdem( no.esquerda );
            percorrerEmPosOrdem( no.direita );
            System.out.printf( "%d ", no.valor );

        }

    }
    
    private void percorrerEmPreOrdemInversa( No no ) {

        if ( no != null ) {

            System.out.printf( "%d ", no.valor );
            percorrerEmPreOrdemInversa( no.direita );
            percorrerEmPreOrdemInversa( no.esquerda );

        }

    }

    private void percorrerEmOrdemInversa( No no ) {

        if ( no != null ) {

            percorrerEmOrdemInversa( no.direita );
            System.out.printf( "%d ", no.valor );
            percorrerEmOrdemInversa( no.esquerda );

        }

    }

    private void percorrerEmPosOrdemInversa( No no ) {

        if ( no != null ) {

            percorrerEmPosOrdemInversa( no.direita );
            percorrerEmPosOrdemInversa( no.esquerda );
            System.out.printf( "%d ", no.valor );

        }

    }
    
    public void esvaziar() {
        raiz = desalocar( raiz );
    }
    
    private No desalocar( No no ) {

        if ( no != null ) {
            no.esquerda = desalocar( no.esquerda );
            no.direita = desalocar( no.direita );
            no = null;
        }

        return null;

    }
    
}
