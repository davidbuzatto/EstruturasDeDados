/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package algoritmosbuscaordenacaografico.engine;

import algoritmosbuscaordenacaografico.sorters.Element;
import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.geom.*;
import java.util.*;

/**
 *
 * @author David Buzatto
 */
public class DrawEngine {

    private List< Element[] > list;
    private int larguraLinha;
    private int espacamento;
    private int espacamentoVerticalLinha;
    private int espacamentoHorizontal;
    private int maxX;
    private int maxY;
    
    public DrawEngine() {
        list = new ArrayList<Element[]>();
        larguraLinha = 10;
        espacamentoVerticalLinha = 20;
        espacamentoHorizontal = 20;
    }

    // desenha
    public void drawIt( Graphics g, boolean drawLabels ) {
        if ( g == null ) {
            toSout( list );
        } else {
            toG2D( g, list, drawLabels );
        }
    }

    // adiciona um array
    public void addArray( Element[] array ) {
        list.add( array );
    }

    // limpa a lista
    public void clean() {
        list = new ArrayList<Element[]>();
    }

    // escreve um array na saída
    private void printArray( Element[] array ) {
        System.out.print( "[" );
        for ( int i = 0; i < array.length; i++ ) {
            System.out.print( array[i].getValue() );
            if ( i != array.length - 1 )
                System.out.print( ", " );
        }
        System.out.println( "]" );
    }

    // desenha na saída
    private void toSout( List<Element[]> list ) {
        for ( Element[] array : list ) {
            printArray( array );
        }
    }

    // desenha no Graphics2D
    private void toG2D( Graphics g, List<Element[]> list, boolean drawLabels ) {

        if ( list.size() > 0 ) {

            // onde iniciar o desenho na vertical
            int yMargin = 5;

            // espacamento vertical entre os caminhos
            espacamento = larguraLinha;
            
            if ( drawLabels ) {
                espacamento += espacamentoVerticalLinha + 10;
            } else {
                espacamento += espacamentoVerticalLinha;
            }

            Graphics2D g2d = ( Graphics2D ) g;
            g2d.setRenderingHint( RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON );

            // obtém os elementos do primeiro item da lista
            Element[] elmIni = list.get( 0 );

            // cria uma mapa de paths para poder identificalos e usar o correto na hora de desenhar
            HashMap< Integer, Path2D.Float > paths = new HashMap< Integer, Path2D.Float >();

            // cria os mapas e já desenha as primeiras strings
            for ( int i = 0; i < elmIni.length; i++ ) {
                Path2D.Float path = new Path2D.Float();
                path.moveTo( espacamentoHorizontal, ( i + 1 ) * espacamento + yMargin );
                paths.put( elmIni[i].getKey(), path );
                g2d.drawString( String.valueOf( elmIni[i].getValue() ), espacamentoHorizontal, ( i + 1 ) * espacamento + yMargin );
            }
            
            maxX = 0;
            maxY = 0;
            
            // monta os paths
            for ( int i = 0; i < list.size() - 1; i++ ) {
                Element[] elm = list.get( i );
                Element[] elmTo = list.get( i + 1 );
                for ( int j = 0; j < elm.length; j++ ) {
                    int x = ( i + 2 ) * espacamentoHorizontal;
                    int y = ( getNodePositionByKey( elm[j].getKey(), elmTo ) + 1 ) * espacamento + yMargin;
                    paths.get( elm[j].getKey() ).lineTo( x, y );
                    if ( maxX < x ) {
                        maxX = x;
                    }
                    if ( maxY < y ) {
                        maxY = y;
                    }
                }
            }

            // gera as cores
            Element[] elmUlt = list.get( list.size() - 1 );
            HashMap< Integer, Color > cMap = new HashMap< Integer, Color >();
            int vBase = 255 / elmUlt.length;
            for ( int i = 0; i < elmUlt.length; i++ ) {
                int v = 255 - ( vBase * i );
                cMap.put( elmUlt[i].getKey(), new Color( v, v, v ) );
            }

            // desenha as linhas
            int c = 0;
            Color cCont = new Color( 125, 125, 125 );
            for ( Path2D.Float path : paths.values() ) {

                g2d.setStroke( new BasicStroke( larguraLinha, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND ) );
                g2d.setColor( cCont );
                g2d.draw( paths.get( elmUlt[c].getKey() ) );

                g2d.setStroke( new BasicStroke( larguraLinha - 1, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND ) );
                g2d.setColor( cMap.get( elmUlt[c].getKey() ) );
                g2d.draw( paths.get( elmUlt[c].getKey() ) );
                c++;

            }

            // desenha as strings
            Color cNum = new Color( 100, 100, 100 );
            Color cPt = new Color( 0, 128, 192 );
            if ( drawLabels ) {
                g2d.setFont( new Font( "arial", Font.BOLD, 12 ) );
                for ( int i = 0; i < elmIni.length; i++ ) {
                    int x = espacamentoHorizontal;
                    int y = ( i + 1 ) * espacamento + yMargin;
                    g2d.setColor( cNum );
                    g2d.drawString( String.valueOf( elmIni[i].getValue() ), x, y - 7 );
                    g2d.setColor( cPt );
                    g2d.fill( new Ellipse2D.Float( x, y - 2, 5, 5 ) );
                }
                for ( int i = 0; i < list.size() - 1; i++ ) {
                    Element[] nodes = list.get( i );
                    Element[] nodesTo = list.get( i + 1 );
                    for ( int j = 0; j < nodes.length; j++ ) {
                        int x = ( i + 2 ) * espacamentoHorizontal;
                        int y = ( getNodePositionByKey( nodes[j].getKey(), nodesTo ) + 1 ) * espacamento + yMargin;
                        g2d.setColor( cNum );
                        g2d.drawString( String.valueOf( nodes[j].getValue() ), x, y - 5);
                        g2d.setColor( cPt );
                        g2d.fill( new Ellipse2D.Float( x, y - 2, 5, 5 ) );
                    }
                }
            }

        }

    }

    private int getNodePositionByKey( Integer key, Element[] nodes ) {
        for ( int i = 0; i < nodes.length; i++ ) {
            if ( nodes[i].getKey().equals( key ) ) {
                return i;
            }
        }
        return 0;
    }

    public void setEspacamentoHorizontal(int espacamentoHorizontal) {
        this.espacamentoHorizontal = espacamentoHorizontal;
    }

    public void setEspacamentoVerticalLinha(int espacamentoVerticalLinha) {
        this.espacamentoVerticalLinha = espacamentoVerticalLinha;
    }

    public void setLarguraLinha(int larguraLinha) {
        this.larguraLinha = larguraLinha;
    }

    public int getMaxX() {
        return maxX;
    }

    public int getMaxY() {
        return maxY;
    }

}
