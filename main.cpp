#include <QApplication>
#include <MainWindow.h>

int main(int argc, char *argv[]){
        QApplication app(argc,argv);
        MainWindow *arayuz = new MainWindow;
        arayuz->show();
        return app.exec();
}

