/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package arvorebinariabuscagrafico.gui;

import arvorebinariabuscagrafico.arvorebinaria.ArvoreBinariaBusca;
import arvorebinariabuscagrafico.arvorebinaria.No;
import arvorebinariabuscagrafico.arvorebinaria.TipoPercurso;
import java.awt.*;
import java.util.ArrayList;
import java.util.List;
import javax.swing.JPanel;

/**
 *
 * @author David
 */
public class PainelArvore extends JPanel {

    private List<NoGrafico> nosG = new ArrayList<NoGrafico>();
    private List<ArestaGrafico> arestasG = new ArrayList<ArestaGrafico>();
    private List<No> nosVisitados = new ArrayList<No>();
    private ArvoreBinariaBusca arvore = new ArvoreBinariaBusca();
    
    private int nivelAtual;
    private int alturaAtual;
    private int altura;
    private boolean mostrarNiveis;
    private boolean mostrarGraus;
    private boolean mostrarAltura;
    private boolean mostrarOrdem;
    
    private static final int DISTANCIA_ENTRE_IRMAOS = 50;
    private static final int DISTANCIA_ENTRE_NIVEIS = 100;
    
    private enum PosicaoNoGrafico {
        CENTRO,
        ESQUERDA,
        DIREITA
    }
    
    @Override
    protected void paintComponent( Graphics g ) {
        
        super.paintComponent( g );
        
        Graphics2D g2d = ( Graphics2D ) g.create();
        g2d.setRenderingHint( 
                RenderingHints.KEY_ANTIALIASING, 
                RenderingHints.VALUE_ANTIALIAS_ON );
        
        desenhar( g2d );
        
        g2d.dispose();
        
    }
    
    public void inserir( int valor ) {
        arvore.inserir( valor );
    }
    
    public void remover( int valor ) {
        arvore.remover( valor );
    }
    
    public void limpar() {
        arvore.esvaziar();
    }
    
    private void desenhar( Graphics2D g2d ) {
        
        g2d.setColor( getBackground() );
        g2d.fillRect( 0, 0, getWidth(), getHeight() );
        
        g2d.setColor( Color.BLACK );
        g2d.drawRect( 0, 0, getWidth() - 1, getHeight() - 1 );
        
        nosG.clear();
        arestasG.clear();
        
        nivelAtual = 0;
        alturaAtual = 0;
        altura = 0;
        
        obterAltura( arvore.getRaiz() );
        extrairNos( arvore.getRaiz(), null, PosicaoNoGrafico.CENTRO );
        
        for ( ArestaGrafico aG : arestasG ) {
            aG.desenhar( g2d );
        }
        
        for ( NoGrafico noG : nosG ) {
            for ( No no : nosVisitados ) {
                if ( noG.no.equals( no ) ) {
                    noG.visitado = true;
                    break;
                }
            }
            noG.desenhar( g2d, mostrarNiveis, mostrarGraus, mostrarOrdem );
        }
        
        if ( altura != 0 && mostrarAltura ) {
            
            g2d.setColor( new Color( 255, 69, 0 ) ) ;
            g2d.setFont( new Font( "Arial", Font.BOLD, 16 ) );
            
            String valorAltura = "Altura da Árvore: " + String.valueOf( altura - 1 );
            
            g2d.drawString( valorAltura, 
                    getWidth() - g2d.getFontMetrics().stringWidth( valorAltura ) - 10, 
                    25 );
            
        }
        
    }
    
    private void extrairNos( No no, NoGrafico pai, PosicaoNoGrafico posicao ) {
        
        if ( no != null ) {
            
            NoGrafico noG = null;
            no.grau = 0;
            
            if ( no.esquerda != null ) {
                no.grau++;
            }
            
            if ( no.direita != null ) {
                no.grau++;
            }
            
            switch ( posicao ) {
                case CENTRO:
                    noG = new NoGrafico( 
                        no, 
                        getWidth() / 2, 
                        DISTANCIA_ENTRE_NIVEIS * ( nivelAtual + 1 ), 
                        nivelAtual );
                    break;
                case ESQUERDA:
                    noG = new NoGrafico( 
                        no, 
                        pai.centroX - ( DISTANCIA_ENTRE_IRMAOS * ( altura - nivelAtual ) ), 
                        DISTANCIA_ENTRE_NIVEIS * ( nivelAtual + 1 ), 
                        nivelAtual );
                    break;
                case DIREITA:
                    noG = new NoGrafico( 
                        no, 
                        pai.centroX + ( DISTANCIA_ENTRE_IRMAOS * ( altura - nivelAtual ) ), 
                        DISTANCIA_ENTRE_NIVEIS * ( nivelAtual + 1 ), 
                        nivelAtual );
                    break;
            }
            
            arestasG.add( new ArestaGrafico( pai, noG ) );
            nosG.add( noG );
            
            nivelAtual++;
            
            extrairNos( no.esquerda, noG, PosicaoNoGrafico.ESQUERDA );
            extrairNos( no.direita, noG, PosicaoNoGrafico.DIREITA );
            
            nivelAtual--;

        }

    }
    
    private void obterAltura( No no ) {
        
        if ( no != null ) {
            
            alturaAtual++;
            
            obterAltura( no.esquerda );
            obterAltura( no.direita );
            
            if ( altura < alturaAtual ) {
                altura = alturaAtual;
            }
            
            alturaAtual--;

        }

    }
    
    public Percurso gerarPercurso( TipoPercurso tipo ) {

        Percurso p = new Percurso();
        StringBuilder sb = new StringBuilder();
        
        switch ( tipo ) {
            case EM_ORDEM:
                percorrerEmOrdem( arvore.getRaiz(), sb, p );
                break;
            case PRE_ORDEM:
                percorrerEmPreOrdem( arvore.getRaiz(), sb, p );
                break;
            case POS_ORDEM:
                percorrerEmPosOrdem( arvore.getRaiz(), sb, p );
                break;
            case EM_ORDEM_INV:
                percorrerEmOrdemInversa( arvore.getRaiz(), sb, p );
                break;
            case PRE_ORDEM_INV:
                percorrerEmPreOrdemInversa( arvore.getRaiz(), sb, p );
                break;
            case POS_ORDEM_INV:
                percorrerEmPosOrdemInversa( arvore.getRaiz(), sb, p );
                break;
        }
        
        p.textoPercurso = sb.toString();
        
        return p;

    }

    private void percorrerEmPreOrdem( No no, StringBuilder sb, Percurso p ) {

        if ( no != null ) {
            
            p.itensPercurso.add( no );
            sb.append( no.valor ).append( " " );
            percorrerEmPreOrdem( no.esquerda, sb, p );
            percorrerEmPreOrdem( no.direita, sb, p );

        }

    }
    
    private void percorrerEmPreOrdemInversa( No no, StringBuilder sb, Percurso p ) {

        if ( no != null ) {
            
            p.itensPercurso.add( no );
            sb.append( no.valor ).append( " " );
            percorrerEmPreOrdemInversa( no.direita, sb, p );
            percorrerEmPreOrdemInversa( no.esquerda, sb, p );

        }

    }

    private void percorrerEmOrdem( No no, StringBuilder sb, Percurso p ) {

        if ( no != null ) {

            percorrerEmOrdem( no.esquerda, sb, p );
            p.itensPercurso.add( no );
            sb.append( no.valor ).append( " " );
            percorrerEmOrdem( no.direita, sb, p );

        }

    }
    
    private void percorrerEmOrdemInversa( No no, StringBuilder sb, Percurso p ) {

        if ( no != null ) {

            percorrerEmOrdemInversa( no.direita, sb, p );
            p.itensPercurso.add( no );
            sb.append( no.valor ).append( " " );
            percorrerEmOrdemInversa( no.esquerda, sb, p );

        }

    }

    private void percorrerEmPosOrdem( No no, StringBuilder sb, Percurso p ) {

        if ( no != null ) {

            percorrerEmPosOrdem( no.esquerda, sb, p );
            percorrerEmPosOrdem( no.direita, sb, p );
            p.itensPercurso.add( no );
            sb.append( no.valor ).append( " " );

        }

    }
    
    private void percorrerEmPosOrdemInversa( No no, StringBuilder sb, Percurso p ) {

        if ( no != null ) {

            percorrerEmPosOrdemInversa( no.direita, sb, p );
            percorrerEmPosOrdemInversa( no.esquerda, sb, p );
            p.itensPercurso.add( no );
            sb.append( no.valor ).append( " " );

        }

    }

    public void setMostrarNiveis( boolean mostrarNiveis ) {
        this.mostrarNiveis = mostrarNiveis;
    }

    public boolean isMostrarOrdem() {
        return mostrarOrdem;
    }

    public void setMostrarOrdem(boolean mostrarOrdem) {
        this.mostrarOrdem = mostrarOrdem;
    }

    public void setMostrarGraus( boolean mostrarGraus ) {
        this.mostrarGraus = mostrarGraus;
    }

    public void setMostrarAltura( boolean mostrarAltura ) {
        this.mostrarAltura = mostrarAltura;
    }
    
    public void visitar( No no ) {
        nosVisitados.add( no );
    }
    
    public void resetar() {
        nosVisitados.clear();
    }
    
}
