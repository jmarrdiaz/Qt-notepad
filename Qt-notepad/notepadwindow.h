#ifndef NOTEPADWINDOW_H
#define NOTEPADWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit> //Clase pensada para añadir un cuadro de texto en texto plano
//Para los menu
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QFileDialog> //Para alAbrir()
#include <QFile>       // ""
//Añadidos a posteriori (codigo copiado/pegado)
#include <QFontDialog>
#include <QClipboard>
#include <QKeySequence>

//Tarea de clase
#include <QMessageBox>
#include <QToolBar>
#include <QIcon>


class NotepadWindow : public QMainWindow
{
    Q_OBJECT

public:
    NotepadWindow(QWidget *parent = 0);
    ~NotepadWindow();

private slots: //Necesario añadir previamente Q_OBJECT para que compile private slots ya que no es de c++ puro
    void alAbrir();
    void alGuardar();
    //Añadido a posteriori
    void alFuente();
    void alCerrar();
    void alAcercade();

private:
    QMenuBar* mainMenu_;
    QMenu* mnuArchivo_;
    QPlainTextEdit* txtEditor_; //ptr privado (_)
    QAction* actArchivoAbrir_;
    QAction* actArchivoGuardar_;

    //Añadidos a posteriori (codigo copiado/pegado)
    QMenu* mnuFormato_;
    QAction* actFormatoFuente_;
    QMenu* mnuEditar_;
    QAction* actEditarCopiar_;
    QAction* actEditarPegar_;
    QClipboard* portapapeles_;
    //Tareas propuestas para clase
    QAction* actArchivoCerrar_;
    QAction* actEditarCortar_;
    QAction* actEditarDeshacer_;
    QAction* actEditarRehacer_;
    QMenu* mnuAyuda_;
    QAction* actAyudaAcercade_;

};

#endif // NOTEPADWINDOW_H
