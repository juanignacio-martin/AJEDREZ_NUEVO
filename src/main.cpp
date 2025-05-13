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
//Funcion para control teclado
void keyboardCallback(unsigned char key, int x, int y) {
    controlador->manejarTecla(key, x, y);

    glutPostRedisplay(); //fuerza que se vuelva a ejectutar
}
//Faltaria añadir una funcion para cuando se arrastra el raton y otra para cuando se mueve el raton
int main(int argc, char** argv) {
    std::string variante;
    std::cout << "Elige variante (clasico, silverman, demi): ";
    std::cin >> variante;

    partida* p = new partida(variante);
    controlador = new ControladorJuego(p);

    //Inicializar el gestor de ventanas y crearla
    glutInit(&argc, argv);
    //glutInitWindowSize(p->getColumnas() * controlador->getVista().getCeldaSize(), p->getFilas() * controlador->getVista().getCeldaSize());
    glutInitWindowSize(1000.0f, 1000.0f); //Tamaño general cambiar luego
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Ajedrez POO");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();


    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(40.0, 1000.0f / 1000.0f, 0.1, 150); //Tamaño general cambiar luego. este permite 3D
    //gluOrtho2D(0, p->getColumnas() * controlador->getVista().getCeldaSize(), p->getFilas() * controlador->getVista().getCeldaSize(), 0); 

    //Callbacks
    
    glutDisplayFunc(display);   //Antes displaycallback 
    glutMouseFunc(mouseCallback);
    glutKeyboardFunc(keyboardCallback);

    //Bucle infinito
    glutMainLoop();

    delete controlador;
    delete p;

    //Musica 
    ETSIDI::playMusica("resources/sounds/cancioninicio.mp3", true);
    return 0;
}


