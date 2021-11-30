/********************************************************************************
** Form generated from reading UI file 'lobbywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOBBYWINDOW_H
#define UI_LOBBYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LobbyWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout;
    QLabel *RoomLabel;
    QLabel *PlayerListText;
    QPushButton *GameStartButton;
    QWidget *verticalWidget_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *AIText;
    QPushButton *IncreaseAI;
    QLabel *AICount;
    QPushButton *DecreaseAI;
    QVBoxLayout *verticalLayout_7;
    QLabel *PlayerText;
    QPushButton *IncreasePlayers;
    QLabel *PlayerCount;
    QPushButton *DecreasePlayers;
    QCheckBox *UNOMode;
    QLabel *IPLabel;

    void setupUi(QMainWindow *LobbyWindow)
    {
        if (LobbyWindow->objectName().isEmpty())
            LobbyWindow->setObjectName(QString::fromUtf8("LobbyWindow"));
        LobbyWindow->resize(808, 600);
        centralwidget = new QWidget(LobbyWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalWidget = new QWidget(centralwidget);
        verticalWidget->setObjectName(QString::fromUtf8("verticalWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(6);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(verticalWidget->sizePolicy().hasHeightForWidth());
        verticalWidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        RoomLabel = new QLabel(verticalWidget);
        RoomLabel->setObjectName(QString::fromUtf8("RoomLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(RoomLabel->sizePolicy().hasHeightForWidth());
        RoomLabel->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(RoomLabel);

        PlayerListText = new QLabel(verticalWidget);
        PlayerListText->setObjectName(QString::fromUtf8("PlayerListText"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(5);
        sizePolicy2.setHeightForWidth(PlayerListText->sizePolicy().hasHeightForWidth());
        PlayerListText->setSizePolicy(sizePolicy2);
        QFont font;
        font.setPointSize(16);
        PlayerListText->setFont(font);

        verticalLayout->addWidget(PlayerListText);

        GameStartButton = new QPushButton(verticalWidget);
        GameStartButton->setObjectName(QString::fromUtf8("GameStartButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(2);
        sizePolicy3.setHeightForWidth(GameStartButton->sizePolicy().hasHeightForWidth());
        GameStartButton->setSizePolicy(sizePolicy3);
        QFont font1;
        font1.setPointSize(34);
        GameStartButton->setFont(font1);

        verticalLayout->addWidget(GameStartButton);


        horizontalLayout->addWidget(verticalWidget);

        verticalWidget_2 = new QWidget(centralwidget);
        verticalWidget_2->setObjectName(QString::fromUtf8("verticalWidget_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(4);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(verticalWidget_2->sizePolicy().hasHeightForWidth());
        verticalWidget_2->setSizePolicy(sizePolicy4);
        verticalLayout_3 = new QVBoxLayout(verticalWidget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        AIText = new QLabel(verticalWidget_2);
        AIText->setObjectName(QString::fromUtf8("AIText"));
        sizePolicy1.setHeightForWidth(AIText->sizePolicy().hasHeightForWidth());
        AIText->setSizePolicy(sizePolicy1);

        verticalLayout_4->addWidget(AIText);

        IncreaseAI = new QPushButton(verticalWidget_2);
        IncreaseAI->setObjectName(QString::fromUtf8("IncreaseAI"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(3);
        sizePolicy5.setHeightForWidth(IncreaseAI->sizePolicy().hasHeightForWidth());
        IncreaseAI->setSizePolicy(sizePolicy5);

        verticalLayout_4->addWidget(IncreaseAI);

        AICount = new QLabel(verticalWidget_2);
        AICount->setObjectName(QString::fromUtf8("AICount"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(6);
        sizePolicy6.setHeightForWidth(AICount->sizePolicy().hasHeightForWidth());
        AICount->setSizePolicy(sizePolicy6);
        QFont font2;
        font2.setPointSize(30);
        AICount->setFont(font2);
        AICount->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(AICount);

        DecreaseAI = new QPushButton(verticalWidget_2);
        DecreaseAI->setObjectName(QString::fromUtf8("DecreaseAI"));
        sizePolicy5.setHeightForWidth(DecreaseAI->sizePolicy().hasHeightForWidth());
        DecreaseAI->setSizePolicy(sizePolicy5);

        verticalLayout_4->addWidget(DecreaseAI);


        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        PlayerText = new QLabel(verticalWidget_2);
        PlayerText->setObjectName(QString::fromUtf8("PlayerText"));
        sizePolicy1.setHeightForWidth(PlayerText->sizePolicy().hasHeightForWidth());
        PlayerText->setSizePolicy(sizePolicy1);

        verticalLayout_7->addWidget(PlayerText);

        IncreasePlayers = new QPushButton(verticalWidget_2);
        IncreasePlayers->setObjectName(QString::fromUtf8("IncreasePlayers"));
        sizePolicy5.setHeightForWidth(IncreasePlayers->sizePolicy().hasHeightForWidth());
        IncreasePlayers->setSizePolicy(sizePolicy5);

        verticalLayout_7->addWidget(IncreasePlayers);

        PlayerCount = new QLabel(verticalWidget_2);
        PlayerCount->setObjectName(QString::fromUtf8("PlayerCount"));
        sizePolicy6.setHeightForWidth(PlayerCount->sizePolicy().hasHeightForWidth());
        PlayerCount->setSizePolicy(sizePolicy6);
        PlayerCount->setFont(font2);
        PlayerCount->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(PlayerCount);

        DecreasePlayers = new QPushButton(verticalWidget_2);
        DecreasePlayers->setObjectName(QString::fromUtf8("DecreasePlayers"));
        sizePolicy5.setHeightForWidth(DecreasePlayers->sizePolicy().hasHeightForWidth());
        DecreasePlayers->setSizePolicy(sizePolicy5);

        verticalLayout_7->addWidget(DecreasePlayers);


        horizontalLayout_2->addLayout(verticalLayout_7);


        verticalLayout_3->addLayout(horizontalLayout_2);

        UNOMode = new QCheckBox(verticalWidget_2);
        UNOMode->setObjectName(QString::fromUtf8("UNOMode"));
        QFont font3;
        font3.setPointSize(14);
        UNOMode->setFont(font3);
        UNOMode->setChecked(true);

        verticalLayout_3->addWidget(UNOMode);

        IPLabel = new QLabel(verticalWidget_2);
        IPLabel->setObjectName(QString::fromUtf8("IPLabel"));
        IPLabel->setFont(font3);

        verticalLayout_3->addWidget(IPLabel);


        horizontalLayout->addWidget(verticalWidget_2);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        LobbyWindow->setCentralWidget(centralwidget);

        retranslateUi(LobbyWindow);

        QMetaObject::connectSlotsByName(LobbyWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LobbyWindow)
    {
        LobbyWindow->setWindowTitle(QApplication::translate("LobbyWindow", "MainWindow", nullptr));
        RoomLabel->setText(QApplication::translate("LobbyWindow", "Lobby Room", nullptr));
        PlayerListText->setText(QApplication::translate("LobbyWindow", "Show plsyers here", nullptr));
        GameStartButton->setText(QApplication::translate("LobbyWindow", "Start Game", nullptr));
        AIText->setText(QApplication::translate("LobbyWindow", "Number of AI", nullptr));
        IncreaseAI->setText(QApplication::translate("LobbyWindow", "Increase", nullptr));
        AICount->setText(QApplication::translate("LobbyWindow", "TextLabel", nullptr));
        DecreaseAI->setText(QApplication::translate("LobbyWindow", "Decrease", nullptr));
        PlayerText->setText(QApplication::translate("LobbyWindow", "Number of Players", nullptr));
        IncreasePlayers->setText(QApplication::translate("LobbyWindow", "Increase", nullptr));
        PlayerCount->setText(QApplication::translate("LobbyWindow", "TextLabel", nullptr));
        DecreasePlayers->setText(QApplication::translate("LobbyWindow", "Decrease", nullptr));
        UNOMode->setText(QApplication::translate("LobbyWindow", "Big TwUNO mode", nullptr));
        IPLabel->setText(QApplication::translate("LobbyWindow", "IP Here", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LobbyWindow: public Ui_LobbyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOBBYWINDOW_H
