#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "nineSquareTable.h"
#include "sixteenSquareTable.h"

int hardlevel = 2;
nineDatabase* newbase;
nineTable* newtbl;
nineTable* restbl;
int numbers = 0;
int num[9] = {0,0,0,0,0,0,0,0,0};

sixteenDatabase* newbase_16;
sixteenTable* newtbl_16;
sixteenTable* restbl_16;
int numbers_16 = 0;
int num_16[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand (time (NULL));
    ui->tabWidget->setCurrentIndex(1);
    on_newButton_clicked();
    ui->tabWidget->setCurrentIndex(0);
    on_newButton_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_newButton_clicked()
{
    if (ui->tabWidget->currentIndex() == 0)
    {
        numbers = 0;
        for (int i = 0; i < newtbl->bodySize; i++)
        {
            num[i] = 0;
            ui->numbersTable->item(i,0)->setBackground(Qt::NoBrush);
        }

        ui->sudokuWidget->clear();
        newtbl = new nineTable;
        restbl = new nineTable;
        newbase = new nineDatabase;

        for (int i = 0; i < newtbl->bodySize; i++)
        {
            for (int j = 0; j < newtbl->bodySize; j++)
            {
                QTableWidgetItem *item = new QTableWidgetItem();
                ui->sudokuWidget->setItem (i, j, item);
            }
        }
        newtbl->sudokuGen (&hardlevel);
        restbl->sudokuCopy(newtbl, restbl);

        for (int i = 0; i < newtbl->bodySize; i++)
        {
            for (int j = 0; j < newtbl->bodySize; j++)
            {
                int tmp = newtbl->body[i][j][0];
                if (tmp != 0)
                {
                    numbers++;

                    QString tmp2 = QString::number (tmp);
                    QTableWidgetItem *item = new QTableWidgetItem();
                    QString nothingstr = "0";
                    insertNumber(nothingstr, tmp2);
                    item->setText (tmp2);
                    ui->sudokuWidget->setItem (i, j, item);
                    ui->sudokuWidget->item (i, j)->setFlags (Qt::NoItemFlags);
                }
            }
        }
        newbase->renderingSolutions(restbl);
    }
    else if (ui->tabWidget->currentIndex() == 1)
    {
        numbers_16 = 0;
        for (int i = 0; i < newtbl_16->bodySize; i++)
        {
            num_16[i] = 0;
            ui->numbersTable_16->item(i,0)->setBackground(Qt::NoBrush);
        }

        ui->sudokuWidget_16->clear();
        newtbl_16 = new sixteenTable;
        restbl_16 = new sixteenTable;
        newbase_16 = new sixteenDatabase;
        for (int i = 0; i < newtbl_16->bodySize; i++)
        {
            for (int j = 0; j < newtbl_16->bodySize; j++)
            {
                QTableWidgetItem *item = new QTableWidgetItem();
                ui->sudokuWidget_16->setItem (i, j, item);
            }
        }
        int tmplevel = (int)(hardlevel*100/ui->hardLevelSlider->maximum());
        newtbl_16->sudokuGen (&tmplevel);
        restbl_16->sudokuCopy(newtbl_16, restbl_16);

        for (int i = 0; i < newtbl_16->bodySize; i++)
        {
            for (int j = 0; j < newtbl_16->bodySize; j++)
            {
                int tmp = newtbl_16->body[i][j][0];
                if (tmp != 0)
                {
                    numbers_16++;

                    QString tmp2 = QString::number (tmp);
                    QTableWidgetItem *item = new QTableWidgetItem();
                    QString nothingstr = "0";
                    insertNumber_16(nothingstr, tmp2);
                    item->setText (tmp2);
                    ui->sudokuWidget_16->setItem (i, j, item);
                    ui->sudokuWidget_16->item (i, j)->setFlags (Qt::NoItemFlags);
                }
            }
        }
        newbase_16->renderingSolutions(restbl_16);
    }
}

void MainWindow::pushButton (int num)
{
    if (!(ui->sudokuWidget->selectedItems().isEmpty()))
    {
        QString tmp = QString::number (num);
        int i = ui->sudokuWidget->currentRow();
        int j = ui->sudokuWidget->currentColumn();
        if (i >= 0 && j >= 0)
        {

            if (ui->sudokuWidget->item(i,j)->text().size() == 0)
            {
                numbers++;
                QString nothingstr = "0";
                insertNumber (nothingstr, tmp);
            }
            else
            {
                insertNumber (ui->sudokuWidget->item(i,j)->text(), tmp);
            }
            ui->sudokuWidget->item(i, j)->setText(tmp);
            if (numbers == (newtbl->bodySize)*(newtbl->bodySize)) on_checkButton_clicked();
        }
        ui->sudokuWidget->selectedItems().first()->setSelected(false);
        for (int p = 0; p < newtbl->bodySize; p++)
        {
            for (int q = 0; q < newtbl->bodySize; q++)
            {
                ui->sudokuWidget->item(p, q)->setBackground(Qt::white);
            }
        }
    }
}

void MainWindow::on_oneButton_clicked()
{
    pushButton (1);
    /*if (!(ui->sudokuWidget->selectedItems().isEmpty()))
    {
        QString tmp = QString::number(1);
        int i = ui->sudokuWidget->currentRow();
        int j = ui->sudokuWidget->currentColumn();
        if (i >= 0 && j >= 0)
        {

            if (ui->sudokuWidget->item(i,j)->text().size() == 0)
            {
                numbers++;
                QString nothingstr = "0";
                insertNumber (nothingstr, tmp);
            }
            else
            {
                insertNumber (ui->sudokuWidget->item(i,j)->text(), tmp);
            }
            ui->sudokuWidget->item(i, j)->setText(tmp);
            if (numbers == (newtbl->bodySize)*(newtbl->bodySize)) on_checkButton_clicked();
        }
        ui->sudokuWidget->selectedItems().first()->setSelected(false);
        for (int p = 0; p < newtbl->bodySize; p++)
        {
            for (int q = 0; q < newtbl->bodySize; q++)
            {
                ui->sudokuWidget->item(p, q)->setBackground(Qt::white);
            }
        }
    }*/
}

void MainWindow::on_twoButton_clicked()
{
    pushButton (2);
    /*if (!(ui->sudokuWidget->selectedItems().isEmpty()))
    {
        QString tmp = QString::number(2);
        int i = ui->sudokuWidget->currentRow();
        int j = ui->sudokuWidget->currentColumn();
        if (i >= 0 && j >= 0)
        {
            if (ui->sudokuWidget->item(i,j)->text().size() == 0)
            {
                numbers++;
                QString nothingstr = "0";
                insertNumber (nothingstr, tmp);
            }
            else
            {
                insertNumber(ui->sudokuWidget->item(i,j)->text(), tmp);
            }
            ui->sudokuWidget->item(i, j)->setText(tmp);
            if (numbers == (newtbl->bodySize)*(newtbl->bodySize)) on_checkButton_clicked();
        }
        ui->sudokuWidget->selectedItems().first()->setSelected(false);
        for (int p = 0; p < newtbl->bodySize; p++)
        {
            for (int q = 0; q < newtbl->bodySize; q++)
            {
                ui->sudokuWidget->item(p, q)->setBackground(Qt::white);
            }
        }
    }*/
}

void MainWindow::on_threeButton_clicked()
{
    pushButton (3);
/*    if (!(ui->sudokuWidget->selectedItems().isEmpty()))
    {
        QString tmp = QString::number(3);
        int i = ui->sudokuWidget->currentRow();
        int j = ui->sudokuWidget->currentColumn();
        if (i >= 0 && j >= 0)
        {
            if (ui->sudokuWidget->item(i,j)->text().size() == 0)
            {
                numbers++;
                QString nothingstr = "0";
                insertNumber (nothingstr, tmp);
            }
            else
            {
                insertNumber(ui->sudokuWidget->item(i,j)->text(), tmp);
            }
            ui->sudokuWidget->item(i, j)->setText(tmp);
            if (numbers == (newtbl->bodySize)*(newtbl->bodySize)) on_checkButton_clicked();
        }
        ui->sudokuWidget->selectedItems().first()->setSelected(false);
        for (int p = 0; p < newtbl->bodySize; p++)
        {
            for (int q = 0; q < newtbl->bodySize; q++)
            {
                ui->sudokuWidget->item(p, q)->setBackground(Qt::white);
            }
        }
    }*/
}

void MainWindow::on_fourButton_clicked()
{
    pushButton (4);
    /*if (!(ui->sudokuWidget->selectedItems().isEmpty()))
    {
        QString tmp = QString::number(4);
        int i = ui->sudokuWidget->currentRow();
        int j = ui->sudokuWidget->currentColumn();
        if (i >= 0 && j >= 0)
        {
            if (ui->sudokuWidget->item(i,j)->text().size() == 0)
            {
                numbers++;
                QString nothingstr = "0";
                insertNumber (nothingstr, tmp);
            }
            else
            {
                insertNumber(ui->sudokuWidget->item(i,j)->text(), tmp);
            }
            ui->sudokuWidget->item(i, j)->setText(tmp);
            if (numbers == (newtbl->bodySize)*(newtbl->bodySize)) on_checkButton_clicked();
        }
        ui->sudokuWidget->selectedItems().first()->setSelected(false);
        for (int p = 0; p < newtbl->bodySize; p++)
        {
            for (int q = 0; q < newtbl->bodySize; q++)
            {
                ui->sudokuWidget->item(p, q)->setBackground(Qt::white);
            }
        }
    }*/
}

void MainWindow::on_fiveButton_clicked()
{
    pushButton (5);
    /*if (!(ui->sudokuWidget->selectedItems().isEmpty()))
    {
        QString tmp = QString::number(5);
        int i = ui->sudokuWidget->currentRow();
        int j = ui->sudokuWidget->currentColumn();
        if (i >= 0 && j >= 0)
        {
            if (ui->sudokuWidget->item(i,j)->text().size() == 0)
            {
                numbers++;
                QString nothingstr = "0";
                insertNumber (nothingstr, tmp);
            }
            else
            {
                insertNumber(ui->sudokuWidget->item(i,j)->text(), tmp);
            }
            ui->sudokuWidget->item(i, j)->setText(tmp);
            if (numbers == (newtbl->bodySize)*(newtbl->bodySize)) on_checkButton_clicked();
        }
        ui->sudokuWidget->selectedItems().first()->setSelected(false);
        for (int p = 0; p < newtbl->bodySize; p++)
        {
            for (int q = 0; q < newtbl->bodySize; q++)
            {
                ui->sudokuWidget->item(p, q)->setBackground(Qt::white);
            }
        }
    }*/
}

void MainWindow::on_sixButton_clicked()
{
    pushButton (6);
    /*if (!(ui->sudokuWidget->selectedItems().isEmpty()))
    {
        QString tmp = QString::number(6);
        int i = ui->sudokuWidget->currentRow();
        int j = ui->sudokuWidget->currentColumn();
        if (i >= 0 && j >= 0)
        {
            if (ui->sudokuWidget->item(i,j)->text().size() == 0)
            {
                numbers++;
                QString nothingstr = "0";
                insertNumber (nothingstr, tmp);
            }
            else
            {
                insertNumber(ui->sudokuWidget->item(i,j)->text(), tmp);
            }
            ui->sudokuWidget->item(i, j)->setText(tmp);
            if (numbers == (newtbl->bodySize)*(newtbl->bodySize)) on_checkButton_clicked();
        }
        ui->sudokuWidget->selectedItems().first()->setSelected(false);
        for (int p = 0; p < newtbl->bodySize; p++)
        {
            for (int q = 0; q < newtbl->bodySize; q++)
            {
                ui->sudokuWidget->item(p, q)->setBackground(Qt::white);
            }
        }
    }*/
}

void MainWindow::on_sevenButton_clicked()
{
    pushButton (7);
    /*if (!(ui->sudokuWidget->selectedItems().isEmpty()))
    {
        QString tmp = QString::number(7);
        int i = ui->sudokuWidget->currentRow();
        int j = ui->sudokuWidget->currentColumn();
        if (i >= 0 && j >= 0)
        {
            if (ui->sudokuWidget->item(i,j)->text().size() == 0)
            {
                numbers++;
                QString nothingstr = "0";
                insertNumber (nothingstr, tmp);
            }
            else
            {
                insertNumber(ui->sudokuWidget->item(i,j)->text(), tmp);
            }
            ui->sudokuWidget->item(i, j)->setText(tmp);
            if (numbers == (newtbl->bodySize)*(newtbl->bodySize)) on_checkButton_clicked();
        }
        ui->sudokuWidget->selectedItems().first()->setSelected(false);
        for (int p = 0; p < newtbl->bodySize; p++)
        {
            for (int q = 0; q < newtbl->bodySize; q++)
            {
                ui->sudokuWidget->item(p, q)->setBackground(Qt::white);
            }
        }
    }*/
}

void MainWindow::on_eightButton_clicked()
{
    pushButton (8);
    /*if (!(ui->sudokuWidget->selectedItems().isEmpty()))
    {
        QString tmp = QString::number(8);
        int i = ui->sudokuWidget->currentRow();
        int j = ui->sudokuWidget->currentColumn();
        if (i >= 0 && j >= 0)
        {
            if (ui->sudokuWidget->item(i,j)->text().size() == 0)
            {
                numbers++;
                QString nothingstr = "0";
                insertNumber (nothingstr, tmp);
            }
            else
            {
                insertNumber(ui->sudokuWidget->item(i,j)->text(), tmp);
            }
            ui->sudokuWidget->item(i, j)->setText(tmp);
            if (numbers == (newtbl->bodySize)*(newtbl->bodySize)) on_checkButton_clicked();
        }
        ui->sudokuWidget->selectedItems().first()->setSelected(false);
        for (int p = 0; p < newtbl->bodySize; p++)
        {
            for (int q = 0; q < newtbl->bodySize; q++)
            {
                ui->sudokuWidget->item(p, q)->setBackground(Qt::white);
            }
        }
    }*/
}

void MainWindow::on_nineButton_clicked()
{
    pushButton (9);
    /*if (!(ui->sudokuWidget->selectedItems().isEmpty()))
    {
        QString tmp = QString::number(9);
        int i = ui->sudokuWidget->currentRow();
        int j = ui->sudokuWidget->currentColumn();
        if (i >= 0 && j >= 0)
        {
            if (ui->sudokuWidget->item(i,j)->text().size() == 0)
            {
                numbers++;
                QString nothingstr = "0";
                insertNumber (nothingstr, tmp);
            }
            else
            {
                insertNumber(ui->sudokuWidget->item(i,j)->text(), tmp);
            }
            ui->sudokuWidget->item(i, j)->setText(tmp);
            if (numbers == (newtbl->bodySize)*(newtbl->bodySize)) on_checkButton_clicked();
        }
        ui->sudokuWidget->selectedItems().first()->setSelected(false);
        for (int p = 0; p < newtbl->bodySize; p++)
        {
            for (int q = 0; q < newtbl->bodySize; q++)
            {
                ui->sudokuWidget->item(p, q)->setBackground(Qt::white);
            }
        }
    }*/
}

void MainWindow::on_clearButton_clicked()
{
    if (ui->tabWidget->currentIndex() == 0)
    {
       if (!(ui->sudokuWidget->selectedItems().isEmpty()))
        {
           numbers--;

           int i = ui->sudokuWidget->currentRow();
           int j = ui->sudokuWidget->currentColumn();
           QString nothingstr = "0";
           //insertNumber(ui->sudokuWidget->item(i, j)->text(), nothingstr);
           QTableWidgetItem *item = ui->sudokuWidget->item(i, j);
           if (item != NULL)
           {
               insertNumber(item->text(), nothingstr);
               item->setText("");
           }
           for (int p = 0; p < newtbl->bodySize; p++)
           {
               for (int q = 0; q < newtbl->bodySize; q++)
               {
                   ui->sudokuWidget->item(p, q)->setBackground(Qt::white);
               }
           }
       }
   }
   else if (ui->tabWidget->currentIndex() == 1)
   {
       numbers_16--;

       if (!(ui->sudokuWidget_16->selectedItems().isEmpty()))
       {
           int i = ui->sudokuWidget_16->currentRow();
           int j = ui->sudokuWidget_16->currentColumn();
           QString nothingstr = "0";
           //insertNumber_16(ui->sudokuWidget_16->item(i, j)->text(), nothingstr);
           QTableWidgetItem *item = ui->sudokuWidget_16->item(i, j);
           if (item != NULL)
           {
               insertNumber_16(item->text(), nothingstr);
               item->setText("");
           }
           for (int p = 0; p < newtbl_16->bodySize; p++)
           {
               for (int q = 0; q < newtbl_16->bodySize; q++)
               {
                   ui->sudokuWidget_16->item(p, q)->setBackground(Qt::white);
               }
           }
       }
   }
}

void MainWindow::on_checkButton_clicked()
{
   if (ui->tabWidget->currentIndex() == 0)
   {
       bool wrong = false;
       //newbase.renderingSolutions (&newtbl);
       if (newbase->SDbSize == 1)
       {
           for (int i = 0; i < newtbl->bodySize; i++)
           {
               for (int j = 0; j < newtbl->bodySize; j++)
               {
                   QTableWidgetItem* tmpitem = ui->sudokuWidget->item(i, j);
                   if (tmpitem == NULL)
                   {
                       wrong = true;
                       QTableWidgetItem *item = new QTableWidgetItem();
                       ui->sudokuWidget->setItem(i, j, item);
                       ui->sudokuWidget->item(i,j)->setBackground(Qt::red);
                   }
                   else
                   {
                       string tmp1 = QString::number(newbase->database[0].body[i][j][0]).toStdString();
                       string tmp2 = ui->sudokuWidget->item(i, j)->text().toStdString();
                       if ( tmp1.compare(tmp2) != 0)
                       {
                           wrong = true;
                           ui->sudokuWidget->item(i,j)->setBackground(Qt::red);
                       }
                       else
                       {
                           ui->sudokuWidget->item(i,j)->setBackground(Qt::white);
                       }
                   }
               }
           }
       }

       if (!wrong)
       {
           QMessageBox newmsgbox;
           newmsgbox.setText("Everything is OK!");
           newmsgbox.exec();
       }
   }
   else if (ui->tabWidget->currentIndex() == 1)
   {
       bool wrong = false;
       if (newbase_16->SDbSize == 1)
       {
           for (int i = 0; i < newtbl_16->bodySize; i++)
           {
               for (int j = 0; j < newtbl_16->bodySize; j++)
               {
                   QTableWidgetItem* tmpitem = ui->sudokuWidget_16->item(i, j);
                   if (tmpitem == NULL)
                   {
                       wrong = true;
                       QTableWidgetItem *item = new QTableWidgetItem();
                       ui->sudokuWidget_16->setItem(i, j, item);
                       ui->sudokuWidget_16->item(i,j)->setBackground(Qt::red);
                   }
                   else
                   {
                       string tmp1 = QString::number(newbase_16->database[0].body[i][j][0]).toStdString();
                       string tmp2 = ui->sudokuWidget_16->item(i, j)->text().toStdString();
                       if ( tmp1.compare(tmp2) != 0)
                       {
                           wrong = true;
                           ui->sudokuWidget_16->item(i,j)->setBackground(Qt::red);
                       }
                       else
                       {
                           ui->sudokuWidget_16->item(i,j)->setBackground(Qt::white);
                       }
                   }
               }
           }
       }

       if (!wrong)
       {
           QMessageBox newmsgbox;
           newmsgbox.setText("Everything is OK!");
           newmsgbox.exec();
       }
   }

}

void MainWindow::on_hintButton_clicked()
{
   if (ui->tabWidget->currentIndex() == 0)
   {
       bool found = false;

       int itmp = rand();
       itmp %= newtbl->bodySize;
       int jtmp = rand();
       jtmp %= newtbl->bodySize;
       for (int i = itmp; i < newtbl->bodySize; i++)
       {
           for (int j = jtmp; j < newtbl->bodySize; j++)
           {
               if (ui->sudokuWidget->item(i, j)->text().size() == 0)
               {
                   QString tmp = QString::number(newbase->database[0].body[i][j][0]);
                   insertNumber(ui->sudokuWidget->item(i, j)->text(), tmp);
                   ui->sudokuWidget->item(i, j)->setText(tmp);
                   i = newtbl->bodySize;
                   j = newtbl->bodySize;
                   numbers++;
                   found = true;
               }
           }
       }
       if (!found)
       {
           for (int i = 0; i < newtbl->bodySize; i++)
           {
               for (int j = 0; j < newtbl->bodySize; j++)
               {
                   if (ui->sudokuWidget->item(i, j)->text().size() == 0)
                   {
                       QString tmp = QString::number(newbase->database[0].body[i][j][0]);
                       insertNumber(ui->sudokuWidget->item(i, j)->text(), tmp);
                       ui->sudokuWidget->item(i, j)->setText(tmp);
                       numbers++;

                       i = newtbl->bodySize;
                       j = newtbl->bodySize;
                   }
               }
           }
       }
       for (int p = 0; p < newtbl->bodySize; p++)
       {
           for (int q = 0; q < newtbl->bodySize; q++)
           {
               ui->sudokuWidget->item(p, q)->setBackground(Qt::white);
           }
       }
       if (numbers == (newtbl->bodySize)*(newtbl->bodySize)) on_checkButton_clicked();
   }
   else if (ui->tabWidget->currentIndex() == 1)
   {
       bool found = false;

       int itmp = rand();
       itmp %= newtbl_16->bodySize;
       int jtmp = rand();
       jtmp %= newtbl_16->bodySize;

       for (int i = itmp; i < newtbl_16->bodySize; i++)
       {
           for (int j = jtmp; j < newtbl_16->bodySize; j++)
           {
               if (ui->sudokuWidget_16->item(i, j)->text().size() == 0)
               {
                   QString tmp = QString::number(newbase_16->database[0].body[i][j][0]);
                   insertNumber_16(ui->sudokuWidget_16->item(i, j)->text(), tmp);
                   ui->sudokuWidget_16->item(i, j)->setText(tmp);
                   i = newtbl_16->bodySize;
                   j = newtbl_16->bodySize;
                   numbers_16++;
                   found = true;
               }
           }
       }

       if (!found)
       {
           for (int i = 0; i < newtbl_16->bodySize; i++)
           {
               for (int j = 0; j < newtbl_16->bodySize; j++)
               {
                   if (ui->sudokuWidget_16->item(i, j)->text().size() == 0)
                   {
                       QString tmp = QString::number(newbase_16->database[0].body[i][j][0]);
                       insertNumber_16(ui->sudokuWidget_16->item(i, j)->text(), tmp);
                       ui->sudokuWidget_16->item(i, j)->setText(tmp);
                       numbers_16++;

                       i = newtbl_16->bodySize;
                       j = newtbl_16->bodySize;
                   }
               }
           }
       }

       for (int p = 0; p < newtbl_16->bodySize; p++)
       {
           for (int q = 0; q < newtbl_16->bodySize; q++)
           {
               ui->sudokuWidget_16->item(p, q)->setBackground(Qt::white);
           }
       }
       if (numbers_16 == (newtbl_16->bodySize)*(newtbl_16->bodySize)) on_checkButton_clicked();
   }
}

void MainWindow::on_sudokuWidget_doubleClicked(const QModelIndex &index)
{
   if (ui->tabWidget->currentIndex() == 0)
   {
       ui->sudokuWidget->selectedItems().first()->setSelected(false);
   }
   else if (ui->tabWidget->currentIndex() == 1)
   {
       ui->sudokuWidget_16->selectedItems().first()->setSelected(false);
   }
}

void MainWindow::on_hardLevelSlider_valueChanged(int value)
{
   hardlevel = value;
   int totalrange = ui->hardLevelSlider->maximum()-ui->hardLevelSlider->minimum();
   if (hardlevel <= totalrange/3)
   {
       ui->hardLevelLabel->setText("Easy");
   }
   else if (hardlevel <= 2*totalrange/3)
   {
       ui->hardLevelLabel->setText("Medium");
   }
   else
   {
       ui->hardLevelLabel->setText("Hard");
   }
}

void MainWindow::insertNumber (QString beforestr, QString afterstr)
{
   bool ok;
   int before = beforestr.toInt(&ok, 10);
   int after = afterstr.toInt(&ok, 10);
   if (before > 0)
   {
       num[before-1]--;
       if (num[before-1] == newtbl->bodySize) ui->numbersTable->item(before-1,0)->setBackground(Qt::BDiagPattern);
       else ui->numbersTable->item(before-1,0)->setBackground(Qt::NoBrush);
   }

   if (after > 0)
   {
       num[after-1]++;
       if (num[after-1] == newtbl->bodySize) ui->numbersTable->item(after-1,0)->setBackground(Qt::BDiagPattern);
       else ui->numbersTable->item(after-1,0)->setBackground(Qt::NoBrush);
   }
}

void MainWindow::insertNumber_16 (QString beforestr, QString afterstr)
{
   bool ok;
   int before = beforestr.toInt(&ok, 10);
   int after = afterstr.toInt(&ok, 10);
   if (before != 0)
   {
       num_16[before-1]--;
       if (num_16[before-1] == newtbl_16->bodySize) ui->numbersTable_16->item(before-1,0)->setBackground(Qt::BDiagPattern);
       else ui->numbersTable_16->item(before-1,0)->setBackground(Qt::NoBrush);
   }
   if (after != 0)
   {
       num_16[after-1]++;
       if (num_16[after-1] == newtbl_16->bodySize) ui->numbersTable_16->item(after-1,0)->setBackground(Qt::BDiagPattern);
       else ui->numbersTable_16->item(after-1,0)->setBackground(Qt::NoBrush);
   }
}

void MainWindow::pushButton_16 (int num)
{
   if (!(ui->sudokuWidget_16->selectedItems().isEmpty()))
   {
       QString tmp = QString::number(num);
       int i = ui->sudokuWidget_16->currentRow();
       int j = ui->sudokuWidget_16->currentColumn();
       if (i >= 0 && j >= 0)
       {

           if (ui->sudokuWidget_16->item(i,j)->text().size() == 0)
           {
               numbers_16++;
               QString nothingstr = "0";
               insertNumber_16 (nothingstr, tmp);
           }
           else
           {
               insertNumber_16 (ui->sudokuWidget_16->item(i,j)->text(), tmp);
           }
           ui->sudokuWidget_16->item(i, j)->setText(tmp);
           if (numbers_16 == (newtbl_16->bodySize)*(newtbl_16->bodySize)) on_checkButton_clicked();
       }
       ui->sudokuWidget_16->selectedItems().first()->setSelected(false);
       for (int p = 0; p < newtbl_16->bodySize; p++)
       {
           for (int q = 0; q < newtbl_16->bodySize; q++)
           {
               ui->sudokuWidget_16->item(p, q)->setBackground(Qt::white);
           }
       }
   }
}

void MainWindow::on_oneButton_16_clicked()
{
   pushButton_16 (1);
}


void MainWindow::on_twoButton_16_clicked()
{
   pushButton_16 (2);
}

void MainWindow::on_threeButton_16_clicked()
{
   pushButton_16 (3);
}

void MainWindow::on_fourButton_16_clicked()
{
   pushButton_16 (4);
}

void MainWindow::on_fiveButton_16_clicked()
{
   pushButton_16 (5);
}

void MainWindow::on_sixButton_16_clicked()
{
   pushButton_16 (6);
}

void MainWindow::on_sevenButton_16_clicked()
{
   pushButton_16 (7);
}

void MainWindow::on_eightButton_16_clicked()
{
   pushButton_16 (8);
}

void MainWindow::on_nineButton_16_clicked()
{
   pushButton_16 (9);
}

void MainWindow::on_tenButton_16_clicked()
{
   pushButton_16 (10);
}

void MainWindow::on_elevenButton_16_clicked()
{
   pushButton_16 (11);
}

void MainWindow::on_twelveButton_16_clicked()
{
   pushButton_16 (12);
}

void MainWindow::on_thirteenButton_16_clicked()
{
   pushButton_16 (13);
}

void MainWindow::on_fourteenButton_16_clicked()
{
   pushButton_16 (14);
}

void MainWindow::on_fifteenButton_16_clicked()
{
   pushButton_16 (15);
}

void MainWindow::on_sixteenButton_16_clicked()
{
   pushButton_16 (16);
}
int MainWindow::nineSudokuSave()
{
    int s = 0;
    ofstream fout;
    QString saveFile = QFileDialog::getSaveFileName(this, "Select a file to save...", QDir::currentPath(), tr("Documents (*.txt)"));
    if (!saveFile.isEmpty() && !saveFile.isNull())
    {
        fout.open(saveFile.toStdString().c_str());
        assert (!fout.fail());

        for (int i = 0; i < newtbl->bodySize; i++)
        {
            for(int j = 0; j < newtbl->bodySize; j++)
            {
                bool ok = true;
                s += ui->sudokuWidget->item(i,j)->text().toInt(&ok, 10);//
            }
        }

        fout << s*newtbl->bodySize << "\n" << newtbl->bodySize << newtbl->bodySize << "\n" ;//<< newtbl-> << "\n";

        for (int i = 0; i < newtbl->bodySize; i++)
        {
            for (int j = 0; j < newtbl->bodySize; j++)
            {
                fout << newtbl->body[i][j][0] << " ";
            }
            fout <<"\n";
        }

        for (int i = 0; i < newtbl->bodySize; i++)
        {
            for (int j = 0; j < newtbl->bodySize; j++)
            {
                bool ok = true;
                fout << ui->sudokuWidget->item(i,j)->text().toInt(&ok, 10) << " ";
            }
            fout <<"\n";
        }
        fout << hardlevel << "\n";

        fout.close();
    }
    return s;
}

int MainWindow::nineSudokuLoad()
{
    int sum = 0, checksum = 0, type, k;
    ifstream fin;
    QString saveFile = QFileDialog::getOpenFileName(this, "Select a file to load...", QDir::currentPath(), tr("Documents (*.txt)"));
    if (!saveFile.isEmpty() && !saveFile.isNull())
    {
        fin.open(saveFile.toStdString().c_str());
        assert (!fin.fail());

        fin >> checksum >> type;
        if (type != 99)
        {
            //здесь должно быть сообщение об ошибке
            return 0;
        }
        ui->sudokuWidget->clear();
        newtbl = new nineTable;
        restbl = new nineTable;
        newbase = new nineDatabase;

        for (int i = 0; i < newtbl->bodySize; i++)
        {
            for (int j = 0; j < newtbl->bodySize; j++)
            {
                fin >> k;
                newtbl->body[i][j].push_back(k);
            }
        }

        for (int i = 0; i < newtbl->bodySize; i++)
        {
            for (int j = 0; j < newtbl->bodySize; j++)
            {
                fin >> k;
                sum += k;
                QTableWidgetItem *item = new QTableWidgetItem();

                if (k != 0)
                {
                    numbers++;
                    QString tmp2 = QString::number (k);
                    QString nothingstr = "0";
                    insertNumber (nothingstr, tmp2);
                    item->setText (tmp2);
                    ui->sudokuWidget->setItem (i, j, item);
                    if (newtbl->body[i][j][0] != 0)
                    {
                        ui->sudokuWidget->item (i, j)->setFlags (Qt::NoItemFlags);
                    }
                }
                else
                {
                    ui->sudokuWidget->setItem (i, j, item);
                }
            }
        }

        sum *= newtbl->bodySize;
        if (checksum != sum)
        {
            return -1;
        }

        fin >> hardlevel;
        ui->hardLevelSlider->setSliderPosition (hardlevel);

        restbl->sudokuCopy(newtbl, restbl);
        newbase->renderingSolutions(restbl);

        fin.close();
    }
    return 0;
}

int MainWindow::sixteenSudokuSave()
{
    int s = 0;
    ofstream fout;
    QString saveFile = QFileDialog::getSaveFileName(this, "Select a file to save...", QDir::currentPath(), tr("Documents (*.txt)"));
    if (!saveFile.isEmpty() && !saveFile.isNull())
    {
        fout.open(saveFile.toStdString().c_str());
        assert (!fout.fail());

        for (int i = 0; i < newtbl_16->bodySize; i++)
        {
            for(int j = 0; j < newtbl_16->bodySize; j++)
            {
                bool ok = true;
                s += ui->sudokuWidget_16->item(i,j)->text().toInt(&ok, 10);
            }
        }

        fout << s*newtbl_16->bodySize << "\n" << newtbl_16->bodySize << newtbl_16->bodySize << "\n" ;//<< newtbl-> << "\n";

        for (int i = 0; i < newtbl_16->bodySize; i++)
        {
            for (int j = 0; j < newtbl_16->bodySize; j++)
            {
                fout << newtbl_16->body[i][j][0] << " ";
            }
            fout <<"\n";
        }
        for (int i = 0; i < newtbl_16->bodySize; i++)
        {
            for (int j = 0; j < newtbl_16->bodySize; j++)
            {
                bool ok = true;
                fout << ui->sudokuWidget_16->item(i,j)->text().toInt(&ok, 10) << " ";
            }
            fout <<"\n";
        }
        fout << hardlevel << "\n";

        fout.close();
    }
    return s;
}

int MainWindow::sixteenSudokuLoad()
{
    int sum = 0, checksum = 0, type, k;
    ifstream fin;
    QString saveFile = QFileDialog::getOpenFileName(this, "Select a file to load...", QDir::currentPath(), tr("Documents (*.txt)"));
    if (!saveFile.isEmpty() && !saveFile.isNull())
    {
        fin.open(saveFile.toStdString().c_str());
        assert (!fin.fail());

        fin >> checksum >> type;
        if (type != 1616)
        {
            //сообщение об ошибке
            return 0;
        }
        ui->sudokuWidget_16->clear();
        newtbl_16 = new sixteenTable;
        restbl_16 = new sixteenTable;
        newbase_16 = new sixteenDatabase;

        for (int i = 0; i < newtbl_16->bodySize; i++)
        {
            for (int j = 0; j < newtbl_16->bodySize; j++)
            {
                fin >> k;
                newtbl_16->body[i][j].push_back(k);
            }
        }

        for (int i = 0; i < newtbl_16->bodySize; i++)
        {
            for (int j = 0; j < newtbl_16->bodySize; j++)
            {
                fin >> k;
                sum += k;
                QTableWidgetItem *item = new QTableWidgetItem();

                if (k != 0)
                {
                    numbers_16++;
                    QString tmp2 = QString::number (k);
                    QString nothingstr = "0";
                    insertNumber_16 (nothingstr, tmp2);
                    item->setText (tmp2);
                    ui->sudokuWidget_16->setItem (i, j, item);
                    if (newtbl_16->body[i][j][0] != 0)
                    {
                        ui->sudokuWidget_16->item (i, j)->setFlags (Qt::NoItemFlags);
                    }
                }
                else
                {
                    ui->sudokuWidget_16->setItem (i, j, item);
                }
            }
        }

        sum *= newtbl_16->bodySize;
        if (checksum != sum)
        {
            return -1;
        }
        fin >> hardlevel;
        ui->hardLevelSlider->setSliderPosition (hardlevel);

        restbl_16->sudokuCopy(newtbl_16, restbl_16);
        newbase_16->renderingSolutions(restbl_16);

        fin.close();
    }
    return 0;
}

void MainWindow::on_saveButton_clicked()
{
    if (ui->tabWidget->currentIndex() == 0)
    {
        nineSudokuSave();
    }
    else if (ui->tabWidget->currentIndex() == 1)
    {
        sixteenSudokuSave();
    }
}

void MainWindow::on_loadButton_clicked()
{
    if (ui->tabWidget->currentIndex() == 0)
    {
        nineSudokuLoad();
    }
    else if (ui->tabWidget->currentIndex() == 1)
    {
        sixteenSudokuLoad();
    }
}

void MainWindow::on_newButton_pressed()
{
    ui->newButton->setText(QString("Rendering..."));
}

void MainWindow::on_newButton_released()
{
    ui->newButton->setText(QString("New game"));
}
