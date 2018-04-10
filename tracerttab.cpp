#include "tracerttab.h"
#include <QIntValidator>

TracertTab::TracertTab(QWidget *parent) :
  QWidget(parent),
  vLayout(new QVBoxLayout(this)),
  ipLayout(new QHBoxLayout(this)),
  ipLabel(new QLabel(this)),
  dotLabel1(new QLabel(this)),
  dotLabel2(new QLabel(this)),
  dotLabel3(new QLabel(this)),
  ipEdit1(new QLineEdit(this)),
  ipEdit2(new QLineEdit(this)),
  ipEdit3(new QLineEdit(this)),
  ipEdit4(new QLineEdit(this))
{
    /* IP address - horizontal layout */

    ipLabel->setText("IP of the host to ping:");
    dotLabel1->setText(".");
    dotLabel2->setText(".");
    dotLabel3->setText(".");
    ipEdit1->setFixedWidth(35);
    ipEdit2->setFixedWidth(35);
    ipEdit3->setFixedWidth(35);
    ipEdit4->setFixedWidth(35);

    // Limit number of characters to 3
    ipEdit1->setMaxLength(3);
    ipEdit2->setMaxLength(3);
    ipEdit3->setMaxLength(3);
    ipEdit4->setMaxLength(3);

    // Accept only numbers proper range of numbers
    ipEdit1->setValidator(new QIntValidator(0, 255, this));
    ipEdit2->setValidator(new QIntValidator(0, 255, this));
    ipEdit3->setValidator(new QIntValidator(0, 255, this));
    ipEdit4->setValidator(new QIntValidator(0, 255, this));

    // Align text to the left
    ipEdit1->setAlignment(Qt::AlignRight);
    ipEdit2->setAlignment(Qt::AlignRight);
    ipEdit3->setAlignment(Qt::AlignRight);
    ipEdit4->setAlignment(Qt::AlignRight);

    // Set default Ip to loopback address
    ipEdit1->setText(QString("127"));
    ipEdit2->setText(QString("0"));
    ipEdit3->setText(QString("0"));
    ipEdit4->setText(QString("1"));

    // Add everything to the horizontal layout
    ipLayout->addWidget(ipEdit1);
    ipLayout->addWidget(dotLabel1);
    ipLayout->addWidget(ipEdit2);
    ipLayout->addWidget(dotLabel2);
    ipLayout->addWidget(ipEdit3);
    ipLayout->addWidget(dotLabel3);
    ipLayout->addWidget(ipEdit4);
    ipLayout->addStretch(1);

    /* Main layout for this tab */

    vLayout->addWidget(ipLabel);
    vLayout->addLayout(ipLayout);
    vLayout->addStretch(1);
    setLayout(vLayout);
}

QString TracertTab::getIp()
{
    // Data validation is done by the widget itself
    QString ipAddress;
    ipAddress.append(ipEdit1->text());
    ipAddress.append(".");
    ipAddress.append(ipEdit2->text());
    ipAddress.append(".");
    ipAddress.append(ipEdit3->text());
    ipAddress.append(".");
    ipAddress.append(ipEdit4->text());

    return ipAddress;
}
