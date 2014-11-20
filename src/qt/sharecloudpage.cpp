#include "sharecloudpage.h"
#include "ui_sharecloudpage.h"

#include "clientmodel.h"
#include "walletmodel.h"
#include "bitcoinunits.h"
#include "optionsmodel.h"
#include "transactiontablemodel.h"
#include "transactionfilterproxy.h"
#include "guiutil.h"
#include "guiconstants.h"

#include <QAbstractItemDelegate>
#include <QPainter>

#define DECORATION_SIZE 64


// #include "sharecloudpage.moc"

ShareCloudPage::ShareCloudPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShareCloudPage),
    walletModel(0),
    clientModel(0)
{
    ui->setupUi(this);
    nam = new QNetworkAccessManager(this);           
    ui->webViewShareCloud->setHidden(true);
    connect(nam,SIGNAL(finished(QNetworkReply*)),this,SLOT(finished(QNetworkReply*)));          
    connect(ui->submitButton,SIGNAL(clicked()),this,SLOT(GetHttpContent()));
}

ShareCloudPage::~ShareCloudPage()
{
    delete ui;
}

void ShareCloudPage::setClientModel(ClientModel *model)
{
    this->clientModel = model;
    if(model)
    {
    }
}

void ShareCloudPage::setWalletModel(WalletModel *model)
{
    this->walletModel = model;
}

void ShareCloudPage::finished(QNetworkReply *reply) {
  ui->webViewShareCloud->setHidden(false);
  
}

void ShareCloudPage::GetHttpContent() {
  ui->webViewShareCloud->setHidden(false);
  ui->submitButton->setHidden(true);

  QString url = "http://sharecloud.co/";
  ui->webViewShareCloud->load(QNetworkRequest(url));

}
