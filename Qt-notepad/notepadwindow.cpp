#include "notepadwindow.h"

NotepadWindow::NotepadWindow(QWidget *parent)
    : QMainWindow(parent)
{
    txtEditor_ = new QPlainTextEdit(this); //instanciamos var privada con el padre QmainWindow
    setCentralWidget(txtEditor_);
    //Inicializamos los menus
    mainMenu_ = new QMenuBar(this); //Pedir memoria para la barra
    mnuArchivo_ = new QMenu(tr("&Archivo"), this); //& para el guión bajo para pulsar con Alt, con this indicamos el padre para que cuando él muera, muera el hijo tb
    mainMenu_ -> addMenu (mnuArchivo_);
    setMenuBar(mainMenu_);

    actArchivoAbrir_ = new QAction (tr("&Abrir"), this);
    actArchivoAbrir_ -> setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O)); //Opcional
    mnuArchivo_ -> addAction (actArchivoAbrir_);

    actArchivoGuardar_ = new QAction (tr("&Guardar"), this);
    actArchivoGuardar_ -> setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S)); //Opcional
    mnuArchivo_ -> addAction (actArchivoGuardar_);

    //Conexión de nuestros menús con los slots
    connect(actArchivoAbrir_, SIGNAL (triggered()), this, SLOT(alAbrir()));
    connect(actArchivoGuardar_, SIGNAL (triggered()), this, SLOT(alGuardar()));


    mnuEditar_ = new QMenu(tr("&Editar"));
    mainMenu_->addMenu(mnuEditar_);
    setMenuBar(mainMenu_);

    actEditarCopiar_ = new QAction(tr("&Copiar"), this);
    actEditarCopiar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_C));
    mnuEditar_->addAction(actEditarCopiar_);

    actEditarPegar_ = new QAction(tr("&Pegar"), this);
    actEditarPegar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_V));
    mnuEditar_->addAction(actEditarPegar_);

    mnuFormato_ = new QMenu(tr("&Formato"));
    mainMenu_->addMenu(mnuFormato_);

    actFormatoFuente_ = new QAction(tr("&Fuente"), this);
    mnuFormato_->addAction(actFormatoFuente_);

    //Añadidos a posteriori, analogo a lo anterior
    connect(actEditarCopiar_, SIGNAL(triggered()), txtEditor_, SLOT(copy()));
    connect(actEditarPegar_, SIGNAL(triggered()), txtEditor_, SLOT(paste()));
    connect(actFormatoFuente_, SIGNAL(triggered()), this, SLOT(alFuente()));

    //Tareas propuestas para clase
    actArchivoCerrar_ = new QAction (tr("&Cerrar"), this);
    actArchivoCerrar_ -> setShortcut(QKeySequence(Qt::CTRL + Qt::Key_C));
    mnuArchivo_ -> addAction (actArchivoCerrar_);
    connect(actArchivoCerrar_, SIGNAL(triggered()), this, SLOT(alCerrar()));

    actEditarCortar_ = new QAction(tr("&Cortar"), this);
    actEditarCortar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_X));
    mnuEditar_->addAction(actEditarCortar_);
    connect(actEditarCortar_, SIGNAL(triggered()), txtEditor_, SLOT(cut()));

    actEditarDeshacer_ = new QAction(tr("&Deshacer"), this);
    actEditarDeshacer_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_U));
    mnuEditar_->addAction(actEditarDeshacer_);
    connect(actEditarDeshacer_, SIGNAL(triggered()), txtEditor_, SLOT(undo()));

    actEditarRehacer_ = new QAction(tr("&Rehacer"), this);
    actEditarRehacer_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y));
    mnuEditar_->addAction(actEditarRehacer_);
    connect(actEditarRehacer_, SIGNAL(triggered()), txtEditor_, SLOT(redo()));

    mnuAyuda_ = new QMenu(tr("&Ayuda"), this);
    mainMenu_ -> addMenu (mnuAyuda_);
    setMenuBar(mainMenu_);
    actAyudaAcercade_ = new QAction(tr("&Acerca de"), this);
    actAyudaAcercade_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_A));
    mnuAyuda_->addAction(actAyudaAcercade_);
    connect(actAyudaAcercade_, SIGNAL(triggered()), this, SLOT(alAcercade()));
}

NotepadWindow::~NotepadWindow()
{

}

void NotepadWindow::alAbrir() {
QString nombreArchivo;
nombreArchivo = QFileDialog::getOpenFileName(this, tr("Abrir archivo de texto plano"), " ", tr("Archivos de texto plano (*.txt)")); // Las " " es porque no especificamos ningún directorio por defecto

//Para poder abrirlo
if (nombreArchivo != ""){
    QFile archivo;
    archivo.setFileName(nombreArchivo);
    if (archivo.open(QFile::ReadOnly)){
        txtEditor_ -> setPlainText(archivo.readAll()); //Plasmamos en txtEditor_ el fichero que abrimos
        archivo.close();
    }
  }
}

void NotepadWindow::alGuardar(){
    QString nombreArchivo;
    nombreArchivo = QFileDialog::getSaveFileName(this, tr("Guardar archivo de texto plano"), " ", tr("Archivos de texto plano (*.txt)")); // Las " " es porque no especificamos ningún directorio por defecto
    if (nombreArchivo != "") {
    QFile archivo;
    //archivo.setFileName(nombreArchivo + ".txt");
    archivo.setFileName(nombreArchivo);
    if (archivo.open(QFile::WriteOnly | QFile::Truncate)) {
        archivo.write(txtEditor_ -> toPlainText().toUtf8());
        archivo.close();
    }
  }
}

//Añadidos a posteriori (codigo copiado/pegado)
void NotepadWindow::alFuente()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, txtEditor_->font(), this);
    if (ok) {
        // Si el usuario hizo click en OK, se establece la fuente seleccionada
        txtEditor_->setFont(font);
    }
}

//Tareas para clase
void NotepadWindow::alCerrar() {
close ();
}

void NotepadWindow::alAcercade() {
    QMessageBox mensaje;
     mensaje.setText("Curso QT. Febrero 2014");
     mensaje.exec();
}
