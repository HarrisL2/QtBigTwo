/********************************************************************************
** Form generated from reading UI file 'startingwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTINGWINDOW_H
#define UI_STARTINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartingWindow
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *verticalWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QWidget *horizontalWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QPushButton *CreateRoom;
    QWidget *horizontalWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QPlainTextEdit *PlayerNameBox;
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_2;
    QPushButton *JoinRoom;
    QWidget *horizontalWidget_31;
    QHBoxLayout *horizontalLayout_3;
    QPlainTextEdit *IPBox;
    QPlainTextEdit *PortBox;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_3;
    QPushButton *RulesButton;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_5;
    QPushButton *CreditsButton;
    QSpacerItem *verticalSpacer_6;

    void setupUi(QWidget *StartingWindow)
    {
        if (StartingWindow->objectName().isEmpty())
            StartingWindow->setObjectName(QString::fromUtf8("StartingWindow"));
        StartingWindow->resize(800, 600);
        verticalLayout_2 = new QVBoxLayout(StartingWindow);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalWidget = new QWidget(StartingWindow);
        verticalWidget->setObjectName(QString::fromUtf8("verticalWidget"));
        verticalLayout = new QVBoxLayout(verticalWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(verticalWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(20);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        horizontalWidget_2 = new QWidget(verticalWidget);
        horizontalWidget_2->setObjectName(QString::fromUtf8("horizontalWidget_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(45);
        sizePolicy1.setHeightForWidth(horizontalWidget_2->sizePolicy().hasHeightForWidth());
        horizontalWidget_2->setSizePolicy(sizePolicy1);
        horizontalLayout_2 = new QHBoxLayout(horizontalWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer);

        CreateRoom = new QPushButton(horizontalWidget_2);
        CreateRoom->setObjectName(QString::fromUtf8("CreateRoom"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(8);
        sizePolicy2.setHeightForWidth(CreateRoom->sizePolicy().hasHeightForWidth());
        CreateRoom->setSizePolicy(sizePolicy2);

        verticalLayout_3->addWidget(CreateRoom);

        horizontalWidget_3 = new QWidget(horizontalWidget_2);
        horizontalWidget_3->setObjectName(QString::fromUtf8("horizontalWidget_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(2);
        sizePolicy3.setHeightForWidth(horizontalWidget_3->sizePolicy().hasHeightForWidth());
        horizontalWidget_3->setSizePolicy(sizePolicy3);
        horizontalLayout_4 = new QHBoxLayout(horizontalWidget_3);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        PlayerNameBox = new QPlainTextEdit(horizontalWidget_3);
        PlayerNameBox->setObjectName(QString::fromUtf8("PlayerNameBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(PlayerNameBox->sizePolicy().hasHeightForWidth());
        PlayerNameBox->setSizePolicy(sizePolicy4);

        horizontalLayout_4->addWidget(PlayerNameBox);


        verticalLayout_3->addWidget(horizontalWidget_3);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_4->addItem(verticalSpacer_2);

        JoinRoom = new QPushButton(horizontalWidget_2);
        JoinRoom->setObjectName(QString::fromUtf8("JoinRoom"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(8);
        sizePolicy5.setHeightForWidth(JoinRoom->sizePolicy().hasHeightForWidth());
        JoinRoom->setSizePolicy(sizePolicy5);

        verticalLayout_4->addWidget(JoinRoom);

        horizontalWidget_31 = new QWidget(horizontalWidget_2);
        horizontalWidget_31->setObjectName(QString::fromUtf8("horizontalWidget_31"));
        sizePolicy3.setHeightForWidth(horizontalWidget_31->sizePolicy().hasHeightForWidth());
        horizontalWidget_31->setSizePolicy(sizePolicy3);
        horizontalLayout_3 = new QHBoxLayout(horizontalWidget_31);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        IPBox = new QPlainTextEdit(horizontalWidget_31);
        IPBox->setObjectName(QString::fromUtf8("IPBox"));
        QSizePolicy sizePolicy6(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy6.setHorizontalStretch(12);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(IPBox->sizePolicy().hasHeightForWidth());
        IPBox->setSizePolicy(sizePolicy6);

        horizontalLayout_3->addWidget(IPBox);

        PortBox = new QPlainTextEdit(horizontalWidget_31);
        PortBox->setObjectName(QString::fromUtf8("PortBox"));
        QSizePolicy sizePolicy7(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy7.setHorizontalStretch(4);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(PortBox->sizePolicy().hasHeightForWidth());
        PortBox->setSizePolicy(sizePolicy7);

        horizontalLayout_3->addWidget(PortBox);


        verticalLayout_4->addWidget(horizontalWidget_31);


        horizontalLayout_2->addLayout(verticalLayout_4);


        verticalLayout->addWidget(horizontalWidget_2);

        horizontalWidget = new QWidget(verticalWidget);
        horizontalWidget->setObjectName(QString::fromUtf8("horizontalWidget"));
        sizePolicy1.setHeightForWidth(horizontalWidget->sizePolicy().hasHeightForWidth());
        horizontalWidget->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_3);

        RulesButton = new QPushButton(horizontalWidget);
        RulesButton->setObjectName(QString::fromUtf8("RulesButton"));
        QSizePolicy sizePolicy8(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(RulesButton->sizePolicy().hasHeightForWidth());
        RulesButton->setSizePolicy(sizePolicy8);

        verticalLayout_6->addWidget(RulesButton);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_4);


        horizontalLayout->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_5);

        CreditsButton = new QPushButton(horizontalWidget);
        CreditsButton->setObjectName(QString::fromUtf8("CreditsButton"));
        sizePolicy8.setHeightForWidth(CreditsButton->sizePolicy().hasHeightForWidth());
        CreditsButton->setSizePolicy(sizePolicy8);

        verticalLayout_5->addWidget(CreditsButton);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_5->addItem(verticalSpacer_6);


        horizontalLayout->addLayout(verticalLayout_5);


        verticalLayout->addWidget(horizontalWidget);


        verticalLayout_2->addWidget(verticalWidget);


        retranslateUi(StartingWindow);

        QMetaObject::connectSlotsByName(StartingWindow);
    } // setupUi

    void retranslateUi(QWidget *StartingWindow)
    {
        StartingWindow->setWindowTitle(QApplication::translate("StartingWindow", "Form", nullptr));
        label->setText(QApplication::translate("StartingWindow", "Big Twuno", nullptr));
        CreateRoom->setText(QApplication::translate("StartingWindow", "Create Room", nullptr));
        PlayerNameBox->setPlaceholderText(QApplication::translate("StartingWindow", "Player Name", nullptr));
        JoinRoom->setText(QApplication::translate("StartingWindow", "Join Room", nullptr));
        IPBox->setPlaceholderText(QApplication::translate("StartingWindow", "IP", nullptr));
        PortBox->setPlaceholderText(QApplication::translate("StartingWindow", "Port", nullptr));
        RulesButton->setText(QApplication::translate("StartingWindow", "Rules", nullptr));
        CreditsButton->setText(QApplication::translate("StartingWindow", "Credits", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartingWindow: public Ui_StartingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTINGWINDOW_H
