#pragma once
#include <freeglut.h>
#include "ControladorJuego.h"

ControladorJuego* controlador = nullptr;

//Funcion para dibujar
void display(void)
{
    //Borrado de la pantalla	
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Punto de vista
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    controlador->dibujar();

    glEnd();
    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);


    glutSwapBuffers();
}


//Funcion para click raton
void mouseCallback(int button, int state, int x, int y) {
    controlador->manejarClick(button, state, x, y);
}


//Funcion para control movimiento raton 
void mouseMoveCallback(int x, int y)
{
    controlador->manejarmov(x, y);
}


//Funcion para control teclado
void keyboardCallback(unsigned char key, int x, int y) {
    controlador->manejarTecla(key, x, y);

    glutPostRedisplay(); //fuerza que se vuelva a ejectutar
}

//Funcion para temporizar
void OnTimer(int value)
{
    
    glutTimerFunc(25, OnTimer, 0);
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    std::string variante;
    std::cout << "Elige variante (clasico, silverman, demi): ";
    std::cin >> variante;

    partida* p = new partida(variante);
    controlador = new ControladorJuego(p);

    //Inicializar el gestor de ventanas y crearla
    double ancho = 800.0f, altura = 600.0f;
    glutInit(&argc, argv);
    glutInitWindowSize(ancho, altura); //Tamaño general cambiar luego
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Ajedrez POO");


    //Perspectiva, luz
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(40.0, ancho/altura, 0.1, 150); //Tamaño general cambiar luego. este permite 3D
    
    //Callbacks
    glutDisplayFunc(display);  //Antes displaycallback
    glutTimerFunc(25, OnTimer, 0);  //cada 25msllame 1 vez a la funcion OnTimer() 
    glutMouseFunc(mouseCallback);   //click del raton
    glutKeyboardFunc(keyboardCallback); //Teclado
    glutPassiveMotionFunc(mouseMoveCallback); // Movimiento pasivo del ratón (sin botón presionado)

    //Bucle infinito
    glutMainLoop();

    delete controlador;
    delete p;

    //Musica 
    ETSIDI::playMusica("resources/sounds/cancioninicio.mp3", true);
    return 0;
}


