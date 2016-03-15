#include "gui.h"
#include "roadrace.h"
#include "gamemodel.h"
#include "ui_roadrace.h"
#include <QLabel>
GuiManager *GuiManager::instance_ = NULL;

GuiManager& GuiManager::instance() {
    if (instance_ == NULL ) {
        instance_ = new GuiManager();
    }

    return *instance_;
}

void GuiManager::generateSquareGrid() {
    std::cout << getUi()->label->text().toStdString() << std::endl;


    vector<vector<Square*>> squaresList = Game::instance().getSquares();
    int i2 = 0;
     int hit=1;
    while(i2 < squaresList.size()){
    vector<Square*> squares = squaresList.at(i2);
    int index = 0;

    int wid=0;
    for(index = 0;index<squares.size();index++){
        int i = squares.size();
        wid++;

       Square *proc = squares.at(index);
       SquareLabel *lbl = new SquareLabel(proc,ui->gridLayoutWidget);
       QPixmap map = setmap(proc);
       lbl->setPixmap(map);
        lbl->setFixedHeight(40);
        lbl->setFixedWidth(40);
       ui->gameLayout->addWidget(lbl,hit,wid,0);

      proc->setX(wid);
      proc->setY(hit);
       lbl->show();
    }
    i2++;
    hit++;
}
     ui->gameLayout->setSpacing(0);
}
QPixmap GuiManager::setmap(Square *sq){
    string image = sq->getImage();

    if(image == "Fo"){
        QPixmap map(":/forrest");
        QPixmap result = map.scaled(QSize(40,40), Qt::KeepAspectRatio);

        return result;
    }
    if(image == "Ca"){
        QPixmap map(":/canyon");
        QPixmap result = map.scaled(QSize(40,40), Qt::KeepAspectRatio);
        return result;
    }
    if(image == "Ri"){
        QPixmap map(":/water");
          QPixmap result = map.scaled(QSize(40,40), Qt::KeepAspectRatio);
        return result;
    }
    if (image == "Mo"){
        QPixmap map(":/mountain");
          QPixmap result = map.scaled(QSize(40,40), Qt::KeepAspectRatio);
        return result;
    }
    if(image == "Pl"){
        QPixmap map(":/grass");
          QPixmap result = map.scaled(QSize(40,40), Qt::KeepAspectRatio);
        return result;
    }
}
