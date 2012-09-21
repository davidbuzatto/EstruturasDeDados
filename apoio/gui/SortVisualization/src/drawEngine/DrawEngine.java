/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package drawEngine;

import java.awt.BasicStroke;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.geom.*;
import java.util.*;
import sorters.*;

/**
 *
 * @author David Buzatto
 */
public class DrawEngine {

    private List< Element[] > list;

    public DrawEngine() {
        list = new ArrayList<Element[]>();
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

            // largura da linha
            int larg = 5;

            // onde iniciar o desenho na vertical
            int yMargin = 10;

            // espacamento vertical entre os caminhos
            int espVert = larg;
            if ( drawLabels ) {
                espVert += 20;
            } else {
                espVert += 10;
            }

            // espaçamento entre as mudancas no array
            int espHor = 20;

            Graphics2D g2d = ( Graphics2D ) g;
            g2d.setRenderingHint( RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON );

            // obtém os elementos do primeiro item da lista
            Element[] elmIni = list.get( 0 );

            // cria uma mapa de paths para poder identificalos e usar o correto na hora de desenhar
            HashMap< Integer, Path2D.Float > paths = new HashMap< Integer, Path2D.Float >();

            // cria os mapas e já desenha as primeiras strings
            for ( int i = 0; i < elmIni.length; i++ ) {
                Path2D.Float path = new Path2D.Float();
                path.moveTo( espHor, ( i + 1 ) * espVert + yMargin );
                paths.put( elmIni[i].getKey(), path );
                g2d.drawString( String.valueOf( elmIni[i].getValue() ), espHor, ( i + 1 ) * espVert + yMargin );
            }

            // monta os paths
            for ( int i = 0; i < list.size() - 1; i++ ) {
                Element[] elm = list.get( i );
                Element[] elmTo = list.get( i + 1 );
                for ( int j = 0; j < elm.length; j++ ) {
                    int x = ( i + 2 ) * espHor;
                    int y = ( getNodePositionByKey( elm[j].getKey(), elmTo ) + 1 ) * espVert + yMargin;
                    paths.get( elm[j].getKey() ).lineTo( x, y );
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

                g2d.setStroke( new BasicStroke( larg, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND ) );
                g2d.setColor( cCont );
                g2d.draw( paths.get( elmUlt[c].getKey() ) );

                g2d.setStroke( new BasicStroke( larg - 1, BasicStroke.CAP_ROUND, BasicStroke.JOIN_ROUND ) );
                g2d.setColor( cMap.get( elmUlt[c].getKey() ) );
                g2d.draw( paths.get( elmUlt[c].getKey() ) );
                c++;

            }

            // desenha as strings
            Color cNum = new Color( 0, 128, 192 );
            Color cPt = Color.RED;
            if ( drawLabels ) {
                g2d.setFont( new Font( "arial", Font.BOLD, 12 ) );
                for ( int i = 0; i < elmIni.length; i++ ) {
                    int x = espHor;
                    int y = ( i + 1 ) * espVert + yMargin;
                    g2d.setColor( cNum );
                    g2d.drawString( String.valueOf( elmIni[i].getValue() ), x, y - 5 );
                    g2d.setColor( cPt );
                    g2d.fill( new Ellipse2D.Float( x, y - 2, 5, 5 ) );
                }
                for ( int i = 0; i < list.size() - 1; i++ ) {
                    Element[] nodes = list.get( i );
                    Element[] nodesTo = list.get( i + 1 );
                    for ( int j = 0; j < nodes.length; j++ ) {
                        int x = ( i + 2 ) * espHor;
                        int y = ( getNodePositionByKey( nodes[j].getKey(), nodesTo ) + 1 ) * espVert + yMargin;
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

}
