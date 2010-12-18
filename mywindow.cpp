#include "mywindow.h"

/*MyWindow::MyWindow()
{
}

MyWindow::~MyWindow()
{
}
*/
void    MyWindow::run()
{
    this->resize(1024, 780);

    this->add = new QPushButton("Add", this);
    this->add->setGeometry(432, 600, 150, 30);
//    this->add->connect(this->add, SIGNAL(clicked()), SLOT(test()));

    this->del = new QPushButton("Delete", this);
    this->del->setGeometry(432, 660, 150, 30);

    this->edit = new QPushButton("Edit", this);
    this->edit->setGeometry(432, 630, 150, 30);

   // this->feedlist = new QStringList();
    this->feedview = new QListView(this);
    this->feedview->setGeometry(10, 10, 500, 580);

    this->itemview = new QListView(this);
    this->itemview->setGeometry(514, 10, 508, 580);

    this->connect(this->add, SIGNAL(clicked()), SLOT(addRss()));
    this->connect(this->del, SIGNAL(clicked()), SLOT(delRss()));
    this->connect(this->edit, SIGNAL(clicked()), SLOT(editRss()));
    this->show();
}

void MyWindow::addRss()
{
    bool ok = false;
    QString url = QInputDialog::getText(this, "Ajouter RSS", "Indiquez le flux RSS a ajouter", QLineEdit::Normal, QString(), &ok);

    if (ok && !url.isEmpty())
    {
        this->feedlist << url;
        this->feedlistmodel = new QStringListModel(this->feedlist);
        this->feedview->setModel(this->feedlistmodel);
    }
}

void    MyWindow::editRss()
{
    QMessageBox::information(this, "Edit", "You're inside editRss");
}

void    MyWindow::delRss()
{
    if (feedlist.length() > 0)
    {
    QItemSelectionModel *selection = feedview->selectionModel();
       QModelIndexList listeSelections = selection->selectedIndexes();
       QString elementsSelectionnes;

       for (int i = 0 ; i < listeSelections.size() ; i++)
       {
           QVariant elementSelectionne = feedlistmodel->data(listeSelections[i], Qt::DisplayRole);
           elementsSelectionnes += elementSelectionne.toString() + "<br />";
       }

       QMessageBox::information(this, "Eléments sélectionnés", elementsSelectionnes);
   }
}
